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


node* insert(node *tail, int item){
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

node* split_LL(node* tail, int half){
    node *temp,*t_tail; 
    node *ptr = tail;
    while(half--)
        ptr = ptr->next;
    temp = ptr->next;
    ptr->next = tail->next;
    t_tail = ptr;
    tail->next = temp;
    return t_tail;
}

int main(void){
    node *LL1 = NULL;
    node *LL2 = NULL;
    int count, i = 0;
    printf("Enter the number of Nodes: ");
    scanf("%d", &count);
    if(count%2)
        printf("Splitting is not possible for odd Nodes!!!");
    else{
        while(i++ < count){
            int item;
            printf("Enter the value: ");
            scanf("%d", &item);
            LL1 = insert(LL1, item);
        }
        LL2 = split_LL(LL1, count/2);
        printf("\nFirst Linked List:-\n");
        display(LL2);
        printf("\nSecond Linked List:-\n");
        display(LL1);
    }
    return 0;
}

/*
Output - 1
------------
Enter the number of Nodes: 6
Enter the value: 7
Enter the value: 1
Enter the value: 6
Enter the value: 7
Enter the value: 8
Enter the value: 9

First Linked List:-

[12202784|7|12202800]->[12202800|1|12202816]->[12202816|6|12202784]

Second Linked List:-

[12202832|7|12202848]->[12202848|8|12202864]->[12202864|9|12202832]

Output - 2
------------
Enter the number of Nodes: 5
Splitting is not possible for odd Nodes!!!


Output - 3
------------
Enter the number of Nodes: 4
Enter the value: 78
Enter the value: 87
Enter the value: 12
Enter the value: 21

First Linked List:-

[6632224|78|6632240]->[6632240|87|6632224]

Second Linked List:-

[6632256|12|6632272]->[6632272|21|6632256]

*/












