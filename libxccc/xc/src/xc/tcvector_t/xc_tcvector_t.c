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
#include "xc/common/xc_tc_common.h"
/* --- */
#include "xc/am_seq/xc_ammo_seq.h"
#include "xc/tcvector_t/xc_tcvector_t.h"
/* --- */

/* base value for object initialization check */
#define  xc_tcVectorT_LL_initval 3450


static void* idx2itemptr(const xc_tcVectorT_LL_deref_t* self_deref, const size_t idx_public);

/*
 * high- level validation of DEREFER; DOES NOT check if object is operational; 
 * to be used only internally, eg. before calling init(
 */
static int xc_tcVectorT_LL_validate_integrity(const xc_tcVectorT_LL_deref_t* refp_deref);


static int xc_tcVectorT_LL_validate_integrity_const(const xc_tcVectorT_LL_derefConst_t* refp_deref);

static int xc_tcVectorT_LL_validate_initialization_and_index_access_refp(const xc_tcVectorT_LL_deref_t* self_deref, const int idx);

static int xc_tcVectorT_LL_validate_initialization_and_index_access_insert_refp(const xc_tcVectorT_LL_deref_t* self_deref, const int idx);

/* *** *** *** */
/* *** INIT: *** */
/* *** INIT: *** */


/* *** INIT: *** */


static int xc_tcVectorT_LL_validate_integrity(const xc_tcVectorT_LL_deref_t* refp_deref)
{
	xc_err_decl();
	
	if(NULL==refp_deref) {
		xc_err_term_unmg();
	}
	
	if(NULL==refp_deref->items_byteptr.BtPtr) {
		xc_err_term_unmg();
	}
	
	if(NULL==refp_deref->refp_hdr) {
		xc_err_term_unmg();
	}
	
	if(NULL==refp_deref->self_bytes_ref.BtPtr) {
		xc_err_term_unmg();
	}
	if(0==refp_deref->self_bytes_size) {
		xc_err_term_unmg();
	}
	
	return 0;
	
	xc_err_on_unmg();
	xc_err_return();
}

static int xc_tcVectorT_LL_validate_integrity_const(const xc_tcVectorT_LL_derefConst_t* refp_deref)
{
	xc_err_decl();
	
	if(NULL==refp_deref) {
		xc_err_term_unmg();
	}
	
	if(NULL==refp_deref->items_byteptr.BtPtr) {
		xc_err_term_unmg();
	}
	
	if(NULL==refp_deref->refp_hdr) {
		xc_err_term_unmg();
	}
	
	if(NULL==refp_deref->self_bytes_ref.BtPtr) {
		xc_err_term_unmg();
	}
	if(0==refp_deref->self_bytes_size) {
		xc_err_term_unmg();
	}
	
	return 0;
	
	xc_err_on_unmg();
	xc_err_return();
}


int xc_tcVectorT_LL_validate_initialized(const xc_tcVectorT_LL_deref_t* refp_deref)
{
	xc_err_decl();
	
	if( 0 != xc_tcVectorT_LL_validate_integrity(refp_deref) ) {
		xc_err_term_unmg();
	}
	
	if(1)
	{
		if( 0 == xc_initc_anyscopeNZ_isValid_u( (&refp_deref->refp_hdr->runtime.initIndicator), xc_tcVectorT_LL_initval) ) {
			xc_err_term_unmg();
		}
	}
	
	return 0;
	
	xc_err_on_unmg();
	xc_err_return();
}


int xc_tcVectorT_LL_validate_initialized_const(const xc_tcVectorT_LL_derefConst_t* refp_deref)
{
	xc_err_decl();
	
	if( 0 != xc_tcVectorT_LL_validate_integrity_const(refp_deref) ) {
		xc_err_term_unmg();
	}
	
	if(1)
	{
		if( 0 == xc_initc_anyscopeNZ_isValid_u( (&refp_deref->refp_hdr->runtime.initIndicator), xc_tcVectorT_LL_initval) ) {
			xc_err_term_unmg();
		}
	}
	
	return 0;
	
	xc_err_on_unmg();
	xc_err_return();
}

