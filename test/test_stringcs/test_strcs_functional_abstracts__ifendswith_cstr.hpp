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

#ifndef _TEST_STRINGCS_ABSTRACTS_ifEndsWithCstr_HPP_
#define _TEST_STRINGCS_ABSTRACTS_ifEndsWithCstr_HPP_
/* --- */

#include "xcc/test/xcc_test2.hpp"
#include "xcc/test/xcc_test2_paramrow.hpp"
#include "xcc/common/xcc_cpp.hpp"
/* --- */
#include "test_strcs_functional_abstracts__shared.hpp"
/* --- */


template<typename TPL_STROBJ>
class subtest_ifEndsWithCstr_tplt: public test_xcStringS_testStaticStr_sub_I<TPL_STROBJ>
{
	protected: test_xcStringS_testStaticStr_intfs_tpl<TPL_STROBJ>* intfs;
	
	protected: virtual int testedOp(test_xcStringS_I_abstract<TPL_STROBJ>* intf, TPL_STROBJ* ref_self, const char* param1)=0;
	
	public: typedef xcc_test3_DATAROW5_DECLT(
		  xcc_test2_failureDetails_t*
		, test_xcStringS_I_abstract<TPL_STROBJ>*
		, testParamValued01<TPL_STROBJ>
		, const char*
		, int
	) test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t;
	protected: int test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv(
		  xcc_test2_failureDetails_t* failInfo
		, test_xcStringS_I_abstract<TPL_STROBJ>* strIntf
		, testParamValued01<TPL_STROBJ> self
		, const char* param1_cstr
		, int resultval
	)
	{
		xcc_test2_scope_disconnected();
		
		do
		{
			xcc_test2_case("checking internal state");
			if(1)
			{
				int retv=0;
				test_xcStringS_state<TPL_STROBJ> self_state;
				test_xcStringS_state<TPL_STROBJ>* ptr_self_state=&self_state;

				xcc_test2_expect( 0 == self.intf->prepareState2(*failInfo, ptr_self_state, self.value) );
				
				xcc_test2_expect( resultval == (retv=testedOp(strIntf, ptr_self_state->refp_obj_operational, param1_cstr) ) );
				
				xcc_test2_expect( 0 == self.intf->verifyState(*failInfo, ptr_self_state, self.value.c_str()) );
				xcc_test2_expect( 0 == self.intf->deinit(*failInfo, ptr_self_state) );
			}
			xcc_test2_case_end();
			
		} while(0);
		
		xcc_test2_scope_end();
	}


