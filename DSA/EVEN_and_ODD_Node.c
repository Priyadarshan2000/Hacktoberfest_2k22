#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

node *head = NULL;
node *oddhead = NULL;
node *evenhead = NULL;

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


void separateOddEven(){
    node *ptr = head, *temp, *cptr;
    while(ptr != NULL){
        if(ptr->data % 2 == 1){
            if(oddhead == NULL){
                oddhead = setNode(oddhead);
                oddhead->data = ptr->data;
            }
            else{
                temp = setNode(temp);
                temp->data = ptr->data;
                cptr = oddhead;
                while(cptr->next != NULL)
                    cptr = cptr->next;
                cptr->next = temp;
            }
        }
        else{
            if(evenhead == NULL){
                evenhead = setNode(evenhead);
                evenhead->data = ptr->data;
            }
            else{
                temp = setNode(temp);
                temp->data = ptr->data;
                cptr = evenhead;
                while(cptr->next != NULL)
                    cptr = cptr->next;
                cptr->next = temp;
            }
        }
        ptr = ptr->next;
    }
}


int main(void){
    int t;
    node* ptr;
    printf("Enter the number of Nodes: ");
    scanf("%d", &t);
    printf("Insert %d values:--\n", t);
    while(t--){
        int val;
        scanf("%d", &val);
        ptr = addNode(val);
    }
    separateOddEven();
    printf("The values in the given linked list are:\n");
    display(head);
    printf("The odd elements are:\n");
    display(oddhead);
    printf("The even elements are:\n");
    display(evenhead);
    return 0;
}