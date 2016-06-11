#include<stdio.h>
#include<string.h>

int main()
{
	char *s1 = "aab";
	char *s2 = "aba";
	int i, j;
		int set1[256];
		int set2[256];
	if(strlen(s1) != strlen(s2)){
		printf("Not Anagram\n");
				return 1;
}

for(i=0;i<256;i++){
	set1[i] =0;
	set2[i] =0;
}
for(i=0;i<strlen(s1);i++)
	set1[s1[i]] += 1;
for(i=0;i<strlen(s2);i++)
	set2[s2[i]] += 1;
for(i=0;i<256;i++){
	if(set1[i] != set2[i]){
		printf("not anagram\n");
return;
	}
}
printf("Anagram\n");
/*
	if(strlen(s1) != strlen(s2)){
		printf("Not Anagram\n");
				return 1;
	}
	else
	{
	yy	int match[256];
		for(i=0;i<strlen(s1);i++)
			match[i] = 0;
		for(i=0;i<strlen(s1);i++)
		{
			for(j=0;j<strlen(s2);j++)
			{
				if(s1[i] == s2[j]){
					match[s1[i]] += 1;
					break;
				}
			}
//			if(s1[i] != s2[j]){
//				printf("Not Anagram\n");
//				return 1;
//			}
		}
//		if(match != strlen(s1))
//			printf("Not Anagram\n");
//		else
//			printf("Anagram\n");
			for(i=0;i<strlen(s1);i++){
				if(match[s1[i]] == 0 || match[s1[i]] > 1){
					printf("Not Anagram\n");
					return 1;
				}
				printf("Anagram\n");
			}
	}*/
	return 0;
}
