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

#ifndef _XC_TCPOOL_T_API_CC_H_
#define _XC_TCPOOL_T_API_CC_H_

#ifdef __cplusplus
extern "C" {
#endif

/* --- */
#include <limits.h>
#include <stddef.h>
/* --- */
#include "xc/common/xc_mem.h"
#include "xc/common/xc_cptr.h"
#include "xc/common/xc_tc_common.h"
/* --- */


typedef struct xc_tcPoolT_cfg_t
{
	size_t obj_bytesize;
	size_t static_capacity;
	
} xc_tcPoolT_cfg_t;


typedef struct xc_tcPoolT_runtime_t
{
	xc_initc_anyscopeNZ_t initIndicator;
	
	size_t cur_length;

} xc_tcPoolT_runtime_t;


typedef struct xc_tcPoolT_hdr_t
{
	xc_tcPoolT_cfg_t cfg;
	xc_tcPoolT_runtime_t runtime;
	
} xc_tcPoolT_hdr_t;


typedef struct xc_tcPoolT_LL_deref_t
{
	xc_p_BytesArray_t items_byteptr;
	xc_tcPoolT_hdr_t* refp_hdr;
	xc_tc_LLII_idx_t* refp_arrayTS_array1D_lookups;
	xc_tc_LLII_idx_t* refp_arrayTS_array1D_frees;
	xc_p_pBytes_t self_bytes_ref;
	size_t self_bytes_size;
} xc_tcPoolT_LL_deref_t;

typedef struct xc_tcPoolT_LL_derefConst_t
{
	const unsigned char* items_byteptr;
	const xc_tcPoolT_hdr_t* refp_hdr;
	const xc_tc_LLII_idx_t* refp_arrayTS_array1D_lookups;
	const xc_tc_LLII_idx_t* refp_arrayTS_array1D_frees;
	xc_p_pBytesConst_t self_bytes_ref;
	size_t self_bytes_size;
} xc_tcPoolT_LL_derefConst_t;


#define xc_tcPoolT_declt(_ARG_TYPENAME_, _ARG_CAPACITY_) struct {\
	xc_tcPoolT_hdr_t prv__hdrTS;/* must have unique postfix so different variants of this type (S / D / DS) are varranted to be incompatible */\
	xc_tc_LLII_idx_t prv_arrayTS_array1D_lookups[(_ARG_CAPACITY_)];\
	xc_tc_LLII_idx_t prv_arrayTS_array1D_frees[(_ARG_CAPACITY_)];\
	_ARG_TYPENAME_ prv_arrayTS_array1D_items[(_ARG_CAPACITY_)];\
	_ARG_TYPENAME_* prv__dummyptr;\
}\
    


typedef struct xc_tcPoolT_LL_inspect_LLII_info_t
{
	int valid;
	void* anyptr_item;
	xc_byteptr_t byteptr_item;
	int item_idx_LLII;
	int item_idx_public;
} xc_tcPoolT_LL_inspect_LLII_info_t;


/* -- --- --- --- */
/* -- --- --- --- */


xc_tcPoolT_LL_deref_t xc_tcPoolT_LL_derefer_get_retv(
	  xc_tcPoolT_hdr_t* refp_hdr
	, xc_byteptr_t refp_items_byteptr
	, xc_tc_LLII_idx_t* refp_lookups_array
	, xc_tc_LLII_idx_t* refp_frees_array
	, xc_byteptr_t self_byteptr
	, const size_t self_size
);


xc_tcPoolT_LL_derefConst_t xc_tcPoolT_LL_derefer_get_retv_const(
	  const xc_tcPoolT_hdr_t* refp_hdr
	, const unsigned char* refp_items_byteptr
	, const xc_tc_LLII_idx_t* refp_lookups_array
	, const xc_tc_LLII_idx_t* refp_frees_array
	, const unsigned char* self_byteptr
	, const size_t self_size
);


int xc_tcPoolT_LL_init(
	  xc_tcPoolT_LL_deref_t self_deref
	, const size_t cfg_itemsize
	, const size_t initial_capacity
);


int xc_tcPoolT_LL_init__dc01(
	  xc_tcPoolT_LL_deref_t self_deref
	, const size_t cfg_itemsize
	, const size_t initial_capacity
);


void* xc_tcPoolT_LL_init_ret_self_refp(
	  xc_tcPoolT_LL_deref_t self_deref
	, const size_t cfg_itemsize
	, const size_t initial_capacity
);


void* xc_tcPoolT_LL_init_ret_self_refp__dc01(
	  xc_tcPoolT_LL_deref_t self_deref
	, const size_t cfg_itemsize
	, const size_t initial_capacity
);

int xc_tcPoolT_DIAG_getFreesLength(const xc_tcPoolT_hdr_t* refp_hdr, int* result_length);
int xc_tcPoolT_DIAG_getLookupsLength(const xc_tcPoolT_hdr_t* refp_hdr, int* result_length);

/*
 * high- level validation of DEREFER; checks if object is operational; 
 * to be used in all API calls in order to determine if any operatiiion can be done at object at all
 */
int xc_tcPoolT_LL_validate_initialized(const xc_tcPoolT_LL_deref_t* refp_deref);
int xc_tcPoolT_LL_validate_initialized_const(const xc_tcPoolT_LL_derefConst_t* refp_deref);


int xc_tcPoolT_LL_validate_initialization_and_index_access(xc_tcPoolT_LL_deref_t self_deref, const int idx);
int xc_tcPoolT_LL_publicIdx_to_lookupIdx_validated(xc_tcPoolT_LL_deref_t self_deref, const int idx);


int xc_tcPoolT_LL_deinit(xc_tcPoolT_LL_deref_t self_deref);

int xc_tcPoolT_LL_isEmpty(xc_tcPoolT_LL_deref_t self_deref);

int xc_tcPoolT_LL_get_capacity(xc_tcPoolT_LL_deref_t self_deref);

int xc_tcPoolT_LL_get_length(xc_tcPoolT_LL_deref_t self_deref);

int xc_tcPoolT_LL_push(xc_tcPoolT_LL_deref_t self_deref, const void* obj_bytes_ref, const size_t obj_bytes_size);

int xc_tcPoolT_LL_pop(xc_tcPoolT_LL_deref_t self_deref);

int xc_tcPoolT_LL_inspect_LLII_info_cp(xc_tcPoolT_LL_deref_t self_deref, const int idx, xc_tcPoolT_LL_inspect_LLII_info_t* refp_result);

int xc_tcPoolT_LL_rem_idx(xc_tcPoolT_LL_deref_t self_deref, const int public_idx);

int xc_tcPoolT_LL_insert(xc_tcPoolT_LL_deref_t self_deref, const int idx, const void* obj_bytes_ref, const size_t obj_bytes_size);

int xc_tcPoolT_LL_get_cp(xc_tcPoolT_LL_deref_t self_deref, const int idx, void* obj_bytes_ref, const size_t obj_bytes_size);

int xc_tcPoolT_LL_set_idx(xc_tcPoolT_LL_deref_t self_deref, const int idx, const void* obj_bytes_ref, const size_t obj_bytes_size);

void* xc_tcPoolT_LL_alloc(const size_t self_obj_bytesize);

int xc_tcPoolT_LL_dealloc(xc_tcPoolT_LL_deref_t self_deref);

int xc_tcPoolT_LL_assign_from(xc_tcPoolT_LL_deref_t self_deref, const xc_tcPoolT_LL_derefConst_t src_deref, int* opt_overflow);

#ifdef __cplusplus
}
#endif



#endif