static int xc_tcVectorT_LL_validate_initialization_and_index_access_refp(const xc_tcVectorT_LL_deref_t* self_deref, const int idx)
{
	size_t conv_idx=0;
	xc_err_decl();
	
	if( 0 != xc_tcVectorT_LL_validate_initialized(self_deref) ) {
		xc_err_term_mg(); /* manageable error */
	}
	
	if( 0 == xc_tc_isValid_idx_staticRange(idx) ) {
		xc_err_term_mg(); /* manageable error */
	}
	
	conv_idx=idx;  /* !!! int -> uint [VALIDATED] */
	
	if( conv_idx >= self_deref->refp_hdr->runtime.cur_length ) {
		xc_err_term_mg(); /* manageable error */
	}

	if( conv_idx >= self_deref->refp_hdr->cfg.static_capacity) { /* redundant */
		xc_err_term_mg(); /* manageable error */
	}
	
	return 0;
	
	xc_err_on_mg();
	return 1;
}

static int xc_tcVectorT_LL_validate_initialization_and_index_access_insert_refp(const xc_tcVectorT_LL_deref_t* self_deref, const int idx)
{
	size_t conv_idx=0;
	xc_err_decl();
	
	if( 0 != xc_tcVectorT_LL_validate_initialized(self_deref) ) {
		xc_err_term_mg(); /* manageable error */
	}
	
	if( 0 == xc_tc_isValid_idx_staticRange(idx) ) {
		xc_err_term_mg(); /* manageable error */
	}
	
	conv_idx=idx;  /* !!! int -> uint [VALIDATED] */
	
	if( conv_idx > self_deref->refp_hdr->runtime.cur_length ) {
		xc_err_term_mg(); /* manageable error */
	}

	if( conv_idx >= self_deref->refp_hdr->cfg.static_capacity) { /* redundant */
		xc_err_term_mg(); /* manageable error */
	}
	
	return 0;
	
	xc_err_on_mg();
	return 1;
}

int xc_tcVectorT_LL_validate_initialization_and_index_access(xc_tcVectorT_LL_deref_t self_deref, const int idx)
{
	return xc_tcVectorT_LL_validate_initialization_and_index_access_refp(&self_deref, idx);
}




xc_tcVectorT_LL_deref_t xc_tcVectorT_LL_derefer_get_retv(xc_tcVectorT_hdr_t* refp_hdr, xc_byteptr_t refp_items_byteptr, xc_byteptr_t self_byteptr, const size_t self_size)
{
	xc_tcVectorT_LL_deref_t retv_empty={0};
	xc_tcVectorT_LL_deref_t retv={0};
	xc_err_decl();
	/* --- */
	
	if(NULL==refp_hdr) {
		xc_err_term_mg();
	}
	if(NULL==refp_items_byteptr) {
		xc_err_term_mg();
	}
	/* --- */
	
	retv.items_byteptr.BtPtr=refp_items_byteptr;
	retv.refp_hdr=refp_hdr;
	retv.self_bytes_ref.BtPtr=self_byteptr;
	retv.self_bytes_size=self_size;
	
	return retv;
	
	xc_err_on_mg();
	return retv_empty;
	
}


xc_tcVectorT_LL_derefConst_t xc_tcVectorT_LL_derefer_get_retv_const(const xc_tcVectorT_hdr_t* refp_hdr, const unsigned char* refp_items_byteptr, const unsigned char* self_byteptr, const size_t self_size)
{
	xc_tcVectorT_LL_derefConst_t retv_empty={0};
	xc_tcVectorT_LL_derefConst_t retv={0};
	xc_err_decl();
	/* --- */
	
	if(NULL==refp_hdr) {
		xc_err_term_mg();
	}
	if(NULL==refp_items_byteptr) {
		xc_err_term_mg();
	}
	/* --- */
	/* this is irrelevant, because it's const -> nonconst -> const w/o any other operations */
	retv.items_byteptr.BtPtr=refp_items_byteptr;
	retv.refp_hdr=refp_hdr;
	retv.self_bytes_ref.BtPtr=self_byteptr;
	retv.self_bytes_size=self_size;
	
	do
	{
		const xc_tcVectorT_LL_derefConst_t retv2=retv;
		return retv2;
	} while(0);
	
	xc_err_on_mg();
	return retv_empty;
	
}


