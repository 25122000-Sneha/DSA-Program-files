#include <stdio.h>
#include <malloc.h>
#include <process.h>

int queue[100];
int MAX;
int front=-1,rear=-1;
int num;

struct node
{
	int data;
	struct node *next;
};
struct node *front1, *rear1, *x, *ptr, *temp;

void insert();
void dlt();
void display();

void insert_list();
void dlt_list();
void display_list();

main()
{
	int ch,choice;
	
	while(1)
	{
		printf("\n\n*********IMPLEMENTATION*************");
		printf("\n1. Using Array\n2. Using Linked list\n3. ******END OF PROGRAM******");
		printf("\nEnter choice of implementation:");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("Enter size of queue:");
	        scanf("%d",&MAX);
		}
	
		
		switch(choice)
		{
			case 1:
				printf("*********ARRAY***********");
				while(1)
				{
										
				printf("\n\n***********MAIN MENU**************");
		        printf("\n1. Enqueue(insertion)\n2. Dequeue(deletion)\n3. Display\n4. ***********EXIT*************");
		        printf("\nEnter choice(1-4):");
		        scanf("%d",&ch);
		        switch(ch)
		        {
		        	case 1:
		        		printf("\n*********INSERTION*********");
		        		insert();
		        		break;
		        	case 2:
		        		printf("\n*********DELETION***********");
		        		dlt();
		        		break;
		        	case 3:
		        		printf("\n*********DISPLAY************");
		        		display();
		        		break;
		        	case 4:
		        		printf("********EXIT implementation********");
		        		break;
		        	default:
		        		printf("Wrong choice");
		        		break;
				}
				if(ch==4)
				{
					break;
				}
			   }
				break;
		    case 2:
		    	printf("\n********LINKED LIST**********");
		    	while(1)
		    	{
				
		    	printf("\n\n------MAIN MENU--------");
		        printf("\n1. Enqueue(insertion)\n2. Dequeue(deletion)\n3. Display\n4. ***********EXIT*************");
		        printf("\nEnter choice(1-4):");
		        scanf("%d",&ch);
		        switch(ch)
		        {
			        case 1:
				        printf("\n****INSERT*****");
				        insert_list();
				        break;
			        case 2:
				        printf("\n****DELETE****");
				        dlt_list();
				        break;
			        case 3:
				        printf("\n****DISPLAY****");
				        display_list();
				        break;
			        case 4:
				        printf("******EXIT IMPLEMENTATION******");
				        break;
			        default:
			     	    printf("\nWrong choice");
			     	    break;
		        }
		        if(ch==4)
		        {
		        	break;
				}
		        }
		        break;
		    case 3:
		    	printf("********END*********");
		    	exit(0);
		    default:
		    	printf("\nWrong choice!!");
		    	break;
			         
		}
		
	}
}

void insert()
{
	printf("\nEnter value to be inserted:");
	scanf("%d",&num);
	if(rear==MAX-1)
	{
		printf("\nOverflow!! Unable to allocate memory");
	}
	else if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
		queue[rear]=num;
		
	}
	else
	{
		rear=rear+1;
		queue[rear]=num;
	}
	
	
}

void dlt()
{
	if(front==-1)
	{
		printf("\nUnderflow!! Queue is empty!!");
	}
	else if(front==rear)
	{
		num=queue[front];
		front=-1;
		rear=-1;
	}
	else
	{
		num=queue[front];
		front=front+1;
	}
}

void display()
{
	int i;
	if(front==-1)
	{
		printf("\nQueue is empty");
	}
	else
	{
		printf("\nContents of the queue:\n");
		for(i=front;i<=rear;i++)
		{
			printf(" %d",queue[i]);
		}
	}
}

void insert_list()
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
	    if(front1==NULL)
	    {
		    x->next=NULL;
		    front1=x;
		    rear1=x;
		
	    }
	    else
	    {
		    x->next=NULL;
		    rear1->next=x;
		    rear1=x;
	    }
    }
	
}

void dlt_list()
{
	if(front1==NULL)
	{
		printf("\nUnderflow!! Queue is empty");
	}
	else
	{
		temp=front1;
		front1=front1->next;
		free(temp);
	}
}

void display_list()
{
	if(front1==NULL)
	{
		printf("\nList is empty!!");
	}
	
	else
	{
		printf("\nContents of the queue:\n");
		ptr=front1;
		while(ptr!=rear1)
		{
			printf(" %d",ptr->data);
			ptr=ptr->next;
		}
		if(ptr==rear1)
		{
			printf(" %d",ptr->data);
		}
	}
}


