#include <stdio.h>
#include <malloc.h>
#include <process.h>
struct node
{
	int data;
	struct node *next;
};
struct node *ptr,*x,*locp,*loc;
struct node *start=NULL;
int i,key,c=0;
void create();
void dlt_beg();
void dlt_end();
void search();
void dlt_after_key();
void dlt_before_key();
void display();

main()
{
	int index,choice;
	while(1)
	{
		printf("\n\n---------Main Menu-----------");
		printf("\n1. Create a linked list");
		printf("\n2. Delete an element at the front");
		printf("\n3. Delete an element at the end");
		printf("\n4. Search for key element");
		printf("\n5. Delete an element after key");
		printf("\n6. Delete an element before key");
		printf("\n7. Display the linked list");
		printf("\n8. --------EXIT-----------");
		printf("\nEnter choice(1-8):");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\n*****Creating a linked list*****");
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
				printf("\n******Search for key******");
				search();
				break;
			case 5:
			    printf("\n******Deletion after key******");
				dlt_after_key();
				break;
			case 6:
			    printf("\n******Deletion before key******");
				dlt_before_key();
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
	int n;
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
}
void dlt_beg()
{
	ptr=start;
	if(start==NULL)
	{
		printf("\nList is empty.UNDERFLOW!!");
	}
	else if(ptr->next==NULL)
	{
		start=NULL;
		free(ptr);
	}
	else
	{
		start=start->next;
		printf("\nDeleted element is %d",ptr->data);
		free(ptr);
	}
}
void dlt_end()
{
	ptr=start;
	if(start==NULL)
	{
		printf("\nList is empty!!UNDERFLOW!!");
	}
	else if(ptr->next==NULL)
	{
		start=NULL;
		printf("\nDeleted element is %d",ptr->data);
		free(ptr);
	}
	else
	{
		while(ptr->next!=NULL)
		{
			locp=ptr;
			ptr=ptr->next;
		}
		locp->next=NULL;
		printf("\nDeleted element is %d",ptr->data);
		free(ptr);
	}
}
void search()
{
	int n;
	printf("\nEnter key element value:");
	scanf("%d",&key);
	if(start==NULL)
	{
		printf("\nLinked list is empty");
	}
	else
	{
		n=0;
	    ptr=start;
	    while(ptr!=NULL)
	    {
	    	if(key==ptr->data)
	    	{
	    		c++;
	    		loc=ptr;
	    		break;
			}
			else
			{
				ptr=ptr->next;
			}
			n++;
		}
		if(c==0)
		{
			printf("\nKey not found!! Search is unsuccessful :(");
			return;
		}
	    printf("\nKey found at node index %d",n);
    }
    
}
void dlt_after_key()
{
	printf("\nEnter key element value:");
	scanf("%d",&key);
	if(start==NULL)
	{
		printf("\nList is empty!!");                                            //Empty List
	}
	else if(key==start->data && start->next==NULL)
	{
		printf("\nNo node present after key so deletion not possible");             //If head node is the key and there are no more nodes in the list
	}
	else
	{
		ptr=start;
		while(ptr->data!=key)
		{
			ptr=ptr->next;
			if(ptr==NULL)
			{
				printf("\nKey not found!!");
				return;
			}
		}
		
		if(ptr->next==NULL)
		{
			printf("\nNo node present after key so deletion not possible");              // if last node is the key //
		}
		else
		{
		    loc=ptr->next;
		    ptr->next=loc->next;
		    printf("\nDeleted element is %d",loc->data);
		    free(loc);
	    }
	}
}
void dlt_before_key()
{
	printf("\nEnter key element value:");
	scanf("%d",&key);
	if(start==NULL)
	{
		printf("\nList is empty");                                                    //Empty List
	}
	else if(key==start->data)
	{
		printf("\nNo node present before key so node cannot be deleted");                    //If head node is the key
	}
	else if(key==start->next->data)                                                          // if node after head node is the key //
	{
		ptr=start;
		start=start->next;
		printf("\nDeleted element is %d",ptr->data);
		free(ptr);
	}
	else
	{
		ptr=start;
		while(ptr->next->next->data!=key && ptr->next->next!=NULL)
		{
			ptr=ptr->next;
			if(ptr->next->next==NULL)
			{
				printf("\nKey not found!!");
				return;
			}
		}
		
		if(ptr->next->next->data==key)
		{
			locp=ptr->next;
			ptr->next=ptr->next->next;
			free(locp);
		}
		
	}
}
void display()
{
	if(start==NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		ptr=start;
		printf("\nContents of linked list:\n");
		while(ptr!=NULL)
		{
		   printf(" %d",ptr->data);
		   ptr=ptr->next;
	    }
	}	
}


