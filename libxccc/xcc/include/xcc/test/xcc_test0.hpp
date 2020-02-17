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

#ifndef _XCC_TEST_HPP_
#define _XCC_TEST_HPP_

#include <stdio.h>
#include <string>
#include <sstream>

/* *** *** */
/* test: done */
/* *** *** */



typedef struct xcc_test0_data_scopeInfo
{
	char filename[256];
	char fnname[256];
	int line;
} xcc_test0_data_scopeInfo;

xcc_test0_data_scopeInfo xcc_test0_data_scopeInfo_LL_initializer(const char* filename, const char* fnname, const int line);
#define xcc_test0_data_scopeInfo_initializer() xcc_test0_data_scopeInfo_LL_initializer(__FILE__, __FUNCTION__, __LINE__)



typedef struct xcc_test0_data_annotation
{
	char static_part[256];
	char runtime_part[256];
} xcc_test0_data_annotation;

xcc_test0_data_annotation xcc_test0_data_annotation_initializer(const char* static_str, const char* runtime_str_fmt, ...);

typedef struct xcc_test0_data_failInfo
{
	xcc_test0_data_scopeInfo scopeInfo;
	xcc_test0_data_annotation annotation;
	
} xcc_test0_data_failInfo;

xcc_test0_data_failInfo xcc_test0_data_failInfo_LL_initializer(xcc_test0_data_scopeInfo scopeInfo, xcc_test0_data_annotation annotation);
#define xcc_test0_data_failInfo_itz( _ANNOTATION_OBJ_ ) xcc_test0_data_failInfo_LL_initializer( xcc_test0_data_scopeInfo_initializer(), _ANNOTATION_OBJ_ ) 


class xcc_test0_procedure
{
	private: int silent;
	public: std::string proc_id;
	private: xcc_test0_data_scopeInfo cur_scope;
	private: xcc_test0_data_failInfo last_fail;
	private: int error_cnt;
	private: int trap_enabled;
	
	private: xcc_test0_data_scopeInfo last_case_scope;
	private: std::string last_case_id;
	
	private: xcc_test0_data_scopeInfo cur_annotation_scope;
	xcc_test0_data_annotation cur_annotation_data;
	
	public: int isError()
	{
		return !!error_cnt;
	}
	
	public: void test_case(xcc_test0_data_scopeInfo scopeInfo, const char* case_id)
	{
		
		this->last_case_id.assign( ( case_id)? case_id: "" );
		this->last_case_scope=scopeInfo;
		
		return;
	}
	
	public: void case_print_start()
	{
		if( 0 == this->silent)
		{
			fprintf(stdout, ">>>\t\t-------- -------- -------- --------\n"); \
			fprintf(stdout, ">>>\t\t[%s]: test case: [%s]: \n",  this->proc_id.c_str(), this->last_case_id.c_str() );
			fprintf(stdout, ">>>\t\t-------- -------- -------- --------\n"); \
		}

		return;
	}
	public: void case_print_end()
	{
		if( 0 == this->error_cnt )
		{
			if(0 == this->silent )
			{
				fprintf(stdout, ">>>\t\t-------- -------- -------- --------\n"); \
				fprintf(stdout, ">>>\t\t[%s]: test case: [%s]: (OK)\n",  this->proc_id.c_str(), this->last_case_id.c_str() );
				fprintf(stdout, ">>>\t\t-------- -------- -------- --------\n"); \
			}
		}
		else
		{
			fprintf(stdout, ">>>\t\t-------- -------- -------- --------\n"); \
			fprintf(stdout, ">>>\t\t[%s]: test case: [%s]: (FAIL): // [%s]:[%d]\n",  
				  this->proc_id.c_str()
				, this->last_case_id.c_str() 
				, this->cur_scope.fnname
				, this->cur_scope.line
			);
			fprintf(stdout, ">>>\t\t-------- -------- -------- --------\n"); \
			fprintf(stdout, ">>>\t\t\t file=[%s] \n", this->last_fail.scopeInfo.filename);
			fprintf(stdout, ">>>\t\t\t fn=[%s]:[%d] \n", this->last_fail.scopeInfo.fnname, this->last_fail.scopeInfo.line);
			/*fprintf(stdout, ">>>\t\t\t info=[%s]:[%s] \n", this->last_fail.annotation.static_part, this->last_fail.annotation.runtime_part);*/
			fprintf(stdout, ">>>\t\t-------- -------- -------- --------\n"); \
			fprintf(stdout, ">>>\t\t[%s]: test case: [%s]: (FAIL): summary done\n",  this->proc_id.c_str(), this->last_case_id.c_str() );
			fprintf(stdout, ">>>\t\t-------- -------- -------- --------\n"); \
		}
		
		return;
	}
	
