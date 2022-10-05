#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node;
node* create()
{
	node *temp;
	int x;
	printf("enter data\t-1 for no data\n");
	scanf("%d",&x);
	if(x==-1)
	{
		return NULL;
	}
		temp=(node*)malloc(sizeof(node));
		temp->data=x;
		printf("enter data for left %d\n",x);
		temp->left=create();
		printf("enter data for right %d\n",x);
        temp->right=create();
        return temp;
}
void inorder(node *root)
{
	if(root==NULL)
	{	
		return;
	}
	else
	{
		inorder(root->left);
		printf("\t%u-%u|%d|%u\t",root,root->left,root->data,root->right);
		inorder(root->right);
	}
}
void preorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		printf("\t%u-%u|%d|%u\t",root,root->left,root->data,root->right);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		postorder(root->left);
		postorder(root->right);
		printf("\t%u-%u|%d|%u\t",root,root->left,root->data,root->right);
	}
}
int main()
{
	node *root=NULL;
	root=create();
	printf("\nthe binary tree after inorder is \n");
	inorder(root);
	printf("\nthe binary tree after preorder is \n");
	preorder(root);
	printf("\nthe binary tree after postorder is \n");
	postorder(root);
	return 0;
}

