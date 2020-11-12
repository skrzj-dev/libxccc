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

#ifndef _TEST_STRINGCS_FUNCTIONAL_ABSTRACTS__SUBSTR_MUTABLE_HPP_
#define _TEST_STRINGCS_FUNCTIONAL_ABSTRACTS__SUBSTR_MUTABLE_HPP_

/* --- */

#include "xcc/test/xcc_test2.hpp"
#include "xcc/test/xcc_test2_paramrow.hpp"
#include "xcc/common/xcc_cpp.hpp"
/* --- */
#include "test_strcs_functional_abstracts__shared.hpp"
/* --- */

template<typename TPL_STROBJ>
class subtest_fnSubstrInit_tplt: public test_xcStringS_testStaticStr_sub_I<TPL_STROBJ>
{

	protected: test_xcStringS_testStaticStr_intfs_tpl<TPL_STROBJ>* intfs;
	
	protected: virtual int testedOp(int id, TPL_STROBJ* target, test_xcStringS_I_findResult info, TPL_STROBJ* result)
	{
		return intfs->INTF_STATICSTR->substr_init(target, &info, result);
	}
	
	public: subtest_fnSubstrInit_tplt(test_xcStringS_testStaticStr_intfs_tpl<TPL_STROBJ>* ref_intfs)
	{
		this->intfs=ref_intfs;
	}
	
	protected: typedef xcc_test3_DATAROW5_DECLT(
		  xcc_test2_failureDetails_t*
		, int
		, testParamValued01<TPL_STROBJ>
		, testParamValued01<TPL_STROBJ>
		, test_xcStringS_I_findResult
	) init_paramsError_expectError_paramRow_t;
	public: int init_paramsError_expectError(
		  xcc_test2_failureDetails_t* failInfo
		, int id
		, testParamValued01<TPL_STROBJ> selfI
		, testParamValued01<TPL_STROBJ> result_param
		, test_xcStringS_I_findResult info
	)
	{
		xcc_test2_scope_disconnected();
		
		do
		{
			xcc_test2_case("checking internal state");
			if(1)
			{
				test_xcStringS_state<TPL_STROBJ> self_state;
				test_xcStringS_state<TPL_STROBJ>* ptr_self_state=&self_state;

				test_xcStringS_state<TPL_STROBJ> param_state;
				test_xcStringS_state<TPL_STROBJ>* ptr_param_state=&param_state;
				
				xcc_test2_expect( 0 == selfI.intf->prepareState2(*failInfo, ptr_self_state, selfI.value) );
				xcc_test2_expect( 0 == result_param.intf->prepareState2(*failInfo, ptr_param_state, result_param.value) );
				
				xcc_test2_expect( 0 != this->testedOp(id, ptr_self_state->refp_obj_operational, info, ptr_param_state->refp_obj_operational) );
				
				xcc_test2_expect( 0 == selfI.intf->verifyState(*failInfo, ptr_self_state, selfI.value) );
				
				xcc_test2_expect( 0 == selfI.intf->deinit(*failInfo, ptr_self_state) );
				xcc_test2_expect( 0 == result_param.intf->deinit(*failInfo, ptr_param_state) );
			}
			xcc_test2_case_end();
			
		} while(0);
		
		xcc_test2_scope_end();
	}

	protected: typedef xcc_test3_DATAROW6_DECLT(
		  xcc_test2_failureDetails_t*
		, int
		, testParamValued01<TPL_STROBJ>
		, testParamValued01<TPL_STROBJ>
		, test_xcStringS_I_findResult
		, testParamValued01<TPL_STROBJ>
	) init_paramsError_expectResultOk_paramRow_t;
	public: int init_paramsError_expectResultOk(
		  xcc_test2_failureDetails_t* failInfo
		, int id
		, testParamValued01<TPL_STROBJ> target1
		, testParamValued01<TPL_STROBJ> param
		, test_xcStringS_I_findResult info
		, testParamValued01<TPL_STROBJ> result
	)
	{
		xcc_test2_scope_disconnected();
		
		do
		{
			xcc_test2_case("checking internal state");
			if(1)
			{
				test_xcStringS_state<TPL_STROBJ> self_state;
				test_xcStringS_state<TPL_STROBJ>* ptr_self_state=&self_state;

				test_xcStringS_state<TPL_STROBJ> param_state;
				test_xcStringS_state<TPL_STROBJ>* ptr_param_state=&param_state;
				
				//test_xcStringS_state<TPL_STROBJ> result_state;
				//test_xcStringS_state<TPL_STROBJ>* ptr_result_state=&result_state;
				
				xcc_test2_expect( 0 == target1.intf->prepareState2(*failInfo, ptr_self_state, target1.value) );
				xcc_test2_expect( 0 == param.intf->prepareState2(*failInfo, ptr_param_state, param.value) );
				//xcc_test2_expect( 0 == result.intf->prepareState2(*failInfo, &result_state, result) );
				
				xcc_test2_expect( 0 == this->testedOp(id, ptr_self_state->refp_obj_operational, info, ptr_param_state->refp_obj_operational) );
				
				xcc_test2_expect( 0 == result.intf->verifyState(*failInfo, ptr_param_state, result.value) );
				
				xcc_test2_expect( 0 == target1.intf->deinit(*failInfo, ptr_self_state) );
				xcc_test2_expect( 0 == param.intf->deinit(*failInfo, ptr_param_state) );
				//xcc_test2_expect( 0 == result.intf->deinit(*failInfo, ptr_result_state) );
			}
			xcc_test2_case_end();
			
		} while(0);
		
		xcc_test2_scope_end();
	}
	
