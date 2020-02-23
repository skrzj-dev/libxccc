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

#ifndef _XCC_TEST_TPL_VECTOR_API_CCCVECTORDS_I_HPP_
#define _XCC_TEST_TPL_VECTOR_API_CCCVECTORDS_I_HPP_

#include "abstracts_functional_any/vector_test_tpl_abstraction_api.hpp"
/* --- */
#include "xcc/common/xcc_err.hpp"
/* --- */
#include "xc/am_seq/xc_ammo_seq.h"
#include "xc/tcvector_s/xc_tcvector_s.h"
/* --- */
#include "_xcvector_ds_api_i_hlp.hpp"
/* --- */

namespace testXcVectorS
{

template<typename TPL_VTYPE, typename _ARG_TPL_VITEMTYPE_, typename ARG_TPL_DEREFER>
class intf_api_i: public tplTestVector_vectorIntf<TPL_VTYPE, _ARG_TPL_VITEMTYPE_, ARG_TPL_DEREFER>
{
	public: int init(TPL_VTYPE* refp_self) noexcept
	{
		return seqDS_dummyItem_t_I.init(
			  refp_self
			, 8
		);
	}
	public: int init(TPL_VTYPE* refp_self, const size_t initial_capacity) noexcept
	{
		return seqDS_dummyItem_t_I.init(
			  refp_self
			, initial_capacity
		);
	}
	public: int deinit(TPL_VTYPE* refp_self) noexcept
	{
		return seqDS_dummyItem_t_I.deinit(
			  refp_self
		);
	}
	
	public: ARG_TPL_DEREFER derefer_retv(TPL_VTYPE* refp_self) noexcept
	{
		ARG_TPL_DEREFER retv=ARG_TPL_DEREFER();
		
		retv=xc_tcVectorS_s_derefer_get_retv(refp_self);
		
		return retv;
	}
	
	public: int derefer_validate_integrity(TPL_VTYPE* refp_self, ARG_TPL_DEREFER* refp_tpl_deref) noexcept
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
	
	public: int derefer_validate_data(ARG_TPL_DEREFER* refp_tpl_deref) noexcept
	{
		xc_tcVectorS_hdr_t* refp_hdr=refp_tpl_deref->refp_hdr;
		xc_tcVectorS_LL_deref_t* refp_deref=refp_tpl_deref;
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
			
			return 0;
		}
		catch(...)
		{
			
			xcc_err_handle();
			return 1;
		}
	}	
	
	public: int push(TPL_VTYPE* refp_self, const _ARG_TPL_VITEMTYPE_* refp_target) noexcept
	{
		return seqDS_dummyItem_t_I.push(
			  refp_self
			, refp_target
		);

	}
	public: int pop(TPL_VTYPE* refp_self) noexcept
	{
		return seqDS_dummyItem_t_I.pop(
			  refp_self
		);

	}
	
	public: int remove_idx(TPL_VTYPE* refp_self, const int idx) noexcept
	{
		return seqDS_dummyItem_t_I.remove_idx(
			  refp_self
			, idx
		);

	}
	
	public: int insert_idx(TPL_VTYPE* refp_self, const int idx, const _ARG_TPL_VITEMTYPE_* refp_target) noexcept
	{
		return seqDS_dummyItem_t_I.insert(
			  refp_self
			, idx
			, refp_target
		);

	}
	
	public: int set(TPL_VTYPE* refp_self, const int idx, const _ARG_TPL_VITEMTYPE_* refp_target) noexcept
	{
		return seqDS_dummyItem_t_I.set_idx(
			  refp_self
			, idx
			, refp_target
		);

	}
	
	public: int get_idx_cp(TPL_VTYPE* refp_self, const int idx, _ARG_TPL_VITEMTYPE_*  refp_target) noexcept
	{
		return seqDS_dummyItem_t_I.item_cp(
			  refp_self
			, idx
			, refp_target
		);

	}
	public: _ARG_TPL_VITEMTYPE_* get_idx_refp(TPL_VTYPE* refp_self, const int idx) noexcept
	{
		return seqDS_dummyItem_t_I.item_refp(
			  refp_self
			, idx
		);

	}
	public: _ARG_TPL_VITEMTYPE_& get_idx_val(TPL_VTYPE* refp_self, const int idx) noexcept
	{
		/* there are no C++ references in C, so {access_direct} cannot be implemented; it's emulated with derefence of ptr */
		return *seqDS_dummyItem_t_I.item_refp(
			  refp_self
			, idx
		);

	}

	public: size_t DIAG_get_expected_capacity_for_length(const size_t arg_length, const size_t arg_cur_capacity) noexcept
	{
		/* hardcoded for test static capacity */
		return 8;
	}
	
	public: int get_length(TPL_VTYPE* refp_self) noexcept
	{
		return seqDS_dummyItem_t_I.get_length(
			  refp_self
		);

	}
	public: int get_capacity(TPL_VTYPE* refp_self) noexcept
	{
		return seqDS_dummyItem_t_I.get_capacity(
			  refp_self
		);

	}
	
	public: TPL_VTYPE* alloc_init(TPL_VTYPE* refp) noexcept
	{
		return seqDS_dummyItem_t_I.alloc_init(
			  8
		);

	}
	public: int dealloc(TPL_VTYPE* refp_self) noexcept
	{
		return seqDS_dummyItem_t_I.dealloc(
			  refp_self
		);

	}
	
	public: int assignFrom(TPL_VTYPE* refp_self, const TPL_VTYPE* refp_self_src, int* result_overflow) noexcept
	{
		return seqDS_dummyItem_t_I.assign_from(
			  refp_self
			, refp_self_src
			, result_overflow
		);
	}
	
};

}

#endif
