#include <stdio.h>
#include <malloc.h>
#include <process.h>
struct node
{
	int data;
	struct node *next;
};

struct node *ptr,*x,*temp;
struct node *start=NULL;
int key;

void create();
void insert_after_key();
void insert_before_key();
void dlt_after_key();
void dlt_before_key();
void display();

main()
{
	int choice;
	while(1)
	{
		printf("\n\n---------Main Menu-----------");
		printf("\n1. Create a circular linked list");
		printf("\n2. Insert a node after key");
		printf("\n3. Insert a node before key");
		printf("\n4. Delete a node after key");
		printf("\n5. Delete a node before key");
		printf("\n6. Display the circular linked list");
		printf("\n7. --------EXIT-----------");
		printf("\nEnter choice(1-7):");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\n*****Creating a circular linked list*****");
				create();
				break;
			case 2:
				printf("\n******Insertion after key ******");
				insert_after_key();
				break;
			case 3:
				printf("\n******Insertion before key******");
				insert_before_key();
				break;
			case 4:
				printf("\n******Deletion after key******");
				dlt_after_key();
				break;
			case 5:
			    printf("\n******Deletion before key******");
				dlt_before_key();
				break;
		
			case 6:
				printf("\n******Display******");
				display();
				break;
			case 7:
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
		ptr=ptr->next;
		
	}
	ptr->next=start;
}

void insert_after_key()
{
	x=(struct node*)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("\nOverflow!! Unable to allocate memory");
		
	}
	else
	{
		printf("\nEnter key element:");                                        
		scanf("%d",&key);
		printf("\nEnter data u want to insert:");
		scanf("%d",&x->data);
		ptr=start;
		while(ptr->data!=key)
		{
			ptr=ptr->next;
		}
		x->next=ptr->next;
		ptr->next=x;
		
	}
}

void insert_before_key()
{
	x=(struct node*)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("\nOverflow!! Unable to allocate memory");
		
	}
	else
	{
		printf("\nEnter key element:");
		scanf("%d",&key);
		printf("\nEnter data u want to insert:");
		scanf("%d",&x->data);
		ptr=start;
		while(ptr->next->data!=key)
		{
		    ptr=ptr->next;
		}
		
		
		if(ptr->next==start)                                                // if first node is the key //
		{
			x->next=start;
			ptr->next=x;
			start=x;
		}	
		else
		{
			x->next=ptr->next;
		    ptr->next=x;
		}
	}
}

void dlt_after_key()
{
	if(start==NULL)
	{
		printf("\nUnderflow!! List is empty");
	}
	else
	{
		printf("\nEnter key element:");
		scanf("%d",&key);
		ptr=start;
		if(start->data==key && start->next==start)
		{
			temp=start;
			start=NULL;
			free(temp);
			return;
		}
		while(ptr->data!=key)                                   //search for key//
		{
			ptr=ptr->next;
		}
		if(ptr->next==start)                                  // when the last node is the key //
		{
			temp=start;
			start=start->next;
			ptr->next=start;
			free(temp);
		}
		else
		{
			temp=ptr->next;
		    ptr->next=temp->next;
		    free(temp);
		}
		
	}
}

void dlt_before_key()
{
	if(start==NULL)
	{
		printf("\nUnderflow!! List is empty");
	}
	else
	{
		printf("\nEnter key element:");
		scanf("%d",&key);
		ptr=start;
		if(key==start->data && start->next==start)
	    {
		    temp=start;
			start=NULL;  
			free(temp);
			return;                                                                 //If head node is the key and there are no more nodes in the list
	    }
		while(ptr->next->next->data!=key)                                // search for key//
		{
			ptr=ptr->next;
		}
		if(ptr->next->next==start->next)                                    // when the node after start is the key//
		{
			temp=start;
			start=start->next;                                     
			ptr->next=start;
			free(temp);
		}
		else
		{
		
		    temp=ptr->next;
		    ptr->next=temp->next;
		    free(temp);
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


	
	

