//Solution to Homework 7
//CSCE 2050, Fall 2011
//Student: Joseph Penrod
//Instructor: Dr. Xiaohui Yuan


#ifndef COMPLEX_H
#define COMPLEX_H

#include<iostream>
#include<string>
using namespace std;

class complex
{
friend ostream &operator<<(ostream &, const complex &);
friend istream &operator>>(istream &, complex &);
friend bool operator ==(const complex &, const complex &);
friend bool operator !=(const complex &, const complex &);
public:
	complex(double = 0.0, double = 0.0);
	complex operator+(const complex &) const;
	complex operator-(const complex &) const;
	complex operator*(const complex &) const;
private:
	double real;
	double imaginary;
};

#endif