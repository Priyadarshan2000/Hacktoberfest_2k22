#include <iostream>
using namespace std;
struct node {
   int data;
   struct node *next;
};
node *front=NULL, *rear=NULL, *newnode, *temp;
void insert() {
   int val;
   cout<<"Insert the element in queue : "<<endl;
   cin>>val;
   newnode = new node;
   newnode->data=val;
   newnode->next=NULL;
   if (front == NULL) {
      front = rear=newnode;
   } else {
      rear->next=newnode;
      rear=newnode;
   }
}
void del(){
   temp = front;
   if (front == NULL) {
      cout<<"Underflow"<<endl;
      return;
   }
   else{
    front=front->next;
    delete temp;
    temp=NULL;
   }
}
void display() {
   temp = front;
   if (front == NULL) {
      cout<<"Queue is empty"<<endl;
      return;
   }
   cout<<"Queue elements are: ";
   while (temp != NULL) {
      cout<<temp->data<<" ";
      temp = temp->next;
   }
   cout<<endl;
}
int main() {
   int ch;
   cout<<"1) Insert element to queue"<<endl;
   cout<<"2) Delete element from queue"<<endl;
   cout<<"3) Display all the elements of queue"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter your choice : "<<endl;
      cin>>ch;
      switch (ch) {
         case 1: insert();
         break;
         case 2: del();
         break;
         case 3: display();
         break;
         case 4: cout<<"Exit"<<endl;
         break;
         default: cout<<"Invalid choice"<<endl;
      }
   } while(ch!=4);
   return 0;
}
