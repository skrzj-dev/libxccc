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
#include "xc/tcpool_s/xc_tcpool_s.h"
/* --- */
#include "intf_xcpool_s/xcpool_ds.hpp"
#include "xcpool_ds_main.hpp"
/* --- */



static int test_poolS_u(xcc_test2_param_list) noexcept;
static int test_poolS_s(xcc_test2_param_list) noexcept;
static int test_poolS_i(xcc_test2_param_list) noexcept;

static int test_poolS_u(xcc_test2_param_list) noexcept
{
	
	xcc_tplTestVector_static< 
		  xcPoolDS_dummyItem_t
		, xc_tcPoolS_LL_deref_t
		, dummyItem_t
		, xcc_tplTestVector_vectorIntf__xcPoolDS_u< 
				  xcPoolDS_dummyItem_t
				, dummyItem_t
				, xc_tcPoolS_LL_deref_t 
			> 
		, testIntf_internal_xcPoolDS_intf< 
				  xcPoolDS_dummyItem_t
				, dummyItem_t
				, xc_tcPoolS_LL_deref_t
				, xcc_tplTestVector_itemIntf_obj1< dummyItem_t >  
			> 
		, xcc_tplTestVector_itemIntf_obj1< dummyItem_t > 
	> poolSVectorTest_intf;
	
	return poolSVectorTest_intf.perform_test_main( xcc_test2_param_list_forward );
}

static int test_poolS_s(xcc_test2_param_list) noexcept
{
	xcc_tplTestVector_static< 
		  xcPoolDS_dummyItem_t
		, xc_tcPoolS_LL_deref_t
		, dummyItem_t
		, xcc_tplTestVector_vectorIntf__xcPoolDS_s< 
				  xcPoolDS_dummyItem_t
				, dummyItem_t
				, xc_tcPoolS_LL_deref_t 
			> 
		, testIntf_internal_xcPoolDS_intf< 
				  xcPoolDS_dummyItem_t
				, dummyItem_t
				, xc_tcPoolS_LL_deref_t
				, xcc_tplTestVector_itemIntf_obj1< dummyItem_t >  
			> 
		, xcc_tplTestVector_itemIntf_obj1< dummyItem_t > 
	> poolSVectorTest_intf;
	
	return poolSVectorTest_intf.perform_test_main( xcc_test2_param_list_forward );
}

static int test_poolS_i(xcc_test2_param_list) noexcept
{
	xcc_tplTestVector_static< 
		  xcPoolDS_dummyItem_t
		, xc_tcPoolS_LL_deref_t
		, dummyItem_t
		, tplTestVector_vectorIntf__xcPoolS_i< 
				  xcPoolDS_dummyItem_t
				, dummyItem_t
				, xc_tcPoolS_LL_deref_t 
			> 
		, testIntf_internal_xcPoolDS_intf< 
				  xcPoolDS_dummyItem_t
				, dummyItem_t
				, xc_tcPoolS_LL_deref_t
				, xcc_tplTestVector_itemIntf_obj1< dummyItem_t >  
			> 
		, xcc_tplTestVector_itemIntf_obj1< dummyItem_t > 
	> 
	poolSVectorTest_intf;
	
	return poolSVectorTest_intf.perform_test_main( xcc_test2_param_list_forward );
}


int test_xcPoolDS_x()
{
	xcc_err_decl();
	
	const xc_tcPoolS_i_type(xcPoolDS_dummyItem_t, dummyItem_t) tmpI=xc_tcPoolS_i_refI(xcPoolDS_dummyItem_t, dummyItem_t);
	xcPoolDS_dummyItem_t_I.clear(NULL);
	tmpI.clear(NULL);

	
	try
	{
		//xcc_test2_wrapper testrun_paramEval=xcc_test2_wrapper("[poolS_x] param eval test", std::function<int(xcc_test2_testParamObj_t)>(test_paramEvaluationCnt_xcVectorD_main) );
		xcc_test2_wrapper testrun_poolS_u=xcc_test2_wrapper("[poolS_u] test", std::function<int(xcc_test2_testParamObj_t)>(test_poolS_u) );
		xcc_test2_wrapper testrun_poolS_s=xcc_test2_wrapper("[poolS_s] test", std::function<int(xcc_test2_testParamObj_t)>(test_poolS_s) );
		xcc_test2_wrapper testrun_poolS_i=xcc_test2_wrapper("[poolS_i] test", std::function<int(xcc_test2_testParamObj_t)>(test_poolS_i) );
		
		//testrun_paramEval.run_throwErr();
		testrun_poolS_u.run_throwErr();
		testrun_poolS_s.run_throwErr();
		testrun_poolS_i.run_throwErr();

		//testrun_paramEval.summary();
		testrun_poolS_u.summary();
		testrun_poolS_s.summary();
		testrun_poolS_i.summary();
		
	}
	catch(...)
	{
		xcc_err_term_unmg();
		return 1;
	}
	
	fprintf(stdout, "[poolS_x] ALL TESTS DONE OK\n");
	
	return 0;
}