	public: typedef xcc_test3_DATAROW4_DECLT(
		  xcc_test2_failureDetails_t*
		, test_xcStringS_I_abstract<TPL_STROBJ>*
		, testParamValued01<TPL_STROBJ>
		, int
	) test_ifEndsWithCstr_againstItself_expectRetv_paramRow_t;
	protected: int test_ifEndsWithCstr_againstItself_expectRetv(
		  xcc_test2_failureDetails_t* failInfo
		, test_xcStringS_I_abstract<TPL_STROBJ>* strIntf
		, testParamValued01<TPL_STROBJ> self
		, int resultval
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
				
				xcc_test2_expect( 0 == self.intf->prepareState2(*failInfo, ptr_self_state, self.value) );
				
				xcc_test2_expect( resultval == testedOp(strIntf, ptr_self_state->refp_obj_operational, strIntf->cstr( ptr_self_state->refp_obj_operational) ) );
				
				xcc_test2_expect( 0 == self.intf->verifyState(*failInfo, ptr_self_state, self.value.c_str() ) );
				
				xcc_test2_expect( 0 == self.intf->deinit(*failInfo, ptr_self_state) );
			}
			xcc_test2_case_end();
			
		} while(0);
		
		xcc_test2_scope_end();
	}
	
	
	public: subtest_ifEndsWithCstr_tplt(
		  test_xcStringS_testStaticStr_intfs_tpl<TPL_STROBJ>* ref_intfs
	) 
	{
		this->intfs=ref_intfs;
	}
	

	protected: int test_ifEndsWithCstr_ANYCASE(xcc_test2_param_list)
	{
		xcc_test2_scope("[CSTRD]-[ifEndsWithCstr]");
		
		test_xcStringS_param_I_Set_tplt<TPL_STROBJ>* ref_set=this->intfs->INTF_SET;
		xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
		
		if(1)
		{
			test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t, "var1"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsNull->value(), NULL, 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t, "var2"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsNull->value(), "", 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t, "var3"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsNull->value(), "abcd123", 0
				)
				
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "ifEndsWithCstr-[err-param.01,null self]"
				, "TODO-01"
				, test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t
				, test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv
				, rows
			);
		}
		
		if(1)
		{
			test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t, "var1"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsUninitZero->value(), NULL, 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t, "var2"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsUninitZero->value(), "", 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t, "var3"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsUninitZero->value(), "abcd123", 0
				)
				
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "ifEndsWithCstr-[err-param.02,uninit-zero-self]"
				, "TODO-01"
				, test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t
				, test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv
				, rows
			);
		}
		
		if(1)
		{
			test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t, "var1"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsUninitNonZero->value(), NULL, 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t, "var2"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsUninitNonZero->value(), "", 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t, "var3"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsUninitNonZero->value(), "abcd123", 0
				)
				
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "ifEndsWithCstr-[err-param.03,uninit-nonzero.self]"
				, "TODO-01"
				, test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t
				, test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv
				, rows
			);
		}
		
		if(1)
		{
			test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t, "var1"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitEmpty->value(), NULL, 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t, "var2"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitEmpty->value(), "", 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t, "var3"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitEmpty->value(), "abcd123", 0
				)
				
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "ifEndsWithCstr-[err-param.04,init-empty.self]"
				, "TODO-01"
				, test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t
				, test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv
				, rows
			);
		}
		
		if(1)
		{
			test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t, "var1"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), NULL, 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t, "var2"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), "", 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t, "var3"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), "abcd123", 0
				)
				
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "ifEndsWithCstr-[err-param.05,init-non-empty.self]"
				, "TODO-01"
				, test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t
				, test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv
				, rows
			);
		}
		
		
		if(1)
		{
			test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t, "var1"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitEmpty->value(), "", 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t, "var2"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("qwerty386"), ("qwerty386"), 1
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t, "var3"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("XXXX.qwerty386"), ("qwerty386"), 1
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t, "var3"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("XXXX.qwerty386"), ("XXX"), 0
				)
				
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "ifEndsWithCstr-[ok-param.01]"
				, "TODO-01"
				, test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t
				, test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv
				, rows
			);
		}
		
		xcc_test2_scope_end();
	}
	
};



template<typename TPL_STROBJ>
class subtest_ifEndsWithCstr_CaseSensitive_tplt: public subtest_ifEndsWithCstr_tplt<TPL_STROBJ>
{
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */
	
	using typename subtest_ifEndsWithCstr_tplt<TPL_STROBJ>::test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t;
	using subtest_ifEndsWithCstr_tplt<TPL_STROBJ>::intfs;
	using subtest_ifEndsWithCstr_tplt<TPL_STROBJ>::test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv;
	
	public: subtest_ifEndsWithCstr_CaseSensitive_tplt(test_xcStringS_testStaticStr_intfs_tpl<TPL_STROBJ>* ref_intfs): subtest_ifEndsWithCstr_tplt <TPL_STROBJ>(ref_intfs)
	{
	}
	
	protected: int testedOp(test_xcStringS_I_abstract<TPL_STROBJ>* intf, TPL_STROBJ* ref_self, const char* param1)
	{
		return intf->ifEndsWith_cstr(ref_self, param1);
	}
	
	public: int perform(xcc_test2_param_list)
	{
		int x=0;
		
		x+=this->test_ifEndsWithCstr_ANYCASE(xcc_test2_param_list_forward);
		x+=this->test_ifEndsWithCstr_okParamsMatchCaseSensitive(xcc_test2_param_list_forward);
		
		return x;
	}
	
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */
	
