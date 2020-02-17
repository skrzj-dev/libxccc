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

#ifndef _XCC_TEST_TPL_VECTOR_API_CCCVECTORDS_S_HPP_
#define _XCC_TEST_TPL_VECTOR_API_CCCVECTORDS_S_HPP_

#include "abstracts_functional_any/vector_test_tpl_abstraction_api.hpp"
/* --- */


#define xcc_tplTestVector_vectorIntf__xcVectorDS__s_hdr() template<typename TPL_VTYPE, typename _ARG_TPL_VITEMTYPE_, typename ARG_TPL_DEREFER>
#define xcc_tplTestVector_vectorIntf__xcVectorDS_s_m(TYPE) TYPE xcc_tplTestVector_vectorIntf__xcVectorDS_s <TPL_VTYPE, _ARG_TPL_VITEMTYPE_, ARG_TPL_DEREFER>::


xcc_tplTestVector_vectorIntf__xcVectorDS__s_hdr()
class xcc_tplTestVector_vectorIntf__xcVectorDS_s: public tplTestVector_vectorIntf<TPL_VTYPE, _ARG_TPL_VITEMTYPE_, ARG_TPL_DEREFER>
{
	public: int init(TPL_VTYPE* refp_self) noexcept;
	public: int init(TPL_VTYPE* refp_self, const size_t initial_capacity) noexcept;
	public: int deinit(TPL_VTYPE* refp_self) noexcept;
	
	public: ARG_TPL_DEREFER derefer_retv(TPL_VTYPE* refp_self) noexcept;
	public: int derefer_validate_integrity(TPL_VTYPE* refp_self, ARG_TPL_DEREFER* refp_deref) noexcept;
	public: int derefer_validate_data(ARG_TPL_DEREFER* refp_tpl_deref) noexcept;
	
	public: int push(TPL_VTYPE* refp_self, const _ARG_TPL_VITEMTYPE_* refp_target) noexcept;
	public: int pop(TPL_VTYPE* refp_self) noexcept;
	
	public: int remove_idx(TPL_VTYPE* refp_self, const int idx) noexcept;
	
	public: int insert_idx(TPL_VTYPE* refp_self, const int idx, const _ARG_TPL_VITEMTYPE_* refp_target) noexcept;
	
	public: int set(TPL_VTYPE* refp_self, const int idx, const _ARG_TPL_VITEMTYPE_* refp_target) noexcept;
	
	public: int get_idx_cp(TPL_VTYPE* refp_self, const int idx, _ARG_TPL_VITEMTYPE_*  refp_target) noexcept;
	public: _ARG_TPL_VITEMTYPE_* get_idx_refp(TPL_VTYPE* refp_self, const int idx) noexcept;
	public: _ARG_TPL_VITEMTYPE_& get_idx_val(TPL_VTYPE* refp_self, const int idx) noexcept;

	public: int get_first_cp(TPL_VTYPE* refp_self, _ARG_TPL_VITEMTYPE_*  refp_target) noexcept;
	public: _ARG_TPL_VITEMTYPE_* get_first_refp(TPL_VTYPE* refp_self) noexcept;
	public: _ARG_TPL_VITEMTYPE_ get_first_val(TPL_VTYPE* refp_self) noexcept;

	public: int get_last_cp(TPL_VTYPE* refp_self, _ARG_TPL_VITEMTYPE_*  refp_target) noexcept;
	public: _ARG_TPL_VITEMTYPE_* get_last_refp(TPL_VTYPE* refp_self) noexcept;
	public: _ARG_TPL_VITEMTYPE_ get_last_val(TPL_VTYPE* refp_self) noexcept;
	
	public: size_t DIAG_get_expected_capacity_for_length(const size_t arg_length) noexcept;
	
	public: int get_length(TPL_VTYPE* refp_self) noexcept;
	public: int get_capacity(TPL_VTYPE* refp_self) noexcept;
	
	public: TPL_VTYPE* alloc_init(TPL_VTYPE* refp_self) noexcept;
	public: int dealloc(TPL_VTYPE* refp_self) noexcept;
	
	public: int assignFrom(TPL_VTYPE* refp_self, const TPL_VTYPE* refp_self_src, int* result_overflow) noexcept;
};

#include "_xcvector_ds_api_s.incl.hpp"

#endif
