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
#include "xc/tcpool_t/xc_tcpool_t.h"
/* --- */
#include "intf_xcpool_t/xcpool_ts.hpp"
#include "xcpool_ts_main.hpp"
/* --- */



static int test_poolT_u(xcc_test2_param_list) noexcept;
static int test_poolT_s(xcc_test2_param_list) noexcept;
static int test_poolT_i(xcc_test2_param_list) noexcept;

static int test_poolT_u(xcc_test2_param_list) noexcept
{
	
	xcc_tplTestVector_static< 
		  xcPoolTS_dummyItem_t
		, xc_tcPoolT_LL_deref_t
		, dummyItem_t
		, testXcPoolT::intf_api_u< 
				  xcPoolTS_dummyItem_t
				, dummyItem_t
				, xc_tcPoolT_LL_deref_t 
			> 
		, testXcPoolT::intf_internal< 
				  xcPoolTS_dummyItem_t
				, dummyItem_t
				, xc_tcPoolT_LL_deref_t
				, xcc_tplTestVector_itemIntf_obj1< dummyItem_t >  
			> 
		, xcc_tplTestVector_itemIntf_obj1< dummyItem_t > 
	> poolTVectorTest_intf;
	
	return poolTVectorTest_intf.perform_test_main( xcc_test2_param_list_forward );
}

static int test_poolT_s(xcc_test2_param_list) noexcept
{
	xcc_tplTestVector_static< 
		  xcPoolTS_dummyItem_t
		, xc_tcPoolT_LL_deref_t
		, dummyItem_t
		, testXcPoolT::intf_api_s< 
				  xcPoolTS_dummyItem_t
				, dummyItem_t
				, xc_tcPoolT_LL_deref_t 
			> 
		, testXcPoolT::intf_internal< 
				  xcPoolTS_dummyItem_t
				, dummyItem_t
				, xc_tcPoolT_LL_deref_t
				, xcc_tplTestVector_itemIntf_obj1< dummyItem_t >  
			> 
		, xcc_tplTestVector_itemIntf_obj1< dummyItem_t > 
	> poolTVectorTest_intf;
	
	return poolTVectorTest_intf.perform_test_main( xcc_test2_param_list_forward );
}

static int test_poolT_i(xcc_test2_param_list) noexcept
{
	xcc_tplTestVector_static< 
		  xcPoolTS_dummyItem_t
		, xc_tcPoolT_LL_deref_t
		, dummyItem_t
		, testXcPoolT::intf_api_i< 
				  xcPoolTS_dummyItem_t
				, dummyItem_t
				, xc_tcPoolT_LL_deref_t 
			> 
		, testXcPoolT::intf_internal< 
				  xcPoolTS_dummyItem_t
				, dummyItem_t
				, xc_tcPoolT_LL_deref_t
				, xcc_tplTestVector_itemIntf_obj1< dummyItem_t >  
			> 
		, xcc_tplTestVector_itemIntf_obj1< dummyItem_t > 
	> 
	poolTVectorTest_intf;
	
	return poolTVectorTest_intf.perform_test_main( xcc_test2_param_list_forward );
}


int test_xcPoolTS_x()
{
	xcc_err_decl();
	
	const xc_tcPoolT_i_type(xcPoolTS_dummyItem_t, dummyItem_t) tmpI=xc_tcPoolT_i_refI(xcPoolTS_dummyItem_t, dummyItem_t);
	xcPoolTS_dummyItem_t_I.clear(NULL);
	tmpI.clear(NULL);

	
	try
	{
		//xcc_test2_wrapper testrun_paramEval=xcc_test2_wrapper("[poolT_x] param eval test", std::function<int(xcc_test2_testParamObj_t)>(test_paramEvaluationCnt_xcVectorD_main) );
		xcc_test2_wrapper testrun_poolT_u=xcc_test2_wrapper("[poolT_u] test", std::function<int(xcc_test2_testParamObj_t)>(test_poolT_u) );
		xcc_test2_wrapper testrun_poolT_s=xcc_test2_wrapper("[poolT_s] test", std::function<int(xcc_test2_testParamObj_t)>(test_poolT_s) );
		xcc_test2_wrapper testrun_poolT_i=xcc_test2_wrapper("[poolT_i] test", std::function<int(xcc_test2_testParamObj_t)>(test_poolT_i) );
		
		//testrun_paramEval.run_throwErr();
		testrun_poolT_u.run_throwErr();
		testrun_poolT_s.run_throwErr();
		testrun_poolT_i.run_throwErr();

		//testrun_paramEval.summary();
		testrun_poolT_u.summary();
		testrun_poolT_s.summary();
		testrun_poolT_i.summary();
		
	}
	catch(...)
	{
		xcc_err_term_unmg();
		return 1;
	}
	
	fprintf(stdout, "[poolT_x] ALL TESTS DONE OK\n");
	
	return 0;
}

