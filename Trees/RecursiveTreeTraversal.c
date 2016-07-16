#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
};

void RecursivePreOrderTraversal(struct TreeNode *root)
{
	if(!root)return;
	printf("%d ", root->data);
	RecursivePreOrderTraversal(root->left);
	RecursivePreOrderTraversal(root->right);
}

void RecursiveInOrderTraversal(struct TreeNode *root)
{
	if(!root)return;
	RecursiveInOrderTraversal(root->left);
	printf("%d ", root->data);
	RecursiveInOrderTraversal(root->right);
}

void RecursivePostOrderTraversal(struct TreeNode *root)
{
	if(!root)return;
	RecursivePostOrderTraversal(root->left);
	RecursivePostOrderTraversal(root->right);
	printf("%d ", root->data);
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

	printf("RecursivePreOrderTraversal\n");
	RecursivePreOrderTraversal(root);
	printf("\n");
	printf("RecursiveInOrderTraversal\n");
	RecursiveInOrderTraversal(root);
	printf("\n");
	printf("RecursivePostOrderTraversal\n");
	RecursivePostOrderTraversal(root);
	printf("\n");
	return 0;
}
