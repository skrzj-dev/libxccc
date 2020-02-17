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

#include "test_tpl_main___hlp.hpp"
/* --- */
#include "test_tpl_procedures_abstract.hpp"
/* --- */


int VectorPerformanceTest::xc_svector_test_performance_abstract_power2short_to64K(
	  const std::string operation_name
	, xcc::objPtr<xcc::test::testBenchmarkAction_I> refp_actionObj 
	, xcc::objPtr<xcc::test::testBenchmark01_result> refp_result
)
{
	xcc_err_decl();
	
	try
	{
		if( refp_actionObj.isNull() ) {
			xcc_err_term_unmg();
		}
		if( refp_result.isNull() ) {
			xcc_err_term_unmg();
		}
		
		if(1)
		{
			xcc::test::testBenchmark01_result_entry tmp_entry=xcc::test::testBenchmark01_result_entry();
			xcc::test::testBenchmark01_adt tmp_bechmark= xcc::test::testBenchmark01_adt(
				  operation_name+"; (2K)"
				, 2 * 1024
				, refp_actionObj.val() 
			);
			
			if(0!=tmp_bechmark.perform() ) {
				xcc_err_term_unmg();
			}
			
			if(0!=tmp_bechmark.produce_summary( &tmp_entry ) ) {
				xcc_err_term_unmg();
			}
			
			xcc_err_try_unmg( refp_result.ref().result_append_entry(&tmp_entry) );
		}
		
		if(1)
		{
			xcc::test::testBenchmark01_result_entry tmp_entry=xcc::test::testBenchmark01_result_entry();
			xcc::test::testBenchmark01_adt tmp_bechmark= xcc::test::testBenchmark01_adt(
				  operation_name+"; (4K)"
				, 4 * 1024
				, refp_actionObj.val() 
			);
			
			if(0!=tmp_bechmark.perform() ) {
				xcc_err_term_unmg();
			}
			
			if(0!=tmp_bechmark.produce_summary( &tmp_entry ) ) {
				xcc_err_term_unmg();
			}
			
			xcc_err_try_unmg( refp_result.ref().result_append_entry(&tmp_entry) );
		}

		if(1)
		{
			xcc::test::testBenchmark01_result_entry tmp_entry=xcc::test::testBenchmark01_result_entry();
			xcc::test::testBenchmark01_adt tmp_bechmark= xcc::test::testBenchmark01_adt(
				  operation_name+"; (8K)"
				, 8 * 1024
				, refp_actionObj.val() 
			);
			
			if(0!=tmp_bechmark.perform() ) {
				xcc_err_term_unmg();
			}
			
			if(0!=tmp_bechmark.produce_summary( &tmp_entry ) ) {
				xcc_err_term_unmg();
			}
			
			xcc_err_try_unmg( refp_result.ref().result_append_entry(&tmp_entry) );
		}
		
		if(1)
		{
			xcc::test::testBenchmark01_result_entry tmp_entry=xcc::test::testBenchmark01_result_entry();
			xcc::test::testBenchmark01_adt tmp_bechmark= xcc::test::testBenchmark01_adt(
				  operation_name+"; (16K)"
				, 16 * 1024
				, refp_actionObj.val() 
			);
			
			if(0!=tmp_bechmark.perform() ) {
				xcc_err_term_unmg();
			}
			
			if(0!=tmp_bechmark.produce_summary( &tmp_entry ) ) {
				xcc_err_term_unmg();
			}
			
			xcc_err_try_unmg( refp_result.ref().result_append_entry(&tmp_entry) );
		}

		if(1)
		{
			xcc::test::testBenchmark01_result_entry tmp_entry=xcc::test::testBenchmark01_result_entry();
			xcc::test::testBenchmark01_adt tmp_bechmark= xcc::test::testBenchmark01_adt(
				  operation_name+"; (32K)"
				, 32 * 1024
				, refp_actionObj.val() 
			);
			
			if(0!=tmp_bechmark.perform() ) {
				xcc_err_term_unmg();
			}
			
			if(0!=tmp_bechmark.produce_summary( &tmp_entry ) ) {
				xcc_err_term_unmg();
			}
			
			xcc_err_try_unmg( refp_result.ref().result_append_entry(&tmp_entry) );
		}

		if(1)
		{
			xcc::test::testBenchmark01_result_entry tmp_entry=xcc::test::testBenchmark01_result_entry();
			xcc::test::testBenchmark01_adt tmp_bechmark= xcc::test::testBenchmark01_adt(
				  operation_name+"; (64K)"
				, 64 * 1024
				, refp_actionObj.val() 
			);
			
			if(0!=tmp_bechmark.perform() ) {
				xcc_err_term_unmg();
			}
			
			if(0!=tmp_bechmark.produce_summary( &tmp_entry ) ) {
				xcc_err_term_unmg();
			}
			
			xcc_err_try_unmg( refp_result.ref().result_append_entry(&tmp_entry) );
		}
		
		return 0;
	}
	catch(...)
	{
		xcc_err_handle();
		return 1;
	}
	
	xc_testBenchmark_msg("=====================================================");
	
	return 0;
}

