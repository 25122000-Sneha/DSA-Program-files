#include <stdio.h>
#include <malloc.h>
#include <process.h>
struct node
{
	int data;
	struct node *next;
};
struct node *front, *rear, *x, *ptr, *temp;
void insert();
void dlt();
void display();
main()
{
	int choice;
	while(1)
	{
		printf("\n\n------MENU--------");
		printf("\n1. Enqueue(insertion)\n2. Dequeue(deletion)\n3. Display\n4. ***********EXIT*************");
		printf("\nEnter choice(1-4):");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\n****INSERT*****");
				insert();
				break;
			case 2:
				printf("\n****DELETE****");
				dlt();
				break;
			case 3:
				printf("\n****DISPLAY****");
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("\nWrong choice");
		}
	}
}

void insert()
{
	x=(struct node*)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("\nOverflow!! Unable to allocate memory!!");
	}
	else
	{
		
	
	    printf("\nEnter data u want to insert:");
	    scanf("%d",&x->data);
	    if(front==NULL)
	    {
		    x->next=NULL;
		    front=x;
		    rear=x;
		
	    }
	    else
	    {
		    x->next=NULL;
		    rear->next=x;
		    rear=x;
	    }
    }
	
}

void dlt()
{
	if(front==NULL)
	{
		printf("\nUnderflow!! Queue is empty");
	}
	else
	{
		temp=front;
		front=front->next;
		free(temp);
	}
}

void display()
{
	if(front==NULL)
	{
		printf("\nList is empty!!");
	}
	else if(front==rear)
	{
		printf("\nContents of the queue:\n");
		printf(" %d",front->data);
	}
	else
	{
		printf("\nContents of the queue:\n");
		ptr=front;
		while(ptr!=rear)
		{
			printf(" %d",ptr->data);
			ptr=ptr->next;
		}
		if(ptr==rear)
		{
			printf(" %d",ptr->data);
		}
	}
}




