#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *next;
};//node

struct node* getnewnode(int newdata){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    if(new){
        new->data = newdata;
	new->next = NULL;
	return new;
    }//if
    else{
        printf("can't allocate memory for new node\n");
	return;
    }//else
}//getnewnode

struct node* createlist(){
    int i = 0, num = 0, ndata = 0;
    struct node *tmp, *start = NULL, *newnode = NULL;
    printf("\n***Enter the no. of nodes you want to add in the LL***\n");
    scanf("%d", &num);
    while(i < num){
        printf("Enter nod-%d data value\n", i+1);
        scanf("%d", &ndata);
        newnode = getnewnode(ndata);
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
        i++;
    }//while
    printf("Base LL created\n");
    return start;
}//createlist

void printlist(struct node *start){
    struct node *tmp = start;
    printf("Printing LL\n");
    while(tmp != NULL){
    printf("%d->", tmp->data);
    tmp = tmp->next;
    }//while
printf("NULL");
printf("\n");
}//printlist

void sortedInsert(struct node **start){
    struct node *tmp = *start, *newnode, *prev;
    int newval = 0;
    printf("\nEnter the node data to be inserted in sorted order\n");
    scanf("%d", &newval);
    newnode = getnewnode(newval);
    if(tmp == NULL){
	*start = newnode;
    }
    else if(newval < tmp->data){
	newnode->next = *start;
	*start = newnode; 
    }
    else{
	while(tmp->next != NULL && tmp->next->data < newval){
	    tmp = tmp->next;
	  //  prev = tmp;
	}//while
	newnode->next = tmp->next;
	//if(tmp->next == NULL)
	tmp->next = newnode;
    }
    printlist(*start);
}//sortedInsert

void deletenode(struct node *head, struct node *delnode){
    struct node *prev, *tmp = head; 
    if(head == delnode){
	if(head->next == NULL){
	    printf("LL can't be empty\n");
	    return;
	}
	tmp = tmp->next;
	head->data = tmp->data;
	head->next = tmp->next;
	free(tmp);
    }
    else{
	while(tmp != delnode && tmp != NULL){
	    prev = tmp;
	    tmp = tmp->next;
	}
	if(tmp == NULL){
	    printf("Node not present\n");
	    return;
	}
	prev->next=tmp->next;
	free(tmp);
    }
    printlist(head);
}//deletenode

void createloop(struct node *head){
	struct node *tmp = head;
	while(tmp->next!=NULL){
		tmp = tmp->next;
	}
	if(head->next->next!= NULL)
	tmp->next = head->next->next;
	printf("loop inserted at =%d\n", head->next->next->data);	
}//createloop

void removeloop(struct node *loop, struct node *head){
	struct node *p1 = head;
	struct node *p2 = loop;
	while(1){
		p2 = loop;
		while(p2->next!=loop && p2->next!=p1){
			p2 = p2->next;
		}
		if(p2->next==p1){
			printf("Found and removed loop at = %d\n", p1->data);
			break;
		}
		p1 = p1->next;
	}//while(1)
	p2->next = NULL;
}//removeloop

void detectnremoveloop(struct node *head){
	struct node *slow = head;
	struct node *fast = head;
	while(fast!=NULL && fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast){
			printf("loop detected at=%d\n", slow->data);
			removeloop(slow, head);
			return;
		}
	}
	printf("No loop\n");
}//detectloop

int main(void){
    struct node *start = NULL;
    start = createlist();
    printlist(start);
	createloop(start);
	detectnremoveloop(start);
    //sortedInsert(&start);
    //deletenode(start, start->next->next);
    //deletenode(start, start);
    //deletenode(start, NULL);
    return 0;

}//main
