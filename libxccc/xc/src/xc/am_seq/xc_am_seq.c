/*
 * Copyright block:
 *
 * Source file of libxccc project
 *
 * Copyright (c) 2018 Jakub Skrzyniarz, skrzj-dev@protonmail.com
 *
 * Licensed under: MIT license; See the file "LICENSE" of libxccc project for more information.
 *
 * Copyright block: end
 */

#include "xc/common/xc_err.h"
#include "xc/common/xc_mem.h"
/* --- */
#include "xc/am_seq/xc_am_seq.h"
/* --- */

/* --- --- --- --- */

int xc_am_seq_set_at_idx(
	  xc_am_seq_state_t* self_state
	, const size_t item_bytesize
	, const size_t idx_public
	, const xc_byteptr_t refp_item
)
{
	xc_byteptr_t refp_target=NULL;
	
	if(NULL == (refp_target=xc_am_seq_idx2byteptr(self_state, item_bytesize, idx_public) ) ) {
		return 1;
	}
	
	memmove(refp_target, refp_item, item_bytesize);
	
	return 0;
}

xc_am_seq_state_t xc_am_seq_state_retv(
	  xc_p_refp2pBytes_t refp_itemArray_byteptr
	, const size_t length
	, const size_t capacity
)
{
	xc_am_seq_state_t retv={0};
	
	retv.refp_itemArray_byteptr=refp_itemArray_byteptr;
	retv.length=length;
	retv.capacity=capacity;
	
	return retv;
}

xc_am_seq_state_c_t xc_am_seq_state_const_retv(
	  xc_p_refp2pBytesConst_t refp_itemArray_byteptr
	, const size_t length
	, const size_t capacity
)
{
	xc_am_seq_state_c_t retv={0};
	
	retv.refp_itemArray_byteptr=refp_itemArray_byteptr;
	retv.length=length;
	retv.capacity=capacity;
	
	return retv;
}


xc_am_seq_cfg_t xc_am_seq_cfg_retv(const size_t item_bytesize, const size_t cnt_items_in_chunk)
{
	xc_am_seq_cfg_t retv={0};
	
	retv.item_bytesize=item_bytesize;
	retv.cnt_items_in_chunk=cnt_items_in_chunk;
	
	return retv;
}


