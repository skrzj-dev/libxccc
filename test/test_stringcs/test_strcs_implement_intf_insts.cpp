#include "xcc/test/xcc_test2.hpp"
#include "xcc/common/xcc_cpp.hpp"
/* --- */
#include "xc/common/xc_mem_u.h"
#include "xc/common/xc_strd.h"
/* --- */
#include "test_strcs_internal.hpp"
#include "test_strcs_functional_abstracts.hpp"
#include "test_strcs_implement_intf_xcstrcs.hpp"
#include "test_strcs_implement_tpl_insts.hpp"
/* --- */

/* --- --- --- */

test_xcStringS_verify_CalcAlloc_I_01 MYCI=test_xcStringS_verify_CalcAlloc_I_01();

test_xcStringS_I_cstrd<xc_strcs_t> INTF01=test_xcStringS_I_cstrd<xc_strcs_t>();

/* --- --- --- */

test_xcStringS_param_I_initNonEmpty_t TESTPARAM_INIT_NONNEMPTY_I_cstrd=test_xcStringS_param_I_initNonEmpty_t(
	  &MYCI
);
test_xcStringS_param_I_initEmpty_t TESTPARAM_INIT_EMPTY_I_cstrd=test_xcStringS_param_I_initEmpty_t(
	  &MYCI
);
test_xcStringS_param_I_null_t TESTPARAM_UNINIT_NULL_I_cstrd=test_xcStringS_param_I_null_t(
	  &MYCI
);
test_xcStringS_param_I_uninitZero_t TESTPARAM_UNINIT_ZERO_I_cstrd=test_xcStringS_param_I_uninitZero_t(
	  &MYCI
);
test_xcStringS_param_I_uninitNonZero_t TESTPARAM_UNINIT_NONZERO_I_cstrd=test_xcStringS_param_I_uninitNonZero_t(
	  &MYCI
);

test_xcStringS_param_I_Set_t TESTPARAMSET_I_cstrd=test_xcStringS_param_I_Set_t(
	  &TESTPARAM_UNINIT_NULL_I_cstrd
	, &TESTPARAM_UNINIT_ZERO_I_cstrd
	, &TESTPARAM_UNINIT_NONZERO_I_cstrd
	, &TESTPARAM_INIT_EMPTY_I_cstrd
	, &TESTPARAM_INIT_NONNEMPTY_I_cstrd
);

/* --- --- --- */

test_xcStringS_testStaticStr<xc_strcs_t> TEST_STATICSTR_cstrd=test_xcStringS_testStaticStr<xc_strcs_t>(
	  &INTF01
	, &TESTPARAMSET_I_cstrd
);

/* --- --- --- */
