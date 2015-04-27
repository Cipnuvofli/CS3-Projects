//Solution to Homework 3
//CSCE 2050, Fall 2011
//Student: Joseph Penrod
//Instructor: Dr. Xiaohui Yuan


#include <iostream>;
#include <iomanip>;
using namespace std;


inline int celsius(int fahrenheit)//converts fahrenheit to celsius
{
	double celsius = (fahrenheit-32)*(0.555555556);//if it's not a decimal it comes out weird

	return celsius;

}

inline int fahrenheit(int celsius)//converts celsius to fahrenheit
{

	double fahrenheit = ((celsius *1.8)+32);

	return fahrenheit;
}


int main()
{


	cout<<"Fahrenheit equivalents of Celsius temperatures:\n";
	cout<<"Celsius Fahrenheit Celsius Fahrenheit Celsius Fahrenheit Celsius Fahrenheit\n";
	for(int x = 0; x<=10; x++)
	{
		cout<<setw(7)<<x<<setw(11)<<fahrenheit(x)<<setw(8)<<x+25<<setw(11)<<fahrenheit(x+25);//there's a lot of material per line
		cout<<setw(8)<<x+50<<setw(11)<<fahrenheit(x+50);
		cout<<setw(8)<<x+75<<setw(11)<<fahrenheit(x+75)<<"\n";
	}
	cout<<"...\n";
	cout<<"Celsius equivalents of Fahrenheit temperatures:\n";
	cout<<"Fahrenheit Celsius Fahrenheit Celsius Fahrenheit Celsius Fahrenheit Celsius\n";
	for(int z = 32; z<=40; z++)
	{
		cout<<setw(10)<<z<<setw(8)<<celsius(z)<<setw(11)<<z+45<<setw(8)<<celsius(z+45);
		cout<<setw(11)<<z+90<<setw(8)<<celsius(z+90);
		cout<<setw(11)<<z+135<<setw(8)<<celsius(z+135)<<"\n";
	
	}
	cout<<"...\n";
	return 0;



}