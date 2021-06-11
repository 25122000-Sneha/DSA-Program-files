#include <stdio.h>
#include <process.h>
int stack[100],choice,ch,max,val,i;
int top=-1;
void push();
void pop();
void display();
main()
{
	printf("\nEnter size of the stack:");
	scanf("%d",&max);
	while(1)
	{
		printf("\n\n*****Array******");
		printf("\n\n------2nd Menu-------");
		printf("\n1. Push\n2. Pop\n3. Display\n4. -------EXIT--------");
		printf("\nEnter choice(1-4):");
        scanf("%d",&choice);
	    switch(choice)
	    {
	    	case 1:
	    		printf("****PUSH****");
	    		push();
	    		break;
	    	case 2:
	    		printf("****POP****");
	    		pop();
	    		break;
	    	case 3:
	    		printf("****DISPLAY****");
	    		display();
	    		break;
	    	case 4:
	    		exit(0);
	    	default:
	    		printf("Wrong choice!");
		}
    }
	
}
void push()
{
	if(top>=max-1)
	{
		printf("\nStack Overflow");
		
	}
	else
	{
		printf("\nEnter value to be pushed:");
		scanf("%d",&val);
		top=top+1;
		stack[top]=val;
	}
}
void pop()
{
	if(top==-1)
	{
		printf("\nStack underflow");
	}
	else
	{
		val=stack[top];
		printf("\nPopped element is %d",val);
		top=top-1;
	}
}
void display()
{
	if(top==-1)
	{
		printf("\nStack is empty");
	}
	else
	{
		printf("\nContents of stack:\n");
		for(i=top;i>=0;i--)
		{
			printf("\n%d",stack[i]);
		}
	}
}
