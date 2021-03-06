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
#include "xc/common/xc_si.h"
/* --- */
#include "xc/am_seq/xc_am_seq.h"
#include "xc/tcvector_s/xc_tcvector_s.h"
/* --- */


#define xc_tcVectorS_LL_initval 2340


/*
 * high- level validation of DEREFER; DOES NOT check if object is operational; 
 * to be used only internally, eg. before calling init(
 */
static int xc_tcVectorS_LL_validate_integrity(const xc_tcVectorS_LL_deref_t* refp_deref);

static int xc_tcVectorS_LL_validate_integrity_const(const xc_tcVectorS_LL_derefConst_t* refp_deref);

static int xc_tcVectorS_LL_validate_initialization_and_index_access_refp(const xc_tcVectorS_LL_deref_t* self_deref, const int idx);

static int xc_tcVectorS_LL_validate_initialization_and_index_access_insert_refp(const xc_tcVectorS_LL_deref_t* self_deref, const int idx);


/* *** *** *** */


/* *** INIT: *** */


static int xc_tcVectorS_LL_validate_integrity(const xc_tcVectorS_LL_deref_t* refp_deref)
{
	xc_err_decl();
	
	if(NULL==refp_deref) {
		xc_err_term_unmg();
	}
	
	if(NULL==refp_deref->items_byteptr.Refp2BtPtr) {
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


static int xc_tcVectorS_LL_validate_integrity_const(const xc_tcVectorS_LL_derefConst_t* refp_deref)
{
	xc_err_decl();
	
	if(NULL==refp_deref) {
		xc_err_term_unmg();
	}
	
	if(NULL==refp_deref->items_byteptr.Refp2BtPtr) {
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


int xc_tcVectorS_LL_validate_initialized(const xc_tcVectorS_LL_deref_t* refp_deref)
{
	xc_err_decl();
	
	if( 0 != xc_tcVectorS_LL_validate_integrity(refp_deref) ) {
		xc_err_term_unmg();
	}
	
	if(1)
	{
		if( 0 == xc_initc_anyscopeNZ_isValid_u( (&refp_deref->refp_hdr->runtime.initIndicator), xc_tcVectorS_LL_initval) ) {
			xc_err_term_unmg();
		}
	}
	
	return 0;
	
	xc_err_on_unmg();
	xc_err_return();
}


int xc_tcVectorS_LL_validate_initialized_const(const xc_tcVectorS_LL_derefConst_t* refp_deref)
{
	xc_err_decl();
	
	if( 0 != xc_tcVectorS_LL_validate_integrity_const(refp_deref) ) {
		xc_err_term_unmg();
	}
	
	if(1)
	{
		if( 0 == xc_initc_anyscopeNZ_isValid_u( (&refp_deref->refp_hdr->runtime.initIndicator), xc_tcVectorS_LL_initval) ) {
			xc_err_term_unmg();
		}
	}
	
	return 0;
	
	xc_err_on_unmg();
	xc_err_return();
}

static int xc_tcVectorS_LL_validate_initialization_and_index_access_refp(const xc_tcVectorS_LL_deref_t* self_deref, const int idx)
{
	size_t conv_idx=0;
	xc_err_decl();
	
	if(NULL == self_deref) {
		xc_err_term_mg();
	}
	
	if( 0 != xc_tcVectorS_LL_validate_initialized(self_deref) ) {
		xc_err_term_mg(); /* manageable error */
	}
	
	if( 0 == xc_tc_isValid_idx_staticRange(idx) ) {
		xc_err_term_mg(); /* manageable error */
	}
	
	conv_idx=idx;  /* !!! int -> uint [VALIDATED] */
	
	if( conv_idx >= self_deref->refp_hdr->runtime.cur_length ) {
		xc_err_term_mg(); /* manageable error */
	}

	if( conv_idx >= self_deref->refp_hdr->runtime.cur_capacity) { /* redundant */
		xc_err_term_mg(); /* manageable error */
	}
	
	return 0;
	
	xc_err_on_mg();
	return 1;
}


static int xc_tcVectorS_LL_validate_initialization_and_index_access_insert_refp(const xc_tcVectorS_LL_deref_t* self_deref, const int idx)
{
	size_t conv_idx=0;
	xc_err_decl();
	
	if(NULL == self_deref) {
		xc_err_term_mg();
	}
	
	if( 0 != xc_tcVectorS_LL_validate_initialized(self_deref) ) {
		xc_err_term_mg(); /* manageable error */
	}
	
	if( 0 == xc_tc_isValid_idx_staticRange(idx) ) {
		xc_err_term_mg(); /* manageable error */
	}
	
	conv_idx=idx;  /* !!! int -> uint [VALIDATED] */
	
	if( conv_idx > self_deref->refp_hdr->runtime.cur_length ) {
		xc_err_term_mg(); /* manageable error */
	}

	if( conv_idx >= self_deref->refp_hdr->runtime.cur_capacity) { /* redundant */
		xc_err_term_mg(); /* manageable error */
	}
	
	return 0;
	
	xc_err_on_mg();
	return 1;
}


int xc_tcVectorS_LL_validate_initialization_and_index_access(xc_tcVectorS_LL_deref_t self_deref, const int idx)
{
	return xc_tcVectorS_LL_validate_initialization_and_index_access_refp(&self_deref, idx);
}


xc_tcVectorS_LL_deref_t xc_tcVectorS_LL_derefer_get_retv(xc_tcVectorS_hdr_t* refp_hdr, unsigned char** refp_items_byteptr, unsigned char* self_byteptr, const size_t self_size)
{
	xc_tcVectorS_LL_deref_t retv_empty={0};
	xc_tcVectorS_LL_deref_t retv={0};
	xc_err_decl();
	/* --- */
	
	if(NULL==refp_hdr) {
		xc_err_term_mg();
	}
	if(NULL==refp_items_byteptr) {
		xc_err_term_mg();
	}
	/* --- */
	
	retv.items_byteptr.Refp2BtPtr=refp_items_byteptr;
	retv.refp_hdr=refp_hdr;
	retv.self_bytes_ref.BtPtr=self_byteptr;
	retv.self_bytes_size=self_size;
	
	return retv;
	
	xc_err_on_mg();
	return retv_empty;
	
}


xc_tcVectorS_LL_derefConst_t xc_tcVectorS_LL_derefer_get_retv_const(const xc_tcVectorS_hdr_t* refp_hdr, const unsigned char** refp_items_byteptr, const unsigned char* self_byteptr, const size_t self_size)
{
	xc_tcVectorS_LL_derefConst_t retv_empty={0};
	xc_tcVectorS_LL_derefConst_t retv={0};
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
	retv.items_byteptr.Refp2BtPtr=refp_items_byteptr;
	retv.refp_hdr=refp_hdr;
	retv.self_bytes_ref.BtPtr=self_byteptr;
	retv.self_bytes_size=self_size;
	
	do
	{
		const xc_tcVectorS_LL_derefConst_t retv2=retv;
		return retv2;
	} while(0);
	
	xc_err_on_mg();
	return retv_empty;
	
}


int xc_tcVectorS_LL_init(
	  xc_tcVectorS_LL_deref_t self_deref
	, const size_t cfg_itemsize
	, const size_t initial_capacity
)
{
	return xc_tcVectorS_LL_init__dc01(
		  self_deref
		, cfg_itemsize
		, initial_capacity
	);
}


int xc_tcVectorS_LL_init__dc01(
	  xc_tcVectorS_LL_deref_t self_deref
	, const size_t cfg_itemsize
	, const size_t initial_capacity
)
{
	xc_tcVectorS_LL_deref_t* refp_deref=NULL;
	xc_err_decl();
	
	refp_deref=&self_deref;
	
	if( 0 != xc_tcVectorS_LL_validate_integrity(refp_deref) ) {
		xc_err_term_unmg();
	}
	
	if(1)
	{
		if( 0 == xc_tc_isValid_capacity_staticRange_uint(cfg_itemsize) ) {
			xc_err_term_unmg();
		}
		
		if( 0 == xc_tc_isValid_capacity_staticRange_uint(initial_capacity) ) {
			xc_err_term_unmg();
		}
		
		if( 0 != xc_tc_validate_arrayStaticSize(initial_capacity, cfg_itemsize) ) {
			xc_err_term_unmg();
		}
	}
	
	xc_mem_bzero_bytes(refp_deref->self_bytes_ref.BtPtr, refp_deref->self_bytes_size);
	
	refp_deref->refp_hdr->cfg.obj_bytesize=cfg_itemsize;
	
	/* allocation : separeted scope, this may change between version */
	if(1)
	{
		xc_am_seq_cfg_t alloctr_cfg={0};
		xc_am_seq_state_t alloctr_state_init={0};
		xc_am_seq_state_t alloctr_state_result={0};
		
		if(1) /* indicate initialization by writing specific pattern */
		{
			if( 0 != xc_initc_anyscopeNZ_init_c( &refp_deref->refp_hdr->runtime.initIndicator, xc_tcVectorS_LL_initval) ) {
				xc_err_term_unmg();
			}
		}
		
		alloctr_cfg=xc_am_seq_cfg_retv(
			  cfg_itemsize
			, 1
		);
		
		alloctr_state_init=xc_am_seq_state_retv(refp_deref->items_byteptr, 0, 0);
		
		/* */
		if( 0 != xc_am_seq_tStatic_realloc(
			  &alloctr_cfg
			, &alloctr_state_init
			, &alloctr_state_result
			, initial_capacity
		) ) {
			xc_err_term_unmg();
		}
		
		refp_deref->refp_hdr->runtime.cur_capacity=alloctr_state_result.capacity;
		refp_deref->refp_hdr->runtime.cur_length=alloctr_state_result.length;
	}
	
	return 0;
	
	xc_err_on_unmg();
	xc_err_return();
}


void* xc_tcVectorS_LL_init_ret_self_refp(
	  xc_tcVectorS_LL_deref_t self_deref
	, const size_t cfg_itemsize
	, const size_t initial_capacity
)
{
	xc_tcVectorS_LL_deref_t* refp_deref=NULL;
	xc_err_decl();
	/* --- */
	
	refp_deref=&self_deref;
	
	if( 0 != xc_tcVectorS_LL_init(
		  self_deref
		, cfg_itemsize
		, initial_capacity
		)
	) {
		xc_err_term_unmg();
	}
	
	return refp_deref->self_bytes_ref.BtPtr;
	
	xc_err_on_unmg();
	return NULL;
}


void* xc_tcVectorS_LL_init_ret_self_refp__dc01(
	  xc_tcVectorS_LL_deref_t self_deref
	, const size_t cfg_itemsize
	, const size_t initial_capacity
)
{
	xc_tcVectorS_LL_deref_t* refp_deref=NULL;
	xc_err_decl();
	/* --- */
	
	refp_deref=&self_deref;
	
	if( 0 != xc_tcVectorS_LL_init__dc01(
		  self_deref
		, cfg_itemsize
		, initial_capacity
		)
	) {
		xc_err_term_unmg();
	}
	
	return refp_deref->self_bytes_ref.BtPtr;
	
	xc_err_on_unmg();
	return NULL;
}


int xc_tcVectorS_LL_deinit(xc_tcVectorS_LL_deref_t self_deref)
{
	xc_byteptr_t items_byteptr=NULL;
	xc_err_decl();
	
	if( 0 != xc_tcVectorS_LL_validate_initialized(&self_deref) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if(1)
	{
		xc_am_seq_cfg_t _cfg={0};
		xc_am_seq_state_t _state={0};
		
		_cfg=xc_am_seq_cfg_retv(
			  self_deref.refp_hdr->cfg.obj_bytesize
			, 1
		);
		
		_state=xc_am_seq_state_retv(
			  self_deref.items_byteptr
			, self_deref.refp_hdr->runtime.cur_length
			, self_deref.refp_hdr->runtime.cur_capacity
		);
		
		if( 0 != xc_amOp_seq_clear(&_cfg, &_state) ) {
			xc_err_term_unmg();
		}
	}
	
	if(NULL != items_byteptr ) {
		free(items_byteptr);
	}
	
	xc_mem_bzero_bytes( self_deref.self_bytes_ref.BtPtr, self_deref.self_bytes_size );
	
	return 0;
	
	xc_err_on_unmg();
	xc_err_return();
}


int xc_tcVectorS_LL_inspect_LLII_info_cp(xc_tcVectorS_LL_deref_t self_deref, const int idx, xc_tcVectorS_LL_inspect_LLII_info_t* refp_result)
{
	size_t tmp_idx=0;
	xc_p_pBytes_t tmp_byteptr_items={0};
	xc_err_decl();
	/* --- */
	
	if( 0 != xc_tcVectorS_LL_validate_initialized(&self_deref) ) {
		xc_err_term_unmg();
	}
	if(NULL == refp_result) {
		xc_err_term_unmg();
	}
	/* --- */
	tmp_byteptr_items=xc_p_pBytes_from_ref2pBytes(self_deref.items_byteptr);
	
	tmp_idx=idx; /* ssigned -> unsigned */
	
	/* 
	 *  check: index out of CAPACITY range
	 *  any allocated object within CAPACITY can be inspected, but index out of range is unmanaged error
	 */
	if( tmp_idx >= self_deref.refp_hdr->runtime.cur_capacity ) {
		xc_err_term_unmg();
	}
	
	xc_mem_bzero_obj(xc_tcVectorS_LL_inspect_LLII_info_t, refp_result);
	
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


int xc_tcVectorS_LL_push(xc_tcVectorS_LL_deref_t self_deref, const void* obj_bytes_ref, const size_t obj_bytes_size)
{
	xc_am_seq_state_t state_init={0};
	xc_tcVectorS_LL_deref_t* refp_deref=&self_deref;
	xc_err_decl();
	/* --- */
	
	if( 0 != xc_tcVectorS_LL_validate_initialized(refp_deref) ) {
		xc_err_term_unmg();
	}
	if( NULL == obj_bytes_ref ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	state_init=xc_am_seq_state_retv(
		  self_deref.items_byteptr
		, self_deref.refp_hdr->runtime.cur_length
		, self_deref.refp_hdr->runtime.cur_capacity
	);

	if( 0 != xc_amOp_seq_push(&state_init, self_deref.refp_hdr->cfg.obj_bytesize, (xc_byteptr_t)obj_bytes_ref) ) {
		xc_err_term_unmg();
	}
	
	self_deref.refp_hdr->runtime.cur_length=state_init.length;
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}


/* *** ADD: done *** */


/* *** REMOVE: *** */


int xc_tcVectorS_LL_pop(xc_tcVectorS_LL_deref_t self_deref)
{
	size_t new_required_length=0;
	xc_tcVectorS_LL_deref_t* refp_deref=&self_deref;
	xc_err_decl();
	/* --- */
	
	/* validate params: */
	
	if( 0 != xc_tcVectorS_LL_validate_initialized(refp_deref) ) {
		xc_err_term_unmg();
	}
	
	/* validate params: done */

	/* --- */
	
	/* perform: */
	if(1)
	{
		xc_am_seq_state_t state={0};
		
		state=xc_am_seq_state_retv(
			  self_deref.items_byteptr
			, self_deref.refp_hdr->runtime.cur_length
			, self_deref.refp_hdr->runtime.cur_capacity
		);
		
		if( 0 != xc_amOp_seq_pop(&state, self_deref.refp_hdr->cfg.obj_bytesize) ) {
			xc_err_term_unmg();
		}
		
		refp_deref->refp_hdr->runtime.cur_length=state.length;
	}
	/* perform: done */
	
	/* realloc (shrink if required): */
	if(1)
	{
		/* nothing to do */
	}
	/* realloc (shrink if required): done */

	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}


int xc_tcVectorS_LL_rem_idx(xc_tcVectorS_LL_deref_t self_deref, const int public_idx)
{
	size_t new_required_length=0;
	const size_t target_array_idx=public_idx; /* ! uint <- int  */
	xc_tcVectorS_LL_deref_t* refp_deref=&self_deref;
	xc_err_decl();
	/* --- */
	
	/* validate params: */
	
	if( 0 != xc_tcVectorS_LL_validate_initialization_and_index_access_refp(refp_deref, public_idx) ) {
		xc_err_term_unmg();
	}
	/* validate params: done */

	/* --- */
	
	/* perform: */
	if(1)
	{
		xc_am_seq_cfg_t alloctr_cfg={0};
		xc_am_seq_state_t alloctr_state_init={0};
		
		alloctr_cfg=xc_am_seq_cfg_retv(
			  self_deref.refp_hdr->cfg.obj_bytesize
			, 1
		);
		
		alloctr_state_init=xc_am_seq_state_retv(
			  self_deref.items_byteptr
			, self_deref.refp_hdr->runtime.cur_length
			, self_deref.refp_hdr->runtime.cur_capacity
		);
		
		if( 0 != xc_amOp_seq_remove_at_idx(
				  &alloctr_state_init
				, self_deref.refp_hdr->cfg.obj_bytesize
				, target_array_idx
			) 
		) {
			xc_err_term_unmg();
		}
		
		refp_deref->refp_hdr->runtime.cur_length=alloctr_state_init.length;
	}
	/* perform: done */
	
	/* shrink if required: */
	if(1)
	{
		/* nothing to do */
	}
	/* shrink if required: done */
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}

/* *** REMOVE: done *** */


/* *** INSERT: *** */

int xc_tcVectorS_LL_insert(xc_tcVectorS_LL_deref_t self_deref, const int public_idx, const void* obj_bytes_ref, const size_t obj_bytes_size)
{
	size_t new_required_length=0;
	const size_t target_array_idx=public_idx; /* ! uint <- int  */
	xc_tcVectorS_LL_deref_t* refp_deref=&self_deref;
	xc_err_decl();
	/* --- */
	
	/* validate params: */
	
	if( 0 != xc_tcVectorS_LL_validate_initialization_and_index_access_insert_refp(refp_deref, public_idx) ) {
		xc_err_term_unmg();
	}
	if( NULL == obj_bytes_ref ) {
		xc_err_term_unmg();
	}
	/* validate params: done */

	/* --- 	*/
	
	/* : */
	xc_si_UNCHECKED(new_required_length = self_deref.refp_hdr->runtime.cur_length+1);
	if( new_required_length > self_deref.refp_hdr->runtime.cur_capacity ) {
		xc_err_term_unmg();
	}
	/* : done */
	
	/* validate state: */
	if( 0 == self_deref.refp_hdr->runtime.cur_capacity ) { /* redundant */
		xc_err_term_unmg();
	}
	if( target_array_idx > self_deref.refp_hdr->runtime.cur_length ) { /* error if reference to outside of length */ /* insert at IDX==LENGTH iis valid (works as push) */
		xc_err_term_unmg();
	}
	/* validate state: done */
	
	/* grow if required: */
	if(1)
	{
		/* fixed capacity, do nothing */
	}
	/* insert: done */
	
	/* insert: */
	if(1)
	{
		xc_am_seq_state_t alloctr_state_init={0};
		
		alloctr_state_init=xc_am_seq_state_retv(
			  self_deref.items_byteptr
			, self_deref.refp_hdr->runtime.cur_length
			, self_deref.refp_hdr->runtime.cur_capacity
		);
		
		if( 0 != xc_amOp_seq_insert_at_idx(
				  &alloctr_state_init
				, self_deref.refp_hdr->cfg.obj_bytesize
				, target_array_idx
				, (const xc_byteptr_t)obj_bytes_ref
			) 
		) {
			xc_err_term_unmg();
		}
		
		/* apply changes: */
		refp_deref->refp_hdr->runtime.cur_length=alloctr_state_init.length;
		/* apply changes: done */

	}
	/* insert: done */

	return 0;
	
	xc_err_on_unmg();
	return 1;
}


/* *** INSERT: DONE *** */


int xc_tcVectorS_LL_get_cp(xc_tcVectorS_LL_deref_t self_deref, const int idx, void* obj_bytes_ref, const size_t obj_bytes_size)
{
	xc_byteptr_t refp_item_by_idx=NULL;
	xc_err_decl();
	/* --- */
	
	/* validate params: */
	if(0!=xc_tcVectorS_LL_validate_initialization_and_index_access_refp(&self_deref, idx) ) {
		xc_err_term_unmg();
	}
	if(NULL==obj_bytes_ref) {
		xc_err_term_unmg();
	}
	/* validate params: done */
	
	if(1)
	{
		xc_am_seq_cfg_t cfg={0};
		xc_am_seq_state_t state={0};
		
		cfg=xc_am_seq_cfg_retv(
			  self_deref.refp_hdr->cfg.obj_bytesize
			, 1
		);

		state=xc_am_seq_state_retv(
			  self_deref.items_byteptr
			, self_deref.refp_hdr->runtime.cur_length
			, self_deref.refp_hdr->runtime.cur_capacity
		);

		if( NULL == ( refp_item_by_idx=xc_amOp_seq_item_at_idx(&cfg, &state, idx) ) ) {
			xc_err_term_unmg();
		}
	}
	
	memcpy(obj_bytes_ref, refp_item_by_idx, self_deref.refp_hdr->cfg.obj_bytesize);
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}


int xc_tcVectorS_LL_get_capacity(xc_tcVectorS_LL_deref_t self_deref)
{
	xc_err_decl();
	/* --- */
	
	/* validate params: */
	if( 0 != xc_tcVectorS_LL_validate_initialized(&self_deref) ) {
		xc_err_term_unmg();
	}
	/* validate params: done */
	
	return self_deref.refp_hdr->runtime.cur_capacity;
	
	xc_err_on_unmg();
	return 0;
}


int xc_tcVectorS_LL_get_length(xc_tcVectorS_LL_deref_t self_deref)
{
	xc_err_decl();
	/* --- */
	
	/* validate params: */
	if( 0 != xc_tcVectorS_LL_validate_initialized(&self_deref) ) {
		xc_err_term_unmg();
	}
	/* validate params: done */
	
	return self_deref.refp_hdr->runtime.cur_length;
	
	xc_err_on_unmg();
	return 0;
}


int xc_tcVectorS_LL_isEmpty(xc_tcVectorS_LL_deref_t self_deref)
{
	xc_err_decl();
	/* --- */
	
	/* validate params: */
	
	if( 0 != xc_tcVectorS_LL_validate_initialized(&self_deref) ) {
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


int xc_tcVectorS_LL_set_idx(xc_tcVectorS_LL_deref_t self_deref, const int idx, const void* obj_bytes_ref, const size_t obj_bytes_size)
{
	xc_tcVectorS_LL_deref_t* refp_deref=&self_deref;
	xc_err_decl();
	/* --- */
	
	if( NULL == obj_bytes_ref ) {
		xc_err_term_unmg();
	}
	if( 0 != xc_tcVectorS_LL_validate_initialization_and_index_access_refp(refp_deref, idx) ) {
		xc_err_term_unmg();
	}
	
	/* shallow copy to last index before reallocation */
	if(1)
	{
		xc_am_seq_state_t state={0};
		
		state=xc_am_seq_state_retv(
			  self_deref.items_byteptr
			, self_deref.refp_hdr->runtime.cur_length
			, self_deref.refp_hdr->runtime.cur_capacity
		);

		if( 0 != xc_amMdl_seq_I.set_at_idx(&state, self_deref.refp_hdr->cfg.obj_bytesize, idx, (const xc_byteptr_t)obj_bytes_ref) ) {
			xc_err_term_unmg();
		}
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}


void* xc_tcVectorS_LL_alloc(const size_t self_obj_bytesize)
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


int xc_tcVectorS_LL_dealloc(xc_tcVectorS_LL_deref_t self_deref)
{
	size_t self_bytesize=0;
	void* ptr_obj=NULL;
	xc_tcVectorS_LL_deref_t* refp_deref=&self_deref;
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
	if( 0 == xc_tcVectorS_LL_deinit(self_deref) ) { 
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


int xc_tcVectorS_LL_assign_from(xc_tcVectorS_LL_deref_t self_deref, const xc_tcVectorS_LL_derefConst_t src_deref, int* opt_overflow)
{
	int tmp_overflow=0;
	size_t new_required_length=0;
	xc_err_decl();
	/* --- */

	if( 0 != xc_tcVectorS_LL_validate_initialized(&self_deref) ) {
		xc_err_term_unmg();
	}
	if( 0 != xc_tcVectorS_LL_validate_initialized_const(&src_deref) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	if(1)
	{
		xc_am_seq_cfg_t src_cfg={0};
		xc_am_seq_state_c_t src_state={0};
		xc_am_seq_cfg_t self_cfg={0};
		xc_am_seq_state_t self_state={0};
		
		self_cfg=xc_am_seq_cfg_retv(
			  self_deref.refp_hdr->cfg.obj_bytesize
			, 1
		);
		self_state=xc_am_seq_state_retv(
			  self_deref.items_byteptr
			, self_deref.refp_hdr->runtime.cur_length
			, self_deref.refp_hdr->runtime.cur_capacity
		);
		
		src_cfg=xc_am_seq_cfg_retv(
			  src_deref.refp_hdr->cfg.obj_bytesize
			, 1
		);
		src_state=xc_am_seq_state_const_retv(
			  src_deref.items_byteptr
			, src_deref.refp_hdr->runtime.cur_length
			, src_deref.refp_hdr->runtime.cur_capacity
		);
		
		if(0!=xc_amOp_seq_assignFrom(
				  &self_cfg
				, &self_state
				, &src_cfg
				, &src_state
				, &tmp_overflow
			)
		) {
			xc_err_term_unmg();
		}
		
		self_deref.refp_hdr->runtime.cur_length=self_state.length;
		self_deref.refp_hdr->runtime.cur_capacity=self_state.capacity;
		
	}

	return 0;
	
	xc_err_on_unmg();
	return 1;
}
