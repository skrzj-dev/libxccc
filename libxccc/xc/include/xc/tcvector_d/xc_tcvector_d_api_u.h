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

#ifndef _XC_TCVECTOR_D_API_U_H_
#define _XC_TCVECTOR_D_API_U_H_

#ifdef __cplusplus
extern "C" {
#endif

/* -- --- --- --- */
/* -- --- --- --- */


#define xc_tcVectorD_u_derefer_get_retv(_ARG_SELF_REFP_) xc_tcVectorD_LL_derefer_get_retv(\
		  &(_ARG_SELF_REFP_)->prv__hdrD\
		, (unsigned char**)&(_ARG_SELF_REFP_)->items_array_ptr\
		, (unsigned char*)(_ARG_SELF_REFP_)\
		, sizeof( (_ARG_SELF_REFP_)[0] )\
	)


#define xc_tcVectorD_u_derefer_get_retv_const(_ARG_SELF_REFP_) xc_tcVectorD_LL_derefer_get_retv_const(\
		  &(_ARG_SELF_REFP_)->prv__hdrD\
		, (const unsigned char**)&(_ARG_SELF_REFP_)->items_array_ptr\
		, (const unsigned char*)(_ARG_SELF_REFP_)\
		, sizeof( (_ARG_SELF_REFP_)[0] )\
	)


/* --- */
/* API: init / deinit */
/* --- */


#define xc_tcVectorD_u_init(_ARG_SELF_REFP_) xc_tcVectorD_LL_init(\
		  xc_tcVectorD_u_derefer_get_retv(_ARG_SELF_REFP_)\
		, sizeof( (_ARG_SELF_REFP_)->items_array_ptr[0] )\
	)


#define xc_tcVectorD_u_deinit(_ARG_SELF_REFP_) xc_tcVectorD_LL_deinit(\
		  xc_tcVectorD_u_derefer_get_retv( (_ARG_SELF_REFP_) )\
	)

/* --- */
/* API: init / deinit */
/* --- */


/* --- */
/* API: RAII: */
/* --- */


#define xc_tcVectorD_u_alloc_init(_ARG_SELF_REFP_TYPE_, _ARG_SELF_REFP_) (_ARG_SELF_REFP_TYPE_*) (\
		( NULL == ( (_ARG_SELF_REFP_) = (_ARG_SELF_REFP_TYPE_*)xc_tcVectorD_LL_alloc( sizeof( (_ARG_SELF_REFP_)[0] ) ) ) ) \
			? NULL \
			: xc_tcVectorD_LL_init_ret_self_refp(\
				  xc_tcVectorD_u_derefer_get_retv( (_ARG_SELF_REFP_) )\
				, sizeof( (_ARG_SELF_REFP_)->items_array_ptr[0] )\
			)\
	)


#define xc_tcVectorD_u_dealloc(_ARG_SELF_REFP_) xc_tcVectorD_LL_dealloc(\
		xc_tcVectorD_u_derefer_get_retv( (_ARG_SELF_REFP_) )\
	)
	

/* --- */
/* API: RAII: done */
/* --- */


#define xc_tcVectorD_u_push(_ARG_SELF_REFP_, _ARG_OBJ_REFP_) xc_tcVectorD_LL_push(\
		  xc_tcVectorD_u_derefer_get_retv( (_ARG_SELF_REFP_) )\
		, ( ( (_ARG_OBJ_REFP_)==(_ARG_SELF_REFP_)->prv__dummyptr ) ? (_ARG_OBJ_REFP_) : (_ARG_OBJ_REFP_) )\
		, sizeof( ( (_ARG_OBJ_REFP_)[0] ) )\
	)


#define xc_tcVectorD_u_pop(_ARG_SELF_REFP_) xc_tcVectorD_LL_pop(\
		  xc_tcVectorD_u_derefer_get_retv( (_ARG_SELF_REFP_) )\
	)


#define xc_tcVectorD_u_remove_idx(_ARG_SELF_REFP_, _ARG_TARGET_IDX_) xc_tcVectorD_LL_rem_idx(\
		  xc_tcVectorD_u_derefer_get_retv( (_ARG_SELF_REFP_) )\
		, (_ARG_TARGET_IDX_)\
	)

#define xc_tcVectorD_u_insert(_ARG_SELF_REFP_, _ARG_TARGET_IDX_, _ARG_OBJ_REFP_) xc_tcVectorD_LL_insert(\
		  xc_tcVectorD_u_derefer_get_retv( (_ARG_SELF_REFP_) )\
		, (_ARG_TARGET_IDX_)\
		, ( ( (_ARG_OBJ_REFP_)==(_ARG_SELF_REFP_)->prv__dummyptr ) ? (_ARG_OBJ_REFP_) : (_ARG_OBJ_REFP_) )\
		, sizeof( ( (_ARG_OBJ_REFP_)[0] ) )\
	)


