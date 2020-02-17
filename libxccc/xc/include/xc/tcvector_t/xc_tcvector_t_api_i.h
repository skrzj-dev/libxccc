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

#ifndef _XC_TCVECTOR_T_API_I_H_
#define _XC_TCVECTOR_T_API_I_H_

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  =======================================
 */
/*
 *   INTERNAL API: 
 */
/*
 *  =======================================
 */



#define xc_tcVectorT__I0_name(_ARG_SVECT_TYPENAME_, _ARG_FNNAME_) xcVecST ##_i_##_ARG_SVECT_TYPENAME_##_##_ARG_FNNAME_

#define xc_tcVectorT__I0_decl_prototypes(_ARG_SVECT_TYPE_, _ARG_ITEMTYPE_)\
	/* --- --- --- --- */\
	static int               xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, init)                 (_ARG_SVECT_TYPE_* refp_self);\
	static int               xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, deinit )              (_ARG_SVECT_TYPE_* refp_self);\
	static int               xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, clear )               (_ARG_SVECT_TYPE_* refp_self);\
	/**/\
	static _ARG_SVECT_TYPE_* xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, alloc_init )          (void);\
	static int               xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, dealloc )             (_ARG_SVECT_TYPE_* refp_self);\
	/**/\
	static int               xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, push )                (_ARG_SVECT_TYPE_* refp_self, const _ARG_ITEMTYPE_* refp_item);\
	static int               xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, pop )                 (_ARG_SVECT_TYPE_* refp_self);\
	/**/\
	static int               xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, remove_idx )          (_ARG_SVECT_TYPE_* refp_self, const int idx);\
	/**/\
	static int               xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, set_idx )             (_ARG_SVECT_TYPE_* refp_self, const int idx, const _ARG_ITEMTYPE_* refp_result_item);\
	/**/\
	static int               xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, insert )              (_ARG_SVECT_TYPE_* refp_self, const int idx, const _ARG_ITEMTYPE_* refp_result_item);\
	/**/\
	static _ARG_ITEMTYPE_*   xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, get_refp )         (_ARG_SVECT_TYPE_* refp_self, const int idx);\
	static int               xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, get_val_cp )          (_ARG_SVECT_TYPE_* refp_self, const int idx, _ARG_ITEMTYPE_* refp_result_item);\
	/**/\
	static int               xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, get_capacity )        ( _ARG_SVECT_TYPE_* refp_self);\
	static int               xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, get_length )          ( _ARG_SVECT_TYPE_* refp_self);\
	/**/\
	static int               xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, assign_from)          (_ARG_SVECT_TYPE_* refp_self, const _ARG_SVECT_TYPE_* refp_src, int* refp_overflow);\
	/* --- --- --- --- */


