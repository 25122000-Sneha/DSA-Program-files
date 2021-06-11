#include <stdio.h>
#include <malloc.h>
#include <process.h>
struct node
{
	int data;
	struct node *next;
};
struct node *ptr;
struct node *start=NULL;
struct node *x;
void insert_beg();
void insert_end();
void insert_pos();
int count();
void display();

main()
{
	
	int choice,n;
	while(1)
	{
		printf("\n\n----------Main menu-----------");
		printf("\n1. Insert a node at the end");
		printf("\n2. Count the no. of nodes");
		printf("\n3. Insert a node at the beginning");
		printf("\n4. Insert a node after the specified no. of nodes");
		printf("\n5. Display the linked list");
		printf("\n6. ---------EXIT-----------------");
		printf("\nEnter choice(1-6):");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("****Insertion at the end****");
				insert_end();
				break;
			case 2:
				printf("****Count the no. of nodes****");
				n=count();
				printf("\nNo. of nodes in list=%d",n);
				break;
			case 3:
				printf("****Insertion at the beginning****");
				insert_beg();
				break;
			case 4:
				printf("****Insertion after n-th node****");
				insert_pos();
				break;
			case 5:
				printf("****Display list****");
				display();
				break;
			case 6:
				exit(0);
			default:
				printf("Wrong choice");
				
		}
		
			
	}
}
void insert_end()
{
	
	x=(struct node*)malloc(sizeof(struct node));	
	printf("\nEnter data u would like to insert:");
	scanf("%d",&x->data);
	if(x==NULL)
	{
		printf("Unable to allocate memory");
		exit(0);
	}
	if(start==NULL)
	{
		x->next=NULL;
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
		ptr->next=x;
		
	}
}
int count()
{
	int c=0;
	ptr=start;
	while(ptr!=NULL)
	{
		c=c+1;
		ptr=ptr->next;
	}
	return(c);
}
void insert_beg()
{
	x=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter data u would like to insert:");
	scanf("%d",&x->data);
	if(x==NULL)
	{
		printf("Unable to allocate memory");
		exit(0);
	}
	if(start==NULL)
	{
		x->next=NULL;
		start=x;
	}
	else
	{
		x->next=start;
		start=x;
	}
}
void insert_pos()
{
	int i,pos;
	if(start==NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		x=(struct node *)malloc(sizeof(struct node));
		if(x==NULL)
		{
		printf("Unable to allocate memory");
		exit(0);
		}
		printf("\nEnter data u would like to insert:");
		scanf("%d",&x->data);
		printf("Enter node no. after which it is to be inserted:");
		scanf("%d",&pos);
		ptr=start;
		for(i=0;i<pos-1;i++)
		{
			ptr=ptr->next;
			
		}
		x->next=ptr->next;
		ptr->next=x;
	}
	
}
void display()
{
	ptr=start;
	if(start==NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		printf("\nContents of linked list:\n");
		while(ptr!=NULL)
		{
		   printf(" %d",ptr->data);
		   ptr=ptr->next;
	    }
	}	
}