	protected: int testProcedure_empty_offsets_errors_anyMutability(xcc_test2_param_list)
	{
		xcc_test2_scope("[CSTRD]-[fnSubstrInit]");
		xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
		
		if(1)
		{
			init_paramsError_expectError_paramRow_t rows[]=
			{
				 xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4.11", 
					refp_failReport, 1140040, 
					intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsUninitZero->value()
					, test_xcStringS_I_findResult::GET(-1,-1)
				)
				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4.12", 
					refp_failReport, 1140041, 
					intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsUninitZero->value()
					, test_xcStringS_I_findResult::GET(-1,0)
				)
				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4.13", 
					refp_failReport, 1140042, 
					intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsUninitZero->value()
					, test_xcStringS_I_findResult::GET(-1,1)
				)
				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4.13.1", 
					refp_failReport, 1140042, 
					intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsUninitZero->value()
					, test_xcStringS_I_findResult::GET(-99,0)
				)
				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4.13.2", 
					refp_failReport, 1140042, 
					intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsUninitZero->value()
					, test_xcStringS_I_findResult::GET(-99,99)
				)
				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4.13.3", 
					refp_failReport, 1140042, 
					intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsUninitZero->value()
					, test_xcStringS_I_findResult::GET(-99,100)
				)
				
				//, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4.21", 
				//	refp_failReport, 1140043, 
				//	intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsUninitZero->value()
				//	, test_xcStringS_I_findResult::GET(0,-1)
				//) // this is ok
				//, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4.22", 
				//	refp_failReport, 1140044, 
				//	intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsUninitZero->value()
				//	, test_xcStringS_I_findResult::GET(0,0)
				//) // this is ok
				
				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4.23", 
					refp_failReport, 1140045, 
					intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsUninitZero->value()
					, test_xcStringS_I_findResult::GET(0,1)
				)
				
				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4.31", 
					refp_failReport, 1140046, 
					intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsUninitZero->value()
					, test_xcStringS_I_findResult::GET(1,-1)
				)
				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4.32", 
					refp_failReport, 1140047, 
					intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsUninitZero->value()
					, test_xcStringS_I_findResult::GET(1,0)
				)
				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4.33", 
					refp_failReport, 1140048, 
					intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsUninitZero->value()
					, test_xcStringS_I_findResult::GET(1,1)
				)
				
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "fnSubstrInit[err-param.04.10, init empty self]"
				, "ERROR-OTHER-PARAM-NULL-OR-UNINIT"
				, init_paramsError_expectError_paramRow_t
				, init_paramsError_expectError
				, rows
			);
		}
		
		xcc_test2_scope_end();
	}
	
	protected: int testProcedure_nonempty_offsets_errors_anyMutability(xcc_test2_param_list)
	{
		xcc_test2_scope("[CSTRD]-[fnSubstrInit]");
		xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
		
		if(1)
		{
/*
qwwerty12345
0123456789AB
*/
			init_paramsError_expectError_paramRow_t rows[]=
			{
				 xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4.11", 
					refp_failReport, 1150040, 
					intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsUninitZero->value()
					, test_xcStringS_I_findResult::GET(-1,-1)
				)
				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4.12", 
					refp_failReport, 1150041, 
					intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsUninitZero->value()
					, test_xcStringS_I_findResult::GET(-1,0)
				)
				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4.13", 
					refp_failReport, 1150042, 
					intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsUninitZero->value()
					, test_xcStringS_I_findResult::GET(-1,1)
				)
				
				//, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4.21", 
				//	refp_failReport, 1150043, 
				//	intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsUninitZero->value()
				//	, test_xcStringS_I_findResult::GET(0,-1)
				//)
				//, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4.22", 
				//	refp_failReport, 1150044, 
				//	intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsUninitZero->value()
				//	, test_xcStringS_I_findResult::GET(0,0)
				//)
				//, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4.23", 
				//	refp_failReport, 1150045, 
				//	intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsUninitZero->value()
				//	, test_xcStringS_I_findResult::GET(0,1)
				//)
				
				//, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4.31", 
				//	refp_failReport, 1150046, 
				//	intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsUninitZero->value()
				//	, test_xcStringS_I_findResult::GET(1,-1)
				//)
				//, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4.32", 
				//	refp_failReport, 1150047, 
				//	intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsUninitZero->value()
				//	, test_xcStringS_I_findResult::GET(1,0)
				//)
				//, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4.33", 
				//	refp_failReport, 1150048, 
				//	intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsUninitZero->value()
				//	, test_xcStringS_I_findResult::GET(1,1)
				//)
				


				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var5.11", 
					refp_failReport, 1150057, 
					intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsUninitZero->value()
					, test_xcStringS_I_findResult::GET(10,3)
				)
				//, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var5.11.1", 
				//	refp_failReport, 1150057, 
				//	intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsUninitZero->value()
				//	, test_xcStringS_I_findResult::GET(10,2)
				//)
				
				//, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var5.12", 
				//	refp_failReport, 1150057, 
				//	intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsUninitZero->value()
				//	, test_xcStringS_I_findResult::GET(11,1)
				//)
				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var5.13", 
					refp_failReport, 1150058, 
					intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsUninitZero->value()
					, test_xcStringS_I_findResult::GET(11,2)
				)
				
				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var5.14", 
					refp_failReport, 1150051, 
					intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsUninitZero->value()
					, test_xcStringS_I_findResult::GET(12,-1)
				)
				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var5.15", 
					refp_failReport, 1150052, 
					intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsUninitZero->value()
					, test_xcStringS_I_findResult::GET(12,1)
				)

				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var5.16", 
					refp_failReport, 1150053, 
					intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsUninitZero->value()
					, test_xcStringS_I_findResult::GET(13,-1)
				)
				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var5.17", 
					refp_failReport, 1150053, 
					intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsUninitZero->value()
					, test_xcStringS_I_findResult::GET(13,-1)
				)
				, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var5.18", 
					refp_failReport, 1150054, 
					intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsUninitZero->value()
					, test_xcStringS_I_findResult::GET(13,0)
				)
				
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "fnSubstrInit[err-param.04.20, init nonempty self]"
				, "ERROR-OTHER-PARAM-NULL-OR-UNINIT"
				, init_paramsError_expectError_paramRow_t
				, init_paramsError_expectError
				, rows
			);
		}
		
		xcc_test2_scope_end();
	}
	
	protected: int testProcedure_errorParams_unmanageable_anyMutability(xcc_test2_param_list)
	{
		xcc_test2_scope("[CSTRD]-[fnSubstrInit]");
		xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
		
		/* errors case: */
		if(1)
		{
			if(1)
			{
				init_paramsError_expectError_paramRow_t rows[]=
				{
				    xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var1"
						, refp_failReport, 1110011
						, intfs->INTF_SET->strcsNull->value(), intfs->INTF_SET->strcsNull->value()
						, test_xcStringS_I_findResult::GET(0,0)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var2", 
						refp_failReport, 1110022, 
						intfs->INTF_SET->strcsNull->value(), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(0,0)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var3", 
						refp_failReport, 1110033, 
						intfs->INTF_SET->strcsNull->value(), intfs->INTF_SET->strcsUninitNonZero->value()
						, test_xcStringS_I_findResult::GET(0,0)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4", 
						refp_failReport, 1110044,  
						intfs->INTF_SET->strcsNull->value(), intfs->INTF_SET->strcsInitEmpty->value()
						, test_xcStringS_I_findResult::GET(0,0)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var5", 
						refp_failReport, 1110055, 
						intfs->INTF_SET->strcsNull->value(), intfs->INTF_SET->strcsInitNonEmpty->value("abcd123")
						, test_xcStringS_I_findResult::GET(0,0)
					)
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow5(
					  "fnSubstrInit[err-param.01,null self]"
					, "ERROR-ANY-PARAM-NULL"
					, init_paramsError_expectError_paramRow_t
					, init_paramsError_expectError
					, rows
				);
			}
			
			if(1)
			{
				
				init_paramsError_expectError_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var1", 
						refp_failReport, 1120011, 
						intfs->INTF_SET->strcsUninitZero->value(), intfs->INTF_SET->strcsNull->value()
						, test_xcStringS_I_findResult::GET(0,0)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var2", 
						refp_failReport, 1120022, 
						intfs->INTF_SET->strcsUninitZero->value(), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(0,0)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var3", 
						refp_failReport, 1120033, 
						intfs->INTF_SET->strcsUninitZero->value(), intfs->INTF_SET->strcsUninitNonZero->value()
						, test_xcStringS_I_findResult::GET(0,0)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4", 
						refp_failReport, 1120044, 
						intfs->INTF_SET->strcsUninitZero->value(), intfs->INTF_SET->strcsInitEmpty->value()
						, test_xcStringS_I_findResult::GET(0,0)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var5", 
						refp_failReport, 1120055, 
						intfs->INTF_SET->strcsUninitZero->value(), intfs->INTF_SET->strcsInitNonEmpty->value("abcd")
						, test_xcStringS_I_findResult::GET(0,0)
					)
					
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow5(
					  "fnSubstrInit[err-param.02, uninit self]"
					, "ERROR-OTHER-PARAM-NULL-OR-UNINIT"
					, init_paramsError_expectError_paramRow_t
					, init_paramsError_expectError
					, rows
				);
			}
			
			if(1)
			{
				xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
				
				init_paramsError_expectError_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var1", 
 						refp_failReport, 1130011, 
						intfs->INTF_SET->strcsUninitNonZero->value(), intfs->INTF_SET->strcsNull->value()
						, test_xcStringS_I_findResult::GET(0,0)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var2", 
 						refp_failReport, 1130022, 
						intfs->INTF_SET->strcsUninitNonZero->value(), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(0,0)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var3", 
 						refp_failReport, 1130033, 
						intfs->INTF_SET->strcsUninitNonZero->value(), intfs->INTF_SET->strcsUninitNonZero->value()
						, test_xcStringS_I_findResult::GET(0,0)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4", 
						refp_failReport, 1130044, 
						intfs->INTF_SET->strcsUninitNonZero->value(), intfs->INTF_SET->strcsInitEmpty->value()
						, test_xcStringS_I_findResult::GET(0,0)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var5", 
						refp_failReport, 1130055, 
						intfs->INTF_SET->strcsUninitNonZero->value(), intfs->INTF_SET->strcsInitNonEmpty->value("abcd")
						, test_xcStringS_I_findResult::GET(0,0)
					)
					
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow5(
					  "fnSubstrInit[err-param.03, uninit self]"
					, "ERROR-OTHER-PARAM-NULL-OR-UNINIT"
					, init_paramsError_expectError_paramRow_t
					, init_paramsError_expectError
					, rows
				);
			}
			
			if(1)
			{
				xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
				
				init_paramsError_expectError_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var1", 
 						refp_failReport, 1140011, 
						intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsNull->value()
						, test_xcStringS_I_findResult::GET(0,0)
					)
					//, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var2", 
 					//	refp_failReport, 1140012, 
					//	intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsUninitZero->value()
					//	, test_xcStringS_I_findResult::GET(0,0)
					//)
					//, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var3", 
 					//	refp_failReport, 1140013, 
					//	intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsUninitNonZero->value()
					//	, test_xcStringS_I_findResult::GET(0,0)
					//)
					//, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4", 
					//	refp_failReport, 1130014, 
					//	intfs->INTF_SET->strcsUninitNonZero->value(), intfs->INTF_SET->strcsInitEmpty->value()
					//	, test_xcStringS_I_findResult::GET(0,0)
					//)
					//, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var5", 
					//	refp_failReport, 114015, 
					//	intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsInitNonEmpty->value("abcd")
					//	, test_xcStringS_I_findResult::GET(0,0)
					//)
					
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				
				xcc_test3_case_forDataRow5(
					  "fnSubstrInit[err-param.04, init empty self]"
					, "ERROR-OTHER-PARAM-NULL-OR-UNINIT"
					, init_paramsError_expectError_paramRow_t
					, init_paramsError_expectError
					, rows
				);
			}
			
			
			if(1)
			{
				xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
				
				init_paramsError_expectError_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var1", 
 						refp_failReport, 1150011 ,
						intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsNull->value(),
						test_xcStringS_I_findResult::GET(0,0)
					)
					//, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var2", 
 					//	refp_failReport, 1150022,
					//	intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsUninitZero->value(),
					//	test_xcStringS_I_findResult::GET(0,0)
					//)
					//, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var3", 
 					//	refp_failReport, 1150033,
					//	intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsUninitNonZero->value(),
					//	test_xcStringS_I_findResult::GET(0,0)
					//)
					//, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4", 
					//	refp_failReport, 1150044, 
					//	intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsInitEmpty->value()
					//	, test_xcStringS_I_findResult::GET(0,0)
					//)
					//, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var5", 
					//	refp_failReport, 115055, 
					//	intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsInitNonEmpty->value("abcd")
					//	, test_xcStringS_I_findResult::GET(0,0)
					//)
					
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow5(
					  "fnSubstrInit[err-param.04, init nonempty self]"
					, "ERROR-OTHER-PARAM-NULL-OR-UNINIT"
					, init_paramsError_expectError_paramRow_t
					, init_paramsError_expectError
					, rows
				);
			}
			
		}
		/* errors case: done */
		
		xcc_test2_scope_end();
	}
	
	protected: int testProcedure_validParams_anyMutabiility(xcc_test2_param_list)
	{
		xcc_test2_scope("[CSTRD]-[fnSubstrInit]");
		xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
		
		/* --- --- --- */
		/* --- --- --- */
		/* --- --- --- */
		
		if(1)
		{
			
			if(1)
			{
				xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
				
				init_paramsError_expectResultOk_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var11"
						, refp_failReport, 2330011 
						, intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(0,0), intfs->INTF_SET->strcsInitEmpty->value()
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var12"
						, refp_failReport, 2330012
						, intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsUninitNonZero->value()
						, test_xcStringS_I_findResult::GET(0,0), intfs->INTF_SET->strcsInitEmpty->value()
					)


					
					
					
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var21"
						, refp_failReport, 2330021 
						, intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(0,-1), intfs->INTF_SET->strcsInitEmpty->value()
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var22"
						, refp_failReport, 2330022
						, intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsUninitNonZero->value()
						, test_xcStringS_I_findResult::GET(0,-1), intfs->INTF_SET->strcsInitEmpty->value()
					)
					
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow6(
					  "fnSubstrInit[ok-param.03, init empty self]"
					, "INIT-ERROR-IF-ALREADY-INITIALIZED"
					, init_paramsError_expectResultOk_paramRow_t
					, init_paramsError_expectResultOk
					, rows
				);
			}
			
			if(1)
			{
				xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
				
				init_paramsError_expectResultOk_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var11"
						, refp_failReport, 2130011 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(0,0), intfs->INTF_SET->strcsInitEmpty->value()
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var12"
						, refp_failReport, 2130011 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(0,0), intfs->INTF_SET->strcsInitEmpty->value()
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var13"
						, refp_failReport, 2130011 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(0,0), intfs->INTF_SET->strcsInitEmpty->value()
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var14"
						, refp_failReport, 2130012 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value("1")
						, test_xcStringS_I_findResult::GET(0,0), intfs->INTF_SET->strcsInitEmpty->value()
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var15"
						, refp_failReport, 2130013 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value("abcdegh12345")
						, test_xcStringS_I_findResult::GET(0,0), intfs->INTF_SET->strcsInitEmpty->value()
					)
					
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow6(
					  "fnSubstrInit[ok-param.101.toempty]"
					, "TODO"
					, init_paramsError_expectResultOk_paramRow_t
					, init_paramsError_expectResultOk
					, rows
				);
			}
		}
		
		/* --- --- --- */
		/* --- --- --- */
		/* --- --- --- */
		
		if(1)
		{
			
			if(1)
			{
				xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
				
				init_paramsError_expectResultOk_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var11"
						, refp_failReport, 2130011 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(0,-1), intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf")
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var12"
						, refp_failReport, 2130011 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(0,-1), intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf")
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var13"
						, refp_failReport, 2130011 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(0,-1), intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf")
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var14"
						, refp_failReport, 2130012 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value("1")
						, test_xcStringS_I_findResult::GET(0,-1), intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf")
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var15"
						, refp_failReport, 2130013 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value("abcdegh12345")
						, test_xcStringS_I_findResult::GET(0,-1), intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf")
					)

					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var15"
						, refp_failReport, 2130013 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value("abcdegh12345")
						, test_xcStringS_I_findResult::GET(0,-99), intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf")
					)
					
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow6(
					  "fnSubstrInit[ok-param.101.tofullcopy]"
					, "TODO"
					, init_paramsError_expectResultOk_paramRow_t
					, init_paramsError_expectResultOk
					, rows
				);
			}
			
			if(1)
			{
/*
qwerty123.abcdefg.!@@#$.asdf
         9               ^^^
         9               ^^27
         9               ^^ 
         9               ^26 
         9               ^  
                         25 
0123456789ABCDEF............
                0123456789AB
*/
				xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
				
				init_paramsError_expectResultOk_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var11"
						, refp_failReport, 2130011 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(9,-1), intfs->INTF_SET->strcsInitNonEmpty->value(".abcdefg.!@@#$.asdf")
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var12"
						, refp_failReport, 2130011 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(25,-1), intfs->INTF_SET->strcsInitNonEmpty->value("sdf")
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var13"
						, refp_failReport, 2130011 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(26,-1), intfs->INTF_SET->strcsInitNonEmpty->value("df")
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var14"
						, refp_failReport, 2130012 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value("1")
						, test_xcStringS_I_findResult::GET(27,-1), intfs->INTF_SET->strcsInitNonEmpty->value("f")
					)
					
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var14"
						, refp_failReport, 2130012 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value("1")
						, test_xcStringS_I_findResult::GET(27,-99), intfs->INTF_SET->strcsInitNonEmpty->value("f")
					)
					
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow6(
					  "fnSubstrInit[ok-param.201.middleToEnd]"
					, "TODO"
					, init_paramsError_expectResultOk_paramRow_t
					, init_paramsError_expectResultOk
					, rows
				);
			}
			
			if(1)
			{
/*
qwerty123.abcdefg.!@@#$.asdf
         9               ^^^
         9               ^^27
         9               ^^ 
         9               ^26 
         9               ^  
                         25 
0123456789ABCDEF............
                0123456789AB
*/
				xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
				
				init_paramsError_expectResultOk_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var11"
						, refp_failReport, 2130011 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(0,27), intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asd")
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var12"
						, refp_failReport, 2130011 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(0,28), intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf")
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var13"
						, refp_failReport, 2130011 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(0,10), intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.")
					)
					
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow6(
					  "fnSubstrInit[ok-param.201.startToLen]"
					, "TODO"
					, init_paramsError_expectResultOk_paramRow_t
					, init_paramsError_expectResultOk
					, rows
				);
			}
			
			if(1)
			{
/*
qwerty123.abcdefg.!@@#$.asdf
         9               ^^^
         9               ^^27
         9               ^^ 
         9               ^26 
         9               ^  
                         25 
0123456789ABCDEF............
                0123456789AB
				
.abcdefg.!@@#$.asdf
*/
				xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
				
				init_paramsError_expectResultOk_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var11"
						, refp_failReport, 9130011 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(1,27), intfs->INTF_SET->strcsInitNonEmpty->value("werty123.abcdefg.!@@#$.asdf")
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var12"
						, refp_failReport, 9130012 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(1,10), intfs->INTF_SET->strcsInitNonEmpty->value("werty123.a")
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var13"
						, refp_failReport, 9130013 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(2,10), intfs->INTF_SET->strcsInitNonEmpty->value("erty123.ab")
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var14"
						, refp_failReport, 9130014 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(9,19), intfs->INTF_SET->strcsInitNonEmpty->value(".abcdefg.!@@#$.asdf")
					)
					
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var14"
						, refp_failReport, 9130014 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(25,3), intfs->INTF_SET->strcsInitNonEmpty->value("sdf")
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var14"
						, refp_failReport, 9130014 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(26,2), intfs->INTF_SET->strcsInitNonEmpty->value("df")
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var14"
						, refp_failReport, 9130014 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(27,1), intfs->INTF_SET->strcsInitNonEmpty->value("f")
					)
					
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow6(
					  "fnSubstrInit[ok-param.201.OffToLen]"
					, "TODO"
					, init_paramsError_expectResultOk_paramRow_t
					, init_paramsError_expectResultOk
					, rows
				);
			}
			
			if(1)
			{
/*
qwerty123.abcdefg.!@@#$.asdf
         9               ^^^
         9               ^^27
         9               ^^ 
         9               ^26 
         9               ^  
                         25 
0123456789ABCDEF............
                0123456789AB
				
.abcdefg.!@@#$.asdf
*/
				xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
				
				init_paramsError_expectResultOk_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var11"
						, refp_failReport, 9150011 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(1,0), intfs->INTF_SET->strcsInitEmpty->value()
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var12"
						, refp_failReport, 9150012 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(1,0), intfs->INTF_SET->strcsInitEmpty->value()
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var13"
						, refp_failReport, 9150013 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(2,0), intfs->INTF_SET->strcsInitEmpty->value()
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var14"
						, refp_failReport, 9150014 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(9,0), intfs->INTF_SET->strcsInitEmpty->value()
					)

					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var15"
						, refp_failReport, 9150015 
						, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty123.abcdefg.!@@#$.asdf"), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(27,0), intfs->INTF_SET->strcsInitEmpty->value()
					)
					
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow6(
					  "fnSubstrInit[ok-param.201.OffZeroLLenEmpty]"
					, "TODO"
					, init_paramsError_expectResultOk_paramRow_t
					, init_paramsError_expectResultOk
					, rows
				);
			}
			
		}
		/* --- --- --- */
		/* --- --- --- */
		/* --- --- --- */

		xcc_test2_scope_end();
	}
};


