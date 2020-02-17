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

#ifndef _XC_TCVECTOR_T_API_S_H_
#define _XC_TCVECTOR_T_API_S_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "xc_tcvector_t_cc.h"

#define xc_c_TYPEOF(_ARG_TYPE_) __typeof__(_ARG_TYPE_) 

#define xc_c_LOCALNAME(_ARG_NAME_) TMP_LOCAL_S_##_ARG_NAME_

/* -- --- --- --- */
/* -- --- --- --- */
#define xc_tcVectorT_s_derefer_get_retv(_ARG_SELF_REFP_) ({\
	/* --- */\
	xc_tcVectorT_LL_derefer_get_retv(\
			  &( _ARG_SELF_REFP_)->prv__hdrST\
			, (unsigned char*)&( _ARG_SELF_REFP_ )->items_array\
			, (unsigned char*)( _ARG_SELF_REFP_ )\
			, sizeof( (_ARG_SELF_REFP_ )[0] )\
		);\
		/* --- */\
	})
#if 0
#define xc_tcVectorT_s_derefer_get_retv(_ARG_SELF_REFP_) ({\
	xc_c_TYPEOF(_ARG_SELF_REFP_) xc_c_LOCALNAME(refp_self)=(_ARG_SELF_REFP_);\
	/*xc_c_LOCALNAME(refp_self)=(_ARG_SELF_REFP_);*/\
	/* --- */\
	xc_tcVectorT_LL_derefer_get_retv(\
			  &( xc_c_LOCALNAME(refp_self) )->prv__hdrD\
			, (unsigned char**)&( xc_c_LOCALNAME(refp_self) )->items_array_ptr\
			, (unsigned char*)( xc_c_LOCALNAME(refp_self) )\
			, sizeof( (xc_c_LOCALNAME(refp_self) )[0] )\
		);\
		/* --- */\
	})
#endif


#define xc_tcVectorT_s_init(_ARG_SELF_REFP_) ({\
		xc_c_TYPEOF(_ARG_SELF_REFP_) xc_c_LOCALNAME(refp_self) = ( _ARG_SELF_REFP_);\
		const size_t xc_c_LOCALNAME(tmp_bytesize)=sizeof( xc_c_LOCALNAME(refp_self)->items_array );\
		int xc_c_LOCALNAME(retv)=0;\
		/* --- */\
		xc_c_LOCALNAME(retv) = xc_tcVectorT_LL_init(\
			  xc_tcVectorT_s_derefer_get_retv( \
				  xc_c_LOCALNAME(refp_self)\
			  )\
			, sizeof( ( xc_c_LOCALNAME(refp_self) )->items_array[0] )\
			, xc_c_LOCALNAME(tmp_bytesize)\
		);\
		/* --- */\
		xc_c_LOCALNAME(retv);\
	})


#define xc_tcVectorT_s_deinit(_ARG_SELF_REFP_) ({\
		xc_c_TYPEOF(_ARG_SELF_REFP_) xc_c_LOCALNAME(refp_self)=(_ARG_SELF_REFP_);\
		int xc_c_LOCALNAME(retv)=0;\
		/* --- */\
		xc_c_LOCALNAME(retv) = xc_tcVectorT_LL_deinit(\
			  xc_tcVectorT_s_derefer_get_retv( ( xc_c_LOCALNAME(refp_self) ) )\
		);\
		/* --- */\
		xc_c_LOCALNAME(retv);\
	})


#define xc_tcVectorT_s_push(_ARG_SELF_REFP_, _ARG_OBJ_REFP_) ({\
		xc_c_TYPEOF(_ARG_SELF_REFP_) xc_c_LOCALNAME(refp_self)=(_ARG_SELF_REFP_);\
		const xc_c_TYPEOF(_ARG_OBJ_REFP_) xc_c_LOCALNAME(refp_item)=(_ARG_OBJ_REFP_);\
		int xc_c_LOCALNAME(retv)=0;\
		/* --- */\
		xc_c_LOCALNAME(retv) = xc_tcVectorT_LL_push(\
			  xc_tcVectorT_s_derefer_get_retv( xc_c_LOCALNAME(refp_self) )\
			, ( ( ( xc_c_LOCALNAME(refp_item) )==( xc_c_LOCALNAME(refp_self) )->prv__dummyptr ) ? ( xc_c_LOCALNAME(refp_item) ) : ( xc_c_LOCALNAME(refp_item) ) )\
			, sizeof( ( ( xc_c_LOCALNAME(refp_self) )[0] ) )\
		);\
		/* --- */\
		xc_c_LOCALNAME(retv);\
	})


