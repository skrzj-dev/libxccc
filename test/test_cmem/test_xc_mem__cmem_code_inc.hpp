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

/* --- */

/*
 * this file is expected to be included directly in N .cxx files in order to havee the same code declared in 1 place 
*/

#include "xcc/common/xcc_cpp.hpp"
#include "xcc/test/xcc_test2.hpp"
/* --- */
#include "test_xc_mem__cmem.hpp"
/* --- */

#include <string.h>
#include <malloc.h>
#include <stdlib.h>


typedef struct test_cmem_obj1 {
	int val1;
	char tmp[256];
} test_cmem_obj1;


typedef struct mocked_free_obj
{
	
	int call_cnt;
	
} mocked_free_obj_t;


static mocked_free_obj_t mocked_free_obj={0};

static void mocked_free(void* arg);
static void mocked_free_clear(void);

static void mocked_free_clear(void)
{
	mocked_free_obj.call_cnt=0;
}

static void mocked_free(void* arg)
{
	mocked_free_obj.call_cnt++;
	return;
}

#define free(ARG_PTR_) mocked_free(ARG_PTR_)

static int test_cmem__alloc(xcc_test2_param_list) noexcept;
static int test_cmem__cmp(xcc_test2_param_list) noexcept;
static int test_cmem__copy(xcc_test2_param_list) noexcept;