int VectorPerformanceTest::xc_svector_test_performance_abstract_power2long_toMax(
	  const std::string operation_name
	, xcc::objPtr<xcc::test::testBenchmarkAction_I> refp_actionObj 
	, xcc::objPtr<xcc::test::testBenchmark01_result> refp_result
)
{
	xcc_err_decl();
	
	try
	{
		if( refp_actionObj.isNull() ) {
			xcc_err_term_unmg();
		}
		if( refp_result.isNull() ) {
			xcc_err_term_unmg();
		}
		
		if(1)
		{
			xcc::test::testBenchmark01_result_entry tmp_entry=xcc::test::testBenchmark01_result_entry();
			xcc::test::testBenchmark01_adt tmp_bechmark= xcc::test::testBenchmark01_adt(
				  operation_name+"; (64K)"
				, 64 * 1024
				, refp_actionObj.val() 
			);
			
			if(0!=tmp_bechmark.perform() ) {
				xcc_err_term_unmg();
			}
			
			if(0!=tmp_bechmark.produce_summary( &tmp_entry ) ) {
				xcc_err_term_unmg();
			}
			
			xcc_err_try_unmg( refp_result.ref().result_append_entry(&tmp_entry) );
		}
		
		if(1)
		{
			xcc::test::testBenchmark01_result_entry tmp_entry=xcc::test::testBenchmark01_result_entry();
			xcc::test::testBenchmark01_adt tmp_bechmark= xcc::test::testBenchmark01_adt(
				  operation_name+"; (128K)"
				, 128 * 1024
				, refp_actionObj.val() 
			);
			
			if(0!=tmp_bechmark.perform() ) {
				xcc_err_term_unmg();
			}
			
			if(0!=tmp_bechmark.produce_summary( &tmp_entry ) ) {
				xcc_err_term_unmg();
			}
			
			xcc_err_try_unmg( refp_result.ref().result_append_entry(&tmp_entry) );
		}
		
		if(1)
		{
			xcc::test::testBenchmark01_result_entry tmp_entry=xcc::test::testBenchmark01_result_entry();
			xcc::test::testBenchmark01_adt tmp_bechmark= xcc::test::testBenchmark01_adt(
				  operation_name+"; (256K)"
				, 256 * 1024
				, refp_actionObj.val() 
			);
			
			if(0!=tmp_bechmark.perform() ) {
				xcc_err_term_unmg();
			}
			
			if(0!=tmp_bechmark.produce_summary( &tmp_entry ) ) {
				xcc_err_term_unmg();
			}
			
			xcc_err_try_unmg( refp_result.ref().result_append_entry(&tmp_entry) );
		}

		if(1)
		{
			xcc::test::testBenchmark01_result_entry tmp_entry=xcc::test::testBenchmark01_result_entry();
			xcc::test::testBenchmark01_adt tmp_bechmark= xcc::test::testBenchmark01_adt(
				  operation_name+"; (512K)"
				, 512 * 1024
				, refp_actionObj.val() 
			);
			
			if(0!=tmp_bechmark.perform() ) {
				xcc_err_term_unmg();
			}
			
			if(0!=tmp_bechmark.produce_summary( &tmp_entry ) ) {
				xcc_err_term_unmg();
			}
			
			xcc_err_try_unmg( refp_result.ref().result_append_entry(&tmp_entry) );
		}
		
		return 0;
	}
	catch(...)
	{
		xcc_err_handle();
		return 1;
	}
	
	xc_testBenchmark_msg("=====================================================");
	
	return 0;
}
