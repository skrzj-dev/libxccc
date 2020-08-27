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

#ifndef _XCC_TEST_TPL_VECTOR___CCCVECTOR_ST_INTERNAL_HPP_
#define _XCC_TEST_TPL_VECTOR___CCCVECTOR_ST_INTERNAL_HPP_

#include "abstracts_functional_any/vector_test_tpl_abstraction_api.hpp"
/* --- */
#include "xcc/test/xcc_test2.hpp"
#include "xcc/common/xcc_err.hpp"
/* --- */
#include "xc/am_seq/xc_am_seq.h"
#include "xc/tcvector_t/xc_tcvector_t.h"
/* --- */


template<typename TPL_VTYPE, typename _ARG_TPL_VITEMTYPE_, typename ARG_TPL_DEREFER, class _TPL_LLII_>
class testIntf_internal_xcVectorST_intf  
{
	template <typename TPL_VECTOR_TYPE>  
	static int verifyInternalState_itemsIntegrity_entry(xc_tcVectorT_LL_inspect_LLII_info_t* tmp_info, const int public_idx, xc_tcVectorT_hdr_t* refp_hdr, TPL_VECTOR_TYPE* refp_self)
	{
		xcc_test2_scope_disconnected();
		/* --- */
		
		do
		{
			xcc_test2_case("item verification: part #1");
			
			/* : */
			if(1)
			{
				xcc_test2_expect( tmp_info->anyptr_item == (void*)&refp_self->items_array[public_idx] );
				xcc_test2_expect( tmp_info->byteptr_item == (xc_byteptr_t)&refp_self->items_array[public_idx] );
			}
			/* : done */
			
			xcc_test2_case_end();
			
		} while(0);
			
		do
		{
			xcc_test2_case("item verification: part #2");
			
			/* verify that data are continuous in memory: */
			if(1)
			{
				xc_byteptr_t byteptr_items=(xc_byteptr_t)refp_self->items_array;
				void* anyptr_items=(void*)refp_self->items_array;
				
				xc_byteptr_t byteptr_cur_item=NULL;
				void* anyptr_cur_item=NULL;

				byteptr_cur_item= (xc_byteptr_t)(byteptr_items+public_idx*refp_hdr->cfg.obj_bytesize);
				anyptr_cur_item=(void*)(byteptr_items+public_idx*refp_hdr->cfg.obj_bytesize);
				
				xcc_test2_expect( tmp_info->anyptr_item == anyptr_cur_item );
				xcc_test2_expect( tmp_info->byteptr_item == byteptr_cur_item );
				
			}
			/* verify that data are continuous in memory: done */
			
			xcc_test2_case_end();

		} while(0);

		do
		{
			xcc_test2_case("item verification: part #3");

			/* : */
			if(1)
			{
				xcc_test2_expect_eq_t(int, public_idx, tmp_info->item_idx_public );
				xcc_test2_expect_eq_t(int, public_idx, tmp_info->item_idx_LLII); /* in seq allocator, the LLII INDEX and PUBLIC INDEX are the same */
			}
			/* : done */
			
			xcc_test2_case_end();

		} while(0);
		
		/* --- */
		xcc_test2_scope_end();
	}
	
	public: int verifyInternalState_itemsNumbers(TPL_VTYPE* refp_self, const int expected_capacity, const int expected_length) noexcept
	{
		xc_tcVectorT_hdr_t* refp_hdr=NULL;
		xcc_test2_scope_disconnected();
		
		int got_length=0;
		int got_capacity=0;
		
		refp_hdr=&refp_self->prv__hdrST;
		
		do
		{
			xcc_test2_case("item numbers verification");
			
			/* : */
			if(1)
			{
				xcc_test2_expect_eq_t(int, expected_capacity, refp_hdr->cfg.static_capacity);
				xcc_test2_expect_eq_t(int, expected_length, refp_hdr->runtime.cur_length);
			}
			/* : done */
			
			xcc_test2_case_end();
			
		} while(0);
		
		xcc_test2_scope_end();
	}	
	
