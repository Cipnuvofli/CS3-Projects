//Student: Joseph Penrod
//Solution to Programming Homework 1
//CSCE 3110
//Instructor: Dr. Robert Renka


#include <iostream>
#include<vector>
using namespace std;


template<typename Comparable>
class OrderedCollection
{
public:
	

	void insert(Comparable T)//Takes a Comparable and places it on the end of the vector named storage
	{
		Storage.push_back(T);
		size++;//Adds 1 to the private variable size
	
	}
	bool remove(Comparable T)//Removes the first instance of Comparable T it encounters from a vector and returns true, if Comparable T isn't found, returns false
	{
		for(int z = 0; z<Storage.size(); z++)
		{
			if(Storage[z] == T)
			{
				Storage.erase(Storage.begin()+z);//THe method won't take just an integer, which is why Storage.begin() is in there
				size--;//Subtracts 1 from the private variable size
				return true;
			}
		}
		
		return false;
	
	}
	Comparable findMin()//If vector storage is empty, returns 0, otherwise it returns the smallest value of the vector
	{
		if(Storage.size() == 0)
		{
			cout<<"Empty Vector, returning zero as a default value.\n";
			return 0;
		}
		else
		{
			Comparable min = Storage[0];
			for(int z = 0; z<Storage.size(); z++)
			{
				if(Storage[z]<min)
				{
					min = Storage[z];
				}
			}
			return min;
		
		}
	}
	Comparable findMax()//if vector Storage is empty, returns 0, otherwise it returns the largest value of the vector
	{
		if(Storage.size() == 0)
		{
			cout<<"Empty Vector, returning zero as a default value.\n";
			return 0;
		}
		else
		{
			Comparable max = Storage[0];
			for(int z = 0; z<Storage.size(); z++)
			{
				if(Storage[z]>max)
				{
					max = Storage[z];
				}
			}
			return max;
		
		}
	}
	void makeEmpty()//reverts vector Storage to an empty vector
	{
		if(Storage.size()!= 0)
		{
			Storage.clear();
			size = 0;//Brings private variable size back down to zero
		}
	
	}
	bool isEmpty()//checks if vector Storage is empty
	{
		if(Storage.size() == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void getContents()//A method for outputting the contents of the vector
	{
		if(Storage.size() == 0)
		{
		   cout<<"Empty vector\n";
		
		}
		else
		{
			for(int q = 0; q<Storage.size(); q++)
			{
				cout<<Storage[q]<<endl;
			
			}
		}
	}

private:
    vector<Comparable> Storage;
	int size;
};


int main()
{
	
	OrderedCollection<int> Tester;//The Ordered collection used to test the methods
	int command = 0;
	int number = 0;
	while (command != 7)//Entering 7 as the value for command exits the program
	{
		cout<<"Commands\n1. isEmpty function test\n2. makeEmpty function test\n3. Insert function test\n4. Remove function test\n5. findMin function test\n6. findMax function test\n7. Exit program\n\n";
		cout<<"Enter a command\n";
		cin>>command;
		cout<<"\n\n";
		switch(command)
		{
			case 1:
				if(Tester.isEmpty() == true)
				{
					cout<<"Empty Vector\n";
				}
				else
				{
					cout<<"The vector is not empty\n";
				}
				break;
			case 2:
				Tester.makeEmpty();//Convert the vector to an empty one
				break;
			case 3: 
				cout<<"What number are you adding to the collection?\n";
				cin>>number;//The number inputted is added to the end of the vector
				Tester.insert(number);
				cout<<endl;
				break;
			case 4:
				cout<<"What number are you trying to remove from the collection?\n";
				cin>>number;//The first instance of the number inputted is removed from the collection
				Tester.remove(number);
				break;
			case 5://outputs the minimum value of the collection
				cout<<"The minimum value in the collection is:"<<endl<<Tester.findMin()<<endl<<endl;
				break;
			case 6://outputs the maximum value of the collection
				cout<<"The maximum value in the collection is:"<<endl<<Tester.findMax()<<endl<<endl;
				break;
			case 7:
				break;
			default:
				break;

		}
	}
}