#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max 20
int top=-1;
int stack[max];
int pop();
void push(int);
void push(int x)
{
	if(top==max-1)
	{
		printf("not ok\n");
		return;
	}
	else
	{
		top++;
		stack[top]=x;
	}	
}
int pop()
{
	if(top==-1)
	{
		printf("stack is empty\n");
		return -99;
	}
	else
		return stack[top--];
}
void postfixevaluation(char str[])
{
	int i,x,y;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='^')
		{
			x=pop();
			y=pop();	
			switch(str[i])
			{
				case '+':
					push(y+x);
					break;
				case '-':
					push(y-x);
					break;
				case '*':
					push(y*x);
					break;
				case '/':
					push(y/x);
					break;
				case '^':
					push(pow(y,x));
					break;
				default:
					printf("wrong input");
			}
		}
		else
			push(str[i]-48);
	}
	printf("result=%d",stack[top]);
}
int main(){
	char *str;
	int n=10;
	printf("Enter postfix expression:");
	str=(char*)malloc(n*sizeof(char));
	gets(str);
	postfixevaluation(str);
	free(str);
	return 0;
}
