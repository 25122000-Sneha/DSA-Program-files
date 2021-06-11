#include<stdio.h>
#include<process.h>      
#include<ctype.h>
#include<string.h>

#define SIZE 100
char stack[SIZE];
int top = -1;

void push(char item);
char pop();
int is_operator(char op);
int precedence(char op);
void infix_to_prefix(char infix_exp[], char prefix_exp[]);

int main()
{
	char infix[SIZE], prefix[SIZE];        

	printf("\nEnter Infix expression : ");
	gets(infix);

	infix_to_prefix(infix,prefix);                   
	printf("Prefix Expression: ");
	puts(prefix);        
	return (0);
}



void push(char item)
{
	if(top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}


char pop()
{
	char item ;

	if(top <0)
	{
		printf("stack under flow: invalid infix expression");
		getchar();
		exit(1);
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}


int is_operator(char op)
{
	if( op== '^' || op=='*' || op=='%' || op== '/' || op== '+' || op=='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}



int precedence(char op)
{
	if(op== '^')
	{
		return(3);
	}
	else if(op=='*' || op=='/' || op=='%')
	{
		return(2);
	}
	else if(op=='+' || op=='-')          
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void infix_to_prefix(char infix_exp[], char prefix_exp[])
{ 
	int i, j;
	char item;
	char x;
	strrev(infix_exp);

	                 
	i=0;
	j=0;
	item=infix_exp[i]; 
	while(item!='\0')
	{
		if(item==')')
		{
			infix_exp[i]='(';
		}
		else if(item=='(')
		{
			infix_exp[i]=')';
		}
		i++;
		item=infix_exp[i];
	}
	i=0;
	item=infix_exp[i];
	push('(');                              
	strcat(infix_exp,")");        

	while(item != '\0')        
	{
		if(item == '(')
		{
			push(item);
		}
		else if( isdigit(item) || isalpha(item))
		{
			prefix_exp[j] = item;              
			j++;
		}
		else if(is_operator(item) == 1)        
		{
			x=pop();
			while(is_operator(x) == 1 && precedence(x)>precedence(item))
			{
				prefix_exp[j] = x;                  
				j++;
				x = pop();                       
			}
			push(x);
			
			push(item);                 
		}
		else if(item == ')')         
		{
			x = pop();                   
			while(x != '(')                
			{
				prefix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{ 
			printf("\nInvalid infix Expression.\n");        
			getchar();
			exit(1);
		}
		i++;


		item = infix_exp[i]; 
	} 
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");        
		getchar();
		exit(1);
    }
    prefix_exp[j] = '\0';
    strrev(prefix_exp);
    

}
