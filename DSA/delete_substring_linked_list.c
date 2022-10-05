#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    char data[10];
    struct node *next;
} node;

node *head = NULL;

void createNode(){
    int n;
    node *ptr, *cptr;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    if(n==0){
        return ;
    }
    ptr = (node*)malloc(sizeof(node));
    if(ptr == NULL){
        printf("Can't allocate Memory.");
        return;
    }
    printf("Enter data: ");
    scanf("%s", &ptr->data);
    head = ptr;
    for(int i = 2; i <= n; i++){
        cptr = (node*)malloc(sizeof(node));
        if(ptr == NULL){
        printf("Can't allocate Memory.");
        return;
        }
        printf("Enter data: ");
        scanf("%s", &cptr->data);
        ptr->next = cptr;
        ptr = cptr;
    }
    ptr->next = NULL;
}

void display(){
    node *ptr;
    ptr = head;
    if(ptr == NULL)
        printf("Nothing to print!!!");
    while(ptr->next != NULL){
        printf("%s -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("%s", ptr->data);
}


void deleteSpecificNode(char item[10]){
    node *ptr, *cptr;
    ptr = head;
    while(ptr->next != NULL){
        if(strstr(head->data, item) != NULL){ 
            cptr = head;
            head = head->next;
            free(cptr);
            continue;
        }
        if(strstr(ptr->next->data, item) != NULL){ 
            cptr = ptr->next;
            ptr->next = cptr->next;
            free(cptr);
            continue;
        }
        ptr = ptr->next;
    }
    
}

int main(void){
    createNode();
    deleteSpecificNode("Ar");
    display();
    return 0;
}

