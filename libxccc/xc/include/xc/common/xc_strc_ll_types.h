#ifndef _XC_STRC_LL_TYPES_H_
#define _XC_STRC_LL_TYPES_H_

/* --- --- --- */
/* --- --- --- */
/* --- --- --- */

typedef struct xc_strcLiteral_t
{
	const int valid;
	const char* const d_buf;
} xc_strcLiteral_t;

#define xc_strcLiteral_ITZ(_ARG_LITERAL_STR_) { 1 , (_ARG_LITERAL_STR_) }

/* --- --- --- */
/* --- --- --- */
/* --- --- --- */

typedef struct xc_strcRO_t
{
	int ro_len;
	const char* ro_buf;
	
} xc_strcRO_t;

#define xc_strcRO_LL_SET(_ARG_TARGET_REFP_, _ARG_LENGTH_, _ARG_BUF_) do {\
	(_ARG_TARGET_REFP_)->ro_len=(_ARG_LENGTH_);\
	(_ARG_TARGET_REFP_)->ro_buf=(_ARG_BUF_);\
}\
while(0);


#define xc_strcRO_isInvalid(_ARG_REFP_OBJ_) ( (_ARG_REFP_OBJ_)->ro_len<0 || NULL == (_ARG_REFP_OBJ_)->ro_buf )

/* --- --- --- */
/* --- --- --- */
/* --- --- --- */

typedef struct xc_strcRW_t
{
	int rw_len;
	char* rw_buf;
	
} xc_strcRW_t;


#define xc_strcRW_LL_SET(_ARG_TARGET_REFP_, _ARG_LENGTH_, _ARG_BUF_) do {\
	(_ARG_TARGET_REFP_)->rw_len=(_ARG_LENGTH_);\
	(_ARG_TARGET_REFP_)->rw_buf=(_ARG_BUF_);\
}\
while(0);

#define xc_strcRW_isInvalid(_ARG_REFP_OBJ_) ( (_ARG_REFP_OBJ_)->rw_len<0 || NULL == (_ARG_REFP_OBJ_)->rw_buf )

/* --- --- --- */
/* --- --- --- */
/* --- --- --- */

typedef struct xc_strcRWS_t
{
	size_t rws_capacity;
	int rws_len;
	char* rws_buf;
	int rws_overflow;
	
} xc_strcRWS_t;

/* --- --- --- */
/* --- --- --- */
/* --- --- --- */

typedef struct xc_strc_subStrInfo_t
{
	int off;
	int len;
	
} xc_strc_subStrInfo_t;

#define xc_strc_subStrInfo_isInvalid(_ARG_REFP_OBJ_) ( \
	( (_ARG_REFP_OBJ_)->off < 0 ) \
	|| \
	( (_ARG_REFP_OBJ_)->len < 0 ) \
)

#define xc_strc_subStrInfo_ITZ_empty() {-1, -1}

/* --- --- --- */
/* --- --- --- */
/* --- --- --- */

#endif