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

#ifndef TEST_XCSTRINGD_IMPLEMENTATION_TPL_INSTANCES_HPP
#define TEST_XCSTRINGD_IMPLEMENTATION_TPL_INSTANCES_HPP

#include "test_strcs_implement_tpl_param_intfs.hpp"

typedef test_xcStringS_param_I_initNonEmpty_tplt<xc_strcs_t> test_xcStringS_param_I_initNonEmpty_t;
typedef test_xcStringS_param_I_initEmpty_tplt<xc_strcs_t> test_xcStringS_param_I_initEmpty_t;
typedef test_xcStringS_param_I_null_tplt<xc_strcs_t> test_xcStringS_param_I_null_t;
typedef test_xcStringS_param_I_uninitZero_tplt<xc_strcs_t> test_xcStringS_param_I_uninitZero_t;
typedef test_xcStringS_param_I_uninitNonZero_tplt<xc_strcs_t> test_xcStringS_param_I_uninitNonZero_t;

typedef test_xcStringS_param_I_Set_tplt<xc_strcs_t> test_xcStringS_param_I_Set_t;

#endif
