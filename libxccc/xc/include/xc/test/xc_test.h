/*
 * Copyright block:
 *
 * Source file of libxccc project
 *
 * Copyright (c) 2018 Jakub Skrzyniarz, skrzj-dev@protonmail.com
 *
 * Licensed under: MIT license; See the file "LICENSE" of libxccc project for more information.
 *
 * Copyright block: end
 */

#ifndef _XC_TEST_H_
#define _XC_TEST_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>


/* *** *** */
/* test: done */
/* *** *** */


typedef struct xc_test_data_t {
	int test_fail_line;
	int err_cnt;
	int step_cnt;
	const char* cur_label_str;
	
} xc_test_data_t;


xc_test_data_t xc_test_data_initializer(const char* label_str);


int xc_test_msg(const char* fmt, ...) __attribute__( (format(printf, 1, 2) ) );

int xc_test_testCase_isError(const xc_test_data_t* arg_data);

#define xc_test_testCase_start(_STR_LABEL_) \
	do { \
		xc_test_data_t t__testdata=xc_test_data_initializer(_STR_LABEL_); /* { 0, 0, 0, _STR_LABEL_}; */ \
		xc_test_testCase_start_print(&t__testdata); \
		do { \
		;

#define xc_test_testCase_end() \
		} while(0); \
		xc_test_testCase_end_print(&t__testdata); \
		if( 0 != xc_test_testCase_isError(&t__testdata) ) { \
			goto L_TESTSEQ_FAIL; \
		} \
		else { \
		} \
 	} while(0); \
	;


#define xc_test_testcaseSilent_start() \
	do { \
		xc_test_data_t t__testdata=xc_test_data_initializer(""); /* { 0, 0, 0, _STR_LABEL_}; */ \
		do { \
		;


#define xc_test_testcaseSilent_end() \
		} while(0); \
		if(0!=t__testdata.err_cnt || 0!= t__testdata.test_fail_line ) { \
			goto L_TESTSEQ_FAIL; \
		} \
		else { \
		} \
 	} while(0); \
	;


#define xc_test__fail() if(1) { t__testdata_seq.err_cnt++; t__testdata_seq.test_fail_line=__LINE__; t__testdata.err_cnt++; t__testdata.test_fail_line=__LINE__; fprintf(stderr, "\t[%s]: FAIL at [%d]\n",  t__testdata.cur_label_str, t__testdata.test_fail_line); break; }


#define xc_test_expect(_STMT_) if( 0 == (_STMT_) ) { xc_test__fail(); } else { }


#define xc_test_testCase_step() if(1) { xc_test_testCase_step_auto_LL(&t__testdata, __LINE__); }


#define xc_test_testCase_step_annotate(_ARG_STR_) if(1) { xc_test_testCase_step_annotate_LL(&t__testdata, __LINE__, _ARG_STR_); }


#define xc_test_testScope_start(_STR_LABEL_) \
	xc_test_data_t t__testdata_seq={0}; \
	t__testdata_seq=xc_test_data_initializer(_STR_LABEL_); \
	xc_test_testScope_start_print(&t__testdata_seq); \
	;


#define xc_test_testScope_end() \
	xc_test_testScope_end_print(&t__testdata_seq); \
	return 0;  \
	L_TESTSEQ_FAIL:  \
	xc_test_testScope_end_print(&t__testdata_seq); \
	return  1;


#define xc_test_sequenceSilent_start() \
	xc_test_data_t t__testdata_seq=xc_test_data_initializer(""); /* { 0, 0, 0, _STR_LABEL_}; */ \
	;


#define xc_test_sequenceSilent_end() \
	return 0;  \
	L_TESTSEQ_FAIL:  \
	return  1;


int xc_test_testCase_step_auto_LL(xc_test_data_t* ref_data, int line);


int xc_test_testCase_step_annotate_LL(xc_test_data_t* ref_data, int line, const char* arg_str);


int xc_test_testScope_start_print(xc_test_data_t* ref_data);


int xc_test_testScope_end_print(xc_test_data_t* ref_data);


int xc_test_testCase_start_print(xc_test_data_t* ref_data);


int xc_test_testCase_end_print(xc_test_data_t* ref_data);



/* *** *** */
/* test: done */
/* *** *** */


#ifdef __cplusplus
}
#endif


#endif
