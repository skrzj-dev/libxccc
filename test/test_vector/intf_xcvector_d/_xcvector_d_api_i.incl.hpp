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
#include "xcc/common/xcc_err.hpp"
/* --- */
#include "xc/am_seq/xc_ammo_seq.h"
#include "xc/tcvector_d/xc_tcvector_d.h"
/* --- */
/* --- */
#include "abstracts_functional_any/vector_test_tpl_abstraction_item.hpp"

#include "intf_xcvector_d/_xcvector_d_api_i_hlp.hpp"

/* --- --- --- --- */
/* --- --- --- --- */


xcc_tplTestVector_vectorIntf__xcVectorD_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorD_i_m(ARG_TPL_DEREFER) derefer_retv(TPL_VTYPE* refp_self) noexcept
{
	ARG_TPL_DEREFER retv=ARG_TPL_DEREFER();
	
	retv=xc_tcVectorD_s_derefer_get_retv(refp_self);
	
	return retv;
}

xcc_tplTestVector_vectorIntf__xcVectorD_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorD_i_m(int) derefer_validate_integrity(TPL_VTYPE* refp_self, ARG_TPL_DEREFER* refp_tpl_deref) noexcept
{
	xc_tcVectorD_hdr_t* refp_hdr=NULL;
	xc_byteptr_t byteptr_items=NULL;
	xc_refp2byteptr_t byteptr_items_ref=NULL;
	xc_tcVectorD_LL_deref_t* refp_deref=refp_tpl_deref;
	/* --- */
	xcc_err_decl();
	
	try
	{
		
		refp_hdr=&refp_self->prv__hdrD;
		byteptr_items=(xc_byteptr_t)refp_self->items_array_ptr;
		byteptr_items_ref=(xc_refp2byteptr_t)&refp_self->items_array_ptr;
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

xcc_tplTestVector_vectorIntf__xcVectorD_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorD_i_m(int) derefer_validate_data(ARG_TPL_DEREFER* refp_tpl_deref) noexcept
{
	xc_tcVectorD_hdr_t* refp_hdr=refp_tpl_deref->refp_hdr;
	xc_tcVectorD_LL_deref_t* refp_deref=refp_tpl_deref;
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
		if( NULL == refp_deref->items_byteptr.Refp2BtPtr) {
			xcc_err_term_unmg();
		}
		
		byteptr_items= xc_p_pBytes_from_ref2pBytes(refp_deref->items_byteptr).BtPtr;
		
		if( NULL == byteptr_items ) {
			xcc_err_term_unmg();
		}
		
		if( NULL == refp_deref->refp_hdr ) {
			xcc_err_term_unmg();
		}
		
		if( sizeof(_ARG_TPL_VITEMTYPE_) != refp_deref->refp_hdr->cfg.obj_bytesize  ) {
			xcc_err_term_unmg();
		}
		if( 0 == refp_deref->refp_hdr->cfg.growable_chunk_objcnt) {
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


xcc_tplTestVector_vectorIntf__xcVectorD_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorD_i_m(int) init(TPL_VTYPE* refp_self) noexcept
{
	return seq_dummyItem_t_I.init(
		  refp_self
	);
	
}


xcc_tplTestVector_vectorIntf__xcVectorD_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorD_i_m(int) deinit(TPL_VTYPE* refp_self) noexcept
{
	
	return seq_dummyItem_t_I.deinit(
		  refp_self
	);
	
}


/* --- --- --- --- */
/* --- --- --- --- */

xcc_tplTestVector_vectorIntf__xcVectorD_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorD_i_m(int) get_first_cp(TPL_VTYPE* refp_self, _ARG_TPL_VITEMTYPE_* refp_target) noexcept
{
	return 0;
}

xcc_tplTestVector_vectorIntf__xcVectorD_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorD_i_m(_ARG_TPL_VITEMTYPE_*) get_first_refp(TPL_VTYPE* refp_self) noexcept
{
	_ARG_TPL_VITEMTYPE_* retv=NULL;
	
	return retv;
}

xcc_tplTestVector_vectorIntf__xcVectorD_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorD_i_m(_ARG_TPL_VITEMTYPE_) get_first_val(TPL_VTYPE* refp_self) noexcept
{
	_ARG_TPL_VITEMTYPE_ retv=_ARG_TPL_VITEMTYPE_();
	
	return retv;
}

xcc_tplTestVector_vectorIntf__xcVectorD_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorD_i_m(int) get_idx_cp(TPL_VTYPE* refp_self, const int idx, _ARG_TPL_VITEMTYPE_* refp_target) noexcept
{
	return seq_dummyItem_t_I.item_cp(
		  refp_self
		, idx
		, refp_target
	);
}

xcc_tplTestVector_vectorIntf__xcVectorD_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorD_i_m(_ARG_TPL_VITEMTYPE_*) get_idx_refp(TPL_VTYPE* refp_self, const int idx) noexcept
{
	return seq_dummyItem_t_I.item_refp(
		  refp_self
		, idx
	);
}

xcc_tplTestVector_vectorIntf__xcVectorD_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorD_i_m(_ARG_TPL_VITEMTYPE_&) get_idx_val(TPL_VTYPE* refp_self, const int idx) noexcept
{
	/* there are no C++ references in C, so {access_direct} cannot be implemented; it's emulated with derefence of ptr */
	return *seq_dummyItem_t_I.item_refp(
		  refp_self
		, idx
	);
}

xcc_tplTestVector_vectorIntf__xcVectorD_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorD_i_m(int) get_last_cp(TPL_VTYPE* refp_self, _ARG_TPL_VITEMTYPE_* refp_target) noexcept
{
	
	return 0;
}

xcc_tplTestVector_vectorIntf__xcVectorD_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorD_i_m(_ARG_TPL_VITEMTYPE_*) get_last_refp(TPL_VTYPE* refp_self) noexcept
{
	_ARG_TPL_VITEMTYPE_* retv=NULL;
	
	return retv;
}

xcc_tplTestVector_vectorIntf__xcVectorD_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorD_i_m(_ARG_TPL_VITEMTYPE_) get_last_val(TPL_VTYPE* refp_self) noexcept
{
	_ARG_TPL_VITEMTYPE_ retv=_ARG_TPL_VITEMTYPE_();
	
	return retv;
}


xcc_tplTestVector_vectorIntf__xcVectorD_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorD_i_m(int) insert_idx(TPL_VTYPE* refp_self, const int idx, const _ARG_TPL_VITEMTYPE_* refp_target) noexcept
{
	return seq_dummyItem_t_I.insert(
		  refp_self
		, idx
		, refp_target
	);
}


xcc_tplTestVector_vectorIntf__xcVectorD_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorD_i_m(int) push(TPL_VTYPE* refp_self, const _ARG_TPL_VITEMTYPE_* refp_target) noexcept
{
	
	return seq_dummyItem_t_I.push(
		  refp_self
		, refp_target
	);
	
}


xcc_tplTestVector_vectorIntf__xcVectorD_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorD_i_m(int) pop(TPL_VTYPE* refp_self) noexcept
{
	return seq_dummyItem_t_I.pop(
		  refp_self
	);
	
}


xcc_tplTestVector_vectorIntf__xcVectorD_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorD_i_m(int) remove_idx(TPL_VTYPE* refp_self, const int idx) noexcept
{
	return seq_dummyItem_t_I.remove_idx(
		  refp_self
		, idx
	);
}

xcc_tplTestVector_vectorIntf__xcVectorD_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorD_i_m(int) get_length(TPL_VTYPE* refp_self) noexcept
{
	return seq_dummyItem_t_I.get_length(
		  refp_self
	);
}

xcc_tplTestVector_vectorIntf__xcVectorD_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorD_i_m(int) get_capacity(TPL_VTYPE* refp_self) noexcept
{
	return seq_dummyItem_t_I.get_capacity(
		  refp_self
	);
}



xcc_tplTestVector_vectorIntf__xcVectorD_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorD_i_m(size_t) DIAG_get_expected_capacity_for_length(const size_t arg_length) noexcept
{
	switch(arg_length)
	{
		case  0:
		case  1:
		case  2:
		case  3:
		case  4:
		case  5:
		case  6:
		case  7:
		case  8:
			return 8;
		break;

		case  9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
			return 16;
		break;
		
		case 17:
		case 18:
		case 19:
		case 20:
		case 21:
		case 22:
		case 23:
		case 24:
			return 24;
		break;
		
		
		case 25:
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
		case 31:
		case 32:
			return 32;
		break;
		
		default:
		break;
	};
	
	if(1)
	{
		size_t capacity=0;
		if( 0!=xc_ammo_seq_tChunkC_length2capacity( arg_length, 8, &capacity) ) {
			return 0;
		}
		return capacity;
	}
	
	return 0;
}


xcc_tplTestVector_vectorIntf__xcVectorD_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorD_i_m(int) set(TPL_VTYPE* refp_self, const int idx, const _ARG_TPL_VITEMTYPE_* refp_target) noexcept
{
	return seq_dummyItem_t_I.set_idx(
		  refp_self
		, idx
		, refp_target
	);
}


/* --- --- --- --- */
/* --- --- --- --- */


xcc_tplTestVector_vectorIntf__xcVectorD_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorD_i_m(TPL_VTYPE*) alloc_init(TPL_VTYPE* refp) noexcept
{
	return seq_dummyItem_t_I.alloc_init(
		  
	);
	
}


xcc_tplTestVector_vectorIntf__xcVectorD_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorD_i_m(int) dealloc(TPL_VTYPE* refp_self) noexcept
{
	
	return seq_dummyItem_t_I.dealloc(
		  refp_self
	);
	
}


xcc_tplTestVector_vectorIntf__xcVectorD_i_hdr()
xcc_tplTestVector_vectorIntf__xcVectorD_i_m(int) assignFrom(TPL_VTYPE* refp_self, const TPL_VTYPE* refp_self_src, int* result_overflow) noexcept
{
	return seq_dummyItem_t_I.assign_from(
		  refp_self
		, refp_self_src
		, result_overflow
	);
}
