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

removeduplicatesSorted(struct node *head)
{
    struct node *ptr1, *dup;
    
    ptr1 = head;
    
    while(ptr1->next != NULL)
    {
        if(ptr1->data == ptr1->next->data)
        {
            dup = ptr1->next;
            ptr1->next = ptr1->next->next;
            free(dup);
        }
        else
            ptr1 = ptr1->next;
    }
}
int main()
{
  struct node *head = createlist();
  printlist(head);
  removeduplicatesSorted(head);
  printf("After\n");
  printlist(head);
 return 0;
}
