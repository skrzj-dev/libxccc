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

#ifndef _XCC_TEST2_HPP_
#define _XCC_TEST2_HPP_

/* --- */
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <functional>
#include <stdlib.h>
#include <cstring>
#include <stdarg.h>
/* --- */
#include <xcc/common/xcc_cpp.hpp>
/* --- */

/* *** *** */
/* test: done */
/* *** *** */

namespace xcc
{

namespace test2
{
	class helper
	{

		public: static std::string cstrfmt_to_string(const char* fmt, ...)
		{
			char tmp[1]={0};
			size_t length=0;
			char* buf=NULL;
			va_list args;
			std::string retv="";
			
			va_start (args, fmt);
			length=vsnprintf(tmp, 0, fmt, args);
			buf=(char*)malloc(sizeof(char)*length+1);
			
			vsnprintf(buf, length+1, fmt, args);
			va_end (args);
			
			retv.assign(buf);
			free(buf);
			
			return retv;
		}
		
	};
	
	struct testExpectUnevaluatedStringifiedInfo_t
	{
		std::string stringifiedStmt;
		std::string stringifiedExpected;
		std::string stringifiedResult;
		
		static testExpectUnevaluatedStringifiedInfo_t itz_retv(std::string tested_stmt, std::string expected_result, std::string received_result)
		{
			testExpectUnevaluatedStringifiedInfo_t retv;
			
			retv.stringifiedStmt=tested_stmt;
			retv.stringifiedExpected=expected_result;
			retv.stringifiedResult=received_result;
			
			return retv;
		}
	};

	struct testExpectEvaluatedStringifiedInfo_t
	{
		std::string stringifiedExpected;
		std::string stringifiedResult;
		
		static testExpectEvaluatedStringifiedInfo_t itz_retv(std::string expected_result, std::string received_result)
		{
			testExpectEvaluatedStringifiedInfo_t retv;
			
			retv.stringifiedExpected=expected_result;
			retv.stringifiedResult=received_result;
			
			return retv;
		}
	};

	struct testScopeInfo_t
	{
		std::string filename;
		std::string fnname;
		int line;
		
		testScopeInfo_t()
		{
			this->line=0;
		}
		
		static testScopeInfo_t itz_retv(const char* filename, const char* fnname, const int line) noexcept
		{
			testScopeInfo_t retv={};
			
			retv.filename=helper::cstrfmt_to_string("%s", filename);
			retv.fnname=helper::cstrfmt_to_string("%s", fnname);
			retv.line=line;
			
			return retv;
		}
		
	};
	
	struct testAnnotationData_t
	{
		testScopeInfo_t scopeInfo;
		char static_part[64];
		char runtime_part[64];
		
		testAnnotationData_t()
		{
			this->scopeInfo={};
			std::memset(this->static_part, 0, sizeof(this->static_part) );
			std::memset(this->runtime_part, 0, sizeof(this->runtime_part) );
		}
		
		static testAnnotationData_t itz_retv(const testScopeInfo_t scopeInfo, const char* static_str, const char* runtime_str_fmt, ...) noexcept 
		{
			testAnnotationData_t retv={};
			va_list args;
			
			try
			{
				if(nullptr == static_str) {
					throw 1;
				}
				if(nullptr == runtime_str_fmt) {
					throw 1;
				}
				
				snprintf(retv.static_part, sizeof(retv.static_part),  "%s", static_str);
				
				va_start (args, runtime_str_fmt);
				vsnprintf(retv.runtime_part, sizeof(retv.runtime_part), runtime_str_fmt, args);
				va_end (args);
				
				retv.scopeInfo=scopeInfo;
				
				return retv;
			}
			catch(...)
			{
				return retv;
			}
		}
		
	};

	struct testExpectStatementResult_t
	{
		xcc::tval<bool> is_error;
		testScopeInfo_t scopeInfo;
		testExpectUnevaluatedStringifiedInfo_t stringifiedUnevaluatedStmt;
		testExpectEvaluatedStringifiedInfo_t stringifiedEvaluatedStmt;
		
