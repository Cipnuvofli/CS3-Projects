//Solution to Homework 6
//CSCE 2050, Fall 2011
//Student: Joseph Penrod
//Instructor: Dr. Xiaohui Yuan


#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<vector>
using namespace std;







int main()
{

    int accountNumber;//old master data
    int accountNum;//transactions
    double currentBalance;
    double dollarAmount;
    string firstname;
	string lastname;
	vector<int>numbersusedOldmaster;//stores account numbers
	vector<int>numbersusedTransactions;//stores account numbers
	vector<double>FnumbersusedOldmaster;
	vector<double>FnumbersusedTransactions;//used when a nonmatch destabilizes things on the financial end
	

	ifstream inOldMaster("oldmast.dat", ios::in);
	ifstream inTransaction("trans.dat", ios::in);
	ofstream outNewMaster("newmast.dat", ios::out);



	if(inOldMaster.is_open()&& inTransaction.is_open())
	{
		
		while(!inTransaction.eof())//This is necessary to make all the account numbers accessible
		{
			inTransaction>>accountNum>>dollarAmount;
			numbersusedTransactions.push_back(accountNum);
			FnumbersusedTransactions.push_back(dollarAmount);
			inOldMaster>>accountNumber>>firstname>>lastname>>currentBalance;
			numbersusedOldmaster.push_back(accountNumber);
			FnumbersusedOldmaster.push_back(currentBalance);
			
		}
		inTransaction.clear();
		inTransaction.seekg(0, ios::beg);
		inOldMaster.clear();
		inOldMaster.seekg(0,ios::beg);
		while(!inOldMaster.eof())
		{
			inOldMaster>>accountNumber>>firstname>>lastname>>currentBalance;
			inTransaction>>accountNum>>dollarAmount;
			int match = 0;
			int match2 = 2;
			int transactions = 0;
				for(int z = 0; z<numbersusedOldmaster.size(); z++)
				{
					if(accountNum == numbersusedOldmaster[z])
					{
						match = 1;
					}
				
				}
				if(match == 0)
				{
					outNewMaster<<"Unmatched transaction record for account "<<accountNum<<endl;
				}
				
				if(accountNumber == accountNum)
				{
					currentBalance = dollarAmount+currentBalance;
					outNewMaster<< fixed;
					outNewMaster<<setprecision(2)<<accountNumber<<" "<<firstname<<" "<<lastname<<" "<<currentBalance<<endl;	
				}
				else
				{
					for(int q = 0; q<numbersusedTransactions.size(); q++)
					{
						if(accountNumber == numbersusedTransactions[q])
						{
						currentBalance = FnumbersusedTransactions[q]+currentBalance;
						outNewMaster<<fixed;
						outNewMaster<<setprecision(2)<<accountNumber<<" "<<firstname<<" "<<lastname<<" "<<currentBalance<<endl;	
						}
					}
				}
				
				
			
			
		
		}
	
	}
	
	inOldMaster.close();
	inTransaction.close();
	outNewMaster.close();

	return 0;
}


