#include "xcc/test/xcc_test2.hpp"
#include "xcc/common/xcc_cpp.hpp"
/* -- */
#include "test_strcs.hpp"
#include "test_strcs_functional_abstracts.hpp"

#include "test_strcs_implement_intf_xcstrcs.hpp"
/* -- */

int test_xcStringS_all(xcc_test2_param_list) noexcept;

int test_xcStringS_all(xcc_test2_param_list) noexcept
{
	xcc_test2_scope("[test xc_strCS]");
	
	/* --- --- --- --- */
	xcc_test2_expect( 0 == TEST_STATICSTR_cstrd.test_sanity( xcc_test2_param_internal_embedded() ) );
	/* --- --- --- --- */
	
	/* --- --- --- --- */
	/* --- operations modifying string object state: --- */
	/* --- --- --- --- */
	xcc_test2_expect( 0 == TEST_STATICSTR_cstrd.test_init_obj_immutable( xcc_test2_param_internal_embedded() ) );
	xcc_test2_expect( 0 == TEST_STATICSTR_cstrd.test_initCstr_immutable( xcc_test2_param_internal_embedded() ) );
	xcc_test2_expect( 0 == TEST_STATICSTR_cstrd.test_initFmt_immutable( xcc_test2_param_internal_embedded() ) );
	
	xcc_test2_expect( 0 == TEST_STATICSTR_cstrd.test_substrInit_Immutable( xcc_test2_param_internal_embedded() ) );
	/* --- --- --- --- */
	/* --- operations modifying string object state: done --- */
	/* --- --- --- --- */
	
	/* --- --- --- --- */
	/* --- operations read- only to string object state: --- */
	/* --- --- --- --- */
	xcc_test2_expect( 0 == TEST_STATICSTR_cstrd.test_cmpEq_CaseInSensitive( xcc_test2_param_internal_embedded() ) );
	xcc_test2_expect( 0 == TEST_STATICSTR_cstrd.test_cmpEq_CaseSensitive( xcc_test2_param_internal_embedded() ) );

	xcc_test2_expect( 0 == TEST_STATICSTR_cstrd.test_containsObj_caseSensitive( xcc_test2_param_internal_embedded() ) );
	xcc_test2_expect( 0 == TEST_STATICSTR_cstrd.test_containsObj_caseInSensitive( xcc_test2_param_internal_embedded() ) );
	xcc_test2_expect( 0 == TEST_STATICSTR_cstrd.test_containsCstr_caseSensitive( xcc_test2_param_internal_embedded() ) );
	xcc_test2_expect( 0 == TEST_STATICSTR_cstrd.test_containsCstr_caseInSensitive( xcc_test2_param_internal_embedded() ) );
	
	xcc_test2_expect( 0 == TEST_STATICSTR_cstrd.test_startsWithObj_caseSensitive( xcc_test2_param_internal_embedded() ) );
	xcc_test2_expect( 0 == TEST_STATICSTR_cstrd.test_startsWithObj_caseInSensitive( xcc_test2_param_internal_embedded() ) );
	xcc_test2_expect( 0 == TEST_STATICSTR_cstrd.test_startsWithCstr_caseSensitive( xcc_test2_param_internal_embedded() ) );
	xcc_test2_expect( 0 == TEST_STATICSTR_cstrd.test_startsWithCstr_caseInSensitive( xcc_test2_param_internal_embedded() ) );
	
	xcc_test2_expect( 0 == TEST_STATICSTR_cstrd.test_EndsWithObj_caseSensitive( xcc_test2_param_internal_embedded() ) );
	xcc_test2_expect( 0 == TEST_STATICSTR_cstrd.test_EndsWithObj_caseInSensitive( xcc_test2_param_internal_embedded() ) );
	xcc_test2_expect( 0 == TEST_STATICSTR_cstrd.test_EndsWithCstr_caseSensitive( xcc_test2_param_internal_embedded() ) );
	xcc_test2_expect( 0 == TEST_STATICSTR_cstrd.test_EndsWithCstr_caseInSensitive( xcc_test2_param_internal_embedded() ) );
	
	xcc_test2_expect( 0 == TEST_STATICSTR_cstrd.test_findNextObj_caseSensitive( xcc_test2_param_internal_embedded() ) );
	xcc_test2_expect( 0 == TEST_STATICSTR_cstrd.test_findNextObj_caseInSensitive( xcc_test2_param_internal_embedded() ) );
	xcc_test2_expect( 0 == TEST_STATICSTR_cstrd.test_findNextCstr_caseSensitive( xcc_test2_param_internal_embedded() ) );
	xcc_test2_expect( 0 == TEST_STATICSTR_cstrd.test_findNextCstr_caseInSensitive( xcc_test2_param_internal_embedded() ) );
	/* --- --- --- --- */
	/* --- operations read- only to string object state: done --- */
	/* --- --- --- --- */
	
	xcc_test2_scope_end();
}
