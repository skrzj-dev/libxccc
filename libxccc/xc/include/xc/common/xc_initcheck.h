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

#ifndef _XC_INITCHECK_H_
#define _XC_INITCHECK_H_

/* --- --- --- */
#ifdef __cplusplus
extern "C" {
#endif
/* --- --- --- */

typedef struct xc_initc_anyscopeNZ_t
{
	
	int values[4];
	
} xc_initc_anyscopeNZ_t;


int xc_initc_anyscopeNZ_isValid_c(const xc_initc_anyscopeNZ_t* refp_target, const int baseIntegerVal);


#define xc_initc_anyscopeNZ_isValid_u(_REFP_TARGET_, _BASEINTEGER_VALUE_) (\
	   ( (_BASEINTEGER_VALUE_)+1 == (_REFP_TARGET_)->values[0] )\
	&& ( (_BASEINTEGER_VALUE_)+2 == (_REFP_TARGET_)->values[1] )\
	&& ( (_BASEINTEGER_VALUE_)+3 == (_REFP_TARGET_)->values[2] )\
	&& ( (_BASEINTEGER_VALUE_)+4 == (_REFP_TARGET_)->values[3] )\
)


int xc_initc_anyscopeNZ_init_c(xc_initc_anyscopeNZ_t* refp_target, const int baseIntegerVal);

/* --- --- --- */
#ifdef __cplusplus
}
#endif
/* --- --- --- */

#endif
