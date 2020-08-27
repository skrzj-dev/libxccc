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
#include "xc/common/xc_si.h"
#include "xc/common/xc_tc_common.h"
/* --- */
#include "xc/am_seq/xc_am_seq.h"
#include "xc/tcpool_s/xc_tcpool_s.h"
/* --- */


#define xc_tcPoolS_LL_initval 3440

/*static void* LLII2itemptr(const xc_tcPoolS_LL_deref_t* self_deref, const xc_tc_LLII_idx_t idx_LLII);*/
static xc_p_pBytes_t LLII_to_itemptr(const xc_tcPoolS_LL_deref_t* self_deref, const xc_tc_LLII_idx_t idx_LLII);

/*
 * high- level validation of DEREFER; DOES NOT check if object is operational; 
 * to be used only internally, eg. before calling init(
 */
static int xc_tcPoolS_LL_validate_integrity(const xc_tcPoolS_LL_deref_t* refp_deref);

static int xc_tcPoolS_LL_validate_integrity_const(const xc_tcPoolS_LL_derefConst_t* refp_deref);

static int xc_tcPoolS_LL_validate_initialization_and_index_access_refp(const xc_tcPoolS_LL_deref_t* self_deref, const int idx);

static int xc_tcPoolS_LL_validate_initialization_and_index_access_insert_refp(const xc_tcPoolS_LL_deref_t* self_deref, const int idx);


static int xc_tc1_frees(xc_am_seq_ctx_t* result, xc_tcPoolS_LL_deref_t* arg);
static int xc_tc1_lookups(xc_am_seq_ctx_t* result, xc_tcPoolS_LL_deref_t* arg);
static int xc_tc1_items(xc_am_seq_ctx_t* result, xc_tcPoolS_LL_deref_t* arg);

static int xc_tc1_frees(xc_am_seq_ctx_t* result, xc_tcPoolS_LL_deref_t* arg)
{
	xc_mem_bzero_obj(xc_am_seq_ctx_t, result);
	
	result->cfg=xc_am_seq_cfg_retv(
		  sizeof(xc_tc_LLII_idx_t)
		, 1
	);

	result->state=xc_am_seq_state_retv(
		  xc_p_refp2pBytes_from_raw( (unsigned char**)&arg->refp_hdr->runtime.frees.arrS)
		, arg->refp_hdr->runtime.cur_capacity-arg->refp_hdr->runtime.cur_length
		, arg->refp_hdr->runtime.cur_capacity
	);
	
	return 0;
}

static int xc_tc1_lookups(xc_am_seq_ctx_t* result, xc_tcPoolS_LL_deref_t* arg)
{
	xc_mem_bzero_obj(xc_am_seq_ctx_t, result);
	
	result->cfg=xc_am_seq_cfg_retv(
		  sizeof(xc_tc_LLII_idx_t)
		, 1
	);
	
	result->state=xc_am_seq_state_retv(
		  xc_p_refp2pBytes_from_raw( (unsigned char**)&arg->refp_hdr->runtime.lookups.arrS)
		, arg->refp_hdr->runtime.cur_length
		, arg->refp_hdr->runtime.cur_capacity
	);
	
	return 0;
}

static int xc_tc1_items(xc_am_seq_ctx_t* result, xc_tcPoolS_LL_deref_t* arg)
{
	xc_mem_bzero_obj(xc_am_seq_ctx_t, result);
	
	result->cfg=xc_am_seq_cfg_retv(
		  arg->refp_hdr->cfg.obj_bytesize
		, 1
	);
	
	result->state=xc_am_seq_state_retv(
		  xc_p_refp2pBytes_from_raw(( unsigned char**)&arg->items_byteptr )
		, arg->refp_hdr->runtime.cur_length
		, arg->refp_hdr->runtime.cur_capacity
	);
	
	return 0;
}

/* *** *** *** */

/* *** INIT: *** */

static int xc_tcPoolS_LL_validate_integrity(const xc_tcPoolS_LL_deref_t* refp_deref)
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
	
#	if 0
	if(1) /* addition for POOL */
	{
		if( 0 != xc_tcVectorS_LL_validate_initialized(refp_deref->refp_hdr->runtime.vectDS_free) {
			xc_err_term_unmg();
		}
		if(NULL==refp_deref->refp_hdr->runtime.arrayDS_lookup.objArr) {
			xc_err_term_unmg();
		}
	}
#	endif
	
	return 0;
	
	xc_err_on_unmg();
	xc_err_return();
}


static int xc_tcPoolS_LL_validate_integrity_const(const xc_tcPoolS_LL_derefConst_t* refp_deref)
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
	
