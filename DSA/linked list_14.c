#include<stdio.h>
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

node* ins_after(node *f)
{
     int m;
     node *c,*cur;
     cur=(node*)malloc(sizeof(node));
     printf("\n Data ::");
     scanf("%d",&cur->data);
     cur->next=NULL;
     if(f==NULL)
     {
          f=cur;
          return f;
     }
     printf("\n After Which No.?");
     scanf("%d",&m);
     for(c=f;c!=NULL;c=c->next)
     {
          if(c->data==m)
          {
               cur->next=c->next;
               c->next=cur;
               break;
          }
     }
     return f;
}

node *ins_before(node *f)
{
     int m;
     node *c,*cur,*p;
     cur=(node*)malloc(sizeof(node));
     printf("\n Data ::");
     scanf("%d",&cur->data);
     cur->next=NULL;
     if(f==NULL)
     {
          f=cur;
          return f;
     }
     printf("\n Before Which No. ?");
     scanf("%d",&m);
     c=f;
     p=NULL;
     while(c!=NULL)
     {
          if(c->data==m)
          {
               cur->next=c;
               if(p!=NULL)
                    p->next=cur;
               else
                    f=cur;
               break;
          }
          p=c;
          c=c->next;
     }
     return f;
}

node* del_duplicate(node *f)
{
    int m;
    node *p,*t,*c;
    if(f==NULL)
    {
         printf("\n!!! Empty !!!");
         return NULL;
    }
    printf("\nEnter the number u want to delete ::");
    scanf("%d",&m);
    p=NULL;
    c=f;
    while(c!=NULL)
    {
          if(c->data==m)
          {
               if(p==NULL)
               {
                    t=c;
                    c=c->next;
                    f=c;
                    free(t);
               }
               else
               {
                    p->next=c->next;
                    free(c);
                    c=p->next;
               }
               continue;
          }
          p=c;
          c=c->next;
     }
     return f;
}

main()
{
    int a,n,i,p;
    node *f=NULL;

    do
    {
        printf("\n1.Insert After");
        printf("\n2.Insert Before");
        printf("\n3.Delete Duplicate");
        printf("\n4.List");
        printf("\n5.Exit");
        printf("\nEnter Your Choice ::");
        scanf("%d",&n);

        switch(n)
        {
        case 1:
            f=ins_after(f);
            list(f);
            break;
        case 2:
            f=ins_before(f);
            list(f);
            break;
        case 3:
            f=del_duplicate(f);
            list(f);
            break;
        case 4:
            list(f);
            break;
        }
    }
    while(n!=5);
}
