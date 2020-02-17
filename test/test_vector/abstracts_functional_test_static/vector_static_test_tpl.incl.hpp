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

#include <vector>
/* --- */
#include "xc/common/xc_mem.h"
#include "xcc/common/xcc_cpp.hpp"
#include "xcc/test/xcc_test2.hpp"
/* --- */
#include "vector_static_test_tpl.hpp"
#include "vector_static_test_tpl___internal_hlp.hpp"
/* --- */

#include "vector_static_test_tpl___derefer.incl.hpp"
#include "vector_static_test_tpl___init_deinit.incl.hpp"
#include "vector_static_test_tpl___push.incl.hpp"
#include "vector_static_test_tpl___pop.incl.hpp"
#include "vector_static_test_tpl___insert.incl.hpp"
#include "vector_static_test_tpl___remove.incl.hpp"
#include "vector_static_test_tpl___get.incl.hpp"
#include "vector_static_test_tpl___set.incl.hpp"
#include "vector_static_test_tpl___alloc_dealloc.incl.hpp"
#include "vector_static_test_tpl___copyfrom.incl.hpp"


/* --- */


/* --- */

xcc_tplTestVector_static_hdr()
xcc_tplTestVector_static_method(int) TMP_TEST_INTERNAL_02( 
	  xcc_test2_failureDetails_t& failInfo
	, TPL_VTYPE* vector_obj_ref
	, const size_t expected_length
	, const size_t expected_capacity
	, std::vector<TPL_ITEM_TYPE> expected_items ) noexcept
{
	xcc_test2_scope_disconnected();
	
	do
	{
		xcc_test2_case("checking internal state");
		
		int got_length=vector_I.get_length(vector_obj_ref);
		int got_capacity=vector_I.get_capacity(vector_obj_ref);

		xcc_test2_expect_eq_t(int, expected_length, got_length);
		xcc_test2_expect_eq_t(int, expected_capacity, got_capacity);

		xcc_test2_expect( 0 ==  INTF_INTERNAL_I.verifyInternalState_itemsNumbers(vector_obj_ref, expected_capacity, expected_length) );
		xcc_test2_expect( 0 ==  INTF_INTERNAL_I.verifyInternalState_itemsIntegrity(vector_obj_ref, expected_capacity, expected_length) );
		xcc_test2_expect( 0 ==  INTF_INTERNAL_I.verifyInternalState_itemsValues(vector_obj_ref, expected_capacity, expected_length, expected_items) );
		
		xcc_test2_case_end();
		
		
	} while(0);
	
	xcc_test2_scope_end();
}

xcc_tplTestVector_static_hdr()
xcc_tplTestVector_static_method(int) TMP_TEST_INTERNAL_02_uninitZero( 
	  xcc_test2_failureDetails_t& failInfo
	, TPL_VTYPE* vector_obj_ref
	, const size_t expected_length
	, const size_t expected_capacity
	, std::vector<TPL_ITEM_TYPE> expected_items ) noexcept
{
	xcc_test2_scope_disconnected();
	
	do
	{
		xcc_test2_case("checking internal state");
		
		int got_length=vector_I.get_length(vector_obj_ref);
		int got_capacity=vector_I.get_capacity(vector_obj_ref);

		xcc_test2_expect_eq_t(int, expected_length, got_length);
		xcc_test2_expect_eq_t(int, expected_capacity, got_capacity);

		//xcc_test2_expect( 0 ==  INTF_INTERNAL_I.verifyInternalState_itemsNumbers(vector_obj_ref, expected_capacity, expected_length) );
		//xcc_test2_expect( 0 ==  INTF_INTERNAL_I.verifyInternalState_itemsIntegrity(vector_obj_ref, expected_capacity, expected_length) );
		//xcc_test2_expect( 0 ==  INTF_INTERNAL_I.verifyInternalState_itemsValues(vector_obj_ref, expected_capacity, expected_length, expected_items) );
		
		xcc_test2_case_end();
		
		
	} while(0);
	
	xcc_test2_scope_end();
}



xcc_tplTestVector_static_hdr()
xcc_tplTestVector_static_method(int) perform_test_main(xcc_test2_param_list) noexcept
{
	xcc_test2_scope("STATIC-VECTOR-TEST-ALL");
	
	do
	{
		xcc_test2_case("TEST SEQUENCE: DEREFER 00");
		xcc_test2_expect( 0 == this->test_derefer_00( xcc_test2_param_internal_embedded() ) );
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		xcc_test2_case("TEST SEQUENCE: INIT");
		xcc_test2_expect( 0 == this->test_init( xcc_test2_param_internal_embedded() ) );
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		xcc_test2_case("TEST SEQUENCE: DEREFER 01");
		xcc_test2_expect( 0 == this->test_derefer_01( xcc_test2_param_internal_embedded() ) );
		xcc_test2_case_end();
		
	} while(0);

	do
	{
		xcc_test2_case("TEST SEQUENCE: DEINIT");
		xcc_test2_expect( 0 == this->test_deinit( xcc_test2_param_internal_embedded() ) );
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		xcc_test2_case("TEST SEQUENCE: ALLOC_INIT");
		xcc_test2_expect( 0 == this->test_raii_alloc_init( xcc_test2_param_internal_embedded() ) );
		xcc_test2_case_end();
		
	} while(0);

	do
	{
		xcc_test2_case("TEST SEQUENCE: DEALLOC");
		xcc_test2_expect( 0 == this->test_raii_dealloc( xcc_test2_param_internal_embedded() ) );
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		xcc_test2_case("TEST SEQUENCE: PUSH");
		
		xcc_test2_expect( 0 == this->test_push( xcc_test2_param_internal_embedded() ) );
		
		xcc_test2_case_end();
		
	} while(0);
	
	do
	{
		xcc_test2_case("TEST SEQUENCE: POP");
		xcc_test2_expect( 0 == this->test_pop(  xcc_test2_param_internal_embedded() ) );
		xcc_test2_case_end();
		
	} while(0);

	do
	{
		xcc_test2_case("TEST SEQUENCE: REMOVE");
		xcc_test2_expect( 0 == this->test_rem_idx(  xcc_test2_param_internal_embedded() ) );
		xcc_test2_case_end();
		
	} while(0);

	do
	{
		xcc_test2_case("TEST SEQUENCE: INSERT");
		xcc_test2_expect( 0 == this->test_insert_idx(  xcc_test2_param_internal_embedded() ) );
		xcc_test2_case_end();
		
	} while(0);

	do
	{
		xcc_test2_case("TEST SEQUENCE: GET");
		xcc_test2_expect( 0 == this->test_get(  xcc_test2_param_internal_embedded() ) );
		xcc_test2_case_end();
		
	} while(0);

	do
	{
		xcc_test2_case("TEST SEQUENCE: SET");
		xcc_test2_expect( 0 == this->test_set(  xcc_test2_param_internal_embedded() ) );
		xcc_test2_case_end();
		
	} while(0);
	
	if(1)
	{
		do
		{
			xcc_test2_case("TEST SEQUENCE: COPYFROM");
			xcc_test2_expect( 0 == this->test_copyFrom_all(  xcc_test2_param_internal_embedded() ) );
			xcc_test2_case_end();
			
		} while(0);
	}
	
	xcc_test2_scope_end();
}