		static testExpectStatementResult_t itz_retv(
			  const bool is_error
			, const testScopeInfo_t scopeInfo
			, const testExpectUnevaluatedStringifiedInfo_t stringifiedUnevaluatedStmt
			, const testExpectEvaluatedStringifiedInfo_t stringifiedEvaluatedStmt
		) noexcept
		{
			testExpectStatementResult_t retv={};
			
			retv.is_error=is_error;
			retv.scopeInfo=scopeInfo;
			retv.stringifiedUnevaluatedStmt=stringifiedUnevaluatedStmt;
			retv.stringifiedEvaluatedStmt=stringifiedEvaluatedStmt;
			
			return retv;
		}
		
	};
	
	
	struct testFailureDetails_t
	{
		testScopeInfo_t scopeInfo;
		testAnnotationData_t lastAnnotation;
		std::string content;
		
		static testFailureDetails_t itz_retv(const testScopeInfo_t scopeInfo, const std::string content)
		{
			testFailureDetails_t retv;
			
			retv.scopeInfo=scopeInfo;
			retv.content=content;
			
			return retv;
		}
	};
	
	
	struct testProcedureCase
	{
		bool isClosed;
		std::string proc_id;
		std::string case_id;
		std::string description;
		//testAnnotationData_t annotation;
		testScopeInfo_t scopeInfo;
		testExpectStatementResult_t lastStmtResult;
		testExpectStatementResult_t failInfo;
		testAnnotationData_t cur_annotation_data;
		testFailureDetails_t failCustomInfo;
		
		bool is_ok() const noexcept
		{
			return !failInfo.is_error.val();
		}
	};

	class testProcedure;

	struct testParamObj_t
	{
		testProcedure* refp_parent;
		testProcedure* refp_result;
		
		testParamObj_t(testProcedure* refp_parent, testProcedure* refp_result) noexcept
		{
			this->refp_parent=refp_parent;
			this->refp_result=refp_result;
		}
		
	};
	
	class testProcedure
	{
		class GeneralInfo
		{
			public: std::string proc_id;
			public: testScopeInfo_t cur_scope;
		};
		
		class settingData
		{
			public: xcc::tval<int> trap_enabled;
			public: xcc::tval<int> silent;
		};
		
		class resultData
		{
			public: xcc::tval<int> error_cnt;
			public: std::vector<testProcedureCase> test_cases_list;
			public: testProcedureCase last_case;
			public: testProcedureCase failed_case;
		};
		
		private: GeneralInfo header;
		private: settingData settings;
		private: resultData results;
		
		
		public: testFailureDetails_t& customFailInfo_ref()
		{
			return this->results.last_case.failCustomInfo;
		}
		
		
		public: testFailureDetails_t* customFailInfo_refp()
		{
			return &this->results.last_case.failCustomInfo;
		}
		
		private: int trapOnFail()
		{
			/* placeholder */
			return 0;
		}
		
		public: const std::vector<testProcedureCase>& test_cases_list_get() noexcept
		{
			return this->results.test_cases_list;
		}
		
		private: void case_skipOnError(const testScopeInfo_t scope_info) noexcept
		{
			xcc::test2::testExpectStatementResult_t tmp;
			std::string failed_case_id=this->results.failed_case.proc_id+":"+this->results.failed_case.case_id;
			
			if(0)
			{
				tmp.is_error=true;
				tmp.scopeInfo=scope_info;
				tmp.stringifiedEvaluatedStmt=xcc::test2::testExpectEvaluatedStringifiedInfo_t::itz_retv(
					  "N/A (skip)"
					, "N/A (skip)"
				);
				tmp.stringifiedUnevaluatedStmt=xcc::test2::testExpectUnevaluatedStringifiedInfo_t::itz_retv(
					  "N/A (skip)"
					, "N/A (skip)"
					, "N/A (skip)"
				);
			}
			if(1)
			{
				tmp=this->results.failed_case.failInfo;
				//tmp.scopeInfo=scope_info;
			}
			
			this->annotate( testAnnotationData_t::itz_retv(scope_info, "SKIP DUE TO PREVIOUS ERROR", failed_case_id.c_str() ) );
			this->fail_skip(tmp);
			
			return;
		}
		
		public: void scope_start(const testParamObj_t paramObj) noexcept
		{
			this->handle_from_scope_param(paramObj);
			this->scope_print_start();
			
			return;
		}

		public: int scope_end(testParamObj_t paramObj) noexcept
		{
			this->scope_print_end();
			this->handle_scope_param(paramObj);
			return ( 0 == this->isError() ) ? 0 : 1;
		}
		
	
		public: void case_start(const testScopeInfo_t scope_info, const std::string case_id, const std::string description)
		{
			this->results.last_case.isClosed=false;
			this->test_case(scope_info, case_id, description);
			
			this->case_print_start();
			
			if( 0 != this->isError() ) {
				throw int(1); /* terminate scope of case after previous error detected */
			}
			
			return;
		}
		