#	if 0
	if(1) /* addition for POOL */
	{
		if(NULL==refp_deref->refp_hdr->runtime.arrayDS_free.objArr) {
			xc_err_term_unmg();
		}
		if(NULL==refp_deref->refp_hdr->runtime.arrayDS_lookup.objArr) {
			xc_err_term_unmg();
		}
	}
#	endif
	
	return 0;
	
	xc_err_on_unmg();
	xc_err_return();
}

int xc_tcPoolS_LL_validate_initialized(const xc_tcPoolS_LL_deref_t* refp_deref)
{
	xc_err_decl();
	
	if( 0 != xc_tcPoolS_LL_validate_integrity(refp_deref) ) {
		xc_err_term_unmg();
	}
	
	if(1)
	{
		if( 0 == xc_initc_anyscopeNZ_isValid_u( (&refp_deref->refp_hdr->runtime.initIndicator), xc_tcPoolS_LL_initval) ) {
			xc_err_term_unmg();
		}
	}
	
	return 0;
	
	xc_err_on_unmg();
	xc_err_return();
}


int xc_tcPoolS_LL_validate_initialized_const(const xc_tcPoolS_LL_derefConst_t* refp_deref)
{
	xc_err_decl();
	
	if( 0 != xc_tcPoolS_LL_validate_integrity_const(refp_deref) ) {
		xc_err_term_unmg();
	}
	
	if(1)
	{
		if( 0 == xc_initc_anyscopeNZ_isValid_u( (&refp_deref->refp_hdr->runtime.initIndicator), xc_tcPoolS_LL_initval) ) {
			xc_err_term_unmg();
		}
	}
	
	return 0;
	
	xc_err_on_unmg();
	xc_err_return();
}


