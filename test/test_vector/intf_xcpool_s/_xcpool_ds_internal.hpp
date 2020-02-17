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

#ifndef _XCC_TEST_TPL_VECTOR___CPOOL_DS_INTERNAL_HPP_
#define _XCC_TEST_TPL_VECTOR___CPOOL_DS_INTERNAL_HPP_


#define testIntf_internal_xcVectorDS__hdr() template<typename TPL_VTYPE, typename _ARG_TPL_VITEMTYPE_, typename ARG_TPL_DEREFER, class _TPL_LLII_>
#define testIntf_internal_xcVectorDS__method(TYPE) TYPE testIntf_internal_xcPoolDS_intf<TPL_VTYPE, _ARG_TPL_VITEMTYPE_, ARG_TPL_DEREFER, _TPL_LLII_>::

testIntf_internal_xcVectorDS__hdr()
class testIntf_internal_xcPoolDS_intf
{
	public: int verifyInternalState_itemsNumbers(TPL_VTYPE* refp_self, const int expected_capacity, const int expected_length) noexcept;
	public: int verifyInternalState_itemsIntegrity(TPL_VTYPE* refp_self, const int expected_capacity, const int expected_length) noexcept;
	public: int verifyInternalState_itemsValues(TPL_VTYPE* refp_self, const int expected_capacity, const int expected_length, std::vector<_ARG_TPL_VITEMTYPE_>& refp_expected_item_order) noexcept;
	public: int verifyInternalState_2vectors_same(TPL_VTYPE* refp_self, const TPL_VTYPE* refp_2nd) noexcept;
	
	public: int hack_forceSmallerCapacity(TPL_VTYPE* refp_self,  const size_t expected_static_capacity) noexcept;
};

#include "_xcpool_ds_internal.incl.hpp"

#endif
