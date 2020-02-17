#ifndef _XC_SI_TEST_INT_SUB_HPP_
#define _XC_SI_TEST_INT_SUB_HPP_

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
int test_si_signed_sub(
	  xcc_test2_param_list //xcc_test2_paramObj& testScope_param
	, const TPL_PRIMITIVE val_min
	, const TPL_PRIMITIVE val_max
) noexcept
{
	const TPL_PRIMITIVE MIN=val_min;
	const TPL_PRIMITIVE MAX=val_max;
	TPL_OP_I op_I;
	
	xcc_test2_scope("xc_si:SUB: test");

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
			
			xcc_test2_case_descr("sub+1.1.0-zeros", "");
			
			VZ=op_I.SUB(VX, VY);
			
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
			const TPL_PRIMITIVE y=1;
			const TPL_PRIMITIVE z=-1;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("sub+1.1.1-positive", "");
			
			VZ=op_I.SUB(VX, VY);
			
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
			const TPL_PRIMITIVE y=MAX/2;
			const TPL_PRIMITIVE z=-MAX/2;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("sub+1.1.2-positive", "");
			
			VZ=op_I.SUB(VX, VY);
			
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
			const TPL_PRIMITIVE y=MAX-1;
			const TPL_PRIMITIVE z=-MAX+1;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("sub+1.1.3-positive", "");
			
			VZ=op_I.SUB(VX, VY);
			
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
			const TPL_PRIMITIVE y=MAX;
			const TPL_PRIMITIVE z=-MAX;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("sub+1.1.4-positive", "");
			
			VZ=op_I.SUB(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_success<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward, VX, VY, VZ, x, y, z
				) )
			);
			
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
			const TPL_PRIMITIVE z=1;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("sub+1.2.1-negative", "");
			
			VZ=op_I.SUB(VX, VY);
			
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
			const TPL_PRIMITIVE y=MAX/2;
			const TPL_PRIMITIVE z=-MAX/2;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("sub+1.2.2-negative", "");
			
			VZ=op_I.SUB(VX, VY);
			
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
			const TPL_PRIMITIVE y=MIN+1;
			const TPL_PRIMITIVE z=-MIN-1;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("sub+1.2.3-negative", "");
			
			VZ=op_I.SUB(VX, VY);
			
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
			const TPL_PRIMITIVE y=MAX;
			const TPL_PRIMITIVE z=-MAX;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("sub+1.2.4-negative", "");
			
			VZ=op_I.SUB(VX, VY);
			
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
			const TPL_PRIMITIVE x=MAX;
			const TPL_PRIMITIVE y=-1;
			const TPL_PRIMITIVE z=0;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("sub+1.error.1-overflow.1.a", "");
			
			VZ=op_I.SUB(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_any<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VX, x, xc_si_retv_ok)
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VY, y, xc_si_retv_ok)
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VZ, z, xc_si_retv_overflow)
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=1;
			const TPL_PRIMITIVE y=-MAX;
			const TPL_PRIMITIVE z=0;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("sub+1.error.1-overflow.1.b", "");
			
			VZ=op_I.SUB(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_any<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VX, x, xc_si_retv_ok)
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VY, y, xc_si_retv_ok)
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VZ, z, xc_si_retv_overflow)
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);

		do
		{
			const TPL_PRIMITIVE x=MAX/2;
			const TPL_PRIMITIVE y=-MAX;
			const TPL_PRIMITIVE z=0;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("sub+1.error.1-overflow.2.a", "");
			
			VZ=op_I.SUB(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_any<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VX, x, xc_si_retv_ok)
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VY, y, xc_si_retv_ok)
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VZ, z, xc_si_retv_overflow)
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
		do
		{
			const TPL_PRIMITIVE x=MAX;
			const TPL_PRIMITIVE y=-MAX/2;
			const TPL_PRIMITIVE z=0;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("sub+1.error.1-overflow.2.b", "");
			
			VZ=op_I.SUB(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_any<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VX, x, xc_si_retv_ok)
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
			
			xcc_test2_case_descr("sub+1.error.1-overflow.10.a", "");
			
			/* prepare params: */
			if(1)
			{
				VX=op_I.FROMVAL(MAX);
				VX=op_I.SUB(VX, op_I.FROMVAL(-1) );
				xcc_test2_expect( xc_si_retv_overflow == xc_si_getStatus(VX) );
				xcc_test2_expect( 0 != xc_si_isError(VX) );
				xcc_test2_expect( 0 == xc_si_val(VX) );
			}
			/* prepare params: done */
			
			VZ=op_I.SUB(VX, VY);
			
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
			
			xcc_test2_case_descr("sub+1.error.1-overflow.10.b", "");
			
			/* prepare params: */
			if(1)
			{
				VY=op_I.FROMVAL(MAX);
				VY=op_I.SUB(VY, op_I.FROMVAL(-1) );
				xcc_test2_expect( xc_si_retv_overflow == xc_si_getStatus(VY) );
				xcc_test2_expect( 0 != xc_si_isError(VY) );
				xcc_test2_expect( 0 == xc_si_val(VY) );
			}
			/* prepare params: done */
			
			VZ=op_I.SUB(VX, VY);
			
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
			
			xcc_test2_case_descr("sub+1.error.1-overflow.10.c", "");
			
			/* prepare params: */
			if(1)
			{
				VX=op_I.FROMVAL(MAX);
				VX=op_I.SUB(VX, op_I.FROMVAL(-1) );
				xcc_test2_expect( xc_si_retv_overflow == xc_si_getStatus(VX) );
				xcc_test2_expect( 0 != xc_si_isError(VX) );
				xcc_test2_expect( 0 == xc_si_val(VX) );
			}
			if(1)
			{
				VY=op_I.FROMVAL(MAX);
				VY=op_I.SUB(VY, op_I.FROMVAL(-1) );
				xcc_test2_expect( xc_si_retv_overflow == xc_si_getStatus(VY) );
				xcc_test2_expect( 0 != xc_si_isError(VY) );
				xcc_test2_expect( 0 == xc_si_val(VY) );
			}
			/* prepare params: done */
			
			VZ=op_I.SUB(VX, VY);
			
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
			const TPL_PRIMITIVE x=MIN;
			const TPL_PRIMITIVE y=1;
			const TPL_PRIMITIVE z=0;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("sub+1.error.1-underflow.1.a", "");
			
			VZ=op_I.SUB(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_any<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VX, x, xc_si_retv_ok)
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VY, y, xc_si_retv_ok)
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VZ, z, xc_si_retv_underflow)
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);

		do
		{
			const TPL_PRIMITIVE x=-2;
			const TPL_PRIMITIVE y=MAX;
			const TPL_PRIMITIVE z=0;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("sub+1.error.1-underflow.1.b", "");
			
			VZ=op_I.SUB(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_any<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VX, x, xc_si_retv_ok)
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VY, y, xc_si_retv_ok)
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VZ, z, xc_si_retv_underflow)
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);
		
		
		do
		{
			const TPL_PRIMITIVE x=-MAX;
			const TPL_PRIMITIVE y=MAX/2;
			const TPL_PRIMITIVE z=0;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("sub+1.error.1-underflow.2.a", "");
			
			VZ=op_I.SUB(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_any<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VX, x, xc_si_retv_ok)
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VY, y, xc_si_retv_ok)
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VZ, z, xc_si_retv_underflow)
				) )
			);
			
			xcc_test2_case_end();
			
		} while(0);

		do
		{
			const TPL_PRIMITIVE x=-MAX/2;
			const TPL_PRIMITIVE y=MAX;
			const TPL_PRIMITIVE z=0;
			TPL_XCTYPE VX=op_I.FROMVAL(x);
			TPL_XCTYPE VY=op_I.FROMVAL(y);
			TPL_XCTYPE VZ=op_I.FROMVAL(0);
			
			xcc_test2_case_descr("sub+1.error.1-underflow.2.b", "");
			
			VZ=op_I.SUB(VX, VY);
			
			xcc_test2_expect( 
				0 == ( test_si_test_verifyState_any<TPL_PRIMITIVE, TPL_XCTYPE, TPL_OP_I>(
					  xcc_test2_param_list_forward
					, test_si_param<TPL_PRIMITIVE, TPL_XCTYPE>(VX, x, xc_si_retv_ok)
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
			
			xcc_test2_case_descr("sub+1.error.1-underflow.10.a", "");
			
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
			
			VZ=op_I.SUB(VX, VY);
			
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
			
			xcc_test2_case_descr("sub+1.error.1-underflow.10.b", "");
			
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
			
			VZ=op_I.SUB(VX, VY);
			
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
			
			xcc_test2_case_descr("sub+1.error.1-underflow.10.c", "");
			
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
			
			VZ=op_I.SUB(VX, VY);
			
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


#endif
