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
struct node *x, *ptr, *temp;
int num;

void create();
void insert_after();
void insert_before();
void dlt_beg();
void dlt_end();
void dlt_after();
void dlt_before();
void display();

main()
{
	int choice;
	while(1)
	{
		printf("\n\n---------Main Menu-----------");
		printf("\n1. Create a doubly linked list");
		printf("\n2. Insert an element after a given node");
		printf("\n3. Insert an element before a given node");
		printf("\n4. Delete the first node");
		printf("\n5. Delete the last node");
		printf("\n6. Delete node after a given node");
		printf("\n7. Delete the node before a given node");
		printf("\n8. Display");
		printf("\n9. ---------EXIT-----------");
		printf("\nEnter choice(1-9):");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\n*****Creating a doubly linked list*****");
				create();
				break;
			case 2:
				printf("\n******Insertion after given node******");
				insert_after();
				break;
			
			case 3:
				printf("\n******Insertion before a given node******");
				insert_before();
				break;
			case 4:
				printf("\n*******Delete the first node*********");
				dlt_beg();
				break;
			case 5:
				printf("\n*******Delete the last node***********");
				dlt_end();
				break;
			case 6:
				printf("\n*********Delete node after given node********");
				dlt_after();
				break;
			case 7:
				printf("\n********Delete node before given node**********");
				dlt_before();
				break;
			case 8:
				printf("\n*********Display***********");
				display();
				break;
			case 9:
				printf("\n*********END**********");
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


void insert_after()
{
	display();
	x=(struct node*)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("\nOVERFLOW!!Unable to allocate memory");
	}
	else
	{
		printf("\nEnter node after which element is to be inserted:");
		scanf("%d",&num);
		printf("\nEnter data u want to insert:");
		scanf("%d",&x->data);
		ptr=start;
		while(ptr->data!=num)
		{
			ptr=ptr->next;
		}
		if(ptr->next==NULL)                                                       // if the last node is the key and new node is to be inserted after it //
		{
			x->next=NULL;
			ptr->next=x;
			x->prev=ptr;
		}
		else
		{
		
		    x->next=ptr->next;
		    x->prev=ptr;
		    ptr->next->prev=x;
		    ptr->next=x;
	    }
	}
	display();
}

void insert_before()
{
	display();
	x=(struct node*)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("\nOVERFLOW!!Unable to allocate memory");
	}
	else
	{
		printf("\nEnter node before which element is to be inserted:");
		scanf("%d",&num);
		printf("\nEnter data u want to insert:");
		scanf("%d",&x->data);
		ptr=start;
		while(ptr->data!=num)
		{
			ptr=ptr->next;
		}
		if(ptr->prev==NULL)
		{
			x->next=ptr;                                                  // if head node is the key and new node is to be inserted before it //
			x->prev=NULL;
			start=x;
		}
		else
		{
			x->next=ptr;
		    x->prev=ptr->prev;
		    ptr->prev->next=x;
		    ptr->prev=x;
		}
		
	}
	display();
}

void dlt_beg()
{
	display();
	if(start==NULL)
	{
		printf("\nUNDERFLOW!! List is empty");
	}
	else if(start->next==NULL)                                                // if list has only one node //
	{
		temp=start;
		start=NULL;
		free(temp);
	}
	else
	{
		temp=start;
		start=start->next;
		start->prev=NULL;
		free(temp);
	}
	display();
}

void dlt_end()
{
	display();
	if(start==NULL)
	{
		printf("\nUNDERFLOW!! List is empty");
	}
	else if(start->next==NULL)
	{
		temp=start;
		start=NULL;
		free(temp);
		
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		temp=ptr;
		ptr->prev->next=NULL;
		free(temp);
	}
	display();
}

void dlt_after()
{
	display();
	if(start==NULL)
	{
		printf("\nUNDERFLOW!! List is empty");
	}
	else
	{
		printf("\nEnter node after which element is to be deleted:");
		scanf("%d",&num);
		if(start->data==num && start->next==NULL)
		{
			printf("No node present after key, deletion impossible!!");
			return;
		}
		ptr=start;
		while(ptr->data!=num)
		{
			ptr=ptr->next;
		}
		if(ptr->next==NULL)
		{
			printf("\nNo node present after key");
			return;
		}
		if(ptr->next->next==NULL)                                     // if node before last node isthe key //
		{
			temp=ptr->next;
			ptr->next=NULL;
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
	display();
}

void dlt_before()
{
	display();
	if(start==NULL)
	{
		printf("\nUNDERFLOW!! List is empty");
	}
	else
	{
		
		printf("\nEnter node before which element is to be deleted:");
		scanf("%d",&num);
		if(start->data==num && start->prev==NULL)
		{
			printf("\nNo node before key so dlt not possible!!");
			return;
		}
		ptr=start;
		while(ptr->data!=num)
		{
			ptr=ptr->next;
		}
		if(ptr->prev->prev==NULL)
		{
			temp=ptr->prev;
			start=start->next;
			start->prev=NULL;
			free(temp);
		}
		else
		{
			temp=ptr->prev;
		    temp->prev->next=ptr;
		    ptr->prev=temp->prev;
		    free(temp);
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

