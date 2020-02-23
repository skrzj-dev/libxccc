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

#ifndef _XC_AMMO_SEQ_H_
#define _XC_AMMO_SEQ_H_

#ifdef __cplusplus
extern "C" {
#endif

/*
 * --- --- ---
 * 
 * Namespace prefixes:
 * 
 * xc_ammo_seq_*                  : allocator of byte sequence 
 * xc_ammo_seq_t<something>       : ( - || - ) API for specific type of memory re / allocation (eg in constant size blocks, in power of 2 size, static)
 * xc_ammo_seq_tStatic_*          : ( - || - ) on preallocated (fixed capacity) memory ; also dynamic static allocation (to fixed capacity)
 * xc_ammo_seq_tChunkC_*          : ( - || - ) on memory that is allocated in Chunks of Constant size (precise memory usage, slow)
 * xc_ammo_seq_tChunkP2_*         : ( - || - ) on memory that is allocated in Chunks of Power of 2 (default, unnprecise memory usage, fast)
 * 
 * --- --- ---
 * 
 * API of type:
 * xc_ammo_seq_<action>*
 * 
 * Can by applied to any allocator
 * 
 * --- --- ---
 * 
 * API of type:
 * 
 * xc_ammo_seq_t<something>_<action>*
 * 
 * Can be applied only to type t<something>
 * 
 * --- --- ---
 * 
 */

/*
 * File content: 
 *
 *    allocator API for data stored as continuous byte sequence
 *
 *    allocator API provides abstraction over memory mangement for object arrays in memory
 *
 *    allocator API operates on:
 *          user data viewed as byte blocks (static byte size of object is known)
 *          numbers describing object storage (length, capacity)
 *          data required for lookup (1:1 index lookup for sequential data; lookup arrays for pool data; etc)
 *
 *    allocator API provides following functionalities over bytes:
 *        - dynamic resize of object array as bytes (grow / shrink)
 *        - item shift left, item shift right inside object array as bytes
 *        - get pointer to 1 object bytes from array by its index
 * 
 */

/* --- */
#include "xc/common/xc_mem.h"
#include "xc/common/xc_cptr.h"
/* --- */

typedef struct xc_ammo_seq_state_t
{
	xc_p_refp2pBytes_t refp_itemArray_byteptr;
	size_t length;
	size_t capacity;
} xc_ammo_seq_state_t;


xc_ammo_seq_state_t xc_ammo_seq_state_retv(
	  xc_p_refp2pBytes_t refp_itemArray_byteptr
	, const size_t length
	, const size_t capacity
);


typedef struct xc_ammo_seq_cfg_t
{
	size_t cnt_items_in_chunk;
	size_t item_bytesize;
} xc_ammo_seq_cfg_t;


xc_ammo_seq_cfg_t xc_ammo_seq_cfg_retv(const size_t item_bytesize, const size_t cnt_items_in_chunk);


int xc_ammo_seq_tChunkC_realloc(
	  const xc_ammo_seq_cfg_t* refp_cfg
	, const xc_ammo_seq_state_t* refp_initial_state
	, xc_ammo_seq_state_t* refp_result_state
	, const size_t requested_new_length
);


int xc_ammo_seq_tChunkC_length2capacity(
	  const size_t length
	, const size_t capacity
	, const size_t chunk_itemcnt
	, size_t* result_capacity
);

/* --- */

int xc_ammo_seq_tChunkP2Grow_realloc(
	  const xc_ammo_seq_cfg_t* refp_cfg
	, const xc_ammo_seq_state_t* refp_initial_state
	, xc_ammo_seq_state_t* refp_result_state
	, const size_t requested_new_length
);


int xc_ammo_seq_tChunkP2Grow_length2capacity(
	  const size_t length
	, const size_t cur_capacity
	, const size_t chunk_itemcnt
	, size_t* result_capacity
);


/* --- */


int xc_ammo_seq_tStatic_realloc(
	  const xc_ammo_seq_cfg_t* refp_cfg
	, const xc_ammo_seq_state_t* refp_initial_state
	, xc_ammo_seq_state_t* refp_result_state
	, const size_t requested_new_capacity
);


int xc_ammo_seq_tStatic_shiftLeft(
	  const xc_ammo_seq_cfg_t* refp_cfg
	, xc_ammo_seq_state_t* refp_state
	, const size_t start_public_idx
	, const size_t shift_size
);


int xc_ammo_seq_tStatic_shiftRight(
	  const xc_ammo_seq_cfg_t* refp_cfg
	, xc_ammo_seq_state_t* refp_state
	, const size_t start_public_idx
	, const size_t shift_size
);


int xc_ammo_seq_set_at_idx(
	  xc_ammo_seq_state_t* self_state
	, const size_t item_bytesize
	, const size_t idx_public
	, const xc_byteptr_t refp_item
);


typedef struct xc_ammo_seq_tStatic_shift_info_t
{
	
	size_t cnt_shift_bound;
	size_t last_idx;
	size_t cnt_complementary_to_orig_length;
	size_t new_length;
	size_t cnt_from_target_index_to_orig_length;
	
} xc_ammo_seq_tStatic_shift_info_t;


int xc_ammo_seq_tStatic_shiftLeft_calculate(
	  const xc_ammo_seq_state_t* refp_state
	, const size_t target_idx
	, const size_t req_shift_cnt
	, xc_ammo_seq_tStatic_shift_info_t* result
);


int xc_ammo_seq_tStatic_shiftRight_calculate(
	  const xc_ammo_seq_state_t* refp_state
	, const size_t target_idx
	, const size_t req_shift_cnt
	, xc_ammo_seq_tStatic_shift_info_t* result
);


xc_byteptr_t xc_ammo_seq_idx2byteptr(
	  xc_ammo_seq_state_t* self_state
	, const size_t item_bytesize
	, const size_t idx_public
);


void* xc_ammo_seq_idx2anyptr(
	  xc_ammo_seq_state_t* self_state
	, const size_t item_bytesize
	, const size_t idx_public
);


/* virtual interfaces: */
/* even if not used, it's useful as validator to enforce API consistency */
#if 1

typedef struct xc_amAlc_seq_I_t
{
	int (*length2capacity)(
		  const size_t length
		, const size_t current_capacity
		, const size_t chunk_itemcnt
		, size_t* result_capacity
	);
	
	int (*re_alloc)(
		  const xc_ammo_seq_cfg_t* refp_cfg
		, const xc_ammo_seq_state_t* refp_initial_state
		, xc_ammo_seq_state_t* refp_result_state
		, const size_t requested_new_length
	);
} xc_amAlc_seq_I_t;


typedef struct xc_amMdl_seq_I_t
{
	xc_byteptr_t (*idx2byteptr)(
		  xc_ammo_seq_state_t* self_state
		, const size_t item_bytesize
		, const size_t idx_public
	);

	void* (*idx2anyptr)(
		  xc_ammo_seq_state_t* self_state
		, const size_t item_bytesize
		, const size_t idx_public
	);
	
	int (*set_at_idx)(
		  xc_ammo_seq_state_t* self_state
		, const size_t item_bytesize
		, const size_t idx_public
		, const xc_byteptr_t refp_item
	);

	int (*shiftLeft_prealloc)(
		  const xc_ammo_seq_cfg_t* refp_cfg
		, xc_ammo_seq_state_t* refp_state
		, const size_t start_public_idx
		, const size_t shift_size
	);
	
	int (*shiftRight_prealloc)(
		  const xc_ammo_seq_cfg_t* refp_cfg
		, xc_ammo_seq_state_t* refp_state
		, const size_t start_public_idx
		, const size_t shift_size
	);
} xc_amMdl_seq_I_t;


typedef struct xc_amOp_seq_I_t
{
	xc_byteptr_t (*insert_at_idx)(
		  xc_ammo_seq_state_t* self_state
		, const size_t item_bytesize
		, const size_t idx_public
		, const xc_byteptr_t refp_item
	);

	int (*remove_at_idx)(
		  xc_ammo_seq_state_t* self_state
		, const size_t item_bytesize
		, const size_t idx_public
	);
	
	int (*append)(
		  xc_ammo_seq_state_t* self_state
		, const size_t item_bytesize
		, const xc_byteptr_t refp_item
	);
	
	xc_byteptr_t (*access_idx)(
		  xc_ammo_seq_state_t* self_state
		, const size_t item_bytesize
		, const size_t idx_public
	);
	
	int (*clear)(
		  const xc_ammo_seq_cfg_t* refp_cfg
		, xc_ammo_seq_state_t* refp_state
		, const size_t start_public_idx
		, const size_t shift_size
	);

	int (*optimizeMemSize)(
		  const xc_ammo_seq_cfg_t* refp_cfg
		, xc_ammo_seq_state_t* refp_state
		, const size_t start_public_idx
		, const size_t shift_size
	);
	
} xc_amOp_seq_I_t;


/*  global interface object */

extern const xc_amAlc_seq_I_t xc_amAlc_seq_tChunkP2_I;
extern const xc_amAlc_seq_I_t xc_amAlc_seq_tChunk_I;
extern const xc_amMdl_seq_I_t xc_amMdl_seq_I;

/* virtual interfaces: done */

#endif


#ifdef __cplusplus
}
#endif

#endif
