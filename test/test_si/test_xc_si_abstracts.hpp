#ifndef _XC_SI_TEST_ABSTRACTS_HPP_
#define _XC_SI_TEST_ABSTRACTS_HPP_

#include "xc/common/xc_si.h"

template<typename TPL_PRIMITIVE, typename TPL_XCTYPE>
class test_si_infOp_abstract
{
	public: virtual TPL_XCTYPE FROMVAL(const TPL_PRIMITIVE arg1)=0;
	public: virtual TPL_XCTYPE ADD(TPL_XCTYPE arg1, TPL_XCTYPE arg2)=0;
	public: virtual TPL_XCTYPE SUB(TPL_XCTYPE arg1, TPL_XCTYPE arg2)=0;
	public: virtual TPL_XCTYPE MUL(TPL_XCTYPE arg1, TPL_XCTYPE arg2)=0;
	public: virtual TPL_XCTYPE DIV(TPL_XCTYPE arg1, TPL_XCTYPE arg2)=0;
};


template<typename TPL_PRIMITIVE, typename TPL_XCTYPE>
struct test_si_param
{
	test_si_param(TPL_XCTYPE result_xctype, TPL_PRIMITIVE expected_primitive, xc_si_retv_t expected_result)
	{
		this->result_xctype=result_xctype;
		this->expected_primitive=expected_primitive;
		this->expected_result=expected_result;
	}
	
	TPL_XCTYPE result_xctype;
	TPL_PRIMITIVE expected_primitive;
	xc_si_retv_t expected_result;
};

template<typename TPL_PRIMITIVE, typename TPL_XCTYPE, class TPL_OP_I>
int test_si_test_verifyState_success(
	  xcc_test2_param_list
	, TPL_XCTYPE VX
	, TPL_XCTYPE VY
	, TPL_XCTYPE VZ
	, TPL_PRIMITIVE x
	, TPL_PRIMITIVE y
	, TPL_PRIMITIVE z
)
{
	xcc_test2_scope("xc_si: TODO");
	
	xcc_test2_expect( x == xc_si_int_val(VX) );
	xcc_test2_expect( 0 == xc_si_isError(VX) );
	
	xcc_test2_expect( y == xc_si_int_val(VY) );
	xcc_test2_expect( 0 == xc_si_isError(VY) );
	
	xcc_test2_expect( z == xc_si_int_val(VZ) );
	xcc_test2_expect( 0 == xc_si_isError(VZ) );
	
	xcc_test2_scope_end();
}

template<typename TPL_PRIMITIVE, typename TPL_XCTYPE, class TPL_OP_I>
int test_si_test_verifyState_any(
	  xcc_test2_param_list
	, const test_si_param<TPL_PRIMITIVE, TPL_XCTYPE> argX
	, const test_si_param<TPL_PRIMITIVE, TPL_XCTYPE> argY
	, const test_si_param<TPL_PRIMITIVE, TPL_XCTYPE> argZ
)
{
	xcc_test2_scope("xc_si: TODO");
	
	xcc_test2_expect( argZ.expected_primitive == xc_si_int_val(argZ.result_xctype) );
	xcc_test2_expect( argZ.expected_result == xc_si_getStatus(argZ.result_xctype) );
	xcc_test2_expect( (argZ.expected_result != xc_si_retv_ok) == xc_si_isError(argZ.result_xctype) );

	xcc_test2_expect( argX.expected_primitive == xc_si_int_val(argX.result_xctype) );
	xcc_test2_expect( argX.expected_result == xc_si_getStatus(argX.result_xctype) );
	xcc_test2_expect( (argX.expected_result != xc_si_retv_ok) == xc_si_isError(argX.result_xctype) );

	xcc_test2_expect( argY.expected_primitive == xc_si_int_val(argY.result_xctype) );
	xcc_test2_expect( argY.expected_result == xc_si_getStatus(argY.result_xctype) );
	xcc_test2_expect( (argY.expected_result != xc_si_retv_ok) == xc_si_isError(argY.result_xctype) );
	
	xcc_test2_scope_end();
}

#endif