template<typename TPL_STROBJ>
class subtest_fnSubstrInit_Mutable_tplt: public subtest_fnSubstrInit_tplt<TPL_STROBJ>
{
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */
	
	using typename subtest_fnSubstrInit_tplt<TPL_STROBJ>::init_paramsError_expectError_paramRow_t;
	using typename subtest_fnSubstrInit_tplt<TPL_STROBJ>::init_paramsError_expectResultOk_paramRow_t;
	using subtest_fnSubstrInit_tplt<TPL_STROBJ>::intfs;
	using subtest_fnSubstrInit_tplt<TPL_STROBJ>::testProcedure_errorParams_unmanageable_anyMutability;
	using subtest_fnSubstrInit_tplt<TPL_STROBJ>::testProcedure_empty_offsets_errors_anyMutability;
	using subtest_fnSubstrInit_tplt<TPL_STROBJ>::testProcedure_nonempty_offsets_errors_anyMutability;
	using subtest_fnSubstrInit_tplt<TPL_STROBJ>::testProcedure_validParams_anyMutabiility;

	public: subtest_fnSubstrInit_Mutable_tplt(test_xcStringS_testStaticStr_intfs_tpl<TPL_STROBJ>* ref_intfs)
		: subtest_fnSubstrInit_tplt<TPL_STROBJ>(ref_intfs)
	{
	}
	
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */
	