		public: void case_end()
		{
			this->results.last_case.isClosed=true;
			
			if( 0 != this->isError() &&  this->results.last_case.is_ok() ) {
				this->case_skipOnError(this->results.last_case.scopeInfo);
			}
			
			this->results.test_cases_list.push_back(this->results.last_case);
			this->case_print_end();
			if( 0 != this->isError() ) {
				
				/*throw int(1);*/ /* used to break termination and jump to the end of scope; */
				/* 
				 * disabled: all cases after 1st error are traversed but skipped;
				 * enabled: termination upon 1st error (expect failure)
				 */
			}
			
			return;
		}
		
		private: int handle_scope_param(testParamObj_t testScope_param) noexcept
		{
			this->results.last_case=testProcedureCase();
			
			if(nullptr!=testScope_param.refp_parent) {
				testScope_param.refp_parent->results_merge_fromOther(this);
			}
			else
			if(nullptr!=testScope_param.refp_result) {
				*testScope_param.refp_result=*this;
			}
			else {
				return 1;
			}
			
			return 0;
		}
		
		private: int handle_from_scope_param(testParamObj_t testScope_param) noexcept
		{
			testProcedure* refp=nullptr;
			bool noPrevious=false;
			
			if(nullptr!=testScope_param.refp_parent) {
				refp=testScope_param.refp_parent;
				noPrevious=false;
			}
			else
			if(nullptr!=testScope_param.refp_result) {
				refp = testScope_param.refp_result;
				noPrevious=true;
			}
			else {
				return 1;
			}
			
			this->results.error_cnt=refp->results.error_cnt;
			this->results.failed_case=refp->results.failed_case;
			
			if(noPrevious)
			{
				this->header.proc_id.insert(0, "X/");
			}
			else
			{
				if(false == refp->results.last_case.isClosed)
				{
					std::string tmp_id_prefix="";
					tmp_id_prefix.append(refp->header.proc_id);
					tmp_id_prefix.append(":");
					tmp_id_prefix.append(refp->results.last_case.case_id);
					tmp_id_prefix.append("/");
					this->header.proc_id.insert(0, tmp_id_prefix);
				}
			}
			
			return 0;
		}
		
		public: int isError()
		{
			return !!this->results.error_cnt.get_val();
			
		}
		
		public: int handleExpectResult(const testExpectStatementResult_t curExpectedStatementInfo)
		{
			this->results.last_case.lastStmtResult=curExpectedStatementInfo;
			
			//if( false == this->last_case.is_ok() )
			if( curExpectedStatementInfo.is_error.val() )
			{
				this->fail(curExpectedStatementInfo);
				this->trapOnFail();
				throw 11;
			}
			else {
				/* do nothing */
			}
			
			return 0;
		}
		
		private: void fail(testExpectStatementResult_t failInfo) noexcept
		{
			this->results.error_cnt++;
			this->results.last_case.failInfo=failInfo;
			this->results.failed_case=this->results.last_case;
			this->print_fail();
			return;
		}
		
		private: void fail_skip(testExpectStatementResult_t failInfo) noexcept
		{
			this->results.last_case.failInfo=failInfo;
			this->print_fail();
			return;
		}

		public: void test_case(testScopeInfo_t scopeInfo, std::string case_id, std::string str_description) noexcept
		{
			this->results.last_case=testProcedureCase();
			
			this->results.last_case.proc_id=this->header.proc_id;
			this->results.last_case.case_id.assign( case_id );
			this->results.last_case.scopeInfo=scopeInfo;
			/* this->last_case.lastStmtResult; */  /* todo ? */
			this->results.last_case.failInfo={};
			this->results.last_case.description=str_description;
			
			return;
		}
		
		public: testProcedure()
		{
			
		}
		
