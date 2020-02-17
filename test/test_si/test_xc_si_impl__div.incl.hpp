#ifndef _XC_SI_TEST_INT_DIV_HPP_
#define _XC_SI_TEST_INT_DIV_HPP_

#include "xcc/common/xcc_cpp.hpp"
#include "xcc/test/xcc_test2.hpp"
/* --- */
#include "xc/common/xc_si.h"
/* --- */
#include "test_xc_si_abstracts.hpp"
#include "test_xc_si_impl__signed.incl.hpp"
#include "test_xc_si_abstract_signed.incl.hpp"
/* --- */


template<typename TPL_PRIMITIVE, typename TPL_XCTYPE, class TPL_OP_I>
int test_si_div_positive(
	  xcc_test2_param_list
	, const TPL_PRIMITIVE val_min
	, const TPL_PRIMITIVE val_max
) noexcept
{
	const TPL_PRIMITIVE MIN=val_min;
	const TPL_PRIMITIVE MAX=val_max;
	TPL_OP_I op_I;
	
	xcc_test2_scope("xc_si:DIV(positiveNumbers): test");
	
	if(1)
	{
		do
		{
			const TPL_PRIMITIVE x=0;
			const TPL_PRIMITIVE y=1;
			const TPL_PRIMITIVE z=0;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.1.1-zeros/1", "");
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward, VX, VY, VZ, x, y, z
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=1;
			const TPL_PRIMITIVE y=1;
			const TPL_PRIMITIVE z=1;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.1.2-positive", "");
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward, VX, VY, VZ, x, y, z
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=MAX/2;
			const TPL_PRIMITIVE y=1;
			const TPL_PRIMITIVE z=MAX/2;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.1.3-positive", "");
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward, VX, VY, VZ, x, y, z
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);

		do
		{
			const TPL_PRIMITIVE x=MAX-1;
			const TPL_PRIMITIVE y=1;
			const TPL_PRIMITIVE z=MAX-1;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.1.4-positive", "");
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward, VX, VY, VZ, x, y, z
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);

		do
		{
			const TPL_PRIMITIVE x=MAX;
			const TPL_PRIMITIVE y=1;
			const TPL_PRIMITIVE z=MAX;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.1.5-positive", "");
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward, VX, VY, VZ, x, y, z
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=4;
			const TPL_PRIMITIVE y=1;
			const TPL_PRIMITIVE z=4;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.1.11-positive", "");
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward, VX, VY, VZ, x, y, z
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
	}
	
	if(1)
	{
		do
		{
			const TPL_PRIMITIVE x=0;
			const TPL_PRIMITIVE y=4;
			const TPL_PRIMITIVE z=0;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.2.1-positive", "");
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward, VX, VY, VZ, x, y, z
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=1;
			const TPL_PRIMITIVE y=4;
			const TPL_PRIMITIVE z=0;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.2.2-positive", "");
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward, VX, VY, VZ, x, y, z
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=MAX/2;
			const TPL_PRIMITIVE y=4;
			const TPL_PRIMITIVE z=MAX/2/4;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.2.3-positive", "");
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward, VX, VY, VZ, x, y, z
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=MAX-1;
			const TPL_PRIMITIVE y=4;
			const TPL_PRIMITIVE z=(MAX-1)/4;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.2.4-positive", "");
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward, VX, VY, VZ, x, y, z
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=MAX;
			const TPL_PRIMITIVE y=4;
			const TPL_PRIMITIVE z=(MAX)/4;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.2.5-positive", "");
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward, VX, VY, VZ, x, y, z
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=4;
			const TPL_PRIMITIVE y=4;
			const TPL_PRIMITIVE z=1;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.2.11-positive", "");
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward, VX, VY, VZ, x, y, z
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
	}
	
	if(1)
	{
		do
		{
			const TPL_PRIMITIVE x=0;
			const TPL_PRIMITIVE y=MAX;
			const TPL_PRIMITIVE z=0;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.3.1-positive", "");
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward, VX, VY, VZ, x, y, z
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=1;
			const TPL_PRIMITIVE y=MAX;
			const TPL_PRIMITIVE z=0;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.3.2-positive", "");
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward, VX, VY, VZ, x, y, z
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=MAX/2;
			const TPL_PRIMITIVE y=MAX;
			const TPL_PRIMITIVE z=0;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.3.3-positive", "");
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward, VX, VY, VZ, x, y, z
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=MAX-1;
			const TPL_PRIMITIVE y=MAX;
			const TPL_PRIMITIVE z=0;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.3.4-positive", "");
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward, VX, VY, VZ, x, y, z
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=MAX;
			const TPL_PRIMITIVE y=MAX;
			const TPL_PRIMITIVE z=1;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.3.5-positive", "");
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward, VX, VY, VZ, x, y, z
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=4;
			const TPL_PRIMITIVE y=MAX;
			const TPL_PRIMITIVE z=0;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.3.11-positive", "");
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward, VX, VY, VZ, x, y, z
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
	}

	
	xcc_test2_scope_end();
}


template<typename TPL_PRIMITIVE, typename TPL_XCTYPE, class TPL_OP_I>
int test_si_div_negative(
	  xcc_test2_param_list
	, const TPL_PRIMITIVE val_min
	, const TPL_PRIMITIVE val_max
) noexcept
{
	const TPL_PRIMITIVE MIN=val_min;
	const TPL_PRIMITIVE MAX=val_max;
	TPL_OP_I op_I;
	
	xcc_test2_scope("xc_si:DIV(negativeNumbers): test");
	
	if(1)
	{
		do
		{
			const TPL_PRIMITIVE x=0;
			const TPL_PRIMITIVE y=-1;
			const TPL_PRIMITIVE z=0;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.2.1-negative.a", "TODO");
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward, VX, VY, VZ, x, y, z
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=1;
			const TPL_PRIMITIVE y=-1;
			const TPL_PRIMITIVE z=-1;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.2.1-negative.b", "TODO");
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward, VX, VY, VZ, x, y, z
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=0;
			const TPL_PRIMITIVE y=MIN/2;
			const TPL_PRIMITIVE z=0;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.2.2-negative.a", "");
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward, VX, VY, VZ, x, y, z
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=MIN/2;
			const TPL_PRIMITIVE y=-1;
			const TPL_PRIMITIVE z=-(MIN/2);
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.2.2-negative.b", "");
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward, VX, VY, VZ, x, y, z
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=0;
			const TPL_PRIMITIVE y=(MIN+1);
			const TPL_PRIMITIVE z=0;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.2.3-negative.a", "");
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward, VX, VY, VZ, x, y, z
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=MIN+1;
			const TPL_PRIMITIVE y=-1;
			const TPL_PRIMITIVE z=-(MIN+1);
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.2.3-negative.b", "");
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward, VX, VY, VZ, x, y, z
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=MIN;
			const TPL_PRIMITIVE y=MIN;
			const TPL_PRIMITIVE z=1;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.2.4-negative", "");
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward, VX, VY, VZ, x, y, z
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
	}
	
	xcc_test2_scope_end();
}


template<typename TPL_PRIMITIVE, typename TPL_XCTYPE, class TPL_OP_I>
int test_si_div_signAgnostic_errors(
	  xcc_test2_param_list
	, const TPL_PRIMITIVE val_min
	, const TPL_PRIMITIVE val_max
) noexcept
{
	const TPL_PRIMITIVE MIN=val_min;
	const TPL_PRIMITIVE MAX=val_max;
	TPL_OP_I op_I;
	
	xcc_test2_scope("xc_si:DIV(signAgnostic Errors): test");
	
	if(1)
	{
		do
		{
			const TPL_PRIMITIVE x=MAX;
			const TPL_PRIMITIVE y=0;
			const TPL_PRIMITIVE z=0;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.error.1-divbyzero.1.a", "");
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_any<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VX, x, xc_si_retv_ok)
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VY, y, xc_si_retv_ok)
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VZ, z, xc_si_retv_divByZero)
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=0;
			const TPL_PRIMITIVE y=0;
			const TPL_PRIMITIVE z=0;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.error.1-divbyzero.1.b", "");
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_any<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VX, x, xc_si_retv_ok)
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VY, y, xc_si_retv_ok)
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VZ, z, xc_si_retv_divByZero)
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
	}
	
	if(1)
	{

		do
		{
			const TPL_PRIMITIVE x=0;
			const TPL_PRIMITIVE y=0;
			const TPL_PRIMITIVE z=0;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.error.1-overflow.10.a", "");
			
			/* prepare params: */
			if(1)
			{
				VX=op_I.FROMVAL(MAX);
				VX=op_I.ADD(VX, op_I.FROMVAL(1) );
				xcc_test2_expect( xc_si_retv_overflow == xc_si_getStatus(VX) );
				xcc_test2_expect( 0 != xc_si_isError(VX) );
				xcc_test2_expect( 0 == xc_si_val(VX) );
			}
			/* prepare params: done */
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_any<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VX, x, xc_si_retv_overflow)
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VY, y, xc_si_retv_ok)
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VZ, z, xc_si_retv_overflow)
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=0;
			const TPL_PRIMITIVE y=0;
			const TPL_PRIMITIVE z=0;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.error.1-overflow.10.b", "");
			
			/* prepare params: */
			if(1)
			{
				VY=op_I.FROMVAL(MAX);
				VY=op_I.ADD(VY, op_I.FROMVAL(1) );
				xcc_test2_expect( xc_si_retv_overflow == xc_si_getStatus(VY) );
				xcc_test2_expect( 0 != xc_si_isError(VY) );
				xcc_test2_expect( 0 == xc_si_val(VY) );
			}
			/* prepare params: done */
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_any<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VX, x, xc_si_retv_ok)
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VY, y, xc_si_retv_overflow)
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VZ, z, xc_si_retv_overflow)
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=0;
			const TPL_PRIMITIVE y=0;
			const TPL_PRIMITIVE z=0;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.error.1-overflow.10.c", "");
			
			/* prepare params: */
			if(1)
			{
				VX=op_I.FROMVAL(MAX);
				VX=op_I.ADD(VX, op_I.FROMVAL(1) );
				xcc_test2_expect( xc_si_retv_overflow == xc_si_getStatus(VX) );
				xcc_test2_expect( 0 != xc_si_isError(VX) );
				xcc_test2_expect( 0 == xc_si_val(VX) );
			}
			if(1)
			{
				VY=op_I.FROMVAL(MAX);
				VY=op_I.ADD(VY, op_I.FROMVAL(1) );
				xcc_test2_expect( xc_si_retv_overflow == xc_si_getStatus(VY) );
				xcc_test2_expect( 0 != xc_si_isError(VY) );
				xcc_test2_expect( 0 == xc_si_val(VY) );
			}
			/* prepare params: done */
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_any<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VX, x, xc_si_retv_overflow)
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VY, y, xc_si_retv_overflow)
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VZ, z, xc_si_retv_overflow)
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
	}
	
	if(1)
	{
		
		do
		{
			const TPL_PRIMITIVE x=0;
			const TPL_PRIMITIVE y=0;
			const TPL_PRIMITIVE z=0;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.error.1-underflow.10.a", "");
			
			/* prepare params: */
			if(1)
			{
				VX=op_I.FROMVAL(MIN);
				VX=op_I.SUB(VX, op_I.FROMVAL(1) );
				xcc_test2_expect( xc_si_retv_underflow == xc_si_getStatus(VX) );
				xcc_test2_expect( 0 != xc_si_isError(VX) );
				xcc_test2_expect( 0 == xc_si_val(VX) );
			}
			/* prepare params: done */
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_any<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VX, x, xc_si_retv_underflow)
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VY, y, xc_si_retv_ok)
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VZ, z, xc_si_retv_underflow)
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=0;
			const TPL_PRIMITIVE y=0;
			const TPL_PRIMITIVE z=0;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.error.1-underflow.10.b", "");
			
			/* prepare params: */
			if(1)
			{
				VY=op_I.FROMVAL(MIN);
				VY=op_I.SUB(VY, op_I.FROMVAL(1) );
				xcc_test2_expect( xc_si_retv_underflow == xc_si_getStatus(VY) );
				xcc_test2_expect( 0 != xc_si_isError(VY) );
				xcc_test2_expect( 0 == xc_si_val(VY) );
			}
			/* prepare params: done */
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_any<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VX, x, xc_si_retv_ok)
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VY, y, xc_si_retv_underflow)
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VZ, z, xc_si_retv_underflow)
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=0;
			const TPL_PRIMITIVE y=0;
			const TPL_PRIMITIVE z=0;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("div+1.error.1-underflow.10.c", "");
			
			/* prepare params: */
			if(1)
			{
				VX=op_I.FROMVAL(MIN);
				VX=op_I.SUB(VX, op_I.FROMVAL(1) );
				xcc_test2_expect( xc_si_retv_underflow == xc_si_getStatus(VX) );
				xcc_test2_expect( 0 != xc_si_isError(VX) );
				xcc_test2_expect( 0 == xc_si_val(VX) );
			}
			if(1)
			{
				VY=op_I.FROMVAL(MIN);
				VY=op_I.SUB(VY, op_I.FROMVAL(1) );
				xcc_test2_expect( xc_si_retv_underflow == xc_si_getStatus(VY) );
				xcc_test2_expect( 0 != xc_si_isError(VY) );
				xcc_test2_expect( 0 == xc_si_val(VY) );
			}
			/* prepare params: done */
			
			VZ=op_I.DIV(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_any<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VX, x, xc_si_retv_underflow)
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VY, y, xc_si_retv_underflow)
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VZ, z, xc_si_retv_underflow)
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
	}
	
	xcc_test2_scope_end();
}