static int test_cmem__alloc(xcc_test2_param_list) noexcept
{
	xcc_test2_scope("[test xc_mem]:[alloc]");
	
	do
	{
		xcc_test2_case_descr("[alloc_bytes]:[1.1.1]", 
			  "[caller calls API; params:[valid]; expect:[valid memory block] ]"
		);
		
		if(1)
		{
			const size_t valid_sizeparam=32000*sizeof(int);
			void* expect_retv=NULL;
			void* retv=NULL;
			
			if(1)
			{
				retv=xc_mem_allocz_bytes(valid_sizeparam);
		
				xcc_test2_expect( NULL != retv );
				memset(retv, 99, valid_sizeparam);
			}
			
			if(1)
			{
				expect_retv=malloc(valid_sizeparam);
				xcc_test2_expect( NULL != expect_retv );
				memset(expect_retv, 99, valid_sizeparam);
				
				xcc_test2_expect( 0 == memcmp(expect_retv, retv, valid_sizeparam) );
			}
			
			if(1)
			{
				free(retv);
				free(expect_retv);
			}
		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		xcc_test2_case_descr("[alloc_obj]:[1.1.1]", 
			":[caller calls API; params:[valid]; expect:[valid memory block] ]"
		);
		
		if(1)
		{
			const size_t valid_sizeparam=sizeof(test_cmem_obj1);
			test_cmem_obj1* expect_retv=NULL;
			test_cmem_obj1* retv=NULL;
			
			if(1)
			{
				retv=TEST_xc_mem_allocz_obj(test_cmem_obj1);
		
				xcc_test2_expect( NULL != retv );
				memset(retv, 99, valid_sizeparam);
			}
			
			if(1)
			{
				expect_retv=(test_cmem_obj1*)malloc(valid_sizeparam);
				xcc_test2_expect( NULL != expect_retv );
				memset(expect_retv, 99, valid_sizeparam);
				
				xcc_test2_expect( 0 == memcmp(expect_retv, retv, valid_sizeparam) );
			}
			
			if(1)
			{
				free(retv);
				free(expect_retv);
			}
		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		xcc_test2_case_descr("[alloc_obj_array]:[1.1.1]",
			"[caller calls API; params:[valid]; expect:[valid memory block] ]"
		);
		
		if(1)
		{
			const size_t array_number=10;
			const size_t valid_sizeparam=array_number*sizeof(test_cmem_obj1);
			test_cmem_obj1* expect_retv=NULL;
			test_cmem_obj1* retv=NULL;
			
			if(1)
			{
				retv=TEST_xc_mem_allocz_obj_array(test_cmem_obj1, array_number);
		
				xcc_test2_expect( NULL != retv );
				memset(retv, 99, valid_sizeparam);
			}
			
			if(1)
			{
				expect_retv=(test_cmem_obj1*)malloc(valid_sizeparam);
				xcc_test2_expect( NULL != expect_retv );
				memset(expect_retv, 99, valid_sizeparam);
				
				xcc_test2_expect( 0 == memcmp(expect_retv, retv, valid_sizeparam) );
			}
			
			if(1)
			{
				free(retv);
				free(expect_retv);
			}
		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	xcc_test2_scope_end();
}


static int test_cmem__free(xcc_test2_param_list) noexcept
{
	xcc_test2_scope("[test xc_mem]:[free]");
	
	do
	{
		xcc_test2_case_descr("[free obj]:[1.1.1]",
			":[caller calls API; params:[valid ptr to allocated memory];"
			"expect:"
			"   [input ptr != NULL]"
			"&& [result ptr is deallocated]"
			"&& [result ptr is NULL]"
			""
		);

		if(1)
		{
			mocked_free_clear();
			xcc_test2_expect_eq_t(int, 0, mocked_free_obj.call_cnt);
		}
		
		if(1)
		{
			const size_t array_number=1;
			const size_t valid_sizeparam=sizeof(test_cmem_obj1);
			test_cmem_obj1* expect_retv=NULL;
			test_cmem_obj1* unexpect_retv=NULL;
			test_cmem_obj1* test_retv=NULL;
			
			if(1)
			{
				test_retv=TEST_xc_mem_allocz_obj(test_cmem_obj1);
		
				xcc_test2_expect( NULL != test_retv );
				memset(test_retv, 99, valid_sizeparam);
			}
			
			if(1)
			{
				TEST_xc_mem_free_obj(test_cmem_obj1, test_retv);
				
				xcc_test2_expect( NULL == test_retv );
				
				xcc_test2_expect_eq_t(int, 1, mocked_free_obj.call_cnt);
			}
		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		xcc_test2_case_descr("[free bytes]:[1.1.1]",
			":[caller calls API; params:[valid ptr to allocated memory];"
			"expect:"
			"   [input ptr != NULL]"
			"&& [result ptr is deallocated]"
			"&& [result ptr is NULL]"
			""
		);
		
		if(1)
		{
			mocked_free_clear();
			xcc_test2_expect_eq_t(int, 0, mocked_free_obj.call_cnt);
		}
		
		if(1)
		{
			const size_t array_number=1;
			const size_t valid_sizeparam=sizeof(test_cmem_obj1);
			test_cmem_obj1* expect_retv=NULL;
			test_cmem_obj1* unexpect_retv=NULL;
			test_cmem_obj1* test_retv=NULL;
			
			if(1)
			{
				test_retv=TEST_xc_mem_allocz_obj(test_cmem_obj1);
		
				xcc_test2_expect( NULL != test_retv );
				memset(test_retv, 99, valid_sizeparam);
			}
			
			if(1)
			{
				TEST_xc_mem_free_bytes(test_retv);
				
				xcc_test2_expect( NULL == test_retv );
				
				xcc_test2_expect_eq_t(int, 1, mocked_free_obj.call_cnt);
			}
		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	xcc_test2_scope_end();
}


static int test_cmem__cmp(xcc_test2_param_list) noexcept
{
	xcc_test2_scope("[test xc_mem]:[cmp]");
	
	do
	{
		xcc_test2_case_descr("[cmp obj]:[1.1.1]",
			"[caller calls API; params:[valid];"
			"expect:"
			"   [result == obj w same values with same size]"
			"&& [result != obj w different values with same size]"
			""
		);
		
		if(1)
		{
			const size_t array_number=1;
			const size_t valid_sizeparam=sizeof(test_cmem_obj1);
			test_cmem_obj1* expect_retv=NULL;
			test_cmem_obj1* unexpect_retv=NULL;
			test_cmem_obj1* test_retv=NULL;
			
			if(1)
			{
				test_retv=TEST_xc_mem_allocz_obj(test_cmem_obj1);
		
				xcc_test2_expect( NULL != test_retv );
				memset(test_retv, 99, valid_sizeparam);
			}
			if(1)
			{
				unexpect_retv=TEST_xc_mem_allocz_obj(test_cmem_obj1);
		
				xcc_test2_expect( NULL != unexpect_retv );
				memset(unexpect_retv, 55, valid_sizeparam);
			}
			if(1)
			{
				expect_retv=TEST_xc_mem_allocz_obj(test_cmem_obj1);
		
				xcc_test2_expect( NULL != expect_retv );
				memset(expect_retv, 99, valid_sizeparam);
			}
			
			if(1)
			{
				int cmp_retv=0;
				
				cmp_retv=0;
				TEST_xc_mem_cmp_obj_param(test_cmem_obj1, test_retv, expect_retv, &cmp_retv);
				xcc_test2_expect_eq_t(int, 0, cmp_retv);

				cmp_retv=0;
				TEST_xc_mem_cmp_obj_param(test_cmem_obj1, test_retv, unexpect_retv, &cmp_retv);
				xcc_test2_expect_neq_t(int, 0, cmp_retv);
			}
			
			if(1)
			{
				free(test_retv);
				free(expect_retv);
				free(unexpect_retv);
			}
		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		xcc_test2_case_descr("[cmp obj array]:[1.1.1]",
			"[caller calls API; params:[valid];"
			"expect:"
			"   [result == array of same values with same size]"
			"&& [result != than array of different values with same size]"
			""
		);
		
		if(1)
		{
			const size_t array_number=10;
			const size_t valid_sizeparam=array_number*sizeof(test_cmem_obj1);
			test_cmem_obj1* expect_retv=NULL;
			test_cmem_obj1* unexpect_retv=NULL;
			test_cmem_obj1* test_retv=NULL;
			
			if(1)
			{
				test_retv=TEST_xc_mem_allocz_obj_array(test_cmem_obj1, array_number);
		
				xcc_test2_expect( NULL != test_retv );
				memset(test_retv, 99, valid_sizeparam);
			}
			if(1)
			{
				unexpect_retv=TEST_xc_mem_allocz_obj_array(test_cmem_obj1, array_number);
		
				xcc_test2_expect( NULL != unexpect_retv );
				memset(unexpect_retv, 55, valid_sizeparam);
			}
			if(1)
			{
				expect_retv=TEST_xc_mem_allocz_obj_array(test_cmem_obj1, array_number);
		
				xcc_test2_expect( NULL != expect_retv );
				memset(expect_retv, 99, valid_sizeparam);
			}
			
			if(1)
			{
				int cmp_retv=0;
				
				cmp_retv=0;
				TEST_xc_mem_cmp_obj_array_param(test_cmem_obj1, array_number, test_retv, expect_retv, &cmp_retv);
				xcc_test2_expect_eq_t(int, 0, cmp_retv);
				
				cmp_retv=0;
				TEST_xc_mem_cmp_obj_array_param(test_cmem_obj1, array_number, test_retv, unexpect_retv, &cmp_retv);
				xcc_test2_expect_neq_t(int, 0, cmp_retv);
			}
			
			if(1)
			{
				free(test_retv);
				free(expect_retv);
				free(unexpect_retv);
			}
		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		xcc_test2_case_descr("[cmp bytes]:[1.1.1]",
			  "[caller calls API; params:[valid];"
			 "expect:"
			 "   [result == array of same values with same size]"
			 "&& [result != than array of different values with same size]"
		);

		
		if(1)
		{
			const size_t array_number=10;
			const size_t valid_sizeparam=array_number*sizeof(test_cmem_obj1);
			test_cmem_obj1* expect_retv=NULL;
			test_cmem_obj1* unexpect_retv=NULL;
			test_cmem_obj1* test_retv=NULL;
			
			if(1)
			{
				test_retv=TEST_xc_mem_allocz_obj_array(test_cmem_obj1, array_number);
		
				xcc_test2_expect( NULL != test_retv );
				memset(test_retv, 99, valid_sizeparam);
			}
			if(1)
			{
				unexpect_retv=TEST_xc_mem_allocz_obj_array(test_cmem_obj1, array_number);
		
				xcc_test2_expect( NULL != unexpect_retv );
				memset(unexpect_retv, 55, valid_sizeparam);
			}
			if(1)
			{
				expect_retv=TEST_xc_mem_allocz_obj_array(test_cmem_obj1, array_number);
		
				xcc_test2_expect( NULL != expect_retv );
				memset(expect_retv, 99, valid_sizeparam);
			}
			
			if(1)
			{
				int cmp_retv=0;
				
				cmp_retv=0;
				TEST_xc_mem_cmp_bytes_param(valid_sizeparam, test_retv, expect_retv, &cmp_retv);
				xcc_test2_expect_eq_t(int, 0, cmp_retv);
				
				cmp_retv=0;
				TEST_xc_mem_cmp_bytes_param(valid_sizeparam, test_retv, unexpect_retv, &cmp_retv);
				xcc_test2_expect_neq_t(int, 0, cmp_retv);
			}
			
			if(1)
			{
				free(test_retv);
				free(expect_retv);
				free(unexpect_retv);
			}
		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	xcc_test2_scope_end();
}


static int test_cmem__copy(xcc_test2_param_list) noexcept
{
	xcc_test2_scope("[test xc_mem]:[copy]");
	
	do
	{
		xcc_test2_case_descr("[copy obj]:[1.1.1]",
			"[caller calls API; params:[valid];"
			"expect results:"
			"   1. [INPUT OBJ 1] IS SAME as before [COPY OPERATION]"
			"   2. [RESULT OBJ] IS SAME as [INPUT OBJ 1]"
			""
		);

		
		if(1)
		{
			const size_t array_number=1;
			const size_t valid_sizeparam=sizeof(test_cmem_obj1);
			test_cmem_obj1* expect_retv=NULL;
			test_cmem_obj1* unexpect_retv=NULL;
			test_cmem_obj1* test_retv=NULL;
			test_cmem_obj1* test_retv_copied=NULL;
			
			if(1)
			{
				test_retv=TEST_xc_mem_allocz_obj(test_cmem_obj1);
		
				xcc_test2_expect( NULL != test_retv );
				memset(test_retv, 99, valid_sizeparam);
			}
			if(1)
			{
				unexpect_retv=TEST_xc_mem_allocz_obj(test_cmem_obj1);
		
				xcc_test2_expect( NULL != unexpect_retv );
				memset(unexpect_retv, 55, valid_sizeparam);
			}
			if(1)
			{
				expect_retv=TEST_xc_mem_allocz_obj(test_cmem_obj1);
		
				xcc_test2_expect( NULL != expect_retv );
				memset(expect_retv, 99, valid_sizeparam);
			}
			if(1)
			{
				test_retv_copied=TEST_xc_mem_allocz_obj(test_cmem_obj1);
		
				xcc_test2_expect( NULL != test_retv_copied );
				memset(test_retv_copied, 0, valid_sizeparam);
			}
			
			if(1)
			{
				int cmp_retv=0;
				
				cmp_retv=0;
				TEST_xc_mem_cmp_obj_param(test_cmem_obj1, test_retv, expect_retv, &cmp_retv);
				xcc_test2_expect_eq_t(int, 0, cmp_retv);
				
				cmp_retv=0;
				TEST_xc_mem_cmp_obj_param(test_cmem_obj1, test_retv, test_retv_copied, &cmp_retv);
				xcc_test2_expect_neq_t(int, 0, cmp_retv);
				
				/* --- */
				
				TEST_xc_mem_cp_obj(test_cmem_obj1, test_retv_copied, test_retv);
				
				/* --- */
				
				cmp_retv=0;
				TEST_xc_mem_cmp_obj_param(test_cmem_obj1, test_retv, expect_retv, &cmp_retv);
				xcc_test2_expect_eq_t(int, 0, cmp_retv);
				
				cmp_retv=0;
				TEST_xc_mem_cmp_obj_param(test_cmem_obj1, test_retv, test_retv_copied, &cmp_retv);
				xcc_test2_expect_eq_t(int, 0, cmp_retv);
			}
			
			if(1)
			{
				free(test_retv);
				free(expect_retv);
				free(unexpect_retv);
				free(test_retv_copied);
			}
		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		xcc_test2_case_descr("[copy obj array]:[1.1.1]",
			"[caller calls API; params:[valid];"
			"expect results:"
			"   1. [INPUT ARRAY 1] IS SAME as before [COPY OPERATION]"
			"   2a. [RESULT ARRAY] IS SAME as [INPUT ARRAY 1]"
			"   2b. [INPUT ARRAY 1] IS SAME as [RESULT ARRAY]"
			""
		);
		
		if(1)
		{
			const size_t array_number=10;
			const size_t valid_sizeparam=array_number*sizeof(test_cmem_obj1);
			test_cmem_obj1* expect_retv=NULL;
			test_cmem_obj1* unexpect_retv=NULL;
			test_cmem_obj1* test_retv=NULL;
			test_cmem_obj1* test_retv_copied=NULL;
			
			if(1)
			{
				test_retv=TEST_xc_mem_allocz_obj_array(test_cmem_obj1, array_number);
		
				xcc_test2_expect( NULL != test_retv );
				memset(test_retv, 99, valid_sizeparam);
			}
			if(1)
			{
				unexpect_retv=TEST_xc_mem_allocz_obj_array(test_cmem_obj1, array_number);
		
				xcc_test2_expect( NULL != unexpect_retv );
				memset(unexpect_retv, 55, valid_sizeparam);
			}
			if(1)
			{
				expect_retv=TEST_xc_mem_allocz_obj_array(test_cmem_obj1, array_number);
		
				xcc_test2_expect( NULL != expect_retv );
				memset(expect_retv, 99, valid_sizeparam);
			}
			if(1)
			{
				test_retv_copied=TEST_xc_mem_allocz_obj_array(test_cmem_obj1, array_number);
		
				xcc_test2_expect( NULL != test_retv_copied );
				memset(test_retv_copied, 0, valid_sizeparam);
			}
			
			if(1)
			{
				int cmp_retv=0;
				
				cmp_retv=0;
				TEST_xc_mem_cmp_obj_array_param(test_cmem_obj1, array_number, test_retv, expect_retv, &cmp_retv);
				xcc_test2_expect_eq_t(int, 0, cmp_retv);
				
				cmp_retv=0;
				TEST_xc_mem_cmp_obj_array_param(test_cmem_obj1, array_number, test_retv, test_retv_copied, &cmp_retv);
				xcc_test2_expect_neq_t(int, 0, cmp_retv);
				
				/* --- */
				
				TEST_xc_mem_cp_obj_array(test_cmem_obj1, array_number, test_retv_copied, test_retv);
				
				/* --- */
				
				cmp_retv=0;
				TEST_xc_mem_cmp_obj_array_param(test_cmem_obj1, array_number, test_retv, expect_retv, &cmp_retv);
				xcc_test2_expect_eq_t(int, 0, cmp_retv);
				
				cmp_retv=0;
				TEST_xc_mem_cmp_obj_array_param(test_cmem_obj1, array_number, test_retv, test_retv_copied, &cmp_retv);
				xcc_test2_expect_eq_t(int, 0, cmp_retv);

				cmp_retv=0;
				TEST_xc_mem_cmp_obj_array_param(test_cmem_obj1, array_number, test_retv_copied, test_retv, &cmp_retv);
				xcc_test2_expect_eq_t(int, 0, cmp_retv);

				cmp_retv=0;
				TEST_xc_mem_cmp_obj_array_param(test_cmem_obj1, array_number, test_retv_copied, unexpect_retv, &cmp_retv);
				xcc_test2_expect_neq_t(int, 0, cmp_retv);
			}
			
			if(1)
			{
				free(test_retv);
				free(expect_retv);
				free(unexpect_retv);
				free(test_retv_copied);
			}

		}
		
		xcc_test2_case_end();
		
	} while(0);
	

	do
	{
		xcc_test2_case_descr("[copy bytes]:[1.1.1]",
			"[caller calls API; params:[valid];"
			"expect results:"
			"   1. [INPUT ARRAY 1] IS SAME as before [COPY OPERATION]"
			"   2a. [RESULT ARRAY] IS SAME as [INPUT ARRAY 1]"
			"   2b. [INPUT ARRAY 1] IS SAME as [RESULT ARRAY]"
			""
		);
		
		if(1)
		{
			const size_t array_number=10;
			const size_t valid_sizeparam=array_number*sizeof(test_cmem_obj1);
			void* expect_retv=NULL;
			void* unexpect_retv=NULL;
			void* test_retv=NULL;
			void* test_retv_copied=NULL;
			
			if(1)
			{
				test_retv=TEST_xc_mem_allocz_bytes(valid_sizeparam);
		
				xcc_test2_expect( NULL != test_retv );
				memset(test_retv, 99, valid_sizeparam);
			}
			if(1)
			{
				unexpect_retv=TEST_xc_mem_allocz_bytes(valid_sizeparam);
		
				xcc_test2_expect( NULL != unexpect_retv );
				memset(unexpect_retv, 55, valid_sizeparam);
			}
			if(1)
			{
				expect_retv=TEST_xc_mem_allocz_bytes(valid_sizeparam);
		
				xcc_test2_expect( NULL != expect_retv );
				memset(expect_retv, 99, valid_sizeparam);
			}
			if(1)
			{
				test_retv_copied=TEST_xc_mem_allocz_bytes(valid_sizeparam);
		
				xcc_test2_expect( NULL != test_retv_copied );
				memset(test_retv_copied, 0, valid_sizeparam);
			}
			
			if(1)
			{
				int cmp_retv=0;
				
				cmp_retv=0;
				TEST_xc_mem_cmp_bytes_param(valid_sizeparam, test_retv, expect_retv, &cmp_retv);
				xcc_test2_expect_eq_t(int, 0, cmp_retv);
				
				cmp_retv=0;
				TEST_xc_mem_cmp_bytes_param(valid_sizeparam, test_retv, test_retv_copied, &cmp_retv);
				xcc_test2_expect_neq_t(int, 0, cmp_retv);
				
				/* --- */
				
				TEST_xc_mem_cp_bytes(valid_sizeparam, test_retv_copied, test_retv);
				
				/* --- */
				
				cmp_retv=0;
				TEST_xc_mem_cmp_bytes_param(valid_sizeparam, test_retv, expect_retv, &cmp_retv);
				xcc_test2_expect_eq_t(int, 0, cmp_retv);
				
				cmp_retv=0;
				TEST_xc_mem_cmp_bytes_param(valid_sizeparam, test_retv, test_retv_copied, &cmp_retv);
				xcc_test2_expect_eq_t(int, 0, cmp_retv);

				cmp_retv=0;
				TEST_xc_mem_cmp_bytes_param(valid_sizeparam, test_retv_copied, test_retv, &cmp_retv);
				xcc_test2_expect_eq_t(int, 0, cmp_retv);

				cmp_retv=0;
				TEST_xc_mem_cmp_bytes_param(valid_sizeparam, test_retv_copied, unexpect_retv, &cmp_retv);
				xcc_test2_expect_neq_t(int, 0, cmp_retv);
			}
			
			if(1)
			{
				free(test_retv);
				free(expect_retv);
				free(unexpect_retv);
				free(test_retv_copied);
			}

		}
		
		xcc_test2_case_end();
		
	} while(0);
	
	xcc_test2_scope_end();
}
