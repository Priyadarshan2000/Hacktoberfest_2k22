#include <iostream>
using namespace std;
void getch();
void clrscr();
template <class T>
class Node
{
    public:
        T info;
        Node *ptr;
};

template <class T>
class SinglyLinkedList
{
    protected:
        Node<T> *head, *tail;
    public:
  // Constructor
  SinglyLinkedList()
  {
    head = tail = NULL;
  }
  // Destructor
  ~SinglyLinkedList()
  {
    if (this->isEmpty())
        return;
    Node<T> *ptr, *temp = head;
    while (temp != NULL)
    {
      ptr = temp->ptr;
      delete temp;
      temp = ptr;
    }
    head = tail = NULL;
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
    temp->ptr = head;
    if (this->isEmpty())
      tail = temp;
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
      temp = temp->ptr;
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
    node->ptr = temp->ptr;
    temp->ptr = node;
    cout << "Inserted node " << info << " at location " << loc << "...";
    this->display();
    return;
  }

  // Inserts a node at the end - O(1)
  void insertBack(T info)
  {
    Node<T> *temp = new Node<T>();
    temp->info = info;
    temp->ptr = NULL;
    if (this->isEmpty())
      head = tail = temp;
    else
      tail->ptr = temp;
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
    head = temp->ptr;
    delete temp;
    if (this->isEmpty())
      tail = NULL;
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
      temp = temp->ptr;
    if (temp == NULL || temp->ptr == NULL)
    {
      cout << "Invalid location...\n";
      return;
    }
    if (temp == tail)
    {
      this->deleteBack();
      return;
    }
    node = temp->ptr->ptr;
    delete temp->ptr;
    temp->ptr = node;
    cout << "Deleted node "
         << "at location " << loc << "...";
    this->display();
    return;
  }

  // Removes a node at the end - O(n)
  void deleteBack()
  {
    if (this->isEmpty())
    {
      cout << "\nList is empty...\n";
      return;
    }
    if (head == tail)
    {
      this->deleteFront();
      return;
    }
    else
    {
      Node<T> *temp = head;
      while (temp->ptr->ptr != NULL)
        temp = temp->ptr;
      delete temp->ptr;
      temp->ptr = NULL;
      tail = temp;
    }
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
            *prev = NULL,
            *next = NULL;
    tail = temp;
    while (temp != NULL)
    {
      next = temp->ptr;
      temp->ptr = prev;
      prev = temp;
      temp = next;
    }
    head = prev;
    cout << "\nList reversed...";
    this->display();
    return;
  }

  // Concatenates two lists - O(n)
  void concat(SinglyLinkedList<T> &list)
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
        node->ptr = NULL;
        temp->ptr = node;
        temp = temp->ptr;
        temp1 = temp1->ptr;
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
  void operator+(SinglyLinkedList<T> &list)
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
      temp = temp->ptr;
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
         temp = temp->ptr, count++)
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
    while (temp->ptr != NULL)
    {
      cout << temp->info << " -> ";
      temp = temp->ptr;
    }
    cout << temp->info << endl;
    return;
  }
};

int main(void)
{
  int choice, ele, info, loc, count;
  SinglyLinkedList<int> list, list2;
  do
  {
    cout << "\tSingly Linked List\n"
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
    case 10:
      list.reverse();
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
