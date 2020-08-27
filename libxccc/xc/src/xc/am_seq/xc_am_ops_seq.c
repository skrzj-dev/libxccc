/*
 * Copyright block:
 *
 * Source file of libxccc project
 *
 * Copyright (c) 2020 Jakub Skrzyniarz, skrzj-dev@protonmail.com
 *
 * Licensed under: MIT license; See the file "LICENSE" of libxccc project for more information.
 *
 * Copyright block: end
 */

#include "xc/common/xc_err.h"
#include "xc/common/xc_mem.h"
/* --- */
#include "xc/common/xc_tc_common.h"
#include "xc/am_seq/xc_am_seq.h"
#include "xc/common/xc_si.h"
/* --- */

/* --- --- --- --- */


const xc_amOp_seq_I_t xc_amOp_seq_I={
	
	  xc_amOp_seq_insert_at_idx
	, xc_amOp_seq_remove_at_idx
	, xc_amOp_seq_push
	, xc_amOp_seq_pop
	, xc_amOp_seq_item_at_idx
	, xc_amOp_seq_assignFrom
	, xc_amOp_seq_clear
	
};

int xc_amOp_seq_push(
	  xc_am_seq_state_t* self_state
	, const size_t item_bytesize
	, const xc_byteptr_t refp_item
)
{
	xc_byteptr_t target=NULL;
	xc_p_pBytes_t pb={0};
	size_t new_length=0;
	xc_err_decl();
	
	/* --- */
	if(NULL==self_state) {
		xc_err_term_unmg();
	}
	if( 0 == item_bytesize)  {
		xc_err_term_unmg();
	}
	if( NULL == refp_item)  {
		xc_err_term_unmg();
	}
	
	/* --- */
	
	xc_si_UNCHECKED(new_length=self_state->length+1);

	if(new_length>self_state->capacity) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if(1)
	{
		size_t new_required_length=0;
		size_t idx_last_old=0;

		new_required_length=xc_si_UNCHECKED(self_state->length+1);

		if(new_required_length>self_state->capacity) {
			xc_err_term_unmg();
		}

		/* --- */
		
		idx_last_old=self_state->length;
		
		/* allocation : separeted scope, this may change between version */
		if(1)
		{
			/* nothing to do - just increase length */
			self_state->length=new_required_length;
		}
		
		/* shallow copy to last index before reallocation */
		if(1)
		{
			xc_p_pBytes_t pb=xc_p_pBytes_from_ref2pBytes(self_state->refp_itemArray_byteptr);
			xc_byteptr_t target=pb.BtPtr+idx_last_old*item_bytesize;
			
			memcpy( target, refp_item, item_bytesize);
		}
		
	}	
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}