#define xc_tcVectorT_s_pop(_ARG_SELF_REFP_) ({\
		xc_c_TYPEOF(_ARG_SELF_REFP_) xc_c_LOCALNAME(refp_self)=(_ARG_SELF_REFP_);\
		int xc_c_LOCALNAME(retv)=0;\
		/* --- */\
		xc_c_LOCALNAME(retv) = xc_tcVectorT_LL_pop(\
			  xc_tcVectorT_s_derefer_get_retv( xc_c_LOCALNAME(refp_self) )\
		);\
		/* --- */\
		xc_c_LOCALNAME(retv);\
	})


#define xc_tcVectorT_s_remove_idx(_ARG_SELF_REFP_, _ARG_TARGET_IDX_) ({\
		xc_c_TYPEOF(_ARG_SELF_REFP_) xc_c_LOCALNAME(refp_self)=(_ARG_SELF_REFP_);\
		const int xc_c_LOCALNAME(idx)=(_ARG_TARGET_IDX_);\
		int xc_c_LOCALNAME(retv)=0;\
		/* --- */\
		xc_c_LOCALNAME(retv) = xc_tcVectorT_LL_rem_idx(\
			  xc_tcVectorT_s_derefer_get_retv( xc_c_LOCALNAME(refp_self) )\
			, ( xc_c_LOCALNAME(idx) )\
		);\
		/* --- */\
		xc_c_LOCALNAME(retv);\
	})


#define xc_tcVectorT_s_insert(_ARG_SELF_REFP_, _ARG_TARGET_IDX_, _ARG_OBJ_REFP_) ({\
		xc_c_TYPEOF(_ARG_SELF_REFP_) xc_c_LOCALNAME(refp_self)=(_ARG_SELF_REFP_);\
		const xc_c_TYPEOF(_ARG_OBJ_REFP_) xc_c_LOCALNAME(refp_item)=(_ARG_OBJ_REFP_);\
		const int xc_c_LOCALNAME(idx)=(_ARG_TARGET_IDX_);\
		int xc_c_LOCALNAME(retv)=0;\
		/* --- */\
		xc_c_LOCALNAME(retv) = xc_tcVectorT_LL_insert(\
			  xc_tcVectorT_s_derefer_get_retv( xc_c_LOCALNAME(refp_self) )\
			, ( xc_c_LOCALNAME(idx) )\
			, ( ( ( xc_c_LOCALNAME(refp_item) )==( xc_c_LOCALNAME(refp_self) )->prv__dummyptr ) ? ( xc_c_LOCALNAME(refp_item) ) : ( xc_c_LOCALNAME(refp_item) ) )\
			, sizeof( ( ( xc_c_LOCALNAME(refp_item) )[0] ) )\
		);\
		/* --- */\
		xc_c_LOCALNAME(retv);\
	})


/* access by IDX API: */


#define xc_tcVectorT_s_item_direct(_ARG_SELF_REFP_, _ARG_TARGET_IDX_) \
	( *xc_tcVectorT_s_item_refp(_ARG_SELF_REFP_, _ARG_TARGET_IDX_) )

#if 0
({\
		xc_c_TYPEOF(_ARG_SELF_REFP_) xc_c_LOCALNAME(refp_self)=(_ARG_SELF_REFP_);\
		const int xc_c_LOCALNAME(idx)=(_ARG_TARGET_IDX_);\
		/* --- */\
		(\
			( 0 == xc_tcVectorT_LL_validate_initialization_and_index_access(\
				   xc_tcVectorT_s_derefer_get_retv( xc_c_LOCALNAME(refp_self) )\
				  ,( xc_c_LOCALNAME(idx) )\
				)\
			)\
			? ( ( xc_c_LOCALNAME(refp_self) )->items_array_ptr[ ( xc_c_LOCALNAME(idx) ) ] )\
			: ( *( ( xc_c_LOCALNAME(refp_self) )->prv__dummyptr=NULL) )/* UNINITIALIZED OBJECT OPERATIONN OR OUT OF BOND ACCESS: UNMANAGEABLE ERROR, NULL */\
		);\
	})
#endif

