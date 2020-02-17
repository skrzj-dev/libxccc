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

#ifndef _XC_CMEM_U_H_
#define _XC_CMEM_U_H_


/* --- --- --- */
#ifdef __cplusplus
extern "C" {
#endif
/* --- --- --- */


#include <stddef.h>
#include <string.h>
#include <malloc.h>

/* --- --- --- --- --- --- --- ---  */

/*
 * type symbol, if present in parameters, will be always first, to resemble order in C++ templated function:
 * template<typename T>
 * templated_func<T>(params)
 */

/*
 * File content:
 * Wrappers over libc memory operations
 * API implementation: macro- based, unsafe macros (ANSI-C / C90 compliant)
 * 
 */

/* --- --- --- --- --- --- --- ---  */
 
/* --- --- --- --- */
/* cmem_allocz:  */
/* --- --- --- --- */


#define xc_mem_u_allocz_obj(_EXPECTED_OBJECT_TYPE_)  (_EXPECTED_OBJECT_TYPE_*)calloc(1, sizeof( _EXPECTED_OBJECT_TYPE_ ) )


#define xc_mem_u_allocz_bytes(_EXPECTED_OBJECT_TYPE_BYTESIZE_) calloc(1, (_EXPECTED_OBJECT_TYPE_BYTESIZE_) )


#define xc_mem_u_allocz_obj_array(_EXPECTED_OBJECT_TYPE_, _ARRAY_SIZE_)  (_EXPECTED_OBJECT_TYPE_*)calloc( (_ARRAY_SIZE_), sizeof( _EXPECTED_OBJECT_TYPE_ ) )

/* --- --- --- --- */
/* cmem_allocz: done */
/* --- --- --- --- */

/* --- --- --- --- --- --- --- ---  */

/* --- --- --- --- */
/* cmem_bzero:  */
/* --- --- --- --- */


#define xc_mem_u_bzero_obj(_EXPECTED_OBJECT_TYPE_, _TARGET_REFP_) memset(\
		  ( xc_mem_u__ptr_typecheck( _EXPECTED_OBJECT_TYPE_, (_TARGET_REFP_) ) )\
		, (0)\
		, sizeof(_EXPECTED_OBJECT_TYPE_)\
	)


#define xc_mem_u_bzero_obj_array(_EXPECTED_OBJECT_TYPE_, _ARRAY_SIZE_, _TARGET_REFP_) memset(\
		  ( xc_mem_u__ptr_typecheck(_EXPECTED_OBJECT_TYPE_, _TARGET_REFP_) )\
		, (0)\
		, sizeof(_EXPECTED_OBJECT_TYPE_)*(_ARRAY_SIZE_)\
	)


#define xc_mem_u_bzero_bytes(_OBJ_BYTE_SIZE_, _TARGET_REFP_) memset(\
		  (void*)(_TARGET_REFP_)\
		, (0)\
		, (_OBJ_BYTE_SIZE_)\
	)


/* --- --- --- --- */
/* cmem_bzero: done  */
/* --- --- --- --- */

/* --- --- --- --- --- --- --- ---  */

/* --- --- --- --- */
/* cmem_copy:  */
/* --- --- --- --- */


#define xc_mem_u_cp_obj(_EXPECTED_OBJECT_TYPE_, _TARGET_REFP_, _SOURCE_REFP_) memmove(\
		  xc_mem_u__ptr_typecheck(_EXPECTED_OBJECT_TYPE_, _TARGET_REFP_)\
		, xc_mem_u__ptr_typecheck(const _EXPECTED_OBJECT_TYPE_, _SOURCE_REFP_)\
		, sizeof(_EXPECTED_OBJECT_TYPE_)\
	)


#define xc_mem_u_cp_obj_array(_EXPECTED_OBJECT_TYPE_, _ARRAY_SIZE_, _TARGET_REFP_, _SOURCE_REFP_) memmove(\
		  xc_mem_u__ptr_typecheck(_EXPECTED_OBJECT_TYPE_, _TARGET_REFP_)\
		, xc_mem_u__ptr_typecheck(const _EXPECTED_OBJECT_TYPE_, _SOURCE_REFP_)\
		, sizeof(_EXPECTED_OBJECT_TYPE_)*(_ARRAY_SIZE_)\
	)


#define xc_mem_u_cp_bytes(_BYTESIZE_, _TARGET_REFP_, _SOURCE_REFP_) memmove(\
		  (void*)(_TARGET_REFP_)\
		, (const void*)(_SOURCE_REFP_)\
		, (_BYTESIZE_)\
	)


/* --- --- --- --- */
/* cmem_copy: done */
/* --- --- --- --- */

/* --- --- --- --- --- --- --- ---  */

/* --- --- --- --- */
/* cmem_cmp: */
/* --- --- --- --- */