		public: testProcedure(testScopeInfo_t scopeInfo, const std::string test_proc_id, const int arg_silent)
		{
			this->results.test_cases_list.clear();
			this->results.error_cnt=0;
			this->results.last_case=testProcedureCase();
			this->settings.trap_enabled=0;
			
			this->header.cur_scope=scopeInfo;
			this->header.proc_id=test_proc_id;
			this->settings.silent=arg_silent;
		}
		
		
		public: void annotate(testAnnotationData_t annotation_data)
		{
			this->results.last_case.cur_annotation_data=annotation_data;
		
			fprintf(stdout, "/// ??? fn=[%s]:[%d]: info=[%s]:[%s]\n", 
				  this->results.last_case.cur_annotation_data.scopeInfo.fnname.c_str()
				, this->results.last_case.cur_annotation_data.scopeInfo.line
				, this->results.last_case.cur_annotation_data.static_part
				, this->results.last_case.cur_annotation_data.runtime_part
			);
			
			return;
		}
		
		public: int results_merge_fromOther(testProcedure* refp_other)
		{
			for ( size_t n=0; n< refp_other->test_cases_list_get().size(); n++ )
			{
				this->results.test_cases_list.push_back( refp_other->test_cases_list_get().at(n) );
			}
			
			this->results.error_cnt+=refp_other->isError();
			this->results.failed_case=refp_other->results.failed_case;
			/*this->results.last_case=refp_other->results.last_case; */ /* TODO required? */
			
			return 0;
		}
		
		
		public: int print_summary(const std::string title)
		{
			fprintf(stdout, "\n  ======== ======== [ %s: ]======== ========\n", title.c_str() ); \
			for(size_t n=0; n<this->results.test_cases_list.size(); n++)
			{
				const testProcedureCase& tmp=this->results.test_cases_list.at(n);
				
				if( tmp.is_ok() )
				{
					fprintf(stdout, "    -------- -------- -------- --------\n"); \
					fprintf(stdout, "    [%s]:[%s]: (OK) //[%s]:[%d]\n", 
						  tmp.proc_id.c_str()
						, tmp.case_id.c_str() 
						, tmp.scopeInfo.fnname.c_str()
						, tmp.scopeInfo.line
					);
					fprintf(stdout, "    //{%s}\n", 
						( 0==tmp.description.length() )
						? "no description" 
						: tmp.description.c_str() 
					);
					fprintf(stdout, "    -------- -------- -------- --------\n"); \
				}
				else
				{
					fprintf(stdout, "    -------- -------- -------- --------\n"); \
					fprintf(stdout, "    [%s]:[%s]: (FAIL): //[%s]:[%d]\n",  
						  tmp.proc_id.c_str()
						, tmp.case_id.c_str()
						, tmp.scopeInfo.fnname.c_str()
						, tmp.scopeInfo.line
					);
					fprintf(stdout, "    //{%s}\n", 
						( 0==tmp.description.length() )
						? "no description" 
						: tmp.description.c_str() 
					);
					fprintf(stdout, "    -------- -------- -------- --------\n"); \
					fprintf(stdout, "      comment=[%s][%s]\n", 
						  tmp.cur_annotation_data.static_part
						, tmp.cur_annotation_data.runtime_part
					);
					fprintf(stdout, "       file=[%s] \n", tmp.failInfo.scopeInfo.filename.c_str());
					fprintf(stdout, "       fn=[%s]:[%d] \n", tmp.failInfo.scopeInfo.fnname.c_str(), tmp.failInfo.scopeInfo.line);
					fprintf(stdout, "       stmt=[%s]\n", 
						  tmp.failInfo.stringifiedUnevaluatedStmt.stringifiedStmt.c_str() 
					); 
					fprintf(stdout, "       expected=[%s] got=[%s]\n", 
						  tmp.failInfo.stringifiedEvaluatedStmt.stringifiedExpected.c_str()
						, tmp.failInfo.stringifiedEvaluatedStmt.stringifiedResult.c_str() 
					);
					if( false == tmp.failCustomInfo.content.empty() )
					{
						fprintf(stdout, "       custom fail info:\n");
						fprintf(stdout, "       ^^^^^^^^^^^^^^^^^\n");
						fprintf(stdout, "fn=[%s]:[%d]\n", 
							  tmp.failCustomInfo.scopeInfo.fnname.c_str()
							, tmp.failCustomInfo.scopeInfo.line
						);
						fprintf(stdout, "last annotation at [%s]:[%d] is [%s]:[%s]\n", 
							  tmp.failCustomInfo.lastAnnotation.scopeInfo.fnname.c_str()
							, tmp.failCustomInfo.lastAnnotation.scopeInfo.line
							, tmp.failCustomInfo.lastAnnotation.static_part
							, tmp.failCustomInfo.lastAnnotation.runtime_part
						);
						fprintf(stdout, "[\n%s\n]\n", tmp.failCustomInfo.content.c_str() );
						fprintf(stdout, "       ^^^^^^^^^^^^^^^^^\n");
						fprintf(stdout, "       custom fail info: done\n");
					}
					fprintf(stdout, "    -------- -------- -------- --------\n"); \
				}
				
			}
			fprintf(stdout, "\n\t======== ======== [ %s: done ]======== ========\n", title.c_str() ); \
			return 0;
		}
		
		
		public: void case_print_start()
		{
			if( 0 == this->settings.silent.get_val() )
			{
				fprintf(stdout, "///\t\t-------- -------- -------- --------\n"); \
				fprintf(stdout, "///\t\t[%s]: test case: [%s]: \n", 
					  this->header.proc_id.c_str()
					, this->results.last_case.case_id.c_str() 
				);
				fprintf(stdout, "///\t\t-------- -------- -------- --------\n"); \
			}

			return;
		}
		public: void case_print_end()
		{
			if( 0 == this->results.error_cnt.get_val() )
			{
				if(0 == this->settings.silent.get_val() )
				{
					fprintf(stdout, "///\t\t-------- -------- -------- --------\n"); \
					fprintf(stdout, "///\t\t[%s]: test case: [%s]: (OK)\n",  
						  this->header.proc_id.c_str()
						, this->results.last_case.case_id.c_str() );
					fprintf(stdout, "///\t\t-------- -------- -------- --------\n"); \
				}
				else
				{
					/* don't print anything */
				}
			}
			else
			{
				fprintf(stdout, "///\t\t-------- -------- -------- --------\n"); \
				fprintf(stdout, "///\t\t[%s]: test case: [%s]: (FAIL): // [%s]:[%d]\n",  
					  this->header.proc_id.c_str()
					, this->results.last_case.case_id.c_str() 
					, this->results.last_case.scopeInfo.fnname.c_str()
					, this->results.last_case.scopeInfo.line
				);
				fprintf(stdout, "///\t\t-------- -------- -------- --------\n"); \
				fprintf(stdout, "///\t\t\t file=[%s] \n", 
					  this->results.last_case.failInfo.scopeInfo.filename.c_str()
				);
				fprintf(stdout, "///\t\t\t fn=[%s]:[%d] \n", 
					  this->results.last_case.failInfo.scopeInfo.fnname.c_str()
					, this->results.last_case.failInfo.scopeInfo.line
				);
				fprintf(stdout, "///\t\t\t stmt=[%s]\n", 
					  this->results.last_case.failInfo.stringifiedUnevaluatedStmt.stringifiedStmt.c_str() 
				);
				fprintf(stdout, "///\t\t\t expected=[%s] got=[%s]\n", 
					  this->results.last_case.failInfo.stringifiedEvaluatedStmt.stringifiedExpected.c_str()
					, this->results.last_case.failInfo.stringifiedEvaluatedStmt.stringifiedResult.c_str() 
				);
				/*fprintf(stdout, "///\t\t\t info=[%s]:[%s] \n", this->last_fail.annotation.static_part, this->last_fail.annotation.runtime_part);*/
				fprintf(stdout, "///\t\t-------- -------- -------- --------\n"); \
				fprintf(stdout, "///\t\t[%s]: test case: [%s]: (FAIL): summary done\n", 
					  this->header.proc_id.c_str()
					, this->results.last_case.case_id.c_str() 
				);
				fprintf(stdout, "///\t\t-------- -------- -------- --------\n"); \
			}
			
			return;
		}
		
