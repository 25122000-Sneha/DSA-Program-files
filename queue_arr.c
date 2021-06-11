#include <stdio.h>
#include <process.h>

int queue[100];
int MAX;
int front=-1,rear=-1;
int num;

void insert();
void dlt();
void display();

main()
{
	int ch;
	printf("Enter size of queue:");
	scanf("%d",&MAX);
	while(1)
	{
		printf("\n\n***********MAIN MENU**************");
		printf("\n1. Enqueue(insertion)\n2. Dequeue(deletion)\n3. Display\n4. ***********EXIT*************");
		printf("\nEnter choice(1-4):");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n*******INSERTION********");
				insert();
				break;
			case 2:
				printf("\n*******DELETION**********");
				dlt();
				break;
			case 3:
				printf("\n*******DISPLAY**********");
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("\nWrong choice!!!!!");
				
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

