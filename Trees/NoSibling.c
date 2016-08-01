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
	if((root->left != NULL)&& (root->right == NULL))
		printf("%d\n", root->left->data);
	if((root->left == NULL)&& (root->right != NULL))
		printf("%d\n", root->right->data);
	RecursivePreOrderTraversal(root->left);
	RecursivePreOrderTraversal(root->right);
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
	root->left->left->right = CreateTreeNode(5);
	root->right->left = CreateTreeNode(6);
	root->right->left->right = CreateTreeNode(7);

	printf("RecursivePreOrderTraversal\n");
	RecursivePreOrderTraversal(root);
	printf("\n");
	return 0;
}
