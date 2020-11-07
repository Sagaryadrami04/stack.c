#include<stdio.h>
#include<stdlib.h>
#define max 5
int push();
int pop();
void display();
int overflow();
int underflow();
int ele,top=-1,stack[max],choice,i;
int main()
{
	while(1)
	{
	  printf("1.push\n 2.pop\n3.display\n4.exit\n");
	  printf("enter your choice:\t");
	  scanf("%d",&choice);
	  switch(choice)
	  {
		case 1:
 			if (overflow())
			{
			  printf(" arre re..stack overflow!!!\n");
			}
 			else
			{
	 		 printf("enter the element to be pushed:\t");
	  		scanf("%d",&ele);
			push(ele);
			}
		        break;
		case 2:
 			if(underflow())
			{
	 		 printf("arre re..stack underflow!!!\n");
			}
 			else
			{
			  ele=stack[top];
	  		  printf("the popped out element is:%d\n",ele);
			  pop();
		        }
			break;
		case 3:display();
			break;
		case 4:exit(0);
			break;
		default:printf("very sad of u.. invalid choice bro!!!\n");
	 }
	}
}
int push(int ele)
{
 
	  top++;
	  stack[top]=ele;

}
int pop()
{
 
	  top--;
	}
void display()
{
	if(top==-1)
	{
		printf("stack is empty\n");
	}
	else
	{
		printf("the element is stack are:\n");
		for(i=top;i>=0;i--)
		{
		  printf("%d\n",stack[i]);
		}
	}
}
int overflow()
{
	if(top==max-1)
		return 1;
	else
		return 0;
}
int underflow()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
