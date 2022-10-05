#include <iostream>
#include <stdlib.h>
using namespace std;
struct node 
{
    int num;
    struct node * preptr;
    struct node * nextptr;
}
*starrt_node, *end_node;
 

void Listcreation(int n);
void DeleteLastnode();
void display(int a);

int main()
{
    int n,num1,a,insPlc;
    starrt_node = NULL;
    end_node = NULL;
             
    cout<<" Enter the number of nodes: ";
    cin>>n;
    Listcreation(n); 
    a=1;
    display(a);
    DeleteLastnode();
        a=2;
    display(a);
    return 0;
}
 
void Listcreation(int n)
{
    int i, num;
    struct node *fnNode;
 
    if(n >= 1)
    {
        starrt_node = (struct node *)malloc(sizeof(struct node));
        if(starrt_node != NULL)
        {
            cout<<" Enter data for node 1: "; // assigning data in the first node
            cin>>num;
            starrt_node->num = num;
            starrt_node->preptr = NULL;
            starrt_node->nextptr = NULL;
            end_node = starrt_node;
            for(i=2; i<=n; i++)
            {
                fnNode = (struct node *)malloc(sizeof(struct node));
                if(fnNode != NULL)
                {
                    cout<<" Enter data for node "<<i<<": ";
                    cin>>num;
                    fnNode->num = num;
                    fnNode->preptr = end_node;    // new node is linking with the previous node
                    fnNode->nextptr = NULL;       // set next address of fnnode is NULL
                    end_node->nextptr = fnNode;   // previous node is linking with the new node
                    end_node = fnNode;            // assign new node as last node
                }
                else
                {
                    cout<<" Memory can not be allocated.";
                    break;
                }
            }
        }
        else
        {
            cout<<" Memory can not be allocated.";
        }
    }
}

void DeleteLastnode()
{
    struct node * NodeToDel;
 
    if(end_node == NULL)
    {
        cout<<" Delete is not possible. No data in the list.\n";
    }
    else
    {
        NodeToDel = end_node;
        end_node = end_node->preptr;    // move the previous address of the last node to second last node
        end_node->nextptr = NULL;      // set the next address of last node to NULL
        free(NodeToDel);              // delete the last node
    }
}

void display(int m)
{
    struct node * tmp;
    int n = 1;
    if(starrt_node == NULL)
    {
        cout<<" No data found in the list yet.";
    }
    else
    {
        tmp = starrt_node;
        if (m==1)
        {
        cout<<"\n Data entered in the list are :\n";
        }
        else
        {
         cout<<"\n After deletion the new list are :\n";   
        }
        while(tmp != NULL)
        {
            cout<<" node "<< n<<": "<< tmp->num<<endl;
            n++;
            tmp = tmp->nextptr; 
        }
    }
}
