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
struct node *x, *ptr, *temp;
int key;

void create();
void dlt_beg();
void dlt_end();
void dlt_after();
void display();

main()
{
	int choice;
	while(1)
	{
		printf("\n\n---------Main Menu-----------");
		printf("\n1. Create a circular doubly linked list");
		printf("\n2. Delete an element at the beginning");
		printf("\n3. Delete an element at the end");
		printf("\n4. Delete an element after key");
		printf("\n5. Display");
		printf("\n6. ---------EXIT-----------");
		printf("\nEnter choice(1-6):");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\n*****Creating a circular doubly linked list*****");
				create();
				break;
			case 2:
				printf("\n******Deletion at the beginning******");
				dlt_beg();
				break;
			
			case 3:
				printf("\n******Deletion at the end******");
				dlt_end();
				break;
			case 4:
				printf("\n*******Deletion after key********");
				dlt_after();
				break;
			case 5:
				printf("\n*******Display*******");
				display();
				break;
			case 6:
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

void dlt_beg()
{
	printf("\nContents of the list before operation:\n");
	display();
	if(start==NULL)
	{
		printf("\nUnderflow!! List is empty");
	}
	else if(start->next==start)
	{
		temp=start;
		start=NULL;
		free(temp);
	}
	else
	{
		ptr=start;
		while(ptr->next!=start)
		{
			ptr=ptr->next;
		
	    }
	    temp=start;
	    start=start->next;
	    ptr->next=start;
	    start->prev=ptr;
	    free(temp);
		
		
	}
	printf("\nContents of the list after operation:\n");
	display();
}

void dlt_end()
{
	printf("\nContents of the list before operation:\n");
	display();
	if(start==NULL)
	{
		printf("\nUnderflow!! List is empty");
	}
	else if(start->next==start)
	{
		temp=start;
		start=NULL;
		free(temp);
	}
	else
	{
		ptr=start;
		while(ptr->next!=start)
		{
			ptr=ptr->next;
		
	    }
	    temp=ptr;
	    ptr->prev->next=start;
	    start->prev=ptr->prev;
	    free(temp);
	}
	
	printf("\nContents of the list after operation:\n");
	display();
}

void dlt_after()
{
	printf("\nContents of the list before operation:\n");
	display();
	if(start==NULL)
	{
		printf("\nUnderflow!!List is empty");
	}
	else 
	{
		printf("\nEnter key:");
		scanf("%d",&key);
		if(start->data==key && start->next==start)                              // if only one node is present in the list and it is the key //
		{
			temp=start;
			start=NULL;
			free(temp);
			return;
		}
		ptr=start;
		while(ptr->data!=key)
		{
			ptr=ptr->next;
		}
		if(ptr->next==start)                                         // if last node is the key //
		{
			temp=start;
			start=start->next;
			ptr->next=start;
			start->prev=ptr;
			free(temp);
			
		}
		else
		{
			temp=ptr->next;
			ptr->next=temp->next;
			temp->next->prev=ptr;
			free(temp);
		}
	}
	printf("\nContents of the list after operation:\n");
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
