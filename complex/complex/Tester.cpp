//Solution to Homework 6
//CSCE 2050, Fall 2011
//Student: Joseph Penrod
//Instructor: Dr. Xiaohui Yuan


#include "complex.h"
#include <iostream>
#include <iomanip>


int main()
{
	complex complexQ;
	cout<<"Give me a complex and I'll return it as complexQ"<<endl;
	cin>>complexQ;//these 2 lines test overloaded operators
	cout<<complexQ<<endl;
	complex complex1(3,7);
	complex complexR(3,7);
	complex complex2(5,4);
	cout<<"Complex 1 is 3+7i, Complex 2 is 5+4i, multiplied they are "<<complex1*complex2<<endl;//this tests the multiplication operator
	cout<<"complex R is 3+7i"<<endl;
	if(complex1 == complexR)//this tests the == operator
	{
		cout<<"Complex 1 = ComplexR"<<endl;
	}
	if(complex1!=complex2)//this tests the != operator
	{
	
		cout<<"Complex1 is not equal to complex 2"<<endl;
	}
	


}