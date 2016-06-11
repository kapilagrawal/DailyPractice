#include<stdio.h>
#include<string.h>
int isAlpha(char ch){
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
	return 1;
    else
	return 0;
}//isAlpha
int main(void){
    char splstr[100], tmp;
    int start=0, end=0;
    printf("Please Enter the special string\n");
    scanf("%s", splstr);
    end = strlen(splstr)-1;
    while(start < end){
        if(!isAlpha(splstr[start])){
	    start++;
        }
	else if(!isAlpha(splstr[end])){
	    end--;
	}
	else{
	    tmp = splstr[start];
	    splstr[start] = splstr[end];
	    splstr[end] = tmp;
	    start++;
	    end--;
	}
    }//while
    printf("\n%s\n", splstr);

}//main
