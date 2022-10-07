#include <iostream>
#include<stdlib.h>
using namespace std;
#define MAX 30
template<class t>
class node
{
	public:
	node *next;
	int vertex;
};
template<class t>
class graphq
{
	public:
	int data[MAX];
	int rear,front;
	void DFS(int);
	void readgraph();
	int empty(graphq *);
	int full(graphq *);
	void insert(int vi, int vj);
	int discovered[MAX];
	int layer[MAX],parent[MAX];
	node<t> *heads[MAX];
	int n;
};


template<class t>
void graphq<t>::DFS(int i)
{
	node<t> *p;
	cout<<"\t"<<i;
	p=heads[i];
	discovered[i]=1;
	while(p!=NULL)
	{
		i=p->vertex;
		if(!discovered[i])
		{
			DFS(i);
		}
		p=p->next;
	}
}
template<class t>
int graphq<t>::empty(graphq *p)
{
	if(p->rear==-1)
	return(1);
	return(0);

}
template<class t>
int graphq<t>::full(graphq *p)
{
	if(p->rear==MAX-1)
	return(1);
	return(0);
}
template<class t>
void graphq<t>::readgraph()
{
	int i,vi,vj, nofedges;
	cout<<"\nEnter the number of vertices : ";
	cin>>n;
	for(i=0;i<n;i++)
	heads[i]=NULL;
	cout<<"\nEnter the number of edges : ";
	cin>>nofedges;
	for(i=0;i<nofedges;i++)
	{
		cout<<"\nEnter an edge (u,v) : ";
		cin>>vi>>vj;
		insert(vi,vj);
		insert(vj,vi);
	}
}
template<class t>
void graphq<t>::insert(int vi, int vj)
{
	node<t>*P;
	node<t>*Q;
	Q=new node<t>;
	Q->vertex=vj;
	Q->next=NULL;
	if(heads[vi]==NULL)
	heads[vi]=Q;
	else
	{
		P=heads[vi];
		while(P->next!=NULL)
		P=P->next;
		P->next=Q;
	}
}
int main()
{
	int i;
	graphq<int>gq;
	cout<<"\n---Create a node--- ";
	gq.readgraph();
	cout<<"\nDFS :";
	cout<<"\nStarting node number : ";
	cin>>i;
	gq.DFS(i);
	return 0;
}

//example to enter and the check dfs how it work [6 vertices and 6 edge]
//(u,v)=(0, 1),(0, 2),(1, 2),(2, 0),(2, 3),(3, 3)
//starting node is 2
//u will get output -[2 0 1 3]