int xc_tcVectorT_LL_init(
	  xc_tcVectorT_LL_deref_t self_deref
	, const size_t cfg_itemsize
	, const size_t items_bytesize
)
{
	return xc_tcVectorT_LL_init__dc01(
		  self_deref
		, cfg_itemsize
		, items_bytesize
	);
}

int xc_tcVectorT_LL_init__dc01(
	  xc_tcVectorT_LL_deref_t self_deref
	, const size_t cfg_itemsize
	, const size_t items_bytesize
)
{
	size_t new_capacity=0;
	xc_tcVectorT_LL_deref_t* refp_deref=NULL;
	xc_err_decl();
	
	refp_deref=&self_deref;
	
	if( 0 != xc_tcVectorT_LL_validate_integrity(refp_deref) ) {
		xc_err_term_unmg();
	}
	
	if(1)
	{
		if( 0 == xc_tc_isValid_capacity_staticRange_uint(cfg_itemsize) ) {
			xc_err_term_unmg();
		}
		
		new_capacity=items_bytesize/cfg_itemsize;
		
		if( 0 == xc_tc_isValid_capacity_staticRange_uint(new_capacity) ) {
			xc_err_term_unmg();
		}
		
		if( 0 != xc_tc_validate_arrayStaticSize(new_capacity, cfg_itemsize) ) {
			xc_err_term_unmg();
		}

	}
	
	xc_mem_bzero_bytes(refp_deref->self_bytes_ref.BtPtr, refp_deref->self_bytes_size);
	
	refp_deref->refp_hdr->cfg.obj_bytesize=cfg_itemsize;
	
	if(1) /* indicate initialization by writing specific pattern */
	{
		if( 0 != xc_initc_anyscopeNZ_init_c( &refp_deref->refp_hdr->runtime.initIndicator, xc_tcVectorT_LL_initval) ) {
			xc_err_term_unmg();
		}
	}
	
	/* allocation : separeted scope, this may change between version */
	if(1)
	{
		xc_mem_bzero_bytes(refp_deref->items_byteptr.BtPtr, items_bytesize);

		refp_deref->refp_hdr->cfg.static_capacity=new_capacity;
	}
	
	return 0;
	
	xc_err_on_unmg();
	xc_err_return();
}


void* xc_tcVectorT_LL_init_ret_self_refp(
	  xc_tcVectorT_LL_deref_t self_deref
	, const size_t cfg_itemsize
	, const size_t items_bytesize
)
{
	xc_tcVectorT_LL_deref_t* refp_deref=NULL;
	xc_err_decl();
	/* --- */
	
	refp_deref=&self_deref;
	
	if( 0 != xc_tcVectorT_LL_init(
		  self_deref
		, cfg_itemsize
		, items_bytesize
		)
	) {
		xc_err_term_unmg();
	}
	
	return refp_deref->self_bytes_ref.BtPtr;
	
	xc_err_on_unmg();
	return NULL;
}


void* xc_tcVectorT_LL_init_ret_self_refp__dc01(
	  xc_tcVectorT_LL_deref_t self_deref
	, const size_t cfg_itemsize
	, const size_t items_bytesize
)
{
	xc_tcVectorT_LL_deref_t* refp_deref=NULL;
	xc_err_decl();
	/* --- */
	
	refp_deref=&self_deref;
	
	if( 0 != xc_tcVectorT_LL_init__dc01(
		  self_deref
		, cfg_itemsize
		, items_bytesize
		)
	) {
		xc_err_term_unmg();
	}
	
	return refp_deref->self_bytes_ref.BtPtr;
	
	xc_err_on_unmg();
	return NULL;
}

int xc_tcVectorT_LL_deinit(xc_tcVectorT_LL_deref_t self_deref)
{
	xc_byteptr_t items_byteptr=NULL;
	xc_err_decl();
	
	if( 0 != xc_tcVectorT_LL_validate_initialized(&self_deref) ) {
		xc_err_term_unmg();
	}
	
	items_byteptr=self_deref.items_byteptr.BtPtr;
	
	xc_mem_bzero_bytes( self_deref.self_bytes_ref.BtPtr, self_deref.self_bytes_size );
	
	return 0;
	
	xc_err_on_unmg();
	xc_err_return();
}


