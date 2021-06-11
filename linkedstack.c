#include <stdio.h>
#include <malloc.h>
#include <process.h>
struct node
{
	int data;
	struct node *next;
};
struct node *top,*x,*ptr;
void push();
void pop();
void display();
main()
{
	int choice;
	while(1)
	{
		printf("\n\n------MENU--------");
		printf("\n1. push\n2. pop\n3. display\n4. ------EXIT------");
		printf("\nEnter choice(1-4):");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\n****PUSH*****");
				push();
				break;
			case 2:
				printf("\n****POP****");
				pop();
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
void push()
{
	x=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter value to be pushed:");
	scanf("%d",&x->data);
	if(x==NULL)
	{
		printf("\nStack overflow");
	}
	if(top==NULL)
	{
		x->next=NULL;
		top=x;
	}
	else
	{
		x->next=top;
		top=x;
	}
}
void pop()
{
	if(top==NULL)
	{
		printf("\nStack underflow");
	}
	else
	{
		printf("\nPopped element is %d",top->data);
		ptr=top;
		top=top->next;
		free(ptr);
	}
}
void display()
{
	if(top==NULL)
	{
		printf("\nStack is empty");
		
	}
	else
	{
		ptr=top;
		while(ptr!=NULL)
		{
			printf("\n%d",ptr->data);
			ptr=ptr->next;
		}
		
	}
}
