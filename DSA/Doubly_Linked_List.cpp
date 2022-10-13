#include <iostream>
using namespace std;
void getch();
void clrscr();
template <class T>
class Node
{
    public:
        T info;
        Node *prev;
        Node *next;
};

template <class T>
class DoublyLinkedList
{
    protected:
        Node<T> *head, *tail;
    public:
  // Constructor
  DoublyLinkedList()
  {
    head = tail = NULL;
  }

  // Destructor
  ~DoublyLinkedList()
  {
    if (this->isEmpty())
      return;
    Node<T> *ptr;
    for (; !isEmpty();)
    {
      ptr = head->next;
      delete head;
      head = ptr;
    }
    head = tail = ptr;
    return;
  }

  // Checks if the list is empty - O(1)
  bool isEmpty()
  {
    return (head == NULL || tail == NULL);
  }

  // Inserts a node at the beginning - O(1)
  void insertFront(T info)
  {
    Node<T> *temp = new Node<T>();
    temp->info = info;
    temp->next = head;
    temp->prev = NULL;
    if (this->isEmpty())
      tail = temp;
    else
      head->prev = temp;
    head = temp;
    cout << "Inserted " << info << " at front...";
    this->display();
    return;
  }

  // Inserts a node at a specified location - O(n)
  void insertAtLoc(int loc, T info)
  {
    if (loc == 1)
    {
      this->insertFront(info);
      return;
    }
    Node<T> *temp = head;
    for (int i = 1; temp != NULL && i < loc - 1; i++)
      temp = temp->next;
    if (temp == NULL)
    {
      cout << "Invalid location...\n";
      return;
    }
    if (temp == tail)
    {
      this->insertBack(info);
      return;
    }
    Node<T> *node = new Node<T>();
    node->info = info;
    node->next = temp->next;
    node->prev = temp;
    temp->next->prev = node;
    temp->next = node;
    cout << "Inserted node " << info << " at location " << loc << "...";
    this->display();
    return;
  }

  // Inserts a node at the end - O(1)
  void insertBack(T info)
  {
    Node<T> *temp = new Node<T>();
    temp->info = info;
    temp->next = NULL;
    temp->prev = tail;
    if (this->isEmpty())
      head = tail = temp;
    else
      tail->next = temp;
    tail = temp;
    cout << "Inserted " << info << " at back...";
    this->display();
    return;
  }

  // Removes a node from the beginning - O(1)
  void deleteFront()
  {
    if (this->isEmpty())
    {
      cout << "\nList is empty...\n";
      return;
    }
    Node<T> *temp = head;
    head = temp->next;
    if (this->isEmpty())
      tail = NULL;
    else
      head->prev = NULL;
    delete temp;
    cout << "\nDeleted node at front...";
    this->display();
    return;
  }

  // Removes a node at a specified location - O(n)
  void deleteAtLoc(int loc)
  {
    if (this->isEmpty())
    {
      cout << "\nList is empty...\n";
      return;
    }
    if (loc == 1)
    {
      this->deleteFront();
      return;
    }
    Node<T> *node, *temp = head;
    for (int i = 1; temp != NULL && i < loc - 1; i++)
      temp = temp->next;
    if (temp == NULL || temp->next == NULL)
    {
      cout << "Invalid location...\n";
      return;
    }
    if (temp->next == tail)
    {
      this->deleteBack();
      return;
    }
    node = temp->next->next;
    node->prev = temp;
    delete temp->next;
    temp->next = node;
    cout << "Deleted node "
         << "at location " << loc << "...";
    this->display();
    return;
  }

  // Removes a node at the end - O(1)
  void deleteBack()
  {
    if (this->isEmpty())
    {
      cout << "\nList is empty...\n";
      return;
    }
    Node<T> *temp = tail;
    tail = temp->prev;
    if (this->isEmpty())
      head = NULL;
    else
      tail->next = NULL;
    delete temp;
    cout << "\nDeleted node at back...";
    this->display();
    return;
  }

  // Reverses the linked list - O(n)
  void reverse()
  {
    if (this->isEmpty())
    {
      cout << "\nList is empty...\n";
      return;
    }
    Node<T> *temp = head,
            *temp1 = NULL;
    tail = temp;
    while (temp != NULL)
    {
      temp1 = temp->prev;
      temp->prev = temp->next;
      temp->next = temp1;
      temp = temp->prev;
    }
    if (temp1 != NULL)
      head = temp1->prev;
    cout << "\nList reversed...";
    this->display();
    return;
  }

