#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct StackNode
{
	struct TreeNode *tree;
	struct StackNode *next;
};

struct StackNode* CreateStack()
{
	return NULL;
}

void push(struct StackNode **SRef, struct TreeNode *root)
{
	struct StackNode *new = (struct StackNode*)malloc(sizeof(struct StackNode));
	if(!new) return;

	new->tree = root;
	new->next = *SRef;
	*SRef = new;
}

struct TreeNode* pop(struct StackNode **SRef)
{
	struct TreeNode *tmp = NULL;
	struct StackNode *del = *SRef;

	tmp = del->tree;
	*SRef = del->next;
	free(del);
	return tmp;
}

int IsEmptyStack(struct StackNode *S)
{
	if(S == NULL)
		return 1;
	else
		return 0;
}

void DeleteStack(struct StackNode **SRef)
{
	struct StackNode *tmp = *SRef;
	struct StackNode *del = NULL;

	while(tmp != NULL)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	*SRef = NULL;
}
struct TreeNode* top(struct StackNode *S)
{
	return S->tree;
}
void IterativePostOrderTraversal(struct TreeNode *root)
{
	struct StackNode* S = CreateStack();
	struct TreeNode *curr = root;
	struct TreeNode *prev = root;
	if(root != NULL)
		push(&S, root);
	while(!IsEmptyStack(S))
	{
		curr = top(S);
		if((prev == curr)||(curr == prev->left)||(curr == prev->right))
		{
			if(curr->left != NULL)
				push(&S, curr->left);
			else if(curr->right != NULL)
				push(&S, curr->right);
			if((curr->left == NULL) && (curr->right == NULL))
			{
				printf("%d ", curr->data);
				pop(&S);
			}
		}
		else if(prev == curr->left)
		{
			if(curr->right != NULL)
				push(&S, curr->right);
			else
			{
				printf("%d ", curr->data);
				pop(&S);
			}
		}
		else if(prev == curr->right)
		{
			printf("%d ", curr->data);
			pop(&S);
		}
		prev = curr;
	}
	DeleteStack(&S);
}

struct TreeNode* CreateTreeNode(int data)
{
	struct TreeNode *new = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	if(!new) return NULL;
	
	new->data = data;
	new->left = new->right = NULL;
	
	return new;
}


int main()
{
	struct TreeNode *root = NULL;
	
	root = CreateTreeNode(1);
	root->left = CreateTreeNode(2);
	root->right = CreateTreeNode(3);
	root->left->left = CreateTreeNode(4);
	root->left->right = CreateTreeNode(5);
	root->right->left = CreateTreeNode(6);
	root->right->right = CreateTreeNode(7);

	IterativePostOrderTraversal(root);
	printf("\n");
	return 0;
}
