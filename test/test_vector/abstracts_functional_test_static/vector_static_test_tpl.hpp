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

#ifndef _XCC_VECTORTESTTPL_STATIC_HPP_
#define _XCC_VECTORTESTTPL_STATIC_HPP_

#include <vector>

#include "xcc/test/xcc_test2.hpp"

#include "abstracts_functional_any/vector_test_tpl_abstraction_item.hpp"
#include "abstracts_functional_any/vector_test_tpl___param_evaluation_check.hpp"




#define xcc_tplTestVector_static_hdr() template<typename TPL_VTYPE, typename _TPL_DEREFER_TYPE_, typename TPL_ITEM_TYPE, class _TPL_INTF_, class _TPL_INTF_INTERNAL_, class _TPL_LLII_ >

#define xcc_tplTestVector_static_method(_FNTYPE_) _FNTYPE_ xcc_tplTestVector_static<TPL_VTYPE, _TPL_DEREFER_TYPE_, TPL_ITEM_TYPE, _TPL_INTF_, _TPL_INTF_INTERNAL_, _TPL_LLII_>::


xcc_tplTestVector_static_hdr()
class xcc_tplTestVector_static 
{
	public: int test_init(xcc_test2_param_list) noexcept;
	public: int test_deinit(xcc_test2_param_list) noexcept;
	
	public: int test_push(xcc_test2_param_list) noexcept;
	public: int test_pop(xcc_test2_param_list) noexcept;
	
	public: int test_rem_idx(xcc_test2_param_list) noexcept;
	
	private: int test_insert_idx___0_err(xcc_test2_param_list) noexcept;
	private: int test_insert_idx___1_start(xcc_test2_param_list) noexcept;
	private: int test_insert_idx___2_end(xcc_test2_param_list) noexcept;
	private: int test_insert_idx___3_middle_N1(xcc_test2_param_list) noexcept;
	private: int test_insert_idx___3_middle_N2(xcc_test2_param_list) noexcept;
	public: int test_insert_idx(xcc_test2_param_list) noexcept;
	
	public: int test_get(xcc_test2_param_list) noexcept;
	
	public: int test_set(xcc_test2_param_list) noexcept;

	public: int test_raii_dealloc(xcc_test2_param_list) noexcept;
	public: int test_raii_alloc_init(xcc_test2_param_list) noexcept;
	
	public: int test_derefer_00(xcc_test2_param_list) noexcept;
	public: int test_derefer_01(xcc_test2_param_list) noexcept;
	
	private: int test_copyFrom_errors(xcc_test2_param_list) noexcept;
	private: int test_copyFrom_ok(xcc_test2_param_list) noexcept;
	public: int test_copyFrom_all(xcc_test2_param_list) noexcept;
	
	public: int perform_test_main(xcc_test2_param_list) noexcept;
	
	private: int TMP_TEST_INTERNAL_02( xcc_test2_failureDetails_t& failInfo,  
		  TPL_VTYPE* vector_obj_ref
		, const size_t expected_length
		, std::vector<TPL_ITEM_TYPE> expected_items
	) noexcept;
	
	private: int TMP_TEST_INTERNAL_02_cap( xcc_test2_failureDetails_t& failInfo,  
		  TPL_VTYPE* vector_obj_ref
		, const size_t expected_length
		, const size_t expected_capacity
		, std::vector<TPL_ITEM_TYPE> expected_items
	) noexcept;
	
	
	private: int TMP_TEST_INTERNAL_02_uninitZero( xcc_test2_failureDetails_t& failInfo,  
		  TPL_VTYPE* vector_obj_ref
		, const size_t expected_length
		, std::vector<TPL_ITEM_TYPE> expected_items
	) noexcept;
		
	private: _TPL_INTF_ vector_I;
	private: _TPL_LLII_ LLII_I;
	private: _TPL_INTF_INTERNAL_ INTF_INTERNAL_I;
	
};


#include "vector_static_test_tpl.incl.hpp"


#endif