		public: void scope_print_start()
		{
			if( 0 == this->settings.silent.get_val() )
			{
				fprintf(stdout, "///\t-------- -------- -------- --------\n"); \
				fprintf(stdout, "///\t[%s]: test scope::\n",  this->header.proc_id.c_str() );
				fprintf(stdout, "///\t-------- -------- -------- --------\n"); \
			}

			return;
		}
		
		public: void scope_print_end()
		{
			if( 0 == this->results.error_cnt.get_val() )
			{
				if(0 == this->settings.silent.val() )
				{
					fprintf(stdout, "///\t-------- -------- -------- --------\n"); \
					fprintf(stdout, "///\t[%s]: test scope: (OK):\n",  this->header.proc_id.c_str() );
					fprintf(stdout, "///\t-------- -------- -------- --------\n"); \
				}
			}
			else
			{
				fprintf(stdout, "///\t-------- -------- -------- --------\n"); \
				fprintf(stdout, "///\t[%s]: test scope: (FAIL):\n",  this->header.proc_id.c_str() );
				fprintf(stdout, "///\t-------- -------- -------- --------\n"); \
				fprintf(stdout, "///\t\t file=[%s] \n", 
					  this->results.last_case.failInfo.scopeInfo.filename.c_str()
				);
				fprintf(stdout, "///\t\t fn=[%s]:[%d] \n", 
					  this->results.last_case.failInfo.scopeInfo.fnname.c_str()
					, this->results.last_case.failInfo.scopeInfo.line
				);
				/*fprintf(stdout, "///\t\t info=[%s]:[%s] \n", this->last_fail.annotation.static_part, this->last_fail.annotation.runtime_part);*/
				fprintf(stdout, "///\t-------- -------- -------- --------\n"); \
				fprintf(stdout, "///\t[%s]: test scope: (FAIL): summary done\n",  this->header.proc_id.c_str() );
				fprintf(stdout, "///\t-------- -------- -------- --------\n"); \
			}
			
			return;
		}

