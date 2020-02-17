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


