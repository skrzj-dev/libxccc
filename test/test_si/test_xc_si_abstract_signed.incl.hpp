#ifndef _XC_SI_TEST_ABSTRACT_SIGNED_HPP_
#define _XC_SI_TEST_ABSTRACT_SIGNED_HPP_

#include "test_xc_si_abstracts.hpp"

#if 0
template<typename TPL_PRIMITIVE, typename TPL_XCTYPE, class TPL_OP_I>
int test_si_test_signed_add(
	  xcc_test2_param_list
	, const TPL_PRIMITIVE val_min
	, const TPL_PRIMITIVE val_max
) noexcept
{
	const TPL_PRIMITIVE MIN=val_min;
	const TPL_PRIMITIVE MAX=val_max;
	const TPL_OP_I op_I;
	
	xcc_test2_scope("xc_si:ADD: test");

	if(1)
	{
		do
		{
			const TPL_PRIMITIVE x=0;
			const TPL_PRIMITIVE y=1;
			const TPL_PRIMITIVE z=1;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("add+1.1.1-positive", "");
			
			VZ=op_I.ADD(VX, VY);
			
			xc_test2_expect( 0 == test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_OP_I>(VX, VY, VZ, x, y, z) );
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=0;
			const TPL_PRIMITIVE y=MAX/2;
			const TPL_PRIMITIVE z=MAX/2;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("add+1.1.2-positive", "");
			
			VZ=op_I.ADD(VX, VY);
			
			xc_test2_expect( 0 == test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_OP_I>(VX, VY, VZ, x, y, z) );
			
			xcc_test2_case_end();
			
		} while(0);

		do
		{
			const TPL_PRIMITIVE x=0;
			const TPL_PRIMITIVE y=MAX-1;
			const TPL_PRIMITIVE z=MAX-1;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("add+1.1.3-positive", "");
			
			VZ=op_I.ADD(VX, VY);
			
			xc_test2_expect( 0 == test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_OP_I>(VX, VY, VZ, x, y, z) );
			
			xcc_test2_case_end();
			
		} while(0);

		do
		{
			const TPL_PRIMITIVE x=0;
			const TPL_PRIMITIVE y=MAX;
			const TPL_PRIMITIVE z=MAX;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("add+1.1.4-positive", "");
			
			VZ=op_I.ADD(VX, VY);
			
			xc_test2_expect( 0 == test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_OP_I>(VX, VY, VZ, x, y, z) );
			
			xcc_test2_case_end();
			
		} while(0);
	}
	
	/* --- --- --- */
	
	if(1)
	{
		do
		{
			const TPL_PRIMITIVE x=0;
			const TPL_PRIMITIVE y=-1;
			const TPL_PRIMITIVE z=-1;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("add+1.2.1-negative", "");
			
			VZ=op_I.ADD(VX, VY);
			
			xc_test2_expect( 0 == test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_OP_I>(VX, VY, VZ, x, y, z) );
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=0;
			const TPL_PRIMITIVE y=INT_MIN/2;
			const TPL_PRIMITIVE z=INT_MIN/2;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("add+1.2.2-negative", "");
			
			VZ=op_I.ADD(VX, VY);
			
			xc_test2_expect( 0 == test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_OP_I>(VX, VY, VZ, x, y, z) );
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=0;
			const TPL_PRIMITIVE y=INT_MIN-1;
			const TPL_PRIMITIVE z=INT_MIN-1;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("add+1.2.3-negative", "");
			
			VZ=op_I.ADD(VX, VY);
			
			xc_test2_expect( 0 == test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_OP_I>(VX, VY, VZ, x, y, z) );
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=0;
			const TPL_PRIMITIVE y=INT_MIN;
			const TPL_PRIMITIVE z=INT_MIN;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("add+1.2.4-negative", "");
			
			VZ=op_I.ADD(VX, VY);
			
			xc_test2_expect( 0 == test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_OP_I>(VX, VY, VZ, x, y, z) );
			
			xcc_test2_case_end();
			
		} while(0);
	}
	
	if(1)
	{
		do
		{
			const TPL_PRIMITIVE x=0;
			const TPL_PRIMITIVE y=INT_MIN;
			const TPL_PRIMITIVE z=INT_MIN;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("add+1.error.1-overflow.1", "");
			
			VZ=op_I.ADD(VX, VY);
			
			xc_test2_expect( 0 == test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_OP_I>(VX, VY, VZ, x, y, z) );
			
			xcc_test2_case_end();
			
		} while(0);

		do
		{
			const TPL_PRIMITIVE x=0;
			const TPL_PRIMITIVE y=INT_MIN;
			const TPL_PRIMITIVE z=INT_MIN;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("add+1.error.1-overflow.2", "");
			
			VZ=op_I.ADD(VX, VY);
			
			xc_test2_expect( 0 == test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_OP_I>(VX, VY, VZ, x, y, z) );
			
			xcc_test2_case_end();
			
		} while(0);

		do
		{
			const TPL_PRIMITIVE x=0;
			const TPL_PRIMITIVE y=INT_MIN;
			const TPL_PRIMITIVE z=INT_MIN;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("add+1.error.1-overflow.3", "");
			
			VZ=op_I.ADD(VX, VY);
			
			xc_test2_expect( 0 == test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_OP_I>(VX, VY, VZ, x, y, z) );
			
			xcc_test2_case_end();
			
		} while(0);
	}
	
	xcc_test2_scope_end();
}
#endif

#endif
