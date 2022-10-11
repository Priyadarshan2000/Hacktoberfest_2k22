//  A complete working C++ program to demonstrate
//  all insertion methods on Linked List
//  Deletion and Middle
#include <bits/stdc++.h>
using namespace std;

//A linked list node
class node {
	public:
		int data;
		node* next;
};

// Function for Inserting a node  into beginning
int first(node* *head_f,int new_data)
{
	node* new_node = new node();
	new_node->data = new_data;
	new_node->next = *head_f;
	*head_f = new_node;
}


// Finction for Inserting a node after any node
int after(node* prev_node,int new_data)
{
	// to check previous node is NULL or Not
	if(prev_node == NULL){
		cout << "Previous node cannot be Null";
	}
	
	node* new_node = new node();
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

// Function for Inserting a node  at the end
int end(node* *head_e,int new_data){
	node* new_node = new node();
	node *last = *head_e;
	new_node->data = new_data;
	new_node->next = NULL;
	
	if(*head_e == NULL)
	{
		*head_e = new_node;
	}
	
	while (last->next != NULL)

		last = last->next;
    	last->next = new_node;
}

// For Printing the entire linked list
int printlist(node *n)
{
	while(n!=NULL){
		cout << n->data << " ";
		n = n->next;
	}
}

// For deleting the linked list
int deletenode(node* head,int val){
	node *temp = head;
	while(temp->next->data!=val){
		temp = temp->next;
	}
	node *todelete = temp->next;
	temp->next = temp->next->next;
	
	delete todelete;
}


// For finding the middle of linkedlist
int middle(node* head){
	node *slow = head;
	node* fast = head;
	
	while(fast!=NULL && fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
	} 
	cout << slow->data;
}

// Main Function 
int main(){
	node* head = NULL;
	node* second = NULL;
	node* third = NULL;
	
	// Making 3 Node 
	head = new node();
	second = new node ();
	third = new node ();
	
	// Inserting data in 3 Node
	head->data = 2;
	head->next = second;
	
	second->data = 3;
	second->next = third;
	
	third->data = 4;
	third->next = NULL;
	
	// Calling function for inserting at beginning. 
	first(&head,1);
	
    // Calling function for inserting at end.
	end(&third,5);
    
	// Calling function for inserting after second Node.	
	//after(second,4);
	
	// Calling function for delete given node.
	//deletenode(head,3);
	
	

   //Calling function for printing   
    cout << " The Linked List is " << endl;
	printlist(head);
	cout <<"\n\n";
	
	// Caliing function for finding the middle
	cout << "The Middle of Linked List is :" << endl;
	middle(head);
	
	return 0;
}
