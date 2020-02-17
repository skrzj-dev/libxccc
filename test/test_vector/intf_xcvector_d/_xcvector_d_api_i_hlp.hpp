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

#ifndef __XCC_TEST_TPL_VECTOR___CCCVECTOR_DS_API_I_HLP_HPP__
#define __XCC_TEST_TPL_VECTOR___CCCVECTOR_DS_API_I_HLP_HPP__

#include "xc/tcvector_d/xc_tcvector_d.h"
#include "abstracts_functional_any/vector_test_tpl_abstraction_item.hpp"

typedef xc_tcVectorD_declt(dummyItem_t) seq_dummyItem_t;
xc_tcVectorD_i_global_declt_instI(seq_dummyItem_t, dummyItem_t);
xc_tcVectorD_i_global_extern_instI(seq_dummyItem_t, dummyItem_t);

#endif
