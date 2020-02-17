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

#ifndef _XCC_TEST_TPL_VECTOR___CCCVECTOR_ST_API_I_HLP_HPP_
#define _XCC_TEST_TPL_VECTOR___CCCVECTOR_ST_API_I_HLP_HPP_

#include "xc/tcvector_t/xc_tcvector_t.h"

#include "abstracts_functional_any/vector_test_tpl_abstraction_item.hpp"

typedef xc_tcVectorT_declt(dummyItem_t, 8) seqST_dummyItem_t;

xc_tcVectorT_i_global_declt_instI(seqST_dummyItem_t, dummyItem_t);

xc_tcVectorT_i_global_extern_instI(seqST_dummyItem_t, dummyItem_t);

#endif
