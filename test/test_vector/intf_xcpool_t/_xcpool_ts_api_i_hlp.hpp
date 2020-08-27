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

#ifndef __XCC_TEST_TPL_VECTOR___CPOOL_TS_API_I_HLP_HPP__
#define __XCC_TEST_TPL_VECTOR___CPOOL_TS_API_I_HLP_HPP__

#include "xc/tcpool_t/xc_tcpool_t.h"
#include "abstracts_functional_any/vector_test_tpl_abstraction_item.hpp"

typedef xc_tcPoolT_declt(dummyItem_t, 8) xcPoolTS_dummyItem_t;


xc_tcPoolT_i_global_declt_instI(xcPoolTS_dummyItem_t, dummyItem_t);

xc_tcPoolT_i_global_extern_instI(xcPoolTS_dummyItem_t, dummyItem_t);


#endif
