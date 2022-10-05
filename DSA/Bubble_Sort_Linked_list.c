#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

node *head = NULL;


node* setNode(node *ptr){
    ptr = (node*)malloc(sizeof(node));
    ptr->next = NULL;
    return ptr;
}

void display(node *ptr){
    if(ptr == NULL){
        printf("Nothing to Print\n");
        return ;
    }
    while(ptr->next != NULL){
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->data);
}


node* addNode(int value){
    node *temp,*ptr;
    temp = setNode(temp);
    temp->data = value;
     if(head == NULL){
        head = temp;
     } 
    else{
        ptr = setNode(ptr);
        ptr = head;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    } 
    return head;
}

void swap(node *a, node *b){ 
    int temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
} 

void bubbleSort(){ 
    int flag; 
    node *ptr = head; 
    node *cptr = NULL; 
  
    if (head == NULL) 
        return; 
    do{ 
        flag = 0; 
        ptr = head;   
        while (ptr->next != cptr){ 
            if (ptr->data > ptr->next->data){  
                swap(ptr, ptr->next); 
                flag = 1; 
            } 
            ptr = ptr->next; 
        } 
        cptr = ptr; 
    } while (flag);         
} 

int main(void){
    int t;
    node* ptr;
    printf("Enter the number of Nodes: ");
    scanf("%d", &t);
    int size = t;
    printf("Insert %d values:--\n", t);
    while(t--){
        int val;
        scanf("%d", &val);
        ptr = addNode(val);
    }
    printf("The original linked list are:\n");
    display(head);
    bubbleSort();
    printf("The updated linked list are:\n");
    display(head);
    return 0;
}