	public: xcc_test0_procedure(xcc_test0_data_scopeInfo scopeInfo, const char* test_proc_id, int arg_silent)
	{
		
		this->cur_annotation_data=xcc_test0_data_annotation();
		this->cur_annotation_scope=xcc_test0_data_scopeInfo();
		this->cur_scope=xcc_test0_data_scopeInfo();
		this->error_cnt=0;
		this->last_case_id="";
		this->last_case_scope=xcc_test0_data_scopeInfo();
		this->last_fail=xcc_test0_data_failInfo();
		this->silent=0;
		this->trap_enabled=0;
		
		
		
		this->cur_scope=scopeInfo;
		this->proc_id.assign( (test_proc_id)?test_proc_id:"" );
		this->silent=arg_silent;
	}
	
	public: void scope_print_start()
	{
		if( 0 == this->silent)
		{
			fprintf(stdout, ">>>\t-------- -------- -------- --------\n"); \
			fprintf(stdout, ">>>\t[%s]: test scope::\n",  this->proc_id.c_str() );
			fprintf(stdout, ">>>\t-------- -------- -------- --------\n"); \
		}

		return;
	}
	
	public: void annotate(xcc_test0_data_scopeInfo scopeInfo, xcc_test0_data_annotation annotation_data)
	{
		this->cur_annotation_scope=scopeInfo;
		this->cur_annotation_data=annotation_data;
	
		fprintf(stdout, ">>> ??? fn=[%s]:[%d]: info=[%s]:[%s]\n", 
			  this->cur_annotation_scope.fnname
			, this->cur_annotation_scope.line
			, this->cur_annotation_data.static_part
			, this->cur_annotation_data.runtime_part
		);
		
		return;
	}
	
	public: void scope_print_end()
	{
		if( 0 == this->error_cnt )
		{
			if(0 == this->silent )
			{
				fprintf(stdout, ">>>\t-------- -------- -------- --------\n"); \
				fprintf(stdout, ">>>\t[%s]: test scope: (OK):\n",  this->proc_id.c_str() );
				fprintf(stdout, ">>>\t-------- -------- -------- --------\n"); \
			}
		}
		else
		{
			fprintf(stdout, ">>>\t-------- -------- -------- --------\n"); \
			fprintf(stdout, ">>>\t[%s]: test scope: (FAIL):\n",  this->proc_id.c_str() );
			fprintf(stdout, ">>>\t-------- -------- -------- --------\n"); \
			fprintf(stdout, ">>>\t\t file=[%s] \n", this->last_fail.scopeInfo.filename);
			fprintf(stdout, ">>>\t\t fn=[%s]:[%d] \n", this->last_fail.scopeInfo.fnname, this->last_fail.scopeInfo.line);
			/*fprintf(stdout, ">>>\t\t info=[%s]:[%s] \n", this->last_fail.annotation.static_part, this->last_fail.annotation.runtime_part);*/
			fprintf(stdout, ">>>\t-------- -------- -------- --------\n"); \
			fprintf(stdout, ">>>\t[%s]: test scope: (FAIL): summary done\n",  this->proc_id.c_str() );
			fprintf(stdout, ">>>\t-------- -------- -------- --------\n"); \
		}
		
		return;
	}
	
	public: void fail(xcc_test0_data_failInfo failInfo)
	{
		this->error_cnt++;
		this->last_fail=failInfo;
		
		return;
	}
	
