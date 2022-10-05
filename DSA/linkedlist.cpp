#include<stdio.h>
#include<stdlib.h>
void insert_begin();
void insert_end();
void insert_after();
void insert_before();
void insert_anyposition();
void delete_node();
void delete_before();
void reverse_print();
void reverse();
void display();
struct node
{
	int data;
	struct node *link;
};
struct node*head=NULL;
void insert_begin()
{
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&ptr->data);
	ptr->link=head;
	head=ptr;
}
void insert_end()
{
		struct node *ptr,*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&temp->data);
	if(head==NULL)
	{
		temp->link=head;
		head=temp;
		return;
		}
		ptr=head;
		while(ptr->link!=NULL)
	{
		ptr=ptr->link;
	}
	temp->link=ptr->link;
	ptr->link=temp;
}
void insert_after()
{
	int item;
		struct node *ptr,*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter data");
	scanf("%d",&temp->data);
	printf("enter item after which you want to insert\n");
	scanf("%d",&item);
		ptr=head;
		while(ptr!=NULL)
	{
		if(ptr->data==item)
		{
		temp->link=ptr->link;
	ptr->link=temp;
	return;	
		}
		else
		ptr=ptr->link;
	}
printf("element not found\n");
}
void insert_before()
{
	int item;
		struct node *ptr,*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter data");
	scanf("%d",&temp->data);
	printf("enter item before which you want to insert\n");
	scanf("%d",&item);
		ptr=head;
		if(head->data==item)
		{
			insert_begin();
			return;
		}
		while(ptr->link!=NULL)
	{
		if(ptr->link->data==item)
		{
		temp->link=ptr->link;
	ptr->link=temp;
	return;	
		}
		ptr=ptr->link;
	}
printf("element not found\n");
}
void insert_anyposition()
{
	int count=0,i,pos;	
		struct node *ptr,*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter data");
	scanf("%d",&temp->data);
	printf("enter the position where you want to insert\n");
	scanf("%d",&pos);
		ptr=head;
		while(ptr!=NULL)
	{
		count++;
		ptr=ptr->link;
	}
		if(pos>count+1||pos<1)
		{
			printf("invalid position\n");
			return;
		}
	ptr=head;
	for(i=1;i<=pos-2;i++)
	{
		ptr=ptr->link;
	}
		temp->link=ptr->link;
	ptr->link=temp;
}
void delete_node()
{
    int item;
	struct node*ptr,*cptr;
	printf("enter the item which you want to delete");
	scanf("%d",&item);
	if(head->data==item)
	{
		ptr=head;
		head=head->link;
		ptr->link=NULL;
		free(ptr);
		return;
	}
	ptr=head;
	while(ptr->link!=NULL)
	{
		if(ptr->link->data==item)
		{
			cptr=ptr->link;
			ptr->link=cptr->link;
			cptr->link=NULL;
			free(cptr);
			return;
		}
		else
		ptr=ptr->link;
	}
	printf("element not found");
}
void delete_before()
{
int item;
	struct node*ptr,*cptr;
	printf("enter the item before which you want to delete");
	scanf("%d",&item);
	if(head->data==item)
	{
		printf("deletion not possible");
		}	
		ptr=head;
		if(head->link->data==item)
		{
			ptr=head;
		head=head->link;
		ptr->link=NULL;
		free(ptr);
		return;
		}
		cptr=NULL;
		ptr=head;
			while(ptr->link!=NULL)
	{
		if(ptr->link->data==item)
		{
			cptr->link=ptr->link;
			ptr->link=NULL;
			free(ptr);
			return;
		}
		else
		{
			cptr=ptr;
			cptr=ptr->link;
		}
}
}
void reverse_print(struct node*ptr)
{
	if(ptr==NULL)
	return;

	else
		reverse_print(ptr->link);
		printf("%d\t",ptr->data);
	
}
void reverse()
{
	struct node *prev ,*current,*next;
	prev=NULL;
	current=head;
	while(current!=NULL)
	{
		next=current->link;
		current->link=prev;
		prev=current;
		current=next;
	}
	head=prev;
	display();
}
void display()
{
	struct node*ptr;
	ptr=head;
	if(head==NULL)
	printf("linked list empty\n");
	else
{
	while(ptr->link!=NULL)
	{
		printf("%d|%u  ------>  ",ptr->data,ptr->link);
		ptr=ptr->link;
	}
	printf("%d|%u",ptr->data,ptr->link);
}
}
int main()
{
	int choice;
	struct node*ptr;
    while(1)
    {
        printf("\nenter 1 for insert_begin\nenter 2 for insert_end\nenter 3 for insert_after\nenter 4 for insert_before\n enter 5 for insert_anyposition\n enter 6 for delete_node\n enter 7 for delete_before\n enter 8 for reverse_print\nenter 9 for reverse\nenter 10 for display\nenter 11 for exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:insert_begin();
                   break;
            case 2:insert_end();
                   break;
            case 3:insert_after();
			       break;
			case 4:insert_before();
			    break;
			case 5:insert_anyposition();
			       break; 
			case 6:delete_node();
			       break;
			case 7:delete_before();
			       break;
			case 8:reverse_print(ptr);
			       break;
			case 9:reverse();
			       break;	   	   	   	         
            case 10:display();
                   break;
            case 11:exit(0);
		    default:printf("wring choice\n");
        }
}
return 0;
} 
