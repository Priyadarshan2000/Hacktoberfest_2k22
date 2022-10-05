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

node* insbeg(node *f)
{
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("\n Data ::");
    scanf("%d",&newnode->data);

    newnode->next=f;
    f=newnode;
    return f;
}

void insbet(node *f)
{
    int i,p;
    node *c,*newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("\n Data ::");
    scanf("%d",&newnode->data);
    newnode->next=NULL;

    printf("\n Position ::");
    scanf("%d",&p);

    i=0;
    for(c=f;c!=NULL;c=c->next)
    {
        i++;
        if(i==p-1)
        {
            newnode->next=c->next;
            c->next=newnode;
            return;
        }
    }
    printf("\n Inavalid Position !!!");
    return;
}

node* insend(node *first)
{
    node *c,*newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("\nData ::");
    scanf("%d",&newnode->data);
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

node* del(node *f)
{
    int i,p;
    node *c,*t;
    if(f==NULL)
    {
        printf("\n List is Empty !!!");
        return f;
    }

    printf("\n Position ::");
    scanf("%d",&p);

    if(p==1)
    {
        t=f;
        f=f->next;
        free(t);
        return f;
    }
    i=0;
    for(c=f;c!=NULL;c=c->next)
    {
        i++;
        if(i==p-1)
        {
            t=c->next;
            c->next=t->next;
            free(t);
            return f;
        }
    }
    printf("\nInvalid Position !!!");
    return f;
}

void revprint(node *f)
{
    node *c,*x;
    x=NULL;
    while(x!=f)
    {
        c=f;
        while(c->next!=x)
        {
            c=c->next;
        }
        printf("%5d",c->data);
        x=c;
    }
}

node* revlink(node *f)
{
    node *c1,*c2,*c3;
    c1=f;
    c2=f->next;
    f->next=NULL;
    while(c2!=NULL)
    {
        c3=c2->next;
        c2->next=c1;
        c1=c2;
        c2=c3;
    }
    f=c1;
    return f;
}

main()
{
    int a,n,i;
    node *f=NULL;

    do
    {
        printf("\n1.Insert End");
        printf("\n2.Insert Beginning");
        printf("\n3.Insert Between");
        printf("\n4.Delete");
        printf("\n5.Reverse Print");
        printf("\n6.Reverse Link");
        printf("\n7.Exit");
        printf("\nEnter Your Choice ::");
        scanf("%d",&n);

        switch(n)
        {
        case 1:
            f=insend(f);
            list(f);
            break;
        case 2:
            f=insbeg(f);
            list(f);
            break;
        case 3:
            insbet(f);
            list(f);
            break;
        case 4:
            f=del(f);
            list(f);
            break;
        case 5:
            revprint(f);
            break;
        case 6:
            f=revlink(f);
            /*  c1=f;
                c2=f->next;
                f->next=NULL;
                f=r_revlink(f,c1,c2);*/ //Using Recursion
            list(f);
            break;
        }
    }
    while(n!=7);
}