#define xc_tcVectorT_s_item_refp(_ARG_SELF_REFP_, _ARG_TARGET_IDX_)  ({\
		xc_c_TYPEOF(_ARG_SELF_REFP_) xc_c_LOCALNAME(refp_self)=(_ARG_SELF_REFP_);\
		const int xc_c_LOCALNAME(idx)=(_ARG_TARGET_IDX_);\
		xc_c_TYPEOF( xc_c_LOCALNAME(refp_self)->prv__dummyptr ) xc_c_LOCALNAME(retv);\
		/* --- */\
		xc_c_LOCALNAME(retv)=\
		(\
			( 0 == xc_tcVectorT_LL_validate_initialization_and_index_access(\
				   xc_tcVectorT_s_derefer_get_retv( xc_c_LOCALNAME(refp_self) )\
				  ,( xc_c_LOCALNAME(idx) )\
				)\
			)\
			? ( &( xc_c_LOCALNAME(refp_self) )->items_array[ ( xc_c_LOCALNAME(idx) ) ] )\
			: ( ( ( xc_c_LOCALNAME(refp_self) )->prv__dummyptr=NULL) )/* UNINITIALIZED OBJECT OPERATION OR OUT OF BOND ACCESS: MANAGEABLE ERROR, NULL */\
		);\
		/* --- */\
		xc_c_LOCALNAME(retv);\
	})


#define xc_tcVectorT_s_item_cp(_ARG_SELF_REFP_, _ARG_TARGET_IDX_, _ARG_OBJ_REFP_) ({\
		xc_c_TYPEOF(_ARG_SELF_REFP_) xc_c_LOCALNAME(refp_self)=(_ARG_SELF_REFP_);\
		const int xc_c_LOCALNAME(idx)=(_ARG_TARGET_IDX_);\
		const xc_c_TYPEOF(_ARG_OBJ_REFP_) xc_c_LOCALNAME(refp_item)=(_ARG_OBJ_REFP_);\
		int xc_c_LOCALNAME(retv)=0;\
		/* --- */\
		xc_c_LOCALNAME(retv) = xc_tcVectorT_LL_get_cp(\
			  xc_tcVectorT_s_derefer_get_retv( ( xc_c_LOCALNAME(refp_self) ) )\
			, ( xc_c_LOCALNAME(idx) )\
			, ( ( ( xc_c_LOCALNAME(refp_item) )==( xc_c_LOCALNAME(refp_self) )->prv__dummyptr ) ? ( xc_c_LOCALNAME(refp_item) ) : ( xc_c_LOCALNAME(refp_item) ) )\
			, sizeof( ( ( xc_c_LOCALNAME(refp_item) )[0] ) )\
		);\
		/* --- */\
		xc_c_LOCALNAME(retv);\
	})

/* access by IDX API: done */



/* : */


#define xc_tcVectorT_s_get_capacity(_ARG_SELF_REFP_) ({\
		xc_c_TYPEOF(_ARG_SELF_REFP_) xc_c_LOCALNAME(refp_self)=(_ARG_SELF_REFP_);\
		int xc_c_LOCALNAME(retv)=0;\
		/* --- */\
		xc_c_LOCALNAME(retv) = xc_tcVectorT_LL_get_capacity(\
			xc_tcVectorT_s_derefer_get_retv( ( xc_c_LOCALNAME(refp_self) ) )\
		);\
		/* --- */\
		xc_c_LOCALNAME(retv);\
	})


#define xc_tcVectorT_s_get_length(_ARG_SELF_REFP_) ({\
		xc_c_TYPEOF(_ARG_SELF_REFP_) xc_c_LOCALNAME(refp_self)=(_ARG_SELF_REFP_);\
		int xc_c_LOCALNAME(retv)=0;\
		/* --- */\
		xc_c_LOCALNAME(retv) = xc_tcVectorT_LL_get_length(\
			xc_tcVectorT_s_derefer_get_retv( ( xc_c_LOCALNAME(refp_self) ) )\
		);\
		/* --- */\
		xc_c_LOCALNAME(retv);\
	})

/* : done*/

/* : */

#define xc_tcVectorT_s_set(_ARG_SELF_REFP_, _ARG_TARGET_IDX_, _ARG_OBJ_REFP_)  ({\
		xc_c_TYPEOF(_ARG_SELF_REFP_) xc_c_LOCALNAME(refp_self)=(_ARG_SELF_REFP_);\
		const int xc_c_LOCALNAME(idx)=(_ARG_TARGET_IDX_);\
		const xc_c_TYPEOF(_ARG_OBJ_REFP_) xc_c_LOCALNAME(refp_item)=(_ARG_OBJ_REFP_);\
		int xc_c_LOCALNAME(retv)=0;\
		/* --- */\
		xc_c_LOCALNAME(retv) = xc_tcVectorT_LL_set_idx(\
			  xc_tcVectorT_s_derefer_get_retv( xc_c_LOCALNAME(refp_self) )\
			, xc_c_LOCALNAME(idx)\
			, ( ( ( xc_c_LOCALNAME(refp_item) ) == ( xc_c_LOCALNAME(refp_self) )->prv__dummyptr ) ? ( xc_c_LOCALNAME(refp_item) ) : ( xc_c_LOCALNAME(refp_item) ) )\
			, sizeof( ( xc_c_LOCALNAME(refp_item) )[0] ) \
		);\
		/* --- */\
		xc_c_LOCALNAME(retv);\
	})