int xc_tcVectorT_LL_inspect_LLII_info_cp(xc_tcVectorT_LL_deref_t self_deref, const int idx, xc_tcVectorT_LL_inspect_LLII_info_t* refp_result)
{
	size_t tmp_idx=0;
	xc_p_pBytes_t tmp_byteptr_items={0};
	xc_err_decl();
	/* --- */
	
	if( 0 != xc_tcVectorT_LL_validate_initialized(&self_deref) ) {
		xc_err_term_unmg();
	}
	if(NULL == refp_result) {
		xc_err_term_unmg();
	}
	/* --- */
	tmp_byteptr_items=self_deref.items_byteptr;
	
	tmp_idx=idx; /* ssigned -> unsigned */
	
	/* 
	 *  check: index out of CAPACITY range
	 *  any allocated object within CAPACITY can be inspected, but index out of range is unmanaged error
	 */
	if( tmp_idx >= self_deref.refp_hdr->cfg.static_capacity ) {
		xc_err_term_unmg();
	}
	
	xc_mem_bzero_obj(xc_tcVectorT_LL_inspect_LLII_info_t, refp_result);
	
	refp_result->anyptr_item=(void*) ( (xc_byteptr_t)(  (tmp_byteptr_items.BtPtr+tmp_idx*self_deref.refp_hdr->cfg.obj_bytesize) ) );
	refp_result->byteptr_item=(xc_byteptr_t) (tmp_byteptr_items.BtPtr+tmp_idx*self_deref.refp_hdr->cfg.obj_bytesize);
	
	refp_result->item_idx_LLII=tmp_idx;
	refp_result->item_idx_public=tmp_idx;
	
	if(tmp_idx < self_deref.refp_hdr->runtime.cur_length) {
		refp_result->valid=1;
	}
	else {
		refp_result->valid=0;
	}
	
	return  0;
	
	xc_err_on_unmg();
	return 1;
}

/* *** INIT: done *** */














/* *** ADD: *** */



