#include <stdio.h>
#include <ctype.h> 
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


void evaluate_postfix(char postfix[])
{

    int i;
    char item;
    int val;
    int A, B;

   
    for (i = 0; postfix[i] != ')'; i++)
	   {
        item = postfix[i];
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
                val = B * A;
                break;

            case '/':
                val = B / A;
                break;

            case '+':
                val = B + A;
                break;

            case '-':
                val = B - A;
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

    
    char postfix_exp[SIZE];
   
    printf(" \nEnter postfix expression,\npress right parenthesis ')' for end expression : ");

    

    for (i = 0; i <= SIZE - 1; i++) 
	{
        scanf("%c", &postfix_exp[i]);

        if (postfix_exp[i] == ')') 
        {
            break;
        }
    }

    

    evaluate_postfix(postfix_exp);

    
}
