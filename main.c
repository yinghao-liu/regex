#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>

char *regular(const char *regex, const char *string, char *result)
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
		regerror(errno, &preg, errbuff, sizeof (errbuff));	
		printf("%s\n",errbuff);
		return NULL;
	}
	if(0 != regexec(&preg, string, MAX_MATCH_NUM, pmatch, 0)){/*REG_NOMATCH*/
		printf("%s\n","not match");	
		return NULL;
	}
	regfree(&preg);

	for (tick=0; tick<MAX_MATCH_NUM; tick++){
		if (pmatch[tick].rm_so == -1){
			break;
		}
		len=pmatch[0].rm_eo - pmatch[0].rm_so;
		memset(result, 0, str_len);
		strncpy(result, string+pmatch[0].rm_so, len);
		printf("1%s\n",result);
	}
	tick-=1;
	len=pmatch[tick].rm_eo - pmatch[tick].rm_so;
	memset(result, 0, str_len);
	return strncpy(result, string+pmatch[tick].rm_so, len);
}

int main(void)
{
	char result[20]={0};
	regular("ab(.*)", "abbb", result);
	printf("2%s\n", result);
	return 0;
}
