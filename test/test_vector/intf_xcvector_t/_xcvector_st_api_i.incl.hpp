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

#include "xcc/common/xcc_err.hpp"
/* --- */
#include "xc/am_seq/xc_ammo_seq.h"
#include "xc/tcvector_t/xc_tcvector_t.h"
/* --- */
#include "intf_xcvector_t/_xcvector_st_api_i_hlp.hpp"
/* --- */


/* --- --- --- --- */
/* --- --- --- --- */


xcc_tplTestVector_vectorIntf__xcVectorST_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorST_i_m(ARG_TPL_DEREFER) derefer_retv(TPL_VTYPE* refp_self) noexcept
{
	ARG_TPL_DEREFER retv=ARG_TPL_DEREFER();
	
	retv=xc_tcVectorT_s_derefer_get_retv(refp_self);
	
	return retv;
}

xcc_tplTestVector_vectorIntf__xcVectorST_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorST_i_m(int) derefer_validate_integrity(TPL_VTYPE* refp_self, ARG_TPL_DEREFER* refp_tpl_deref) noexcept
{
	xc_tcVectorT_hdr_t* refp_hdr=NULL;
	xc_byteptr_t byteptr_items=NULL;
	xc_tcVectorT_LL_deref_t* refp_deref=refp_tpl_deref;
	/* --- */
	xcc_err_decl();
	
	try
	{
		
		refp_hdr=&refp_self->prv__hdrST;
		byteptr_items=(xc_byteptr_t)refp_self->items_array;
		refp_deref=refp_tpl_deref;
		/* --- */
		
		if( refp_deref->refp_hdr != refp_hdr ) {
			xcc_err_term_unmg();
		}
		
		if(refp_deref->items_byteptr.BtPtr != byteptr_items) {
			xcc_err_term_unmg();
		}

		if(refp_deref->self_bytes_ref.BtPtr != (xc_byteptr_t)refp_self) {
			xcc_err_term_unmg();
		}

		if(refp_deref->self_bytes_ref.BtPtr != (xc_byteptr_t)refp_self) {
			xcc_err_term_unmg();
		}

		if(refp_deref->self_bytes_size!= sizeof(TPL_VTYPE) ) {
			xcc_err_term_unmg();
		}

		return 0;
	}
	catch(...)
	{
		xcc_err_handle();
		return 1;
	}
}

xcc_tplTestVector_vectorIntf__xcVectorST_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorST_i_m(int) derefer_validate_data(ARG_TPL_DEREFER* refp_tpl_deref) noexcept
{
	xc_tcVectorT_hdr_t* refp_hdr=refp_tpl_deref->refp_hdr;
	xc_tcVectorT_LL_deref_t* refp_deref=refp_tpl_deref;
	/* --- */
	xcc_err_decl();
	
	try
	{
		xc_byteptr_t byteptr_items=NULL;
		
		if( NULL == refp_deref->self_bytes_ref.BtPtr) {
			xcc_err_term_unmg();
		}
		if( 0 == refp_deref->self_bytes_size) {
			xcc_err_term_unmg();
		}
		if( NULL == refp_deref->items_byteptr.BtPtr ) {
			xcc_err_term_unmg();
		}
		
		byteptr_items= refp_deref->items_byteptr.BtPtr;
		
		if( NULL == byteptr_items ) {
			xcc_err_term_unmg();
		}
		
		if( NULL == refp_deref->refp_hdr ) {
			xcc_err_term_unmg();
		}
		
		if( sizeof(_ARG_TPL_VITEMTYPE_) != refp_deref->refp_hdr->cfg.obj_bytesize  ) {
			xcc_err_term_unmg();
		}
		
		return 0;
	}
	catch(...)
	{
		
		xcc_err_handle();
		return 1;
	}
}
/* --- --- --- --- */
/* --- --- --- --- */


xcc_tplTestVector_vectorIntf__xcVectorST_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorST_i_m(int) init(TPL_VTYPE* refp_self) noexcept
{
	return seqST_dummyItem_t_I.init(
		  refp_self
	);
	
}


xcc_tplTestVector_vectorIntf__xcVectorST_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorST_i_m(int) init(TPL_VTYPE* refp_self, const size_t initial_capacity) noexcept
{
	
	return seqST_dummyItem_t_I.init(
		  refp_self
		, initial_capacity
	);
	
}


xcc_tplTestVector_vectorIntf__xcVectorST_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorST_i_m(int) deinit(TPL_VTYPE* refp_self) noexcept
{
	
	return seqST_dummyItem_t_I.deinit(
		  refp_self
	);
	
}


/* --- --- --- --- */
/* --- --- --- --- */

xcc_tplTestVector_vectorIntf__xcVectorST_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorST_i_m(int) get_first_cp(TPL_VTYPE* refp_self, _ARG_TPL_VITEMTYPE_* refp_target) noexcept
{
	return 0;
}

xcc_tplTestVector_vectorIntf__xcVectorST_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorST_i_m(_ARG_TPL_VITEMTYPE_*) get_first_refp(TPL_VTYPE* refp_self) noexcept
{
	_ARG_TPL_VITEMTYPE_* retv=NULL;
	
	return retv;
}

