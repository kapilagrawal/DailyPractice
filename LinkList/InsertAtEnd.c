/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data)
{
  // Complete this method
    Node *newnode = (Node *)malloc(sizeof(Node));
    if(newnode !=NULL)
        {
        newnode->data = data;
        newnode->next = NULL;
    }
    if (head == NULL)
        {
        head = newnode;
    }
    else
        {
        Node *tmp = head;
        while(tmp->next != NULL)
            tmp = tmp->next;
        
        tmp->next = newnode;
    }
    return head;
}
