#include <stdio.h>
#include <ctype.h> 
#include <string.h>
#define SIZE 100 


int stack[SIZE];
int top = -1; 


void push(int item)
{

    if (top >= SIZE - 1) 
	{
        printf("stack over flow");
    }
    else 
	{
        top = top + 1;
        stack[top] = item;
    }
}


int pop()
{
    int item;
    if (top < 0) 
	{
        printf("stack under flow");
    }
    else 
	{
        item = stack[top];
        top = top - 1;
        return (item);
    }
}


void evaluate_prefix(char prefix_exp[])
{

    int i;
    char item;
    int val;
    int A, B;
    strrev(prefix_exp);
   
    for (i = 0; prefix_exp[i] != '('; i++)
	   {
        item = prefix_exp[i];
        if(item==')')
        {
        	i=i+1;
        	item=prefix_exp[i];
		}
        if (isdigit(item)) 
		{
            
            push(item - '0');
        }
        else if (item == '+' || item == '-' || item == '*' || item == '/') 
		{
            
            A = pop();
            B = pop();

            switch (item) 
            {
            case '*':
                val = A * B;
                break;

            case '/':
                val = A / B;
                break;

            case '+':
                val = A + B;
                break;

            case '-':
                val = A - B;
                break;
            }

            
            push(val);
        }
    }
    printf(" \n Result of expression evaluation : %d \n", pop());
}

main()
{

    int i;

    
    char prefix_exp[SIZE];
   
    printf(" \nEnter prefix expression,\npress left parenthesis '(' for beg & right parenthesis ')' for end expression : ");

    

    for (i = 0; i <= SIZE - 1; i++) 
	{
        scanf("%c", &prefix_exp[i]);

        if (prefix_exp[i] == ')') 
        {
            break;
        }
    }

    

    evaluate_prefix(prefix_exp);

    
}
