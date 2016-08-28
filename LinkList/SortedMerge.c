/* C/C++ program to merge two sorted linked lists */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/* Link list node */
struct node
{
	int data;
	struct node* next;
};
void printList(struct node *node);

struct node* SortedMerge(struct node** a, struct node** b)
{

	struct node *head = NULL;

	/* tail points to the last result node */
	struct node *last = NULL;

	while (1)
	{
	    printf("in while loop\n");
	    if (*a == NULL) 
        {
            if(last == NULL)
            {
                last = *b;
                head = last;
                printf("if -if-1\n");
            }
            else
            {
                last->next = *b;
                printf("if-else-1\n");
            }
            printf("if-1\n");
            break;
        }
        else if (*b==NULL) 
        {
            if(last == NULL)
            {
                last = *a;
                head = last;
                printf("else-if-1\n");
            }
            else
            {
                last->next = *a;
                printf("else-if-1\n");
            }
            printf("else-1\n");
            break;
        
        }
        if((*a)->data <= (*b)->data) 
        {
            if(last == NULL)
            {
                last = *a;
                head = last;
                *a = (*a)->next;
                printf("if-if-2\n");
            }
            else
            {
                last->next = *a;
                *a = (*a)->next;
                last = last->next;
                printf("if-else-2\n");
            }
            printf("if-2\n");
        }
        else
        {
            if(last == NULL)
            {
                last = *b;
                head = last;
                *b = (*b)->next;
                printf("else-if-2\n");
            }
            else
            {
                last->next = *b;
                *b = (*b)->next;
                last = last->next;
                printf("else-if-2\n");
            }
            printf("else-2\n");
        }
        printf("head\n");
        printList(head);
        printf("A\n");
        printList(*a);
        printf("B\n");
        printList(*b);
	}
	return head;
}

/* Function to insert a node at the beginging of the
linked list */
void push(struct node** head_ref, int new_data)
{
	/* allocate node */
	struct node* new_node =
		(struct node*) malloc(sizeof(struct node));

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
	while (node!=NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

/* Drier program to test above functions*/
int main()
{
	/* Start with the empty list */
	struct node* res = NULL;
	struct node* a = NULL;
	struct node* b = NULL;

	/* Let us create two sorted linked lists to test
	the functions
	Created lists, a: 5->10->15, b: 2->3->20 */
	push(&a, 15);
	push(&a, 10);
	push(&a, 5);

	push(&b, 20);
	push(&b, 3);
	push(&b, 2);

	/* Remove duplicates from linked list */
	res = SortedMerge(&a, &b);

	printf("Merged Linked List is: \n");
	printList(res);

	return 0;
}
