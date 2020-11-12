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

#ifndef _TEST_STRINGCS_ABSTRACTS_SHARED_HPP_
#define _TEST_STRINGCS_ABSTRACTS_SHARED_HPP_
/* --- */

#include "xcc/test/xcc_test2.hpp"
#include "xcc/common/xcc_cpp.hpp"
/* --- */
/* --- */


/* ---- ----- ----- ----- */
/* ---- ----- ----- ----- */
/* ---- ----- ----- ----- */


struct test_xcStringS_I_findResult
{
	
	public: int len;
	public: int off;
	
	public: static test_xcStringS_I_findResult GET(int off, int len)
	{
		test_xcStringS_I_findResult  retv={0};
		
		retv.off=off;
		retv.len=len;
		
		return retv;
	}
	
	public: static test_xcStringS_I_findResult GET_VALID(int off)
	{
		test_xcStringS_I_findResult  retv={0};
		
		retv.off=off;
		retv.len=0;
		
		return retv;
	}

	public: static test_xcStringS_I_findResult GET_INVALID()
	{
		test_xcStringS_I_findResult  retv={0};
		
		retv.off=-1;
		retv.len=-1;
		
		return retv;
	}
	
};

template<typename TPL_STR_T>
class test_xcStringS_I_abstract
{
	public: virtual int init_sameObj(TPL_STR_T* refp_self, const TPL_STR_T* refp_src)=0;
	public: virtual int init_cstr(TPL_STR_T* refp_self, const char* refp_src)=0;
	public: int (*init_fmt)(TPL_STR_T* refp_self, const char* fmt, ...);
	
	public: virtual int cmpEq_sameObj(TPL_STR_T* refp_self, const TPL_STR_T* refp_src)=0;
	public: virtual int cmpEq_cstr(TPL_STR_T* refp_self, const char* refp_src)=0;
	
	public: virtual int cmpEq_sameObj_NOCASE(TPL_STR_T* refp_self, const TPL_STR_T* refp_src)=0;
	public: virtual int cmpEq_cstr_NOCASE(TPL_STR_T* refp_self, const char* refp_src)=0;

	
	public: virtual int deinit(TPL_STR_T* refp_self)=0;

	public: virtual int get_length(const TPL_STR_T* refp_self)=0;
	public: virtual size_t get_capacity(const TPL_STR_T* refp_self)=0;
	
	public: virtual int contains_cstr(TPL_STR_T* refp_self, const char* cstr)=0;
	public: virtual int containsNC_cstr(TPL_STR_T* refp_self, const char* cstr2)=0;
	public: virtual int contains_obj(TPL_STR_T* refp_self, const TPL_STR_T* refp_src)=0;
	public: virtual int containsNC_obj(TPL_STR_T* refp_self, const TPL_STR_T* refp_src)=0;
	
	public: virtual int startsWith(TPL_STR_T* refp_self, const TPL_STR_T* refp_src)=0;
	public: virtual int startsWithNC(TPL_STR_T* refp_self, const TPL_STR_T* refp_src)=0;

	public: virtual int ifEndsWith(TPL_STR_T* refp_self, const TPL_STR_T* refp_src)=0;
	public: virtual int ifEndsWithNC(TPL_STR_T* refp_self, const TPL_STR_T* refp_src)=0;
	public: virtual int ifEndsWith_cstr(TPL_STR_T* refp_self, const char* refp_src)=0;
	public: virtual int ifEndsWithNC_cstr(TPL_STR_T* refp_self, const char* refp_src)=0;
	
	public: virtual const char* cstr(const TPL_STR_T* refp_self)=0;
	
	public: virtual int TEST_produceUninitNotZero(TPL_STR_T* refp_target)=0;
	
	public: virtual int findNext(TPL_STR_T* refp_self, const int off, const TPL_STR_T* refp_src, test_xcStringS_I_findResult* result)=0;
	public: virtual int findNextNC(TPL_STR_T* refp_self, const int off, const TPL_STR_T* refp_src, test_xcStringS_I_findResult* result)=0;
	public: virtual int findNext_cstr(TPL_STR_T* refp_self, const int off, const char* refp_src, test_xcStringS_I_findResult* result)=0;
	public: virtual int findNextNC_cstr(TPL_STR_T* refp_self, const int off, const char* refp_src, test_xcStringS_I_findResult* result)=0;
	
	public: virtual int substr_init(TPL_STR_T* target, test_xcStringS_I_findResult* info, TPL_STR_T* result)=0;
	
};

