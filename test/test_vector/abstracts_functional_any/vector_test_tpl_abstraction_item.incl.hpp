/*
 * Copyright block:
 *
 * Source file of libxccc project
 *
 * Copyright (c) 2019 Jakub Skrzyniarz, skrzj-dev@protonmail.com
 *
 * Licensed under: MIT license; See the file "LICENSE" of libxccc project for more information.
 *
 * Copyright block: end
 */

#include <xc/common/xc_mem.h>
#include <xcc/common/xcc_err.hpp>

xcc_tplTestVector_itemIntf_obj1_hdr()
xcc_tplTestVector_itemIntf_obj1_method(_ARG_TPL_VITEMTYPE_) item_obj(const int int_value, const char* str_value) noexcept
{
	_ARG_TPL_VITEMTYPE_ retv={0};
	xcc_err_decl();
	
	try
	{
		retv.val_int=int_value;
		snprintf(retv.val_str, sizeof(retv.val_str), "%s", str_value);
		return retv;
	}
	catch(...)
	{
		xcc_err_handle();
		return retv;
	}
}


xcc_tplTestVector_itemIntf_obj1_hdr()
xcc_tplTestVector_itemIntf_obj1_method(_ARG_TPL_VITEMTYPE_) item_val(const int int_value) noexcept
{
	_ARG_TPL_VITEMTYPE_ retv=0;
	xcc_err_decl();
	
	try
	{
		retv=int_value;
		return retv;
	}
	catch(...)
	{
		xcc_err_handle();
		return retv;
	}
}



xcc_tplTestVector_itemIntf_obj1_hdr()
xcc_tplTestVector_itemIntf_obj1_method(int) item_eq(const _ARG_TPL_VITEMTYPE_* refp_item_1, const _ARG_TPL_VITEMTYPE_* refp_item_2) noexcept
{
	xcc_err_decl();
	
	try
	{
		if(NULL == refp_item_1) {
			xcc_err_term_unmg();
		}
		if(NULL == refp_item_2) {
			xcc_err_term_unmg();
		}
		
		if( 0 == xc_mem_u_cmp_obj(_ARG_TPL_VITEMTYPE_, refp_item_1, refp_item_2) ) {
			return 1;
		}
		else {
			return 0;
		}
		
	}
	catch(...)
	{
		xcc_err_handle();
		return 0;
	}
}

template<typename TPL_ITEMTYPE, size_t TPL_SIZE>
std::vector<TPL_ITEMTYPE> TEST_ARRAY2VEC(const std::array<TPL_ITEMTYPE, TPL_SIZE>& arg_array)
{
	std::vector<TPL_ITEMTYPE> expected_items=std::vector<TPL_ITEMTYPE>(arg_array.data(), arg_array.data()+arg_array.size() );
	
	return expected_items;
}
