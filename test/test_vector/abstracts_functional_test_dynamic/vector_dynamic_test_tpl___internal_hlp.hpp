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

#include <array>

#define _TMP_VECTOR_INIT(TMP_EXPECTED_ITEM_ARRAY) std::vector<TPL_ITEM_TYPE>(\
		  TMP_EXPECTED_ITEM_ARRAY\
		, TMP_EXPECTED_ITEM_ARRAY + ( sizeof(TMP_EXPECTED_ITEM_ARRAY)/sizeof(TPL_ITEM_TYPE) )\
	)



template<typename TPL_ITEM>
struct TEST_STATE
{
	size_t expected_length;
	size_t expected_capacity;
	std::vector<TPL_ITEM> itemvec;
};

template<typename TPL_ITEM>
TEST_STATE<TPL_ITEM> TEST_STATE_ITZ(const size_t expected_length, const size_t expected_capacity, const std::vector<TPL_ITEM>& vec)
{
	TEST_STATE<TPL_ITEM> retv;
	
	retv.expected_capacity=expected_capacity;
	retv.expected_length=expected_length;
	retv.itemvec=vec;
	
	return retv;
}

#define TEST_STATE_ARRAY(...) { __VA_ARGS__ }

#define TEST_STATE_TMP_01(_TARGET_, _ITEMTYPE_, _EXPECTED_LENGTH_, _EXPECTED_CAPACITY_, _ARRAY_CONTENT_) do {\
	const _ITEMTYPE_ __tmp_array[]=_ARRAY_CONTENT_;\
	const std::vector<_ITEMTYPE_> __vec=std::vector<_ITEMTYPE_>(\
		  __tmp_array \
		, __tmp_array + ( sizeof(__tmp_array)/sizeof(_ITEMTYPE_) )\
	);\
	(_TARGET_)=TEST_STATE_ITZ(\
		  (_EXPECTED_LENGTH_)\
		, (_EXPECTED_CAPACITY_)\
		, __vec\
	);\
} while(0)


template<typename TPL_ITEMTYPE, size_t TPL_SIZE>
struct static_array_dump
{
	TPL_ITEMTYPE array[TPL_SIZE];
};


template<typename TPL_ITEMTYPE, size_t TPL_SIZE>
static_array_dump<TPL_ITEMTYPE, TPL_SIZE> static_array_dump_produce_fromCArray(const TPL_ITEMTYPE* src, const size_t  src_capacity)
{
	size_t capacity=0;
	static_array_dump<TPL_ITEMTYPE, TPL_SIZE> retv=static_array_dump<TPL_ITEMTYPE, TPL_SIZE>();
	
	capacity= ( src_capacity > TPL_SIZE ) ? TPL_SIZE : src_capacity;
	
	xc_mem_bzero_obj_array(TPL_ITEMTYPE, retv.array, TPL_SIZE);
	
	xc_mem_cp_obj_array(TPL_ITEMTYPE, TPL_SIZE, retv.array, src);
	
	return retv;
}