template<typename TPL_STR_T, typename TPL_FINDRESULT_T>
class test_xcStringS_I2_abstract
{
	public: virtual int findNext(TPL_STR_T* refp_self, const int off, const TPL_STR_T* refp_src, TPL_FINDRESULT_T* result)=0;
	public: virtual int findNextNC(TPL_STR_T* refp_self, const int off, const TPL_STR_T* refp_src, TPL_FINDRESULT_T* result)=0;
};



/* ---- ----- ----- ----- */
/* ---- ----- ----- ----- */
/* ---- ----- ----- ----- */




class test_xcStringS_expectedState
{
	public: TVal<int> capacity;
	public: TVal<int> length;
	public: std::string content;
};

static test_xcStringS_expectedState XCSTRINGD_EXPECTED_STATE(const int length, std::string content)
{
	test_xcStringS_expectedState retv;
	
	retv.length=length;
	retv.content=content;
	
	return retv;
}

class test_xcStringS_verify_CalcAlloc_I_abstract
{
	public: virtual int calcCapacityAllocForLength(const int length, int& result) =0;
};



template <class TPL_STROBJ>
class test_xcStringS_state
{
	public: TPL_STROBJ obj_initial;
	public: TPL_STROBJ obj_operational;
	public: TPL_STROBJ* refp_obj_operational;
};


template <class TPL_STROBJ>
class test_xcStringS_verify_handleState_I_abstract
{
	protected: TObjRef<test_xcStringS_verify_CalcAlloc_I_abstract> calcCapacity_I;
	public: virtual int verify_state(xcc_test2_failureDetails_t& failInfo, TPL_STROBJ* refp_target, test_xcStringS_expectedState refp_state) noexcept =0;
	public: virtual int verify_state_isUninitZero(xcc_test2_failureDetails_t& failInfo, TPL_STROBJ* refp_target) noexcept =0;
	public: virtual int verify_state_isUninitNonzero(xcc_test2_failureDetails_t& failInfo, TPL_STROBJ* refp_target) noexcept =0;
	public: virtual int verify_state_isInitEmpty(xcc_test2_failureDetails_t& failInfo, TPL_STROBJ* refp_target) noexcept =0;
	public: virtual int verify_state_null(xcc_test2_failureDetails_t& failInfo, TPL_STROBJ* refp_target) noexcept =0;
	public: virtual int verify_state_content(xcc_test2_failureDetails_t& failInfo, TPL_STROBJ* refp_target, std::string content_str) noexcept =0;

	public: virtual int prepare_state_null(test_xcStringS_state<TPL_STROBJ>& refp_targetState) noexcept =0;
	public: virtual int prepare_state_uninitZero(test_xcStringS_state<TPL_STROBJ>& refp_targetState) noexcept =0;
	public: virtual int prepare_state_uninitNonzero(test_xcStringS_state<TPL_STROBJ>& refp_targetState) noexcept =0;
	public: virtual int prepare_state_initEmpty(test_xcStringS_state<TPL_STROBJ>& refp_targetState) noexcept =0;
	public: virtual int prepare_state_initContent01(test_xcStringS_state<TPL_STROBJ>& refp_targetState, std::string content) noexcept =0;
	
	public: virtual int deinitialize_state(test_xcStringS_state<TPL_STROBJ>& refp_targetState) noexcept =0;
};

template <class TPL_STROBJ>
class test_xcStringS_verify_I
{
	public: test_xcStringS_verify_I(
		  test_xcStringS_verify_handleState_I_abstract<TPL_STROBJ>* handleState_I
	)
	{
		this->handleState_I=handleState_I;
	}
	
	private: TObjRef< test_xcStringS_verify_handleState_I_abstract<TPL_STROBJ> > handleState_I;
	
	public: int verify_state( xcc_test2_failureDetails_t& failInfo, TPL_STROBJ* refp_target, test_xcStringS_expectedState refp_state)
	{
		
		handleState_I.val()->verify_state(failInfo, refp_target, refp_state);
		
		return 0;
	}
};




/* ---- ----- ----- ----- */
/* ---- ----- ----- ----- */
/* ---- ----- ----- ----- */










template <class TPL_STROBJ>
class test_xcStringS_param_I_abstract;

	template <class TPL_STROBJ>
	class testParamValued01
	{
		public: testParamValued01() {
			
		}
		
		public: testParamValued01(test_xcStringS_param_I_abstract<TPL_STROBJ>* argParam1, std::string initial_value)
		{
			this->intf=argParam1;
			this->value=initial_value;
		}
		
		public: test_xcStringS_param_I_abstract<TPL_STROBJ>* intf;
		public: std::string value;
	};



