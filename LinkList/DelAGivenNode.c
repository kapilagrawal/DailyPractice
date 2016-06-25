#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

void printlist(struct node *start)
{
    struct node *tmp = start;
    while(tmp != NULL)
    {
        printf("%d->", tmp->data);
        tmp = tmp->next;
    }
}

struct node* createnewnode(int newdata)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    
    newnode->data = newdata;
    newnode->next = NULL;
    
    return newnode;
}

struct node* createlist()
{
    int i, n, newdata;
    struct node *newnode;
    struct node *head = NULL;
    struct node *tmp;
    //printf("No of nodes\n");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        //printf("Enter the data\n");
        scanf("%d", &newdata);
        
        newnode = createnewnode(newdata);
        if(head == NULL)
            head = newnode;
        else
        {
            tmp = head;
            while(tmp->next != NULL)
                tmp = tmp->next;
            tmp->next = newnode;
        }
    }
    return head;
}

void deletenode(struct node *head)
{
    struct node *ptr1, *ptr2;
    
    ptr1 = head;
    
    ptr1->data = ptr1->next->data;
    
    ptr2 = ptr1->next;
    
    ptr1->next = ptr1->next->next;
    
    free(ptr2);
    
}
int main()
{
    int item, n;
  struct node *head = createlist();
 printlist(head);
  //scanf("%d", &n);
  deletenode(head->next->next);
  //printf("%d\n", item);
  printf("\n");
 printlist(head);
 return 0;
}
