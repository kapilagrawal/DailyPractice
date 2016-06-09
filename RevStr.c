#include<stdio.h>
#include<string.h>

int main()
{
	char *str = "abcdefghijklmnopqrstuvwxyz";
	int start = 0;
	int end = strlen(str) - 1;
	char t;
	while(start < end)
	{
		char t = str[start];
		str[start] = str[end];
		str[end] = t;
		str++;
		end--;
	}
	return;
}
