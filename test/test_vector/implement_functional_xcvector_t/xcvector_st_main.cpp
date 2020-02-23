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

#include "abstracts_functional_test_static/vector_static_test_tpl.hpp"

/* --- */
#include "xc/tcvector_t/xc_tcvector_t.h"

#include "intf_xcvector_t/_xcvector_st_api_i_hlp.hpp"
#include "intf_xcvector_t/xcvector_st.hpp"

#include "xcvector_st_main.hpp"

#include "_xcvector_st_param_evaluation.hpp"

/* --- */


static int test_vectT_u(xcc_test2_param_list) noexcept;
static int test_vectT_s(xcc_test2_param_list) noexcept;
static int test_vectT_i(xcc_test2_param_list) noexcept;

static int test_vectT_u(xcc_test2_param_list) noexcept
{
	xcc_tplTestVector_static< 
			  seqST_dummyItem_t
			, xc_tcVectorT_LL_deref_t
			, dummyItem_t
			, testXcVectorT::intf_api_u< seqST_dummyItem_t, dummyItem_t, xc_tcVectorT_LL_deref_t > 
			, testIntf_internal_xcVectorST_intf< seqST_dummyItem_t, dummyItem_t, xc_tcVectorT_LL_deref_t, xcc_tplTestVector_itemIntf_obj1< dummyItem_t >  > 
			, xcc_tplTestVector_itemIntf_obj1< dummyItem_t > 
	> seqVectorTest_intf;
	
	return seqVectorTest_intf.perform_test_main( xcc_test2_param_list_forward );
}

static int test_vectT_s(xcc_test2_param_list) noexcept
{
	xcc_tplTestVector_static< 
			  seqST_dummyItem_t
			, xc_tcVectorT_LL_deref_t
			, dummyItem_t
			, testXcVectorT::intf_api_s< seqST_dummyItem_t, dummyItem_t, xc_tcVectorT_LL_deref_t > 
			, testIntf_internal_xcVectorST_intf< seqST_dummyItem_t, dummyItem_t, xc_tcVectorT_LL_deref_t, xcc_tplTestVector_itemIntf_obj1< dummyItem_t >  > 
			, xcc_tplTestVector_itemIntf_obj1< dummyItem_t > 
	> seqVectorTest_intf;
	
	return seqVectorTest_intf.perform_test_main( xcc_test2_param_list_forward );
}

static int test_vectT_i(xcc_test2_param_list) noexcept
{
	xcc_tplTestVector_static< 
			  seqST_dummyItem_t
			, xc_tcVectorT_LL_deref_t
			, dummyItem_t
			, testXcVectorT::intf_api_i< seqST_dummyItem_t, dummyItem_t, xc_tcVectorT_LL_deref_t > 
			, testIntf_internal_xcVectorST_intf< seqST_dummyItem_t, dummyItem_t, xc_tcVectorT_LL_deref_t, xcc_tplTestVector_itemIntf_obj1< dummyItem_t >  > 
			, xcc_tplTestVector_itemIntf_obj1< dummyItem_t > 
	> seqVectorTest_intf;
	
	return seqVectorTest_intf.perform_test_main( xcc_test2_param_list_forward );
}


int test_seqST_x()
{
	const xc_tcVectorT_i_type(seqST_dummyItem_t, dummyItem_t) tmpI=xc_tcVectorT_i_refI(seqST_dummyItem_t, dummyItem_t);
	xcc_err_decl();
	
	seqST_dummyItem_t_I.clear(NULL);
	tmpI.clear(NULL);
	
	try
	{
		xcc_test2_wrapper testrun_paramEval=xcc_test2_wrapper("[vectT_x] param eval test", std::function<int(xcc_test2_testParamObj_t)>(test_paramEvaluationCnt_xcVectorST_main) );
		xcc_test2_wrapper testrun_vectT_u=xcc_test2_wrapper("[vectT_u] test", std::function<int(xcc_test2_testParamObj_t)>(test_vectT_u) );
		xcc_test2_wrapper testrun_vectT_s=xcc_test2_wrapper("[vectT_s] test", std::function<int(xcc_test2_testParamObj_t)>(test_vectT_s) );
		xcc_test2_wrapper testrun_vectT_i=xcc_test2_wrapper("[vectT_i] test", std::function<int(xcc_test2_testParamObj_t)>(test_vectT_i) );
		
		testrun_paramEval.run_throwErr();
		testrun_vectT_u.run_throwErr();
		testrun_vectT_s.run_throwErr();
		testrun_vectT_i.run_throwErr();

		testrun_paramEval.summary();
		testrun_vectT_u.summary();
		testrun_vectT_s.summary();
		testrun_vectT_i.summary();
		
	}
	catch(...)
	{
		xcc_err_term_unmg();
		return 1;
	}
	
	fprintf(stdout, "[vectT_x] ALL TESTS DONE OK\n");
	
	return 0;
}
