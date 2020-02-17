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

#include <stdlib.h>
#include <stdio.h>
/* --- */
#ifdef _WIN32

#include <windows.h>
#include <tchar.h>

#else 

#include <unistd.h>

#endif
/* --- */
#include "xc/common/xc_err.h"
#include "xc/common/xc_mem.h"
/* --- */
#include "xc/test/xc_test_benchmark.h"
/* --- */

int xc_testBenchmark_msg(const char* fmt, ...) __attribute__( (format(printf, 1, 2) ) );

int xc_testBenchmark_msg(const char* fmt, ...)
{
	va_list args;
	char buffer[256]={0};
	
	if(NULL==fmt) {
		return 1;
	}
	
	va_start (args, fmt);
	vsnprintf(buffer, sizeof(buffer), fmt, args);
	va_end (args);
	
	fprintf(stdout, "%s\n", buffer);
	
	return 0;
}


#ifdef _WIN32

xc_test_time_t xc_testBenchmark_getTickCount_lowres(void)
{
	DWORD result=0;
	xc_test_time_t retv=0;
	
	result=GetTickCount();
	retv=result;
	
	return retv;
}

#else 

xc_test_time_t xc_testBenchmark_getTickCount_lowres(void)
{
	error
	xc_test_time_t retv=0;
	
	result=GetTickCount();
	retv=result;
	
	return retv;
}

#endif


int xc_testBenchmark_fckup_cpu_cache(void)
{
	const int static_size=64*1024;
	int* big_array_of_crap1=NULL;
	int* big_array_of_crap2=NULL;
	int* big_array_of_crap3=NULL;
	int n=0;
	ERR_DECL();
	
	return 0;
	
	if(NULL == (big_array_of_crap1=(int*)malloc(static_size*sizeof(int) ) ) ) {
		ERR_TERM(L_ERR);
	}
	if(NULL == (big_array_of_crap2=(int*)malloc(static_size*sizeof(int) ) ) ) {
		ERR_TERM(L_ERR);
	}
	if(NULL == (big_array_of_crap3=(int*)malloc(static_size*sizeof(int) ) ) ) {
		ERR_TERM(L_ERR);
	}
	
	for(n=static_size-1; n>=0; n--)
	{
		int tmp=0;
		
		tmp=big_array_of_crap1[n];
		big_array_of_crap1[n]=big_array_of_crap1[n];
		big_array_of_crap1[n]+=100;
		
		if(big_array_of_crap1[n]%2) {
			big_array_of_crap1[n]=n+99;
		}
		else {
			big_array_of_crap1[n]=n+100;
		}
	}

	for(n=static_size-1; n>=0; n--)
	{
		int tmp=0;
		
		tmp=big_array_of_crap2[n];
		big_array_of_crap2[n]=big_array_of_crap2[n];
		big_array_of_crap2[n]=big_array_of_crap2[n]/big_array_of_crap1[n];
		
		if(big_array_of_crap2[n]%2) {
			big_array_of_crap2[n]=n+99;
		}
		else {
			big_array_of_crap2[n]=n+100;
		}
	}
	
	for(n=static_size-1; n>=0; n--)
	{
		int tmp=0;
		
		tmp=big_array_of_crap3[n];
		big_array_of_crap3[n]=big_array_of_crap3[n];
		big_array_of_crap3[n]=big_array_of_crap3[n]/big_array_of_crap2[n];
		big_array_of_crap3[n]=big_array_of_crap3[n]/big_array_of_crap1[n];
		
		if(big_array_of_crap3[n]%2) {
			big_array_of_crap3[n]=n+99;
		}
		else {
			big_array_of_crap3[n]=n+100;
		}
	}
	
	free(big_array_of_crap1);
	free(big_array_of_crap2);
	free(big_array_of_crap3);
	
	return 0;
	
	L_ERR:
	
	free(big_array_of_crap1);
	free(big_array_of_crap2);
	free(big_array_of_crap3);
	
	return 1;

}


/* *** *** */
/* benchmark: */
/* ** ** */


int xc_testBenchmark_init(xc_testBenchmark_data_t* refp_data)
{
	xc_err_decl();
	
	if(NULL == refp_data) {
		xc_err_term(L_ERR);
	}
	
	xc_mem_bzero_obj(xc_testBenchmark_data_t, refp_data);
	
	return 0;
	
	L_ERR:
	xc_err_sig();
	return xc_err_retv();
}


int xc_testBenchmark_isDone(const xc_testBenchmark_data_t* refp_data)
{
	xc_err_decl();
	
	if(NULL == refp_data) {
		xc_err_term(L_ERR);
	}
	
	return refp_data->isDone;
	
	L_ERR:
	xc_err_sig();
	return 0;
}


int xc_testBenchmark_retry_start(xc_testBenchmark_data_t* refp_data)
{
	xc_err_decl();
	
	if(NULL == refp_data) {
		xc_err_term(L_ERR);
	}
	
	xc_mem_bzero_obj(xc_testBenchmark_data_entry_t, &refp_data->cur_retry_entry);
	
	refp_data->test_retry_maxCnt=4;
	if(refp_data->test_retry_maxCnt>=xc_testBenchmark_data_entry_MAX) {
		xc_err_term(L_ERR);
	}
	
	xc_testBenchmark_msg("  --------------------");
	
	xc_testBenchmark_msg("  benchmark: retry [%02d]:", 
		  refp_data->test_retry_curIter
	);
	
	return 0;
	
	L_ERR:
	xc_err_sig();
	return xc_err_retv();
}


