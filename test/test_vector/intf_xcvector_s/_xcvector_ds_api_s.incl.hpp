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
#include "xc/tcvector_s/xc_tcvector_s.h"
/* --- */
/* --- */

/* --- --- --- --- */
/* --- --- --- --- */

xcc_tplTestVector_vectorIntf__xcVectorDS__s_hdr()
xcc_tplTestVector_vectorIntf__xcVectorDS_s_m(ARG_TPL_DEREFER) derefer_retv(TPL_VTYPE* refp_self) noexcept
{
	ARG_TPL_DEREFER retv=ARG_TPL_DEREFER();
	
	retv=xc_tcVectorS_s_derefer_get_retv(refp_self);
	
	return retv;
}

xcc_tplTestVector_vectorIntf__xcVectorDS__s_hdr()
xcc_tplTestVector_vectorIntf__xcVectorDS_s_m(int) derefer_validate_integrity(TPL_VTYPE* refp_self, ARG_TPL_DEREFER* refp_tpl_deref) noexcept
{
	xc_tcVectorS_hdr_t* refp_hdr=NULL;
	xc_byteptr_t byteptr_items=NULL;
	unsigned char** byteptr_items_ref=NULL;
	xc_tcVectorS_LL_deref_t* refp_deref=refp_tpl_deref;
	/* --- */
	xcc_err_decl();
	
	try
	{
		
		refp_hdr=&refp_self->prv__hdrDS;
		byteptr_items=(xc_byteptr_t)refp_self->items_array_ptr;
		byteptr_items_ref=(unsigned char**)&refp_self->items_array_ptr;
		refp_deref=refp_tpl_deref;
		/* --- */
		
		if( refp_deref->refp_hdr != refp_hdr ) {
			xcc_err_term_unmg();
		}
		
		if(refp_deref->items_byteptr.Refp2BtPtr != byteptr_items_ref) {
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

xcc_tplTestVector_vectorIntf__xcVectorDS__s_hdr()
xcc_tplTestVector_vectorIntf__xcVectorDS_s_m(int) derefer_validate_data(ARG_TPL_DEREFER* refp_tpl_deref) noexcept
{
	xc_tcVectorS_hdr_t* refp_hdr=refp_tpl_deref->refp_hdr;
	xc_tcVectorS_LL_deref_t* refp_deref=refp_tpl_deref;
	/* --- */
	xcc_err_decl();
	
	try
	{
		xc_byteptr_t byteptr_items=NULL;
		
		if( NULL == refp_deref->self_bytes_ref.BtPtr ) {
			xcc_err_term_unmg();
		}
		if( 0 == refp_deref->self_bytes_size) {
			xcc_err_term_unmg();
		}
		if( NULL == refp_deref->items_byteptr.Refp2BtPtr ) {
			xcc_err_term_unmg();
		}
		
		byteptr_items=xc_p_pBytes_from_ref2pBytes( refp_deref->items_byteptr ).BtPtr;
		
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


xcc_tplTestVector_vectorIntf__xcVectorDS__s_hdr()
xcc_tplTestVector_vectorIntf__xcVectorDS_s_m(int) init(TPL_VTYPE* refp_self) noexcept
{
	return xc_tcVectorS_s_init(
		  refp_self
		, 8
	);
}


xcc_tplTestVector_vectorIntf__xcVectorDS__s_hdr()
xcc_tplTestVector_vectorIntf__xcVectorDS_s_m(int) init(TPL_VTYPE* refp_self, const size_t initial_capacity) noexcept
{
	
	return xc_tcVectorS_s_init(
		  refp_self
		, initial_capacity
	);
	
}


xcc_tplTestVector_vectorIntf__xcVectorDS__s_hdr()
xcc_tplTestVector_vectorIntf__xcVectorDS_s_m(int) deinit(TPL_VTYPE* refp_self) noexcept
{
	
	return xc_tcVectorS_s_deinit(
		  refp_self
	);
	
}


/* --- --- --- --- */
/* --- --- --- --- */

xcc_tplTestVector_vectorIntf__xcVectorDS__s_hdr()
xcc_tplTestVector_vectorIntf__xcVectorDS_s_m(int) get_first_cp(TPL_VTYPE* refp_self, _ARG_TPL_VITEMTYPE_* refp_target) noexcept
{
	return 0;
}

xcc_tplTestVector_vectorIntf__xcVectorDS__s_hdr()
xcc_tplTestVector_vectorIntf__xcVectorDS_s_m(_ARG_TPL_VITEMTYPE_*) get_first_refp(TPL_VTYPE* refp_self) noexcept
{
	_ARG_TPL_VITEMTYPE_* retv=NULL;
	
	return retv;
}

xcc_tplTestVector_vectorIntf__xcVectorDS__s_hdr()
xcc_tplTestVector_vectorIntf__xcVectorDS_s_m(_ARG_TPL_VITEMTYPE_) get_first_val(TPL_VTYPE* refp_self) noexcept
{
	_ARG_TPL_VITEMTYPE_ retv=_ARG_TPL_VITEMTYPE_();
	
	return retv;
}

xcc_tplTestVector_vectorIntf__xcVectorDS__s_hdr()
xcc_tplTestVector_vectorIntf__xcVectorDS_s_m(int) get_idx_cp(TPL_VTYPE* refp_self, const int idx, _ARG_TPL_VITEMTYPE_* refp_target) noexcept
{
	return xc_tcVectorS_s_item_cp(
		  refp_self
		, idx
		, refp_target
	);
}

xcc_tplTestVector_vectorIntf__xcVectorDS__s_hdr()
xcc_tplTestVector_vectorIntf__xcVectorDS_s_m(_ARG_TPL_VITEMTYPE_*) get_idx_refp(TPL_VTYPE* refp_self, const int idx) noexcept
{
	return xc_tcVectorS_s_item_refp(
		  refp_self
		, idx
	);
}

xcc_tplTestVector_vectorIntf__xcVectorDS__s_hdr()
xcc_tplTestVector_vectorIntf__xcVectorDS_s_m(_ARG_TPL_VITEMTYPE_&) get_idx_val(TPL_VTYPE* refp_self, const int idx) noexcept
{
	return xc_tcVectorS_s_item_direct(
		  refp_self
		, idx
	);
}

xcc_tplTestVector_vectorIntf__xcVectorDS__s_hdr()
xcc_tplTestVector_vectorIntf__xcVectorDS_s_m(int) get_last_cp(TPL_VTYPE* refp_self, _ARG_TPL_VITEMTYPE_* refp_target) noexcept
{
	
	return 0;
}

xcc_tplTestVector_vectorIntf__xcVectorDS__s_hdr()
xcc_tplTestVector_vectorIntf__xcVectorDS_s_m(_ARG_TPL_VITEMTYPE_*) get_last_refp(TPL_VTYPE* refp_self) noexcept
{
	_ARG_TPL_VITEMTYPE_* retv=NULL;
	
	return retv;
}

xcc_tplTestVector_vectorIntf__xcVectorDS__s_hdr()
xcc_tplTestVector_vectorIntf__xcVectorDS_s_m(_ARG_TPL_VITEMTYPE_) get_last_val(TPL_VTYPE* refp_self) noexcept
{
	_ARG_TPL_VITEMTYPE_ retv=_ARG_TPL_VITEMTYPE_();
	
	return retv;
}


xcc_tplTestVector_vectorIntf__xcVectorDS__s_hdr()
xcc_tplTestVector_vectorIntf__xcVectorDS_s_m(int) insert_idx(TPL_VTYPE* refp_self, const int idx, const _ARG_TPL_VITEMTYPE_* refp_target) noexcept
{
	return xc_tcVectorS_s_insert(
		  refp_self
		, idx
		, refp_target
	);
}


xcc_tplTestVector_vectorIntf__xcVectorDS__s_hdr()
xcc_tplTestVector_vectorIntf__xcVectorDS_s_m(int) push(TPL_VTYPE* refp_self, const _ARG_TPL_VITEMTYPE_* refp_target) noexcept
{
	
	return xc_tcVectorS_s_push(
		  refp_self
		, refp_target
	);
	
}


xcc_tplTestVector_vectorIntf__xcVectorDS__s_hdr()
xcc_tplTestVector_vectorIntf__xcVectorDS_s_m(int) pop(TPL_VTYPE* refp_self) noexcept
{
	return xc_tcVectorS_s_pop(
		  refp_self
	);
	
}


xcc_tplTestVector_vectorIntf__xcVectorDS__s_hdr()
xcc_tplTestVector_vectorIntf__xcVectorDS_s_m(int) remove_idx(TPL_VTYPE* refp_self, const int idx) noexcept
{
	return xc_tcVectorS_s_remove_idx(
		  refp_self
		, idx
	);
}

xcc_tplTestVector_vectorIntf__xcVectorDS__s_hdr()
xcc_tplTestVector_vectorIntf__xcVectorDS_s_m(int) get_length(TPL_VTYPE* refp_self) noexcept
{
	return xc_tcVectorS_s_get_length(
		  refp_self
	);
}

xcc_tplTestVector_vectorIntf__xcVectorDS__s_hdr()
xcc_tplTestVector_vectorIntf__xcVectorDS_s_m(int) get_capacity(TPL_VTYPE* refp_self) noexcept
{
	return xc_tcVectorS_s_get_capacity(
		  refp_self
	);
}



xcc_tplTestVector_vectorIntf__xcVectorDS__s_hdr()
xcc_tplTestVector_vectorIntf__xcVectorDS_s_m(size_t) DIAG_get_expected_capacity_for_length(const size_t arg_length) noexcept
{
	/* hardcoded for test static capacity */
	return 8;
}


xcc_tplTestVector_vectorIntf__xcVectorDS__s_hdr()
xcc_tplTestVector_vectorIntf__xcVectorDS_s_m(int) set(TPL_VTYPE* refp_self, const int idx, const _ARG_TPL_VITEMTYPE_* refp_target) noexcept
{
	return xc_tcVectorS_s_set(
		  refp_self
		, idx
		, refp_target
	);
}

/* --- --- --- ---- */

xcc_tplTestVector_vectorIntf__xcVectorDS__s_hdr()
xcc_tplTestVector_vectorIntf__xcVectorDS_s_m(TPL_VTYPE*) alloc_init(TPL_VTYPE* refp_self) noexcept
{
	
	return xc_tcVectorS_s_alloc_init(
		  refp_self
		, 8
	);
	
}


xcc_tplTestVector_vectorIntf__xcVectorDS__s_hdr()
xcc_tplTestVector_vectorIntf__xcVectorDS_s_m(int) dealloc(TPL_VTYPE* refp_self) noexcept
{
	
	return xc_tcVectorS_s_dealloc(
		  refp_self
	);
	
}

xcc_tplTestVector_vectorIntf__xcVectorDS__s_hdr()
xcc_tplTestVector_vectorIntf__xcVectorDS_s_m(int) assignFrom(TPL_VTYPE* refp_self, const TPL_VTYPE* refp_self_src, int* result_overflow) noexcept
{
	return xc_tcVectorS_s_assign_from(
		  refp_self
		, refp_self_src
		, result_overflow
	);
}
