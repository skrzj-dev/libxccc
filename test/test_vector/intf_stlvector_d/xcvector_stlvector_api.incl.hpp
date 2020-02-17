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

/* --- */
#include <vector>
/* --- */
/* --- */
/* --- */

/* --- --- --- --- */
/* --- --- --- --- */

xcc_tplTestVector_vectorIntf__stlVector_hdr()
xcc_tplTestVector_vectorIntf__stlVector_m(ARG_TPL_DEREFER) derefer_retv(TPL_VTYPE* refp_self) noexcept
{
	ARG_TPL_DEREFER retv=ARG_TPL_DEREFER();
	
	return retv;
}

xcc_tplTestVector_vectorIntf__stlVector_hdr()
xcc_tplTestVector_vectorIntf__stlVector_m(int) derefer_validate_integrity(TPL_VTYPE* refp_self, ARG_TPL_DEREFER* refp_tpl_deref) noexcept
{
	return 1;
}

xcc_tplTestVector_vectorIntf__stlVector_hdr()
xcc_tplTestVector_vectorIntf__stlVector_m(int) derefer_validate_data(ARG_TPL_DEREFER* refp_tpl_deref) noexcept
{
	return 1;
}
/* --- --- --- --- */
/* --- --- --- --- */


xcc_tplTestVector_vectorIntf__stlVector_hdr()
xcc_tplTestVector_vectorIntf__stlVector_m(int) init(TPL_VTYPE* refp_self) noexcept
{
	*refp_self=std::vector<_ARG_TPL_VITEMTYPE_>();
	return 0;
	
}


xcc_tplTestVector_vectorIntf__stlVector_hdr()
xcc_tplTestVector_vectorIntf__stlVector_m(int) deinit(TPL_VTYPE* refp_self) noexcept
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


/* --- --- --- --- */
/* --- --- --- --- */

xcc_tplTestVector_vectorIntf__stlVector_hdr()
xcc_tplTestVector_vectorIntf__stlVector_m(int) get_first_cp(TPL_VTYPE* refp_self, _ARG_TPL_VITEMTYPE_* refp_target) noexcept
{
	return 0;
}

xcc_tplTestVector_vectorIntf__stlVector_hdr()
xcc_tplTestVector_vectorIntf__stlVector_m(_ARG_TPL_VITEMTYPE_*) get_first_refp(TPL_VTYPE* refp_self) noexcept
{
	_ARG_TPL_VITEMTYPE_* retv=NULL;
	
	return retv;
}

xcc_tplTestVector_vectorIntf__stlVector_hdr()
xcc_tplTestVector_vectorIntf__stlVector_m(_ARG_TPL_VITEMTYPE_) get_first_val(TPL_VTYPE* refp_self) noexcept
{
	_ARG_TPL_VITEMTYPE_ retv=_ARG_TPL_VITEMTYPE_();
	
	return retv;
}

xcc_tplTestVector_vectorIntf__stlVector_hdr()
xcc_tplTestVector_vectorIntf__stlVector_m(int) get_idx_cp(TPL_VTYPE* refp_self, const int idx, _ARG_TPL_VITEMTYPE_* refp_target) noexcept
{
	return 1;
}

xcc_tplTestVector_vectorIntf__stlVector_hdr()
xcc_tplTestVector_vectorIntf__stlVector_m(_ARG_TPL_VITEMTYPE_*) get_idx_refp(TPL_VTYPE* refp_self, const int idx) noexcept
{
	return NULL;
}

xcc_tplTestVector_vectorIntf__stlVector_hdr()
xcc_tplTestVector_vectorIntf__stlVector_m(_ARG_TPL_VITEMTYPE_&) get_idx_val(TPL_VTYPE* refp_self, const int idx) noexcept
{
	return refp_self->at(idx);
}

xcc_tplTestVector_vectorIntf__stlVector_hdr()
xcc_tplTestVector_vectorIntf__stlVector_m(int) get_last_cp(TPL_VTYPE* refp_self, _ARG_TPL_VITEMTYPE_* refp_target) noexcept
{
	return 0;
}

xcc_tplTestVector_vectorIntf__stlVector_hdr()
xcc_tplTestVector_vectorIntf__stlVector_m(_ARG_TPL_VITEMTYPE_*) get_last_refp(TPL_VTYPE* refp_self) noexcept
{
	_ARG_TPL_VITEMTYPE_* retv=NULL;
	
	return retv;
}

xcc_tplTestVector_vectorIntf__stlVector_hdr()
xcc_tplTestVector_vectorIntf__stlVector_m(_ARG_TPL_VITEMTYPE_) get_last_val(TPL_VTYPE* refp_self) noexcept
{
	_ARG_TPL_VITEMTYPE_ retv=_ARG_TPL_VITEMTYPE_();
	
	return retv;
}


xcc_tplTestVector_vectorIntf__stlVector_hdr()
xcc_tplTestVector_vectorIntf__stlVector_m(int) insert_idx(TPL_VTYPE* refp_self, const int idx, const _ARG_TPL_VITEMTYPE_* refp_target) noexcept
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


xcc_tplTestVector_vectorIntf__stlVector_hdr()
xcc_tplTestVector_vectorIntf__stlVector_m(int) push(TPL_VTYPE* refp_self, const _ARG_TPL_VITEMTYPE_* refp_target) noexcept
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


xcc_tplTestVector_vectorIntf__stlVector_hdr()
xcc_tplTestVector_vectorIntf__stlVector_m(int) pop(TPL_VTYPE* refp_self) noexcept
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


xcc_tplTestVector_vectorIntf__stlVector_hdr()
xcc_tplTestVector_vectorIntf__stlVector_m(int) remove_idx(TPL_VTYPE* refp_self, const int idx) noexcept
{
	return 1;
}

xcc_tplTestVector_vectorIntf__stlVector_hdr()
xcc_tplTestVector_vectorIntf__stlVector_m(int) get_length(TPL_VTYPE* refp_self) noexcept
{
	return refp_self->size();
}

xcc_tplTestVector_vectorIntf__stlVector_hdr()
xcc_tplTestVector_vectorIntf__stlVector_m(int) get_capacity(TPL_VTYPE* refp_self) noexcept
{
	return refp_self->capacity();
}



xcc_tplTestVector_vectorIntf__stlVector_hdr()
xcc_tplTestVector_vectorIntf__stlVector_m(size_t) DIAG_get_expected_capacity_for_length(const size_t arg_length) noexcept
{

	return 0;
}


xcc_tplTestVector_vectorIntf__stlVector_hdr()
xcc_tplTestVector_vectorIntf__stlVector_m(int) set(TPL_VTYPE* refp_self, const int idx, const _ARG_TPL_VITEMTYPE_* refp_target) noexcept
{
	return 1;
}


/* --- --- */


xcc_tplTestVector_vectorIntf__stlVector_hdr()
xcc_tplTestVector_vectorIntf__stlVector_m(TPL_VTYPE*) alloc_init(TPL_VTYPE* refp_self) noexcept
{
	return NULL;
	
}


xcc_tplTestVector_vectorIntf__stlVector_hdr()
xcc_tplTestVector_vectorIntf__stlVector_m(int) dealloc(TPL_VTYPE* refp_self) noexcept
{
	return 1;
	
}

xcc_tplTestVector_vectorIntf__stlVector_hdr()
xcc_tplTestVector_vectorIntf__stlVector_m(int) assignFrom(TPL_VTYPE* refp_self, const TPL_VTYPE* refp_self_src, int* overflow) noexcept
{
	//return refp_self->assign(*refp_self_src);
	return 1;
}