/* : done */


/* --- */
/* API: init / deinit */
/* --- */

#define xc_tcVectorT_s_alloc_init(_ARG_SELF_REFP_) ({\
		xc_c_TYPEOF(_ARG_SELF_REFP_) xc_c_LOCALNAME(retv1)=NULL;\
		xc_c_TYPEOF(_ARG_SELF_REFP_) xc_c_LOCALNAME(retv)=NULL;\
		xc_c_TYPEOF(_ARG_SELF_REFP_) xc_c_LOCALNAME(refp_self) = ( _ARG_SELF_REFP_ );\
		const size_t xc_c_LOCALNAME(item_array_bytesize) = sizeof( xc_c_LOCALNAME(refp_self)->items_array );\
		/* --- */\
		xc_c_LOCALNAME(retv1) = ( xc_c_TYPEOF(_ARG_SELF_REFP_) ) xc_tcVectorT_LL_alloc( sizeof( xc_c_LOCALNAME(refp_self)[0] ) );\
		xc_c_LOCALNAME(retv)  = ( xc_c_TYPEOF(_ARG_SELF_REFP_) ) xc_tcVectorT_LL_init_ret_self_refp(\
				xc_tcVectorT_s_derefer_get_retv(\
					  xc_c_LOCALNAME(retv1)\
			  )\
			, sizeof( ( xc_c_LOCALNAME(refp_self) )->items_array[0] )\
			, xc_c_LOCALNAME(item_array_bytesize)\
		);\
		/* --- */\
		xc_c_LOCALNAME(retv);\
	})


#define xc_tcVectorT_s_dealloc(_ARG_SELF_REFP_) ({\
		xc_c_TYPEOF(_ARG_SELF_REFP_) xc_c_LOCALNAME(refp_self)=(_ARG_SELF_REFP_);\
		int xc_c_LOCALNAME(retv)=0;\
		/* --- */\
		xc_c_LOCALNAME(retv) = xc_tcVectorT_LL_dealloc(\
			xc_tcVectorT_s_derefer_get_retv( ( xc_c_LOCALNAME(refp_self) ) )\
		);\
		/* --- */\
		xc_c_LOCALNAME(retv);\
	})


/* --- */
/* API: init / deinit */
/* --- */


#define xc_tcVectorT_s_assign_from(_ARG_SELF_REFP_, _ARG_SRC_REFP_, _ARG_REFP_RESULT_OVERFLOW_) ({\
		xc_c_TYPEOF(_ARG_SELF_REFP_) xc_c_LOCALNAME(refp_self)=(_ARG_SELF_REFP_);\
		const xc_c_TYPEOF(_ARG_SRC_REFP_) xc_c_LOCALNAME(refp_src)=(_ARG_SRC_REFP_);\
		int* xc_c_LOCALNAME(refp_overflow)=(_ARG_REFP_RESULT_OVERFLOW_);\
		int xc_c_LOCALNAME(retv)=0;\
		/* just do type check */\
		const int tmpv=(\
		  ( ( xc_c_LOCALNAME(refp_self)->prv__dummyptr ) == ( xc_c_LOCALNAME(refp_src) )->prv__dummyptr ) \
		  ? ( 1 ) \
		  : ( 1 ) \
		);\
		/* --- */\
		xc_c_LOCALNAME(retv)=xc_tcVectorT_LL_assign_from(\
			  xc_tcVectorT_u_derefer_get_retv( xc_c_LOCALNAME(refp_self) )\
			, xc_tcVectorT_u_derefer_get_retv_const( xc_c_LOCALNAME(refp_src) )\
			, xc_c_LOCALNAME(refp_overflow)\
		);\
		/* --- */\
		xc_c_LOCALNAME(retv);\
	})


/* --- */
/* API: init / deinit: done */
/* --- */



/* -- --- --- --- */
/* -- --- --- --- */

#ifdef __cplusplus
}
#endif


#endif
