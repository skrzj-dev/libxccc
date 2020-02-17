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
#include "xc/tcvector_s/xc_tcvector_s.h"

#include "intf_xcvector_s/_xcvector_ds_api_i_hlp.hpp"
#include "intf_xcvector_s/xcvector_ds.hpp"

#include "xcvector_ds_main.hpp"

#include "_xcvector_ds_param_evaluation.hpp"

/* --- */

static int test_seqDS_u(xcc_test2_param_list) noexcept;
static int test_seqDS_s(xcc_test2_param_list) noexcept;
static int test_seqDS_i(xcc_test2_param_list) noexcept;

static int test_seqDS_u(xcc_test2_param_list) noexcept
{
	xcc_tplTestVector_static< 
			  seqDS_dummyItem_t
			, xc_tcVectorS_LL_deref_t
			, dummyItem_t
			, xcc_tplTestVector_vectorIntf__xcVectorDS_u< seqDS_dummyItem_t, dummyItem_t, xc_tcVectorS_LL_deref_t > 
			, testIntf_internal_xcVectorDS_intf< seqDS_dummyItem_t, dummyItem_t, xc_tcVectorS_LL_deref_t, xcc_tplTestVector_itemIntf_obj1< dummyItem_t >  > 
			, xcc_tplTestVector_itemIntf_obj1< dummyItem_t > 
	> seqVectorTest_intf;
	
	return seqVectorTest_intf.perform_test_main( xcc_test2_param_list_forward );
}

static int test_seqDS_s(xcc_test2_param_list) noexcept
{
	xcc_tplTestVector_static< 
			  seqDS_dummyItem_t
			, xc_tcVectorS_LL_deref_t
			, dummyItem_t
			, xcc_tplTestVector_vectorIntf__xcVectorDS_s< seqDS_dummyItem_t, dummyItem_t, xc_tcVectorS_LL_deref_t > 
			, testIntf_internal_xcVectorDS_intf< seqDS_dummyItem_t, dummyItem_t, xc_tcVectorS_LL_deref_t, xcc_tplTestVector_itemIntf_obj1< dummyItem_t >  > 
			, xcc_tplTestVector_itemIntf_obj1< dummyItem_t > 
	> seqVectorTest_intf;
	
	return seqVectorTest_intf.perform_test_main( xcc_test2_param_list_forward );
}

static int test_seqDS_i(xcc_test2_param_list) noexcept
{
	xcc_tplTestVector_static< 
			  seqDS_dummyItem_t
			, xc_tcVectorS_LL_deref_t
			, dummyItem_t
			, xcc_tplTestVector_vectorIntf__xcVectorDS_i< seqDS_dummyItem_t, dummyItem_t, xc_tcVectorS_LL_deref_t > 
			, testIntf_internal_xcVectorDS_intf< seqDS_dummyItem_t, dummyItem_t, xc_tcVectorS_LL_deref_t, xcc_tplTestVector_itemIntf_obj1< dummyItem_t >  > 
			, xcc_tplTestVector_itemIntf_obj1< dummyItem_t > 
	> seqVectorTest_intf;
	
	return seqVectorTest_intf.perform_test_main( xcc_test2_param_list_forward );
}


int test_seqDS_x(void)
{
	const xc_tcVectorS_i_type(seqDS_dummyItem_t, dummyItem_t) tmpI=xc_tcVectorS_i_refI(seqDS_dummyItem_t, dummyItem_t);
	xcc_err_decl();
	
	seqDS_dummyItem_t_I.clear(NULL);
	tmpI.clear(NULL);
	
	try
	{
		xcc_test2_wrapper testrun_paramEval=xcc_test2_wrapper("[seqDS_x] param eval test", std::function<int(xcc_test2_testParamObj_t)>(test_paramEvaluationCnt_xcVectorDS_main) );
		xcc_test2_wrapper testrun_seqDS_u=xcc_test2_wrapper("[seqDS_u] test", std::function<int(xcc_test2_testParamObj_t)>(test_seqDS_u) );
		xcc_test2_wrapper testrun_seqDS_s=xcc_test2_wrapper("[seqDS_s] test", std::function<int(xcc_test2_testParamObj_t)>(test_seqDS_s) );
		xcc_test2_wrapper testrun_seqDS_i=xcc_test2_wrapper("[seqDS_i] test", std::function<int(xcc_test2_testParamObj_t)>(test_seqDS_i) );
		
		testrun_paramEval.run_throwErr();
		testrun_seqDS_u.run_throwErr();
		testrun_seqDS_s.run_throwErr();
		testrun_seqDS_i.run_throwErr();

		testrun_paramEval.summary();
		testrun_seqDS_u.summary();
		testrun_seqDS_s.summary();
		testrun_seqDS_i.summary();
		
	}
	catch(...)
	{
		xcc_err_term_unmg();
		return 1;
	}
	
	fprintf(stdout, "[seqDS_x] ALL TESTS DONE OK\n");
	
	return 0;
}