#define xc_tcVectorT__I0_decl_implementation(_ARG_SVECT_TYPE_, _ARG_ITEMTYPE_)\
	/* --- --- --- --- */\
	/* implementation: */\
	/* --- --- --- --- */\
	static int               xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, init)(_ARG_SVECT_TYPE_* refp_self) {\
		xc_err_decl();\
		/* --- */ \
		if(NULL==refp_self) {\
			xc_err_term_unmg();\
		}\
		/* --- */\
		return xc_tcVectorT_u_init(refp_self);\
		/* --- */\
		/*L_ERR:*/\
		xc_err_handle_unmg();\
		return 1;\
	}\
	static int               xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, deinit )(_ARG_SVECT_TYPE_* refp_self) {\
		xc_err_decl();\
		/* --- */ \
		if(NULL==refp_self) {\
			xc_err_term_unmg();\
		}\
		/* --- */\
		return xc_tcVectorT_u_deinit(refp_self);\
		/*L_ERR:*/\
		xc_err_handle_unmg();\
		return 1;\
	}\
	static int               xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, clear  )(_ARG_SVECT_TYPE_* refp_self) {\
		xc_err_decl();\
		/* --- */ \
		if(NULL==refp_self) {\
			xc_err_term_unmg();\
		}\
		/* --- */\
		return 1; /* TODO*/ /*xc_tcVectorT_u_clear(refp_self);*/\
		/*L_ERR:*/\
		xc_err_handle_unmg();\
		return 1;\
	}\
	/**/\
	static _ARG_SVECT_TYPE_* xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, alloc_init )(void) {\
		const size_t size2alloc=sizeof(_ARG_SVECT_TYPE_);\
		_ARG_SVECT_TYPE_* retv0=NULL;\
		xc_err_decl();\
		/* --- */ \
		if(NULL == (retv0= (_ARG_SVECT_TYPE_*)xc_tcVectorT_LL_alloc(size2alloc) ) ) {\
			xc_err_term_unmg();\
		}\
		/* --- */\
		if(0!=xc_tcVectorT_u_init(retv0) ) {\
			xc_err_term_unmg();\
		}\
		return retv0;\
		/*L_ERR:*/\
		xc_err_handle_unmg();\
		return NULL;\
	}\
	static int               xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, dealloc )(_ARG_SVECT_TYPE_* refp_self) {\
		xc_err_decl();\
		/* --- */ \
		if(NULL==refp_self) {\
			xc_err_term_unmg();\
		}\
		/* --- */\
		return xc_tcVectorT_u_dealloc(refp_self);\
		/*L_ERR:*/\
		xc_err_handle_unmg();\
		return 1;\
	}\
	/**/\
	static int               xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, push )(_ARG_SVECT_TYPE_* refp_self, const _ARG_ITEMTYPE_* refp_item) {\
		xc_err_decl();\
		/* --- */ \
		if(NULL==refp_self) {\
			xc_err_term_unmg();\
		}\
		/* --- */\
		return xc_tcVectorT_u_push(refp_self, refp_item);\
		/*L_ERR:*/\
		xc_err_handle_unmg();\
		return 1;\
	}\
	static int               xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, pop )(_ARG_SVECT_TYPE_* refp_self) {\
		xc_err_decl();\
		/* --- */ \
		if(NULL==refp_self) {\
			xc_err_term_unmg();\
		}\
		/* --- */\
		return xc_tcVectorT_u_pop(refp_self);\
		/*L_ERR:*/\
		xc_err_handle_unmg();\
		return 1;\
	}\
	/**/\
	static int                xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, remove_idx )(_ARG_SVECT_TYPE_* refp_self, const int idx) {\
		xc_err_decl();\
		/* --- */ \
		if(NULL==refp_self) {\
			xc_err_term_unmg();\
		}\
		/* --- */\
		return xc_tcVectorT_u_remove_idx(refp_self, idx);\
		/*L_ERR:*/\
		xc_err_handle_unmg();\
		return 1;\
	}\
	/**/\
	static int               xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, set_idx )(_ARG_SVECT_TYPE_* refp_self, const int idx, const _ARG_ITEMTYPE_* refp_result_item) {\
		xc_err_decl();\
		/* --- */ \
		if(NULL==refp_self) {\
			xc_err_term_unmg();\
		}\
		/* --- */\
		return xc_tcVectorT_u_set(refp_self, idx, refp_result_item);\
		/*L_ERR:*/\
		xc_err_handle_unmg();\
		return 1;\
	}\
	/**/\
	static int               xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, insert )(_ARG_SVECT_TYPE_* refp_self, const int idx, const _ARG_ITEMTYPE_* refp_result_item) {\
		xc_err_decl();\
		/* --- */ \
		if(NULL==refp_self) {\
			xc_err_term_unmg();\
		}\
		/* --- */\
		return xc_tcVectorT_u_insert(refp_self, idx, refp_result_item);\
		/*L_ERR:*/\
		xc_err_handle_unmg();\
		return 1;\
	}\
	/**/\
	static _ARG_ITEMTYPE_*   xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, get_refp )(_ARG_SVECT_TYPE_* refp_self, const int idx) {\
		xc_err_decl();\
		/* --- */ \
		if(NULL==refp_self) {\
			xc_err_term_unmg();\
		}\
		/* TODO ad validation for valid index and init self */\
		/* --- */\
		return xc_tcVectorT_u_item_refp(refp_self, idx);\
		/*L_ERR:*/\
		xc_err_handle_unmg();\
		return NULL;\
	}\
	static int               xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, get_val_cp )(_ARG_SVECT_TYPE_* refp_self, const int idx, _ARG_ITEMTYPE_* refp_result_item) {\
		xc_err_decl();\
		/* --- */ \
		if(NULL==refp_self) {\
			xc_err_term_unmg();\
		}\
		/* --- */\
		return xc_tcVectorT_u_item_cp(refp_self, idx, refp_result_item);\
		/*L_ERR:*/\
		xc_err_handle_unmg();\
		return 1;\
	}\
	/**/\
	static int               xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, get_capacity )(_ARG_SVECT_TYPE_* refp_self) {\
		xc_err_decl();\
		if(NULL==refp_self) {\
			xc_err_term_unmg();\
		}\
		return xc_tcVectorT_u_get_capacity(refp_self);\
		/*L_ERR:*/\
		xc_err_handle_unmg();\
		return 0;\
	}\
	static int               xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, get_length )(_ARG_SVECT_TYPE_* refp_self) {\
		xc_err_decl();\
		if(NULL==refp_self) {\
			xc_err_term_unmg();\
		}\
		return xc_tcVectorT_u_get_length(refp_self);\
		/*L_ERR:*/\
		xc_err_handle_unmg();\
		return 0;\
	}\
	/**/\
	static int               xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, assign_from)(_ARG_SVECT_TYPE_* refp_self, const _ARG_SVECT_TYPE_* refp_src, int* refp_overflow) {\
		xc_err_decl();\
		if(NULL==refp_self) {\
			xc_err_term_unmg();\
		}\
		if(NULL==refp_src) {\
			xc_err_term_unmg();\
		}\
		return xc_tcVectorT_u_assign_from(refp_self, refp_src, refp_overflow);\
		/*L_ERR:*/\
		xc_err_handle_unmg();\
		return 1;\
	}\
	/* --- --- --- --- */


