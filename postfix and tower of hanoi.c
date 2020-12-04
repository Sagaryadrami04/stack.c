#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#define size 50
int stk[size],top=-1;
void push(int elem)
{
	stk[++top]=elem;
}
int pop()
{
	return stk[top--];
}
void postfix_eval(char *postfix)
{
	char sym;
	int i=0,op1,op2;
	while((sym=postfix[i++])!='\0')
	{
		if(isdigit(sym))
			push(sym-'0');
		else
		{
			op2=pop();
			op1=pop();
			switch(sym)
			{
				case '+' :push(op1+op2);
					  break;
				case '-' :push(op1-op2);
					  break;
				case '*' :push(op1*op2);
					  break;
				case '/' :push(op1/op2);
				          break;
    				case '%' :push(op1%op2);
					  break;
				case '^' :push(pow(op1,op2));
					  break;
				default  :printf("Enter a valid operator\n");
					  exit(0);
					  break;
		       }
		}
	}
	printf("Result of postfix Expression is %d",pop());
}
void tower_of_hanoi(int n,char BEG,char AUX,char END)
{
	int ele;
	if(n==1)
		printf("\n Move disk 1 from peg  %c to  peg %c\n",BEG,END);
	else
	{
		tower_of_hanoi(n-1,BEG,END,AUX);
		printf("\n move disk %d from  peg %c to peg %c\n",n,BEG,AUX);
		tower_of_hanoi(n-1,AUX,BEG,END);
	}
}
void main()
{
	char postfix[30];
	int ch,num;
	while(1)
	{
		printf("\n1.postfix eval\n2.Tower of hanoi\n3.exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter a valid postfix expression\n");
				scanf("%s",postfix);
				postfix_eval(postfix);
				break;
			case 2:printf("Enter no. of disk\n");
			       scanf("%d",&num);
			       printf("The Sequence of move involved in the tower of hanoi are:\n");
			       tower_of_hanoi(num,'A','B','c');
			       break;
			case 3:exit(0);
			default:printf("Invalid choice\n");
		}
	}
}