int xc_am_seq_tStatic_shiftLeft_calculate(
	  const xc_am_seq_state_t* refp_state
	, const size_t target_idx
	, const size_t req_shift_cnt
	, xc_am_seq_tStatic_shift_info_t* result
)
{
	xc_err_decl();
	
	if(NULL==refp_state) {
		xc_err_term_unmg();
	}
	if(NULL==result) {
		xc_err_term_unmg();
	}
	if(target_idx >= refp_state->length) {
		xc_err_term_unmg();
	}
	if( 0 != req_shift_cnt && 0 == refp_state->length ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	xc_mem_bzero_obj(xc_am_seq_tStatic_shift_info_t, result);
	
	if( 0 != req_shift_cnt )
	{
		
		/* original last valid index of array */
		const size_t original_last_array_idx=refp_state->length-1;
		/* count of objects within boundary <target idx; ORIGINAL LENGTH>  */
		const size_t cnt_of_items_from_target_to_length=refp_state->length-target_idx;
		/* --- */
		/* shift cnt within boundary */
		const size_t move_cnt= ( req_shift_cnt>cnt_of_items_from_target_to_length ) ? cnt_of_items_from_target_to_length : req_shift_cnt;
		const size_t length_after=refp_state->length-target_idx-move_cnt;
		
		result->cnt_shift_bound=move_cnt;
		result->cnt_complementary_to_orig_length=refp_state->length-length_after;
		result->last_idx=refp_state->length-move_cnt-1;
		result->new_length=refp_state->length-move_cnt;
		result->cnt_from_target_index_to_orig_length=( refp_state->length - target_idx - move_cnt );
	}
	else 
	{
		result->cnt_shift_bound=0;
		result->cnt_complementary_to_orig_length=0;
		result->last_idx=refp_state->length-1;
		result->new_length=refp_state->length;
		result->cnt_from_target_index_to_orig_length=( refp_state->length - target_idx - 1 );
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}


int xc_am_seq_tStatic_shiftRight_calculate(
	  const xc_am_seq_state_t* refp_state
	, const size_t target_idx
	, const size_t req_shift_cnt
	, xc_am_seq_tStatic_shift_info_t* result
)
{
	xc_err_decl();
	
	if(NULL==refp_state) {
		xc_err_term_unmg();
	}
	if(NULL==result) {
		xc_err_term_unmg();
	}
	if(target_idx >= refp_state->length) {
		xc_err_term_unmg();
	}
	if( 0 != req_shift_cnt && 0 == refp_state->length ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	xc_mem_bzero_obj(xc_am_seq_tStatic_shift_info_t, result);
	
	if( 0 != req_shift_cnt )
	{
		
		/* original last valid index of array */
		const size_t original_last_array_idx=refp_state->length-1;
		/* count of objects within boundary <target idx; ORIGINAL LENGTH>  */
		const size_t cnt_of_items_from_target_to_length=refp_state->length-target_idx;
		const size_t cnt_of_items_from_target_to_capacity=refp_state->capacity-target_idx;
		/* --- */
		/* shift cnt within boundary */
		const size_t move_cnt_in_length= ( req_shift_cnt>cnt_of_items_from_target_to_length) ? cnt_of_items_from_target_to_length: req_shift_cnt;
		const size_t move_cnt_in_capacity= ( req_shift_cnt>cnt_of_items_from_target_to_capacity ) ? cnt_of_items_from_target_to_capacity : req_shift_cnt;
		
		const size_t length_after=refp_state->length-target_idx+move_cnt_in_capacity;
		
		result->cnt_shift_bound=move_cnt_in_capacity;
		result->cnt_complementary_to_orig_length=refp_state->length-length_after;
		result->last_idx=refp_state->length+move_cnt_in_capacity-1;
		result->new_length=refp_state->length+move_cnt_in_capacity;
		result->cnt_from_target_index_to_orig_length=( refp_state->length - target_idx );
	}
	else 
	{
		result->cnt_shift_bound=0;
		result->cnt_complementary_to_orig_length=0;
		result->last_idx=refp_state->length-1;
		result->new_length=refp_state->length;
		result->cnt_from_target_index_to_orig_length=( refp_state->length - target_idx );
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}


/*
	>--- --- ---
	>[x], 2
	>[1][2][3][4][5][6][7][8]
	>--------------------------
	>[3][4][5][6][7][8][.][.]
	
	--- ---  ---
	
	>         [x], 2
	>[1][2][3][4][5][6][7][8]
	>--------------------------
	>[1][2][3][4][7][8][.][.]
	
	--- ---  ---
	
	>                  [x], 100+
	>[1][2][3][4][5][6][7][8]
	>--------------------------
	>[1][2][3][4][5][6][.][.]
	
	--- ---  ---
	
	>                     [x], 1
	>[1][2][3][4][5][6][7][8]
	>--------------------------
	>[1][2][3][4][5][6][7][.]
	
	--- ---  ---
	
	>                     [x], 2+
	>[1][2][3][4][5][6][7][8]oor
	>--------------------------
	>[1][2][3][4][5][6][7][.]
	
*/
int xc_am_seq_tStatic_shiftLeft(
	  const xc_am_seq_cfg_t* refp_cfg
	, xc_am_seq_state_t* refp_state
	, const size_t start_public_idx
	, const size_t shift_size
)
{
	xc_err_decl();
	/* ---  */
	
	if(NULL==refp_cfg) {
		xc_err_term_unmg();
	}
	if(NULL==refp_state) {
		xc_err_term_unmg();
	}
	if(0==shift_size) {
		xc_err_term_unmg();
	}
	/* ---  */
	if( start_public_idx >= refp_state->length ) {
		xc_err_term_unmg();
	}
	if( start_public_idx >= refp_state->capacity) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if(0!=shift_size)
	{
		const size_t target_array_idx_next=start_public_idx+1;
		xc_am_seq_tStatic_shift_info_t tmpresult={0};
		
		if( 0 != xc_am_seq_tStatic_shiftLeft_calculate(refp_state, start_public_idx, shift_size, &tmpresult) ) {
			xc_err_term_unmg();
		}
		
		/* shift <- : */
		if(target_array_idx_next<refp_state->length) /* -1 */
		{
			const size_t next_idx_after_lastIitem_after=tmpresult.last_idx+1; /*!*/
			/* full shift by X items */
			
			xc_byteptr_t target_item_byteptr=NULL;
			xc_byteptr_t target_next_item_byteptr=NULL;
			xc_byteptr_t after_lastItem_byteptr=NULL;
			size_t length_for_memcpy_operation=tmpresult.cnt_from_target_index_to_orig_length; /*!*/
			size_t length_for_memzero_operation=tmpresult.cnt_shift_bound;
			
			if(NULL == (target_item_byteptr=xc_am_seq_idx2byteptr(refp_state, refp_cfg->item_bytesize, start_public_idx) ) ) {
				xc_err_term_unmg();
			}
			if(NULL == (target_next_item_byteptr=xc_am_seq_idx2byteptr(refp_state, refp_cfg->item_bytesize, target_array_idx_next) ) ) {
				xc_err_term_unmg();
			}
			if(NULL == (after_lastItem_byteptr=xc_am_seq_idx2byteptr(refp_state, refp_cfg->item_bytesize, next_idx_after_lastIitem_after) ) ) {
				xc_err_term_unmg();
			}
			
			/* after this point: everything is validated */
			/* only crash impossible to manage can happen */
			
			/* perform shift <- : */
			memmove(target_item_byteptr, target_next_item_byteptr, refp_cfg->item_bytesize*length_for_memcpy_operation);
			/* perform shift <- : done */
			
			/* zero complementary items: */
			xc_mem_bzero_bytes(after_lastItem_byteptr, refp_cfg->item_bytesize*length_for_memzero_operation); /*!*/
			/* zero complementary items: done */
			
			refp_state->length=tmpresult.new_length;
		}
		else 
		{ 
			/* just pop last item */
			
			xc_byteptr_t after_lastItem_byteptr=NULL;

			if(NULL == (after_lastItem_byteptr=xc_am_seq_idx2byteptr(refp_state, refp_cfg->item_bytesize, refp_state->length-1 ) ) ) {
				xc_err_term_unmg();
			}

			/* zero complementary items: */
			xc_mem_bzero_bytes(after_lastItem_byteptr, refp_cfg->item_bytesize*1);
			/* zero complementary items: done */
			
			refp_state->length--;
		}
		/* shift <- : done */
		
	}
	else
	{
		/* do nothing */
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}


int xc_am_seq_tStatic_shiftRight(
	  const xc_am_seq_cfg_t* refp_cfg
	, xc_am_seq_state_t* refp_state
	, const size_t start_public_idx
	, const size_t shift_size
)
{
	xc_err_decl();
	/* ---  */
	
	if(NULL==refp_cfg) {
		xc_err_term_unmg();
	}
	if(NULL==refp_state) {
		xc_err_term_unmg();
	}
	if(0==shift_size) {
		xc_err_term_unmg();
	}
	/* ---  */
	if( start_public_idx >= refp_state->length ) {
		xc_err_term_unmg();
	}
	if( start_public_idx >= refp_state->capacity) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if(0!=shift_size)
	{
		size_t target_array_idx_next=0;
		xc_am_seq_tStatic_shift_info_t tmpresult={0};
		/* const size_t target_array_idx_next=start_public_idx+1; */
		
		if( 0 != xc_am_seq_tStatic_shiftRight_calculate(refp_state, start_public_idx, shift_size, &tmpresult) ) {
			xc_err_term_unmg();
		}
		
		target_array_idx_next=start_public_idx+tmpresult.cnt_shift_bound; 
		
		/* shift -> : */
		if(start_public_idx < refp_state->length)
		{
			xc_byteptr_t target_item_byteptr=NULL;
			xc_byteptr_t target_next_item_byteptr=NULL;
			xc_byteptr_t after_curItem_byteptr=NULL;
			
			if(NULL == (target_item_byteptr=xc_am_seq_idx2byteptr(refp_state, refp_cfg->item_bytesize, start_public_idx) ) ) {
				xc_err_term_unmg();
			}
			if(NULL == (target_next_item_byteptr=xc_am_seq_idx2byteptr(refp_state, refp_cfg->item_bytesize, target_array_idx_next) ) ) {
				xc_err_term_unmg();
			}
			if(NULL == (after_curItem_byteptr=xc_am_seq_idx2byteptr(refp_state, refp_cfg->item_bytesize, start_public_idx) ) ) {
				xc_err_term_unmg();
			}
			
			/* after this point: everything is validated */
			/* only crash impossible to manage can happen */
			
			/* perform shift -> : */
			memmove(target_next_item_byteptr, target_item_byteptr, refp_cfg->item_bytesize*tmpresult.cnt_from_target_index_to_orig_length );
			/* perform shift -> : done */
			
			/* zero hole items: */
			xc_mem_bzero_bytes(after_curItem_byteptr, refp_cfg->item_bytesize*tmpresult.cnt_shift_bound); /*!*/
			/* zero hole items: done */
			
			refp_state->length=tmpresult.new_length;
		}
		else 
		{ 
			/* just push last item */
			
			xc_byteptr_t after_lastItem_byteptr=NULL;

			if(NULL == (after_lastItem_byteptr=xc_am_seq_idx2byteptr(refp_state, refp_cfg->item_bytesize, refp_state->length ) ) ) {
				xc_err_term_unmg();
			}

			/* zero complementary items: */
			/*xc_mem_bzero_bytes(after_lastItem_byteptr, refp_cfg->item_bytesize*tmpresult.cnt_shift_bound);*/ /* change: completely not required for SHIFT RIGHT; and we're supposed to utilize already zeroed block */
			/* zero complementary items: done */
			
			refp_state->length+=tmpresult.cnt_shift_bound;
		}
		/* shift -> : done */
		
	}
	else
	{
		/* do nothing */
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}


int xc_am_seq_tStatic_realloc(
	  const xc_am_seq_cfg_t* refp_cfg
	, const xc_am_seq_state_t* refp_initial_state
	, xc_am_seq_state_t* refp_result_state
	, const size_t requested_new_capacity
)
{
	size_t new_capacity=requested_new_capacity;
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
	
	/* restriction on capacity value zero: */
	/* will NOT be deallocated completely to 0 */
	if( 0 == new_capacity ) {
		new_capacity=1;
	}
	/* restriction on capacity value zero: done */
	
	xc_mem_bzero_obj(xc_am_seq_state_t, refp_result_state);
	
	/* --- content validation: done */

	if( new_capacity < refp_initial_state->capacity )
	{
		is_to_resize=1;
	}
	else
	if( new_capacity > refp_initial_state->capacity )
	{
		is_to_resize=1;
	}
	else
	if( new_capacity == refp_initial_state->capacity )
	{
		is_to_resize=0;
	}
	
	/* --- --- --- */
	
	if( 0 !=  is_to_resize )
	{
		xc_p_pBytes_t tmp_result_byteptr={0};
		
		/* try to resize: */
		if(1)
		{
			xc_p_pBytes_t tmp_target_byteptr={0};
			const size_t newbytesize=refp_cfg->item_bytesize*new_capacity;
			
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
		
		/* result: write length: */
		if(1)
		{
			
			if( refp_initial_state->length > new_capacity ) { /* must be truncated */
				refp_result_state->length=new_capacity;
			}
			else { /* not truncated */
				refp_result_state->length=refp_initial_state->length;
			}
			
		}
		/* result: write length: done */
		
		/* result: modified capacity: */
		refp_result_state->capacity=new_capacity;
		/* result: modified capacity: done */
	}
	else /* no change, just copy initial -> result */
	{
		xc_mem_cp_obj(xc_am_seq_state_t, refp_result_state, refp_initial_state);
	}
	
	if(1)
	{
		size_t n=0;
		
		for(n=refp_result_state->length; n<refp_result_state->capacity; n++)
		{
			xc_p_pBytes_t BtPtr={0};
			xc_p_pBytes_t BtPtr2={0};
			
			BtPtr2=xc_p_pBytes_from_ref2pBytes(refp_result_state->refp_itemArray_byteptr);
			
			BtPtr.BtPtr=BtPtr2.BtPtr+n*refp_cfg->item_bytesize;
			xc_mem_bzero_bytes(BtPtr.BtPtr, refp_cfg->item_bytesize);
		}
	}
	
	return 0;
	
	xc_err_on_unmg();
		if(NULL!=refp_result_state) {
			xc_mem_bzero_obj(xc_am_seq_state_t, refp_result_state);
		}
	return 1;
}



xc_byteptr_t xc_am_seq_idx2byteptr(xc_am_seq_state_t* self_state, const size_t item_bytesize, const size_t idx_public)
{
	xc_p_pBytes_t tmp_BtPtr={0};
	xc_byteptr_t refp_item=NULL;
	
	if(NULL==self_state) {
		return NULL;
	}
	
	if( idx_public >= self_state->capacity) {
		return NULL;
	}
	
	tmp_BtPtr=xc_p_pBytes_from_ref2pBytes(self_state->refp_itemArray_byteptr);
	
	refp_item=tmp_BtPtr.BtPtr+idx_public*item_bytesize;
	
	return refp_item;
}


void* xc_am_seq_idx2anyptr(xc_am_seq_state_t* self_state, const size_t item_bytesize, const size_t idx_public)
{
	xc_p_pBytes_t tmp_BtPtr={0};
	xc_byteptr_t refp_item=NULL;
	
	if(NULL==self_state) {
		return NULL;
	}
	
	if( idx_public >= self_state->capacity) {
		return NULL;
	}
	
	tmp_BtPtr=xc_p_pBytes_from_ref2pBytes(self_state->refp_itemArray_byteptr);
	
	refp_item=tmp_BtPtr.BtPtr+idx_public*item_bytesize;
	
	return (void*)refp_item;
}