	public: int perform(xcc_test2_param_list)
	{
		int retv=0;
		
		retv+=this->testProcedure_errorParams_unmanageable_anyMutability(xcc_test2_param_list_forward);
		retv+=this->testProcedure_empty_offsets_errors_anyMutability(xcc_test2_param_list_forward);
		retv+=this->testProcedure_nonempty_offsets_errors_anyMutability(xcc_test2_param_list_forward);
		retv+=this->testProcedure_validParams_anyMutabiility(xcc_test2_param_list_forward);

		retv+=this->testProcedure_errorParams_mutable(xcc_test2_param_list_forward);
		retv+=this->testProcedure_validParams_mutable(xcc_test2_param_list_forward);
		
		return retv;
	}
	
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */
	
	
	protected: int testProcedure_errorParams_mutable(xcc_test2_param_list)
	{
		xcc_test2_scope("[CSTRD]-[fnSubstrInit-mutable]");
		xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
		
		/* --- --- --- */
		/* --- --- --- */
		/* --- --- --- */
		
		
		
		/* --- --- --- */
		/* --- --- --- */
		/* --- --- --- */
		
		xcc_test2_scope_end();
	}
	
	protected: int testProcedure_validParams_mutable(xcc_test2_param_list)
	{
		xcc_test2_scope("[CSTRD]-[fnSubstrInit-mutable]");
		xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
		
		/* --- --- --- */
		/* --- --- --- */
		/* --- --- --- */
		
		if(1)
		{
			
			if(1)
			{
				xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
				
				init_paramsError_expectResultOk_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var11"
						, refp_failReport, 2330011 
						, intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(0,0), intfs->INTF_SET->strcsInitEmpty->value()
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var12"
						, refp_failReport, 2330012
						, intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsUninitNonZero->value()
						, test_xcStringS_I_findResult::GET(0,0), intfs->INTF_SET->strcsInitEmpty->value()
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var13"
						, refp_failReport, 2330013 
						, intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsInitEmpty->value()
						, test_xcStringS_I_findResult::GET(0,0), intfs->INTF_SET->strcsInitEmpty->value()
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var14"
						, refp_failReport, 2330014 
						, intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsInitNonEmpty->value("1")
						, test_xcStringS_I_findResult::GET(0,0), intfs->INTF_SET->strcsInitEmpty->value()
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var15"
						, refp_failReport, 2330015 
						, intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsInitNonEmpty->value("abcdegh12345")
						, test_xcStringS_I_findResult::GET(0,0), intfs->INTF_SET->strcsInitEmpty->value()
					)
					
					
					
					
					
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var21"
						, refp_failReport, 2330021 
						, intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(0,-1), intfs->INTF_SET->strcsInitEmpty->value()
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var22"
						, refp_failReport, 2330022
						, intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsUninitNonZero->value()
						, test_xcStringS_I_findResult::GET(0,-1), intfs->INTF_SET->strcsInitEmpty->value()
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var23"
						, refp_failReport, 2330023 
						, intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsInitEmpty->value()
						, test_xcStringS_I_findResult::GET(0,-1), intfs->INTF_SET->strcsInitEmpty->value()
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var24"
						, refp_failReport, 2330024 
						, intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsInitNonEmpty->value("1")
						, test_xcStringS_I_findResult::GET(0,-1), intfs->INTF_SET->strcsInitEmpty->value()
					)
					, xcc_test3_DATAROW6_ITZ_T(init_paramsError_expectResultOk_paramRow_t, "var25"
						, refp_failReport, 2330025 
						, intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsInitNonEmpty->value("abcdegh12345")
						, test_xcStringS_I_findResult::GET(0,-1), intfs->INTF_SET->strcsInitEmpty->value()
					)
					
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow6(
					  "fnSubstrInit[ok-param.03, init empty self]"
					, "INIT-ERROR-IF-ALREADY-INITIALIZED"
					, init_paramsError_expectResultOk_paramRow_t
					, init_paramsError_expectResultOk
					, rows
				);
			}
		}
		
		/* --- --- --- */
		/* --- --- --- */
		/* --- --- --- */
		
		xcc_test2_scope_end();
	}
	
};


