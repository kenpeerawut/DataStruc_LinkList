#include <bits/stdc++.h> 
using namespace std;

//Practice Again


class Node
{
	public:
		Node * next;
		int value;
		Node(int value)
		{
			this->value=value;
		}
};
/*
int main() 
{
	Node*a=new Node(10);
	Node*b=new Node(20);
	Node*c=new Node(5);
	Node*d=new Node(7);
	
	a->next=b;
	b->next=c;
	c->next=d;
	d->next=NULL;
	for(Node*h=a;h!=NULL;h=h->next)
	{
		cout<<h->value<<" ";
	}
	return 0;
}
*/

class Link_List
{
	public:
	Node *head;
	int size=0;
	
	Link_List(int value)
	{
		head = new Node(value);
		head->next = NULL;
		size = 1;
	}			
	
	void Addnode(int value)
	{
		for(Node *h = head ; h != NULL ; h = h->next) //Concept LinkList must have this line
		{
			if(h->next == NULL)
			{
				h->next = new Node(value);
				h->next->next = NULL;
				break;
			}
		}
		size++;
	}
	
	//Print
	void PrintList()
	{
		for(Node *h = head ; h != NULL ; h = h->next) //Concept LinkList must have this line
		{
			cout<<h->value<<" ";
		}
	
	}
	
};

int main()
{
	Link_List *ben10 = new Link_List(1);
	ben10->Addnode(5);
	ben10->Addnode(10);
	ben10->Addnode(17);
	ben10->Addnode(19);
	ben10->Addnode(22);
	ben10->PrintList();
	cout<<endl;
	
	return 0;
}

