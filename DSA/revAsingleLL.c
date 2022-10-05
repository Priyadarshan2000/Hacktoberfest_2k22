#include<stdio.h>
#include<stdlib.h>

struct Node
{
    char data;
    struct Node * link;
};

struct Node * head = NULL;

void Create()
{
    int n;
    struct Node *ptr, *Cptr;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    if(n == 0)
        return;
    ptr = (struct Node *)calloc(1,sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d",&ptr->data);
    head = ptr;

    for(int i = 2; i <= n; i++)
    {
        Cptr = (struct Node *)calloc(1,sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d",&Cptr->data);
        ptr->link = Cptr;
        ptr = Cptr;
    }
    ptr->link = NULL;
}
//loop takes n iterations so has O(n) time.
void Display()
{
    struct Node * ptr;
    ptr = head;
    while(ptr->link != NULL)
    {
        printf("%d->",ptr->data);
        ptr = ptr->link;
    }
    printf("%d",ptr->data);
    printf("\n\n");
}
//recursion also takes O(n) time as well as space complexity.
//As recursion takes place in system stack it takes more space than looping
void recursive_display(struct Node *ptr)
{
    if(ptr != NULL)
    {
        printf("%d ",ptr->data);
        recursive_display(ptr->link);
    }
}

void recursive_rev_display(struct Node *ptr)
{
    if(ptr != NULL)
    {
        recursive_rev_display(ptr->link);
        printf("%d ",ptr->data);
    }
}

void reverse()
{
    struct Node *current, *next, *prev;
    current = head;
    prev = NULL;
    while(current != NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main()
{
    Create();
    printf("The main list: ");
    Display();
    recursive_display(head);
    printf("\n");
    recursive_rev_display(head);
    printf("\n");
    reverse();
    printf("The reversed list: ");
    Display();
    return 0;
}
