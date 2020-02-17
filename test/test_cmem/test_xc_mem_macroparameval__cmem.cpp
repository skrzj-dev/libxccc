#include <cstring>
#include <cstdlib>
#include <malloc.h>
/* --- */
#include "xc/common/xc_mem.h"
/* --- */
#include "xcc/common/xcc_cpp.hpp"
#include "xcc/test/xcc_test2.hpp"
#include "xcc/test/xcc_test_evaluation_counter.hpp"
#include "test_xc_mem__cmem.hpp"
/* --- */

/* --- */
#include "test_xc_mem_macroparameval__cmem.hpp"


int test_cmem_eval__cmem(xcc_test2_param_list)
{
	xcc_test2_scope("xc_cmem : param evaluation check");
	
	do
	{
		xcc_test2_case_descr("[alloc_bytes]:[EVAL.1.1]", 
			  "[expect == 1 evaluation number for all params except type symbol]"
		);
		
		size_t bytesize=1;
		test_ObjReference_Refcounter<size_t> eval_bytesize=test_ObjReference_Refcounter<size_t>(&bytesize);
		
		if(1)
		{
			xc_mem_allocz_bytes( eval_bytesize.get_val() );
		}
		
		xcc_test2_expect_eq_t(unsigned int, 1, eval_bytesize.get_cnter() );
		
		xcc_test2_case_end();
	
	}  while(0);

	do
	{
		xcc_test2_case_descr("[alloc_obj]:[EVAL.1.1]", 
			  "[expect == 1 evaluation number for all params except type symbol]"
		);
		
		size_t bytesize=1;
		test_ObjReference_Refcounter<size_t> eval_bytesize=test_ObjReference_Refcounter<size_t>(&bytesize);
		
		if(1)
		{
			xc_mem_allocz_obj( int );
		}
		
		xcc_test2_expect_eq_t(unsigned int, 0, eval_bytesize.get_cnter() );
		
		xcc_test2_case_end();
	
	}  while(0);
	
	do
	{
		xcc_test2_case_descr("[alloc_obj_array]:[EVAL.1.1]", 
			  "[expect == 1 evaluation number for all params except type symbol]"
		);
		
		size_t bytesize=sizeof(int);
		test_ObjReference_Refcounter<size_t> eval_arraysize=test_ObjReference_Refcounter<size_t>(&bytesize);
		
		if(1)
		{
			xc_mem_allocz_obj_array( int, eval_arraysize.get_val() );
		}
		
		xcc_test2_expect_eq_t(unsigned int, 1, eval_arraysize.get_cnter() );
		
		xcc_test2_case_end();
	
	}  while(0);
	
	
	do
	{
		xcc_test2_case_descr("[alloc_cp_bytes]:[EVAL.1.1]", 
			  "[expect == 1 evaluation number for all params except type symbol]"
		);
		
		int src=0;
		test_ObjReference_Refcounter<int> eval_srcp=test_ObjReference_Refcounter<int>(&src);
		int target=0;
		test_ObjReference_Refcounter<int> eval_targetp=test_ObjReference_Refcounter<int>(&target);
		size_t bytesize=sizeof(int);
		test_ObjReference_Refcounter<size_t> eval_bytesize=test_ObjReference_Refcounter<size_t>(&bytesize);
		size_t arraycnt=1;
		test_ObjReference_Refcounter<size_t> eval_arraysize=test_ObjReference_Refcounter<size_t>(&arraycnt);
		
		if(1)
		{
			xc_mem_cp_bytes( eval_arraysize.get_val(), eval_targetp.get_refp(), eval_srcp.get_refp() );
		}
		
		xcc_test2_expect_eq_t(unsigned int, 1, eval_arraysize.get_cnter() );
		xcc_test2_expect_eq_t(unsigned int, 1, eval_targetp.get_cnter() );
		xcc_test2_expect_eq_t(unsigned int, 1, eval_srcp.get_cnter() );
		
		xcc_test2_case_end();
	
	}  while(0);
	
	do
	{
		xcc_test2_case_descr("[alloc_cp_obj]:[EVAL.1.1]", 
			  "[expect == 1 evaluation number for all params except type symbol]"
		);
		
		int src=0;
		test_ObjReference_Refcounter<int> eval_srcp=test_ObjReference_Refcounter<int>(&src);
		int target=0;
		test_ObjReference_Refcounter<int> eval_targetp=test_ObjReference_Refcounter<int>(&target);
		size_t bytesize=sizeof(int);
		test_ObjReference_Refcounter<size_t> eval_bytesize=test_ObjReference_Refcounter<size_t>(&bytesize);
		size_t arraycnt=1;
		test_ObjReference_Refcounter<size_t> eval_arraysize=test_ObjReference_Refcounter<size_t>(&arraycnt);
		
		if(1)
		{
			xc_mem_cp_obj( int, eval_targetp.get_refp(), eval_srcp.get_refp() );
		}
		
		//xcc_test2_expect_neq_t(unsigned int, 0, eval_arraysize.get_cnter() );
		xcc_test2_expect_eq_t(unsigned int, 1, eval_targetp.get_cnter() );
		xcc_test2_expect_eq_t(unsigned int, 1, eval_srcp.get_cnter() );
		
		xcc_test2_case_end();
	
	}  while(0);
	
	
	do
	{
		xcc_test2_case_descr("[alloc_cp_obj_array]:[EVAL.1.1]", 
			  "[expect == 1 evaluation number for all params except type symbol]"
		);
		
		int src=0;
		test_ObjReference_Refcounter<int> eval_srcp=test_ObjReference_Refcounter<int>(&src);
		int target=0;
		test_ObjReference_Refcounter<int> eval_targetp=test_ObjReference_Refcounter<int>(&target);
		size_t bytesize=sizeof(int);
		test_ObjReference_Refcounter<size_t> eval_bytesize=test_ObjReference_Refcounter<size_t>(&bytesize);
		size_t arraycnt=1;
		test_ObjReference_Refcounter<size_t> eval_arraysize=test_ObjReference_Refcounter<size_t>(&arraycnt);
		
		if(1)
		{
			xc_mem_cp_obj_array( int, eval_arraysize.get_val(), eval_targetp.get_refp(), eval_srcp.get_refp() );
		}
		
		xcc_test2_expect_eq_t(unsigned int, 1, eval_arraysize.get_cnter() );
		xcc_test2_expect_eq_t(unsigned int, 1, eval_targetp.get_cnter() );
		xcc_test2_expect_eq_t(unsigned int, 1, eval_srcp.get_cnter() );
		
		xcc_test2_case_end();
	
	}  while(0);
	
	
	do
	{
		xcc_test2_case_descr("[cmp_bytes param]:[EVAL.1.1]", 
			  "[expect == 1 evaluation number for all params except type symbol]"
		);
		
		int src=0;
		test_ObjReference_Refcounter<int> eval_srcp=test_ObjReference_Refcounter<int>(&src);
		int target=0;
		test_ObjReference_Refcounter<int> eval_targetp=test_ObjReference_Refcounter<int>(&target);
		size_t bytesize=sizeof(int);
		test_ObjReference_Refcounter<size_t> eval_bytesize=test_ObjReference_Refcounter<size_t>(&bytesize);
		size_t arraycnt=1;
		test_ObjReference_Refcounter<size_t> eval_arraysize=test_ObjReference_Refcounter<size_t>(&arraycnt);
		int result=1;
		test_ObjReference_Refcounter<int> eval_result=test_ObjReference_Refcounter<int>(&result);
		
		if(1)
		{
			xc_mem_cmp_bytes_param( eval_bytesize.get_val(), eval_targetp.get_refp(), eval_srcp.get_refp(), eval_result.get_refp() );
		}
		
		
		xcc_test2_expect_eq_t(unsigned int, 1, eval_bytesize.get_cnter() );
		xcc_test2_expect_eq_t(unsigned int, 1, eval_targetp.get_cnter() );
		xcc_test2_expect_eq_t(unsigned int, 1, eval_srcp.get_cnter() );
		xcc_test2_expect_eq_t(unsigned int, 1, eval_result.get_cnter() );
		
		xcc_test2_case_end();
	
	}  while(0);
	
	
	do
	{
		xcc_test2_case_descr("[cmp_obj param]:[EVAL.1.1]", 
			  "[expect == 1 evaluation number for all params except type symbol]"
		);
		
		int src=0;
		test_ObjReference_Refcounter<int> eval_srcp=test_ObjReference_Refcounter<int>(&src);
		int target=0;
		test_ObjReference_Refcounter<int> eval_targetp=test_ObjReference_Refcounter<int>(&target);
		size_t bytesize=sizeof(int);
		test_ObjReference_Refcounter<size_t> eval_bytesize=test_ObjReference_Refcounter<size_t>(&bytesize);
		size_t arraycnt=1;
		test_ObjReference_Refcounter<size_t> eval_arraysize=test_ObjReference_Refcounter<size_t>(&arraycnt);
		int result=1;
		test_ObjReference_Refcounter<int> eval_result=test_ObjReference_Refcounter<int>(&result);
		
		if(1)
		{
			xc_mem_cmp_obj_param( int, eval_targetp.get_refp(), eval_srcp.get_refp(), eval_result.get_refp() );
		}
		
		xcc_test2_expect_eq_t(unsigned int, 1, eval_targetp.get_cnter() );
		xcc_test2_expect_eq_t(unsigned int, 1, eval_srcp.get_cnter() );
		xcc_test2_expect_eq_t(unsigned int, 1, eval_result.get_cnter() );
		
		xcc_test2_case_end();
	
	}  while(0);
	
	do
	{
		xcc_test2_case_descr("[cmp_obj_array param]:[EVAL.1.1]", 
			  "[expect == 1 evaluation number for all params except type symbol]"
		);
		
		int src=0;
		test_ObjReference_Refcounter<int> eval_srcp=test_ObjReference_Refcounter<int>(&src);
		int target=0;
		test_ObjReference_Refcounter<int> eval_targetp=test_ObjReference_Refcounter<int>(&target);
		size_t bytesize=sizeof(int);
		test_ObjReference_Refcounter<size_t> eval_bytesize=test_ObjReference_Refcounter<size_t>(&bytesize);
		size_t arraycnt=1;
		test_ObjReference_Refcounter<size_t> eval_arraysize=test_ObjReference_Refcounter<size_t>(&arraycnt);
		int result=1;
		test_ObjReference_Refcounter<int> eval_result=test_ObjReference_Refcounter<int>(&result);
		
		if(1)
		{
			xc_mem_cmp_obj_array_param( int, eval_arraysize.get_val(), eval_targetp.get_refp(), eval_srcp.get_refp(), eval_result.get_refp() );
		}
		
		xcc_test2_expect_eq_t(unsigned int, 1, eval_arraysize.get_cnter() );
		xcc_test2_expect_eq_t(unsigned int, 1, eval_targetp.get_cnter() );
		xcc_test2_expect_eq_t(unsigned int, 1, eval_srcp.get_cnter() );
		xcc_test2_expect_eq_t(unsigned int, 1, eval_result.get_cnter() );
		
		xcc_test2_case_end();
	
	}  while(0);
	
	xcc_test2_scope_end();
}