#define xc_tcVectorT__I0_declt(_ARG_SVECT_TYPE_, _ARG_ITEMTYPE_) \
	struct xc_tcVectorT__I0_name( _ARG_SVECT_TYPE_, intf_t ) {\
		/**/\
		int                 (*init)(_ARG_SVECT_TYPE_* refp_self);\
		int                 (*deinit)(_ARG_SVECT_TYPE_* refp_self);\
		int                 (*clear)(_ARG_SVECT_TYPE_* refp_self);\
		/**/\
		_ARG_SVECT_TYPE_*   (*alloc_init)(void);\
		int                 (*dealloc)(_ARG_SVECT_TYPE_* refp_self);\
		/**/\
		int                 (*push)(_ARG_SVECT_TYPE_* refp_self, const _ARG_ITEMTYPE_* refp_item);\
		int                 (*pop)(_ARG_SVECT_TYPE_* refp_self);\
		/**/\
		int                 (*remove_idx)(_ARG_SVECT_TYPE_* refp_self, const int idx);\
		/**/\
		int                 (*set_idx)(_ARG_SVECT_TYPE_* refp_self, const int idx, const _ARG_ITEMTYPE_* refp_result_item);\
		/**/\
		int                 (*insert)(_ARG_SVECT_TYPE_* refp_self, const int idx, const _ARG_ITEMTYPE_* refp_result_item);\
		/**/\
		_ARG_ITEMTYPE_*     (*item_refp)(_ARG_SVECT_TYPE_* refp_self, const int idx);\
		int                 (*item_cp)(_ARG_SVECT_TYPE_* refp_self, const int idx, _ARG_ITEMTYPE_* refp_result_item);\
		/**/\
		int                 (*get_capacity)( _ARG_SVECT_TYPE_* refp_self);\
		int                 (*get_length)( _ARG_SVECT_TYPE_* refp_self);\
		/**/\
		int                 (*assign_from)( _ARG_SVECT_TYPE_* refp_self, const _ARG_SVECT_TYPE_* src, int* refp_overflow);\
	}


