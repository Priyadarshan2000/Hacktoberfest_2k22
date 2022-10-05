#include<stdio.h>
int stack[100],choice,n,top,x,i;
void push();
void pop();
void display();
int main()
{
	top=-1;
	printf("\nEnter the size of the stack");
	scanf("%d",&n);
	printf("\nSTACK OPERATION USING ARRAY");
	printf("\n\t 1.Push \n\t 2.Pop \n\t 3.Display  \n\t 4.Exit");
	do
	{
		printf("\nEnter the choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			push();
			break;
			case 2:
			pop();
			break;
			case 3 :
			display();
			break;
			case 4:
			printf("\nExit point");
			break;
			default:
			{
	    	printf("\nWRONG CHOICE ");
	        }
		}
	}while(choice!=4);
     return 0;
}
void push()
{
	if(top>=n-1)
	{
	printf("\nSTACK IS OVERFLOW");
    }
	else
	{
	printf("\nEnter a value to be pushed");
	scanf("%d",&x);
	top++;
	stack[top]=x;
    }
}
void pop()
{
	if(top<=-1)
	{
	printf("\nSTACK IS UNDERFLOW");
	}
	else
	{
	printf("\nThe popped element is %d",stack[top]);
	top--;
    }
}
void display()
{
	if(top>=0)
	{
		printf("\n The elements in stack \n");
		for(i=top;i>=0;i--)
		printf("\n %d",stack[i]);
		printf("\n Press next choice ");
		}
		else
		{
			printf("Stack is empty");
		}
	}





