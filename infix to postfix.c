#include<stdio.h>
#include<stdlib.h>
#define max 100
void infix_to_postfix(char *infix,char *postfix);
void push(char element);
char pop();
int prec(char sym);
int top=-1,ele,i,j,sym;
char stack[100], infix[100],postfix[100];
void main()
{
	
	printf("enter the infix expression\n");
	scanf("%s",infix);
	infix_to_postfix(infix,postfix);
	printf("The postfix expression:%s\n",postfix);
}
void infix_to_postfix(char *infix,char *postfix)
{
	
	push('#');
	while(infix[i]!='\0')
	{
	sym=infix[i];
		if(isalnum(sym))
			postfix[j++]=sym;
		else if(sym=='(')
			push(sym);
		else if(sym==')')
		{
			while(stack[top]!='(')
				postfix[j++]=pop();
			ele=pop();
		}
		else
		{
			while(prec(stack[top])>=prec(sym))
			{
				postfix[j++]=pop();
				
			}
			push(sym);
		}
		i++;
	}
		while(stack[top]!='#')
		{
			postfix[j++]=pop();
			
		}
		postfix[j]='\0';
}
void push(char element)
{
	stack[++top]=element;
}
char pop()
{
	return stack[top--];
	
}
int prec(char sym)
{
	switch(sym)
	{
		case '#' : return 0;
		case '(' : return 1;
		case ')' : return 1;
		case '+' : return 2;
		case '-' : return 2;
		case '*' : return 3;
		case '/' : return 3;
		case '%' : return 3;
		case '^' : return 4;
		default  : printf("invalid\n");
			   exit(0);
	}
}