	public: void print_fail()
	{
		fprintf(stdout, ">>> <!!!!> test proc [%s]: FAIL at [%d] //%s\n", this->proc_id.c_str(), this->last_fail.scopeInfo.line, this->last_fail.scopeInfo.fnname );
		return;
	}
	
};


#define xcc_test0_scope(_STR_LABEL_) \
	xcc_test0_procedure t__testScope=xcc_test0_procedure( xcc_test0_data_scopeInfo_initializer(), _STR_LABEL_, 0); \
	t__testScope.scope_print_start(); \
	try { \
	;


#define xcc_test0_scope_silent() \
	xcc_test0_procedure t__testScope=xcc_test0_procedure( xcc_test0_data_scopeInfo_initializer(), "", 1); \
	try { \
	;


#define xcc_test0_scope_end() \
		t__testScope.scope_print_end(); \
		return 0;  \
	} \
	catch(...) {\
		t__testScope.scope_print_end(); \
		return  1; \
	}\
	;




#define xcc_test0_case(_STR_LABEL_) \
	/*xcc_test0_procedure t__testScope_case=xcc_test0_procedure( xcc_test0_data_scopeInfo_initializer(), _STR_LABEL_, 1);*/\
	/*t__testScope_case.scope_print_start();*/\
	try { \
			t__testScope.test_case( xcc_test0_data_scopeInfo_initializer(), (_STR_LABEL_) );\
			t__testScope.case_print_start(); \
			;

#define xcc_test0_case_end() \
			t__testScope.case_print_end(); \
			if( 0 != t__testScope.isError() ) { \
				throw int(1);\
			} \
		}\
		catch(...)\
		{\
			t__testScope.case_print_end(); \
			if( 0 != t__testScope.isError() ) { \
				throw int(1);\
			} \
		}\
	;

#define xcc_test0_term() if(1) {\
		t__testScope.fail( xcc_test0_data_failInfo_itz( xcc_test0_data_annotation_initializer("", "") ) );\
		t__testScope.print_fail();\
		throw 3;\
	}

#define xcc_test0_fail() if(1) {\
		t__testScope.fail( xcc_test0_data_failInfo_itz( xcc_test0_data_annotation_initializer("", "") ) );\
		t__testScope.print_fail();\
		throw 2;\
	}


#define xcc_test0_case_step_annotate(_ARG_STR_) do { \
		t__testScope.annotate( xcc_test0_data_scopeInfo_initializer(), xcc_test0_data_annotation_initializer(_ARG_STR_, "") ); \
	} while(0);





















int xcc_test0_msg(const char* fmt, ...);



int aaa();

inline int aaa()
{
	return 0;
}


#define xcc_test0_breakpoint(_CONDITION_, _STMT_) if(_CONDITION_) { _STMT_; } else { }

#define xcc_test0_trap() do { aaa(); } while(0);

#define xcc_test0_trap_set(_ARG_) do {   } while(0);


#define xcc_test0_expect(_STMT_) if( 0 == (_STMT_) ) { xcc_test0_trap(); xcc_test0_fail(); } else { }

template<typename TPL_T>
inline int xcc_test0_expect_eq_tpl(const TPL_T expected, const TPL_T result, const char* fnname, const int line)
{
	char tmpbuf[128]={0};
	std::string tmp_result;
	std::string tmp_expected;
	std::stringstream tmp;
	
	tmp<<result;
	tmp_result=tmp.str();
	tmp.str("");
	
	tmp<<expected;
	tmp_expected=tmp.str();
	tmp.str("");
	
	snprintf(tmpbuf, sizeof(tmpbuf), ">>> <!!!!> FAIL: expected [%s], got [%s] // [%s]:[%d]", tmp_expected.c_str(), tmp_result.c_str(), fnname, line );
	
	if( expected != (result) ) {
		fprintf(stderr, "%s\n", tmpbuf);
		return 1;
	} 
	else { }
	
	return 0;
}

