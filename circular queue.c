#include<stdio.h>
#include<stdlib.h>
#define max 5
void qmain();
char qdelete();
void qdisplay();
char cqueue[max],item,ele;
int ch,front=0,rear=0;
void main()
{
	while(1)
	{
		printf("\n1) qinsert \n2) qdelete \n3) qdisplay \n4) exit\n");
		printf("enter ur choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			
			case 1: if(front==(rear+1)%max)
			{
				printf("queue overflow\n");
			}
			else
			{
				printf("enter the element\n");
				scanf(" %c",&ele);
                                qinsert();
			}
			break;
			case 2: if(front==rear)
			{
				printf("queue underflow\n");
			}
			else
			{
				item=qdelete();
			}
			break;
			case 3: if(front==rear)
				{
					printf("queue underflow\n");
				}
				else
				{
					qdisplay();
				}
			break;
			case 4: exit(0);
			default: printf(" invalid option\n");
		}
	}
}
void qinsert()
{
	rear=(rear+1)%max;
	cqueue[rear]=ele;
}
char qdelete()
{
	front=(front+1)%max;
	printf("enter the element to be deleted\n%c",cqueue[front]);
	return cqueue[front];
}
void qdisplay()
{
	int i=(front+1)%max;
	while(i!=rear)
	{
		printf("%c\t",cqueue[i]);
	i=(i+1)%max;
	}
	printf("%c\t",cqueue[i]);
}
		
		
				
			