		public: void print_fail()
		{
			fprintf(stdout, "/// <!!!!> test proc [%s]: FAIL at [%d] //%s\n", 
				  this->header.proc_id.c_str()
				, this->results.last_case.failInfo.scopeInfo.line
				, this->results.last_case.failInfo.scopeInfo.fnname.c_str() 
			);
			return;
		}
		
	};
	
	
	class testExpectOps
	{

		public: template<typename TPL_T>
		static int xcc_test2_expect_stmt_true(
			  const int stmt_evaluated_result
			, testExpectStatementResult_t& ref_stmtInfo
		)
		{
			std::string tmp=(0 == stmt_evaluated_result) ? "false" : "true";
			
			ref_stmtInfo.is_error=0==stmt_evaluated_result;
			ref_stmtInfo.stringifiedEvaluatedStmt=testExpectEvaluatedStringifiedInfo_t::itz_retv(
				  "true"
				, tmp
			);
			
			return ref_stmtInfo.is_error.val();
		}
		
		public: template<typename TPL_T>
		static int xcc_test2_expect_eq_tpl(
			  const TPL_T expected
			, const TPL_T result
			, testExpectStatementResult_t& ref_failInfo
		)
		{
			std::stringstream tmp;
			std::string tmp_expected;
			std::string tmp_result;

			tmp<<result;
			tmp_result=tmp.str();
			tmp.str("");
			
			tmp<<result;
			tmp_result=tmp.str();
			tmp.str("");
			
			tmp<<expected;
			tmp_expected=tmp.str();
			tmp.str("");
			
			ref_failInfo.is_error=(expected!=result);
			
			ref_failInfo.stringifiedEvaluatedStmt=testExpectEvaluatedStringifiedInfo_t::itz_retv(
				  tmp_result
				, tmp_expected
			);
			
			return ref_failInfo.is_error.val();
		}

		public: template<typename TPL_T>
		static int xcc_test2_expect_neq_tpl(
			  const TPL_T expected
			, const TPL_T result
			, testExpectStatementResult_t& ref_failInfo
		)
		{
			std::stringstream tmp;
			std::string tmp_expected;
			std::string tmp_result;
			
			tmp<<result;
			tmp_result=tmp.str();
			tmp.str("");
			
			tmp<<result;
			tmp_result=tmp.str();
			tmp.str("");
			
			tmp<<expected;
			tmp_expected=tmp.str();
			tmp.str("");
			
			ref_failInfo.is_error=(expected == result);
			
			ref_failInfo.stringifiedEvaluatedStmt=testExpectEvaluatedStringifiedInfo_t::itz_retv(
				  tmp_result
				, tmp_expected
			);
			
			return ref_failInfo.is_error.val();
		}
	};
	
