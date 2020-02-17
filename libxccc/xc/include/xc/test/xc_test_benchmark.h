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

#ifndef _XC_TEST_BENCHMARK_H_
#define _XC_TEST_BENCHMARK_H_

/* --- --- --- */
#ifdef __cplusplus
extern "C" {
#endif
/* --- --- --- */

int xc_testBenchmark_msg(const char* fmt, ...) __attribute__( (format(printf, 1, 2) ) );

/* *** *** */
/* benchmark: */
/* *** *** */


typedef unsigned long int xc_test_time_t;


xc_test_time_t xc_testBenchmark_getTickCount_lowres(void);


int xc_testBenchmark_fckup_cpu_cache(void);


typedef struct xc_testBenchmark_data_entry_t
{
	xc_test_time_t time_start;
	xc_test_time_t time_end;
	xc_test_time_t time_duration;
	
} xc_testBenchmark_data_entry_t;


#define xc_testBenchmark_data_entry_MAX 32


typedef struct xc_testBenchmark_data_t
{
	int isDone;
	int test_retry_curIter;
	int test_retry_maxCnt;
	xc_testBenchmark_data_entry_t cur_retry_entry;
	int retry_entry_stack_curIdx;
	xc_testBenchmark_data_entry_t retry_entry_stack[xc_testBenchmark_data_entry_MAX];
	xc_test_time_t result_avg_duration;
	
} xc_testBenchmark_data_t;


int xc_testBenchmark_init(xc_testBenchmark_data_t* refp_data);


int xc_testBenchmark_isDone(const xc_testBenchmark_data_t* refp_data);


int xc_testBenchmark_retry_start(xc_testBenchmark_data_t* refp_data);


int xc_testBenchmark_retry_done(xc_testBenchmark_data_t* refp_data);


int xc_testBenchmark_timing_start(xc_testBenchmark_data_t* refp_data);


int xc_testBenchmark_timing_done(xc_testBenchmark_data_t* refp_data);


int xc_testBenchmark_report(const xc_testBenchmark_data_t* refp_data);


/* *** *** */
/* benchmark: done */
/* *** *** */

/* --- --- --- */
#ifdef __cplusplus
}
#endif
/* --- --- --- */

#endif
