//Student: Joseph Penrod
//Solution to Programming Homework 2
//CSCE 3110
//Instructor: Dr. Robert Renka


#include <iostream>
using namespace std;


template<typename object>
class singleList
{
	struct Node
	{
		object item;
		Node *next;
	};
	Node *head;
	int length;

public:

	singleList()
	{
		init();
	}
	singleList(const singleList &rhs)
	{
		init();
		*this = rhs;
	}
	~singleList()
	{
		clear();
		delete head;
	}
	void init()
	{
		length = 0;
		head = new Node;

	
	}
	int size() const 
	{
		return length;
	
	}
	bool empty() const
	{
		return size() == 0;
	
	}
	void clear()//Wipes out the head of a  list until the list is empty
	{
		while(!empty())
		{
			Node *Target = head;
			head = head->next;
			length--;
			delete Target;
		}
	
	}
	void getcontents()//If size is zero, informs user that list is empty, otherwise prints list contents
	{
		if(size() == 0)
		{
			cout<<"Empty list\n\n";
		}
		else
		{
		 cout<<"\n";
		 Node *cur = head;
		 while(cur!=NULL)
		 {
			 cout<<cur->item<<"\n";
			 cur = cur->next;
		 }
		 cout<<"\n\n";
		}
	}
	bool Containedinlist(object item)//Searches the list for an item, returns true if it's in the list
	{
		if(size() == 0)
		{
			return false;
		
		}
		else
		{
			Node *cur = head;
			while(cur!=NULL)
			{
				if(cur->item == item)
				{
					return true;
				}
				cur = cur->next;
			
			}
		}
	
	}
	void conditionalInsert(object item)//checkes if an item isn't in the list, inserts it if it is
	{
		if(Containedinlist(item) == false && size() == 0)
		{
			length++;
			Node *insert = new Node;
			insert->item = item;
			insert->next = NULL;
			head = insert;
		
		}
		else if(Containedinlist(item) == true)
		{
			cout<<"This is already in the list\n";
		}
		else
		{
			length++;
			Node *insert = new Node;
			insert->item = item;
			insert->next = head;
			head = insert;
		}
	
	}
	void remove(object item)//removes an item if it's contained in the list. 
	{
		if(Containedinlist(item) == true)
		{
			Node *cur = head;
			if(head->item == item)
			{
				Node *target = head;
				head = head->next;
				length--;
				delete target;	
				
			}
			else
			{
				while(cur!=NULL)
				{
					if(cur->next!= NULL && cur->next->item == item )
					{
						Node *target = cur->next;	
						cur->next = target->next;
						delete target;
						length--;
					
					}
					cur =  cur->next;			
				}
			}
		
		}
		else
		{
			cout<<"Item not found\n";
		}
	
	}
	
	
};

int main()
{
	singleList<int> Tester;
	int command = 0;
	while (command != 6)
	{
		cout<<"\n";
		cout<<"Enter a command\n1. Test Size method\n2. Test getcontents method\n3. Test ContainedInList method\n4. Test Conditionalinsert Method\n5. Test remove method\n6. Exit Program\n\n";

		if(!(cin>>command))//this conditional validates the input, preventing a char from creating an infinite loop
		{
			cout<<"Enter a number from 1 to 6: \n";
			cin.clear();//te
			cin.ignore(1000, '\n');
		
		}
		else
		{
		cout<<"\n\n";
		
			switch(command)
			{
				case 1:
					cout<<"The size of the list is "<<Tester.size()<<endl<<endl;
					break;
				case 2:
					Tester.getcontents();
					break;
				case 3: 
					if(Tester.size() == 0)
					{
						cout<<"Empty List\n\n";
					}
					else
					{
						int check;
						cout<<"What value are you checking for?\n";
						if(!(cin>>check))
						{
							cout<<"Invalid input, try again \n";
							cin.clear();
							cin.ignore(1000, '\n');
						}
						else
						{
							if(Tester.Containedinlist(check) == true)
							{
								cout<<"Contained in list\n\n";
							}
							else
							{
								cout<<"Not contained in list\n\n";
							}
						}
					}
					break;
				case 4:
					int insert;
					cout<<"What value are you trying to insert?\n";
					if(!(cin>>insert))
					{
							cout<<"Invalid input, try again \n";
							cin.clear();
							cin.ignore(1000, '\n');
					
					}
					else
					{
						Tester.conditionalInsert(insert);
					}
					break;
				case 5:
					if(Tester.size() == 0)
					{
						cout<<"Empty List\n\n";
					}
					else
					{
						int remove;
						cout<<"What value are you trying to remove?\n";
						
						if(!(cin>>remove))
						{
							cout<<"Invalid input, try again \n";
							cin.clear();
							cin.ignore(1000, '\n');
						
						}
						else
						{
							Tester.remove(remove);
						}
					}
					break;
				case 6:
					break;
				default:
					break;
			

			}
		}
	}

}