/* access by IDX API: */


#define xc_tcVectorD_u_item_direct(_ARG_SELF_REFP_, _ARG_TARGET_IDX_) (\
		( 0 == xc_tcVectorD_LL_validate_initialization_and_index_access(\
			   xc_tcVectorD_u_derefer_get_retv(_ARG_SELF_REFP_)\
			  ,(_ARG_TARGET_IDX_)\
			)\
		)\
		? ( (_ARG_SELF_REFP_)->items_array_ptr[ (_ARG_TARGET_IDX_) ] )\
		: ( *( (_ARG_SELF_REFP_)->prv__dummyptr=NULL) )/* UNINITIALIZED OBJECT OPERATIONN OR OUT OF BOND ACCESS: UNMANAGEABLE ERROR, NULL */\
	)

#define xc_tcVectorD_u_item_refp(_ARG_SELF_REFP_, _ARG_TARGET_IDX_) (\
		( 0 == xc_tcVectorD_LL_validate_initialization_and_index_access(\
			   xc_tcVectorD_u_derefer_get_retv(_ARG_SELF_REFP_)\
			  ,(_ARG_TARGET_IDX_)\
			)\
		)\
		? ( &(_ARG_SELF_REFP_)->items_array_ptr[ (_ARG_TARGET_IDX_) ] )\
		: ( ( (_ARG_SELF_REFP_)->prv__dummyptr=NULL) )/* UNINITIALIZED OBJECT OPERATION OR OUT OF BOND ACCESS: MANAGEABLE ERROR, NULL */\
	)


#define xc_tcVectorD_u_item_cp(_ARG_SELF_REFP_, _ARG_TARGET_IDX_, _ARG_OBJ_REFP_) xc_tcVectorD_LL_get_cp(\
		  xc_tcVectorD_u_derefer_get_retv( (_ARG_SELF_REFP_) )\
		, (_ARG_TARGET_IDX_)\
		, ( ( (_ARG_OBJ_REFP_)==(_ARG_SELF_REFP_)->prv__dummyptr ) ? (_ARG_OBJ_REFP_) : (_ARG_OBJ_REFP_) )\
		, sizeof( ( (_ARG_OBJ_REFP_)[0] ) )\
	)

/* access by IDX API: done */



/* : */


#define xc_tcVectorD_u_get_capacity(_ARG_SELF_REFP_) xc_tcVectorD_LL_get_capacity(\
		xc_tcVectorD_u_derefer_get_retv( (_ARG_SELF_REFP_) )\
	)


#define xc_tcVectorD_u_get_length(_ARG_SELF_REFP_) xc_tcVectorD_LL_get_length(\
		xc_tcVectorD_u_derefer_get_retv( (_ARG_SELF_REFP_) )\
	)

/* : done*/

/* : */

#define xc_tcVectorD_u_set(_ARG_SELF_REFP_, _ARG_TARGET_IDX_, _ARG_OBJ_REFP_) xc_tcVectorD_LL_set_idx(\
		  xc_tcVectorD_u_derefer_get_retv( (_ARG_SELF_REFP_) )\
		, (_ARG_TARGET_IDX_)\
		, ( ( (_ARG_OBJ_REFP_)==(_ARG_SELF_REFP_)->prv__dummyptr ) ? (_ARG_OBJ_REFP_) : (_ARG_OBJ_REFP_) )\
		, sizeof( ( (_ARG_OBJ_REFP_)[0] ) )\
	)

/* : done */




/* copy: */
#define xc_tcVectorD_u_assign_from(_ARG_SELF_REFP_, _ARG_SRC_REFP_, _ARG_REFP_RESULT_OVERFLOW_) xc_tcVectorD_LL_assign_from(\
		  xc_tcVectorD_u_derefer_get_retv( ( ( (_ARG_SELF_REFP_)->prv__dummyptr == (_ARG_SRC_REFP_)->prv__dummyptr ) ? (_ARG_SELF_REFP_) : (_ARG_SELF_REFP_) ) )\
		, xc_tcVectorD_u_derefer_get_retv_const( ( ( (_ARG_SELF_REFP_)->prv__dummyptr == (_ARG_SRC_REFP_)->prv__dummyptr ) ? (_ARG_SRC_REFP_) : (_ARG_SRC_REFP_) ) )\
		, (_ARG_REFP_RESULT_OVERFLOW_)\
	)
/* copy: done */



/* -- --- --- --- */
/* -- --- --- --- */

#ifdef __cplusplus
}
#endif



#endif
