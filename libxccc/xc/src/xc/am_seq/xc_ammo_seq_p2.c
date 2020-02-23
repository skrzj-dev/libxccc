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

#include "xc/common/xc_err.h"
#include "xc/common/xc_mem.h"
/* --- */
#include "xc/am_seq/xc_ammo_seq.h"
/* --- */

/* --- --- --- --- */

const xc_amAlc_seq_I_t xc_amAlc_seq_tChunkP2Grow_I={
	  &xc_ammo_seq_tChunkP2Grow_length2capacity
	, &xc_ammo_seq_tChunkP2Grow_realloc
};



int xc_ammo_seq_tChunkP2Grow_realloc(
	  const xc_ammo_seq_cfg_t* refp_cfg
	, const xc_ammo_seq_state_t* refp_initial_state
	, xc_ammo_seq_state_t* refp_result_state
	, const size_t requested_new_length
)
{
	size_t requested_new_length_for_capacity_calculation=requested_new_length;
	size_t new_capacity=0;
	int is_to_resize=0;
	xc_err_decl();
	
	/* --- param validation: */
	if(NULL == refp_cfg) {
		xc_err_term_unmg();
	}
	if(NULL == refp_initial_state) {
		xc_err_term_unmg();
	}
	if(NULL == refp_result_state) {
		xc_err_term_unmg();
	}
	/* --- param validation: done */
	
	/* --- content validation: */
	
	if( 0 == refp_cfg->cnt_items_in_chunk) {
		xc_err_term_unmg();
	}
	if( 0 == refp_cfg->item_bytesize) {
		xc_err_term_unmg();
	}
	
	if( NULL == refp_initial_state->refp_itemArray_byteptr.Refp2BtPtr) {
		xc_err_term_unmg();
	}
	/* --- */
	
	/* --- content validation: done */
	
	xc_mem_bzero_obj(xc_ammo_seq_state_t, refp_result_state);
	
	if( 0 != xc_ammo_seq_tChunkC_length2capacity(
			  requested_new_length
			, refp_initial_state->capacity
			, refp_cfg->cnt_items_in_chunk
			, &new_capacity
		) 
	) {
		xc_err_term_unmg();
	}

	if( new_capacity < refp_initial_state->capacity ) {
		is_to_resize=1;
		requested_new_length_for_capacity_calculation=requested_new_length;
	}
	else
	if( new_capacity > refp_initial_state->capacity ) {
		is_to_resize=1;
		requested_new_length_for_capacity_calculation=requested_new_length;

	}
	else
	if( new_capacity == refp_initial_state->capacity ) {
			is_to_resize=0;
	}
	
	/* --- --- --- */
	
	if( 0 != is_to_resize )
	{
		xc_p_pBytes_t tmp_result_byteptr={0};
		
		/* try to resize: */
		if(1)
		{
			xc_p_pBytes_t tmp_target_byteptr={0};
			size_t newbytesize=refp_cfg->item_bytesize*new_capacity;
			
			tmp_result_byteptr=xc_p_pBytes_from_ref2pBytes(refp_initial_state->refp_itemArray_byteptr);
			tmp_target_byteptr=xc_p_pBytes_from_ref2pBytes(refp_initial_state->refp_itemArray_byteptr);
			
			if(NULL == tmp_result_byteptr.BtPtr)
			{
				tmp_result_byteptr.BtPtr=xc_mem_allocz_obj_array(unsigned char, newbytesize);
			}
			else
			{
				tmp_result_byteptr.BtPtr=realloc(tmp_target_byteptr.BtPtr, newbytesize);
			}
			
			if( NULL == tmp_result_byteptr.BtPtr ) {
				xc_err_term_unmg();
			}

		}
		/* try to resize: done */
		
		/* after this point evertything is valid  and can be assigned to result */
		
		/* result: assign new allocated ptr: */
		refp_result_state->refp_itemArray_byteptr=refp_initial_state->refp_itemArray_byteptr;
		xc_p_refp2pBytes_assign_pBytes(&refp_result_state->refp_itemArray_byteptr, tmp_result_byteptr);
		/* result: assign new allocated ptr: done */
		/* result: just write old length */
		refp_result_state->length=requested_new_length; /* not [requested_new_length_for_capacity_calculation]! */
		/* result: bigger capacity */
		refp_result_state->capacity=new_capacity;
		
		if(1)
		{
			if(new_capacity > refp_initial_state->capacity) /* just zero entirebyte block in item array until the end in 1 call */
			{
				xc_p_pBytes_t BtPtr={0};
				xc_p_pBytes_t BtPtr2={0};
				const size_t byteoff_start=refp_result_state->length * refp_cfg->item_bytesize;
				const size_t cnt_to_end=refp_result_state->capacity - refp_result_state->length;
				
				BtPtr2=xc_p_pBytes_from_ref2pBytes(refp_result_state->refp_itemArray_byteptr);
				BtPtr.BtPtr=BtPtr2.BtPtr + byteoff_start;
				xc_mem_bzero_bytes(BtPtr.BtPtr, cnt_to_end * refp_cfg->item_bytesize);
			}
		}
	}
	else
	{
		xc_mem_cp_obj(xc_ammo_seq_state_t, refp_result_state, refp_initial_state);
		refp_result_state->length=requested_new_length;
		
	}
	
	return 0;
	
	xc_err_on_unmg();
		if(NULL!=refp_result_state) {
			xc_mem_bzero_obj(xc_ammo_seq_state_t, refp_result_state);
		}
	return 1;
}


int xc_ammo_seq_tChunkP2Grow_length2capacity(const size_t length, const size_t cur_capacity, const size_t chunk_itemcnt, size_t* result_capacity)
{
	unsigned int tmp_result=0;
	xc_err_decl();
	
	if(NULL == result_capacity) {
		xc_err_term_unmg();
	}
	if(0==chunk_itemcnt) {
		xc_err_term_unmg();
	}
	
	if( 0 == length && 0 == cur_capacity ) {
		*result_capacity=1;
	}
	else
	{
		if(length<=cur_capacity) {
			*result_capacity=cur_capacity;
		}
		else
		{
			unsigned int n=0;
			int is_ok=0;
			
			for(n=0; n<sizeof(unsigned int)*8; n++)
			{
				tmp_result=(unsigned int)(1<<n);
				
				if(tmp_result>=length) {
					*result_capacity=tmp_result;
					is_ok=1;
				}
			}
			
			if(0 == is_ok) {
				xc_err_term_unmg();
			}
		}
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}
