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

#ifndef _TEST_STRINGCS_INTERNAL_HPP_
#define _TEST_STRINGCS_INTERNAL_HPP_

#include "xcc/test/xcc_test2.hpp"
#include "xcc/common/xcc_cpp.hpp"

/* -- */
#include "xcc/common/xcc_err.hpp"
#include "xc/common/xc_strcs.h"

#include "test_strcs_functional_abstracts.hpp"
#include "test_strcs_implement_intf_xcstrcs.hpp"
#include "test_strcs_implement_tpl_insts.hpp"

#include "test_strcs_functional_abstracts_main.hpp"


extern test_xcStringS_testStaticStr<xc_strcs_t> TEST_STATICSTR_cstrd;

extern test_xcStringS_param_I_initNonEmpty_t TESTPARAM_INIT_NONEMPTY_I_cstrd;
extern test_xcStringS_param_I_initEmpty_t TESTPARAM_INIT_EMPTY_I_cstrd;
extern test_xcStringS_param_I_null_t TESTPARAM_UNINIT_NULL_I_cstrd;
extern test_xcStringS_param_I_uninitZero_t TESTPARAM_UNINIT_ZERO_I_cstrd;
extern test_xcStringS_param_I_uninitNonZero_t TESTPARAM_UNINIT_NONZERO_I_cstrd;

extern test_xcStringS_param_I_Set_t TESTPARAMSET_I_cstrd;

#endif
