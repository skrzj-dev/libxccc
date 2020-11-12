#ifndef _XCC_TEST2_PARAMROW_HPP_
#define _XCC_TEST2_PARAMROW_HPP_

#if 0
typedef struct objt_null
{
	void* yogsothoth;
} objt_t;

objt_t objt_null;

#define DATAROW3_DECLT(TYPE_P1, TYPE_P2, TYPE_P3) \
	struct DATAROW_T##__LINE__ { \
		const char* row_id;\
		TYPE_P1 param1;\
		TYPE_P2 param2;\
		TYPE_P3 param3;\
	} 

#if 0
#define DATAROW3_ITZ_P3(TYPE, ID, P1, P2, P3) { \
	  ((const char**)(NULL)) == &(ID) ? (ID) : (ID) \
	, ((TYPE*)(NULL))->param1 == (P1) ? (P1) : (P1) \
	, ((TYPE*)(NULL))->param2 == (P2) ? (P2) : (P2) \
	, ((TYPE*)(NULL))->param3 == (P3) ? (P3) : (P3) \
}
#endif


#define DATAROW3_ITZ_T(TYPE, ID, P1, P2, P3) { \
	  (ID) \
	, (P1) \
	, (P2) \
	, (P3) \
}

#define DATAROWX_ITZ_TERM() {0}

typedef DATAROW3_DECLT(int, const char*, objt_t) tmprow_t;


const tmprow_t tmprow1[]=
{
	  DATAROW3_ITZ_T(tmprow_t, "row1", 9, "aa", objt_null)
	, DATAROW3_ITZ_T(tmprow_t, "row1", 9, "aa", objt_null)
	, DATAROW3_ITZ_T(tmprow_t, "row1", 9, "aa", objt_null)
	, DATAROW3_ITZ_T(tmprow_t, "row1", 9, "aa", objt_null)
	, DATAROW3_ITZ_T(tmprow_t, "row1", 9, "aa", objt_null)
	, DATAROW3_ITZ_T(tmprow_t, "row1", 9, "aa", objt_null)
	, DATAROWX_ITZ_TERM()
};

#define xcc_test3_case_forDataRow3(_ID_, _DESCRIPTION_, _TMPROW_T_, _FN_, _ARRAY_) do {\
			int xcc_test2_tmp_cnter_##__LINE__=0;\
			xcc_test2_case_descr(_ID_, _DESCRIPTION_);\
			if(1)\
			{\
				for(xcc_test2_tmp_cnter_##__LINE__=0; NULL!=_ARRAY_[xcc_test2_tmp_cnter_##__LINE__]->row_id; xcc_test2_tmp_cnter_##__LINE__++)\
				{\
					_TMPROW_T_* xcc_test2_tmp_tmprow_##__LINE__=&_ARRAY_[xcc_test2_tmp_cnter_##__LINE__];\
					xcc_test2_expect( 0 == _FN_( \
						  (xcc_test2_tmp_tmprow_##__LINE__)->param1\
						, (xcc_test2_tmp_tmprow_##__LINE__)->param2\
						, (xcc_test2_tmp_tmprow_##__LINE__)->param3\
					) );\
				}\
			}\
			xcc_test2_case_end();\
	} while(0);
#endif



#define xcc_test3_case_descr(_CASE_ID_, _VARIANT_ID_, _DESCRIPTION_) xcc_test2_case_descr( xcc::test2::helper::cstrfmt_to_string("%s-[%s]", _CASE_ID_, _VARIANT_ID_), _DESCRIPTION_)

/* --- --- --- --- */
/* --- --- --- --- */
/* --- --- --- --- */

#define xcc_test3_DATAROWX_ITZ_TERM() {NULL}


#define xcc_test3_LL_case_forDataRowX_START(_ID_, _DESCRIPTION_, _TMPROW_T_, _FN_, _ARRAY_) do {\
			int xcc_test2_tmp_cnter_##__LINE__=0;\
			if(1)\
			{\
				for(xcc_test2_tmp_cnter_##__LINE__=0; NULL!=_ARRAY_[xcc_test2_tmp_cnter_##__LINE__].row_id; xcc_test2_tmp_cnter_##__LINE__++)\
				{\
					_TMPROW_T_* xcc_test2_tmp_tmprow_##__LINE__=&_ARRAY_[xcc_test2_tmp_cnter_##__LINE__];\
					xcc_test3_case_descr(_ID_, xcc_test2_tmp_tmprow_##__LINE__->row_id, _DESCRIPTION_);\
					 

#define xcc_test3_LL_case_forDataRowX_END(_ID_, _DESCRIPTION_, _TMPROW_T_, _FN_, _ARRAY_)\
					xcc_test2_case_end();\
				}\
			}\
	} while(0);\
	;

/* --- --- --- --- */
/* --- --- --- --- */
/* --- --- --- --- */

#define xcc_test3_DATAROW1_DECLT(TYPE_P1, TYPE_P2) \
	struct DATAROW_T##__LINE__ { \
		const char* row_id;\
		TYPE_P1 param1;\
	} 

#define xcc_test3_DATAROW1_ITZ_T(TYPE, ID, P1, P2) { \
	  (ID) \
	, (P1) \
}

#define xcc_test3_case_forDataRow1(_ID_, _DESCRIPTION_, _TMPROW_T_, _FN_, _ARRAY_) do {\
			xcc_test3_LL_case_forDataRowX_START(_ID_, _DESCRIPTION_, _TMPROW_T_, _FN_, _ARRAY_)\
				  (xcc_test2_tmp_tmprow_##__LINE__)->param1\
			xcc_test3_LL_case_forDataRowX_END(_ID_, _DESCRIPTION_, _TMPROW_T_, _FN_, _ARRAY_)\
	} while(0);

/* --- --- --- --- */
/* --- --- --- --- */
/* --- --- --- --- */

#define xcc_test3_DATAROW2_DECLT(TYPE_P1, TYPE_P2) \
	struct DATAROW_T##__LINE__ { \
		const char* row_id;\
		TYPE_P1 param1;\
		TYPE_P2 param2;\
	} 

#define xcc_test3_DATAROW2_ITZ_T(TYPE, ID, P1, P2) { \
	  (ID) \
	, (P1) \
	, (P2) \
}

