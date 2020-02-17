/*
 * Copyright block:
 *
 * Source file of libxccc project
 *
 * Copyright (c) 2019 Jakub Skrzyniarz, skrzj-dev@protonmail.com
 *
 * Licensed under: MIT license; See the file "LICENSE" of libxccc project for more information.
 *
 * Copyright block: end
 */

#ifndef _XCC_TEST_BENCHMARK_HPP_
#define _XCC_TEST_BENCHMARK_HPP_

#include <string>
#include <vector>
/* --- */
#include "xcc/common/xcc_err.hpp"
#include "xcc/common/xcc_cpp.hpp"
#include "xc/test/xc_test_benchmark.h"
/*  ---  */


namespace xcc
{


namespace test
{


class testBenchmarkAction_I
{
	public: virtual int operation_init(const size_t max)=0;
	public: virtual int do_operation(const size_t operation_current_nr)=0;
	public: virtual int operation_deinit(void)=0;
};


class testBenchmark01_result_entry
{
	public: xc_testBenchmark_data_t benchmark_data;
	public: std::string test_name;
	public: xcc::tval<size_t> benchmarked_ops_number;
	public: xcc::tval<int> retry_number;
};


class testBenchmark01_result
{
	
	private: std::string test_label;
	
	public: void test_label_set(std::string test_label)
	{
		this->test_label=test_label;
		return;
	}
	
	private: std::vector<xcc::test::testBenchmark01_result_entry> results;
	
	public: int result_append_entry( xcc::objPtrConst<testBenchmark01_result_entry> ref_item) noexcept
	{
		xcc_err_decl();
		
		try
		{
			if( ref_item.isNull() ) {
				xcc_err_term_unmg();
			}
			this->results.push_back( ref_item.ref() );
			
			return 0;
		}
		catch(...)
		{
			xcc_err_handle();
			return 1;
		}
	}
	
	public: int result_append_from(TConstObjRef<testBenchmark01_result> ref_otherResult) noexcept
	{
		xcc_err_decl();
		
		try
		{
			TVal<size_t> nmax=0;
			TVal<size_t> n=0;
			
			if( ref_otherResult.isNull() ) {
				xcc_err_term_unmg();
			}
			
			nmax=ref_otherResult.ref().results.size();
			
			for(n=0; n.val() < nmax.val(); n++ ) 
			{
				const testBenchmark01_result_entry& ref_item_other=ref_otherResult.ref().results[ n.val() ];
				
				this->results.push_back(ref_item_other);
			}
			
			return 0;
		}
		catch(...)
		{
			xcc_err_handle();
			return 1;
		}
	}

	public: int print_summary_header(xcc::objPtr<FILE> refp_stream) noexcept
	{
		xcc_err_decl();
		
		try
		{
			if( refp_stream.isNull() ) {
				xcc_err_term_unmg();
			}
			
			fprintf(refp_stream.val(), "%s\n", "+------------------------------------------------------------------------------------------------------------------------------------------+");
			fprintf(refp_stream.val(), "%s\n", "| Test name:                                                      | Operation number | Retry number | AVG     [ms]/          [s]           |");
			fprintf(refp_stream.val(), "%s\n", "+------------------------------------------------------------------------------------------------------------------------------------------+");
			
			return 0;
		}
		catch(...)
		{
			xcc_err_handle();
			return 1;
		}
	}
	
	public: int print_entry_line(xcc::objPtr<FILE> refp_stream, xcc::objPtrConst<testBenchmark01_result_entry> result_entry) noexcept
	{
		xcc_err_decl();
		
		try
		{
			char buffer[256]={0};
			xcc::tval<size_t> n=0;
			
			if( refp_stream.isNull() ) {
				xcc_err_term_unmg();
			}
			
			if( result_entry.isNull() ) {
				xcc_err_term_unmg();
			}
			/* --- */
			
			snprintf( 
				  buffer, sizeof(buffer)
				, "| %63s |          %06d |          %05d |     [%06lu] ms / [%03lu.%03lu] s        |"
				, result_entry.val()->test_name.c_str()
				, result_entry.val()->benchmarked_ops_number.val()
				, result_entry.val()->retry_number.val()
				, result_entry.val()->benchmark_data.result_avg_duration
				, (long unsigned int)( result_entry.val()->benchmark_data.result_avg_duration / 1000 )
				, (long unsigned int)( result_entry.val()->benchmark_data.result_avg_duration % 1000 )
			);
			
			fprintf(refp_stream.val(), "%s\n", buffer);
			
			return 0;
		}
		catch(...)
		{
			xcc_err_handle();
			return 1;
		}
	}
	
