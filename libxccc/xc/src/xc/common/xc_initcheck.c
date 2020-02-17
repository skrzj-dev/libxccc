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

/* --- */
#include <stddef.h>
#include "xc/common/xc_initcheck.h"
/* --- */

int xc_initc_anyscopeNZ_isValid_c(const xc_initc_anyscopeNZ_t* refp_target, const int baseIntegerVal)
{
	if( NULL ==  refp_target ) {
		return 1;
	}
	
	return xc_initc_anyscopeNZ_isValid_u(refp_target, baseIntegerVal);
}


int xc_initc_anyscopeNZ_init_c(xc_initc_anyscopeNZ_t* refp_target, const int baseIntegerVal)
{
	if(NULL  == refp_target )  {
		return 1;
	}
	
	refp_target->values[0]=baseIntegerVal+1;
	refp_target->values[1]=baseIntegerVal+2;
	refp_target->values[2]=baseIntegerVal+3;
	refp_target->values[3]=baseIntegerVal+4;
	
	return 0;
}
