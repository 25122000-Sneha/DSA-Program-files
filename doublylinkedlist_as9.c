#include <stdio.h>
#include <malloc.h>
#include <process.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *start=NULL;
struct node *x, *ptr;

void create();
void insert_beg();
void insert_end();
void display();

main()
{
	int choice;
	while(1)
	{
		printf("\n\n---------Main Menu-----------");
		printf("\n1. Create a doubly linked list");
		printf("\n2. Insert an element at the front");
		printf("\n3. Insert an element at the end");
		printf("\n4. --------EXIT-----------");
		printf("\nEnter choice(1-4):");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\n*****Creating a doubly linked list*****");
				create();
				break;
			case 2:
				printf("\n******Insertion at the beginning******");
				insert_beg();
				break;
			
			case 3:
				printf("\n******Insertion at the end******");
				insert_end();
				break;
			
			case 4:
				printf("\n**********END*********");
				exit(0);
			default:
				printf("\nWrong choice!!");
				break;
        }
	}
}

void create()
{
	int n,i;
	printf("\nEnter no. of nodes u want to create:");
	scanf("%d",&n);
	start=(struct node*)malloc(sizeof(struct node));
	if(start==NULL)
	{
		printf("\nUnable to allocate memory");
		exit(0);
	}
	printf("\nEnter data u want to insert:");
	scanf("%d",&start->data);
	start->next=NULL;
	start->prev=NULL;
	ptr=start;
	for(i=1;i<n;i++)
	{
		x=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter data u want to insert:");
		scanf("%d",&x->data);
		x->next=NULL;
		x->prev=ptr;
		ptr->next=x;
		ptr=ptr->next;
		
	}
	display();
}

void insert_beg()
{
	display();
	x=(struct node*)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("\nOVERFLOW!! Unable to allocate memory!!");
	}
	else
	{
		printf("\nEnter data u want to insert: ");
		scanf("%d",&x->data);
		if(start==NULL)
		{
			x->next=NULL;
			x->prev=NULL;
			start=x;
		}
		else
		{
			x->next=start;
			x->prev=NULL;
			start->prev=x;
			start=x;
		}
	}
	display();
}

void insert_end()
{
	display();
	x=(struct node*)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("\nOVERFLOW!! Unable to allocate memory!!");
	}
	else
	{
		printf("\nEnter data u want to insert: ");
		scanf("%d",&x->data);
		if(start==NULL)
		{
			x->next=NULL;
			x->prev;
			start=x;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			x->next=NULL;
			x->prev=ptr;
			ptr->next=x;
		}
	}
	display();
}

void display()
{
	if(start==NULL)
	{
		printf("\nList is empty");
		
	}
	else
	{
		printf("\nContents of the doubly linked list:\n");
		ptr=start;
		while(ptr!=NULL)
		{
			printf(" %d",ptr->data);
			ptr=ptr->next;
		}
		
	}
}