template<typename TPL_STROBJ>
class subtest_fnSubstrInit_Immutable_tplt: public subtest_fnSubstrInit_tplt<TPL_STROBJ>
{
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */
	
	using typename subtest_fnSubstrInit_tplt<TPL_STROBJ>::init_paramsError_expectError_paramRow_t;
	using typename subtest_fnSubstrInit_tplt<TPL_STROBJ>::init_paramsError_expectResultOk_paramRow_t;
	using subtest_fnSubstrInit_tplt<TPL_STROBJ>::intfs;
	using subtest_fnSubstrInit_tplt<TPL_STROBJ>::testProcedure_errorParams_unmanageable_anyMutability;
	using subtest_fnSubstrInit_tplt<TPL_STROBJ>::testProcedure_empty_offsets_errors_anyMutability;
	using subtest_fnSubstrInit_tplt<TPL_STROBJ>::testProcedure_nonempty_offsets_errors_anyMutability;
	using subtest_fnSubstrInit_tplt<TPL_STROBJ>::testProcedure_validParams_anyMutabiility;

	using subtest_fnSubstrInit_tplt<TPL_STROBJ>::init_paramsError_expectError;
	using subtest_fnSubstrInit_tplt<TPL_STROBJ>::init_paramsError_expectResultOk;

