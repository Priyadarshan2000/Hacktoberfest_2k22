#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * link;
};

struct Node * insert(struct Node * tail, int item)
{
    struct Node *ptr;
     ptr = (struct Node *)calloc(1,sizeof(struct Node));
     ptr->data = item;
     if(tail == NULL)
     {
         ptr->link = ptr;
         tail = ptr;
         return tail;
     }
     else
     {
         ptr->link = tail->link;
         tail->link = ptr;
         tail = ptr;
         return tail;
     }
}

struct Node * split(struct Node *tail, struct node *tail1, int count)
{
    int a = count;
    struct Node *ptr = tail;
    int temp;

    if(a%2 != 0)
    {
        printf("Splitting not possible\n");
        return tail1;
    }
    else
    {
        while(a/2 > 0)
        {
            ptr = ptr->link;
            a -= 2;
        }
        printf("%d\t",tail);

        tail1 = ptr;
        temp = ptr->link;
        ptr->link = tail->link;
        tail->link = temp;

        printf("%d\n",tail1);
    }
    return tail1;
}

void Display(struct Node * tail)
{
    if(tail == NULL)
    {
        printf("Nothing to display\n");
        return;
    }
    struct Node *ptr;
    ptr = tail->link;
    do
    {
        printf("%u,",ptr);
        printf("%d->",ptr->data);
        printf("%u\t",ptr->link);
        ptr = ptr->link;
    }while(ptr != tail->link);
    printf("\n");
}

int main()
{
    struct Node *tail = NULL;
    struct node *tail1 = NULL;
    int a,b,count = 0;
    do
    {
        printf("1) Enter 1 for insert element\n2) Enter 2 for splitting\n3) Enter 3 for display\n4) Enter 0 for exit\n");
        printf("Enter your choice: ");
        scanf("%d",&a);
        switch(a)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d",&b);
            tail = insert(tail,b);
            count++;
            break;
        case 2:
            tail1 = split(tail,tail1,count);
            break;
        case 3:
            Display(tail);
            Display(tail1);
            break;
        case 0:
            exit(0);
        default:
            printf("Invalid entry.\n");
        }
    }while(1);

    return 0;
}