template<typename TPL_T>
inline int xcc_test0_expect_neq_tpl(const TPL_T expected, const TPL_T result, const char* fnname, const int line)
{
	char tmpbuf[128]={0};
	std::string tmp_result;
	std::string tmp_expected;
	std::stringstream tmp;
	
	tmp<<result;
	tmp_result=tmp.str();
	tmp.str("");
	
	tmp<<expected;
	tmp_expected=tmp.str();
	tmp.str("");
	
	snprintf(tmpbuf, sizeof(tmpbuf), ">>> <!!!!> FAIL: NOT expected [%s], got [%s] // [%s]:[%d]", tmp_expected.c_str(), tmp_result.c_str(), fnname, line );
	
	if( expected == (result) ) {
		fprintf(stderr, "%s\n", tmpbuf);
		return 1;
	} 
	else { }
	
	return 0;
}


#define xcc_test0_expect_eq_t(_TYPE_, _EXPECTED_RETV_, _STMT_RETV_) if(1) { if( 0 != xcc_test0_expect_eq_tpl<_TYPE_> (_EXPECTED_RETV_, _STMT_RETV_, __FUNCTION__, __LINE__ ) ) {\
			xcc_test0_trap();\
			xcc_test0_fail();\
		}\
		else { }\
	}
	
#define xcc_test0_expect_neq_t(_TYPE_, _EXPECTED_RETV_, _STMT_RETV_) if(1) { if( 0 != xcc_test0_expect_neq_tpl<_TYPE_> (_EXPECTED_RETV_, _STMT_RETV_, __FUNCTION__, __LINE__ ) ) {\
			xcc_test0_trap();\
			xcc_test0_fail();\
		}\
		else { }\
	}



#define xcc_test0_expect_int_eq(_EXPECTED_VAL_, _STMT_) do {\
	int tmp_val=0;\
	tmp_val = (_STMT_);\
	if( tmp_val != (_EXPECTED_VAL_) ) {\
		fprintf(stderr, ">>> <!!!!> FAIL: expected [%d], got [%d] // [%s]:[%d]\n", _EXPECTED_VAL_, tmp_val, __FUNCTION__, __LINE__);\
		xcc_test0_trap();\
		xcc_test0_fail();\
	} else { }\
} while(0);

#define xcc_test0_expect_int_neq(_EXPECTED_VAL_, _STMT_) do {\
	int tmp_val=0;\
	tmp_val = (_STMT_);\
	if( (_EXPECTED_VAL_) == (tmp_val) ) {\
		fprintf(stderr, ">>>> <!!!!> FAIL: expected not [%d], got [%d] // [%s]:[%d]\n", _EXPECTED_VAL_, tmp_val, __FUNCTION__, __LINE__);\
		xcc_test0_trap();\
		xcc_test0_fail();\
	} else {  }\
} while(0);
















































#if 0


class xcc_test0_printing_I_adt
{
	public: virtual void testScope_start_print(const xc_test_data_t* refp_data)=0;
	public: virtual void testScope_end_print(const xc_test_data_t* refp_data)=0;
	
	public: virtual void testCase_start_print(const xc_test_data_t* refp_data)=0;
	public: virtual void testCase_end_print(const xc_test_data_t* refp_data)=0;
	
	public: virtual void testCase_annotate_step(xc_test_data_t* refp_data, const int line, const char* arg_str)=0;
};


class xcc_test0_printing_I_xml : public xcc_test0_printing_I_adt
{
	
	public: void testCase_annotate_step(xc_test_data_t* refp_data, const int line, const char* arg_str)
	{
		if(NULL==refp_data) {
			fprintf(stdout, "\t<TEST-INTERNAL-FAILURE></<TEST-INTERNAL-FAILURE>\n");
			return;
		}
		
		refp_data->step_cnt++; 
		fprintf(stdout, "\t\t--- step [%d] line [%d]; [%s]\n", refp_data->step_cnt, line, NULL!=arg_str?  arg_str : "<NULL!>");
		
		return;
	}