	public: int verifyInternalState_itemsIntegrity(TPL_VTYPE* refp_self, const int expected_capacity, const int expected_length) noexcept
	{
		xc_tcVectorT_LL_deref_t deref={0};
		xc_tcVectorT_hdr_t* refp_hdr=NULL;
		int public_idx=0;
		xcc_test2_scope_disconnected();
		
		refp_hdr=&refp_self->prv__hdrST;
		
		deref=xc_tcVectorT_u_derefer_get_retv(refp_self);
		
		do
		{
			xcc_test2_case("checking internal state: valid items range <0; length) ");
			
			for(public_idx=0; public_idx<refp_hdr->runtime.cur_length; public_idx++)
			{
				xc_tcVectorT_LL_inspect_LLII_info_t tmp_info={0};
				/* --- */
				
				// log idx
				
				xcc_test2_expect( 0 == xc_tcVectorT_LL_inspect_LLII_info_cp(deref, public_idx, &tmp_info) );
				
				if(1) {
					xcc_test2_expect_neq_t(int, 0, tmp_info.valid);
				}
				
				xcc_test2_expect( 0 == verifyInternalState_itemsIntegrity_entry<TPL_VTYPE>(
						  &tmp_info
						, public_idx
						, refp_hdr
						, refp_self
					) 
				);
			}
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			xcc_test2_case("checking internal state: invalid items range <length; capacity) ");
			
			// log unused range in capacity
			
			for(public_idx=refp_hdr->runtime.cur_length; public_idx<refp_hdr->cfg.static_capacity; public_idx++)
			{
				xc_tcVectorT_LL_inspect_LLII_info_t tmp_info={0};
				
				/* perform get: */
				xcc_test2_expect( 0 == xc_tcVectorT_LL_inspect_LLII_info_cp(deref, public_idx, &tmp_info) );
				/* perform get: done */
				
				/* ensuure valid / invalid item: */
				if(1)
				{
					xcc_test2_expect_eq_t(int, 0, tmp_info.valid);
				}
				/* ensuure valid / invalid item: */
				
				xcc_test2_expect( 0 == verifyInternalState_itemsIntegrity_entry<TPL_VTYPE>(
					  &tmp_info
					, public_idx
					, refp_hdr
					, refp_self) 
				);
				
			}
			
			xcc_test2_case_end();
			
		} while(0);
		
		xcc_test2_scope_end();
	}	
	
