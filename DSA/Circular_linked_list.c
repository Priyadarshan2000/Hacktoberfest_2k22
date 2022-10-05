#include<stdio.h>
#include<stdlib.h>
int flag = 0;
typedef struct node{
    int data;
    struct node *next;
} node;

void display(node *tail){
    node *ptr;
    printf("\n");
    if(tail == NULL){
        printf("\nNothing to print!!!\n");
        return ;
    }
    ptr = tail->next;
    if(flag == 1){
        printf("[%u|%d|%u]", ptr, ptr->data, ptr->next);
        return;
    }
    do{
        printf("[%u|%d|%u]->", ptr, ptr->data, ptr->next);
        ptr = ptr->next;
    }while(ptr != tail);
    printf("[%u|%d|%u]\n", ptr, ptr->data, ptr->next);
}

node* insertBegin(node *tail, int item){
    node *ptr;
    ptr = (node*)malloc(sizeof(node));
    ptr->data = item;
    if(tail == NULL){
        ptr->next = ptr;
        tail = ptr;
    }
    else{
        ptr->next = tail->next;
        tail->next = ptr;
    }
    return tail;
}

node* insertEnd(node *tail, int item){
    node *ptr;
    ptr = (node*)malloc(sizeof(node));
    ptr->data = item;
    if(tail == NULL){
        ptr->next = ptr;
        tail = ptr;
        return tail;
    }
    else{
        ptr->next = tail->next;
        tail->next = ptr;
        tail = ptr;
        return tail;
    }
}

node* insertAfter(node *tail, int data, int item){

    if (tail == NULL)
       return NULL;
    node *temp, *ptr;
    ptr = tail->next;

    do{
        if (ptr ->data == item){
            temp = (node*)malloc(sizeof(node));
            temp->data = data;
            temp -> next = ptr -> next;
            ptr->next = temp;
            if (ptr == tail)
                tail = temp;
            return tail;
        }
        ptr = ptr -> next;
    } while (ptr != tail -> next);

    printf("\nItem not Found!!!\n");
    return tail;
}

node* deleteSpecific(node *tail, int item){
    if (tail == NULL){
        printf("\nInsert data first!!!\n");
        return tail;
    }
    node *ptr = tail->next;
    node *cptr;
    if(ptr->data == item){
        tail->next = ptr->next;
        ptr->next = NULL;
        free(ptr);
        return tail;
    }
    do{
        if(ptr->next->data == item){
            cptr = ptr->next;
            ptr->next = ptr->next->next;
            cptr->next = NULL;
            free(cptr);
            return tail;
        }
        ptr = ptr->next;
    }while(ptr->next!= tail);

    if(ptr->next == tail && ptr->next->data == item){
        cptr = ptr->next;
        ptr->next = tail->next;
        tail = ptr;
        cptr->next = NULL;
        free(cptr);
        return tail;
    }
    printf("\nItem not Found!!!\n");
    return tail;
}

int main(void){
    int num, item, key;
    node *tail = NULL;
    while(1){
        printf("\nMenu:");
        printf("\n1) insert front\n2) insert end\n3) display\n4) insert after\n5) delete specific\n6) exit\n");
        printf("\nChoose: ");
        scanf("%d", &num);
        switch(num){
            case 1: printf("\nEnter value: ");
                    scanf("%d", &item);
                    tail = insertBegin(tail, item);
                    flag++;
                    printf("\n%d inserted at begin.\n", item);
                break;
            case 2: printf("\nEnter value: ");
                    scanf("%d", &item);
                    tail = insertEnd(tail, item);
                    flag++;
                    printf("\n%d inserted at end.\n", item);
                break;

            case 3: display(tail);
                break;

            case 4: printf("\nEnter KEY: ");
                    scanf("%d", &key);
                    printf("\nEnter value: ");
                    scanf("%d", &item);
                    tail = insertAfter(tail, item, key);
                    flag++;
                    printf("\n%d inserted after %d.\n", item, key);
                break;

            case 5: printf("\nEnter value: ");
                    scanf("%d", &item);
                    tail = deleteSpecific(tail, item);
                    flag++;
                    printf("\n%d deleted.\n", item);
                break;

            case 6: exit(0);
                break;

            default: printf("Invalid Input");
        }
    }
    return 0;
}














