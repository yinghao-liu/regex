#include <stdio.h>
#include "regular.h"
int main(void)
{
	char result[20]={0};
	if (NULL != regular("ab(.*)", "dsdsdsbb", result)){
		printf("%s\n", result);
	}
	return 0;
}