	public: void testScope_start_print(const xc_test_data_t* refp_data)
	{
		if(NULL==refp_data) {
			fprintf(stdout, "\t<TEST-INTERNAL-FAILURE></<TEST-INTERNAL-FAILURE>\n");
			return;
		}
		
		fprintf(stdout, "\n");
		fprintf(stdout, "\t<TEST-SEQUENCE>\n");
		fprintf(stdout, "\t\t<TEST-SEQUENCE-CONTENT>\n");
		fprintf(stdout, "\n");
		
		/*
		 *	fprintf(stdout, "\t======== ======== ======== =========\n");
		 *	fprintf(stdout, "[%s]:\n",  refp_data->cur_label_str);
		 *	fprintf(stdout, "\t-------- -------- -------- --------\n");
		 */
		
		return;

	}
	
	public: void testScope_end_print(const xc_test_data_t* refp_data)
	{
		if(0!=refp_data->err_cnt)
		{
			fprintf(stdout, "\n");
			fprintf(stdout, "\t\t</TEST-SEQUENCE-CONTENT>\n");
			fprintf(stdout, "\t\t<TEST-SEQUENCE-SUMMARY>\n");
			fprintf(stdout, "[%s]\n", refp_data->cur_label_str);
			fprintf(stdout, "ERROR LINE=[%d]\n", refp_data->test_fail_line );
			fprintf(stdout, "ERROR CNT=[%d]\n", refp_data->err_cnt);
			fprintf(stdout, "OPERATIONS DONE=[%d]\n", refp_data->step_cnt);
			fprintf(stdout, "\t\t</TEST-SEQUENCE-SUMMARY>\n");
			fprintf(stdout, "\t</TEST-SEQUENCE>\n");

			/*
			*fprintf(stdout, "\t-------- -------- -------- -------- -------- --------\n"); \
			*fprintf(stdout, "\n[%s]: done ERROR! error line=[%d] cnt=[%d]\n",  t__testdata_seq.cur_label_str, t__testdata_seq.test_fail_line, t__testdata_seq.err_cnt); \
			*fprintf(stdout, "\t======== ======== ======== ========= ======== ======== \n"); \
			*/
		}
		else
		{
			fprintf(stdout, "\n");
			fprintf(stdout, "\t\t</TEST-SEQUENCE-CONTENT>\n");
			fprintf(stdout, "\t\t<TEST-SEQUENCE-SUMMARY>\n");
			fprintf(stdout, "[%s]\n", refp_data->cur_label_str);
			fprintf(stdout, "SUCCESS\n");
			fprintf(stdout, "ERROR CNT=[%d]\n", refp_data->err_cnt);
			fprintf(stdout, "OPERATIONS DONE=[%d]\n", refp_data->step_cnt);
			fprintf(stdout, "\t\t</TEST-SEQUENCE-SUMMARY>\n");
			fprintf(stdout, "\t</TEST-SEQUENCE>\n");
			/*
			*fprintf(stdout, "\t-------- -------- -------- -------- -------- --------\n"); \
			*fprintf(stdout, "\n[%s]: done OK\n",  t__testdata_seq.cur_label_str); \
			*fprintf(stdout, "\t======== ======== ======== ========= ======== ======== \n"); \
			*/
		}

		return;
	}
	
	public: void testCase_start_print(const xc_test_data_t* refp_data)
	{
		if(NULL==refp_data) {
			fprintf(stdout, "\t<TEST-INTERNAL-FAILURE></<TEST-INTERNAL-FAILURE>\n");
			return;
		}
		
		if(0!=refp_data->silent) {
			return;
		}

		fprintf(stdout, "\n");
		fprintf(stdout, "\t\t<TEST-CASE>\n");
		
		//fprintf(stdout, "\t\t\t<TEST-CASE-TITLE>\n");
		//fprintf(stdout, "[%s]\n",  refp_data->cur_label_str);
		//fprintf(stdout, "\t\t\t</TEST-CASE-TITLE>\n");
		fprintf(stdout, "\t\t\t<TEST-CASE-TITLE> ");
		fprintf(stdout, "[%s]",  refp_data->cur_label_str);
		fprintf(stdout, "  </TEST-CASE-TITLE>\n");

		
		fprintf(stdout, "\t\t<TEST-CASE-CONTENT>\n");
		fprintf(stdout, "\n");

		/*
		*	fprintf(stdout, "\t======== ======== ======== =========\n"); \
		*	fprintf(stdout, "\t[%s]:\n",  t__testdata.cur_label_str); \
		*	fprintf(stdout, "\t-------- -------- -------- --------\n"); \
		*/
		
		return;
	}
	
