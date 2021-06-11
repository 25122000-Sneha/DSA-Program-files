#include <stdio.h>
#include <malloc.h>
#include <process.h>
struct bstnode
{
	int data;
	struct bstnode *left;
	struct bstnode *right;
};
struct bstnode *root=NULL, *x=NULL, *temp;
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

struct bstnode *smallestnode(struct bstnode *tree)
{
	if(tree==NULL || tree->left==NULL)
	return tree;
	else
	return smallestnode(tree->left);
}

struct bstnode *largestnode(struct bstnode *tree)
{
	if(tree==NULL || tree->right==NULL)
	return tree;
	else
	return largestnode(tree->right);
}

int total_nodes(struct bstnode *tree)
{
	if(tree==NULL)
	return 0;
	else 
	return total_nodes(tree->left) + total_nodes(tree->right) + 1;
}

int height(struct bstnode *tree)
{
	int left_height, right_height;
	if(tree==NULL)
	return 0;
	else
	{
		left_height = height(tree->left);
		right_height = height(tree->right);
		if(left_height > right_height)
		{
			return left_height+1;
		}
		else
		{
			return right_height+1;
		}
	}
}

int internal(struct bstnode *tree)
{
	if(tree==NULL)
	{
		return 0;
	}
	if(tree->left==NULL && tree->right==NULL)
	{
		return 0;
	}
	else
	{
		return internal(tree->left) + internal(tree->right) + 1;
	}
}

int external(struct bstnode *tree)
{
	if(tree==NULL)
	{
		return 0;
	}
	else if(tree->left==NULL && tree->right==NULL)
	{
		return 1;
	}
	else
	{
		return external(tree->left) + external(tree->right);
	}
}

void dlt_tree(struct bstnode *tree)
{
	if(tree==NULL)
	return;
	dlt_tree(tree->left);
    dlt_tree(tree->right);
    printf("\nDeleting node containing %d",tree->data);
	free(tree);
	
}

void mirror(struct bstnode *tree)
{
	if(tree!=NULL)
	{
		mirror(tree->left);
		mirror(tree->right);
		temp=tree->left;
		tree->left=tree->right;
		tree->right=temp;
	}
}

void inorder(struct bstnode *tree)
{
	if (tree == NULL)
    {
        printf("\nNo elements in a tree to display");
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
        printf("\nNo elements in a tree to display");
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
        printf("\nNo elements in a tree to display");
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

void traversal()
{
	int choice;
	printf("\nEnter 1 for inorder:\nEnter 2 for preorder\nEnter 3 for postorder\nEnter 4 to exit traversal");
	printf("\nEnter choice(1-4):");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			inorder(root);
			break;
		case 2:
			preorder(root);
			break;
		case 3:
			postorder(root);
			break;
		case 4:
			return;
		default:
			printf("\nInvalid choice!!");
			break;
	}
	
}
main()
{
	int ch, count, tree_height;
	while(1)
	{
		printf("\n\n-----------MAIN MENU---------------");
		printf("\n1. Construct binary search tree\n2. Find smallest node\n3. Find largest node\n4. Display mirror image of tree\n5. Count total no. of nodes\n6. Count total external nodes\n7. Count total internal nodes\n8. Calculate height\n9. Delete the tree\n10. Traversal\n11. -------------EXIT--------------");
		printf("\nEnter choice(1-13):");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n***********Construct***********");
				insert();
				break;
			case 2:
				printf("\n*********Find smallest node********\n");
				temp=smallestnode(root);
				printf("\nSmallest node: %d",temp->data);
				break;
			case 3:
				printf("\n********Find largest node********\n");
				temp=largestnode(root);
				printf("\nLargest node: %d",temp->data);
				break;
			case 4:
				printf("\n*********Display mirror image********\n");
				mirror(root);
				traversal();
				break;
			case 5:
				printf("\n*********Count total nodes**********\n");
				count=total_nodes(root);
				printf("\nTotal no. of nodes: %d",count);
				break;
			case 6:
				printf("\n********Count total external*********\n");
				count=external(root);
				printf("\nTotal no. of external nodes: %d",count);
				break;
			case 7:
				printf("\n********Count total internal*******\n");
				count=internal(root);
				printf("\nTotal no. of internal nodes: %d",count);
				break;
			case 8:
				printf("\n*******Calculate height*********\n");
				tree_height=height(root);
				printf("\nHeight of the tree: %d", tree_height);
				break;
			case 9:
				printf("\n*******Delete tree********\n");
				dlt_tree(root);
				root=NULL;
				traversal();
				break;
			case 10:
				printf("\n*******Traversal*******\n");
				traversal();
				break;
			case 11:
				printf("\n*********EXIT*********");
				exit(0);
			default:
				printf("\nWrong choice!!");
				break;
		}
	}
}

