#include <stdio.h>
#include "cregex.h"
int main(void)
{
	char result[20]={0};
	if (NULL != cregex("ab(.*)", "absdkjsd", result)){
		printf("here is main %s\n", result);
	}
	return 0;
}
