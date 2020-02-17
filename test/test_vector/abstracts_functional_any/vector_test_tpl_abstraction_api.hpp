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

#ifndef _XCC_VECTORTESTTPL_API_HPP_
#define _XCC_VECTORTESTTPL_API_HPP_


template<typename TPL_VTYPE, typename _ARG_TPL_VITEMTYPE_, typename ARG_TPL_DEREFER>
class tplTestVector_vectorIntf
{
	public: virtual int init(TPL_VTYPE* refp_self) noexcept =0;
	public: virtual int deinit(TPL_VTYPE* refp_self) noexcept =0;
	
	public: virtual ARG_TPL_DEREFER derefer_retv(TPL_VTYPE* refp_self) noexcept =0;
	public: virtual int derefer_validate_integrity(TPL_VTYPE* refp_self, ARG_TPL_DEREFER* refp_deref) noexcept =0;
	public: virtual int derefer_validate_data(ARG_TPL_DEREFER* refp_tpl_deref) noexcept =0;
	
	public: virtual int push(TPL_VTYPE* refp_self, const _ARG_TPL_VITEMTYPE_* refp_target) noexcept =0;
	public: virtual int pop(TPL_VTYPE* refp_self) noexcept =0;
	
	public: virtual int remove_idx(TPL_VTYPE* refp_self, const int idx) noexcept =0;
	public: virtual int insert_idx(TPL_VTYPE* refp_self, const int idx, const _ARG_TPL_VITEMTYPE_* refp_target) noexcept =0;
	
	public: virtual int set(TPL_VTYPE* refp_self, const int idx, const _ARG_TPL_VITEMTYPE_* refp_target) noexcept =0;
	
	public: virtual int get_idx_cp(TPL_VTYPE* refp_self, const int idx, _ARG_TPL_VITEMTYPE_*  refp_target) noexcept =0;
	public: virtual _ARG_TPL_VITEMTYPE_* get_idx_refp(TPL_VTYPE* refp_self, const int idx) noexcept =0;
	public: virtual _ARG_TPL_VITEMTYPE_& get_idx_val(TPL_VTYPE* refp_self, const int idx) noexcept =0;

				public: virtual int get_first_cp(TPL_VTYPE* refp_self, _ARG_TPL_VITEMTYPE_*  refp_target) noexcept =0;
				public: virtual _ARG_TPL_VITEMTYPE_* get_first_refp(TPL_VTYPE* refp_self) noexcept =0;
				public: virtual _ARG_TPL_VITEMTYPE_ get_first_val(TPL_VTYPE* refp_self) noexcept =0;

				public: virtual int get_last_cp(TPL_VTYPE* refp_self, _ARG_TPL_VITEMTYPE_*  refp_target) noexcept =0;
				public: virtual _ARG_TPL_VITEMTYPE_* get_last_refp(TPL_VTYPE* refp_self) noexcept =0;
				public: virtual _ARG_TPL_VITEMTYPE_ get_last_val(TPL_VTYPE* refp_self) noexcept =0;
	
	public: virtual size_t DIAG_get_expected_capacity_for_length(const size_t arg_length) noexcept =0;

	public: virtual int get_length(TPL_VTYPE* refp_self) noexcept =0;
	public: virtual int get_capacity(TPL_VTYPE* refp_self) noexcept =0;
	
	public: virtual TPL_VTYPE* alloc_init(TPL_VTYPE* refp) noexcept =0;
	public: virtual int dealloc(TPL_VTYPE* refp_self) noexcept =0;
	
	public: virtual int assignFrom(TPL_VTYPE* refp_self, const TPL_VTYPE* refp_self_src, int* result_overflow) noexcept =0;
};

#endif