	public: void testCase_end_print(const xc_test_data_t* refp_data)
	{
		if(NULL==refp_data) {
			fprintf(stdout, "\t<TEST-INTERNAL-FAILURE></<TEST-INTERNAL-FAILURE>\n");
			return;
		}
		
		if( 0 != xcc_test0_case_isError(refp_data) ) {
			fprintf(stdout, "\n");
			fprintf(stdout, "\t\t\t<TEST-CASE-SUMMARY>\n");
			fprintf(stdout, "[%s]\n",  refp_data->cur_label_str);
			fprintf(stdout, "ERROR\n" );
			fprintf(stdout, "ERROR LINE=[%d]\n",  refp_data->test_fail_line);
			fprintf(stdout, "ERROR CNT=[%d]\n",  refp_data->err_cnt);
			fprintf(stdout, "\t\t\t</TEST-CASE-SUMMARY>\n");
			fprintf(stdout, "\t\t</TEST-CASE-CONTENT>\n");
			fprintf(stdout, "\t\t</TEST-CASE>\n");
			fprintf(stdout, "\n");
		}
		else {
			fprintf(stdout, "\n");
			fprintf(stdout, "\t\t\t<TEST-CASE-SUMMARY>\n");
			fprintf(stdout, "[%s]\n",  refp_data->cur_label_str);
			fprintf(stdout, "SUCCESS\n");
			fprintf(stdout, "\t\t\t</TEST-CASE-SUMMARY>\n");
			fprintf(stdout, "\t\t</TEST-CASE-CONTENT>\n");
			fprintf(stdout, "\t\t</TEST-CASE>\n");
			fprintf(stdout, "\n");
		}
		
		return;
	}
	
};


class xcc_test0_printing_I_txt : public xcc_test0_printing_I_adt
{
	
	public: void testCase_annotate_step(xc_test_data_t* refp_data, const int line, const char* arg_str)
	{
		if(NULL==refp_data) {
			fprintf(stdout, "\t<TEST-INTERNAL-FAILURE></<TEST-INTERNAL-FAILURE>\n");
			return;
		}
		
		refp_data->step_cnt++; 
		fprintf(stdout, "\t\t--- step [%d] line [%d]; [%s]\n", refp_data->step_cnt, line, NULL!=arg_str?  arg_str : "<NULL!>");
		
		return;
	}

	public: void testScope_start_print(const xc_test_data_t* refp_data)
	{
		if(NULL==refp_data) {
			fprintf(stdout, "\t<TEST-INTERNAL-FAILURE></<TEST-INTERNAL-FAILURE>\n");
			return;
		}
		
		if(0!=refp_data->silent) {
			return;
		}
	
		fprintf(stdout, "\n");
		fprintf(stdout, "\t<TEST-SEQUENCE>\n");
		fprintf(stdout, "\n");
		
		/*
		 *	fprintf(stdout, "\t======== ======== ======== =========\n");
		 *	fprintf(stdout, "[%s]:\n",  refp_data->cur_label_str);
		 *	fprintf(stdout, "\t-------- -------- -------- --------\n");
		 */
		
		return;

	}
	
