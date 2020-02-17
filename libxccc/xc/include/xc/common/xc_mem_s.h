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

#ifndef _XC_CMEM_S_H_
#define _XC_CMEM_S_H_


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
 * API implementation: macro- based, safe (C99 statement expression)
 */

/* --- --- --- --- --- --- --- ---  */
 
/* --- --- --- --- */
/* cmem_allocz:  */
/* --- --- --- --- */


#define xc_mem_s_allocz_obj(_EXPECTED_OBJECT_TYPE_)  (_EXPECTED_OBJECT_TYPE_*)calloc(1, sizeof( _EXPECTED_OBJECT_TYPE_ ) )


#define xc_mem_s_allocz_bytes(_EXPECTED_OBJECT_TYPE_BYTESIZE_) calloc(1, (_EXPECTED_OBJECT_TYPE_BYTESIZE_) )


#define xc_mem_s_allocz_obj_array(_EXPECTED_OBJECT_TYPE_, _ARRAY_SIZE_)  (_EXPECTED_OBJECT_TYPE_*)calloc( (_ARRAY_SIZE_), sizeof( _EXPECTED_OBJECT_TYPE_ ) )

/* --- --- --- --- */
/* cmem_allocz: done */
/* --- --- --- --- */

/* --- --- --- --- --- --- --- ---  */

/* --- --- --- --- */
/* cmem_bzero:  */
/* --- --- --- --- */


#define xc_mem_s_bzero_obj(_EXPECTED_OBJECT_TYPE_, _TARGET_REFP_)  do {\
	_EXPECTED_OBJECT_TYPE_* tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__=(_TARGET_REFP_);\
	memset( \
		  ( tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__ )\
		, 0\
		, sizeof(_EXPECTED_OBJECT_TYPE_) \
	);\
} while(0);


#define xc_mem_s_bzero_obj_array(_ARRAY_SIZE_, _EXPECTED_OBJECT_TYPE_, _TARGET_REFP_)  do {\
	_EXPECTED_OBJECT_TYPE_* tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__=(_TARGET_REFP_);\
	memset( \
		  ( tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__ )\
		, 0\
		, sizeof(_EXPECTED_OBJECT_TYPE_)*(_ARRAY_SIZE_)\
	);\
} while(0);


#define xc_mem_s_bzero_bytes(_OBJ_BYTE_SIZE_, _TARGET_REFP_)  do {\
	void* tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__=(_TARGET_REFP_);\
	memset( \
		  ( tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__ )\
		, 0\
		, (_OBJ_BYTE_SIZE_)\
	);\
} while(0);


/* --- --- --- --- */
/* cmem_bzero: done  */
/* --- --- --- --- */

/* --- --- --- --- --- --- --- ---  */

/* --- --- --- --- */
/* cmem_copy:  */
/* --- --- --- --- */


