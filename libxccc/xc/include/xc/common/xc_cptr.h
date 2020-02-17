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

#ifndef _XC_CPTR_H_
#define _XC_CPTR_H_

/* --- --- --- */
#ifdef __cplusplus
extern "C" {
#endif
/* --- --- --- */

/*
 * 
 * File content:
 *    Wrappers over low- level "anytype" pointers (byte char* and anytype void*)
 *    Discrete types to indicate context of ambiguos pointers 
 * --- --- --- 
 * 
 * Notices:
 *    Any NULLPTR parameter error or similar unamnaged error MUST cause crash (basically panic, it can be only debugged if it occurs)
 *    It's too low layer to do any error handling
 * 
 * --- --- --- 
 *
 * Nameespace prefix:
 *    xc_p_*
 *    xc_p_<typename>_t
 *    xc_p_<typename>_API
 *
 * Naming:
 *    xc_p_p<Type> - pointer to type
 *    xc_p_p<Type>Const - const pointer to type
 *    xc_p_p<Type>Array - array of pointers to type
 *    xc_p_p<Type>ConstArray - array of const pointers to type
 *    xc_p_refp2p<Type> - [reference by pointer] to pointer to type
 *    xc_p_refp2p<Type>Const - [reference by pointer] to const pointer to type
 *    xc_p_refp2p<Type>ConstArray - [reference by pointer] to array of const pointer to type
 * 
 * --- --- --- 
 *
 * Types:
 * 
 *     - byte pointer - BytePtr - BtPtr
 *       char*
 *          pointer to bytes; can be used for pointer arithmetic for 1 byte
 * 
 *     - reference to byte pointer - Refp2BytePtr - Ref2BtPtr
 *       char**
 *          pointer to pointer to bytes; 
 * 
 *     - array of byte pointers - ArrayOfBytePtr - ArrOfBtPtr
 *       char**
 *          array<byte pointer>; 
 *
 *     - reference to array of byte pointers - Refp2ArrayOfBytePtr - Refp2ArrOfBtPtr
 *       char***
 *          pointer to array<byte pointer>;
 *
 * --- --- --- 
 * 
 */


/* --- --- --- --- */
/* ptr types: */
/* --- --- --- --- */


typedef struct xc_p_pBytes_t
{
	
	unsigned char* BtPtr;
	
} xc_p_pBytes_t;


typedef struct xc_p_pBytesConst_t
{
	
	const unsigned char* BtPtr;
	
} xc_p_pBytesConst_t;


typedef struct xc_p_refp2pBytes_t
{
	
	unsigned char** Refp2BtPtr;
	
} xc_p_refp2pBytes_t;


typedef struct xc_p_refp2pBytesConst_t
{
	
	const unsigned char** Refp2BtPtr;
	
} xc_p_refp2pBytesConst_t;


/* --- --- --- */


typedef struct xc_p_BytesArray_t
{
	
	unsigned char* BtPtrArr;
	
} xc_p_BytesArray_t;


typedef struct xc_p_BytesConstArray_t
{
	
	const unsigned char* BtPtrArr;
	
} xc_p_BytesConstArray_t;


/* --- --- --- */


typedef struct xc_p_pBytesArray_t
{
	
	unsigned char** BtPtrArr;
	
} xc_p_pBytesArray_t;


typedef struct xc_p_pBytesConstArray_t
{
	
	unsigned const char** BtPtrArr;
	
} xc_p_pBytesConstArray_t;


typedef struct xc_p_refp2pBytesArray_t
{
	
	unsigned char*** Refp2ArrOfBtPtr;
	
} xc_p_refp2pBytesArray_t;


typedef struct xc_p_refp2pBytesConstArray_t
{
	
	const unsigned char*** Refp2ArrOfBtPtr;
	
} xc_p_refp2pBytesConstArray_t;


/* --- --- --- */


xc_p_pBytes_t           xc_p_pBytes_from_ref2pBytes(xc_p_refp2pBytes_t refp_src);
xc_p_pBytes_t           xc_p_pBytes_from_raw(unsigned char* target);

int                     xc_p_refp2pBytes_assign_pBytes(xc_p_refp2pBytes_t* refp_target, xc_p_pBytes_t refp_src);
xc_p_refp2pBytes_t       xc_p_refp2pBytes_from_raw(unsigned char** target);

xc_p_pBytesConst_t      xc_ptr_pBytesConst_from_ref2pBytesConst(xc_p_refp2pBytesConst_t refp_src);

/* --- --- --- */
/* --- --- --- */

typedef struct xcc_p_pIntArray_t
{
	int* array;
	
}  xcc_p_pIntArray_t;


typedef struct xcc_p_refp2pIntArray_t
{
	int** refp2array;
	
}  xcc_p_refp2pIntArray_t;


/* --- --- --- */


/* --- --- --- --- */
/* ptr types: done */
/* --- --- --- --- */


/* --- --- --- --- */
/* custom ptr types: */
/* --- --- --- --- */

/* 
 * Kind of useless without discrete type- safe interface
 *
 * cannot be used as funcion parameters:
 * - parameters cannot be anonymous typed - declt would had to be declared dor every single insantiated type with typedef - madness
 *
 * may bbe used effectively in function scope as aliases for pointer parameters or random pointers in code
 * this will result with improved readability, as the names explicitly name context in which a pointer is used.
 *
 */

#define xc_p_declt_pObj(_ARG_TYPE_) struct {\
	_ARG_TYPE_*  pObj;\
}

#define xc_p_declt_refp2pObj(_ARG_TYPE_) struct {\
	_ARG_TYPE_**  ref2pObj;\
}

#define xc_p_declt_objArr(_ARG_TYPE_) struct {\
	_ARG_TYPE_*  objArr;\
}

#define xc_p_declt_ref2ObjArr(_ARG_TYPE_) struct {\
	_ARG_TYPE_**  ref2ObjArr;\
}

#define xc_p_declt_objArr2(_ARG_TYPE_) struct {\
	_ARG_TYPE_**  objArr2;\
}

/* --- */

#define xc_p_declt_objPtrConst(_ARG_TYPE_) struct {\
	const _ARG_TYPE_*  objPtrConst;\
}

#define xc_p_declt_refp2pObjConst(_ARG_TYPE_) struct {\
	const _ARG_TYPE_**  ref2pObjConst;\
}

#define xc_p_declt_objArrConst(_ARG_TYPE_) struct {\
	const _ARG_TYPE_*  objArrPtrConst;\
}

#define xc_p_declt_refp2pObjArrConst(_ARG_TYPE_) struct {\
	const _ARG_TYPE_**  refp2ObjArrPtrConst;\
}

#define xc_p_declt_objArr2Const(_ARG_TYPE_) struct {\
	const _ARG_TYPE_**  objArr2Const;\
}

/* --- */

/* all objects here have onyl 1 member which is value field */
#define xc_p_itz_fromRaw(_ARG_TARGET_PTR_) { _ARG_TARGET_PTR_ }

/* --- --- --- --- */
/* custom ptr types: done */
/* --- --- --- --- */

#define xc_p_refp2pBytes_castFrom_raw(_ARG_PTR_SRC_) (unsigned char**)&(_ARG_PTR_SRC_)

#define xc_p_pBytes_castFrom_raw(_ARG_PTR_SRC_) (unsigned char*)(_ARG_PTR_SRC_)

/* --- --- --- */
#ifdef __cplusplus
}
#endif
/* --- --- --- */

#endif
