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
#include "test_xc_mem__cmem.hpp"
#include "test_xc_mem__cmem_u.hpp"
#include "test_xc_mem__cmem_s.hpp"

#include "test_xc_mem_main.hpp"
#include "test_xc_mem_macroparameval__cmem_u.hpp"
#include "test_xc_mem_macroparameval__cmem_s.hpp"
#include "test_xc_mem_macroparameval__cmem.hpp"
/* --- */

int test_cmem_all(void) noexcept
{
	xcc::tval<int> err_cnt=0;
	xcc_test2_procedure result_xc_mem=xcc_test2_procedure();
	xcc_test2_procedure result_xc_mem_u=xcc_test2_procedure();
	xcc_test2_procedure result_xc_mem_s=xcc_test2_procedure();
	
	xcc_test2_procedure result_paramEval_xc_mem_U=xcc_test2_procedure();
	xcc_test2_procedure result_paramEval_xc_mem_S=xcc_test2_procedure();
	xcc_test2_procedure result_paramEval_xc_mem_M=xcc_test2_procedure();
	/* --- */
	
	err_cnt+=test_xc_mem( xcc_test2_param_public_result(&result_xc_mem) );
	err_cnt+=test_xc_mem_u( xcc_test2_param_public_result(&result_xc_mem_u) );
	err_cnt+=test_xc_mem_s( xcc_test2_param_public_result(&result_xc_mem_s) );
	/* ---  */
	
	err_cnt+=test_cmem_eval__cmem_u( xcc_test2_param_public_result(&result_paramEval_xc_mem_U) );
	err_cnt+=test_cmem_eval__cmem_s( xcc_test2_param_public_result(&result_paramEval_xc_mem_S) );
	err_cnt+=test_cmem_eval__cmem( xcc_test2_param_public_result(&result_paramEval_xc_mem_M) );
	
	err_cnt+=result_xc_mem.print_summary("xc_mem");
	err_cnt+=result_xc_mem_u.print_summary("xc_mem_u");
	err_cnt+=result_xc_mem_s.print_summary("xc_mem_s");
	
	result_paramEval_xc_mem_M.print_summary("macro param eval:xc_mem");
	result_paramEval_xc_mem_U.print_summary("macro param eval:xc_mem_u");
	result_paramEval_xc_mem_S.print_summary("macro param eval:xc_mem_s");
	
	return err_cnt.val();
}

int main()
{
	if(0==test_cmem_all() ) {
		fprintf(stdout, "xc_cmem test (all):  OK!\n");
	}
	else {
		fprintf(stdout, "xc_cmem test  (all):  error!\n");
		return 1;
	}
	
	
	return 0;
}
