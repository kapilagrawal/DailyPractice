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
    printf("No of nodes\n");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        printf("Enter the data\n");
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
struct node* detectloop(struct node *start)
{
    int loopfound = 0;
    struct node *slow = start;
    struct node *fast = start;

    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            loopfound = 1;
            break;
        }
    }
    if(loopfound == 1)
    {
        printf("loop found\n");
        return slow;
    }
    else
        return NULL;
}

struct node* findloopnode(struct node *head, struct node *loop)
{
    struct node *tmp1 = head;
    struct node *tmp2;
    while(1)
    {
        tmp2 = loop;
        while((tmp2->next != tmp1) && (tmp2->next != loop))
        {
            tmp2 = tmp2->next;
        }
        if(tmp2->next == tmp1)
        {
            break;
        }
        tmp1=tmp1->next;
    }
    return tmp1;
}

int main()
{
    struct node *head = createlist();
    struct node *tmp, *loopnode, *node;
    printlist(head);
    tmp = head;
    while(tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = head->next->next;
    
    loopnode = detectloop(head);
    
    node = findloopnode(head, loopnode);
    printf("loop is at node=%d\n", node->data);
    
    return 0;
}