	class testRunWrapper
	{
		/* --- */
		private: int retv;
		/* --- */
		private: std::string msg_after_execution;
		/* --- */
		private: std::string test_title;
		/* --- */
		private: testProcedure result;
		public: const testProcedure& result_get() {
			return result;
		}
		/* --- */
		private: std::function<int(testParamObj_t)> fn_testMain;
		/* --- */
		public: testRunWrapper(const std::string test_title, const std::function<int(testParamObj_t)> fn_testMain)
		{
			retv=0;
			this->test_title=test_title;
			this->fn_testMain=fn_testMain;
		}
		public: ~testRunWrapper()
		{
		}
		/* --- */
		public: int run_noThrowErr() noexcept
		{
			fprintf(stdout, "[%s] test: \n", this->test_title.c_str() );
			try
			{
				this->retv=this->fn_testMain( testParamObj_t(nullptr, &result) );
			}
			catch(...)
			{
				this->retv=-1;
				this->msg_after_execution="ERROR TERMINATION";
			}
			
			if(0==retv)
			{
				this->msg_after_execution="SUCCESS";
			}
			else {
				this->msg_after_execution="FAILURE";
			}
			
			/* on failure: print summary: */
			if(0!=retv) {
				this->summary();
			}
			/* on failure: print summary: done */
			
			fprintf(stdout, "[%s] test: %s!\n", this->test_title.c_str(), this->msg_after_execution.c_str() );
			
			return this->retv;
		}
		
		public: int run_throwErr()
		{
			if( 0 != this->run_noThrowErr() ) {
				throw std::runtime_error("");
			}
			return this->retv;
		}
		
		public: int summary()
		{
			fprintf(stdout, "[%s] (ended as %s) summary:\n", this->test_title.c_str(), this->msg_after_execution.c_str() );
			
			this->result.print_summary(this->test_title);
			
			fprintf(stdout, "[%s] (ended as %s) summary: done!\n", this->test_title.c_str(), this->msg_after_execution.c_str() );
			
			return 0;
		}
		
	};


}

}


/* 
 * 
 * macros are required to alias obtaining static scope information  (__LINE__), inject code to the scope where they are used, etc 
 * macros must be declared outside of namespace due to syntax limitations
 * macros must keep naming consistency- using namespace prefixes in naming, C style flat api 
 *
*/


typedef xcc::test2::testRunWrapper xcc_test2_wrapper;


typedef xcc::test2::testAnnotationData_t xcc_test2_annotation_t;


typedef xcc::test2::testFailureDetails_t xcc_test2_failureDetails_t;


typedef xcc::test2::testProcedure xcc_test2_procedure;


typedef xcc::test2::testParamObj_t xcc_test2_testParamObj_t;


#define xcc_test2_scopeInfo_ITZ() xcc::test2::testScopeInfo_t::itz_retv(__FILE__, __FUNCTION__, __LINE__)


#define xcc_test2_param_internal_result() xcc_test2_testParamObj_t(nullptr, &t__testScope)


#define xcc_test2_param_internal_embedded() xcc_test2_testParamObj_t(&t__testScope, nullptr)


inline xcc_test2_testParamObj_t xcc_test2_param_public_result(xcc_test2_procedure* refp_testProc)
{
	return xcc_test2_testParamObj_t(nullptr, refp_testProc);
}


//#define xcc_test2_param_internal_embedded xcc_test2_testParamObj_t(&t__testScope, nullptr)
//inline xcc_test2_testParamObj_t xcc_test2_param_internal_embedded(xcc_test2_procedure* refp_testProc)
//{
//	return xcc_test2_testParamObj_t(refp_testProc, nullptr);
//}


#define xcc_test2_param_list xcc_test2_testParamObj_t testScope_param


#define xcc_test2_param_list_forward testScope_param