template<typename TPL_PRIMITIVE, typename TPL_XCTYPE, class TPL_OP_I>
int test_si_signed_div(
	  xcc_test2_param_list
	, const TPL_PRIMITIVE val_min
	, const TPL_PRIMITIVE val_max
) noexcept
{
	const TPL_PRIMITIVE MIN=val_min;
	const TPL_PRIMITIVE MAX=val_max;
	TPL_OP_I op_I;
	
	xcc_test2_scope("xc_si:DIV: test");
	
	if(1)
	{
		
		do
		{
			xcc_test2_case_descr("div-positiveNumbers:", "TODO");
			
			xcc_test2_expect( 0 == ( test_si_div_positive <TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I> (
					  xcc_test2_param_internal_embedded()
					, val_min
					, val_max
				) )
			);
			
			xcc_test2_case_end();
		}
		while(0);
	}
	/* --- --- --- */
	
	if(1)
	{
		do
		{
			xcc_test2_case_descr("div-negativeNumbers:", "TODO");
			
			xcc_test2_expect( 0 == ( test_si_div_positive <TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I> (
					  xcc_test2_param_internal_embedded()
					, val_min
					, val_max
				) )
			);
			
			xcc_test2_case_end();
		}
		while(0);
	}
	
	
	if(1)
	{
		do
		{
			xcc_test2_case_descr("div-signAgnosticErrors:", "TODO");
			
			xcc_test2_expect( 0 == ( test_si_div_signAgnostic_errors<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I> (
					  xcc_test2_param_internal_embedded()
					, val_min
					, val_max
				) )
			);
			
			xcc_test2_case_end();
		}
		while(0);
	}
	
	xcc_test2_scope_end();
}


#endif
