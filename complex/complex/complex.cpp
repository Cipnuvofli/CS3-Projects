//Solution to Homework 7
//CSCE 2050, Fall 2011
//Student: Joseph Penrod
//Instructor: Dr. Xiaohui Yuan



#include<iostream>
#include<iomanip>
#include "complex.h"
using namespace std;

complex::complex(double realpart, double imaginarypart)
	: real(realpart),
	imaginary(imaginarypart)
{

}

complex complex::operator+(const complex &operand2)const
{
	return complex(real+operand2.real, imaginary+operand2.imaginary);
}

complex complex::operator-(const complex &operand2)const
{
	return complex(real-operand2.real, imaginary - operand2.imaginary);

}

complex complex::operator*(const complex &operand3)const
{
	return complex(((real*operand3.real)-(imaginary*operand3.imaginary)),((real*operand3.imaginary)+(imaginary*operand3.real)));
}
ostream &operator<<(ostream &output, const complex &q)
{
	
	output<<q.real<<"+"<<q.imaginary<<"i"<<endl;
	return output;
}
istream &operator>>(istream &input, complex &r)
{
	input>>r.real>>r.imaginary;
	return input;
	
}
bool operator ==(const complex &a, const complex &b)
{
	bool  result=true;
	if(a.real != b.real || a.imaginary!=b.imaginary)//checks if the real or imaginaryparts are different
	{
		result = false;
	}
	return result;
}
bool operator !=(const complex &a, const complex &b)
{
	bool  result=true;
	if(a.real == b.real && a.imaginary==b.imaginary)//ensures everyting is equal
	{
		result = false;
	}
	return result;

}