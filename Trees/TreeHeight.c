#include <stdio.h>
#include <stdlib.h>


struct TreeNode
{
	int data;
	struct TreeNode *left, *right;
};

struct QueueNode
{
	struct TreeNode *tree;
	struct QueueNode *next;
};

struct Queue
{
	struct QueueNode *front;
	struct QueueNode *rear;
};

struct Queue* CreateListQueue()
{
	struct Queue *Q = (struct Queue*)malloc(sizeof(struct Queue));
	if(!Q) return;

	Q->front = Q->rear = NULL;

	return Q;
}
int SizeQueue(struct Queue *Q)
{
	struct QueueNode *tmp = Q->front;
	int size =0;
	while(tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return size;
}
void Enqueue(struct Queue **Q, struct TreeNode *root)
{
	struct QueueNode *new = (struct QueueNode*)malloc(sizeof(struct QueueNode));
	if(!new)return;
	
	new->tree = root;
	new->next = NULL;

	if((*Q)->front == NULL)
		(*Q)->front = (*Q)->rear = new;
	else
	{
		(*Q)->rear->next = new;
		(*Q)->rear = new;
	}
}

struct TreeNode* Dequeue(struct Queue **Q)
{
	struct TreeNode *Tnode = NULL;
	struct QueueNode *Qnode = (*Q)->front;
	Tnode = Qnode->tree;
	(*Q)->front = (*Q)->front->next;
	free(Qnode);
	return Tnode;
}

int IsEmptyQueue(struct Queue *Q)
{
	if(Q->front == NULL)
		return 1;
	else
		return 0;
}

int Height(struct TreeNode *root)
{
	struct Queue *Q = CreateListQueue();
    int nodecount = 0;
	int height = 0;
	if(!root) return;

	Enqueue(&Q, root);
	while(1)
	{
		nodecount = SizeQueue(Q);
		if(nodecount == 0)
		break;
		height++;
		while(nodecount > 0)
		{
			root = Dequeue(&Q);
			//printf("%d ", root->data);
		
			if(root->left)
				Enqueue(&Q, root->left);
			if(root->right)
				Enqueue(&Q, root->right);

			nodecount--;
		}
//		printf("\n");
	}
	return height;
}

struct TreeNode* CreateTreeNode(int data)
{
	struct TreeNode *new = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	if (!new) return;

	new->data = data;
	new->left = new->right = NULL;

	return new;
}

int main()
{
	struct TreeNode *root = NULL;
	int h;
	root = CreateTreeNode(1);
	root->left = CreateTreeNode(2);
	root->right = CreateTreeNode(3);
	root->left->left = CreateTreeNode(4);
	root->left->right = CreateTreeNode(5);
	root->right->left = CreateTreeNode(6);
	root->right->right= CreateTreeNode(7);

	h = Height(root);
	printf("\n**%d**\n", h);
	return 0;
}