int xc_testBenchmark_retry_done(xc_testBenchmark_data_t* refp_data)
{
	int n=0;
	xc_testBenchmark_data_entry_t* item_ref=NULL;
	xc_err_decl();
	
	if(NULL == refp_data) {
		xc_err_term(L_ERR);
	}
	
	if(refp_data->retry_entry_stack_curIdx >= xc_testBenchmark_data_entry_MAX ) {
		xc_err_term(L_ERR);
	}
	
	xc_testBenchmark_msg("  benchmark: retry [%02d]: done", 
		  refp_data->test_retry_curIter
	);
	xc_testBenchmark_msg("    duration [%06lu] ms / [%03lu.%03lu] s\n", 
		  refp_data->cur_retry_entry.time_duration
		, (long unsigned int)(refp_data->cur_retry_entry.time_duration / 1000)
		, (long unsigned int)(refp_data->cur_retry_entry.time_duration % 1000) 
	);
	
	/* push item: */
	item_ref=&refp_data->retry_entry_stack[refp_data->retry_entry_stack_curIdx];
	
	xc_mem_cp_obj(xc_testBenchmark_data_entry_t, item_ref, &refp_data->cur_retry_entry);
	
	refp_data->retry_entry_stack_curIdx++;
	/* push item: done */
	
	/* increase retry cnt / check if done: */
	refp_data->test_retry_curIter++;
	
	if(refp_data->test_retry_curIter>=refp_data->test_retry_maxCnt) {
		refp_data->isDone=1;
	}
	else {
		refp_data->isDone=0;
	}
	/* increase retry cnt / check if done: done */
	
	/* calculate average: */
	if(1)
	{
		xc_test_time_t duration_avg=0;
		
		for(n=0; n < refp_data->test_retry_maxCnt; n++)
		{
			const xc_testBenchmark_data_entry_t* refp_cur_item=NULL;
			
			refp_cur_item=&refp_data->retry_entry_stack[ n ];
			duration_avg+=refp_cur_item->time_duration;
		}
		
		duration_avg=duration_avg/refp_data->test_retry_curIter;
		
		refp_data->result_avg_duration=duration_avg;
	}
	/* calculate average: done */
	
	return 0;
	
	L_ERR:
	xc_err_sig();
	return xc_err_retv();
}


int xc_testBenchmark_timing_start(xc_testBenchmark_data_t* refp_data)
{
	xc_err_decl();
	
	if(NULL == refp_data) {
		xc_err_term(L_ERR);
	}
	
	refp_data->cur_retry_entry.time_start=xc_testBenchmark_getTickCount_lowres();
	
	return 0;
	
	L_ERR:
	xc_err_sig();
	return xc_err_retv();
}


int xc_testBenchmark_timing_done(xc_testBenchmark_data_t* refp_data)
{
	xc_err_decl();
	
	if(NULL == refp_data) {
		xc_err_term(L_ERR);
	}
	
	refp_data->cur_retry_entry.time_end=xc_testBenchmark_getTickCount_lowres();
	refp_data->cur_retry_entry.time_duration=refp_data->cur_retry_entry.time_end - refp_data->cur_retry_entry.time_start;
	
	return 0;
	
	L_ERR:
	xc_err_sig();
	return xc_err_retv();
}


int xc_testBenchmark_report(const xc_testBenchmark_data_t* refp_data)
{
	int n=0;
	xc_test_time_t duration_avg=0;
	xc_err_decl();
	
	if(NULL == refp_data) {
		xc_err_term(L_ERR);
	}
	
	/* ** ** */
	
	for(n=0; n  < refp_data->test_retry_maxCnt; n++)
	{
		const xc_testBenchmark_data_entry_t* refp_cur_item=NULL;
		
		refp_cur_item=&refp_data->retry_entry_stack[n];
		duration_avg+=refp_cur_item->time_duration;
	}
	
	duration_avg=duration_avg/refp_data->test_retry_maxCnt;
	
	/* ** ** */
	
	xc_testBenchmark_msg("------------------------------------------");
	for(n=0; n  < refp_data->test_retry_maxCnt; n++)
	{
		const xc_testBenchmark_data_entry_t* refp_cur_item=NULL;
		
		refp_cur_item=&refp_data->retry_entry_stack[n];
		
		xc_testBenchmark_msg("  benchmark retry [%02d]:", n);
		xc_testBenchmark_msg("    duration [%06lu] ms / [%03lu.%03lu] s", 
		  refp_cur_item->time_duration
		, (long unsigned int)(refp_cur_item->time_duration / 1000)
		, (long unsigned int)(refp_cur_item->time_duration % 1000) 
	);

		xc_testBenchmark_msg("  benchmark retry [%02d]: done", n);
		xc_testBenchmark_msg("  --------------------");
	}
	xc_testBenchmark_msg("------------------------------------------");
	
		xc_testBenchmark_msg("    avg duration [%06lu] ms / [%03lu.%03lu] s", 
			  duration_avg
			, (long unsigned int)( duration_avg / 1000 )
			, (long unsigned int)( duration_avg % 1000 )
		);
		
	xc_testBenchmark_msg("------------------------------------------");
	
	return 0;
	
	L_ERR:
	xc_err_sig();
	return xc_err_retv();
}


/* *** *** */
/* benchmark: */
/* ** ** */