	public: int test_ifEndsWithCstr_okParamsMatchCaseSensitive(xcc_test2_param_list)
	{
		xcc_test2_scope("[CSTRD]-[ifEndsWithCstr-matchCaseSensitive]");
		
		test_xcStringS_param_I_Set_tplt<TPL_STROBJ>* ref_set=this->intfs->INTF_SET;
		xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
		
		if(1)
		{
			test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t, "var1"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), ("abcdz.123ABCZ.!@#$%^&*().zyx"), 1
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t, "var2"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), ("ABCdZ.123ABCz.!@#$%^&*().zYX"), 0
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t, "var3"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), (".zyx"), 1
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t, "var4"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123abcz.!@#$%^&*().zyx"), (".ZYX"), 0
				)
				
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "ifEndsWithCstr-[ok-param.110.case-sensitive-match-of-entire-string]"
				, "TODO-01"
				, test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t
				, test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv
				, rows
			);
		}
		
		xcc_test2_scope_end();
	}
	
};


template<typename TPL_STROBJ>
class subtest_ifEndsWithCstr_CaseInSensitive_tplt: public subtest_ifEndsWithCstr_tplt<TPL_STROBJ>
{
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */
	
	using typename subtest_ifEndsWithCstr_tplt<TPL_STROBJ>::test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t;
	using subtest_ifEndsWithCstr_tplt<TPL_STROBJ>::intfs;
	using subtest_ifEndsWithCstr_tplt<TPL_STROBJ>::test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv;

	public: subtest_ifEndsWithCstr_CaseInSensitive_tplt(test_xcStringS_testStaticStr_intfs_tpl<TPL_STROBJ>* ref_intfs): subtest_ifEndsWithCstr_tplt<TPL_STROBJ>(ref_intfs)
	{
	}

	protected: int testedOp(test_xcStringS_I_abstract<TPL_STROBJ>* intf, TPL_STROBJ* ref_self, const char* param1)
	{
		return intf->ifEndsWithNC_cstr(ref_self, param1);
	}
	
	public: int perform(xcc_test2_param_list)
	{
		int x=0;
		
		x+=this->test_ifEndsWithCstr_ANYCASE(xcc_test2_param_list_forward);
		x+=this->test_ifEndsWithCstr_okParamsMatchCaseInsensitive(xcc_test2_param_list_forward);
		
		return x;
	}
	
	/* --- --- --- --- */
	/* --- --- --- --- */
	/* --- --- --- --- */
	
	public: int test_ifEndsWithCstr_okParamsMatchCaseInsensitive(xcc_test2_param_list)
	{
		xcc_test2_scope("[CSTRD]-[ifEndsWithCstr-matchCaseInsensitive]");
		
		test_xcStringS_param_I_Set_tplt<TPL_STROBJ>* ref_set=this->intfs->INTF_SET;
		xcc_test2_failureDetails_t* refp_failReport=xcc_test2_case_referp_customFailInfo();
		
		if(1)
		{
			test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t rows[]=
			{
				  xcc_test3_DATAROW5_ITZ_T(test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t, "var1"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), ("abcdz.123ABCZ.!@#$%^&*().zyx"), 1
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t, "var2"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), ("ABCdZ.123ABCz.!@#$%^&*().zYX"), 1
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t, "var3"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123ABCZ.!@#$%^&*().zyx"), (".zyx"), 1
				)
				, xcc_test3_DATAROW5_ITZ_T(test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t, "var4"
					, refp_failReport, intfs->INTF_STATICSTR
					, intfs->INTF_SET->strcsInitNonEmpty->value("abcdz.123abcz.!@#$%^&*().zyx"), (".ZYX"), 1
				)
				
				, xcc_test3_DATAROWX_ITZ_TERM()
			};
			
			xcc_test3_case_forDataRow5(
				  "ifEndsWithCstr-[ok-param.110.case-insensitive-match-of-entire-string]"
				, "TODO-01"
				, test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv_paramRow_t
				, test_ifEndsWithCstr_ANYCASE_paramsError_expectRetv
				, rows
			);
		}
		
		xcc_test2_scope_end();
	}
	
};

#endif
