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
#include "xcc/common/xcc_cpp.hpp"
#include "xcc/test/xcc_test2.hpp"
/* --- */
#include "test_xc_si_main.hpp"
#include "test_xc_si_impl__add.incl.hpp"
#include "test_xc_si_impl__sub.incl.hpp"
#include "test_xc_si_impl__div.incl.hpp"
#include "test_xc_si_impl__mul.incl.hpp"
/* --- */

int test_xc_si_int(xcc_test2_param_list);

int test_xc_si_int(xcc_test2_param_list)
{
	xcc_test2_scope("xc_si:int: test");
	
	if(1)
	{
		int tmpv=test_si_signed_add<int, xc_si_int_t, test_si_infOp_int<int, xc_si_int_t> >(xcc_test2_param_internal_embedded(), INT_MIN, INT_MAX);
		xcc_test2_expect( 0 == 
			( 
				tmpv
			) 
		);
	}
	
	if(1)
	{
		int tmpv=test_si_signed_sub<int, xc_si_int_t, test_si_infOp_int<int, xc_si_int_t> >(xcc_test2_param_internal_embedded(), INT_MIN, INT_MAX);
		xcc_test2_expect( 0 == 
			( 
				tmpv
			) 
		);
	}

	if(1)
	{
		int tmpv=test_si_signed_div<int, xc_si_int_t, test_si_infOp_int<int, xc_si_int_t> >(xcc_test2_param_internal_embedded(), INT_MIN, INT_MAX);
		xcc_test2_expect( 0 == 
			( 
				tmpv
			) 
		);
	}
	
	if(1)
	{
		int tmpv=test_si_signed_mul<int, xc_si_int_t, test_si_infOp_int<int, xc_si_int_t> >(xcc_test2_param_internal_embedded(), INT_MIN, INT_MAX);
		xcc_test2_expect( 0 == 
			( 
				tmpv
			) 
		);
	}
	
	xcc_test2_scope_end();
}

int test_si_all(void) noexcept
{
	xcc::tval<int> err_cnt=0;
	xcc_test2_procedure result_xc_mem=xcc_test2_procedure();
	
	xcc_test2_procedure result_paramEval_xc_mem_U=xcc_test2_procedure();
	/* --- */
	
	err_cnt+=test_xc_si_int( xcc_test2_param_public_result(&result_xc_mem) );
	/* ---  */

	err_cnt+=result_xc_mem.print_summary("xc_si");
	
	return err_cnt.val();
}

int main()
{
	if(0==test_si_all() ) {
		fprintf(stdout, "[xc_si] test (all):  OK!\n");
	}
	else {
		fprintf(stdout, "[xc_si] test  (all):  error!\n");
		return 1;
	}
	
	return 0;
}
