#include <stdio.h>
#include <malloc.h>
#include <process.h>

int queue[100];
int MAX,num;
int left=-1;
int right=-1;

void insert_left()
{
	if((left==0 && right==MAX-1) || left==right+1)
	{
		printf("\nOVERFLOW!! Queue is full");
		return;
	}
	printf("\nEnter data to insert:");
	scanf("%d",&num);
	if(left==NULL)
	{
		left=0;
		right=0;
	}
	else
	{
		if(left==0)
		{
			left=MAX-1;
		}
		else
		{
			left=left-1;
		}
	}
	queue[left]=num;
	
}

void insert_right()
{
	if(left==0 && right==MAX-1)
	{
		printf("\nOVERFLOW!! Queue is full");
		return;
	}
	printf("\nEnter data to insert:");
	scanf("%d",&num);
	if(left==-1)
	{
		left=0;
		right=0;
	}
	else
	{
		if(right==MAX-1)
		{
			right=0;
		}
		else
		{
			right=right+1;
		}
	}
	queue[right]=num;
}

void dlt_right()
{
	if(left==-1)
	{
		printf("\nUNDERFLOW!! Queue is empty");
		return;
	}
	printf("\nDeleted element is %d",queue[right]);
	if(left==right)
	{
		left=-1;
		right=-1;
	}
	else
	{
		if(right==0)
		{
			right=MAX-1;
		}
		else
		{
			right=right-1;
		}
	}
	
}

void dlt_left()
{
	if(left==-1)
	{
		printf("\nUNDERFLOW!! Queue is empty");
		return;
	}
	printf("\nDeleted element is %d",queue[left]);
	if(left==right)
	{
		left=-1;
		right=-1;
		
	}
	else
	{
		if(left==MAX-1)
		{
			left=0;
		}
		else
		{
			left=left+1;
		}
	}
}

void display()
 {
 	
	int i;
	if(left==-1)
	{
		printf("\nQueue is empty");
		return;
	}
	if(left<=right)
	{
		printf("\nContents of the queue:\n");
		for(i=left;i<=right;i++)
		{
			printf(" %d",queue[i]);
		}
		
	}
	else
	{
		printf("\nContents of the queue:\n");
		while(left<=MAX-1)
		{
			printf(" %d",queue[left]);
			left++;
		}
		left=0;
		while(left<=right)
		{
			printf(" %d",queue[left]);
			left++;
		}
	}
}

main()
{
	int ch;
	printf("\nEnter MAX value:");
	scanf("%d",&MAX);
	while(1)
	{
		printf("\n\n--------MAIN MENU---------");
		printf("\n1. Insert at right\n2. Delete from left\n3. Delete from right\n4. Display deque\n5. -----------EXIT------------");
		printf("\nEnter choice(1-4):");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n*******Insert at right*******");
				insert_right();
				break;
			case 2:
				printf("\n*******Delete at left*******");
				dlt_left();
				break;
			case 3:
				printf("\n*******Delete at right*******");
				dlt_right();
				break;
			case 4:
				printf("\n******Display*********");
				display();
				break;
			case 5:
				printf("\n********End*******");
				exit(0);
			default:
				printf("\nWrong choice!!");
				break;
		}
		
	}
	
}


