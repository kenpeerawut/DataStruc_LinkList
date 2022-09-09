#include <bits/stdc++.h> 
using namespace std;

//Practice Again

//----------PDF Junior  Exercise (W3)--------------- 
//Ex.2
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
	int Search_Index(int value)  //Function Seach Value
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
		return -1; //if search not found return -1
	}
	
};

int main()
{
	Link_List *a = new Link_List(1);
	a->Addnode(9);
	a->Addnode(5);
	a->Addnode(2);
	
	a->PrintList(); cout<<endl;
	
	
	//+++++++++++++++++++++++Search Value then Delete value++++++++++++++++++++++++
//	int t_index = a->Search_Index(5);
//	if(t_index != -1){ a->DeleteNode(t_index); }
//	a->PrintList(); cout<<endl;
	
	//++++++++++++++++++++++Search value then add new value after the number of search++++++++++++++
	int t_index = a->Search_Index(5);
	if(t_index != -1){ a->InsertNode_After(t_index,3); }
	a->PrintList(); cout<<endl;

//++++++++++++++++++++++Search value then add new value before the number of search++++++++++++++
    int t_index = a->Search_Index(5);
	if(t_index != -1){ a->InsertNode(t_index,3); }
	a->PrintList(); cout<<endl;
	


	return 0;
}

