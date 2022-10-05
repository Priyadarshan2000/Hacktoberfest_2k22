#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node * create(int key)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->left = NULL;
    temp->right = NULL;
    temp->data = key;
    return temp;
}

struct Node * insert(struct Node *ptr, int key)
{
    if(ptr == NULL)
        return create(key);
    if(key < ptr->data)
        ptr->left = insert(ptr->left,key);
    else
        ptr->right = insert(ptr->right,key);
    return ptr;
}

void inOrder(struct Node * ptr)
{
    if(ptr != NULL)
    {
        inOrder(ptr->left);
        printf("%d\t",ptr->data);
        inOrder(ptr->right);
    }
}

void preOrder(struct Node * ptr)
{
    if(ptr != NULL)
    {
        printf("%d\t",ptr->data);
        preOrder(ptr->left);
        preOrder(ptr->right);
    }
}

void postOrder(struct Node * ptr)
{
    if(ptr != NULL)
    {
        postOrder(ptr->left);
        postOrder(ptr->right);
        printf("%d\t",ptr->data);
    }
}
int main()
{
    int a,b;
    struct Node * root = NULL;
    do
    {
        printf("Enter 1 to add value in the BST\nEnter 2 for inorder display\nEnter 3 for postorder display\nEnter 4 for preorder display\nEnter 0 for exit");
        printf("\nEnter choice: ");
        scanf("%d",&a);
        switch(a)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d",&b);
            root = insert(root,b);
            break;
        case 2:
            printf("Inorder: ");
            inOrder(root);
            printf("\n");
            break;
        case 3:
            printf("Postorder: ");
            postOrder(root);
            printf("\n");
            break;
        case 4:
            printf("Preorder: ");
            preOrder(root);
            printf("\n");
            break;
        case 0:
            exit(0);
        default:
            printf("Invalid Input\n");
        }
    }while(1);

    return 0;
}
