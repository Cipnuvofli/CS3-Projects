//Solution to Homework 8
//CSCE 2050, Fall 2011
//Student: Joseph Penrod
//Instructor: Dr. Xiaohui Yuan



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
			if(cur->item == NULL)
			{
				cout<<"Invalid location\n";
				return -1;
			
			}
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
		if((index<1)||(index>length))
		{
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

int main()
{
	doublylinkedlist dllist;
	int inserter = 0;
	int iterator = 0;
	cout<<"Give me 9 numbers\n";
	while (iterator<9)
	{
		iterator++;
		cin>>inserter;
		dllist.insert(inserter);	
	}
	cout<<"The numbers given were:\n";
	dllist.display();
	dllist.ascendingsort();
	cout<<"The numbers sorted are:\n";
	dllist.display();
	dllist.insert(6, dllist.locationdeterminant(6));
	cout<<"Inserting 6 without disrupting the sorting makes it look like this\n";
	dllist.display();
	dllist.remove(6);
	cout<<"Removing the 6th item makes it look like this\n";
	dllist.display();
	int eighthitem = dllist.retrieve(8);
	int ninthitem = dllist.retrieve(9);
	cout<<"Eigthitem is "<<eighthitem<<endl;
	cout<<"Ninthitem is "<<ninthitem<<endl;
	cout<<"Sum of eigth and Ninth item is "<<eighthitem+ninthitem<<endl;
	cout<<"After this statement the list is cleared\n";
	dllist.deleteall();
	cout<<"After this statement the empty list is displayed\n";
	dllist.display();
	
	return 0;
}