	public: subtest_fnSubstrInit_Immutable_tplt(test_xcStringS_testStaticStr_intfs_tpl<TPL_STROBJ>* ref_intfs)
		: subtest_fnSubstrInit_tplt<TPL_STROBJ>(ref_intfs)
	{
	}
	
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */
	
	public: int perform(xcc_test2_param_list)
	{
		int retv=0;
		
		retv+=this->testProcedure_errorParams_unmanageable_anyMutability(xcc_test2_param_list_forward);
		retv+=this->testProcedure_empty_offsets_errors_anyMutability(xcc_test2_param_list_forward);
		retv+=this->testProcedure_nonempty_offsets_errors_anyMutability(xcc_test2_param_list_forward);
		retv+=this->testProcedure_validParams_anyMutabiility(xcc_test2_param_list_forward);
		
		retv+=this->testProcedure_errorParams_immutable(xcc_test2_param_list_forward);
		retv+=this->testProcedure_validParams_immutable(xcc_test2_param_list_forward);
		
		return retv;
	}
	
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */
	
	protected: int testProcedure_errorParams_immutable(xcc_test2_param_list)
	{
		xcc_test2_scope("[CSTRD]-[fnSubstrInit-immutable]");
		xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
		
		/* --- --- --- */
		/* --- --- --- */
		/* --- --- --- */
		
		if(1)
		{
			if(1)
			{
				init_paramsError_expectError_paramRow_t rows[]=
				{
				    xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var1"
						, refp_failReport, 1110011
						, intfs->INTF_SET->strcsNull->value(), intfs->INTF_SET->strcsNull->value()
						, test_xcStringS_I_findResult::GET(0,0)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var2", 
						refp_failReport, 1110022, 
						intfs->INTF_SET->strcsNull->value(), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(0,0)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var3", 
						refp_failReport, 1110033, 
						intfs->INTF_SET->strcsNull->value(), intfs->INTF_SET->strcsUninitNonZero->value()
						, test_xcStringS_I_findResult::GET(0,0)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4", 
						refp_failReport, 1110044,  
						intfs->INTF_SET->strcsNull->value(), intfs->INTF_SET->strcsInitEmpty->value()
						, test_xcStringS_I_findResult::GET(0,0)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var5", 
						refp_failReport, 1110055, 
						intfs->INTF_SET->strcsNull->value(), intfs->INTF_SET->strcsInitNonEmpty->value("abcd123")
						, test_xcStringS_I_findResult::GET(0,0)
					)
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow5(
					  "fnSubstrInit[err-param.01,null self]"
					, "ERROR-ANY-PARAM-NULL"
					, init_paramsError_expectError_paramRow_t
					, init_paramsError_expectError
					, rows
				);
			}
			
			if(1)
			{
				
				init_paramsError_expectError_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var1", 
						refp_failReport, 1120011, 
						intfs->INTF_SET->strcsUninitZero->value(), intfs->INTF_SET->strcsNull->value()
						, test_xcStringS_I_findResult::GET(0,0)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var2", 
						refp_failReport, 1120022, 
						intfs->INTF_SET->strcsUninitZero->value(), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(0,0)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var3", 
						refp_failReport, 1120033, 
						intfs->INTF_SET->strcsUninitZero->value(), intfs->INTF_SET->strcsUninitNonZero->value()
						, test_xcStringS_I_findResult::GET(0,0)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4", 
						refp_failReport, 1120044, 
						intfs->INTF_SET->strcsUninitZero->value(), intfs->INTF_SET->strcsInitEmpty->value()
						, test_xcStringS_I_findResult::GET(0,0)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var5", 
						refp_failReport, 1120055, 
						intfs->INTF_SET->strcsUninitZero->value(), intfs->INTF_SET->strcsInitNonEmpty->value("abcd")
						, test_xcStringS_I_findResult::GET(0,0)
					)
					
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow5(
					  "fnSubstrInit[err-param.02, uninit self]"
					, "ERROR-OTHER-PARAM-NULL-OR-UNINIT"
					, init_paramsError_expectError_paramRow_t
					, init_paramsError_expectError
					, rows
				);
			}
			
			if(1)
			{
				xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
				
				init_paramsError_expectError_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var1", 
 						refp_failReport, 1130011, 
						intfs->INTF_SET->strcsUninitNonZero->value(), intfs->INTF_SET->strcsNull->value()
						, test_xcStringS_I_findResult::GET(0,0)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var2", 
 						refp_failReport, 1130022, 
						intfs->INTF_SET->strcsUninitNonZero->value(), intfs->INTF_SET->strcsUninitZero->value()
						, test_xcStringS_I_findResult::GET(0,0)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var3", 
 						refp_failReport, 1130033, 
						intfs->INTF_SET->strcsUninitNonZero->value(), intfs->INTF_SET->strcsUninitNonZero->value()
						, test_xcStringS_I_findResult::GET(0,0)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4", 
						refp_failReport, 1130044, 
						intfs->INTF_SET->strcsUninitNonZero->value(), intfs->INTF_SET->strcsInitEmpty->value()
						, test_xcStringS_I_findResult::GET(0,0)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var5", 
						refp_failReport, 1130055, 
						intfs->INTF_SET->strcsUninitNonZero->value(), intfs->INTF_SET->strcsInitNonEmpty->value("abcd")
						, test_xcStringS_I_findResult::GET(0,0)
					)
					
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow5(
					  "fnSubstrInit[err-param.03, uninit self]"
					, "ERROR-OTHER-PARAM-NULL-OR-UNINIT"
					, init_paramsError_expectError_paramRow_t
					, init_paramsError_expectError
					, rows
				);
			}
			
