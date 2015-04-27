//Solution to Homework 5
//CSCE 2050, Fall 2011
//Student: Joseph Penrod
//Instructor: Dr. Xiaohui Yuan



#include<iomanip>
#include<iostream>
#include<fstream>
using namespace std;



int main()
{
	ofstream output;
	output.open ("datasize.dat", ios::out | ios::app | ios::binary);//opens the file
	char charsize;
	unsigned char Ucharsize;
	short shortsize;
	unsigned short Ushortsize;
	int intsize;
	unsigned int Uintsize;
	long Longsize;
	unsigned long Ulongsize;
	float floatsize;
	double doublesize;
	long double Ldoublesize;//Apparently the fact that long doubles display 8 bytes is a quirk of Visual C++


	output<<"char                  "<<sizeof(charsize)<<endl;
	output<<"unsigned char         "<<sizeof(Ucharsize)<<endl;
	output<<"short int             "<<sizeof(shortsize)<<endl;
	output<<"unsigned short int    "<<sizeof(Ushortsize)<<endl;
	output<<"int                   "<<sizeof(intsize)<<endl;
	output<<"unsigned int          "<<sizeof(Uintsize)<<endl;
	output<<"long int              "<<sizeof(Longsize)<<endl;
	output<<"unsigned long int     "<<sizeof(Ulongsize)<<endl;
	output<<"float                 "<<sizeof(floatsize)<<endl;
	output<<"double                "<<sizeof(doublesize)<<endl;
	output<<"long double           "<<sizeof(Ldoublesize)<<endl;//If it's 8 bytes, it's a quirk of Visual C++

	output.close();



}