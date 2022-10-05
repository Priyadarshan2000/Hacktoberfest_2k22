#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

void list(node *first)
{
    node *c;
    printf("\n");
    for(c=first;c!=NULL;c=c->next)
    {
        printf("%5d",c->data);
    }
}

node* insend(node *first,int d)
{
    node *c,*newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=d;
    newnode->next=NULL;

    if(first==NULL)
    {
        first=newnode;
        return first;
    }
    c=first;
    while(c->next!=NULL)
    {
        c=c->next;
    }
    c->next=newnode;
    return first;
}

node* intersection_list(node *f1,node *f2)
{
     node *c,*d;
     node *f3=NULL;

     for(c=f1;c!=NULL;c=c->next)
     {
        for(d=f2;d!=NULL;d=d->next)
        {
            if(c->data==d->data)
            {
                f3=insend(f3,c->data);
                break;
            }
        }
     }
     return f3;
}

main()
{
    int f1,f2,i,v;
    node *s=NULL;
    node *e=NULL;
    node *f3=NULL;
    printf("\nIn First Linked List How Many Nodes ?");
    scanf("%d",&f1);
    for(i=1;i<=f1;i++)
    {
          printf("Enter Data ::");
          scanf("%d",&v);
          s=insend(s,v);
    }


    printf("\nIn Second Linked List How Many Nodes ?");
    scanf("%d",&f2);
    for(i=1;i<=f2;i++)
    {
          printf("Enter Data ::");
          scanf("%d",&v);
          e=insend(e,v);
    }

    list(s);

    list(e);
    f3=intersection_list(s,e);
    printf("\n Intersection of the Linked List ::");
    list(f3);
}