#define xcc_test3_case_forDataRow2(_ID_, _DESCRIPTION_, _TMPROW_T_, _FN_, _ARRAY_) do {\
			xcc_test3_LL_case_forDataRowX_START(_ID_, _DESCRIPTION_, _TMPROW_T_, _FN_, _ARRAY_)\
				  (xcc_test2_tmp_tmprow_##__LINE__)->param1\
				, (xcc_test2_tmp_tmprow_##__LINE__)->param2\
			xcc_test3_LL_case_forDataRowX_END(_ID_, _DESCRIPTION_, _TMPROW_T_, _FN_, _ARRAY_)\
	} while(0);

/* --- --- --- --- */
/* --- --- --- --- */
/* --- --- --- --- */

#define xcc_test3_DATAROW3_DECLT(TYPE_P1, TYPE_P2, TYPE_P3) \
	struct DATAROW_T##__LINE__ { \
		const char* row_id;\
		TYPE_P1 param1;\
		TYPE_P2 param2;\
		TYPE_P3 param3;\
	} 


#define xcc_test3_DATAROW3_ITZ_T(TYPE, ID, P1, P2, P3) { \
	  (ID) \
	, (P1) \
	, (P2) \
	, (P3) \
}

#define xcc_test3_case_forDataRow3(_ID_, _DESCRIPTION_, _TMPROW_T_, _FN_, _ARRAY_) do {\
			xcc_test3_LL_case_forDataRowX_START(_ID_, _DESCRIPTION_, _TMPROW_T_, _FN_, _ARRAY_)\
				  (xcc_test2_tmp_tmprow_##__LINE__)->param1\
				, (xcc_test2_tmp_tmprow_##__LINE__)->param2\
				, (xcc_test2_tmp_tmprow_##__LINE__)->param3\
			xcc_test3_LL_case_forDataRowX_END(_ID_, _DESCRIPTION_, _TMPROW_T_, _FN_, _ARRAY_)\
	} while(0);

/* --- --- --- --- */
/* --- --- --- --- */
/* --- --- --- --- */

#define xcc_test3_DATAROW4_DECLT(TYPE_P1, TYPE_P2, TYPE_P3, TYPE_P4) \
	struct { \
		const char* row_id;\
		TYPE_P1 param1;\
		TYPE_P2 param2;\
		TYPE_P3 param3;\
		TYPE_P4 param4;\
	} 


#define xcc_test3_DATAROW4_ITZ_T(TYPE, ID, P1, P2, P3, P4) { \
	  (ID) \
	, (P1) \
	, (P2) \
	, (P3) \
	, (P4) \
}

#define xcc_test3_case_forDataRow4(_ID_, _DESCRIPTION_, _TMPROW_T_, _FN_, _ARRAY_) do {\
			xcc_test3_LL_case_forDataRowX_START(_ID_, _DESCRIPTION_, _TMPROW_T_, _FN_, _ARRAY_)\
			xcc_test2_expect( 0 == _FN_( \
					  (xcc_test2_tmp_tmprow_##__LINE__)->param1\
					, (xcc_test2_tmp_tmprow_##__LINE__)->param2\
					, (xcc_test2_tmp_tmprow_##__LINE__)->param3\
					, (xcc_test2_tmp_tmprow_##__LINE__)->param4\
				)\
			);\
			xcc_test3_LL_case_forDataRowX_END(_ID_, _DESCRIPTION_, _TMPROW_T_, _FN_, _ARRAY_)\
	} while(0);

/* --- --- --- --- */
/* --- --- --- --- */
/* --- --- --- --- */

#define xcc_test3_DATAROW5_DECLT(TYPE_P1, TYPE_P2, TYPE_P3, TYPE_P4, TYPE_P5) \
	struct { \
		const char* row_id;\
		TYPE_P1 param51;\
		TYPE_P2 param52;\
		TYPE_P3 param53;\
		TYPE_P4 param54;\
		TYPE_P5 param55;\
	} 


#define xcc_test3_DATAROW5_ITZ_T(TYPE, ID, P1, P2, P3, P4, P5) { \
	  (ID) \
	, (P1) \
	, (P2) \
	, (P3) \
	, (P4) \
	, (P5) \
}

#define xcc_test3_case_forDataRow5(_ID_, _DESCRIPTION_, _TMPROW_T_, _FN_, _ARRAY_) do {\
			xcc_test3_LL_case_forDataRowX_START(_ID_, _DESCRIPTION_, _TMPROW_T_, _FN_, _ARRAY_)\
			xcc_test2_expect( 0 == _FN_( \
					  (xcc_test2_tmp_tmprow_##__LINE__)->param51\
					, (xcc_test2_tmp_tmprow_##__LINE__)->param52\
					, (xcc_test2_tmp_tmprow_##__LINE__)->param53\
					, (xcc_test2_tmp_tmprow_##__LINE__)->param54\
					, (xcc_test2_tmp_tmprow_##__LINE__)->param55\
				)\
			);\
			xcc_test3_LL_case_forDataRowX_END(_ID_, _DESCRIPTION_, _TMPROW_T_, _FN_, _ARRAY_)\
	} while(0);

/* --- --- --- --- */
/* --- --- --- --- */
/* --- --- --- --- */

#define xcc_test3_DATAROW6_DECLT(TYPE_P1, TYPE_P2, TYPE_P3, TYPE_P4, TYPE_P5, TYPE_P6) \
	struct { \
		const char* row_id;\
		TYPE_P1 param61;\
		TYPE_P2 param62;\
		TYPE_P3 param63;\
		TYPE_P4 param64;\
		TYPE_P5 param65;\
		TYPE_P6 param66;\
	} 

#define xcc_test3_DATAROW6_ITZ_T(TYPE, ID, P1, P2, P3, P4, P5, P6) { \
	  (ID) \
	, (P1) \
	, (P2) \
	, (P3) \
	, (P4) \
	, (P5) \
	, (P6) \
}

#define xcc_test3_case_forDataRow6(_ID_, _DESCRIPTION_, _TMPROW_T_, _FN_, _ARRAY_) do {\
			xcc_test3_LL_case_forDataRowX_START(_ID_, _DESCRIPTION_, _TMPROW_T_, _FN_, _ARRAY_)\
			xcc_test2_expect( 0 == _FN_( \
					  (xcc_test2_tmp_tmprow_##__LINE__)->param61\
					, (xcc_test2_tmp_tmprow_##__LINE__)->param62\
					, (xcc_test2_tmp_tmprow_##__LINE__)->param63\
					, (xcc_test2_tmp_tmprow_##__LINE__)->param64\
					, (xcc_test2_tmp_tmprow_##__LINE__)->param65\
					, (xcc_test2_tmp_tmprow_##__LINE__)->param66\
				)\
			);\
			xcc_test3_LL_case_forDataRowX_END(_ID_, _DESCRIPTION_, _TMPROW_T_, _FN_, _ARRAY_)\
	} while(0);
	
	

/* --- --- --- --- */
/* --- --- --- --- */
/* --- --- --- --- */

#define xcc_test3_DATAROW7_DECLT(TYPE_P1, TYPE_P2, TYPE_P3, TYPE_P4, TYPE_P5, TYPE_P6, TYPE_P7) \
	struct { \
		const char* row_id;\
		TYPE_P1 param71;\
		TYPE_P2 param72;\
		TYPE_P3 param73;\
		TYPE_P4 param74;\
		TYPE_P5 param75;\
		TYPE_P6 param76;\
		TYPE_P7 param77;\
	} 

#define xcc_test3_DATAROW7_ITZ_T(TYPE, ID, P1, P2, P3, P4, P5, P6, P7) { \
	  (ID) \
	, (P1) \
	, (P2) \
	, (P3) \
	, (P4) \
	, (P5) \
	, (P6) \
	, (P7) \
}

#define xcc_test3_case_forDataRow7(_ID_, _DESCRIPTION_, _TMPROW_T_, _FN_, _ARRAY_) do {\
			xcc_test3_LL_case_forDataRowX_START(_ID_, _DESCRIPTION_, _TMPROW_T_, _FN_, _ARRAY_)\
			xcc_test2_expect( 0 == _FN_( \
					  (xcc_test2_tmp_tmprow_##__LINE__)->param71\
					, (xcc_test2_tmp_tmprow_##__LINE__)->param72\
					, (xcc_test2_tmp_tmprow_##__LINE__)->param73\
					, (xcc_test2_tmp_tmprow_##__LINE__)->param74\
					, (xcc_test2_tmp_tmprow_##__LINE__)->param75\
					, (xcc_test2_tmp_tmprow_##__LINE__)->param76\
					, (xcc_test2_tmp_tmprow_##__LINE__)->param77\
				)\
			);\
			xcc_test3_LL_case_forDataRowX_END(_ID_, _DESCRIPTION_, _TMPROW_T_, _FN_, _ARRAY_)\
	} while(0);
	
/* --- --- --- --- */
/* --- --- --- --- */
/* --- --- --- --- */

#define xcc_test3_DATAROW8_DECLT(TYPE_P1, TYPE_P2, TYPE_P3, TYPE_P4, TYPE_P5, TYPE_P6, TYPE_P7, TYPE_P8) \
	struct { \
		const char* row_id;\
		TYPE_P1 param81;\
		TYPE_P2 param82;\
		TYPE_P3 param83;\
		TYPE_P4 param84;\
		TYPE_P5 param85;\
		TYPE_P6 param86;\
		TYPE_P7 param87;\
		TYPE_P8 param88;\
	} 

#define xcc_test3_DATAROW8_ITZ_T(TYPE, ID, P1, P2, P3, P4, P5, P6, P7, P8) { \
	  (ID) \
	, (P1) \
	, (P2) \
	, (P3) \
	, (P4) \
	, (P5) \
	, (P6) \
	, (P7) \
	, (P8) \
}

#define xcc_test3_case_forDataRow8(_ID_, _DESCRIPTION_, _TMPROW_T_, _FN_, _ARRAY_) do {\
			xcc_test3_LL_case_forDataRowX_START(_ID_, _DESCRIPTION_, _TMPROW_T_, _FN_, _ARRAY_)\
			xcc_test2_expect( 0 == _FN_( \
					  (xcc_test2_tmp_tmprow_##__LINE__)->param81\
					, (xcc_test2_tmp_tmprow_##__LINE__)->param82\
					, (xcc_test2_tmp_tmprow_##__LINE__)->param83\
					, (xcc_test2_tmp_tmprow_##__LINE__)->param84\
					, (xcc_test2_tmp_tmprow_##__LINE__)->param85\
					, (xcc_test2_tmp_tmprow_##__LINE__)->param86\
					, (xcc_test2_tmp_tmprow_##__LINE__)->param87\
					, (xcc_test2_tmp_tmprow_##__LINE__)->param88\
				)\
			);\
			xcc_test3_LL_case_forDataRowX_END(_ID_, _DESCRIPTION_, _TMPROW_T_, _FN_, _ARRAY_)\
	} while(0);
	
/* --- --- --- --- */
/* --- --- --- --- */
/* --- --- --- --- */

#endif
