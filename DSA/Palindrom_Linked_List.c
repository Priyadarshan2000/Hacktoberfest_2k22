#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100

char stack[max];
int top = -1;
int isFull(){
    if(top == max - 1)
        return 1;
    else
        return 0;
}

int isEmpty(){
    if(top == -1)
        return 1;
    else
        return 0;
}

void push(char x){
    if(isFull())
        return;
    else
        stack[++top] = x;
}


char pop(){
    if(isEmpty())
        return 0;
    else
        return stack[top--];
}

//============================= Stack Ends ============================================


typedef struct node{
    char data;
    struct node *next;
} node;

node *head = NULL;

node* setNode(node *ptr, char data){
    ptr = (node*)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

void display(node *ptr){
    if(ptr == NULL){
        printf("Nothing to Print\n");
        return ;
    }
    while(ptr->next != NULL){
        printf("%c -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("%c\n", ptr->data);
}

node* addNode(char value){
    node *temp,*ptr;
    temp = setNode(temp, value);
    push(value);
    if(head == NULL)
        head = temp;
    else{
        ptr = head;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
    return head;
}

int checkPalindrom(){
    node *ptr = head;
    while(ptr != NULL){
        if(ptr->data != pop())
            return 0;
        ptr = ptr->next;
    }
    return 1;
}


int main(void){
    int t;
    node* ptr;
    printf("Enter the number of Nodes: ");
    scanf("%d", &t);
    fflush(stdin);
    printf("Insert %d values:--\n", t);
    while(t--){
        char val;
        scanf("%c",&val);
        fflush(stdin);

        ptr = addNode(val);
    }
    printf("The values in the given linked list are:\n");
    display(head);
    if(checkPalindrom())
        printf("\nThe linked list is palindrom");
    else
        printf("\nThe linked list is not palindrom");
    return 0;
}

/*
Enter the number of Nodes: 5
Insert 5 values:--
r
a
d
a
r
The values in the given linked list are:
r -> a -> d -> a -> r

The linked list is palindrom

*/
