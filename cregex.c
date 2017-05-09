/*
 * Copyright (C) 2017 francis_hao <francis_hao@126.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, GOOD TITLE or
 * NON INFRINGEMENT.  See the GNU General Public License for more
 * details.
 *
 */
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>

int cregex(const char *regex, const char *string, char *result)
{
	int len;
	int tick;
	int errno;
	int str_len;
	char *errbuff[20]={0};

#define MAX_MATCH_NUM 10
	regmatch_t pmatch[MAX_MATCH_NUM];
	regex_t preg;
	str_len = strlen(string);

	errno = regcomp(&preg, regex, REG_EXTENDED|REG_NEWLINE);/*Use POSIX Extended Regular Expression syntax*/
	if (errno != 0){
		goto ERROR;
	}
	errno = regexec(&preg, string, MAX_MATCH_NUM, pmatch, 0);/*REG_NOMATCH*/
	if(errno != 0){
		goto ERROR;
	}
	regfree(&preg);
	if(NULL == result){
		return 0;
	}

	for (tick=0; tick<MAX_MATCH_NUM; tick++){
		if (pmatch[tick].rm_so == -1){
			break;
		}
		len=pmatch[tick].rm_eo - pmatch[tick].rm_so;
		memset(result, 0, str_len);
		strncpy(result, string+pmatch[tick].rm_so, len);
		printf("%s\n",result);
	}
	return 0;

ERROR:
	regfree(&preg);
	regerror(errno, &preg, (char * __restrict__)errbuff, sizeof (errbuff));	
	printf("regular expression error: %s\n",errbuff);
	return -1;

}
