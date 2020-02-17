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
#include "xc/common/xc_mem.h"
/* --- */


int xc_mem_realloc_safe_LL(void** refp_target_ptr, const size_t new_bytesize)
{
	void* target_ptr=NULL;
	void* target_ptr_tmp=NULL;
	
	if(NULL == refp_target_ptr) {
		goto L_ERR_UNMG;
	}
	if(0==new_bytesize) {
		goto L_ERR_UNMG;
	}
	
	target_ptr=*refp_target_ptr;
	
	if(NULL==target_ptr)
	{
		if(NULL == (target_ptr_tmp=malloc(new_bytesize) ) ) {
			goto L_ERR_UNMG;
		}
		target_ptr=target_ptr_tmp;
	}
	else
	{
		
		if(NULL == (target_ptr_tmp=realloc(target_ptr, new_bytesize) ) ) {
			goto L_ERR_UNMG;
		}
		target_ptr=target_ptr_tmp;
	}
	
	*refp_target_ptr=target_ptr;
	
	return 0;
	
	L_ERR_UNMG:
	return 1;
}


void xc_mem_free_safe_LL(void** refp_to_target_ptr)
{
	void* referred_ptr=*refp_to_target_ptr;
	free(referred_ptr);
	*refp_to_target_ptr=NULL;
	return;
}