#define xcc_test2_scope(_STR_LABEL_)\
	xcc::test2::testProcedure t__testScope_obj=xcc::test2::testProcedure( xcc_test2_scopeInfo_ITZ(), _STR_LABEL_, 0);\
	xcc::test2::testProcedure& t__testScope=t__testScope_obj;\
	t__testScope.scope_start(testScope_param);\
	try { \
	;


#define xcc_test2_scope_disconnected()\
	xcc::test2::testParamObj_t testScope_param=xcc::test2::testParamObj_t(nullptr, nullptr);\
	xcc::test2::testProcedure t__testScope_obj=xcc::test2::testProcedure( xcc_test2_scopeInfo_ITZ(), "", 1);\
	xcc::test2::testProcedure& t__testScope=t__testScope_obj;\
	t__testScope.scope_start(testScope_param);\
	try { \
	;


#define xcc_test2_scope_from(_REF_SCOPEOBJ_)\
	xcc::test2::testProcedure& t__testScope=_REF_SCOPEOBJ_;\
	t__testScope.scope_start(testScope_param);\
	try { \
	;


#define xcc_test2_scope_end() \
		return t__testScope.scope_end(testScope_param); \
	} \
	catch(...) {\
		return t__testScope.scope_end(testScope_param); \
	}\
	;


#define xcc_test2_case_descr(_STR_LABEL_,  _STR_DESCRIPTION_ARRAY_) \
	try { \
			t__testScope.case_start( xcc_test2_scopeInfo_ITZ(), (_STR_LABEL_), (_STR_DESCRIPTION_ARRAY_) );\
			;


#define xcc_test2_case(_STR_LABEL_) \
	try { \
			t__testScope.case_start( xcc_test2_scopeInfo_ITZ(), (_STR_LABEL_), "" );\
			;


#define xcc_test2_case_end() \
			t__testScope.case_end();\
		}\
		catch(...)\
		{\
			t__testScope.case_end();\
		}\
	;


#define xcc_test2_case_step_annotate(_ARG_STR_) do { \
		t__testScope.annotate( xcc::test2::testAnnotationData_t::itz_retv(xcc_test2_scopeInfo_ITZ(), _ARG_STR_, "") ); \
	} while(0);


#define xcc_test2_trap() do { } while(0);


#define xcc_test2_trap_set(_ARG_) do {   } while(0);


#define xcc_test2_case_refer_customFailInfo() t__testScope.customFailInfo_ref()
#define xcc_test2_case_referp_customFailInfo() t__testScope.customFailInfo_refp()


#define xcc_test2_expect(_STMT_) do {\
		xcc::test2::testExpectStatementResult_t tmp;\
		tmp.scopeInfo=xcc_test2_scopeInfo_ITZ();\
		xcc::test2::testExpectOps::xcc_test2_expect_stmt_true<int> (\
			  _STMT_\
			, tmp\
		);\
		tmp.stringifiedUnevaluatedStmt=xcc::test2::testExpectUnevaluatedStringifiedInfo_t::itz_retv(\
			  "(literal) "#_STMT_\
			, "(literal) N/A"\
			, "(literal) N/A"\
		);\
		if( 0 != t__testScope.handleExpectResult(\
				  tmp\
			)\
		) {\
			/* additional code to handle [on failure]? */\
		}\
		else {\
			/* OK */\
		}\
	} while(0)


#define xcc_test2_expect_eq_t(_TYPE_, _EXPECTED_RETV_, _STMT_RETV_) do {\
		xcc::test2::testExpectStatementResult_t tmp;\
		tmp.scopeInfo=xcc_test2_scopeInfo_ITZ();\
		xcc::test2::testExpectOps::xcc_test2_expect_eq_tpl<_TYPE_> (\
			  _EXPECTED_RETV_\
			, _STMT_RETV_\
			, tmp\
		);\
		tmp.stringifiedUnevaluatedStmt=xcc::test2::testExpectUnevaluatedStringifiedInfo_t::itz_retv(\
			  "(not literal) "#_STMT_RETV_\
			, ""#_EXPECTED_RETV_\
			, ""#_STMT_RETV_\
		);\
		if( 0 != t__testScope.handleExpectResult(\
				  tmp\
			)\
		) {\
			int* x=NULL; *x=0xdead; /* additional code to handle [on failure]? */\
		}\
		else {\
			/* OK */\
		}\
	} while(0)
	
	
#define xcc_test2_expect_neq_t(_TYPE_, _EXPECTED_RETV_, _STMT_RETV_) do {\
		xcc::test2::testExpectStatementResult_t tmp;\
		tmp.scopeInfo=xcc_test2_scopeInfo_ITZ();\
		xcc::test2::testExpectOps::xcc_test2_expect_neq_tpl<_TYPE_> (\
			  _EXPECTED_RETV_\
			, _STMT_RETV_\
			, tmp\
		);\
		tmp.stringifiedUnevaluatedStmt=xcc::test2::testExpectUnevaluatedStringifiedInfo_t::itz_retv(\
			  "(not literal) "#_STMT_RETV_\
			, ""#_EXPECTED_RETV_\
			, ""#_STMT_RETV_\
		);\
		if( 0 != t__testScope.handleExpectResult(\
				  tmp\
			)\
		) {\
			/* additional code to handle [on failure]? */\
		}\
		else {\
			/* OK */\
		}\
	} while(0)


#endif