#define xc_tcVectorT__I0_initt(_ARG_SVECT_TYPE_) \
	{\
		  &xc_tcVectorT__I0_name( _ARG_SVECT_TYPE_, init )\
		, &xc_tcVectorT__I0_name( _ARG_SVECT_TYPE_, deinit )\
		, &xc_tcVectorT__I0_name( _ARG_SVECT_TYPE_, clear )\
		/**/\
		, &xc_tcVectorT__I0_name( _ARG_SVECT_TYPE_, alloc_init )\
		, &xc_tcVectorT__I0_name( _ARG_SVECT_TYPE_, dealloc )\
		/**/\
		, &xc_tcVectorT__I0_name( _ARG_SVECT_TYPE_, push )\
		, &xc_tcVectorT__I0_name( _ARG_SVECT_TYPE_, pop )\
		/**/\
		, &xc_tcVectorT__I0_name( _ARG_SVECT_TYPE_, remove_idx )\
		/**/\
		, &xc_tcVectorT__I0_name( _ARG_SVECT_TYPE_, set_idx)\
		/**/\
		, &xc_tcVectorT__I0_name( _ARG_SVECT_TYPE_, insert )\
		/**/\
		, &xc_tcVectorT__I0_name( _ARG_SVECT_TYPE_, get_refp )\
		, &xc_tcVectorT__I0_name( _ARG_SVECT_TYPE_, get_val_cp )\
		/**/\
		, &xc_tcVectorT__I0_name( _ARG_SVECT_TYPE_, get_capacity )\
		, &xc_tcVectorT__I0_name( _ARG_SVECT_TYPE_, get_length )\
		/**/\
		, &xc_tcVectorT__I0_name( _ARG_SVECT_TYPE_, assign_from )\
	}


#define xc_tcVectorT__I0_placeholder(_POSTFIX_) int svect_tmp_##__LINE__



#if 0
#define xc_tcVectorT__I0_decl_hlpTypes(_ARG_SVECT_TYPE_, _ARG_ITEMTYPE_)\
	typedef xc_tcVectorT__I_inf_decl(_ARG_SVECT_TYPE_, _ARG_ITEMTYPE_) stvect__I_t_##_ARG_SVECT_TYPE_;\
	const xc_tcVectorT__I0_name(_ARG_SVECT_TYPE_, stvect__I_obj )=xc_tcVectorT__I_initt01(_ARG_SVECT_TYPE_);\
	typedef const stvect__I_t_##_ARG_SVECT_TYPE_ 
#endif



/*
 *  =======================================
 */
/*
 *   INTERNAL API: done
 */
/*
 *  =======================================
 */
	


/*
 *  =======================================
 */
/*
 *   PUBLIC API:
 */
/*
 *  =======================================
 */



/* internal code */
#define xc_tcVectorT__I0_defaultObj_declt(_ARG_SVECT_TYPE_, _ARG_ITEMTYPE_) \
	const xc_tcVectorT__I0_name( _ARG_SVECT_TYPE_, I_t ) _ARG_SVECT_TYPE_##_I = xc_tcVectorT__I0_initt(_ARG_SVECT_TYPE_) \

/* to be used in customer code, declare type (in case if local instance / named alias for default intf object is required) */
#define xc_tcVectorT_i_type(_ARG_SVECT_TYPE_, _ARG_ITEMTYPE_) xc_tcVectorT__I0_name( _ARG_SVECT_TYPE_, I_t )

/* to be used in customer code, get object of default intf object ) */
#define xc_tcVectorT_i_refI(_ARG_SVECT_TYPE_, _ARG_ITEMTYPE_) (_ARG_SVECT_TYPE_##_I)

/* this has to be called in .c; declared code and default interface object */
#define xc_tcVectorT_i_local_instI(_ARG_SVECT_TYPE_, _ARG_ITEMTYPE_) \
	xc_tcVectorT__I0_decl_prototypes(_ARG_SVECT_TYPE_, _ARG_ITEMTYPE_) \
	xc_tcVectorT__I0_decl_implementation(_ARG_SVECT_TYPE_, _ARG_ITEMTYPE_) \
	/* --- */\
	xc_tcVectorT__I0_defaultObj_declt(_ARG_SVECT_TYPE_, _ARG_ITEMTYPE_) \
	/*xc_tcVectorT__I0_placeholder()*//* syntactic sugar so this macro can be called in fashion {xc_tcVectorT_i_localCode(x);} (ie ';' at end) */