int xc_tcVectorT_LL_push(xc_tcVectorT_LL_deref_t self_deref, const void* obj_bytes_ref, const size_t obj_bytes_size)
{
	size_t new_required_length=0;
	size_t idx_last_old=0;
	xc_tcVectorT_LL_deref_t* refp_deref=&self_deref;
	xc_err_decl();
	/* --- */
	
	if( 0 != xc_tcVectorT_LL_validate_initialized(refp_deref) ) {
		xc_err_term_unmg();
	}
	if( NULL == obj_bytes_ref ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	new_required_length=self_deref.refp_hdr->runtime.cur_length+1;

	if(new_required_length>self_deref.refp_hdr->cfg.static_capacity) {
		xc_err_term_unmg();
	}

	/* --- */
	
	idx_last_old=self_deref.refp_hdr->runtime.cur_length;
	
	/* allocation : separeted scope, this may change between version */
	if(1)
	{
		/* nothing to do - just increase length */
		refp_deref->refp_hdr->runtime.cur_length=new_required_length;
	}
	
	/* shallow copy to last index before reallocation */
	if(1)
	{
		void* item_destination_ptr=NULL;
		
		if(NULL == (item_destination_ptr=idx2itemptr(&self_deref, idx_last_old) ) ) {
			xc_err_term_unmg();
		}
		
		memcpy( item_destination_ptr, obj_bytes_ref, self_deref.refp_hdr->cfg.obj_bytesize );
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}



/* *** ADD: done *** */

































/* *** REMOVE: *** */



int xc_tcVectorT_LL_pop(xc_tcVectorT_LL_deref_t self_deref)
{
	size_t new_required_length=0;
	xc_tcVectorT_LL_deref_t* refp_deref=&self_deref;
	xc_err_decl();
	/* --- */
	
	/* validate params: */
	
	if( 0 != xc_tcVectorT_LL_validate_initialized(refp_deref) ) {
		xc_err_term_unmg();
	}
	
	/* validate params: done */

	/* --- */
	
	/* validate state: */

	if( 0 == self_deref.refp_hdr->runtime.cur_length ) {
		xc_err_term_unmg();
	}
	if( 0 == self_deref.refp_hdr->cfg.static_capacity ) { /* redundant */
		xc_err_term_unmg();
	}
	/* validate state: done */
	
	/*  : */
	new_required_length=self_deref.refp_hdr->runtime.cur_length-1;
	
	if( new_required_length>self_deref.refp_hdr->cfg.static_capacity ) {
		xc_err_term_unmg();
	}
	/*  : done */
	
	/* --- */
	
	/* erase last: */
	if(1)
	{
		size_t last_array_idx=0;
		xc_byteptr_t lastItem_byteptr=NULL;
		
		/* get last array index: */
		last_array_idx=self_deref.refp_hdr->runtime.cur_length-1;
		/* get last array index: done */
		
		if(NULL == (lastItem_byteptr=idx2itemptr(&self_deref, last_array_idx) ) ) {
			xc_err_term_unmg();
		}
		
		xc_mem_bzero_bytes(lastItem_byteptr, self_deref.refp_hdr->cfg.obj_bytesize);
	}
	/* erase last: done */
	
	/* shrink if required: */
	if(1)
	{
		refp_deref->refp_hdr->runtime.cur_length=new_required_length;
	}
	/* shrink if required: done */
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}






int xc_tcVectorT_LL_rem_idx(xc_tcVectorT_LL_deref_t self_deref, const int public_idx)
{
	size_t new_required_length=0;
	const size_t target_array_idx=public_idx; /* ! uint <- int  */
	xc_tcVectorT_LL_deref_t* refp_deref=&self_deref;
	xc_err_decl();
	/* --- */
	
	/* validate params: */
	
	if( 0 != xc_tcVectorT_LL_validate_initialization_and_index_access_refp(refp_deref, public_idx) ) {
		xc_err_term_unmg();
	}
	/* validate params: done */

	/* --- */
	
	/* validate state: */
	if( 0 == self_deref.refp_hdr->runtime.cur_length ) {
		xc_err_term_unmg();
	}
	if( 0 == self_deref.refp_hdr->cfg.static_capacity ) { /* redundant */
		xc_err_term_unmg();
	}
	if( target_array_idx >= self_deref.refp_hdr->runtime.cur_length ) {
		xc_err_term_unmg();
	}
	/* validate state: done */
	
	/* : */
	new_required_length=self_deref.refp_hdr->runtime.cur_length-1;
	if(new_required_length>self_deref.refp_hdr->cfg.static_capacity) {
		xc_err_term_unmg();
	}
	/* : done */
	
	/* shrink if required: */
	if(1)
	{
		xc_ammo_seq_cfg_t alloctr_cfg={0};
		xc_ammo_seq_state_t alloctr_state_init={0};
		xc_ammo_seq_state_t alloctr_state_init_updated={0};
		xc_p_refp2pBytes_t tmpRef2PB={0};
		
		tmpRef2PB.Refp2BtPtr=&self_deref.items_byteptr.BtPtr; /* wrapper for it, and byteptr must not be passed as value */
		
		alloctr_cfg=xc_ammo_seq_cfg_retv(
			  self_deref.refp_hdr->cfg.obj_bytesize
			, 1
		);
		
		alloctr_state_init=xc_ammo_seq_state_retv(
			  tmpRef2PB
			, self_deref.refp_hdr->runtime.cur_length
			, self_deref.refp_hdr->cfg.static_capacity
		);
		
		alloctr_state_init_updated=alloctr_state_init;
		
		/* shift: */
		if(1)
		{
			const size_t shift_cnt=1;
			
			if( 0 != xc_ammo_seq_tStatic_shiftLeft(&alloctr_cfg, &alloctr_state_init_updated, public_idx, shift_cnt) ) {
				xc_err_term_unmg();
			}
		}
		/* shift: done */
		
		/*refp_deref->items_byteptr=xc_p_pBytes_from_ref2pBytes(alloctr_state_init_updated.refp_itemArray_byteptr);*/ /* this will */
		/* refp_deref->refp_hdr->cfg.static_capacity=alloctr_state_init_updated.capacity; */ /* this will never change */
		refp_deref->refp_hdr->runtime.cur_length=alloctr_state_init_updated.length;
	}
	/* shrink if required: done */
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}

/* *** REMOVE: done *** */






/* *** INSERT: *** */

int xc_tcVectorT_LL_insert(xc_tcVectorT_LL_deref_t self_deref, const int public_idx, const void* obj_bytes_ref, const size_t obj_bytes_size)
{
	size_t new_required_length=0;
	const size_t target_array_idx=public_idx; /* ! uint <- int  */
	xc_tcVectorT_LL_deref_t* refp_deref=&self_deref;
	xc_err_decl();
	/* --- */
	
	/* validate params: */
	
	if( 0 != xc_tcVectorT_LL_validate_initialization_and_index_access_insert_refp(refp_deref, public_idx) ) {
		xc_err_term_unmg();
	}
	if( NULL == obj_bytes_ref ) {
		xc_err_term_unmg();
	}
	/* validate params: done */

	/* --- 	*/
	
	/* : */
	new_required_length = self_deref.refp_hdr->runtime.cur_length+1;
	if( new_required_length > self_deref.refp_hdr->cfg.static_capacity ) {
		xc_err_term_unmg();
	}
	/* : done */
	
	/* validate state: */
	if( 0 == self_deref.refp_hdr->cfg.static_capacity ) { /* redundant */
		xc_err_term_unmg();
	}
	if( target_array_idx > self_deref.refp_hdr->runtime.cur_length ) { /* error if reference to outside of length */ /* insert at IDX==LENGTH iis valid (works as push) */
		xc_err_term_unmg();
	}
	/* validate state: done */
	
	/* grow if required: */
	if(1)
	{
		
		xc_ammo_seq_cfg_t alloctr_cfg={0};
		xc_ammo_seq_state_t alloctr_state_init={0};
		xc_ammo_seq_state_t alloctr_state_init_updated={0};
		xc_p_refp2pBytes_t tmpRef2PB={0};
		
		tmpRef2PB.Refp2BtPtr=&self_deref.items_byteptr.BtPtr;

		alloctr_cfg=xc_ammo_seq_cfg_retv(
			  self_deref.refp_hdr->cfg.obj_bytesize
			, 1
		);
		
		alloctr_state_init=xc_ammo_seq_state_retv(
			  tmpRef2PB
			, self_deref.refp_hdr->runtime.cur_length
			, self_deref.refp_hdr->cfg.static_capacity
		);
		
		alloctr_state_init_updated=alloctr_state_init;
		
		if(target_array_idx < self_deref.refp_hdr->runtime.cur_length )
		{
			/* shift: */
			if(1)
			{
				const size_t shift_cnt=1;
				
				if( 0 != xc_ammo_seq_tStatic_shiftRight(&alloctr_cfg, &alloctr_state_init_updated, public_idx, shift_cnt) ) {
					xc_err_term_unmg();
				}
			}
			/* shift: done */
		}
		else /* just append 1 element */
		{
			alloctr_state_init_updated.length++;
		}
		
		/* refp_deref->items_byteptr=alloctr_state_init_updated.refp_itemArray_byteptr; */ /* will not change */
		/* refp_deref->refp_hdr->cfg.static_capacity=alloctr_state_init_updated.capacity; */ /* will not change */
		refp_deref->refp_hdr->runtime.cur_length=alloctr_state_init_updated.length;
	}
	/* grow if required: done */
	
	/* set item at index: */
	if(1)
	{
		void* item_destination_ptr=NULL;
		
		if(NULL == (item_destination_ptr=idx2itemptr(&self_deref, target_array_idx) ) ) {
			xc_err_term_unmg();
		}
		
		memcpy( item_destination_ptr, obj_bytes_ref, self_deref.refp_hdr->cfg.obj_bytesize );
	}
	/* set item at index: done */
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}


/* *** INSERT: DONE *** */





int xc_tcVectorT_LL_get_cp(xc_tcVectorT_LL_deref_t self_deref, const int idx, void* obj_bytes_ref, const size_t obj_bytes_size)
{
	void* refp_item_by_idx=NULL;
	xc_err_decl();
	/* --- */
	
	/* validate params: */
	if( 0 != xc_tcVectorT_LL_validate_initialized(&self_deref) ) {
		xc_err_term_unmg();
	}
	
	if(0!=xc_tcVectorT_LL_validate_initialization_and_index_access_refp(&self_deref, idx) ) {
		xc_err_term_unmg();
	}
	if(NULL==obj_bytes_ref) {
		xc_err_term_unmg();
	}
	/* validate params: done */
	
	if( NULL == (refp_item_by_idx=idx2itemptr(&self_deref, idx) ) ) {
		xc_err_term_unmg();
	}
	
	memcpy(obj_bytes_ref, refp_item_by_idx, self_deref.refp_hdr->cfg.obj_bytesize);
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}




int xc_tcVectorT_LL_get_capacity(xc_tcVectorT_LL_deref_t self_deref)
{
	xc_err_decl();
	/* --- */
	
	/* validate params: */
	if( 0 != xc_tcVectorT_LL_validate_initialized(&self_deref) ) {
		xc_err_term_unmg();
	}
	/* validate params: done */
	
	return self_deref.refp_hdr->cfg.static_capacity;
	
	xc_err_on_unmg();
	return 0;
}


int xc_tcVectorT_LL_get_length(xc_tcVectorT_LL_deref_t self_deref)
{
	xc_err_decl();
	/* --- */
	
	/* validate params: */
	if( 0 != xc_tcVectorT_LL_validate_initialized(&self_deref) ) {
		xc_err_term_unmg();
	}
	/* validate params: done */
	
	return self_deref.refp_hdr->runtime.cur_length;
	
	xc_err_on_unmg();
	return 0;
}



int xc_tcVectorT_LL_isEmpty(xc_tcVectorT_LL_deref_t self_deref)
{
	xc_err_decl();
	/* --- */
	
	/* validate params: */
	
	if( 0 != xc_tcVectorT_LL_validate_initialized(&self_deref) ) {
		xc_err_term_unmg();
	}
	
	/* validate params: done */
	
	if( 0 != self_deref.refp_hdr->runtime.cur_length) {
		return 0;
	}
	
	return 1;
	
	xc_err_on_unmg();
	return 1;
}


int xc_tcVectorT_LL_set_idx(xc_tcVectorT_LL_deref_t self_deref, const int idx, const void* obj_bytes_ref, const size_t obj_bytes_size)
{
	
	xc_tcVectorT_LL_deref_t* refp_deref=&self_deref;
	xc_err_decl();
	/* --- */
	
	if( NULL == obj_bytes_ref ) {
		xc_err_term_unmg();
	}
	if( 0 != xc_tcVectorT_LL_validate_initialization_and_index_access(self_deref, idx) ) {
		xc_err_term_unmg();
	}
	
	/* shallow copy to last index before reallocation */
	if(1)
	{
		void* item_destination_ptr=NULL;
		
		if(NULL == (item_destination_ptr=idx2itemptr(&self_deref, idx) ) ) {
			xc_err_term_unmg();
		}
		
		memcpy( item_destination_ptr, obj_bytes_ref, self_deref.refp_hdr->cfg.obj_bytesize );
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}


void* xc_tcVectorT_LL_alloc(const size_t self_obj_bytesize)
{
	void* retv_anyptr=NULL;
	xc_err_decl();
	/* --- */
	
	if(0 == self_obj_bytesize) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if( NULL == ( retv_anyptr=xc_mem_allocz_bytes(self_obj_bytesize) ) ) {
		xc_err_term_unmg();
	}
	
	return retv_anyptr;
	
	xc_err_on_unmg();
	return NULL;
}


int xc_tcVectorT_LL_dealloc(xc_tcVectorT_LL_deref_t self_deref)
{
	size_t self_bytesize=0;
	void* ptr_obj=NULL;
	xc_tcVectorT_LL_deref_t* refp_deref=&self_deref;
	xc_err_decl();
	/* --- */
	
	if( NULL == refp_deref->self_bytes_ref.BtPtr ) {
		xc_err_term_unmg();
	}
	if( 0 == refp_deref->self_bytes_size ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	self_bytesize=refp_deref->self_bytes_size;
	ptr_obj=refp_deref->self_bytes_ref.BtPtr;
	
	/* deinit */
	if( 0 == xc_tcVectorT_LL_deinit(self_deref) ) { 
		/* dealloc upon succeesful deinit */
		xc_mem_free_bytes(ptr_obj);
	}
	else {
		xc_err_term_unmg();
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}


int xc_tcVectorT_LL_assign_from(xc_tcVectorT_LL_deref_t self_deref, const xc_tcVectorT_LL_derefConst_t src_deref, int* opt_overflow)
{
	size_t new_required_length=0;
	xc_err_decl();
	/* --- */

	if( 0 != xc_tcVectorT_LL_validate_initialized(&self_deref) ) {
		xc_err_term_unmg();
	}
	if( 0 != xc_tcVectorT_LL_validate_initialized_const(&src_deref) ) {
		xc_err_term_unmg();
	}
	/* --- */
	if(1)
	{
		/* new length: from SRC */
		new_required_length=src_deref.refp_hdr->runtime.cur_length;
		
		/* limit by SELF capacity: */
		if( new_required_length > self_deref.refp_hdr->cfg.static_capacity ) {
			new_required_length = self_deref.refp_hdr->cfg.static_capacity;
		}
	}
	/* limit by SELF capacity: done */
	/* --- */
	
	if(1) /*  optional but useful shortcut: DO NOTHING RETURN OK if PARAM TARGEET and PARAM SOURCE are same */
	{
		if( self_deref.self_bytes_ref.BtPtr == src_deref.self_bytes_ref.BtPtr ) {
			return 0; /* nothing to be done, no error- return OK */
		}
		
	}
	
	if(1)
	{
		/*self_deref.items_byteptr=alloctr_state_result.refp_itemArray_byteptr;*/ /* NO CHANGE */
		/*self_deref.refp_hdr->cfg.static_capacity=alloctr_state_result.capacity;*/ /* NO CHANGE */
		self_deref.refp_hdr->runtime.cur_length=new_required_length;
	}
	
	if(1) /* addition: export information about overflow */
	{
		if( NULL != opt_overflow ) {
			size_t diff=0;
			xc_tc_calc_overflow(
				  self_deref.refp_hdr->cfg.static_capacity
				, src_deref.refp_hdr->runtime.cur_length
				, &diff 
			);
			*opt_overflow=diff; /* !!! int -> uint [validated] */
		}
	}

	
	if(1) /* just copy entire memory block instead of copying object by object */
	{
		size_t self_items_memblock_bytesize_total=0;
		const size_t maxcnt=new_required_length;
		xc_p_pBytes_t self_items_memblock_ptr=self_deref.items_byteptr;
		xc_p_pBytesConst_t src_items_memblock_ptr=src_deref.items_byteptr;
		
		self_items_memblock_bytesize_total=self_deref.refp_hdr->cfg.obj_bytesize * self_deref.refp_hdr->cfg.static_capacity;
		
		xc_mem_bzero_bytes(self_items_memblock_ptr.BtPtr, self_items_memblock_bytesize_total);
		
		memcpy(self_items_memblock_ptr.BtPtr, src_items_memblock_ptr.BtPtr, self_deref.refp_hdr->cfg.obj_bytesize*maxcnt); /* varranteed non overlapping memory block, memcpy can be used instead of memmove */
	}

	return 0;
	
	xc_err_on_unmg();
	return 1;
}


static void* idx2itemptr(const xc_tcVectorT_LL_deref_t* self_deref, const size_t idx_public)
{
	xc_p_pBytes_t tmp_BtPtr={0};
	xc_byteptr_t refp_item=NULL;
	
	if(NULL==self_deref) {
		return NULL;
	}
	
	if( idx_public >= self_deref->refp_hdr->cfg.static_capacity) {
		return NULL;
	}
	
	tmp_BtPtr=self_deref->items_byteptr;
	
	refp_item=tmp_BtPtr.BtPtr+idx_public*self_deref->refp_hdr->cfg.obj_bytesize;
	
	return refp_item;
}
