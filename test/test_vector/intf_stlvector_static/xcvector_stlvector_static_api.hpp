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

#ifndef _XCC_TEST_TPL_VECTOR_API_STLVECTOR_STATIC_HPP_
#define _XCC_TEST_TPL_VECTOR_API_STLVECTOR_STATIC_HPP_

#include "abstracts_functional_any/vector_test_tpl_abstraction_api.hpp"
/* --- */

template<typename TPL_VTYPE, typename _ARG_TPL_VITEMTYPE_, typename ARG_TPL_DEREFER>
class xcc_tplTestVector_vectorIntf__stlVector_static: public tplTestVector_vectorIntf<TPL_VTYPE, _ARG_TPL_VITEMTYPE_, ARG_TPL_DEREFER>
{
	public: int init(TPL_VTYPE* refp_self) noexcept
	{
		*refp_self=std::vector<_ARG_TPL_VITEMTYPE_>();
		return 0;
	}
	
	public: int init(TPL_VTYPE* refp_self, const size_t initial_capacity) noexcept
	{
		
		*refp_self=std::vector<_ARG_TPL_VITEMTYPE_>();
		refp_self->reserve(initial_capacity);
		return 0;
	}
	
	public: int deinit(TPL_VTYPE* refp_self) noexcept
	{
		try
		{
			 refp_self->clear();
		}
		catch(...) {
			return 1;
		}
		
		return 0;
	}
	
	public: ARG_TPL_DEREFER derefer_retv(TPL_VTYPE* refp_self) noexcept
	{
		ARG_TPL_DEREFER retv=ARG_TPL_DEREFER();
		
		return retv;
	}
	
	public: int derefer_validate_integrity(TPL_VTYPE* refp_self, ARG_TPL_DEREFER* refp_deref) noexcept
	{
		return 1;
	}

	public: int derefer_validate_data(ARG_TPL_DEREFER* refp_tpl_deref) noexcept
	{
		return 1;
	}
	
	public: int push(TPL_VTYPE* refp_self, const _ARG_TPL_VITEMTYPE_* refp_target) noexcept
	{
		try
		{
			refp_self->push_back(*refp_target);
		}
		catch(...) {
			return 1;
		}
		
		return 0;
	}

	public: int pop(TPL_VTYPE* refp_self) noexcept
	{
		try
		{
			refp_self->pop_back();
		}
		catch(...) {
			return 1;
		}
		
		return 0;
	}
	
	public: int remove_idx(TPL_VTYPE* refp_self, const int idx) noexcept
	{
		try
		{
			refp_self->erase(refp_self->begin()+idx);
			return 0;
		}
		catch(...) {
			return 1;
		}
	}
	
	public: int insert_idx(TPL_VTYPE* refp_self, const int idx, const _ARG_TPL_VITEMTYPE_* refp_target) noexcept
	{
		try
		{
			refp_self->insert(refp_self->begin()+idx, *refp_target);
		}
		catch(...) {
			return 1;
		}
		return 0;
	}
	
	public: int set(TPL_VTYPE* refp_self, const int idx, const _ARG_TPL_VITEMTYPE_* refp_target) noexcept
	{
		return 1;
	}
	
	public: int get_idx_cp(TPL_VTYPE* refp_self, const int idx, _ARG_TPL_VITEMTYPE_*  refp_target) noexcept
	{
		return 1;
	}
	
	public: _ARG_TPL_VITEMTYPE_* get_idx_refp(TPL_VTYPE* refp_self, const int idx) noexcept
	{
		return NULL;
	}
	
	public: _ARG_TPL_VITEMTYPE_& get_idx_val(TPL_VTYPE* refp_self, const int idx) noexcept
	{
		return refp_self->at(idx);
	}

	public: int get_first_cp(TPL_VTYPE* refp_self, _ARG_TPL_VITEMTYPE_*  refp_target) noexcept
	{
		return 0;
	}
	public: _ARG_TPL_VITEMTYPE_* get_first_refp(TPL_VTYPE* refp_self) noexcept
	{
		_ARG_TPL_VITEMTYPE_* retv=NULL;
		
		return retv;
	}
	public: _ARG_TPL_VITEMTYPE_ get_first_val(TPL_VTYPE* refp_self) noexcept
	{
		_ARG_TPL_VITEMTYPE_ retv=_ARG_TPL_VITEMTYPE_();
		
		return retv;
	}

	public: int get_last_cp(TPL_VTYPE* refp_self, _ARG_TPL_VITEMTYPE_*  refp_target) noexcept
	{
		return 0;
	}
	
	public: _ARG_TPL_VITEMTYPE_* get_last_refp(TPL_VTYPE* refp_self) noexcept
	{
		_ARG_TPL_VITEMTYPE_* retv=NULL;
		
		return retv;
	}
	
	public: _ARG_TPL_VITEMTYPE_ get_last_val(TPL_VTYPE* refp_self) noexcept
	{
		_ARG_TPL_VITEMTYPE_ retv=_ARG_TPL_VITEMTYPE_();
		
		return retv;
	}
	
	public: size_t DIAG_get_expected_capacity_for_length(const size_t arg_length, const size_t arg_cur_capacity) noexcept
	{
		return 0;
	}
	
	public: int get_length(TPL_VTYPE* refp_self) noexcept
	{
		return refp_self->size();
	}

	public: int get_capacity(TPL_VTYPE* refp_self) noexcept
	{
		return refp_self->capacity();
	}

	
	public: TPL_VTYPE* alloc_init(TPL_VTYPE* refp_self) noexcept
	{
		
		return new TPL_VTYPE();
		
	}
	
	public: int dealloc(TPL_VTYPE* refp_self) noexcept
	{
		delete refp_self;
		return 0;
	}
	
	public: int assignFrom(TPL_VTYPE* refp_self, const TPL_VTYPE* refp_self_src, int* result_overflow) noexcept
	{
		//return refp_self->assign(*refp_self_src);
		return 1;
	}
	
	public: int DIAG_is_continuous(void) noexcept
	{
		return 1;
	}
};


#endif