int xc_amOp_seq_pop(
	  xc_am_seq_state_t* self_state
	, const size_t item_bytesize
)
{
	xc_byteptr_t target=NULL;
	xc_p_pBytes_t pb={0};
	size_t new_length=0;
	xc_err_decl();
	/* --- */
	
	if(1)
	{
		if(NULL==self_state) {
			xc_err_term_unmg();
		}
		if( 0 == item_bytesize)  {
			xc_err_term_unmg();
		}
	}
	/* --- */
	
	if(1)
	{
		if( 0 == self_state->length ) {
			xc_err_term_unmg();
		}
		if( 0 == self_state->capacity ) { /* redundant */
			xc_err_term_unmg();
		}
	}
	/* --- */
	
	xc_si_UNCHECKED(new_length=self_state->length-1);

	/* --- */
	
	if(1)
	{
		size_t last_array_idx=0;
		xc_byteptr_t lastItem_byteptr=NULL;
		size_t new_required_length=self_state->length-1;
		
		/* get last array index: */
		last_array_idx=self_state->length-1;
		/* get last array index: done */
		
		if(1)
		{
			xc_p_pBytes_t pb=xc_p_pBytes_from_ref2pBytes(self_state->refp_itemArray_byteptr);
			xc_byteptr_t target=pb.BtPtr+last_array_idx*item_bytesize;

			xc_mem_bzero_bytes(target, item_bytesize);
		}
		
		self_state->length=new_required_length;
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}



int xc_amOp_seq_insert_at_idx(
	  xc_am_seq_state_t* self_state
	, const size_t item_bytesize
	, const size_t idx_public
	, const xc_byteptr_t refp_item
)
{
	xc_byteptr_t target=NULL;
	xc_p_pBytes_t pb={0};
	const size_t idx_uint=idx_public;
	size_t new_length=0;
	xc_err_decl();
	
	/* --- */
	if(NULL==self_state) {
		xc_err_term_unmg();
	}
	if( 0 == item_bytesize)  {
		xc_err_term_unmg();
	}
	if( NULL == refp_item)  {
		xc_err_term_unmg();
	}
	
#	if 0
	if( idx_public<0) {
		xc_err_term_unmg();
	}
#	endif
	
	if(idx_public>=self_state->capacity) {
		xc_err_term_unmg();
	}
	/* --- */
	
	xc_si_UNCHECKED(new_length=self_state->length+1);

	if(idx_public>self_state->length) {
		xc_err_term_unmg();
	}
	if(new_length>self_state->capacity) {
		xc_err_term_unmg();
	}
	/* --- */
	
	pb=xc_p_pBytes_from_ref2pBytes(self_state->refp_itemArray_byteptr);
	target=pb.BtPtr+idx_uint*item_bytesize;
	
	/* --- */
	
	if(idx_public==self_state->length)
	{
		/* append */
		/* nothing to be done */
	}
	else
	{
		/* insert at, with shuffling to right <target index; length) */
		
		xc_am_seq_cfg_t alloctr_cfg={0};
		xc_am_seq_state_t alloctr_state_init=*self_state;
		xc_am_seq_state_t alloctr_state_init_updated={0};
		
		alloctr_cfg=xc_am_seq_cfg_retv(
			  item_bytesize
			, 1
		);
		
		alloctr_state_init_updated=alloctr_state_init;
		
		/* shift: */
		if(1)
		{
			const size_t shift_cnt=1;
			
			if( 0 != xc_am_seq_tStatic_shiftRight(&alloctr_cfg, &alloctr_state_init_updated, idx_uint, shift_cnt) ) {
				xc_err_term_unmg();
			}
		}
		
		new_length=alloctr_state_init_updated.length;

		/* shift: done */
	}
	
	/* final operation- copy to target idx: */
	if(1) {
		memcpy((void*)target, (void*)refp_item, item_bytesize);
	}
	/* final operation- copy to target idx: end */
	
	/* increase length: */
	if(1) {
		self_state->length=new_length;
	}
	/* increase length: done */
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}


int xc_amOp_seq_remove_at_idx(
	  xc_am_seq_state_t* self_state
	, const size_t item_bytesize
	, const size_t idx_public
)
{
	xc_err_decl();
	
	/* --- */
	if(1)
	{
		if(NULL==self_state) {
			xc_err_term_unmg();
		}
		if( 0 == item_bytesize)  {
			xc_err_term_unmg();
		}
	}
	/* --- */
	
	if(1)
	{
		/* validate state: */
		if( 0 == self_state->length ) {
			xc_err_term_unmg();
		}
		if( 0 == self_state->capacity ) { /* redundant */
			xc_err_term_unmg();
		}
		/* validate state: done */
	}
	
	if(1)
	{
		if( idx_public >= self_state->length ) {
			xc_err_term_unmg();
		}
#		if 0 /* uint */
		if( idx_public < 0 ) {
			xc_err_term_unmg();
		}
#		endif
	}
	/* --- */
	
	if(1)
	{
		xc_am_seq_cfg_t alloctr_cfg={0};
		xc_am_seq_state_t alloctr_state_init_updated={0};
		
		alloctr_cfg=xc_am_seq_cfg_retv(
			  item_bytesize
			, 1
		);
		
		alloctr_state_init_updated=*self_state;
		
		/* shift: */
		if(1)
		{
			const size_t shift_cnt=1;
			
			if( 0 != xc_am_seq_tStatic_shiftLeft(&alloctr_cfg, &alloctr_state_init_updated, idx_public, shift_cnt) ) {
				xc_err_term_unmg();
			}
		}
		/* shift: done */
		
		/*  apply changes: */
		if(1)
		{
			self_state->capacity=alloctr_state_init_updated.capacity;
			self_state->length=alloctr_state_init_updated.length;
		}
		/* apply changes: done */
	}
	
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}

int xc_amOp_seq_clear(
	  const xc_am_seq_cfg_t* refp_cfg
	, xc_am_seq_state_t* refp_state
)
{
	xc_err_decl();
	
	/* --- */
	
	if(1)
	{
		if(NULL== refp_state) {
			xc_err_term_unmg();
		}
		if(NULL == refp_cfg) {
			xc_err_term_unmg();
		}
	}
	/* --- */
	
	if(1)
	{
		xc_p_pBytes_t pb=xc_p_pBytes_from_ref2pBytes(refp_state->refp_itemArray_byteptr);
		xc_byteptr_t target=pb.BtPtr;
		size_t bytesize=0;
		
		xc_si_UNCHECKED(bytesize=refp_state->capacity*refp_cfg->item_bytesize);
		
		xc_mem_bzero_bytes( target, bytesize);
		
		refp_state->capacity=0;
		refp_state->length=0;
		
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}

int xc_amOp_seq_assignFrom(
	  const xc_am_seq_cfg_t* refp_cfg_dst
	, xc_am_seq_state_t* refp_state_dst
	, const xc_am_seq_cfg_t* refp_cfg_src
	, const xc_am_seq_state_c_t* refp_state_src
	, int* result_overflow
)
{
	size_t new_required_length=0;
	xc_err_decl();
	/* --- */
	
	if(1)
	{
		if(NULL== refp_cfg_dst) {
			xc_err_term_unmg();
		}
		if(NULL == refp_state_dst) {
			xc_err_term_unmg();
		}
		if(NULL== refp_cfg_src) {
			xc_err_term_unmg();
		}
		if(NULL == refp_state_src) {
			xc_err_term_unmg();
		}
	}
	
	if(1)
	{
		if( refp_cfg_dst->item_bytesize != refp_cfg_src->item_bytesize )  {
			xc_err_term_unmg();
		}
	}
	/* --- */
	
	if(1)
	{
		/* new length: from SRC */
		new_required_length=refp_state_src->length;
		
		/* limit by SELF capacity: */
		if( new_required_length > refp_state_dst->capacity ) {
			new_required_length = refp_state_dst->capacity;
		}
	}
	/* limit by SELF capacity: done */
	/* --- */
	
	if(1) /*  optional but useful shortcut: DO NOTHING RETURN OK if PARAM TARGEET and PARAM SOURCE are same */
	{
		if( refp_state_dst->refp_itemArray_byteptr.Refp2BtPtr[0] == refp_state_src->refp_itemArray_byteptr.Refp2BtPtr[0]  ) {
			return 0; /* nothing to be done, no error- return OK */
		}
		
	}
	
	if(1)
	{
		refp_state_dst->length=new_required_length;
	}
	
	if(1) /* addition: export information about overflow */
	{
		if( NULL != result_overflow ) {
			size_t diff=0;
			xc_tc_calc_overflow(
				  refp_state_dst->capacity
				, refp_state_src->length
				, &diff 
			);
			*result_overflow=diff; /* !!! int -> uint [validated] */
		}
	}
	
	if(1) /* just copy entire memory block instead of copying object by object */
	{
		size_t self_items_memblock_bytesize_total=0;
		xc_p_pBytes_t self_items_memblock_ptr=xc_p_pBytes_from_ref2pBytes(refp_state_dst->refp_itemArray_byteptr);
		xc_p_pBytesConst_t src_items_memblock_ptr=xc_ptr_pBytesConst_from_ref2pBytesConst(refp_state_src->refp_itemArray_byteptr);
		size_t src_bytesize2copy=0;
		
		xc_si_UNCHECKED( self_items_memblock_bytesize_total=refp_cfg_dst->item_bytesize * refp_state_dst->capacity );
		xc_si_UNCHECKED( src_bytesize2copy=refp_cfg_src->item_bytesize * new_required_length );
		
		xc_mem_bzero_bytes(self_items_memblock_ptr.BtPtr, self_items_memblock_bytesize_total);
		
		memcpy(self_items_memblock_ptr.BtPtr, src_items_memblock_ptr.BtPtr, src_bytesize2copy); /* varranteed non overlapping memory block, memcpy can be used instead of memmove */
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}

xc_byteptr_t xc_amOp_seq_item_at_idx(
	  const xc_am_seq_cfg_t* refp_cfg
	, xc_am_seq_state_t* refp_state
	, const size_t idx
)
{
	xc_byteptr_t retv=NULL;
	xc_err_decl();
	/* --- */
	
	if(1)
	{
		if(NULL== refp_cfg) {
			xc_err_term_unmg();
		}
		if(NULL == refp_state) {
			xc_err_term_unmg();
		}
	}
	
	/* --- */
	if(1)
	{
		if(idx >= refp_state->length ) {
			xc_err_term_unmg();
		}
	}
	/* --- */
	
	if( NULL == (retv=xc_amMdl_seq_I.idx2byteptr(refp_state, refp_cfg->item_bytesize, idx) ) ) {
		xc_err_term_unmg();
	}
	
	return retv;
	
	xc_err_on_unmg();
	return NULL;
}