static int xc_tcPoolS_LL_validate_initialization_and_index_access_refp(const xc_tcPoolS_LL_deref_t* self_deref, const int idx)
{
	size_t conv_idx=0;
	xc_err_decl();
	
	if(NULL == self_deref) {
		xc_err_term_mg();
	}
	
	if( 0 != xc_tcPoolS_LL_validate_initialized(self_deref) ) {
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


static int xc_tcPoolS_LL_validate_initialization_and_index_access_insert_refp(const xc_tcPoolS_LL_deref_t* self_deref, const int idx)
{
	size_t conv_idx=0;
	xc_err_decl();
	
	if(NULL == self_deref) {
		xc_err_term_mg();
	}
	
	if( 0 != xc_tcPoolS_LL_validate_initialized(self_deref) ) {
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


int xc_tcPoolS_LL_validate_initialization_and_index_access(xc_tcPoolS_LL_deref_t self_deref, const int idx)
{
	return xc_tcPoolS_LL_validate_initialization_and_index_access_refp(&self_deref, idx);
}


int xc_tcPoolS_LL_publicIdx_to_lookupIdx_validated(xc_tcPoolS_LL_deref_t self_deref, const int idx)
{
	xc_tc_LLII_idx_t tmp_LLII=xc_tc_LLII_idx_itz_invalid();
	
	if( 0 == xc_tcPoolS_LL_validate_initialization_and_index_access_refp(&self_deref, idx) ) {
		
		tmp_LLII=self_deref.refp_hdr->runtime.lookups.arrS[idx];
	}
	else {
		xc_err_panic();
		/* panic */
		
	}
	
	return tmp_LLII.idx0;
}


xc_tcPoolS_LL_deref_t xc_tcPoolS_LL_derefer_get_retv(xc_tcPoolS_hdr_t* refp_hdr, xc_refp2byteptr_t refp_items_byteptr, xc_byteptr_t self_byteptr, const size_t self_size)
{
	xc_tcPoolS_LL_deref_t retv_empty={0};
	xc_tcPoolS_LL_deref_t retv={0};
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


xc_tcPoolS_LL_derefConst_t xc_tcPoolS_LL_derefer_get_retv_const(const xc_tcPoolS_hdr_t* refp_hdr, const unsigned char** refp_items_byteptr, const unsigned char* self_byteptr, const size_t self_size)
{
	xc_tcPoolS_LL_derefConst_t retv_empty={0};
	xc_tcPoolS_LL_derefConst_t retv={0};
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
		const xc_tcPoolS_LL_derefConst_t retv2=retv;
		return retv2;
	} while(0);
	
	xc_err_on_mg();
	return retv_empty;
	
}


int xc_tcPoolS_LL_init(
	  xc_tcPoolS_LL_deref_t self_deref
	, const size_t cfg_itemsize
	, const size_t initial_capacity
)
{
	return xc_tcPoolS_LL_init__dc01(
		  self_deref
		, cfg_itemsize
		, initial_capacity
	);
}

int xc_tcPoolS_LL_init__dc01(
	  xc_tcPoolS_LL_deref_t self_deref
	, const size_t cfg_itemsize
	, const size_t initial_capacity
)
{
	xc_tcPoolS_LL_deref_t* refp_deref=NULL;
	xc_err_decl();
	
	refp_deref=&self_deref;
	
	if( 0 != xc_tcPoolS_LL_validate_integrity(refp_deref) ) {
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
		
		if(1) /* indicate initialization by writing specific pattern */
		{
			if( 0 != xc_initc_anyscopeNZ_init_c( &refp_deref->refp_hdr->runtime.initIndicator, xc_tcPoolS_LL_initval) ) {
				xc_err_term_unmg();
			}
		}
		
		if(1)
		{
			xc_am_seq_cfg_t alloctr_cfg={0};
			xc_am_seq_state_t alloctr_state_init={0};
			xc_am_seq_state_t alloctr_state_result={0};

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
		
		if(1) /* POOL addition */
		{
			if(1)
			{
				if(1)
				{
					refp_deref->refp_hdr->runtime.lookups.arrS=xc_mem_allocz_obj_array(xc_tc_LLII_idx_t, refp_deref->refp_hdr->runtime.cur_capacity);
					
					if(NULL == refp_deref->refp_hdr->runtime.lookups.arrS ) {
						xc_err_term_unmg();
					}
				}
			}
			
			if(1)
			{
				xc_am_seq_ctx_t frees_ctx={0};
				int tmp_idx=0;
				
				if(1)
				{
					refp_deref->refp_hdr->runtime.frees.arrS=xc_mem_allocz_obj_array(xc_tc_LLII_idx_t, refp_deref->refp_hdr->runtime.cur_capacity);
					
					if(NULL == refp_deref->refp_hdr->runtime.frees.arrS ) {
						xc_err_term_unmg();
					}
				}
				
				xc_tc1_frees(&frees_ctx, refp_deref);
				
				for(tmp_idx=refp_deref->refp_hdr->runtime.cur_capacity-1; tmp_idx>=0; tmp_idx--)
				{
					xc_tc_LLII_idx_t tmpidx=xc_tc_LLII_idx_itz(tmp_idx);
					
					refp_deref->refp_hdr->runtime.frees.arrS[tmp_idx]=tmpidx;
					/*if( 0 != xc_amOp_seq_push_U(xc_tc_LLII_idx_t, &frees_ctx.state, frees_ctx.cfg.item_bytesize, &tmpidx) ) {
					*	xc_err_term_unmg();
					*}*/
				}
			}
		}
	}
	
	return 0;
	
	xc_err_on_unmg();
	xc_err_return();
}


void* xc_tcPoolS_LL_init_ret_self_refp(
	  xc_tcPoolS_LL_deref_t self_deref
	, const size_t cfg_itemsize
	, const size_t initial_capacity
)
{
	xc_tcPoolS_LL_deref_t* refp_deref=NULL;
	xc_err_decl();
	/* --- */
	
	refp_deref=&self_deref;
	
	if( 0 != xc_tcPoolS_LL_init(
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


void* xc_tcPoolS_LL_init_ret_self_refp__dc01(
	  xc_tcPoolS_LL_deref_t self_deref
	, const size_t cfg_itemsize
	, const size_t initial_capacity
)
{
	xc_tcPoolS_LL_deref_t* refp_deref=NULL;
	xc_err_decl();
	/* --- */
	
	refp_deref=&self_deref;
	
	if( 0 != xc_tcPoolS_LL_init__dc01(
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


int xc_tcPoolS_LL_deinit(xc_tcPoolS_LL_deref_t self_deref)
{
	xc_byteptr_t items_byteptr=NULL;
	xc_err_decl();
	
	if( 0 != xc_tcPoolS_LL_validate_initialized(&self_deref) ) {
		xc_err_term_unmg();
	}
	
	items_byteptr=xc_p_pBytes_from_ref2pBytes(self_deref.items_byteptr).BtPtr;
	
	if(NULL != items_byteptr ) {
		free(items_byteptr);
	}
	
	xc_mem_bzero_bytes( self_deref.self_bytes_ref.BtPtr, self_deref.self_bytes_size );
	
	return 0;
	
	xc_err_on_unmg();
	xc_err_return();
}


int xc_tcPoolS_LL_inspect_LLII_info_cp(xc_tcPoolS_LL_deref_t self_deref, const int idx, xc_tcPoolS_LL_inspect_LLII_info_t* refp_result)
{
	size_t tmp_idx=0;
	xc_p_pBytes_t tmp_byteptr_items={0};
	xc_err_decl();
	/* --- */
	
	if( 0 != xc_tcPoolS_LL_validate_initialized(&self_deref) ) {
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
	
	xc_mem_bzero_obj(xc_tcPoolS_LL_inspect_LLII_info_t, refp_result);
	
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


int xc_tcPoolS_LL_push(xc_tcPoolS_LL_deref_t self_deref, const void* obj_bytes_ref, const size_t obj_bytes_size)
{
	size_t new_required_length=0;
	xc_tc_LLII_idx_t cur_free_LLII=xc_tc_LLII_idx_itz_invalid();
	xc_tcPoolS_LL_deref_t* refp_deref=&self_deref;
	/* --- */
	xc_am_seq_ctx_t ctx_lookup={0};
	xc_am_seq_ctx_t ctx_free={0};
	xc_am_seq_ctx_t ctx_items={0};
	/* --- */
	xc_err_decl();
	/* --- */
	
	if( 0 != xc_tcPoolS_LL_validate_initialized(refp_deref) ) {
		xc_err_term_unmg();
	}
	if( NULL == obj_bytes_ref ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	new_required_length=self_deref.refp_hdr->runtime.cur_length+1;

	if(new_required_length>self_deref.refp_hdr->runtime.cur_capacity) {
		xc_err_term_unmg();
	}
	
	if(1)
	{
		xc_tc1_frees(&ctx_free, &self_deref);
		xc_tc1_lookups(&ctx_lookup, &self_deref);
		xc_tc1_items(&ctx_items, &self_deref);
	}
	
	if(1)
	{
		const xc_tc_LLII_idx_t tmp_invalid=xc_tc_LLII_idx_itz_invalid();
		xc_tc_LLII_idx_t tmp_LLII=xc_tc_LLII_idx_itz_invalid();
		
		
		/* get last free LLII: */
		tmp_LLII=self_deref.refp_hdr->runtime.frees.arrS[ ctx_free.state.length-1 ];
		/* get last free LLII: done */
		
		if( xc_tc_LLII_idx_isInvalid(&tmp_LLII) ) {
			xc_err_term_unmg();
		}
		
		/* push LLII to lookup: */
		self_deref.refp_hdr->runtime.lookups.arrS[ ctx_lookup.state.length ]=tmp_LLII;
		/* push LLII to lookup: done */
		
		/* pop last free LLII: */
		self_deref.refp_hdr->runtime.frees.arrS[ ctx_free.state.length-1 ]=tmp_invalid;
		/* pop last free LLII: done */
		
		cur_free_LLII=tmp_LLII;
	}
	
	/* --- */
	
	/* shallow copy to last index before reallocation */
	if(1)
	{
		xc_p_pBytes_t target={0};
		
		target=LLII_to_itemptr(&self_deref, cur_free_LLII);
		
		if( NULL==target.BtPtr ) {
			xc_err_term_unmg();
		}
		
		memcpy( target.BtPtr, obj_bytes_ref, self_deref.refp_hdr->cfg.obj_bytesize );
		
		self_deref.refp_hdr->runtime.cur_length=new_required_length;
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}



/* *** ADD: done *** */


/* *** REMOVE: *** */


int xc_tcPoolS_LL_pop(xc_tcPoolS_LL_deref_t self_deref)
{
	const xc_tc_LLII_idx_t invalid_LLII=xc_tc_LLII_idx_itz_invalid();
	size_t new_required_length=0;
	xc_tcPoolS_LL_deref_t* refp_deref=&self_deref;
	xc_tc_LLII_idx_t tmp_LLII=xc_tc_LLII_idx_itz_invalid();
	/* --- */
	xc_am_seq_ctx_t ctx_lookup={0};
	xc_am_seq_ctx_t ctx_free={0};
	xc_am_seq_ctx_t ctx_items={0};
	/* --- */
	xc_err_decl();
	/* --- */
	
	/* validate params: */
	
	if( 0 != xc_tcPoolS_LL_validate_initialized(refp_deref) ) {
		xc_err_term_unmg();
	}
	
	/* validate params: done */

	/* --- */
	
	/* validate state: */

	if( 0 == self_deref.refp_hdr->runtime.cur_length ) {
		xc_err_term_unmg();
	}
	if( 0 == self_deref.refp_hdr->runtime.cur_capacity ) { /* redundant */
		xc_err_term_unmg();
	}
	/* validate state: done */
	
	/*  : */
	new_required_length=self_deref.refp_hdr->runtime.cur_length-1;
	
	if( new_required_length >= self_deref.refp_hdr->runtime.cur_capacity ) {
		xc_err_term_unmg();
	}
	/*  : done */
	
	/* --- */
	
	if(1)
	{
		if( 0 != xc_tc1_lookups(&ctx_lookup, &self_deref) ) {
			xc_err_term_unmg();
		}
		if( 0 != xc_tc1_frees(&ctx_free, &self_deref) ) {
			xc_err_term_unmg();
		}
		if( 0 != xc_tc1_items(&ctx_items, &self_deref) ) {
			xc_err_term_unmg();
		}
	}
		
	if(1) 
	{
		const xc_tc_LLII_idx_t tmp_invalid=xc_tc_LLII_idx_itz_invalid();
		const int last_idx=self_deref.refp_hdr->runtime.cur_length-1;

		/* get LLII to last item by public idx: */
		tmp_LLII=self_deref.refp_hdr->runtime.lookups.arrS[last_idx];
		/* get LLII to last item by public idx: done */
		
		/* paranoic check, LLII must be valid: */
		if( xc_tc_LLII_idx_isInvalid(&tmp_LLII) ) {
			xc_err_term_unmg();
		}
		/* paranoic check, LLII must be valid: done */
		
		/* push LLII to free: */
		self_deref.refp_hdr->runtime.frees.arrS[ctx_free.state.length]=tmp_LLII;
		/* push LLII to free: done */

		/* pop last lookup LLII: */
		self_deref.refp_hdr->runtime.lookups.arrS[last_idx]=tmp_invalid;
		/* pop last lookup LLII: done */
	}
	
	/* erase item: */
	if(1)
	{
		if(1)
		{
			xc_p_pBytes_t byteptr_item=LLII_to_itemptr(refp_deref, tmp_LLII);
			xc_mem_bzero_bytes(byteptr_item.BtPtr, self_deref.refp_hdr->cfg.obj_bytesize);
		}
		
		self_deref.refp_hdr->runtime.cur_length=new_required_length;
	}
	/* erase item: done */
	
	/* shrink if required: */
	if(1)
	{
		/* fixed size, nothing to do */
	}
	/* shrink if required: done */
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}


int xc_tcPoolS_LL_rem_idx(xc_tcPoolS_LL_deref_t self_deref, const int public_idx)
{
	size_t new_required_length=0;
	const size_t target_array_idx=public_idx; /* ! uint <- int  */
	xc_tcPoolS_LL_deref_t* refp_deref=&self_deref;
	xc_tc_LLII_idx_t target_item_LLII=xc_tc_LLII_idx_itz_invalid();
	/* --- */
	xc_am_seq_ctx_t ctx_lookup={0};
	xc_am_seq_ctx_t ctx_free={0};
	xc_am_seq_ctx_t ctx_items={0};
	/* --- */
	xc_err_decl();
	/* --- */
	
	/* validate params: */
	
	if( 0 != xc_tcPoolS_LL_validate_initialization_and_index_access_refp(refp_deref, public_idx) ) {
		xc_err_term_unmg();
	}
	/* validate params: done */

	/* --- */
	
	/* validate state: */
	if( 0 == self_deref.refp_hdr->runtime.cur_length ) {
		xc_err_term_unmg();
	}
	if( 0 == self_deref.refp_hdr->runtime.cur_capacity ) { /* redundant */
		xc_err_term_unmg();
	}
	if( target_array_idx >= self_deref.refp_hdr->runtime.cur_length ) {
		xc_err_term_unmg();
	}
	/* validate state: done */
	
	if(1)
	{
		if( 0 != xc_tc1_lookups(&ctx_lookup, &self_deref) ) {
			xc_err_term_unmg();
		}
		if( 0 != xc_tc1_frees(&ctx_free, &self_deref) ) {
			xc_err_term_unmg();
		}
		if( 0 != xc_tc1_items(&ctx_items, &self_deref) ) {
			xc_err_term_unmg();
		}	
	}
	
	/* validate new length: */
	if(1)
	{
		new_required_length=self_deref.refp_hdr->runtime.cur_length-1;
		if(new_required_length>=self_deref.refp_hdr->runtime.cur_capacity) {
			xc_err_term_unmg();
		}
	}
	/* validate new length: done */
	
	if(1) 
	{
		const xc_tc_LLII_idx_t tmp_invalid=xc_tc_LLII_idx_itz_invalid();
		xc_tc_LLII_idx_t tmp_LLII=xc_tc_LLII_idx_itz_invalid();

		/* get LLII to last item by public idx: */
		tmp_LLII=self_deref.refp_hdr->runtime.lookups.arrS[public_idx];
		/* get LLII to last item by public idx: done */
		
		/* paranoic check, LLII must be valid: */
		if( xc_tc_LLII_idx_isInvalid(&tmp_LLII) ) {
			xc_err_term_unmg();
		}
		/* paranoic check, LLII must be valid: done */
		
		/* push LLII to free: */
		self_deref.refp_hdr->runtime.frees.arrS[ctx_free.state.length]=tmp_LLII;
		/* push LLII to free: done */

		/* remove last lookup LLII: */
		if( 0 != xc_amOp_seq_remove_at_idx(&ctx_lookup.state, ctx_lookup.cfg.item_bytesize, public_idx) ) {
			xc_err_term_unmg();
		}
		
		/* pop last lookup LLII: */
		self_deref.refp_hdr->runtime.lookups.arrS[ctx_lookup.state.length]=tmp_invalid;
		/* pop last lookup LLII: done */
		
		target_item_LLII=tmp_LLII;
	}
	
	/* erase item: */
	if(1)
	{
		if(1)
		{
			xc_p_pBytes_t byteptr_item=LLII_to_itemptr(refp_deref, target_item_LLII);
			xc_mem_bzero_bytes(byteptr_item.BtPtr, self_deref.refp_hdr->cfg.obj_bytesize);
		}
		
		self_deref.refp_hdr->runtime.cur_length=new_required_length;
	}
	/* erase item: done */
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}

/* *** REMOVE: done *** */


/* *** INSERT: *** */


int xc_tcPoolS_LL_insert(xc_tcPoolS_LL_deref_t self_deref, const int public_idx, const void* obj_bytes_ref, const size_t obj_bytes_size)
{
	size_t new_required_length=0;
	const xc_si_size_t_t target_array_idx = xc_si_size_t_from_int( xc_si_int_v(public_idx) );
	xc_tcPoolS_LL_deref_t* refp_deref=&self_deref;
	xc_tc_LLII_idx_t tmp_LLII_target=xc_tc_LLII_idx_itz_invalid();
	/* --- */
	xc_am_seq_ctx_t ctx_lookup={0};
	xc_am_seq_ctx_t ctx_free={0};
	xc_am_seq_ctx_t ctx_items={0};
	/* --- */
	xc_err_decl();
	/* --- */
	
	/* validate params: */
	
	if( 0 != xc_si_isError(target_array_idx) ) {
		xc_err_term_unmg();
	}
	
	if( 0 != xc_tcPoolS_LL_validate_initialization_and_index_access_insert_refp(refp_deref, public_idx) ) {
		xc_err_term_unmg();
	}
	if( NULL == obj_bytes_ref ) {
		xc_err_term_unmg();
	}
	/* validate params: done */
	
	/* --- 	*/
	
	/* : */
	new_required_length = self_deref.refp_hdr->runtime.cur_length+1;
	if( new_required_length > self_deref.refp_hdr->runtime.cur_capacity ) {
		xc_err_term_unmg();
	}
	/* : done */
	
	/* validate state: */
	if( 0 == self_deref.refp_hdr->runtime.cur_capacity ) { /* redundant */
		xc_err_term_unmg();
	}
	if( xc_si_size_t_val(target_array_idx) > self_deref.refp_hdr->runtime.cur_length ) { /* error if reference to outside of length */ /* insert at IDX==LENGTH iis valid (works as push) */
		xc_err_term_unmg();
	}
	/* validate state: done */
	
	
	if(1)
	{
		if( 0 != xc_tc1_lookups(&ctx_lookup, &self_deref) ) {
			xc_err_term_unmg();
		}
		if( 0 != xc_tc1_frees(&ctx_free, &self_deref) ) {
			xc_err_term_unmg();
		}
		if( 0 != xc_tc1_items(&ctx_items, &self_deref) ) {
			xc_err_term_unmg();
		}
	}
	
	if(1) 
	{
		const int free_idx=ctx_free.state.length-1;
		xc_tc_LLII_idx_t tmp_LLII=xc_tc_LLII_idx_itz_invalid();
		const xc_tc_LLII_idx_t tmp_LLII_invalid=xc_tc_LLII_idx_itz_invalid();

		/* get free LLII: */
		tmp_LLII=self_deref.refp_hdr->runtime.frees.arrS[free_idx];
		/* get free LLII: done */
		
		/* paranoic check, LLII must be valid: */
		if( xc_tc_LLII_idx_isInvalid(&tmp_LLII) ) {
			xc_err_term_unmg();
		}
		/* paranoic check, LLII must be valid: done */
		
		/* insert LLII to lookup: */
		if( 0 != xc_amOp_seq_insert_at_idx(&ctx_lookup.state, ctx_lookup.cfg.item_bytesize, public_idx, (xc_byteptr_t)&tmp_LLII ) ) {
			xc_err_term_unmg();
		}
		/* push LLII to free: done */

		/* remove free LLII: */
		self_deref.refp_hdr->runtime.frees.arrS[free_idx]=tmp_LLII_invalid;
		/* remove free LLII: done */
		
		tmp_LLII_target=tmp_LLII;
	}
	
	/* set item at index: */
	if(1)
	{
		xc_p_pBytes_t target={0};
		
		target=LLII_to_itemptr(refp_deref, tmp_LLII_target);
		memmove( target.BtPtr, obj_bytes_ref, self_deref.refp_hdr->cfg.obj_bytesize );
		
		self_deref.refp_hdr->runtime.cur_length=new_required_length;
	}
	/* set item at index: done */
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}


/* *** INSERT: DONE *** */


int xc_tcPoolS_LL_get_cp(xc_tcPoolS_LL_deref_t self_deref, const int idx, void* obj_bytes_ref, const size_t obj_bytes_size)
{
	xc_err_decl();
	/* --- */
	
	/* validate params: */
	if(0!=xc_tcPoolS_LL_validate_initialization_and_index_access_refp(&self_deref, idx) ) {
		xc_err_term_unmg();
	}
	if(NULL==obj_bytes_ref) {
		xc_err_term_unmg();
	}
	/* validate params: done */

	if(1)
	{
		xc_tc_LLII_idx_t tmp_LLII=xc_tc_LLII_idx_itz_invalid();
		xc_p_pBytes_t tmp_BtPtr={0};
		
		tmp_LLII=self_deref.refp_hdr->runtime.lookups.arrS[idx];
		
		tmp_BtPtr=LLII_to_itemptr(&self_deref, tmp_LLII);
		
		if(NULL == tmp_BtPtr.BtPtr) {
			xc_err_term_unmg();
		}
		
		memcpy(obj_bytes_ref, tmp_BtPtr.BtPtr, self_deref.refp_hdr->cfg.obj_bytesize);
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}


int xc_tcPoolS_LL_get_capacity(xc_tcPoolS_LL_deref_t self_deref)
{
	xc_err_decl();
	/* --- */
	
	/* validate params: */
	if( 0 != xc_tcPoolS_LL_validate_initialized(&self_deref) ) {
		xc_err_term_unmg();
	}
	/* validate params: done */
	
	return self_deref.refp_hdr->runtime.cur_capacity;
	
	xc_err_on_unmg();
	return 0;
}


int xc_tcPoolS_LL_get_length(xc_tcPoolS_LL_deref_t self_deref)
{
	xc_err_decl();
	/* --- */
	
	/* validate params: */
	if( 0 != xc_tcPoolS_LL_validate_initialized(&self_deref) ) {
		xc_err_term_unmg();
	}
	/* validate params: done */
	
	return self_deref.refp_hdr->runtime.cur_length;
	
	xc_err_on_unmg();
	return 0;
}


int xc_tcPoolS_LL_isEmpty(xc_tcPoolS_LL_deref_t self_deref)
{
	xc_err_decl();
	/* --- */
	
	/* validate params: */
	
	if( 0 != xc_tcPoolS_LL_validate_initialized(&self_deref) ) {
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


int xc_tcPoolS_LL_set_idx(xc_tcPoolS_LL_deref_t self_deref, const int idx, const void* obj_bytes_ref, const size_t obj_bytes_size)
{
	
	xc_tcPoolS_LL_deref_t* refp_deref=&self_deref;
	xc_err_decl();
	/* --- */
	
	if( NULL == obj_bytes_ref ) {
		xc_err_term_unmg();
	}
	if( 0 != xc_tcPoolS_LL_validate_initialization_and_index_access_refp(refp_deref, idx) ) {
		xc_err_term_unmg();
	}
	
	/* shallow copy to last index before reallocation */
	if(1)
	{
		xc_tc_LLII_idx_t tmp_LLII={0};
		xc_p_pBytes_t tmp_BtPtr={0};
		
		tmp_LLII=self_deref.refp_hdr->runtime.lookups.arrS[idx];
		
		tmp_BtPtr=LLII_to_itemptr(&self_deref, tmp_LLII);
		
		if(NULL == tmp_BtPtr.BtPtr) {
			xc_err_term_unmg();
		}
		
		memcpy( tmp_BtPtr.BtPtr, obj_bytes_ref, self_deref.refp_hdr->cfg.obj_bytesize );
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}


void* xc_tcPoolS_LL_alloc(const size_t self_obj_bytesize)
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


int xc_tcPoolS_LL_dealloc(xc_tcPoolS_LL_deref_t self_deref)
{
	size_t self_bytesize=0;
	void* ptr_obj=NULL;
	xc_tcPoolS_LL_deref_t* refp_deref=&self_deref;
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
	if( 0 == xc_tcPoolS_LL_deinit(self_deref) ) { 
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


int xc_tcPoolS_LL_assign_from(xc_tcPoolS_LL_deref_t self_deref, const xc_tcPoolS_LL_derefConst_t src_deref, int* opt_overflow)
{
	size_t new_required_length=0;
	xc_err_decl();
	/* --- */

	if( 0 != xc_tcPoolS_LL_validate_initialized(&self_deref) ) {
		xc_err_term_unmg();
	}
	if( 0 != xc_tcPoolS_LL_validate_initialized_const(&src_deref) ) {
		xc_err_term_unmg();
	}
	/* --- */
	
	/* validate capacity difference: illegal to copy non- sequential collection of BIGGER capacity to SMALLER capacity: */
	if(1) /* addition: export information about overflow */
	{
		size_t diff=0;
		xc_tc_calc_overflow(
			  self_deref.refp_hdr->runtime.cur_capacity
			, src_deref.refp_hdr->runtime.cur_capacity
			, &diff 
		);
		
		if( NULL != opt_overflow ) {
			*opt_overflow=diff; /* !!! int -> uint [validated] */
		}
		
		if(diff>0) {
			xc_err_term_unmg();
		}
	}
	/* validate capacity difference: illegal to copy non- sequential collection of BIGGER capacity to SMALLER capacity: done */
	
	/* new length: from SRC */
	new_required_length=src_deref.refp_hdr->runtime.cur_length;
	
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
		/*self_deref.refp_hdr->runtime.cur_capacity=alloctr_state_result.capacity;*/ /* NO CHANGE */
		self_deref.refp_hdr->runtime.cur_length=new_required_length;
	}
	
	if(1)
	{
		xc_mem_bzero_obj_array(xc_tc_LLII_idx_t,self_deref.refp_hdr->runtime.cur_capacity, self_deref.refp_hdr->runtime.frees.arrS);
		
		xc_mem_cp_obj_array(
			  xc_tc_LLII_idx_t
			, src_deref.refp_hdr->runtime.cur_capacity
			, self_deref.refp_hdr->runtime.frees.arrS
			, src_deref.refp_hdr->runtime.frees.arrS
		);
	}
	
	if(1)
	{
		xc_mem_bzero_obj_array(xc_tc_LLII_idx_t,self_deref.refp_hdr->runtime.cur_capacity, self_deref.refp_hdr->runtime.lookups.arrS);
		
		xc_mem_cp_obj_array(
			  xc_tc_LLII_idx_t
			, src_deref.refp_hdr->runtime.cur_capacity
			, self_deref.refp_hdr->runtime.lookups.arrS
			, src_deref.refp_hdr->runtime.lookups.arrS
		);
	}
	
	/* TODO!!! WARNING!!! SLOW!!! compare total block copy vs copy only lookups!!! */
	if(1) /* just copy entire memory block instead of copying object by object */
	{
		size_t self_items_memblock_bytesize_total=0;
		/* const size_t maxcnt=new_required_length; */ /* not used */
		xc_p_pBytes_t self_items_memblock_ptr=xc_p_pBytes_from_ref2pBytes(self_deref.items_byteptr);
		xc_p_pBytesConst_t src_items_memblock_ptr=xc_ptr_pBytesConst_from_ref2pBytesConst(src_deref.items_byteptr);
		
		self_items_memblock_bytesize_total=self_deref.refp_hdr->cfg.obj_bytesize * self_deref.refp_hdr->runtime.cur_capacity;
		
		xc_mem_bzero_bytes(self_items_memblock_ptr.BtPtr, self_items_memblock_bytesize_total);
		
		memcpy(self_items_memblock_ptr.BtPtr, src_items_memblock_ptr.BtPtr, self_items_memblock_bytesize_total); /* varranteed non overlapping memory block, memcpy can be used instead of memmove */
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}


static xc_p_pBytes_t LLII_to_itemptr(const xc_tcPoolS_LL_deref_t* self_deref, const xc_tc_LLII_idx_t idx_LLII)
{
	xc_p_pBytes_t tmp_BtPtr={0};
	xc_p_pBytes_t tmp_BtPtr_invalid={0};
	
	if(NULL==self_deref) {
		return tmp_BtPtr_invalid;
	}
	
	tmp_BtPtr=xc_p_pBytes_from_ref2pBytes(self_deref->items_byteptr);
	tmp_BtPtr.BtPtr=tmp_BtPtr.BtPtr+idx_LLII.idx0*self_deref->refp_hdr->cfg.obj_bytesize;
	
	return tmp_BtPtr;
}


int xc_tcPoolS_DIAG_getFreesLength(const xc_tcPoolS_hdr_t* refp_hdr, int* result_length)
{
	*result_length=refp_hdr->runtime.cur_capacity-refp_hdr->runtime.cur_length;
	return 0;
}


int xc_tcPoolS_DIAG_getLookupsLength(const xc_tcPoolS_hdr_t* refp_hdr, int* result_length)
{
	*result_length=refp_hdr->runtime.cur_length;
	return 0;
}
