#ifndef _XC_SI_TEST_IMPL_SIGNED_HPP_
#define _XC_SI_TEST_IMPL_SIGNED_HPP_

#include "test_xc_si_abstracts.hpp"
/* --- */
#include "xc/common/xc_si.h"
/* --- */


template<typename TPL_PRIMITIVE, typename TPL_XCTYPE>
class test_si_infOp_int: public test_si_infOp_abstract<TPL_PRIMITIVE, TPL_XCTYPE>
{
	public: TPL_XCTYPE ADD(TPL_XCTYPE arg1, TPL_XCTYPE arg2)
	{
		TPL_XCTYPE retv;
		retv=xc_si_int_add(arg1, arg2);
		return retv;
	}
	public: TPL_XCTYPE SUB(TPL_XCTYPE arg1, TPL_XCTYPE arg2)
	{
		TPL_XCTYPE retv;
		retv=xc_si_int_sub(arg1, arg2);
		return retv;
	}
	public: TPL_XCTYPE MUL(TPL_XCTYPE arg1, TPL_XCTYPE arg2)
	{
		TPL_XCTYPE retv;
		retv=xc_si_int_mul(arg1, arg2);
		return retv;
	}
	public: TPL_XCTYPE DIV(TPL_XCTYPE arg1, TPL_XCTYPE arg2)
	{
		TPL_XCTYPE retv;
		retv=xc_si_int_div(arg1, arg2);
		return retv;
	}
	public: TPL_XCTYPE FROMVAL(const TPL_PRIMITIVE arg1)
	{
		TPL_XCTYPE retv;
		retv=xc_si_int_v(arg1);
		return retv;
	}
};

#endif
