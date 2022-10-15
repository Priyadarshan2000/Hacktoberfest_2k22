#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};
typedef struct tree tree;

void insert(tree *root,tree *p,int v)
{
    tree *cur;
    if(root!=NULL)
    {
        if(v>root->data)
        {
            p=root;
            root=root->right;
            insert(root,p,v);
        }
        else
        {
            p=root;
            root=root->left;
            insert(root,p,v);
        }
    }
    else
    {
        cur=(tree*)malloc(sizeof(tree));
        cur->data=v;
        cur->left=NULL;
        cur->right=NULL;
        if(v>p->data)
            p->right=cur;
        else
            p->left=cur;
    }
}

void inorder(tree *root)
{
     if(root!=NULL)
     {
          inorder(root->left);
          printf("%5d",root->data);
          inorder(root->right);
     }
}

int height(tree* node)
{
    if(node==NULL)
        return 0;
    else
    {
        /*Compute the height or each subtree*/
        int lheight=height(node->left);
        int rheight=height(node->right);

        /*use the larger one*/
        if(lheight>rheight)
            return(lheight+1);
        else
            return(rheight+1);
    }
}

void printGivenLevel(tree *root,int level)
{
    if(root==NULL)
        return;
    if(level==1)
        printf("%5d",root->data);
    else if(level>1)
    {
        printGivenLevel(root->left,level-1);
        printGivenLevel(root->right,level-1);
    }
}

void printLevelOrder(tree *root)
{
    int h=height(root);
    int i;
    for(i=1;i<=h;i++)
        printGivenLevel(root,i);
}

tree *find_small(tree *root)
{
    if(root==NULL || root->left==NULL)
        return(root);
    else
        return(find_small(root->left));
}

tree *find_large(tree *root)
{
    if(root==NULL || root->right==NULL)
        return(root);
    else
        return(find_large(root->right));
}

int count_nodes(tree *root)
{
    if(root==NULL)
        return(0);
    else
        return(count_nodes(root->left) + count_nodes(root->right)+1);
}

int count_leaf_nodes(tree *root)
{
    if(root==NULL)
        return(0);
    else if(root->left==NULL && root->right==NULL)
        return(1);
    else
        return(count_leaf_nodes(root->left) + count_leaf_nodes(root->right));
}

int count_nonleaf_nodes(tree *root)
{
    if((root==NULL) || (root->left==NULL) && (root->right==NULL))
        return(0);
    else
        return(count_nonleaf_nodes(root->left) + count_nonleaf_nodes(root->right)+1);
}

void main()
{
    int c,m,v,h,l,c1,c2,c3;
    tree *root,*a,*b;
    root=(tree*)malloc(sizeof(tree));
    printf("\nEnter The Data ::");
    scanf("%d",&root->data);
    root->left=NULL;
    root->right=NULL;

    do
    {
        printf("\n1. Insert");
        printf("\n2. In-Order");
        printf("\n3. Height");
        printf("\n4. Level Order");
        printf("\n5. Level");
        printf("\n6. Find Small");
        printf("\n7. Find Large");
        printf("\n8. Count Nodes");
        printf("\n9. Count Leaf Nodes");
        printf("\n10.Count Nonleaf Nodes");
        printf("\n11.Exit");
        printf("\n");
        printf("\nEnter Your Choice ::");
        scanf("%d",&c);

        switch(c)
        {
        case 1:
            printf("\nValue ::");
            scanf("%d",&v);
            insert(root,NULL,v);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            h=height(root);
            printf("Height ::%d",h);
            break;
        case 4:
            printLevelOrder(root);
            break;
        case 5:
            printGivenLevel(root,l);
            break;
        case 6:
            a=find_small(root);
            printf("\n %d",a->data);
            break;
        case 7:
            b=find_large(root);
            printf("\n %d",b->data);
            break;
        case 8:
            c1=count_nodes(root);
            printf("Nodes ::%d",c1);
            break;
        case 9:
            c2=count_leaf_nodes(root);
            printf("Leaf Nodes ::%d",c2);
            break;
        case 10:
            c3=count_nonleaf_nodes(root);
            printf("Non Leaf Nodes ::%d",c3);
            break;
        }
    }while(c!=11);
}