#define xc_mem_s_cp_obj(_EXPECTED_OBJECT_TYPE_, _TARGET_REFP_, _SOURCE_REFP_) do {\
		_EXPECTED_OBJECT_TYPE_* tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##_DEST=(_TARGET_REFP_);\
		const _EXPECTED_OBJECT_TYPE_* tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##_SRC=(_SOURCE_REFP_);\
		/* --- */\
		memmove(\
			  ( tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##_DEST )\
			, ( tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##_SRC )\
			, sizeof(_EXPECTED_OBJECT_TYPE_)\
		);\
		/* --- */\
	} while(0); 


#define xc_mem_s_cp_obj_array(_EXPECTED_OBJECT_TYPE_, _ARRAY_SIZE_, _TARGET_REFP_, _SOURCE_REFP_) do {\
		_EXPECTED_OBJECT_TYPE_* tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##_DEST=(_TARGET_REFP_);\
		const _EXPECTED_OBJECT_TYPE_* tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##_SRC=(_SOURCE_REFP_);\
		memmove(\
			  ( tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##_DEST )\
			, ( tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##_SRC )\
			, sizeof(_EXPECTED_OBJECT_TYPE_)*(_ARRAY_SIZE_)\
		);\
		/* --- */\
	} while(0); 


#define xc_mem_s_cp_bytes(_BYTESIZE_, _TARGET_REFP_, _SOURCE_REFP_) do {\
		void* tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##_DEST=(_TARGET_REFP_);\
		const void* tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##_SRC=(_SOURCE_REFP_);\
		/* --- */\
		memmove(\
			  ( tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##_DEST )\
			, ( tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##_SRC )\
			, (_BYTESIZE_)\
		);\
		/* --- */\
	} while(0); 


/* --- --- --- --- */
/* cmem_copy: done */
/* --- --- --- --- */

/* --- --- --- --- --- --- --- ---  */

/* --- --- --- --- */
/* cmem_cmp: */
/* --- --- --- --- */


#define xc_mem_s_cmp_obj(_EXPECTED_OBJECT_TYPE_, _TARGET_REFP_1ST_, _TARGET_REFP_2ND_) ({\
		const _EXPECTED_OBJECT_TYPE_* tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##obj1=(_TARGET_REFP_1ST_);\
		const _EXPECTED_OBJECT_TYPE_* tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##obj2=(_TARGET_REFP_2ND_);\
		/* --- */\
		memcmp(\
			  (const void*)(tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##obj1)\
			, (const void*)(tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##obj2)\
			, sizeof(_EXPECTED_OBJECT_TYPE_)\
		);\
		/* --- */\
	})


/* --- --- --- */


#define xc_mem_s_cmp_obj_array(_EXPECTED_OBJECT_TYPE_, _ARG_ARRAY_ITEM_CNT_, _TARGET_REFP_1ST_, _TARGET_REFP_2ND_) ({\
		const size_t tmpvar##_EXPECTED_OBJECT_TYPE_##__LINE__##tmpsize=(_ARG_ARRAY_ITEM_CNT_)*sizeof(_EXPECTED_OBJECT_TYPE_);\
		const _EXPECTED_OBJECT_TYPE_* tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##obj1=(_TARGET_REFP_1ST_);\
		const _EXPECTED_OBJECT_TYPE_* tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##obj2=(_TARGET_REFP_2ND_);\
		/* --- */\
		memcmp(\
			  (const void*)(tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##obj1)\
			, (const void*)(tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##obj2)\
			, (tmpvar##_EXPECTED_OBJECT_TYPE_##__LINE__##tmpsize)\
		);\
		/* --- */\
	})


/* --- --- --- */


#define xc_mem_s_cmp_bytes(_BYTESIZE_, _TARGET_REFP_1ST_, _TARGET_REFP_2ND_) memcmp(\
		  (const void*)(_TARGET_REFP_1ST_)\
		, (const void*)(_TARGET_REFP_2ND_)\
		, (_BYTESIZE_)\
	)


/* --- --- --- */


#define xc_mem_s_cmp_obj_param(_EXPECTED_OBJECT_TYPE_, _TARGET_REFP_1ST_, _TARGET_REFP_2ND_, _REFP_RESULT_) do {\
		const _EXPECTED_OBJECT_TYPE_* tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##obj1=(_TARGET_REFP_1ST_);\
		const _EXPECTED_OBJECT_TYPE_* tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##obj2=(_TARGET_REFP_2ND_);\
		int* tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##_result=(_REFP_RESULT_);\
		/* --- */\
		*(tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##_result)=memcmp(\
			  (const void*)(tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##obj1)\
			, (const void*)(tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##obj2)\
			, sizeof(_EXPECTED_OBJECT_TYPE_)\
		);\
		/* --- */\
	} while(0);


/* --- --- --- */


#define xc_mem_s_cmp_obj_array_param(_EXPECTED_OBJECT_TYPE_, _ARG_ARRAY_ITEM_CNT_, _TARGET_REFP_1ST_, _TARGET_REFP_2ND_, _REFP_RESULT_) do {\
		const size_t tmpvar##_EXPECTED_OBJECT_TYPE_##__LINE__##tmpsize=(_ARG_ARRAY_ITEM_CNT_)*sizeof(_EXPECTED_OBJECT_TYPE_);\
		const _EXPECTED_OBJECT_TYPE_* tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##obj1=(_TARGET_REFP_1ST_);\
		const _EXPECTED_OBJECT_TYPE_* tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##obj2=(_TARGET_REFP_2ND_);\
		int* tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##_result=(_REFP_RESULT_);\
		/* --- */\
		*(tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##_result)=memcmp(\
			  (const void*)(tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##obj1)\
			, (const void*)(tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##obj2)\
			, (tmpvar##_EXPECTED_OBJECT_TYPE_##__LINE__##tmpsize)\
		);\
		/* --- */\
	} while(0);


/* --- --- --- */


#define xc_mem_s_cmp_bytes_param(_BYTESIZE_, _TARGET_REFP_1ST_, _TARGET_REFP_2ND_, _REFP_RESULT_) do {\
		int* tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##_result=(_REFP_RESULT_);\
		*(tmpptr##_EXPECTED_OBJECT_TYPE_##__LINE__##_result)=memcmp(\
			  (const void*)(_TARGET_REFP_1ST_)\
			, (const void*)(_TARGET_REFP_2ND_)\
			, (_BYTESIZE_)\
		);\
		/* --- */\
	} while(0);


/* --- --- --- --- */
/* cmem_cmp: done */
/* --- --- --- --- */

/* --- --- --- --- --- --- --- ---  */

/* --- --- --- --- */
/* cmem_free: */
/* --- --- --- --- */


#define xc_mem_s_free_obj(_EXPECTED_OBJECT_TYPE_, _ARG_REFP_) do {\
		_EXPECTED_OBJECT_TYPE_* tmpvar_##__LINE__##_anyptr=(_ARG_REFP_);\
		_EXPECTED_OBJECT_TYPE_** tmpvar_##__LINE__##_refp2anyptr=&(_ARG_REFP_);\
		free( (void*)( (tmpvar_##__LINE__##_anyptr) ) );\
		*(tmpvar_##__LINE__##_refp2anyptr)=NULL;\
	} while(0);


#define xc_mem_s_free_bytes(_ARG_REFP_) do {\
		void* tmpvar_##__LINE__##_anyptr=(void*)(_ARG_REFP_);\
		void** tmpvar_##__LINE__##_refp2anyptr=(void**)&(_ARG_REFP_);\
		free( ( tmpvar_##__LINE__##_anyptr ) );\
		*(tmpvar_##__LINE__##_refp2anyptr)=NULL;\
	} while(0);


/* --- --- --- --- */
/* cmem_free: done */
/* --- --- --- --- */

/* --- --- --- --- --- --- --- ---  */

/* --- --- --- */
#ifdef __cplusplus
}
#endif
/* --- --- --- */

#endif