  // Concatenates two lists - O(n)
  void concat(DoublyLinkedList<T> &list)
  {
    if (!list.isEmpty() && !this->isEmpty())
    {
      Node<T> *node,
          *temp = tail,
          *temp1 = list.head;
      while (temp1 != NULL)
      {
        node = new Node<T>();
        node->info = temp1->info;
        node->next = NULL;
        node->prev = temp;
        temp->next = node;
        temp = temp->next;
        temp1 = temp1->next;
      }
      tail = node;
      cout << "Concatenated two lists...\n";
      this->display();
    }
    else
      cout << "\nOne of the lists is empty...\n";
    return;
  }

  // Overloads the + operator - O(n)
  void operator+(DoublyLinkedList<T> &list)
  {
    this->concat(list);
    return;
  }

  // Searches for an element - O(n)
  Node<T> *search(T ele)
  {
    if (this->isEmpty())
      return nullptr;
    Node<T> *temp = head;
    while (temp != NULL)
    {
      if (temp->info == ele)
        return temp;
      temp = temp->next;
    }
    return nullptr;
  }

  // Calculates the number of nodes - O(n)
  int count()
  {
    if (this->isEmpty())
    {
      cout << "\nList is empty...\n";
      return -1;
    }
    int count = 0;
    Node<T> *temp;
    for (temp = head; temp != NULL;
         temp = temp->next, count++)
      ;
    return count;
  }

  // Traverses the list and prints all nodes - O(n)
  void display()
  {
    if (this->isEmpty())
    {
      cout << "\nList is empty...\n";
      return;
    }
    Node<T> *temp = head;
    cout << "\nList: ";
    while (temp->next != NULL)
    {
      cout << temp->info << " -> ";
      temp = temp->next;
    }
    cout << temp->info << endl;
    return;
  }
};

int main(void)
{
  int info, ele, choice, loc, count;
  DoublyLinkedList<int> list, list2;
  do
  {
    cout << "\tDoubly Linked List\n"
         << "===================================\n"
         << "  (1)  Search      (2)  InsertFront\n"
         << "  (3)  InsertBack  (4)  InsertAtLoc\n"
         << "  (5)  DeleteFront (6)  DeleteBack\n"
         << "  (7)  DeleteAtLoc (8)  Display\n"
         << "  (9)  Count       (10) Reverse\n"
         << "  (11) Concat      (0)  Exit\n\n";
    cout << "Enter Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "\nEnter Search Element: ";
      cin >> ele;
      if (list.search(ele) != nullptr)
        cout << "Element " << ele << " found...\n";
      else
        cout << "Element not found or List is Empty...\n";
      break;
    case 2:
      cout << "\nEnter Element: ";
      cin >> info;
      list.insertFront(info);
      break;
    case 3:
      cout << "\nEnter Element: ";
      cin >> info;
      list.insertBack(info);
      break;
    case 4:
      cout << "\nEnter Location: ";
      cin >> loc;
      cout << "Enter Element: ";
      cin >> info;
      list.insertAtLoc(loc, info);
      break;
    case 5:
      list.deleteFront();
      break;
    case 6:
      list.deleteBack();
      break;
    case 7:
      cout << "\nEnter Location: ";
      cin >> loc;
      list.deleteAtLoc(loc);
      break;
    case 8:
      list.display();
      break;
    case 9:
      count = list.count();
      if (count != -1)
        cout << "\nNumber of Nodes: " << count << endl;
      break;
    case 10:
      list.reverse();
      break;
    case 11:
      if (!list2.isEmpty())
      {
        cout << "\nList B:";
        list2.display();
      }
      cout << "\nNumber of Nodes to add in List B: ";
      cin >> count;
      if (count)
      {
        cout << "Enter Elements to List B: ";
        for (int i = 0; i < count; i++)
        {
          cin >> info;
          list2.insertBack(info);
        }
        list + list2;
      }
      break;
    case 0:
    default:
      break;
    }
    getch();
    clrscr();
  } while (choice != 0);
  return 0;
}

void getch()
{
  cout << "\nPress any key to continue...";
  cin.ignore();
  cin.get();
  return;
}

void clrscr()
{
    #ifdef _WIN32
      system("cls");
    #elif __unix__
      system("clear");
    #endif
      return;
}

