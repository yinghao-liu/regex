#include <stdio.h>
#include "cregex.h"
int main(void)
{
	char result[200]={0};
	if (0 == cregex("\"uid\":\"([0-9]*)\"", "\"uid\":\"30710830\",\"albumUrl\":\"http://chunan.19lou.com/user/album?uid=30710830&page=1\",", result)){

		printf("here is main %s\n", result);
	}
	return 0;
}