template <class TPL_STROBJ>
class test_xcStringS_param_I_abstract
{
	
	public: test_xcStringS_param_I_abstract(test_xcStringS_verify_CalcAlloc_I_abstract* argParam1)
	{
		this->calcCapacity_I=argParam1;
	}
	
	public: test_xcStringS_verify_CalcAlloc_I_abstract* calcCapacity_I;





	
	public: testParamValued01<TPL_STROBJ> value(std::string initial_value) // const
	{
		return testParamValued01<TPL_STROBJ>(this, initial_value);
	}

	public: testParamValued01<TPL_STROBJ> value() // const
	{
		return testParamValued01<TPL_STROBJ>(this, std::string(""));
	}
	


	
	
	public: virtual int prepareState2(xcc_test2_failureDetails_t& failInfo, test_xcStringS_state<TPL_STROBJ>* refp_targetState, std::string content) =0;
	public: virtual int verifyState(xcc_test2_failureDetails_t& failInfo, test_xcStringS_state<TPL_STROBJ>* refp_targetState, std::string content) =0;
	public: virtual int deinit(xcc_test2_failureDetails_t& failInfo, test_xcStringS_state<TPL_STROBJ>* refp_targetState) =0;
};



template <class TPL_STROBJ>
class test_xcStringS_param_I_Set_tplt
{
	public: test_xcStringS_param_I_Set_tplt(
		  //const test_xcStringS_I_abstract<TPL_STROBJ>* ref_strI
		  test_xcStringS_param_I_abstract<TPL_STROBJ>* ref_null
		, test_xcStringS_param_I_abstract<TPL_STROBJ>* ref_uninitZero
		, test_xcStringS_param_I_abstract<TPL_STROBJ>* ref_uninitNonZero
		, test_xcStringS_param_I_abstract<TPL_STROBJ>* ref_initEmpty
		, test_xcStringS_param_I_abstract<TPL_STROBJ>* ref_initNonEmpty
	)
	{
		
		//this->ref_strI=ref_strI;
		this->strcsNull=ref_null;
		this->strcsUninitZero=ref_uninitZero;
		this->strcsUninitNonZero=ref_uninitNonZero;
		this->strcsInitEmpty=ref_initEmpty;
		this->strcsInitNonEmpty=ref_initNonEmpty;
	}
	
	//public: const test_xcStringS_I_abstract<TPL_STROBJ>* ref_strI;
	public: test_xcStringS_param_I_abstract<TPL_STROBJ>* strcsNull;
	public: test_xcStringS_param_I_abstract<TPL_STROBJ>* strcsUninitZero;
	public: test_xcStringS_param_I_abstract<TPL_STROBJ>* strcsUninitNonZero;
	public: test_xcStringS_param_I_abstract<TPL_STROBJ>* strcsInitEmpty;
	public: test_xcStringS_param_I_abstract<TPL_STROBJ>* strcsInitNonEmpty;
};






/* ---- ----- ----- ----- */
/* ---- ----- ----- ----- */
/* ---- ----- ----- ----- */





#define xcc_test2_caseDo(_ID_, _DESCRIPTION_, _FN_) do {\
		xcc_test2_case_descr(_ID_, _DESCRIPTION_);\
		if(1)\
		{\
			xcc_test2_expect( 0 == _FN_ );\
		}\
		xcc_test2_case_end();\
} while(0);




/* ---- ----- ----- ----- */
/* ---- ----- ----- ----- */
/* ---- ----- ----- ----- */




template<typename TPL_STR_T>
class test_xcStringS_testStaticStr_intfs_tpl
{
	public: test_xcStringS_I_abstract<TPL_STR_T>* INTF_STATICSTR;
	public: test_xcStringS_param_I_Set_tplt<TPL_STR_T>* INTF_SET;
	
	
	public: test_xcStringS_testStaticStr_intfs_tpl() {}
	
	public: test_xcStringS_testStaticStr_intfs_tpl(
		  test_xcStringS_I_abstract<TPL_STR_T>* refp_INTF_STATICSTR
		, test_xcStringS_param_I_Set_tplt<TPL_STR_T>* INTF_SET
	)
	{
		this->INTF_STATICSTR=refp_INTF_STATICSTR;
		this->INTF_SET=INTF_SET;
	}
};

template<typename TPL_STR_T>
class test_xcStringS_testStaticStr_sub_I
{
	public: virtual int perform(xcc_test2_param_list)=0;
};



/* ---- ----- ----- ----- */
/* ---- ----- ----- ----- */
/* ---- ----- ----- ----- */







#endif
