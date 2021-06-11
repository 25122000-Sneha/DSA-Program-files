#include <stdio.h>
#include <malloc.h>
#include <process.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
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
		printf("\n1. Create a circular doubly linked list");
		printf("\n2. Insert an element at the beginning");
		printf("\n3. Insert an element at the end");
		printf("\n4. Display");
		printf("\n5. ---------EXIT-----------");
		printf("\nEnter choice(1-5):");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\n*****Creating a circular doubly linked list*****");
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
				printf("\n*******Display*******");
				display();
				break;
			case 5:
				printf("\n********END**********");
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
	ptr->next=start;
	start->prev=ptr;
	printf("\nContents of the list after creation:\n");
	display();
}


void insert_beg()
{
	printf("\nContents of list before operation:\n");
	display();
	x=(struct node*)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("\nOVERFLOW!! Unable to allocate memory");
	}
	else
	{
		printf("\nEnter data u want to insert:");
		scanf("%d",&x->data);
		if(start==NULL)
		{
			start=x;
			x->next=start;
			start->prev=x;
		}
		else
		{
			ptr=start;
			while(ptr->next!=start)
			{
				ptr=ptr->next;
			}
			x->next=start;
			start->prev=x;
			ptr->next=x;
			x->prev=ptr;
			start=x;
		}
		
	}
	printf("\nContents of list after operation:\n");
	display();
}

void insert_end()
{
	printf("\nContents of list before operation:\n");
	display();
	x=(struct node*)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("\nOVERFLOW!! Unable to allocate memory");
	}
	else
	{
		printf("\nEnter data u want to insert:");
		scanf("%d",&x->data);
		if(start==NULL)
		{
			start=x;
			x->next=start;
			start->prev=x;
		}
		else
		{
			ptr=start;
			while(ptr->next!=start)
			{
				ptr=ptr->next;
			}
			x->next=start;
			start->prev=x;
			ptr->next=x;
			x->prev=ptr;
		}
	}
	printf("\nContents of list after operation:\n");
	display();
}

void display()
{
	if(start==NULL)
	{
		printf("\nList is empty!!");
	}
	else
	{
		ptr=start;
		while(ptr->next!=start)
		{
			printf(" %d",ptr->data);
			ptr=ptr->next;
		}
		printf(" %d",ptr->data);
	}
}