	public: int print_summary(xcc::objPtr<FILE> refp_stream) noexcept
	{
		xcc_err_decl();
		
		try
		{
			char buffer[256]={0};
			xcc::tval<size_t> n=0;
			
			if( refp_stream.isNull() ) {
				xcc_err_term_unmg();
			}
			
			if( 0 != print_summary_header(refp_stream) ) {
				xcc_err_term_unmg();
			}
			
			for(n=0; n.val()< this->results.size(); n++ )
			{
				this->print_entry_line(
					  refp_stream
					, xcc::objPtrConst<testBenchmark01_result_entry>( &this->results[ n.val() ] ) 
				);
			}
			
			xcc_err_try_unmg( 0 != print_summary_header(refp_stream) );
			
			return 0;
		}
		catch(...)
		{
			xcc_err_handle();
			return 1;
		}
	}
	
	public: int print_summary_toFilename(std::string filename) noexcept
	{
		TObjRef<FILE> pf=NULL;
		xcc_err_decl();
		
		try
		{
			pf=fopen(filename.c_str(), "w");
			
			if(NULL != pf.val() )
			{
				this->print_summary(pf);
				
				fclose(pf.val() );
			}
			else 
			{
				xcc_err_term_unmg();
			}
			
			if(1)
			{
				pf=fopen(filename.c_str(), "w");
				
				if(NULL != pf.val() )
				{
					fprintf(pf.val(), "FILE ERROR!\n");
					
					fclose(pf.val() );
				}
			}
			
			return 0;
		}
		catch(...)
		{
			xcc_err_handle();
			return 1;
		}
	}
};

class testBenchmark01_adt
{
	private: xc_testBenchmark_data_t benchmark_data;
	private: std::string test_name;
	private: xcc::tval<size_t> benchmarked_ops_number;
	private: xcc::objPtr<testBenchmarkAction_I> actionObj;
	
	public: int produce_summary(xcc::objPtr<testBenchmark01_result_entry> refp_result) noexcept
	{
		xcc_err_decl();
		
		try
		{
			if( refp_result.isNull() ) {
				xcc_err_term_unmg();
			}
			/* ** ** */
			
			refp_result.ref()=testBenchmark01_result_entry();
			refp_result.ref().benchmark_data=this->benchmark_data;
			refp_result.ref().benchmarked_ops_number=this->benchmarked_ops_number;
			refp_result.ref().retry_number=4; /* TODO */
			refp_result.ref().test_name=this->test_name;
			/* ** ** */
			
			return 0;
		}
		catch(...)
		{
			xcc_err_handle();
			return 1;
		}
	}
	
	public: testBenchmark01_adt(const std::string operation_name, const size_t benchmarked_ops_number, testBenchmarkAction_I* refp_actions) noexcept
	{
		this->test_name=operation_name;
		this->actionObj=xcc::objPtr<testBenchmarkAction_I>(refp_actions);
		this->benchmarked_ops_number=benchmarked_ops_number;
	}
	
	public: int perform() noexcept
	{
		xcc_err_decl();
		
		try
		{
			xc_testBenchmark_init(&benchmark_data);
			
			xc_testBenchmark_msg(">> [%s]:", test_name.c_str() );
			
			while(1)
			{
				if( xc_testBenchmark_isDone(&benchmark_data) ) {
					break;
				}
				
				xc_testBenchmark_retry_start(&benchmark_data);
				xc_testBenchmark_fckup_cpu_cache();
				
				do
				{
					xcc::tval<size_t> n=0;
					xcc::tval<size_t> max=this->benchmarked_ops_number;
					
					if( 0 != this->actionObj.val()->operation_init( max.val() ) ) {
						xcc_err_term_unmg();
					}
					
					xc_testBenchmark_timing_start(&benchmark_data);
					
					for(n=0; n.val() < max.val(); n.ref()++ )
					{
						
						if(0!=this->actionObj.val()->do_operation( n.val() ) ) {
							xcc_err_term_unmg();
						}
						
						if( 0 == n.val() % 10000 ) {
							xc_testBenchmark_msg(">>    %03d * 10K", n.val() );
						}
					}
					
					xc_testBenchmark_timing_done(&benchmark_data);
					
					if( 0 != this->actionObj.val()->operation_deinit() ) {
						xcc_err_term_unmg();
					}
					
				} while(0);
				
				xc_testBenchmark_retry_done(&benchmark_data);
			}
			
			xc_testBenchmark_msg(">>[%s]: done", test_name.c_str() );
			xc_testBenchmark_msg(">>=================================================");
		
			return 0;
		}
		catch(...)
		{
			xcc_err_handle();
			
			if( 0 != this->actionObj.val()->operation_deinit( ) ) {
				xcc_err_term_unmg();
			}
			
			return 1;
		}
		
		return 0;
	}
	
};


};


};


#endif
