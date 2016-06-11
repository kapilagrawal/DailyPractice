#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main()
{
	char *str = " Geeks    For Geeks Quiz in India ";
	//char *str = "a b c d e f";
	char *newstr = NULL;
	int len, totlen, no_of_spaces=0, i, j;
	len = strlen(str);
	for(i=0;i<len;i++)
	{
		if(str[i] == ' ')
		{
			no_of_spaces++;
		}
	}
	printf("No of Spaces=%d\n", no_of_spaces);
	totlen = len + (no_of_spaces*3)+1;
	newstr = (char*)malloc(totlen*sizeof(char));

	for(i=0, j=0;j<totlen;i++)
	{
		if(str[i] == ' ')
		{
			newstr[j++] = '%';
			newstr[j++] = '2';
			newstr[j++] = '0';
			
		}
		else
			newstr[j++] = str[i];
	}
	newstr[j]='\0';
	printf("Ne String=%s\n", newstr);
	free(newstr);
	return;
}
