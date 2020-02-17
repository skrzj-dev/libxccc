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

#include <stdio.h>
#include <exception>
#include <stdexcept>
#include <vector>
/* --- */
#include "xcc/common/xcc_err.hpp"
#include "xcc/test/xcc_test2.hpp"
/* --- */
#include "xc/tcvector_d/xc_tcvector_d.h"
/* --- */


#include "xcvector_d_main.hpp"
#include "intf_xcvector_d/xcvector_d.hpp"
#include "abstracts_functional_any/vector_test_tpl_abstraction_item.hpp"

#include "implement_functional_xcvector_d/_xcvector_d_param_evaluation.hpp"
#include "abstracts_functional_test_dynamic/vector_dynamic_test_tpl.hpp"
#include "intf_xcvector_d/xcvector_d.hpp"

static int test_seqD_u(xcc_test2_param_list) noexcept;
static int test_seqD_s(xcc_test2_param_list) noexcept;
static int test_seqD_i(xcc_test2_param_list) noexcept;

static int test_seqD_u(xcc_test2_param_list) noexcept
{
	xcc_tplTestVector_dynamic< 
			  seq_dummyItem_t
			, xc_tcVectorD_LL_deref_t
			, dummyItem_t
			, xcc_tplTestVector_vectorIntf__xcVectorD_u< seq_dummyItem_t, dummyItem_t, xc_tcVectorD_LL_deref_t > 
			, testIntf_internal_xcVectorD< seq_dummyItem_t, dummyItem_t, xc_tcVectorD_LL_deref_t, xcc_tplTestVector_itemIntf_obj1< dummyItem_t >  > 
			, xcc_tplTestVector_itemIntf_obj1< dummyItem_t > 
	> seqVectorTest_intf;
	
	return seqVectorTest_intf.perform_test_main( xcc_test2_param_list_forward );
}

static int test_seqD_s(xcc_test2_param_list) noexcept
{
	xcc_tplTestVector_dynamic< 
			  seq_dummyItem_t
			, xc_tcVectorD_LL_deref_t
			, dummyItem_t
			, xcc_tplTestVector_vectorIntf__xcVectorD_s< seq_dummyItem_t, dummyItem_t, xc_tcVectorD_LL_deref_t > 
			, testIntf_internal_xcVectorD< seq_dummyItem_t, dummyItem_t, xc_tcVectorD_LL_deref_t, xcc_tplTestVector_itemIntf_obj1< dummyItem_t >  > 
			, xcc_tplTestVector_itemIntf_obj1< dummyItem_t > 
	> seqVectorTest_intf;
	
	return seqVectorTest_intf.perform_test_main( xcc_test2_param_list_forward );
}

static int test_seqD_i(xcc_test2_param_list) noexcept
{
	xcc_tplTestVector_dynamic< 
			  seq_dummyItem_t
			, xc_tcVectorD_LL_deref_t
			, dummyItem_t
			, xcc_tplTestVector_vectorIntf__xcVectorD_i< seq_dummyItem_t, dummyItem_t, xc_tcVectorD_LL_deref_t> 
			, testIntf_internal_xcVectorD< seq_dummyItem_t, dummyItem_t, xc_tcVectorD_LL_deref_t, xcc_tplTestVector_itemIntf_obj1< dummyItem_t >  > 
			, xcc_tplTestVector_itemIntf_obj1< dummyItem_t > 
	> seqVectorTest_intf;
	
	return seqVectorTest_intf.perform_test_main( xcc_test2_param_list_forward );
}

int test_seqD_x()
{
	const xc_tcVectorD_i_type(seq_dummyItem_t, dummyItem_t) tmpI=xc_tcVectorD_i_refI(seq_dummyItem_t, dummyItem_t);
	xcc_err_decl();
	
	seq_dummyItem_t_I.clear(NULL);
	tmpI.clear(NULL);
	
	try
	{
		xcc_test2_wrapper testrun_paramEval=xcc_test2_wrapper("[seqDS_x] param eval test", std::function<int(xcc_test2_testParamObj_t)>(test_paramEvaluationCnt_xcVectorD_main) );
		xcc_test2_wrapper testrun_seqD_u=xcc_test2_wrapper("[seqD_u] test", std::function<int(xcc_test2_testParamObj_t)>(test_seqD_u) );
		xcc_test2_wrapper testrun_seqD_s=xcc_test2_wrapper("[seqD_s] test", std::function<int(xcc_test2_testParamObj_t)>(test_seqD_s) );
		xcc_test2_wrapper testrun_seqD_i=xcc_test2_wrapper("[seqD_i] test", std::function<int(xcc_test2_testParamObj_t)>(test_seqD_i) );
		
		testrun_paramEval.run_throwErr();
		testrun_seqD_u.run_throwErr();
		testrun_seqD_s.run_throwErr();
		testrun_seqD_i.run_throwErr();

		testrun_paramEval.summary();
		testrun_seqD_u.summary();
		testrun_seqD_s.summary();
		testrun_seqD_i.summary();
		
	}
	catch(...)
	{
		xcc_err_term_unmg();
		return 1;
	}
	
	fprintf(stdout, "[seqD_x] ALL TESTS DONE OK\n");
	
	return 0;
}