/* this has to bbe called in .h file in order to make default interface obbject globally available */
#define xc_tcVectorT_i_global_declt_instI(_ARG_SVECT_TYPE_, _ARG_ITEMTYPE_) \
	typedef xc_tcVectorT__I0_declt(_ARG_SVECT_TYPE_, _ARG_ITEMTYPE_) xc_tcVectorT__I0_name( _ARG_SVECT_TYPE_, I_t )


#define xc_tcVectorT_i_global_extern_instI(_ARG_SVECT_TYPE_, _ARG_ITEMTYPE_) \
	extern const xc_tcVectorT__I0_name( _ARG_SVECT_TYPE_, I_t ) _ARG_SVECT_TYPE_##_I



/*
 *  =======================================
 */
/*
 *   PUBLIC API: done
 */
/*
 *  =======================================
 */


/* -------------------  */


#if 0 /* todo decide what to do furtther  */

#define xc_tcVectorT_i_init(_ARG_I_, _ARG_REFP_SELF_) (_ARG_I_)->init(\
	  (_ARG_REFP_SELF_)\
)

#define xc_tcVectorT_i_deinit(_ARG_I_, _ARG_REFP_SELF_) (_ARG_I_)->deinit(\
	  (_ARG_REFP_SELF_)\
)


/* --- */


#define xc_tcVectorT_i_init_alloc(_ARG_I_, _ARG_REFP_SELF_) (_ARG_I_)->alloc_init(\
	  (_ARG_REFP_SELF_)\
)


#define xc_tcVectorT_i_dealloc(_ARG_I_, _ARG_REFP_SELF_) (_ARG_I_)->dealloc(\
	  (_ARG_REFP_SELF_)\
)


/* --- */


#define xc_tcVectorT_i_set(_ARG_I_, _ARG_REFP_SELF_, _ARG_IDX_, _ARG_ITEM_REFP_) (_ARG_I_)->set(\
	  (_ARG_REFP_SELF_)\
	, (_ARG_IDX_)\
	, (_ARG_ITEM_REFP_)\
)


#define xc_tcVectorT_i_push(_ARG_I_, _ARG_REFP_SELF_, _ARG_ITEM_REFP_) (_ARG_I_)->push(\
	  (_ARG_REFP_SELF_)\
	, (_ARG_ITEM_REFP_)\
)


#define xc_tcVectorT_i_pop(_ARG_I_, _ARG_REFP_SELF_) (_ARG_I_)->pop(\
	  (_ARG_REFP_SELF_)\
)


#define xc_tcVectorT_i_insert(_ARG_I_, _ARG_REFP_SELF_, _ARG_IDX_, _ARG_ITEM_REFP_) (_ARG_I_)->insert(\
	  (_ARG_REFP_SELF_)\
	, (_ARG_IDX_)\
	, (_ARG_ITEM_REFP_)\
)


#define xc_tcVectorT_i_remove(_ARG_I_, _ARG_REFP_SELF_) (_ARG_I_)->remove_idx(\
	  (_ARG_REFP_SELF_)\
	, (_ARG_IDX_)\
)


/* --- */


#define xc_tcVectorT_i_assign_from(_ARG_I_, _ARG_REFP_SELF_, _ARG_REFP_SRC_) (_ARG_I_)->assign_from(\
	  (_ARG_REFP_SELF_)\
	  (_ARG_REFP_SRC_)\
)



/* --- */


#define xc_tcVectorT_i_get_length(_ARG_I_, _ARG_REFP_SELF_) (_ARG_I_)->get_length(\
	  (_ARG_REFP_SELF_)\
)


#define xc_tcVectorT_i_get_capacity(_ARG_I_, _ARG_REFP_SELF_) (_ARG_I_)->get_capacity(\
	  (_ARG_REFP_SELF_)\
)



/* --- */


#define xc_tcVectorT_i_get_val_cp(_ARG_I_, _ARG_REFP_SELF_) (_ARG_I_)->item_cp(\
	  (_ARG_REFP_SELF_)\
	, (_ARG_IDX_)\
)


#define xc_tcVectorT_i_get_val_refp(_ARG_I_, _ARG_REFP_SELF_, _ARG_IDX_) (_ARG_I_)->item_refp(\
	  (_ARG_REFP_SELF_)\
	, (_ARG_IDX_)\
)

#endif


#ifdef __cplusplus
}
#endif

#endif
