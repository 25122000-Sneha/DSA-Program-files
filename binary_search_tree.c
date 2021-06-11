#include <stdio.h>
#include <malloc.h>
#include <process.h>
struct bstnode
{
	int data;
	struct bstnode *left;
	struct bstnode *right;
};
struct bstnode *root=NULL, *x=NULL;
int value;

void construct()
{
	printf("\nEnter data to be inserted into tree:");
	scanf("%d",&value);
	x=(struct bstnode*)malloc(sizeof(struct bstnode));
	x->data=value;
	x->left=x->right=NULL;
}

void search(struct bstnode *tree)
{
	if((x->data < tree->data) && (tree->left!=NULL))
	{
		search(tree->left);
	}
	else if((x->data < tree->data) && (tree->left==NULL))
	{
		tree->left=x;
	}
	else if((x->data > tree->data) && (tree->right!=NULL))
	{
		search(tree->right);
	}
	else if((x->data > tree->data) && (tree->right==NULL))
	{
		tree->right=x;
	}
}

void insert()
{
	construct();
	if(root==NULL)
	{
		root=x;
	}
	else
	{
		search(root);
	}
}

void inorder(struct bstnode *tree)
{
	if (tree == NULL)
    {
        printf("No elements in a tree to display");
        return;
    }
    if(tree->left!=NULL)
	{
		inorder(tree->left);
	}
	printf("%d ",tree->data);
	if(tree->right!=NULL)
	{
		inorder(tree->right);
	}
}
	

void postorder(struct bstnode *tree)
{
	if (tree == NULL)
    {
        printf("No elements in a tree to display");
        return;
    }
    if(tree->left!=NULL)
	{
		postorder(tree->left);
	}
	if(tree->right!=NULL)
	{
		postorder(tree->right);
	}
	printf("%d ",tree->data);
    
}

void preorder(struct bstnode *tree)
{
	if (tree == NULL)
    {
        printf("No elements in a tree to display");
        return;
    }
    printf("%d ",tree->data);
	if(tree->left!=NULL)
	{
		preorder(tree->left);
	}
	if(tree->right!=NULL)
	{
		preorder(tree->right);
	}
}



main()
{
	int ch;
	while(1)
	{
		printf("\n\n-----------MAIN MENU---------------");
		printf("\n1. Construct binary search tree\n2. Inorder traversal\n3. Preorder traversal\n4. Postorder traversal\n5. -------------EXIT--------------");
		printf("\nEnter choice(1-5):");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n***********Construct***********");
				insert();
				break;
			case 2:
				printf("\n*********Inorder********\n");
				inorder(root);
				break;
			case 3:
				printf("\n********Preorder********\n");
				preorder(root);
				break;
			case 4:
				printf("\n*********Postorder********\n");
				postorder(root);
				break;
			case 5:
				printf("\n*********EXIT*********");
				exit(0);
			default:
				printf("\nWrong choice!!");
				break;
		}
	}
}