#define xc_mem_u_cmp_obj(_EXPECTED_OBJECT_TYPE_, _TARGET_REFP_1ST_, _TARGET_REFP_2ND_) memcmp(\
		  (const void*)(_TARGET_REFP_1ST_)\
		, (const void*)(_TARGET_REFP_2ND_)\
		, sizeof(_EXPECTED_OBJECT_TYPE_)\
	)


/* --- --- --- */


#define xc_mem_u_cmp_obj_array(_EXPECTED_OBJECT_TYPE_, _ARG_ARRAY_ITEM_CNT_, _TARGET_REFP_1ST_, _TARGET_REFP_2ND_) memcmp(\
		  (const void*)xc_mem_u__ptr_typecheck(_EXPECTED_OBJECT_TYPE_, (_TARGET_REFP_1ST_) )\
		, (const void*)xc_mem_u__ptr_typecheck(_EXPECTED_OBJECT_TYPE_, (_TARGET_REFP_2ND_) )\
		, sizeof(_EXPECTED_OBJECT_TYPE_)*(_ARG_ARRAY_ITEM_CNT_)\
	)


/* --- --- --- */


#define xc_mem_u_cmp_bytes(_BYTESIZE_, _TARGET_REFP_1ST_, _TARGET_REFP_2ND_) memcmp(\
		  (const void*)(_TARGET_REFP_1ST_)\
		, (const void*)(_TARGET_REFP_2ND_)\
		, (_BYTESIZE_)\
	)


/*  --- --- --- */



#define xc_mem_u_cmp_obj_param(_EXPECTED_OBJECT_TYPE_, _TARGET_REFP_1ST_, _TARGET_REFP_2ND_, _REFP_RESULT_) do {\
		*(_REFP_RESULT_) = memcmp(\
			  (const void*)(_TARGET_REFP_1ST_)\
			, (const void*)(_TARGET_REFP_2ND_)\
			, sizeof(_EXPECTED_OBJECT_TYPE_)\
		); \
	} while(0);


/* --- --- --- */


#define xc_mem_u_cmp_obj_array_param(_EXPECTED_OBJECT_TYPE_, _ARG_ARRAY_ITEM_CNT_, _TARGET_REFP_1ST_, _TARGET_REFP_2ND_, _REFP_RESULT_)  do {\
		*(_REFP_RESULT_) = memcmp(\
			  (const void*)xc_mem_u__ptr_typecheck(_EXPECTED_OBJECT_TYPE_, (_TARGET_REFP_1ST_) )\
			, (const void*)xc_mem_u__ptr_typecheck(_EXPECTED_OBJECT_TYPE_, (_TARGET_REFP_2ND_) )\
			, sizeof(_EXPECTED_OBJECT_TYPE_)*(_ARG_ARRAY_ITEM_CNT_)\
		);\
	} while(0);

/* --- --- --- */


#define xc_mem_u_cmp_bytes_param(_BYTESIZE_, _TARGET_REFP_1ST_, _TARGET_REFP_2ND_, _REFP_RESULT_) do {\
		*(_REFP_RESULT_) = memcmp(\
			  (const void*)(_TARGET_REFP_1ST_)\
			, (const void*)(_TARGET_REFP_2ND_)\
			, (_BYTESIZE_)\
		);\
	} while(0);


/* --- --- --- --- */
/* cmem_cmp: done */
/* --- --- --- --- */

/* --- --- --- --- --- --- --- ---  */

/* --- --- --- --- */
/* cmem_free: */
/* --- --- --- --- */


#define xc_mem_u_free_obj(_ARG_EXPECTED_TYPE_, _ARG_REFP_) do {\
		free( (void*)( xc_mem_u__ptr_typecheck(_ARG_EXPECTED_TYPE_, (_ARG_REFP_) ) ) );\
		(_ARG_REFP_)=NULL;\
	} while(0);


#define xc_mem_u_free_bytes(_ARG_REFP_) do {\
		free( (void*)(_ARG_REFP_) );\
		(_ARG_REFP_)=NULL;\
	} while(0);


/* --- --- --- --- */
/* cmem_free: done */
/* --- --- --- --- */

/* --- --- --- --- --- --- --- ---  */

/* --- --- --- --- */
/* helpers: */
/* --- --- --- --- */


/* syntax sugar that returns _ARG_PTR_ from parameter after useless comparison too dummy pointer-  only to trigger compliation warning / error upon mismatch */
#define xc_mem_u__ptr_typecheck(_ARG_EXPECTED_OBJECT_TYPE_, _ARG_PTR_) (\
		( ( (_ARG_EXPECTED_OBJECT_TYPE_*)( (void*)NULL ) ) != (_ARG_PTR_) )\
		  ? (_ARG_PTR_)\
		  : (_ARG_PTR_)\
	)


/* --- --- --- --- */
/* helpers: done */
/* --- --- --- --- */

/* --- --- --- --- --- --- --- ---  */

/* --- --- --- */
#ifdef __cplusplus
}
#endif
/* --- --- --- */

#endif
