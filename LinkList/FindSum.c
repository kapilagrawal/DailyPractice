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

struct node* findsum(struct node *num1, struct node *num2)
{
    int sum = 0, carry = 0;
    struct node *ptr1, *ptr2;
    struct node *ptr3 = NULL, *tmp;
    struct node *sumnode;
    
    ptr1 = num1;
    ptr2 = num2;
    
    while(ptr1 && ptr2)
    {
        sum = (ptr1->data + ptr2->data + carry) % 10;
        carry = (ptr1->data + ptr2->data + carry) / 10;
        
        sumnode = createnewnode(sum);
        
        if(ptr3 == NULL)
            ptr3 = sumnode;
        else
        {
            tmp = ptr3;
            while(tmp->next != NULL)
                tmp = tmp->next;
            tmp->next = sumnode;
        }
        
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        
    }
    
    while(ptr1)
    {
        sum = (ptr1->data + carry) % 10;
        carry = (ptr1->data + carry) / 10;
        
        sumnode = createnewnode(sum);
        
        if(ptr3 == NULL)
            ptr3 = sumnode;
        else
        {
            tmp = ptr3;
            while(tmp->next != NULL)
                tmp = tmp->next;
            tmp->next = sumnode;
        }
        
        ptr1 = ptr1->next;
        
    }
    
    while(ptr2)
    {
        sum = (ptr2->data + carry) % 10;
        carry = (ptr2->data + carry) / 10;
        
        sumnode = createnewnode(sum);
        
        if(ptr3 == NULL)
            ptr3 = sumnode;
        else
        {
            tmp = ptr3;
            while(tmp->next != NULL)
                tmp = tmp->next;
            tmp->next = sumnode;
        }
        
        ptr2 = ptr2->next;
        
    }
    
    if(carry)
    {
        sumnode = createnewnode(carry);
        
        if(ptr3 == NULL)
            ptr3 = sumnode;
        else
        {
            tmp = ptr3;
            while(tmp->next != NULL)
                tmp = tmp->next;
            tmp->next = sumnode;
        }
        
    }
    
    return ptr3;
    
}
int main()
{
    struct node *num1 = createlist();
    struct node *num2 = createlist();
    
    printlist(num1);
    printf("\n");
    printlist(num2);
    printf("\n");
    struct node *sum = findsum(num1, num2);
    printlist(sum);
    
    return 0;
}
