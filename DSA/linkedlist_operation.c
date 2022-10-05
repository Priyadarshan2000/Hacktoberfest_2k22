#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
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
    scanf("%d", &ptr->data);
    head = ptr;
    int i;
    for( i = 2; i <= n; i++){
        cptr = (node*)malloc(sizeof(node));
        if(ptr == NULL){
        printf("Can't allocate Memory.");
        return;
        }
        printf("Enter data: ");
        scanf("%d", &cptr->data);
        ptr->next = cptr;
        ptr = cptr;
    }
    ptr->next = NULL;
}

void display(){
    node *ptr;
    ptr = head;
    while(ptr->next != NULL){
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d", ptr->data);
}

void insertBegin(){
    node *ptr;
    ptr = (node*)malloc(sizeof(node));
    if(ptr == NULL){
        printf("Can't allocate Memory.");
        return;
    }
    printf("Enter Data: ");
    scanf("%d", &ptr->data);
    if(head == NULL){
        head = ptr;
        ptr->next = NULL;
    }
    else{
        ptr->next = head;
        head = ptr;
    }
    printf("\nData inserted!!!\n");
}

void insertEnd(){
    node *ptr, *cptr;
    cptr = (node*)malloc(sizeof(node));
    printf("Enter Data: ");
    scanf("%d", &cptr->data);

    ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = cptr;
    cptr->next = NULL;
    printf("\nData inserted!!!\n");
}

void insertAfter(int item){
    node *ptr, *cptr;
    cptr = (node*)malloc(sizeof(node));
    printf("Enter Data: ");
    scanf("%d", &cptr->data);

    ptr = head;
    while(ptr != NULL){
        if(ptr->data == item){
            cptr->next = ptr->next;
            ptr->next = cptr;
            printf("\nData inserted!!!\n");
            return ;
        }
        else{
            ptr = ptr->next;
        }
    }
    printf("\nItem not Found!!!\n");
}

void insertAtPos(){
    node *ptr, *cptr;
    int count = 0, pos;

    printf("Enter the pos: ");
    scanf("%d", &pos);

    cptr = (node*)malloc(sizeof(node));
    printf("Enter Data: ");
    scanf("%d", &cptr->data);

    if(pos == 1){
        cptr->next = head;
        head = cptr;
    }
    ptr = head;
    int i;
    for( i = 1; i < pos - 1; i++){
        ptr = ptr->next;
    }
    if(ptr == NULL){
        printf("There are < %d elements", pos);
    }
    else{
        cptr->next = ptr->next;
        ptr->next = cptr;
    }
    printf("\nData inserted!!!\n");
}


void insertBefore(int item){
    node *ptr, *cptr;
    cptr = (node*)malloc(sizeof(node));
    printf("Enter Data: ");
    scanf("%d", &cptr->data);

    ptr = head;
    while(ptr->next != NULL){
        if(ptr->next->data == item){
            cptr->next = ptr->next;
            ptr->next = cptr;
            printf("\nData inserted!!!\n");
            return ;
        }
        else{
            ptr = ptr->next;
        }
    }
    printf("\nItem not Found!!!\n");
}


void deleteBegin(){
    node *ptr;
    if(head == NULL){
        printf("List Empty");
        return ;
    }

    ptr = head;
    head = head->next;
    free(ptr);
    printf("Element Deleted");
}


void deleteEnd(){
    node *ptr, *cptr;
    if(head == NULL){
        printf("List Empty");
        return ;
    }

    ptr = head;
    while(ptr->next != NULL){
        cptr = ptr;
        ptr = ptr->next;
    }
    cptr->next = NULL;
    free(ptr);
    printf("Element Deleted");
}


void deleteSpecificNode(int item){
    node *ptr, *cptr;
    ptr = head;
    while(ptr->next != NULL){

        if(head->data == item){
            cptr = head;
            head = head->next;
            free(cptr);
            printf("Element Deleted");
            return ;
        }

        if(ptr->next->data == item){
            cptr = ptr->next;
            ptr->next = cptr->next;
            free(cptr);
            printf("Element Deleted");
            return ;
        }
        ptr = ptr->next;
    }
    printf("Element Not found");
}



void reverse(){
    node *current, *prev, *next;
    current = head;
    prev = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}


int main(void){
    int num, item;
    createNode();
    while(1){
        printf("\nMenu:");
        printf("\n1) insert front\n2) insert end\n3) insert after\n4) insert before\n5) insert at pos\n6) display\n7) delete begin\n8) delete end\n9) delete specific\n10) reverse\n11) exit\n");
        printf("\nChoose: ");
        scanf("%d", &num);
        switch(num){
            case 1: insertBegin();
                break;
            case 2: insertEnd();
                break;

            case 3: printf("Enter the item: ");
                    scanf("%d", &item);
                    insertAfter(item);
                break;

            case 4: printf("Enter the item: ");
                    scanf("%d", &item);
                    insertBefore(item);
                break;
            case 5: insertAtPos();
                break;

            case 6: display();
                break;

            case 7: deleteBegin();
                break;

            case 8: deleteEnd();
                break;

            case 9:  printf("Enter the item: ");
                    scanf("%d", &item);
                    deleteSpecificNode(item);
                break;

            case 10: reverse();
                     printf("Linked List Reversed");
                break;

            case 11: exit(0);
                break;

            default: printf("Invalid Input");
        }
    }
    return 0;
}
