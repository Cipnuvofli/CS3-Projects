//Solution to Homework 3
//CSCE 2050, Fall 2011
//Student: Joseph Penrod
//Instructor: Dr. Xiaohui Yuan


#include<iostream>;
using namespace std;


inline int GCD(int x, int y)
{
  int swapspace;

  if(y>x)//Why does X need to be larger than Y?
  {
	cout<<"This may be irrelevant, but X needs to be larger than Y for this to work properly, so they're being switched.\n";
	int swapspace = x;//these three lines swap x and y;
	int x = y;
	int y = swapspace;
  }
	if(y == 0)//base case
	{
		return x;
	
	}
	else//it calls itself again
	{
		GCD(y, x%y);
	}


}



int main()
{
	int x;
	int y;
	
	cout<<"Give this program two integers and it will give you the GCD\n";
	cin>>x;//these two CIN lines let the user input two integers
	cin>>y;
	cout<<"The GCD is: "<<GCD(x,y)<<"\n";

	return 0;
}