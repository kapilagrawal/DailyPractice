#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char c;
    struct node *next;
};

void printlist(struct node *start){
    struct node *tmp = start;
    printf("Printing link list\n");
    while(tmp != NULL){
		printf("%c->", tmp->c);
		tmp = tmp->next;
    }
    printf("NULL\n");
}//printlist

struct node* getnewnode(char ch){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    if(new){
		new->c = ch;
		new->next = NULL;
		return new;
    }
    else{
		printf("Can't allocate memory\n");
		return;
    }
}

struct node* createlist(char *str){
    struct node *start = NULL, *newnode, *tmp;
    int len = strlen(str);
    int i;
printf("len=%d, str=%s\n", len, str);
    for(i=0;i<len;i++){
		newnode = getnewnode(str[i]);
		if(start == NULL){
			start = newnode;
		}
		else{
			tmp = start;
			while(tmp->next != NULL){
				tmp = tmp->next;
			}
			tmp->next = newnode;
		}
    }//for
	return start;
}//createlist

int main(void){
    struct node *list1 = NULL;
    struct node *list2 = NULL;
    char str[100] = {0};
    printf("Enter the string 1\n");
    scanf("%s", &str);
    list1 = createlist(str);
	printlist(list1);
    printf("Enter the string 2\n");
    scanf("%s", &str);
    list2 = createlist(str);
	printlist(list2);
}//main
