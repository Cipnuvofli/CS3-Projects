#include <iostream>
using namespace std;


unsigned binaryonescounter(unsigned N)
{
	if(N==0)
	{
		return 0;
	}
	else
	{
		return (N%2) + binaryonescounter(N/2);
	}

}


int main()
{
	
	for(int q = 0; q<16; q++)
	{
		cout<<q<<" has "<<binaryonescounter(21)<<" Ones in its binary equivalent\n";
	
	
	}
    
}