#ifndef _MAIN_HPP_
#define _MAIN_HPP_

/* --- */
#include "xc/common/xc_mem.h"
#include "xcc/common/xcc_err.hpp"
#include "xcc/test/xcc_test_benchmark.hpp"
/* --- */

class test_performance_malloc
{
	class action_smallMalloc: public xcc::test::testBenchmarkAction_I
	{
		std::vector<void*> allocs;
		
		public: int operation_init(const size_t operation_max_cnt) override
		{
			allocs.reserve(operation_max_cnt+1);
			
			return 0;
		}
		
		public: int do_operation(const size_t operation_current_nr)
		{
			void* x=nullptr;
			
			if(nullptr == (x=malloc( 128 ) ) ) {
				return 1;
			}
			
			this->allocs.push_back(x);
			
			return 0;
		}
		
		public: int operation_deinit(void)
		{
			int n=0;
			for(void* N: this->allocs )
			{
				if(nullptr != N) {
					free(N);
				}
				n++;
			}
			
			allocs.clear();
			
			return 0;
		}
	};
	
	public: static int test_smallAllocations(xcc::test::testBenchmark01_result& ref_result)
	{
		xcc_err_decl();
		
		try
		{
			
			if(1)
			{
				std::string op_name="malloc-small chunk";
				action_smallMalloc action=action_smallMalloc();
				xcc::test::testBenchmark01_result_entry tmp_result=xcc::test::testBenchmark01_result_entry();
				xcc::test::testBenchmark01_adt tmp_bechmark(
					  op_name+"; (2K)"
					, 512 * 1024
					, &action
				);
				
				if(0!=tmp_bechmark.perform() ) {
					xcc_err_term_unmg();
				}
				
				if(0!=tmp_bechmark.produce_summary( &tmp_result ) ) {
					xcc_err_term_unmg();
				}
				
			}
			
			return 0;
		}
		catch(...) {
			xcc_err_handle();
			return 1;
		}
	}
};

class test_performance_chunkList
{
	class action_smallAllocs: public xcc::test::testBenchmarkAction_I
	{
		private: int array_of_bytechunks_size;
		void** array_of_bytechunks;
		
		public: int operation_init(const size_t operation_max_cnt)
		{
			this->array_of_bytechunks=nullptr;
			this->array_of_bytechunks_size=0;
			return 0;
		}
		
		public: int do_operation(const size_t operation_current_nr)
		{
			const int const_itemSize=128;
			const int const_chunkSize=128;
			int tmp_chunk_size=(0==operation_current_nr/const_chunkSize)?1:operation_current_nr/const_chunkSize;
			
			if(this->array_of_bytechunks_size != tmp_chunk_size )
			{
				this->array_of_bytechunks_size=tmp_chunk_size;
				
				if(nullptr==array_of_bytechunks) {
					if( nullptr == (array_of_bytechunks=(void**)malloc( this->array_of_bytechunks_size*sizeof(void**) ) ) ) {
						return 1;
					}
				}
				else
				{
					if(nullptr == (array_of_bytechunks=(void**)realloc( this->array_of_bytechunks, this->array_of_bytechunks_size*sizeof(void**) ) ) ) {
						return 1;
					}
				}
				
				if( nullptr == (this->array_of_bytechunks[array_of_bytechunks_size-1]=malloc( const_itemSize*const_chunkSize*sizeof(char) ) ) ) {
					return 1;
				}

			}
			else
			{
				/* no need to resize */
			}
			
			return 0;
		}
		
		public: int operation_deinit(void)
		{
			int n=0;
			for(n=0; n< this->array_of_bytechunks_size; n++)
			{
				if(nullptr != this->array_of_bytechunks[n] ) {
					free( this->array_of_bytechunks[n] );
				}
				n++;
			}
			
			free(this->array_of_bytechunks);
			
			return 0;
		}
	};
	
	public: static int test_smallAllocations(xcc::test::testBenchmark01_result& ref_result)
	{
		xcc_err_decl();
		
		try
		{
			
			if(1)
			{
				std::string op_name="malloc-small chunk";
				action_smallAllocs action=action_smallAllocs();
				xcc::test::testBenchmark01_result_entry tmp_result=xcc::test::testBenchmark01_result_entry();
				xcc::test::testBenchmark01_adt tmp_bechmark(
					  op_name+"; (2K)"
					, 512 * 1024
					, &action
				);
				
				if(0!=tmp_bechmark.perform() ) {
					xcc_err_term_unmg();
				}
				
				if(0!=tmp_bechmark.produce_summary( &tmp_result ) ) {
					xcc_err_term_unmg();
				}
				
			}
			
			return 0;
		}
		catch(...) {
			xcc_err_handle();
			return 1;
		}
	}

};


class test_performance_chunkedRealloc
{
	class action_smallAllocs: public xcc::test::testBenchmarkAction_I
	{
		private: int array_of_bytes_size;
		void* array_of_bytes;
		
		public: int operation_init(const size_t operation_max_cnt)
		{
			this->array_of_bytes=nullptr;
			this->array_of_bytes_size=0;
			return 0;
		}
		
		public: int do_operation(const size_t operation_current_nr)
		{
			const int const_itemSize=128;
			const int const_chunkSize=128;
			int tmp_chunk_size=(0==operation_current_nr/const_chunkSize)
				  ? const_chunkSize*1
				  : const_chunkSize*(operation_current_nr/const_chunkSize);
			
			if(this->array_of_bytes_size != tmp_chunk_size )
			{
				this->array_of_bytes_size=tmp_chunk_size;
				
				if(nullptr==array_of_bytes) {
					if( nullptr == (array_of_bytes=(void*)malloc( this->array_of_bytes_size*const_itemSize ) ) ) {
						return 1;
					}
				}
				else
				{
					if(nullptr == (array_of_bytes=(void*)realloc( this->array_of_bytes, this->array_of_bytes_size*const_itemSize ) ) ) {
						return 1;
					}
				}
				
			}
			else
			{
				/* no need to resize */
			}
			
			return 0;
		}
		
		public: int operation_deinit(void)
		{
			
			free(this->array_of_bytes);
			
			return 0;
		}
	};
	
	public: static int test_smallAllocations(xcc::test::testBenchmark01_result& ref_result)
	{
		xcc_err_decl();
		
		try
		{
			
			if(1)
			{
				std::string op_name="malloc-small chunk";
				action_smallAllocs action=action_smallAllocs();
				xcc::test::testBenchmark01_result_entry tmp_result=xcc::test::testBenchmark01_result_entry();
				xcc::test::testBenchmark01_adt tmp_bechmark(
					  op_name+"; (2K)"
					, 512 * 1024
					, &action
				);
				
				if(0!=tmp_bechmark.perform() ) {
					xcc_err_term_unmg();
				}
				
				if(0!=tmp_bechmark.produce_summary( &tmp_result ) ) {
					xcc_err_term_unmg();
				}
				
			}
			
			return 0;
		}
		catch(...) {
			xcc_err_handle();
			return 1;
		}
	}

};

#endif
