#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *prev, *next;
}node;

void insertBegin(node **head){
    node *temp;
    temp = (node*)malloc(sizeof(node));
    printf("\nEnter data: ");
    scanf("%d", &temp->data);
    temp->next = *head;
    temp->prev = NULL;
    if(*head != NULL)
        (*head)->prev = temp;
    *head = temp;
}

void insertEnd(node **head){
    node *ptr, *temp;
    ptr = *head;

    temp = (node*)malloc(sizeof(node));
    printf("\nEnter data: ");
    scanf("%d", &temp->data);
    temp->next = *head;
    temp->prev = NULL;

    if(*head == NULL){
        insertBegin(head);
        return;
    }

    while(ptr->next != NULL)
        ptr = ptr->next;

    temp->prev = ptr;
    ptr->next = temp;
    temp->next = NULL;
}


void insertAfter(node **head, int item){
    node *temp, *ptr;
    temp = (node*)malloc(sizeof(node));
    printf("\nEnter data: ");
    scanf("%d", &temp->data);
    temp->next = *head;
    temp->prev = NULL;
    ptr = *head;
    while(ptr->next!=NULL){
        if(ptr->data == item){
            temp->prev = ptr;
            temp->next = ptr->next;
            ptr->next->prev = temp;
            ptr->next = temp;
            printf("\ninserted after %d.\n", item);
            return;
        }
        ptr = ptr->next;
    }
    if(ptr->data == item){
        while(ptr->next != NULL)
            ptr = ptr->next;
        temp->prev = ptr;
        ptr->next = temp;
        temp->next = NULL;
        printf("\ninserted after %d.\n", item);
        return;
    }
    printf("Element not found!!!");
}

void fwd_Display(node **head){
    node *ptr;
    ptr = *head;
    if(ptr == NULL){
        printf("\nNothing to print\n");
        return;
    }
    printf("\nLinked List in forward order:\n");
    while(ptr->next!=NULL){
        printf("[%u|%u|%d|%u]<=>", ptr, ptr->prev, ptr->data, ptr->next);
        ptr = ptr->next;
    }
    printf("[%u|%u|%d|%u]", ptr, ptr->prev, ptr->data, ptr->next);
}

void bwd_Display(node **head){
    node *ptr;
    ptr = *head;
    if(ptr == NULL){
        printf("\nNothing to print\n");
        return;
    }
    while(ptr->next!=NULL)
        ptr = ptr->next;
    printf("\nLinked List in backward order:\n");
    while(ptr->prev!=NULL){
        printf("[%u|%u|%d|%u]<=>", ptr, ptr->next, ptr->data, ptr->prev);
        ptr = ptr->prev;
    }
    printf("[%u|%u|%d|%u]", ptr, ptr->next, ptr->data, ptr->prev);
}


void reverse(node** head){
    node *temp, *current;
    temp = NULL;
    current = *head;
    while(current != NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    *head = temp->prev;
    printf("\nLinked list is reversed!!!\n");
}

void deleteSpecific(node **head){
    node *ptr = *head;
    int item;
    printf("\nEnter the key: ");
    scanf("%d", &item);
    if((*head)->data == item){
        (*head)->next->prev = NULL;
        *head = (*head)->next;
        ptr->next = NULL;
        free(ptr);
        printf("\nElelment Deleted!!!\n");
        return;
    }
    while(ptr->next != NULL){
        if(ptr->data == item){
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            ptr->prev = NULL;
            ptr->next = NULL;
            free(ptr);
            printf("\nElelment Deleted!!!\n");
            return;
        }
        ptr = ptr->next;
    }
    if(ptr->data == item){
        ptr->prev->next = NULL;
        ptr->prev = NULL;
        free(ptr);
        printf("\nElelment Deleted!!!\n");
        return;
    }
    printf("\nElement not found!!!\n");
}




int main(void){
    struct node *head = NULL;
    int num, key;
    while(1){
        printf("\nMenu:");
        printf("\n1) insert Begin\n2) insert end\n3) insert after\n4) display forward\n5) display backward\n6) exit\n7) reverse\n8) delete\n");
        printf("\nChoose: ");
        scanf("%d", &num);
        switch(num){
            case 1: insertBegin(&head);
                    printf("\ninserted at begin.\n");
                break;
            case 2: insertEnd(&head);
                    printf("\ninserted at end.\n");
                break;

            case 3: printf("\nEnter KEY: ");
                    scanf("%d", &key);
                    insertAfter(&head, key);
                break;

            case 4: fwd_Display(&head);
                break;

            case 5: bwd_Display(&head);
                break;

            case 6: exit(0);
                break;

            case 7: reverse(&head);
                break;

            case 8: deleteSpecific(&head);
                break;

            default: printf("Invalid Input");
        }
    }
    return 0;
}
