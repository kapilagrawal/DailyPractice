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

int findnthfromlast(struct node *head, int n)
{
    int i;
    struct node *ptr1, *ptr2;
    
    ptr1 = head;
    ptr2 = head;
    
    for(i=0;i<n-1;i++)
        ptr2 = ptr2->next;
    while(ptr2->next != NULL)
    {
        ptr2 = ptr2->next;
        ptr1 = ptr1->next;
    }
    return ptr1->data;
}
int main()
{
    int item, n;
  struct node *head = createlist();
 // printlist(head);
  scanf("%d", &n);
  item = findnthfromlast(head, n);
  printf("%d\n", item);
  //printlist(head);
 return 0;
}
