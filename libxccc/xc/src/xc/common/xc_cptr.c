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
#include "xc/common/xc_cptr.h"
/* --- */


xc_p_pBytes_t xc_p_pBytes_from_raw(unsigned char* target)
{
	xc_p_pBytes_t retv={0};
	retv.BtPtr=target;
	return retv;
}


xc_p_pBytes_t xc_p_pBytes_from_ref2pBytes(xc_p_refp2pBytes_t refp_src)
{
	xc_p_pBytes_t retv={0};
	retv.BtPtr=refp_src.Refp2BtPtr[0];
	return retv;
}


xc_p_pBytesConst_t xc_ptr_pBytesConst_from_ref2pBytesConst(xc_p_refp2pBytesConst_t refp_src)
{
	xc_p_pBytesConst_t retv={0};
	retv.BtPtr=refp_src.Refp2BtPtr[0];
	return retv;
}


int xc_p_refp2pBytes_assign_pBytes(xc_p_refp2pBytes_t* refp_target, xc_p_pBytes_t refp_src)
{
	*refp_target->Refp2BtPtr=refp_src.BtPtr;
	return 0;
}


xc_p_refp2pBytes_t xc_p_refp2pBytes_from_raw(unsigned char** target)
{
	xc_p_refp2pBytes_t retv={0};
	retv.Refp2BtPtr=target;
	return retv;
}

