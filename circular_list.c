#include <stdio.h>
#include <malloc.h>
#include <process.h>
struct node
{
	int data;
	struct node *next;
};

struct node *ptr,*x,*locp,*temp,*d;
struct node *start=NULL;

void create();
void insert_beg();
void insert_end();
void dlt_beg();
void dlt_end();
void dlt_list();
void display();

main()
{
	int index,choice;
	while(1)
	{
		printf("\n\n---------Main Menu-----------");
		printf("\n1. Create a circular linked list");
		printf("\n2. Insert a node at the front");
		printf("\n3. Insert a node at the end");
		printf("\n4. Delete a node at the front");
		printf("\n5. Delete a node at the end");
		printf("\n6. Delete the circular linked list");
		printf("\n7. Display the circular linked list");
		printf("\n8. --------EXIT-----------");
		printf("\nEnter choice(1-8):");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\n*****Creating a circular linked list*****");
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
				printf("\n******Deletion at the beginning******");
				dlt_beg();
				break;
			case 5:
			    printf("\n******Deletion at the end******");
				dlt_end();
				break;
			case 6:
				printf("\n******Delete entire circular list*****");
				dlt_list();
				break;
		
			case 7:
				printf("\n******Display******");
				display();
				break;
			case 8:
				exit(0);
			default:
				printf("\nWrong choice!!");
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
	ptr=start;
	for(i=1;i<n;i++)
	{
		x=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter data u want to insert:");
		scanf("%d",&x->data);
		x->next=NULL;
		ptr->next=x;
		ptr=x;
		
	}
	ptr->next=start;
}
void insert_beg()
{
	x=(struct node*)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("\nOverflow!! Unable to allocate memory");
	}
	else
	{
		printf("\nEnter data u want to insert:");
		scanf("%d",&x->data);
		if(start==NULL)
		{
			start=x;
			x->next=start;
		}
		else
		{
			ptr=start;
			while(ptr->next!=start)
			{
				ptr=ptr->next;
			}
			x->next=start;
			ptr->next=x;
			start=x;
		}
	}
}
void insert_end()
{
	x=(struct node*)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("\nOverflow!! Unable to allocate memory");
	}
	else
	{
		printf("\nEnter data u want to insert:");
		scanf("%d",&x->data);
		if(start==NULL)
		{
			start=x;
			x->next=start;
		}
		else
		{
		
		    ptr=start;
		    while(ptr->next!=start)
		    {
			    ptr=ptr->next;
		    }
		    x->next=start;
		    ptr->next=x;
	    }
	}
}
void dlt_beg()
{
	
	if(start==NULL)
	{
		printf("\nUnderflow!! List is empty");
	}
	else if(start->next==start)
	{
		temp=start;
		printf("\nDeleted element is %d",temp->data);
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
		printf("\nDeleted element is %d",temp->data);
		free(temp);
	}
}
void dlt_end()
{
	if(start==NULL)
	{
		printf("\nUnderflow!! List is empty");
	}
	else if(start->next==start)
	{
		temp=start;
		printf("\nDeleted element is %d",temp->data);
		start=NULL;
		free(temp);
	}
	else
	{
		ptr=start;
		while(ptr->next!=start)
		{
			locp=ptr;
			ptr=ptr->next;
		}
		locp->next=start;
		printf("\nDeleted element is %d",ptr->data);
		free(ptr);
		
	}
}

void dlt_list()
{
	if(start==NULL)
	{
		printf("\nUnderflow!!List is empty");
	}
	else
	{
		ptr=start;
		d=start;
		while(d->next!=start)
		{
			ptr=start;
			while(ptr->next!=start)
			{
				locp=ptr;
				ptr=ptr->next;
				
			}
			locp->next=start;
			free(ptr);
			d=d->next;
		
		}
		if(d->next==start)
		{
			temp=d;
			start=NULL;
			free(temp);
		}
		if(start==NULL)
		{
			printf("\nAll nodes deleted successfully!!");
		}
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
		printf("\nContents of circular linked list:\n");
		while(ptr->next!=start)
		{
		   printf(" %d",ptr->data);
		   ptr=ptr->next;
	    }
	    printf(" %d",ptr->data);
	}	
}

