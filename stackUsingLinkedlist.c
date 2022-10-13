#include<stdlib.h>
#include<stdio.h>

typedef struct linkedlist{
    int data;
    struct linkedlist *next;
} linkedlist;

linkedlist *top;


linkedlist *create_list(int size, int data){
    linkedlist *temp;
    linkedlist *p = malloc(sizeof(linkedlist));
    linkedlist *head= p;
    p->data= data;
    p->next=NULL;
    head=p;
    int data_;
    for (int i = 2; i <= size; i++)
    {
        temp=malloc(sizeof(linkedlist));
        printf("Enter data to be inserted in node %d  ", i);
        scanf("%d", &data_);
        temp->data= data_;
        temp->next=NULL;
        p->next= temp;
        p=temp;
    }  
    return head; 

}
linkedlist *adding_node(int data, linkedlist *head){
    linkedlist *temp= malloc(sizeof(linkedlist))  ;
    temp->data= data;
    temp->next=NULL;
    linkedlist *temp_= head;
    while (temp_->next!=NULL)
    {
        temp_= temp_->next;
    }
    temp_->next=temp;
    return head;
      
}

void display_list( linkedlist* head){
    linkedlist *temp;
    temp =head;
    while(temp!= NULL){
        printf("%d  ", temp->data);
        temp=temp->next;
    }
    printf("\n");
    
}

//Stack Functions

int ISEmpty(){
    if (top== NULL)
        return 1;
    return 0;

}

linkedlist push(int data){
    linkedlist *temp = (linkedlist *)malloc(sizeof(linkedlist));
    temp->data= data;
    temp->next=top;
    top= temp;
}

void pop(){
    linkedlist *temp;
    temp= top;
    top=top->next;
    free(temp);
}

int peek(){
    return top->data;
}

int main(){
    printf("Enter the size of linked list  ");
    int size;
    scanf("%d", &size);
    int data,data_;
    printf("Enter data to be inserted in node 1  ");
    scanf("%d", &data);
    linkedlist *head;
    head= create_list( size, data);
    // head=createchain(size);
    display_list( head);
    printf("Enter data to be inserted in newly created node  ");
    scanf("%d", &data_);
    head= adding_node(data_, head);
    printf("List after adding new node \n");
    display_list(head);
    
    // //STACK IMPLEMENTATION
    linkedlist *head;
    printf("Enter the number of elements you want to push in stack  :");
    int data, size, peak;
    scanf("%d", &size);
    for(int i=0; i<size; i++){
        printf("Enter the data  :");
        scanf("%d", &data);
        push(data);
    }
    display_list(top);
    
    pop();
    display_list(top);
    peak=peek();
    printf("%d", peak);

}
