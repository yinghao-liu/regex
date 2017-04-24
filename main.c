#include <stdio.h>
#include "cregex.h"
int main(void)
{
	char result[20]={0};
	if (NULL != cregex("ab(.*)", "dsdsdsbb", result)){
		printf("%s\n", result);
	}
	return 0;
}
