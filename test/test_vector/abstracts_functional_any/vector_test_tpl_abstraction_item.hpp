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

#ifndef _XCC_VECTOR_TEST_TPL_ABSTRACTION_ITEM_HPP_
#define _XCC_VECTOR_TEST_TPL_ABSTRACTION_ITEM_HPP_

#include <vector>
#include <array>

#define xcc_tplTestVector_itemIntf_obj1_hdr() template< typename _ARG_TPL_VITEMTYPE_ >
#define xcc_tplTestVector_itemIntf_obj1_method(TYPE) TYPE xcc_tplTestVector_itemIntf_obj1< _ARG_TPL_VITEMTYPE_ >::

xcc_tplTestVector_itemIntf_obj1_hdr()
class xcc_tplTestVector_itemIntf_obj1
{
	public: static _ARG_TPL_VITEMTYPE_ item_obj(const int int_value, const char* str_value) noexcept;
	public: static _ARG_TPL_VITEMTYPE_ item_val(const int int_value) noexcept;
	public: static int item_eq(const _ARG_TPL_VITEMTYPE_* refp_item_1, const _ARG_TPL_VITEMTYPE_* refp_item_2) noexcept;
};


typedef struct dummyItem_t
{
	int val_int;
	char val_str[16];
} dummyItem_t;

template<typename TPL_ITEMTYPE, size_t TPL_SIZE>
std::vector<TPL_ITEMTYPE> TEST_ARRAY2VEC(const std::array<TPL_ITEMTYPE, TPL_SIZE>& arg_array);

#include "vector_test_tpl_abstraction_item.incl.hpp"


#endif
