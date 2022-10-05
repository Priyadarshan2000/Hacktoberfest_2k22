#include<stdio.h>
#include <stdio.h>
#include<stdlib.h>
#define max 5
void insert();
void deletion();
void display();
void peek();
int queue[max];
int rear=-1,front=-1;
void insert()
{
    int item;
    if( (front==0&&rear==max - 1)||front==rear+1)
    {	
    printf("Queue Overflow \n");
    return;
}
	else
    {
        if (front==- 1)
        {
        front++;
        }
        rear=(rear+1)%max;
        printf("Inset the element in queue\n");
        scanf("%d",&item);
        queue[rear] =item;
    }
}
void deletion()
{
    if (front==-1)
    {
        printf("Queue Underflow \n");
        return;
    }
    printf("%d is deleted item",queue[front]);
    if(front==rear)
    {
    front=-1;
    rear=-1;
}
else
{
front=(front+1)%max;
}
}
void peek()
{
if(front==-1)
{
printf("Queue Underflow \n");
return;
}
else
{
printf("%d\n",queue[front]);
}
}
void display()
{
    int i;
    if (front==- 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is\n");
        for(i=front;i!=rear;i=(i+1)%max)
            printf("%d \t",queue[i]);
        printf("%d\n",queue[rear]);
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("enter 1 for insert element\n enter 2 for delete\n enter 3 for display\n enter 4 for peek\n enter 5 for exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:insert();
            break;
            case 2:deletion();
            break;
            case 3:display();
            break;
            case 4:peek();
            break;
            case 5:exit(0);
        }
}
} 