			if(1)
			{
				xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
				
				init_paramsError_expectError_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var1", 
 						refp_failReport, 1140011, 
						intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsNull->value()
						, test_xcStringS_I_findResult::GET(0,0)
					)
					//, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var2", 
 					//	refp_failReport, 1140012, 
					//	intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsUninitZero->value()
					//	, test_xcStringS_I_findResult::GET(0,0)
					//)
					//, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var3", 
 					//	refp_failReport, 1140013, 
					//	intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsUninitNonZero->value()
					//	, test_xcStringS_I_findResult::GET(0,0)
					//)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4", 
						refp_failReport, 1130014, 
						intfs->INTF_SET->strcsUninitNonZero->value(), intfs->INTF_SET->strcsInitEmpty->value()
						, test_xcStringS_I_findResult::GET(0,0)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var5", 
						refp_failReport, 114015, 
						intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsInitNonEmpty->value("abcd")
						, test_xcStringS_I_findResult::GET(0,0)
					)
					
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				
				xcc_test3_case_forDataRow5(
					  "fnSubstrInit[err-param.14, init empty self]"
					, "ERROR-OTHER-PARAM-NULL-OR-UNINIT"
					, init_paramsError_expectError_paramRow_t
					, init_paramsError_expectError
					, rows
				);
			}
			
			
			if(1)
			{
				xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
				
				init_paramsError_expectError_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var1", 
 						refp_failReport, 1150011 ,
						intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsNull->value(),
						test_xcStringS_I_findResult::GET(0,0)
					)
					//, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var2", 
 					//	refp_failReport, 1150022,
					//	intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsUninitZero->value(),
					//	test_xcStringS_I_findResult::GET(0,0)
					//)
					//, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var3", 
 					//	refp_failReport, 1150033,
					//	intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsUninitNonZero->value(),
					//	test_xcStringS_I_findResult::GET(0,0)
					//)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4", 
						refp_failReport, 1150044, 
						intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsInitEmpty->value()
						, test_xcStringS_I_findResult::GET(0,0)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var5", 
						refp_failReport, 115055, 
						intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsInitNonEmpty->value("abcd")
						, test_xcStringS_I_findResult::GET(0,0)
					)
					
					, xcc_test3_DATAROWX_ITZ_TERM()
				};
				
				xcc_test3_case_forDataRow5(
					  "fnSubstrInit[err-param.04, init nonempty self]"
					, "ERROR-OTHER-PARAM-NULL-OR-UNINIT"
					, init_paramsError_expectError_paramRow_t
					, init_paramsError_expectError
					, rows
				);
			}
			
		}
		
		/* --- --- --- */
		/* --- --- --- */
		/* --- --- --- */
		
		if(1)
		{

			if(1)
			{
	/*
	qwwerty12345
	0123456789AB
	*/
				init_paramsError_expectError_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4.11", 
						refp_failReport, 1150040, 
						intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsNull->value()
						, test_xcStringS_I_findResult::GET(1,1)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4.12", 
						refp_failReport, 1150041, 
						intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsInitEmpty->value()
						, test_xcStringS_I_findResult::GET(1,1)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4.13", 
						refp_failReport, 1150042, 
						intfs->INTF_SET->strcsInitEmpty->value(), intfs->INTF_SET->strcsInitNonEmpty->value("abc")
						, test_xcStringS_I_findResult::GET(1,1)
					)
				};
				
				xcc_test3_case_forDataRow5(
					  "fnSubstrInit[err-param.04.20, initImmutable nonempty self]"
					, "TODO"
					, init_paramsError_expectError_paramRow_t
					, init_paramsError_expectError
					, rows
				);
			}

			if(1)
			{
	/*
	qwwerty12345
	0123456789AB
	*/
				init_paramsError_expectError_paramRow_t rows[]=
				{
					  xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4.11", 
						refp_failReport, 1150040, 
						intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsNull->value()
						, test_xcStringS_I_findResult::GET(1,1)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4.12", 
						refp_failReport, 1150041, 
						intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsInitEmpty->value()
						, test_xcStringS_I_findResult::GET(1,1)
					)
					, xcc_test3_DATAROW5_ITZ_T(init_paramsError_expectError_paramRow_t, "var4.13", 
						refp_failReport, 1150042, 
						intfs->INTF_SET->strcsInitNonEmpty->value("qwwerty12345"), intfs->INTF_SET->strcsInitNonEmpty->value("abc")
						, test_xcStringS_I_findResult::GET(1,1)
					)
				};
				
				xcc_test3_case_forDataRow5(
					  "fnSubstrInit[err-param.04.20, initImmutable nonempty self]"
					, "TODO"
					, init_paramsError_expectError_paramRow_t
					, init_paramsError_expectError
					, rows
				);
			}

		}
		
		/* --- --- --- */
		/* --- --- --- */
		/* --- --- --- */
		
		xcc_test2_scope_end();
	}
	
	protected: int testProcedure_validParams_immutable(xcc_test2_param_list)
	{
		xcc_test2_scope("[CSTRD]-[fnSubstrInit-immutable]");
		xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
		
		/* --- --- --- */
		/* --- --- --- */
		/* --- --- --- */
		
		/* valid Immutable == anyImmutable; nothing to do */
		
		/* --- --- --- */
		/* --- --- --- */
		/* --- --- --- */
		
		xcc_test2_scope_end();
	}
	
};


#endif
