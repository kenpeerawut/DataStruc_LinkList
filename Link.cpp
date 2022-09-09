#include <bits/stdc++.h> 
using namespace std;

//Practice Again


class Node
{
	public:
		Node *next;
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
			cout<<h->value<<" "; //whitespace in result
		}
	
	}
	
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++	
	void InsertNode(int index,int value) //in
	{
		if(index <= size && index > -1)
		{
			bool complete_insert = 0; //check size has change or not??
			int my_index = 1;         //if insert before ----------------my_index = 1 
			for(Node *h = head;h != NULL; h = h->next)
			{
				if(index == 0) //First insert
				{
					Node *h = new Node(value);
					h->next = head;
					head = h;
					complete_insert = 1;//unnecessary
					break;
				}
				else if(my_index == size && index == size)//insert last 
				{
					h->next = new Node(value);     //Same AddNode
					h->next->next = NULL;          // in line 56,57
					
					complete_insert = 1;
					break;
				}
				else if(my_index == index)// insert before
				{
					Node *n = new Node(value);
					n->next = h->next;
					h->next = n;
					complete_insert = 1;
					break;
					
				}
				my_index++;
			}
			if(complete_insert == 1){	size++;	}
		}
	}
	
	
	void InsertNode_After(int index,int value) 
	{
		if(index <= size && index > -1)
		{
			bool complete_insert = 0; //check size has change or not??
			int my_index = 0;         // insert after ---------------my_index = 0
			for(Node *h = head;h != NULL; h = h->next)
			{
				if(my_index == size && index == size)//insert last 
				{
					h->next = new Node(value);     //Same AddNode
					h->next->next = NULL;          // in line 56,57
					
					complete_insert = 1;
					break;
				}
				else if(my_index == index)// insert before
				{
					Node *n = new Node(value);
					n->next = h->next;
					h->next = n;
					complete_insert = 1;
					break;
					
				}
				my_index++;
			}
			if(complete_insert == 1){	size++;	}
		}
	}
	
	
	void DeleteNode(int index)
	{
		bool complete_delete = 0;//check size has change or not??
		if(index < size && index >-1)
		{
			int my_index = 1;
			for(Node *h = head; h != NULL;h = h->next)
			{
				if(index == 0) //Delete First Node 
				{
					head = head->next;
					
				    complete_delete = 1;
	                break;
				}
				else if(my_index == index) //Delete Another Node until last Node
				{
					h->next = h->next->next;
					
					complete_delete = 1;
					break;
				}
				my_index++;
				
			}
			if(complete_delete = 1) {  size--; }
			
		}
		
		
	}
//+++++++++++++++++++++++++++++++++++++++++++++++++	
	int Search_Index(int value)  //Fun
	{
		int i = 0;
		for(Node *h = head; h != NULL; h = h->next)
		{
			if(value == h->value)
			{
				return i;
			}
			i++;
		}
		return -1;
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
	
	ben10->InsertNode(0,7);//insert First node
	//ben10->InsertNode(2,7);//insert before node
	//ben10->InsertNode(8,7);//insert last node  
	
	//ben10->DeleteNode(0); //Delete  First node
	
	ben10->PrintList(); 
	cout<<"|"<<ben10->size<<endl;  //Output with "| size"  Ex. 1 2 3 |3 but index is 0 1 2
	
	ben10->Addnode(500);
	ben10->PrintList(); 
	cout<<"|"<<ben10->size<<endl;
	
	return 0;
}

