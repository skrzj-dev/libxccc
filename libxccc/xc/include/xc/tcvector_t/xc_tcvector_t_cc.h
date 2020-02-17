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

#ifndef _XC_TCVECTOR_T_API_CC_H_
#define _XC_TCVECTOR_T_API_CC_H_

#ifdef __cplusplus
extern "C" {
#endif

/* --- */
#include <limits.h>
#include <stddef.h>
/* --- */
#include "xc/common/xc_mem.h"
#include "xc/common/xc_cptr.h"
/* --- */


typedef struct xc_tcVectorT_cfg_t
{
	size_t obj_bytesize;
	size_t static_capacity;
	
} xc_tcVectorT_cfg_t;


typedef struct xc_tcVectorT_runtime_t
{
	xc_initc_anyscopeNZ_t initIndicator;
	size_t cur_length;
	
} xc_tcVectorT_runtime_t;


typedef struct xc_tcVectorT_hdr_t
{
	xc_tcVectorT_cfg_t cfg;
	xc_tcVectorT_runtime_t runtime;
	
} xc_tcVectorT_hdr_t;


typedef struct xc_tcVectorT_LL_deref_t
{
	xc_p_pBytes_t items_byteptr;
	xc_tcVectorT_hdr_t* refp_hdr;
	xc_p_pBytes_t self_bytes_ref;
	size_t self_bytes_size;
} xc_tcVectorT_LL_deref_t;


typedef struct xc_tcVectorT_LL_derefConst_t
{
	xc_p_pBytesConst_t items_byteptr;
	const xc_tcVectorT_hdr_t* refp_hdr;
	xc_p_pBytesConst_t self_bytes_ref;
	size_t self_bytes_size;
} xc_tcVectorT_LL_derefConst_t;


#define xc_tcVectorT_declt(_ARG_TYPENAME_, _ARG_CAPACITY_) struct {\
	xc_tcVectorT_hdr_t prv__hdrST;/* must have unique postfix so different variants of this type (S / D / DS) are varranted to be incompatible */\
	_ARG_TYPENAME_ items_array[ (_ARG_CAPACITY_) ];\
	_ARG_TYPENAME_* prv__dummyptr;\
}\
    


typedef struct xc_tcVectorT_LL_inspect_LLII_info_t
{
	int valid;
	void* anyptr_item;
	xc_byteptr_t byteptr_item;
	int item_idx_LLII;
	int item_idx_public;
} xc_tcVectorT_LL_inspect_LLII_info_t;


/* -- --- --- --- */
/* -- --- --- --- */


xc_tcVectorT_LL_deref_t xc_tcVectorT_LL_derefer_get_retv(
	  xc_tcVectorT_hdr_t* refp_hdr
	, xc_byteptr_t refp_items_byteptr
	, xc_byteptr_t self_byteptr
	, const size_t self_size
);


int xc_tcVectorT_LL_init(
	  xc_tcVectorT_LL_deref_t self_deref
	, const size_t cfg_itemsize
	, const size_t items_bytesize
);


int xc_tcVectorT_LL_init__dc01(
	  xc_tcVectorT_LL_deref_t self_deref
	, const size_t cfg_itemsize
	, const size_t items_bytesize
);


void* xc_tcVectorT_LL_init_ret_self_refp(
	  xc_tcVectorT_LL_deref_t self_deref
	, const size_t cfg_itemsize
	, const size_t items_bytesize
);


void* xc_tcVectorT_LL_init_ret_self_refp__dc01(
	  xc_tcVectorT_LL_deref_t self_deref
	, const size_t cfg_itemsize
	, const size_t items_bytesize
);


/*
 * high- level validation of DEREFER; checks if object is operational; 
 * to be used in all API calls in order to determine if any operatiiion can be done at object at all
 */
int xc_tcVectorT_LL_validate_initialized(const xc_tcVectorT_LL_deref_t* refp_deref);
int xc_tcVectorT_LL_validate_initialized_const(const xc_tcVectorT_LL_derefConst_t* refp_deref);

int xc_tcVectorT_LL_deinit(xc_tcVectorT_LL_deref_t self_deref);

int xc_tcVectorT_LL_isEmpty(xc_tcVectorT_LL_deref_t self_deref);

int xc_tcVectorT_LL_get_capacity(xc_tcVectorT_LL_deref_t self_deref);

int xc_tcVectorT_LL_get_length(xc_tcVectorT_LL_deref_t self_deref);

int xc_tcVectorT_LL_push(xc_tcVectorT_LL_deref_t self_deref, const void* obj_bytes_ref, const size_t obj_bytes_size);

int xc_tcVectorT_LL_pop(xc_tcVectorT_LL_deref_t self_deref);

int xc_tcVectorT_LL_inspect_LLII_info_cp(xc_tcVectorT_LL_deref_t self_deref, const int idx, xc_tcVectorT_LL_inspect_LLII_info_t* refp_result);

int xc_tcVectorT_LL_rem_idx(xc_tcVectorT_LL_deref_t self_deref, const int public_idx);

int xc_tcVectorT_LL_insert(xc_tcVectorT_LL_deref_t self_deref, const int idx, const void* obj_bytes_ref, const size_t obj_bytes_size);

int xc_tcVectorT_LL_get_cp(xc_tcVectorT_LL_deref_t self_deref, const int idx, void* obj_bytes_ref, const size_t obj_bytes_size);

int xc_tcVectorT_LL_validate_initialization_and_index_access(xc_tcVectorT_LL_deref_t self_deref, const int idx);

int xc_tcVectorT_LL_set_idx(xc_tcVectorT_LL_deref_t self_deref, const int idx, const void* obj_bytes_ref, const size_t obj_bytes_size);

void* xc_tcVectorT_LL_alloc(const size_t self_obj_bytesize);

int xc_tcVectorT_LL_dealloc(xc_tcVectorT_LL_deref_t self_deref);

xc_tcVectorT_LL_deref_t xc_tcVectorT_LL_derefer_get_retv(xc_tcVectorT_hdr_t* refp_hdr, xc_byteptr_t refp_items_byteptr, xc_byteptr_t self_byteptr, const size_t self_size);
xc_tcVectorT_LL_derefConst_t xc_tcVectorT_LL_derefer_get_retv_const(const xc_tcVectorT_hdr_t* refp_hdr, const unsigned char* refp_items_byteptr, const unsigned char* self_byteptr, const size_t self_size);

int xc_tcVectorT_LL_assign_from(xc_tcVectorT_LL_deref_t self_deref, const xc_tcVectorT_LL_derefConst_t src_deref, int* opt_overflow);

#ifdef __cplusplus
}
#endif



#endif