	public: int verifyInternalState_itemsValues(TPL_VTYPE* refp_self, const int expected_capacity, const int expected_length, std::vector<_ARG_TPL_VITEMTYPE_>& ref_expected_item_order) noexcept
	{
		std::vector<_ARG_TPL_VITEMTYPE_>& expected_items=ref_expected_item_order;
		size_t n=0;
		xcc_test2_scope_disconnected();
		
		do
		{
			xcc_test2_case("ITEMVALUES-length  match");
			
			xcc_test2_expect_eq_t(size_t, expected_length, expected_items.size() );
			
			xcc_test2_case_end();

		} while(0);
		
		do
		{
			xcc_test2_case("ITEMVALUES-values");

			for(n=0;n<expected_items.size(); n++) 
			{
				std::stringstream tmpss;
				std::string tmpstr;
				char tmpb[256]={0};
				const _ARG_TPL_VITEMTYPE_* refp_cur_item=NULL;
				const _ARG_TPL_VITEMTYPE_* refp_tested_item=NULL;
				
				tmpss<<n;
				tmpstr=tmpss.str();

				refp_cur_item=&expected_items[n];
				refp_tested_item=&refp_self->items_array[n];
				
				snprintf(tmpb, sizeof(tmpb), "    comparing item at idx [%s]:", tmpstr.c_str() );
				xcc_test2_case_step_annotate( tmpb );
				
				xcc_test2_expect( 0 != _TPL_LLII_::item_eq(refp_cur_item, refp_tested_item) );
				
				snprintf(tmpb, sizeof(tmpb), "    comparing item at idx [%s]: OK", tmpstr.c_str() );
				xcc_test2_case_step_annotate( tmpb );
				
			}
			
			for(n=refp_self->prv__hdrST.runtime.cur_length; n<refp_self->prv__hdrST.cfg.static_capacity; n++)
			{
				const _ARG_TPL_VITEMTYPE_ tmp_empty_item={0};
				const _ARG_TPL_VITEMTYPE_* refp_tested_item=&tmp_empty_item;
				const _ARG_TPL_VITEMTYPE_* refp_cur_item=NULL;
				char tmpb[256]={0};
				std::stringstream tmpss;
				std::string tmpstr;
				
				refp_cur_item=&refp_self->items_array[n];
				
				tmpss<<n;
				tmpstr=tmpss.str();
				snprintf(tmpb, sizeof(tmpb), "    expecting empty zero item at idx [%s]:", tmpstr.c_str() );
				xcc_test2_case_step_annotate( tmpb );
				

				xcc_test2_expect( 0 == xc_mem_u_cmp_obj(_ARG_TPL_VITEMTYPE_, refp_cur_item, refp_tested_item) );
				
				snprintf(tmpb, sizeof(tmpb), "    expecting empty zero item at idx [%s]: OK", tmpstr.c_str() );
			}
			
			xcc_test2_case_end();

		} while(0);

		xcc_test2_scope_end();
	}
	public: int verifyInternalState_2vectors_same(TPL_VTYPE* refp_self, const TPL_VTYPE* refp_2nd) noexcept
	{
		size_t n=0;
		xcc_test2_scope_disconnected();
		
		do
		{
			xcc_test2_case("2-VECTORS-SAME: LENGTH");
			int length1=0;
			int length2=0;
			
			length1=refp_self->prv__hdrD.runtime.cur_length;
			length2=refp_2nd->prv__hdrD.runtime.cur_length;
			
			xcc_test2_expect_eq_t(int, length1, length2);
			
			xcc_test2_case_end();

		} while(0);
		
		/* WARNING!
		 *  CAPACITY IS NOT CHECKED - CAPACITY MAY BE DIFFERENT BETWEEN 2 VECTOR OBJECTS DUE TO DIFFERENT ALLOCATORS
		 *  THEREFORE CAPACITY IS CONSIDEREED TO BE PART OF INTERNAL IMPLEMEENTATION JUST AS EG ARRAY MEMORY ADDRESSES- IT IS NOT CHECKED
		 */
		
		do
		{
			xcc_test2_case("2-VECTORS-SAME: VALID ITEMS");

			for(n=0; n<refp_self->prv__hdrD.runtime.cur_length; n++) 
			{
				std::stringstream tmpss;
				std::string tmpstr;
				char tmpb[256]={0};
				const _ARG_TPL_VITEMTYPE_* refp_cur_item=NULL;
				const _ARG_TPL_VITEMTYPE_* refp_tested_item=NULL;
				
				tmpss<<n;
				tmpstr=tmpss.str();

				refp_cur_item=&refp_2nd->items_array_ptr[n];
				refp_tested_item=&refp_self->items_array_ptr[n];
				
				snprintf(tmpb, sizeof(tmpb), "    comparing valid item at idx [%s]:", tmpstr.c_str() );
				xcc_test2_case_step_annotate( tmpb );
				
				xcc_test2_expect( 0 != _TPL_LLII_::item_eq(refp_cur_item, refp_tested_item) );
				
				snprintf(tmpb, sizeof(tmpb), "    comparing valid item at idx [%s]: OK", tmpstr.c_str() );
				xcc_test2_case_step_annotate( tmpb );
				
			}
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			xcc_test2_case("2-VECTORS-SAME: INVALID ITEMS");
			
			for(n=refp_self->prv__hdrD.runtime.cur_length; n<refp_self->prv__hdrD.cfg.static_capacity; n++)
			{
				const _ARG_TPL_VITEMTYPE_ tmp_empty_item={0};
				const _ARG_TPL_VITEMTYPE_* refp_tested_item=&tmp_empty_item;
				const _ARG_TPL_VITEMTYPE_* refp_cur_item=NULL;
				char tmpb[256]={0};
				std::stringstream tmpss;
				std::string tmpstr;
				
				refp_cur_item=&refp_2nd->items_array_ptr[n];
				refp_tested_item=&refp_self->items_array_ptr[n];
				
				tmpss<<n;
				tmpstr=tmpss.str();
				snprintf(tmpb, sizeof(tmpb), "    expecting empty zero item at idx [%s]:", tmpstr.c_str() );
				xcc_test2_case_step_annotate( tmpb );
				

				xcc_test2_expect( 0 == xc_mem_u_cmp_obj(_ARG_TPL_VITEMTYPE_, refp_cur_item, refp_tested_item) );
				
				snprintf(tmpb, sizeof(tmpb), "    expecting empty zero item at idx [%s]: OK", tmpstr.c_str() );
			}
			
			xcc_test2_case_end();

		} while(0);

		xcc_test2_scope_end();
	}
	
	public: int hack_forceSmallerCapacity(TPL_VTYPE* refp_self,  const size_t expected_static_capacity) noexcept
	{
		xcc_err_decl();
		
		try
		{
			xc_tcVectorT_hdr_t* refp_hdr=NULL;
			
			if(NULL == refp_self) {
				xcc_err_term_unmg();
			}
			
			refp_hdr=&refp_self->prv__hdrST;
			
			if( expected_static_capacity > refp_hdr->cfg.static_capacity ) {
				xcc_err_term_unmg();
			}
			
			refp_hdr->cfg.static_capacity=expected_static_capacity;
			
		}
		catch(...)
		{
			xcc_err_handle();
			return 1;
		}
		return 0;
	}
	
};

#endif