xcc_tplTestVector_vectorIntf__xcVectorST_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorST_i_m(_ARG_TPL_VITEMTYPE_) get_first_val(TPL_VTYPE* refp_self) noexcept
{
	_ARG_TPL_VITEMTYPE_ retv=_ARG_TPL_VITEMTYPE_();
	
	return retv;
}

xcc_tplTestVector_vectorIntf__xcVectorST_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorST_i_m(int) get_idx_cp(TPL_VTYPE* refp_self, const int idx, _ARG_TPL_VITEMTYPE_* refp_target) noexcept
{
	return seqST_dummyItem_t_I.item_cp(
		  refp_self
		, idx
		, refp_target
	);
}

xcc_tplTestVector_vectorIntf__xcVectorST_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorST_i_m(_ARG_TPL_VITEMTYPE_*) get_idx_refp(TPL_VTYPE* refp_self, const int idx) noexcept
{
	return seqST_dummyItem_t_I.item_refp(
		  refp_self
		, idx
	);
}

xcc_tplTestVector_vectorIntf__xcVectorST_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorST_i_m(_ARG_TPL_VITEMTYPE_&) get_idx_val(TPL_VTYPE* refp_self, const int idx) noexcept
{
	/* there are no C++ references in C, so {access_direct} cannot be implemented; it's emulated with derefence of ptr */
	return *seqST_dummyItem_t_I.item_refp(
		  refp_self
		, idx
	);
}

xcc_tplTestVector_vectorIntf__xcVectorST_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorST_i_m(int) get_last_cp(TPL_VTYPE* refp_self, _ARG_TPL_VITEMTYPE_* refp_target) noexcept
{
	
	return 0;
}

xcc_tplTestVector_vectorIntf__xcVectorST_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorST_i_m(_ARG_TPL_VITEMTYPE_*) get_last_refp(TPL_VTYPE* refp_self) noexcept
{
	_ARG_TPL_VITEMTYPE_* retv=NULL;
	
	return retv;
}

xcc_tplTestVector_vectorIntf__xcVectorST_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorST_i_m(_ARG_TPL_VITEMTYPE_) get_last_val(TPL_VTYPE* refp_self) noexcept
{
	_ARG_TPL_VITEMTYPE_ retv=_ARG_TPL_VITEMTYPE_();
	
	return retv;
}


xcc_tplTestVector_vectorIntf__xcVectorST_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorST_i_m(int) insert_idx(TPL_VTYPE* refp_self, const int idx, const _ARG_TPL_VITEMTYPE_* refp_target) noexcept
{
	return seqST_dummyItem_t_I.insert(
		  refp_self
		, idx
		, refp_target
	);
}


xcc_tplTestVector_vectorIntf__xcVectorST_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorST_i_m(int) push(TPL_VTYPE* refp_self, const _ARG_TPL_VITEMTYPE_* refp_target) noexcept
{
	
	return seqST_dummyItem_t_I.push(
		  refp_self
		, refp_target
	);
	
}


xcc_tplTestVector_vectorIntf__xcVectorST_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorST_i_m(int) pop(TPL_VTYPE* refp_self) noexcept
{
	return seqST_dummyItem_t_I.pop(
		  refp_self
	);
	
}


xcc_tplTestVector_vectorIntf__xcVectorST_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorST_i_m(int) remove_idx(TPL_VTYPE* refp_self, const int idx) noexcept
{
	return seqST_dummyItem_t_I.remove_idx(
		  refp_self
		, idx
	);
}

xcc_tplTestVector_vectorIntf__xcVectorST_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorST_i_m(int) get_length(TPL_VTYPE* refp_self) noexcept
{
	return seqST_dummyItem_t_I.get_length(
		  refp_self
	);
}

xcc_tplTestVector_vectorIntf__xcVectorST_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorST_i_m(int) get_capacity(TPL_VTYPE* refp_self) noexcept
{
	return seqST_dummyItem_t_I.get_capacity(
		  refp_self
	);
}



xcc_tplTestVector_vectorIntf__xcVectorST_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorST_i_m(size_t) DIAG_get_expected_capacity_for_length(const size_t arg_length) noexcept
{
	/* hardcoded for test static capacity */
	return 8;
}


xcc_tplTestVector_vectorIntf__xcVectorST_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorST_i_m(int) set(TPL_VTYPE* refp_self, const int idx, const _ARG_TPL_VITEMTYPE_* refp_target) noexcept
{
	return seqST_dummyItem_t_I.set_idx(
		  refp_self
		, idx
		, refp_target
	);
}


/* --- --- --- --- */
/* --- --- --- --- */


xcc_tplTestVector_vectorIntf__xcVectorST_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorST_i_m(TPL_VTYPE*) alloc_init(TPL_VTYPE* refp) noexcept
{
	return seqST_dummyItem_t_I.alloc_init(
		  
	);
	
}


xcc_tplTestVector_vectorIntf__xcVectorST_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorST_i_m(int) dealloc(TPL_VTYPE* refp_self) noexcept
{
	
	return seqST_dummyItem_t_I.dealloc(
		  refp_self
	);
	
}


xcc_tplTestVector_vectorIntf__xcVectorST_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorST_i_m(int) assignFrom(TPL_VTYPE* refp_self, const TPL_VTYPE* refp_self_src, int* result_overflow) noexcept
{
	return seqST_dummyItem_t_I.assign_from(
		  refp_self
		, refp_self_src
		, result_overflow
	);
}
