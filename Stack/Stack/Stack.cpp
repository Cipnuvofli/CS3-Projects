#include<iostream>
#include<iomanip>
#include<new>
using namespace std;
class doublylinkedlist
{
	struct Node
	{
		Node *prev;
		int item;
		Node *next;
	};

protected:
	Node *head;
	Node *tail;
	int length;

public:

	doublylinkedlist(): head( NULL ), tail(NULL), length(0) 
	{
	
	}
	~doublylinkedlist()
	{
	
	}
	Node* finditem(int index)//find the location of the item and return it's reference, if it fails, return -1;
	{						  //How do you make a method return a pointer or an int with one return type
		Node *cur = head;
		
		if((index<1)||(index>length))
		{
			cout<<"This out of bounds incident shouldn't happen\n";
			return NULL;
		}
		else
		{
			for(int x = 1; x<=index; x++)
			{
				if(x!=index)
				{
				cur = cur->next;	
				}
			}
			return cur;
		}
			return NULL;
	}
	int retrieve(int location) const //returns the item in the nodes location
	{
		if((location<1)||(location>length))
		{
			return -1;
		}
		else
		{
			Node *cur = head;
			for(int x = 1; x<location; x++)
			{
			
				cur = cur->next;
			
				
			}
			/*if(cur->item == NULL)
			{
				cout<<"Invalid location\n";
				return -1;
			
			}*/
			return cur->item;
		
		}
		
	
	
	}
	void insert(int inserted)//inserts in end by default
	{
		int nodecount = length+1;
		length = nodecount;
		Node *newPtr = new Node;
		newPtr->item = inserted;
		if(head == NULL && tail == NULL)
		{
			head = newPtr;
			tail = newPtr;
			newPtr->prev = NULL;
			newPtr->next = NULL;
		}
		else
		{
			if(length == 2)
			{
				head->next = tail;
			
			}
			tail->next = newPtr;
			newPtr->prev = tail;
			newPtr->next = NULL;
			tail = newPtr;
			tail->next = NULL;

			
		}
	
	}
	void insert(int inserted, int location)//inserts in any location in the list
	{
		int nodecount = length+1;
		if((location<1)||(location>nodecount))
		{
			cout<<"This out of bounds incident shouldn't happen\n";
		
		}
		else
		{
				length = nodecount;
				Node *newPtr = new Node;
				newPtr->item = inserted;
				if(head == NULL)
				{

					head = newPtr;
					tail = newPtr;
					newPtr->prev = NULL;
					newPtr->next = NULL;
					
				}
				else
				{
						if(location!=1)
						{
							Node *previous = finditem(location-1);
							newPtr->next = previous->next;
							newPtr->prev = previous;
							previous->next = newPtr;
						}
						else
						{
							if(head == NULL && tail == NULL)
							{
							newPtr->prev = NULL;
							newPtr->next = head;
							tail = head;
							head = newPtr;
							
							}
							else
							{
							newPtr->prev = NULL;
							newPtr->next = head;
							head = newPtr;
							}
						}		
				}	

		}
	}
	int remove(int index)//removes an item from the list
	{
	
		Node *target = finditem(index);
		if(index<1||index>length)
		{
			cout<<"Index less than 1 or index greater than length\n";
			return -1;
		
		}
		else
		{
			length = length-1;
			
			if (target->prev == NULL)
			{
				if(target->next == NULL)
				{
					head = NULL;
					tail = NULL;
					delete target;
					return 0;
				}
				else
				{
				head = target->next;
				head->prev = NULL;
				}
			}
			else 
			{
				(target->prev)->next = target->next;
			}
			if(target->next == NULL)
			{
				tail = target->prev;
				tail->next = NULL;
			}
			else
			{
				(target->next)->prev = target->prev;
			}
			
			delete target;
		}
	}
	void deleteall()//empties the list
	{
		while(isEmpty() == false)
		{
			remove(1);
		}
	
	}
	void display()//outputs the list
	{
		cout<<"\n";
		 Node *cur = head;
		 while(cur!=NULL)
		 {
			 cout<<cur->item<<"\n";
			 cur = cur->next;
		 }
		 cout<<"\n";
	}
	int size() const 
	{
		return length;
	
	}
	bool isEmpty() const
	{
		return length == 0;
	}
	void ascendingsort()//sorts the list
	{
		Node *temp = NULL;
		Node *tempstart = NULL;

		for(tempstart =head; tempstart != NULL; tempstart = tempstart->next)
		{
			for(temp = tempstart->next; temp != NULL; temp = temp->next)
			{
				if(tempstart->item>temp->item)
				{
					int tempitem = temp->item;
					temp->item = tempstart->item;
					tempstart->item = tempitem;
				}
			}
		
		}
	
	}
	int locationdeterminant(int inserted)//used to insert numbers without disrupting sorting
	{
		int index = 1;
		for(Node *cur = head; cur!= NULL; cur = cur->next)
		{
			if(cur->item>inserted && ((cur->prev)->item<inserted || (cur->prev)->item == NULL))
			{
				return index;
			
			}
			index++;
		
		}
		return -1;
	
	}
	    
};
class stack: public doublylinkedlist
{

public:
	stack()
	{
	
	
	}
	~stack()
	{
	
	
	}
	void push(int item)
	{
		insert(item);	
	}
	void pop()
	{
		remove(length);
	
	}
	int top()
	{
		int top = retrieve(length);
		return top;

	}
	int size()
	{
		return length;
	}
	int isEmpty()
	{
		if(length == 0)
		{
			return 1;
		
		
		}
		else
		{
			return 0;
		}
	
	
	}

};


int main()
{
	stack pile;
	int iterator  = 0;
	int inserted;
	int sum;
	cout<<"Give me 7 numbers and I'll sum them\n";
	while(iterator<7)
	{
		cin>>inserted;
		pile.push(inserted);
		iterator++;
	}
	while(pile.size()!=1)
	{
		pile.display();
		int removed1 = pile.top();
		pile.pop();
		int removed2 = pile.top();
		pile.pop();
		sum = removed1+removed2;
		cout<<"Sum is "<<sum<<endl;
		pile.push(sum);
	
	}


}