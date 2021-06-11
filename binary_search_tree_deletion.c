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
struct bstnode *temp;
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


struct bstnode *min_node(struct bstnode *tree)                                           // finding the smallest node in right subtree i.e. inorder successor
{
	if(tree==NULL)
	return NULL;
	else if(tree->left != NULL)
	{
		return min_node(tree->left);
	}
	return tree;
}

struct bstnode *dlt_node(struct bstnode *tree, int x)
{
	if(tree==NULL)
	{
		printf("\nValue not found in tree!!");
		return NULL;
	}
	                                                                              // searching the node to be deleted
	if(x < tree->data)
	{
		tree->left = dlt_node(tree->left, x);                                       // place returned value in the position of left child
		return tree;                                      
	}
	else if(x > tree->data)                                                        // place returned value in the position of right child
	{
		tree->right = dlt_node(tree->right, x);     
		return tree;                               
	}
	else                                                                            // x==tree->data, node to be deleted is found
	{
		if (tree->left == NULL && tree->right == NULL)                              // No children
		{
			free(tree);
			return NULL;
		}
		else if (tree->left == NULL || tree->right == NULL)                        // Only one child
		{
			if(tree->right != NULL)
			{
				temp = tree->right;
				free(tree);
				return temp;
			}
			if(tree->left != NULL)
			{
				temp = tree->left;
				free(tree);
				return temp;
			}
		}
		
		else if(tree->left != NULL && tree->right != NULL)                            // Two children
		{
			temp = min_node(tree->right);
			tree->data = temp->data;                                           //replacing the data of inorder successor node in place of node to be deleted
			tree->right = dlt_node(tree->right, temp->data);                  // deleting the inorder successor node
			return tree;                                              
		}
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
	int ch, x;
	while(1)
	{
		printf("\n\n-----------MAIN MENU---------------");
		printf("\n1. Construct binary search tree\n2. Delete node from tree\n3. Inorder traversal\n4. Preorder traversal\n5. Postorder traversal\n6. -------------EXIT--------------");
		printf("\nEnter choice(1-6):");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n***********Construct***********");
				insert();
				break;
			case 2:
				printf("\n**********Delete*************");
				printf("\nEnter value of node which is to be deleted:");
				scanf("%d",&x);
				root = dlt_node(root, x);
				break;
			case 3:
				printf("\n*********Inorder********\n");
				inorder(root);
				break;
			case 4:
				printf("\n********Preorder********\n");
				preorder(root);
				break;
			case 5:
				printf("\n*********Postorder********\n");
				postorder(root);
				break;
			case 6:
				printf("\n*********EXIT*********");
				exit(0);
			default:
				printf("\nWrong choice!!");
				break;
		}
	}
}

