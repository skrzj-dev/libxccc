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
static xc_tc_LLII_idx_t publicidxLookup2LLII(const xc_tcPoolS_LL_deref_t* self_deref, const int idx);
static xc_p_pBytes_t publicidxLookup2itemptr(const xc_tcPoolS_LL_deref_t* self_deref, const int idx);
static xc_p_pBytes_t LLII_to_itemptr(const xc_tcPoolS_LL_deref_t* self_deref, const xc_tc_LLII_idx_t idx_LLII);

/*
 * high- level validation of DEREFER; DOES NOT check if object is operational; 
 * to be used only internally, eg. before calling init(
 */
static int xc_tcPoolS_LL_validate_integrity(const xc_tcPoolS_LL_deref_t* refp_deref);

static int xc_tcPoolS_LL_validate_integrity_const(const xc_tcPoolS_LL_derefConst_t* refp_deref);

static int xc_tcPoolS_LL_validate_initialization_and_index_access_refp(const xc_tcPoolS_LL_deref_t* self_deref, const int idx);

static int xc_tcPoolS_LL_validate_initialization_and_index_access_insert_refp(const xc_tcPoolS_LL_deref_t* self_deref, const int idx);


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
		
		tmp_LLII=xc_tcVectorS_u_item_direct(&self_deref.refp_hdr->runtime.vectDS_lookup, idx);
	}
	else {
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
				if( 0 != xc_tcVectorS_u_init(&refp_deref->refp_hdr->runtime.vectDS_lookup, refp_deref->refp_hdr->runtime.cur_capacity) ) {
					xc_err_term_unmg();
				}
			}
			
			if(1)
			{
				int tmp_idx=0;
				
				if( 0 != xc_tcVectorS_u_init(&refp_deref->refp_hdr->runtime.vectDS_free, refp_deref->refp_hdr->runtime.cur_capacity) ) {
					xc_err_term_unmg();
				}
				
				for(tmp_idx=refp_deref->refp_hdr->runtime.cur_capacity-1; tmp_idx>=0; tmp_idx--)
				{
					xc_tc_LLII_idx_t tmpidx=xc_tc_LLII_idx_itz(tmp_idx);
					
					if(0!=xc_tcVectorS_u_push(
							  &refp_deref->refp_hdr->runtime.vectDS_free
							, &tmpidx
						)
					) {
						xc_err_term_unmg();
					}
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
		int free_last_idx= xc_tcVectorS_u_get_length(&self_deref.refp_hdr->runtime.vectDS_free)-1;
		xc_tc_LLII_idx_t tmp_LLII=xc_tc_LLII_idx_itz_invalid();
		
		/* get last free LLII: */
		if( 0 != xc_tcVectorS_u_item_cp( 
				  &self_deref.refp_hdr->runtime.vectDS_free
				, free_last_idx
				, &tmp_LLII
			)
		) {
			xc_err_term_unmg();
		}
		/* get last free LLII: done */
		
		if( xc_tc_LLII_idx_isInvalid(&tmp_LLII) ) {
			xc_err_term_unmg();
		}
		
		/* push LLII to lookup: */
		if( 0 != xc_tcVectorS_u_push( &self_deref.refp_hdr->runtime.vectDS_lookup, &tmp_LLII) ) {
			xc_err_term_unmg();
		}
		/* push LLII to lookup: done */
		
		/* pop last free LLII: */
		if(0!=xc_tcVectorS_u_pop( &self_deref.refp_hdr->runtime.vectDS_free) ) {
			xc_err_term_unmg();
		}
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
	}
	
	if(1)
	{
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
	xc_tc_LLII_idx_t cur_target_lookup=xc_tc_LLII_idx_itz_invalid();
	size_t new_required_length=0;
	xc_tcPoolS_LL_deref_t* refp_deref=&self_deref;
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
	
	if( new_required_length>self_deref.refp_hdr->runtime.cur_capacity ) {
		xc_err_term_unmg();
	}
	/*  : done */
	
	/* --- */
	
	if(1)
	{
		int last_idx=self_deref.refp_hdr->runtime.cur_length-1;
		xc_tc_LLII_idx_t tmp_LLII=xc_tc_LLII_idx_itz_invalid();
		
		/* get last lookup LLII: */
		if( 0 != xc_tcVectorS_u_item_cp( 
				  &self_deref.refp_hdr->runtime.vectDS_lookup
				, last_idx
				, &tmp_LLII
			)
		) {
			xc_err_term_unmg();
		}
		/* get last lookup LLII: done */
		
		if( xc_tc_LLII_idx_isInvalid(&tmp_LLII) ) {
			xc_err_term_unmg();
		}
		
		/* push LLII to free: */
		if( 0 != xc_tcVectorS_u_push( &self_deref.refp_hdr->runtime.vectDS_free, &tmp_LLII) ) {
			xc_err_term_unmg();
		}
		/* push LLII to free: done */
		
		/* pop last lookup LLII: */
		if(0!=xc_tcVectorS_u_pop( &self_deref.refp_hdr->runtime.vectDS_lookup) ) {
			xc_err_term_unmg();
		}
		/* pop last lookup LLII: done */
		
		cur_target_lookup=tmp_LLII;
	}
	
	/* erase last: */
	if(1)
	{
		xc_p_pBytes_t target_itemptr={0};
		
		target_itemptr=LLII_to_itemptr(&self_deref, cur_target_lookup);
		
		if(NULL==target_itemptr.BtPtr) {
			xc_err_term_unmg();
		}
		
		xc_mem_bzero_bytes(target_itemptr.BtPtr, self_deref.refp_hdr->cfg.obj_bytesize);
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


int xc_tcPoolS_LL_rem_idx(xc_tcPoolS_LL_deref_t self_deref, const int public_idx)
{
	size_t new_required_length=0;
	const size_t target_array_idx=public_idx; /* ! uint <- int  */
	xc_tcPoolS_LL_deref_t* refp_deref=&self_deref;
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
	
	/* : */
	new_required_length=self_deref.refp_hdr->runtime.cur_length-1;
	if(new_required_length>self_deref.refp_hdr->runtime.cur_capacity) {
		xc_err_term_unmg();
	}
	/* : done */
	
	
	/* shrink if required: */
	if(1)
	{
		xc_am_seq_cfg_t alloctr_cfg={0};
		xc_am_seq_state_t alloctr_state_init={0};
		xc_am_seq_state_t alloctr_state_init_updated={0};
		
		alloctr_cfg=xc_am_seq_cfg_retv(
			  self_deref.refp_hdr->cfg.obj_bytesize
			, 1
		);
		
		alloctr_state_init=xc_am_seq_state_retv(
			  self_deref.items_byteptr
			, self_deref.refp_hdr->runtime.cur_length
			, self_deref.refp_hdr->runtime.cur_capacity
		);
		
		alloctr_state_init_updated=alloctr_state_init;
		
		alloctr_state_init_updated.length--;
		
		refp_deref->items_byteptr=alloctr_state_init_updated.refp_itemArray_byteptr;
		refp_deref->refp_hdr->runtime.cur_capacity=alloctr_state_init_updated.capacity;
		refp_deref->refp_hdr->runtime.cur_length=alloctr_state_init_updated.length;
	}
	/* shrink if required: done */
	
	if(1)
	{
		xc_tc_LLII_idx_t tmp_LLII=xc_tc_LLII_idx_itz_invalid();
		xc_p_pBytes_t byteptr_item={0};
		
		/* get lookup [LLII]: */
		if( 0 != xc_tcVectorS_u_item_cp(
				  &refp_deref->refp_hdr->runtime.vectDS_lookup
				, public_idx
				, &tmp_LLII
			)
		) {
			xc_err_term_unmg();
		}
		/* get free [LLII]: done */
		
		if( 0 != xc_tc_LLII_idx_isInvalid(&tmp_LLII) ) {
			xc_err_term_unmg();
		}
		
		/* push LLII to free: */
		if( 0 != xc_tcVectorS_u_push(
				  &refp_deref->refp_hdr->runtime.vectDS_free
				, &tmp_LLII
			)
		) {
			xc_err_term_unmg();
		}
		/* push LLII to free: done */

		/* remove lookup [LLII] at [public idx]: */
		if( 0 != xc_tcVectorS_u_remove_idx(
				  &refp_deref->refp_hdr->runtime.vectDS_lookup
				, public_idx
			)
		) {
			xc_err_term_unmg();
		}
		/* remove lookup [LLII] at [public idx]: done */
		
		/* clean: */
		if(1)
		{
			byteptr_item=LLII_to_itemptr(refp_deref, tmp_LLII);
			xc_mem_bzero_bytes(byteptr_item.BtPtr, self_deref.refp_hdr->cfg.obj_bytesize);
		}
		/* clean: done */
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}

/* *** REMOVE: done *** */


/* *** INSERT: *** */


int xc_tcPoolS_LL_insert(xc_tcPoolS_LL_deref_t self_deref, const int public_idx, const void* obj_bytes_ref, const size_t obj_bytes_size)
{
	size_t new_required_length=0;
	int conv_err=0;
	const xc_si_size_t_t target_array_idx = xc_si_size_t_from_int( xc_si_int_v(public_idx) );
	xc_tcPoolS_LL_deref_t* refp_deref=&self_deref;
	xc_tc_LLII_idx_t tmp_LLII_target=xc_tc_LLII_idx_itz_invalid();
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
		int free_last_idx= xc_tcVectorS_u_get_length(&self_deref.refp_hdr->runtime.vectDS_free)-1;
		xc_tc_LLII_idx_t tmp_LLII=xc_tc_LLII_idx_itz_invalid();
		
		/* get free [LLII]: */
		if( 0 != xc_tcVectorS_u_item_cp(
				  &refp_deref->refp_hdr->runtime.vectDS_free
				, free_last_idx
				, &tmp_LLII
			)
		) {
			xc_err_term_unmg();
		}
		/* get free [LLII]: done */
		
		if( 0 != xc_tc_LLII_idx_isInvalid(&tmp_LLII) ) {
			xc_err_term_unmg();
		}
		
		/* set lookup: [LLII] at [public idx]: */
		if( 0 != xc_tcVectorS_u_insert(
				  &refp_deref->refp_hdr->runtime.vectDS_lookup
				, public_idx
				, &tmp_LLII
			)
		) {
			xc_err_term_unmg();
		}
		/* set lookup: [LLII] at [public idx]: done */

		/* pop free [LLII]: */
		if( 0 != xc_tcVectorS_u_pop(
				  &refp_deref->refp_hdr->runtime.vectDS_free
			)
		) {
			xc_err_term_unmg();
		}
		/* pop free [LLII]: done */
		
		tmp_LLII_target=tmp_LLII;
	}
	
	/* grow if required: */
	if(1)
	{
		
		xc_am_seq_cfg_t alloctr_cfg={0};
		xc_am_seq_state_t alloctr_state_init={0};
		xc_am_seq_state_t alloctr_state_init_updated={0};
		
		alloctr_cfg=xc_am_seq_cfg_retv(
			  self_deref.refp_hdr->cfg.obj_bytesize
			, 1
		);
		
		alloctr_state_init=xc_am_seq_state_retv(
			  self_deref.items_byteptr
			, self_deref.refp_hdr->runtime.cur_length
			, self_deref.refp_hdr->runtime.cur_capacity
		);
		
		alloctr_state_init_updated=alloctr_state_init;

		alloctr_state_init_updated.length++;
		
		refp_deref->items_byteptr=alloctr_state_init_updated.refp_itemArray_byteptr;
		refp_deref->refp_hdr->runtime.cur_capacity=alloctr_state_init_updated.capacity;
		refp_deref->refp_hdr->runtime.cur_length=alloctr_state_init_updated.length;
	}
	/* grow if required: done */
	
	/* set item at index: */
	if(1)
	{
		xc_p_pBytes_t target={0};
		
		target=LLII_to_itemptr(refp_deref, tmp_LLII_target);
		
		memcpy( target.BtPtr, obj_bytes_ref, self_deref.refp_hdr->cfg.obj_bytesize );
	}
	/* set item at index: done */
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}


/* *** INSERT: DONE *** */


int xc_tcPoolS_LL_get_cp(xc_tcPoolS_LL_deref_t self_deref, const int idx, void* obj_bytes_ref, const size_t obj_bytes_size)
{
	xc_tc_LLII_idx_t tmp_LLII=xc_tc_LLII_idx_itz_invalid();
	xc_p_pBytes_t tmp_BtPtr={0};
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
	
	tmp_BtPtr=publicidxLookup2itemptr(&self_deref, idx);
	
	if( NULL == tmp_BtPtr.BtPtr ) {
		xc_err_term_unmg();
	}
	
	memcpy(obj_bytes_ref, tmp_BtPtr.BtPtr, self_deref.refp_hdr->cfg.obj_bytesize);
	
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
		
		tmp_BtPtr=publicidxLookup2itemptr(&self_deref, idx);
		
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
	if(1)
	{
		/* new length: from SRC */
		new_required_length=src_deref.refp_hdr->runtime.cur_length;
		
		/* limit by SELF capacity: */
		if( new_required_length > self_deref.refp_hdr->runtime.cur_capacity ) {
			new_required_length = self_deref.refp_hdr->runtime.cur_capacity;
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
		/*self_deref.refp_hdr->runtime.cur_capacity=alloctr_state_result.capacity;*/ /* NO CHANGE */
		self_deref.refp_hdr->runtime.cur_length=new_required_length;
	}
	
	if(1) /* addition: export information about overflow */
	{
		if( NULL != opt_overflow ) {
			size_t diff=0;
			xc_tc_calc_overflow(
				  self_deref.refp_hdr->runtime.cur_capacity
				, src_deref.refp_hdr->runtime.cur_length
				, &diff 
			);
			*opt_overflow=diff; /* !!! int -> uint [validated] */
		}
	}
	
	if(1)
	{
		int is_overflow1=0;
		if( 0 != xc_tcVectorS_u_assign_from(
				  &self_deref.refp_hdr->runtime.vectDS_free
				, &src_deref.refp_hdr->runtime.vectDS_free
				, &is_overflow1
			)  
		) {
			xc_err_term_unmg();
		}
	}
	if(1)
	{
		int is_overflow2=0;
		if( 0 != xc_tcVectorS_u_assign_from(
				  &self_deref.refp_hdr->runtime.vectDS_lookup
				, &src_deref.refp_hdr->runtime.vectDS_lookup
				, &is_overflow2
			)  
		) {
			xc_err_term_unmg();
		}
	}
	
	if(1) /* just copy entire memory block instead of copying object by object */
	{
		size_t self_items_memblock_bytesize_total=0;
		const size_t maxcnt=new_required_length;
		xc_p_pBytes_t self_items_memblock_ptr=xc_p_pBytes_from_ref2pBytes(self_deref.items_byteptr);
		xc_p_pBytesConst_t src_items_memblock_ptr=xc_ptr_pBytesConst_from_ref2pBytesConst(src_deref.items_byteptr);
		
		self_items_memblock_bytesize_total=self_deref.refp_hdr->cfg.obj_bytesize * self_deref.refp_hdr->runtime.cur_capacity;
		
		xc_mem_bzero_bytes(self_items_memblock_ptr.BtPtr, self_items_memblock_bytesize_total);
		
		memcpy(self_items_memblock_ptr.BtPtr, src_items_memblock_ptr.BtPtr, self_deref.refp_hdr->cfg.obj_bytesize*maxcnt); /* varranteed non overlapping memory block, memcpy can be used instead of memmove */
	}
	
	return 0;
	
	xc_err_on_unmg();
	return 1;
}


static xc_tc_LLII_idx_t publicidxLookup2LLII(const xc_tcPoolS_LL_deref_t* self_deref, const int idx)
{
	xc_tc_LLII_idx_t retv=xc_tc_LLII_idx_itz_invalid();
	xc_tc_LLII_idx_t retv_invalid=xc_tc_LLII_idx_itz_invalid();
	
	if(NULL==self_deref) {
		return retv_invalid;
	}
	
	retv=xc_tcVectorS_u_item_direct(&self_deref->refp_hdr->runtime.vectDS_lookup, idx);
	
	return retv;
}


static xc_p_pBytes_t publicidxLookup2itemptr(const xc_tcPoolS_LL_deref_t* self_deref, const int idx)
{
	xc_p_pBytes_t tmp_BtPtr={0};
	xc_p_pBytes_t tmp_BtPtr_invalid={0};
	xc_tc_LLII_idx_t tmpidx={0};
	
	if(NULL==self_deref) {
		return tmp_BtPtr_invalid;
	}
	
	tmpidx=xc_tcVectorS_u_item_direct(&self_deref->refp_hdr->runtime.vectDS_lookup, idx);
	tmp_BtPtr=xc_p_pBytes_from_ref2pBytes(self_deref->items_byteptr);
	tmp_BtPtr.BtPtr=tmp_BtPtr.BtPtr+tmpidx.idx0*self_deref->refp_hdr->cfg.obj_bytesize;
	
	return tmp_BtPtr;
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