	public: void testScope_end_print(const xc_test_data_t* refp_data)
	{
		if(0!=refp_data->silent) {
			return;
		}
		if(0!=refp_data->err_cnt)
		{
			fprintf(stdout, "\n");
			fprintf(stdout, "\t<TEST-SEQUENCE-SUMMARY>\n");
			fprintf(stdout, "[%s]\n", refp_data->cur_label_str);
			fprintf(stdout, "ERROR LINE=[%d]\n", refp_data->test_fail_line );
			fprintf(stdout, "ERROR CNT=[%d]\n", refp_data->err_cnt);
			fprintf(stdout, "OPERATIONS DONE=[%d]\n", refp_data->step_cnt);

			/*
			*fprintf(stdout, "\t-------- -------- -------- -------- -------- --------\n"); \
			*fprintf(stdout, "\n[%s]: done ERROR! error line=[%d] cnt=[%d]\n",  t__testdata_seq.cur_label_str, t__testdata_seq.test_fail_line, t__testdata_seq.err_cnt); \
			*fprintf(stdout, "\t======== ======== ======== ========= ======== ======== \n"); \
			*/
		}
		else
		{
			fprintf(stdout, "\n");
			fprintf(stdout, "\t\t<TEST-SEQUENCE-SUMMARY>\n");
			fprintf(stdout, "[%s]\n", refp_data->cur_label_str);
			fprintf(stdout, "SUCCESS\n");
			fprintf(stdout, "ERROR CNT=[%d]\n", refp_data->err_cnt);
			fprintf(stdout, "OPERATIONS DONE=[%d]\n", refp_data->step_cnt);
			/*
			*fprintf(stdout, "\t-------- -------- -------- -------- -------- --------\n"); \
			*fprintf(stdout, "\n[%s]: done OK\n",  t__testdata_seq.cur_label_str); \
			*fprintf(stdout, "\t======== ======== ======== ========= ======== ======== \n"); \
			*/
		}

		return;
	}
	
	public: void testCase_start_print(const xc_test_data_t* refp_data)
	{
		if(NULL==refp_data) {
			fprintf(stdout, "\t<TEST-INTERNAL-FAILURE></<TEST-INTERNAL-FAILURE>\n");
			return;
		}
		
		if(0!=refp_data->silent) {
			return;
		}

		fprintf(stdout, "\n");
		fprintf(stdout, "\t-------- -------- -------- --------\n"); \
		fprintf(stdout, "\t[%s]: test case\n ",  refp_data->cur_label_str);
		fprintf(stdout, "\t-------- -------- -------- --------\n"); \
		fprintf(stdout, "\n");

		/*
		*	fprintf(stdout, "\t======== ======== ======== =========\n"); \
		*	fprintf(stdout, "\t[%s]:\n",  t__testdata.cur_label_str); \
		*	fprintf(stdout, "\t-------- -------- -------- --------\n"); \
		*/
		
		return;
	}
	
	public: void testCase_end_print(const xc_test_data_t* refp_data)
	{
		if(NULL==refp_data) {
			fprintf(stdout, "!!! error !!! \n");
			return;
		}
		
		if( 0 != xcc_test0_case_isError(refp_data) ) {
			fprintf(stdout, "\n");
			fprintf(stdout, "\t-------- -------- -------- --------\n"); \
			fprintf(stdout, "\t[%s]: test case: summary (fail):\n",  refp_data->cur_label_str);
			fprintf(stdout, "\t-------- -------- -------- --------\n"); \
			fprintf(stdout, "ERROR\n" );
			fprintf(stdout, "ERROR LINE=[%d]\n",  refp_data->test_fail_line);
			fprintf(stdout, "ERROR CNT=[%d]\n",  refp_data->err_cnt);
			fprintf(stdout, "\t-------- -------- -------- --------\n"); \
			fprintf(stdout, "\n");
		}
		else {
			fprintf(stdout, "\n");
			fprintf(stdout, "\t-------- -------- -------- --------\n");
			fprintf(stdout, "\tcase [%s]: summary (OK):\n",  refp_data->cur_label_str);
			fprintf(stdout, "\t-------- -------- -------- --------\n");
			//fprintf(stdout, "\tSUCCESS\n");
			//fprintf(stdout, "\t-------- -------- -------- --------\n";
			fprintf(stdout, "\n");
		}
		
		return;
	}
	
};



extern xcc_test0_printing_I_txt printer_txt;
#endif


#endif

