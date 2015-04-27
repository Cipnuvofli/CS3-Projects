

#include <iostream>
#include <iomanip>

using namespace std;

int board[8][8] = {0};//the board the knight moves around on
int accessibilityratings[8][8];//used to heuristically determine what square to go to next


void EastofNorthcheck(int horizontal, int vertical)//The XofX checks are used in generating accessiblity ratings for squares in the accessiblityratings array
{
	if(vertical-2>=0 && horizontal+1<=7 && board[horizontal+1][vertical-2]== 0)
	{
		accessibilityratings[horizontal][vertical]++;
	}


}
void NorthofEastcheck(int horizontal, int vertical)
{
	if(horizontal+2<=7 && vertical-1>=0 && board[horizontal+2][vertical-1]== 0)
	{
		accessibilityratings[horizontal][vertical]++;
	}

}
void SouthofEastcheck(int horizontal, int vertical)
{
	if(horizontal+2<=7 && vertical+1<=7 && board[horizontal+2][vertical+1]== 0)
	{
		accessibilityratings[horizontal][vertical]++;
	}


}
void EastofSouthcheck(int horizontal, int vertical)
{
	if(vertical+2<=7 && horizontal+1<=7 && board[horizontal+1][vertical+2]== 0)
	{
		accessibilityratings[horizontal][vertical]++;
	
	}

}
void WestofSouthcheck(int horizontal, int vertical)
{
	if(vertical+2<=7 && horizontal-1>=0 && board[horizontal-1][vertical+2]== 0)
	{
		accessibilityratings[horizontal][vertical]++;
	}

}
void SouthofWestcheck(int horizontal, int vertical)
{
	if(horizontal-2>=0 && vertical+1<=7 && board[horizontal-2][vertical+1]== 0)
	{
		accessibilityratings[horizontal][vertical]++;
	}

}
void NorthofWestcheck(int horizontal, int vertical)
{
	if(horizontal-2>=0 && vertical-1>=0 && board[horizontal-2][vertical-1]== 0)
	{
		accessibilityratings[horizontal][vertical]++;
	}

}
void WestofNorthcheck(int horizontal, int vertical)
{
	if(horizontal-1>=0 && vertical-2>=0 && board[horizontal-1][vertical-2]== 0)
	{
		accessibilityratings[horizontal][vertical]++;
	}

}
void connectionanalysis()
{

	for(int q = 0; q<8; q++)
	{
		for(int r = 0; r<8; r++)
		{
			
			accessibilityratings[q][r] = 0;	
		}
		
	}
	for(int x = 0; x<8; x++)
	{
		for(int y = 0; y<8; y++)
		{
			EastofNorthcheck(x, y);
			NorthofEastcheck(x,y);
			SouthofEastcheck(x,y);
			EastofSouthcheck(x,y);
			WestofSouthcheck(x,y);
			SouthofWestcheck(x,y);
			NorthofWestcheck(x,y);
			WestofNorthcheck(x,y);

		
		
		}
	}
	for(int A = 0; A<8; A++)
	{
		for(int B = 0; B<8; B++)
		{
			if(board[A][B]!=0)
			{
			
				accessibilityratings[A][B] = 9;
			
			}
		
		}
	
	}




}

int getaccessibilityrating(int x, int y)//used in tiebreaking
{
	cout<<"The x and y passed to getaccessiblityrating are"<<x<<","<<y<<"\n";
	int lowestaccessibilityrating = 10;
	connectionanalysis();
	if(accessibilityratings[x+1][y+2]!= 9 && accessibilityratings[x+1][y+2] <lowestaccessibilityrating && x+1<=7 && y+2<=7)
	{
		cout<<"Case EofN\n";
		lowestaccessibilityrating = accessibilityratings[x+1][y+2];
	
	}
	if(accessibilityratings[x+1][y+2]!= 9 && accessibilityratings[x+2][y-1]<lowestaccessibilityrating && x+2<=7 && y-1 >=0)
	{
		cout<<"Case NofE\n";
		lowestaccessibilityrating = accessibilityratings[x+2][y-1];
	}
	if(accessibilityratings[x+1][y+2]!= 9 && accessibilityratings[x+2][y+1]<lowestaccessibilityrating && x+2<=7 && y-1>=0)
	{
		cout<<"Case SofE\n";
		lowestaccessibilityrating = accessibilityratings[x+2][y+1];
	}
	if(accessibilityratings[x+1][y+2]!= 9 && accessibilityratings[x+1][y+2]<lowestaccessibilityrating && x+1<= 7 && y+2<=7)
	{
		cout<<"Case EofS\n";
		lowestaccessibilityrating = accessibilityratings[x+1][y+2];
	}
	if(accessibilityratings[x+1][y+2]!= 9 && accessibilityratings[x-1][y+2]<lowestaccessibilityrating && x-1>=0 && y+2<=7)
	{
		cout<<"Case WofS\n";
		lowestaccessibilityrating = accessibilityratings[x-1][y+2];
	}
	if(accessibilityratings[x+1][y+2]!= 9 && accessibilityratings[x-2][y+1]<lowestaccessibilityrating && x-2>=0 && y+1<=7)
	{
		cout<<"Case SofW\n";
		lowestaccessibilityrating = accessibilityratings[x-2][y+1];
	}
	if(accessibilityratings[x+1][y+2]!= 9 && accessibilityratings[x-2][y-1]<lowestaccessibilityrating && x-2>=0 && y-1>=0)
	{
		cout<<"Case NofW\n";
		lowestaccessibilityrating = accessibilityratings[x-2][y-1];
	}
	if(accessibilityratings[x+1][y+2]!= 9 && accessibilityratings[x-1][y-2]<lowestaccessibilityrating && x-1>=0 && y-2>=0)
	{
		cout<<"Case WofN\n";
		lowestaccessibilityrating = accessibilityratings[x-1][y-2];
	}
	return lowestaccessibilityrating;
	
}
void displayAR()
{
	connectionanalysis();//used to see what squares can reach each square
	cout<<"These are the accessibilityratings(9 means its been visited)\n";
	for(int x = 0; x<8; x++)
	{
		for(int y = 0; y<8; y++)
		{
			cout<<accessibilityratings[y][x];
		
		
		}
		cout<<"\n";
	}
	cout<<"\n";

}
void displayboard()//shows board
{
	cout<<"This is the board\n";
	for(int x = 0; x<8; x++)
	{
		for(int y = 0; y<8; y++)
		{
			cout<<board[y][x]<<"  ";
		
		
		}
		cout<<"\n";
	}
	cout<<"\n";


}
int lowestaccessibilityrating(int x, int y)//Used to find the square with the lowest accessibility rating around a knights location Also, this method is used in tiebreakers to check which tied square can get to one with a lower accessibility rating. Also
{
	int lowestaccessibilityrating = 10;
	int tiemoves[8] = {0} ;
	int movedescriptionnumber = -1;
	int equivalentmoves = 0;//1 means tiebreaker
	cout<<"x+1, y-2 = "<<x+1<<","<<y-2<<"\n";
	if(x+1<=7 && y-2>=0 && accessibilityratings[x+1][y-2] != 9)
	{
		
		cout<<"Lowest AR is "<<accessibilityratings[x+1][y-2]<<endl;
		lowestaccessibilityrating = accessibilityratings[x+1][y-2];
		tiemoves[0] = 1;
		movedescriptionnumber = 1;
		
	}
	cout<<"x+2, y-1 = "<<x+2<<","<<y-1<<"\n";
	if(accessibilityratings[x+2][y-1] == lowestaccessibilityrating && x+2<=7 && y-1>=0 && accessibilityratings[x+2][y-1]!= 9)
	{
		tiemoves[1] = 1;
	
	}
	if(x+2<=7 && y-1>=0 && accessibilityratings[x+2][y-1]<lowestaccessibilityrating && accessibilityratings[x+2][y-1]!= 9)
	{
		cout<<"Lowest AR is "<<accessibilityratings[x+2][y-1]<<endl;
		lowestaccessibilityrating = accessibilityratings[x+2][y-1];
		movedescriptionnumber = 2;
	
	}
	cout<<"x+2, y+1 = "<<x+2<<","<<y+1<<"\n";
	if(accessibilityratings[x+2][y+1] == lowestaccessibilityrating && x+2<=7 && y+1<=7 && accessibilityratings[x+2][y+1]!=9)
	{
		tiemoves[2] = 1;
	
	}
	if(x+2<=7 && y+1<=7 && accessibilityratings[x+2][y+1]<lowestaccessibilityrating && accessibilityratings[x+2][y+1]!= 9)
	{
		cout<<"Lowest AR is "<<accessibilityratings[x+2][y+1]<<endl;
		lowestaccessibilityrating = accessibilityratings[x+2][y+1];
		movedescriptionnumber = 3;
	
	}
	cout<<"x+1, y+2 = "<<x+1<<","<<y+2<<"\n";
	if(accessibilityratings[x+1][y+2] == lowestaccessibilityrating && x+1<=7 && y+2<=7 && accessibilityratings[x+1][y+2] != 9)
	{
		tiemoves[3] = 1;
	
	}
	if(x+1<=7 && y+2<=7 && accessibilityratings[x+1][y+2]<lowestaccessibilityrating && accessibilityratings[x+1][y+2]!= 9)
	{
	
		cout<<"Lowest AR is "<<accessibilityratings[x+1][y+2]<<endl;
		lowestaccessibilityrating = accessibilityratings[x+1][y+2];
		movedescriptionnumber = 4;
	}
	cout<<"x-1, y+2 = "<<x-1<<","<<y+2<<"\n";
	if(accessibilityratings[x-1][y+2] == lowestaccessibilityrating && x-1>=0 && y+2<=7 && accessibilityratings[x-1][y+2] != 9)
	{
		tiemoves[4] = 1;
	
	
	}
	if(x-1>=0 && y+2<=7 && accessibilityratings[x-1][y+2]<lowestaccessibilityrating && accessibilityratings[x-1][y+2] != 9)
	{
		cout<<"Lowest AR is "<<accessibilityratings[x-1][y+2]<<endl;
		lowestaccessibilityrating = accessibilityratings[x-1][y+2];
		movedescriptionnumber = 5;
	
	}
	cout<<"x-2, y+1 = "<<x-2<<","<<y+1<<"\n";
	if(accessibilityratings[x-2][y+1] == lowestaccessibilityrating && x-2>=0 && y+1<=7 && accessibilityratings[x-2][y+1]!=9)
	{
		tiemoves[5] = 1;
	}
	if(x-2>=0 && y+1<=7 && accessibilityratings[x-2][y+1]<lowestaccessibilityrating && accessibilityratings[x-2][y+1]!= 9)
	{
		cout<<"Lowest AR is "<<accessibilityratings[x-2][y+1]<<endl;
		lowestaccessibilityrating = accessibilityratings[x-2][y+1];
		movedescriptionnumber = 6;
	}
	cout<<"x-2, y-1 = "<<x-2<<","<<y-1<<"\n";
	if(accessibilityratings[x-2][y-1] == lowestaccessibilityrating && x-2>=0 && y-1>=0 && accessibilityratings[x-2][y-1]!= 9)
	{
		tiemoves[6] = 1;
	}
	if(x-2>=0 && y-1>=0 && accessibilityratings[x-2][y-1]<lowestaccessibilityrating && accessibilityratings[x-2][y-1] != 9)
	{
		cout<<"Lowest AR is "<<accessibilityratings[x-2][y-1]<<endl;
		lowestaccessibilityrating = accessibilityratings[x-2][y-1];
		movedescriptionnumber = 7;
	}
	cout<<"x-1, y-2 = "<<x-1<<","<<y-2<<"\n";
	if(accessibilityratings[x-1][y-2] == lowestaccessibilityrating && x-1>=0 && y-2>=0 && accessibilityratings[x-1][y-2] != 9)
	{
		tiemoves[7] = 1;
	}
	if(x-1>=0 && y-2>=0 && accessibilityratings[x-1][y-2]<lowestaccessibilityrating && accessibilityratings[x-1][y-2]!= 9)
	{
		cout<<"Lowest AR is "<<accessibilityratings[x-1][y-2]<<endl;
		lowestaccessibilityrating = accessibilityratings[x-1][y-2];
		movedescriptionnumber = 8;
	
	}
	for(int Z = 1; Z<8; Z++)
	{
		if(tiemoves[Z] == 1)
		{
			equivalentmoves = 1;
		}
	
	}
	if(equivalentmoves == 1)
	{
		int Recursivelowest = 10;//used to determine the ability to get to a square with a low accessiblity rating the can be moved to
		if(x+1<=7 && y-2 >= 0 && tiemoves[0] == 1 && getaccessibilityrating(x+1, y-2)<Recursivelowest && accessibilityratings[x+1][y-2]!=9)
		{
			cout<<"Case tiemoves0\n";
			Recursivelowest = getaccessibilityrating(x+1, y-2);
			movedescriptionnumber = 1;
		}
		if(x+2<= 7 && y-1>=0 && tiemoves[1] == 1 && getaccessibilityrating(x+2, y-1)<Recursivelowest && accessibilityratings[x+2][y-1]!=9)
		{
			cout<<"Case tiemoves1\n";
			Recursivelowest = getaccessibilityrating(x+2, y-1);
			movedescriptionnumber = 2;
		}
		if(x+2<=7 && y+1<= 7 && tiemoves[2] == 1 && getaccessibilityrating(x+2, y+1)<Recursivelowest && accessibilityratings[x+2][y+1]!=9)
		{
			cout<<"Case tiemoves2\n";
			Recursivelowest = getaccessibilityrating(x+2, y+1);
			movedescriptionnumber = 3;
		}
		if(x+1<= 7 && y+2<= 7 && tiemoves[3] == 1 && getaccessibilityrating(x+1, y+2)<Recursivelowest && accessibilityratings[x+1][y+2]!=9)
		{
			cout<<"Case tiemoves3\n";
			Recursivelowest = getaccessibilityrating(x+1, y+2);
			movedescriptionnumber = 4;
		}
		if(x-1>= 0 && y+2<=7 && tiemoves[4] == 1 && getaccessibilityrating(x-1, y+2)<Recursivelowest && accessibilityratings[x-1][y+2]!=9)
		{
			cout<<"Case tiemoves4\n";
			Recursivelowest = getaccessibilityrating(x-1, y+2);
			movedescriptionnumber = 5;
		}
		if(x-2>= 0 && y+1<=7 && tiemoves[5] == 1 && getaccessibilityrating(x-2, y+1)<Recursivelowest && accessibilityratings[x-2][y+1]!=9)
		{
			cout<<"Case tiemoves5\n";
			Recursivelowest = getaccessibilityrating(x-2, y+1);
			movedescriptionnumber = 6;
		
		}
		if(x-2>= 0 && y-1>= 0 && tiemoves[6] == 1 && getaccessibilityrating(x-2, y-1)<Recursivelowest && accessibilityratings[x-2][y-1]!=9)
		{
			cout<<"Case tiemoves6\n";
			Recursivelowest = getaccessibilityrating(x-2, y-1);
			movedescriptionnumber = 7;
		
		}
		if(x-1>=0 && y-2>=0 && tiemoves[7] == 1 && getaccessibilityrating(x-1, y-2)<Recursivelowest && accessibilityratings[x-1][y-2]!=9)
		{
			cout<<"Case tiemoves7\n";
			Recursivelowest = getaccessibilityrating(x-1, y-2);
			movedescriptionnumber = 8;
		
		}
	}
	return movedescriptionnumber;
}

class knight
{
private:
	int horizontal;
	int vertical;
	int counter;
public:
	knight()//defaultconstructor
	{
		sethorizontal(4);
		setvertical(3);
		setcounter(1);
		board[horizontal][vertical] = counter;
	
	
	}
	knight(int hrz, int vrt)
	{
		sethorizontal(hrz);
		setvertical(vrt);
		setcounter(1);
		board[horizontal][vertical] = counter;
	}
	void sethorizontal(int x)
	{
		horizontal = x;
	
	}
	int gethorizontal()
	{
		return horizontal;
	
	
	}
	void setcounter(int count)
	{
		counter = count;
	
	}
	int getcounter()
	{
		return counter;
	
	}
	void setvertical(int y)
	{
		vertical = y;
	}
	int getvertical()
	{
		return vertical;
	
	}
	void Eastofnorth()//the XofX methods are the 8 possible knight movement patterns
	{
		
		if(vertical-2>=0 && horizontal+1<=7 && board[horizontal+1][vertical-2]== 0)
		{
			

			vertical-=2;
			horizontal+=1;

			counter++;
			board[horizontal][vertical] = counter;
			

			displayboard();

		}
	}
	void Northofeast()
	{
		if(horizontal+2<=7 && vertical-1>=0 && board[horizontal+2][vertical-1]== 0)
		{
		

			horizontal+=2;
			vertical-=1;

			
			counter++;
			board[horizontal][vertical] = counter;

			displayboard();
			
			
		}	
	}
	void Southofeast()
	{
		if(horizontal+2<=7 && vertical+1<=7 && board[horizontal+2][vertical+1]== 0)
		{
			
			horizontal+=2;
			vertical+=1;

			
			counter++;
			board[horizontal][vertical] = counter;

			displayboard();

			
		
		}
	}
	void Eastofsouth()
	{
		if(vertical+2<=7 && horizontal+1<=7 && board[horizontal+1][vertical+2]== 0)
		{
			
		

			vertical+=2;
			horizontal+=1;
	
			counter++;
			board[horizontal][vertical] = counter;

			displayboard();

		}
	}
	void Westofsouth()
	{
		if(vertical+2<=7 && horizontal-1>=0 && board[horizontal-1][vertical+2]== 0)
		{
			
		

			vertical+=2;
			horizontal-=1;

			counter++;
			board[horizontal][vertical] = counter;

			displayboard();
		}
	
	}
	void Southofwest()
	{
		if(horizontal-2>=0 && vertical+1<=7 && board[horizontal-2][vertical+1]== 0)
		{
			
			

			horizontal-=2;
			vertical+=1;

			counter++;
			board[horizontal][vertical] = counter;

			displayboard();
		}
	
	
	}
	void Northofwest()
	{
		if(horizontal-2>=0 && vertical-1>=0 && board[horizontal-2][vertical-1]== 0)
		{
			

			horizontal-=2;
			vertical-=1;

			counter++;
			board[horizontal][vertical] = counter;
		
			displayboard();
		}
	}
	void Westofnorth()
	{
		if(horizontal-1>=0 && vertical-2>=0 && board[horizontal-1][vertical-2]== 0)
		{
			
			

			horizontal-=1;
			vertical-=2;

			counter++;
			board[horizontal][vertical] = counter;

			displayboard();
		}
	
	}
	void move()//It searches in a clockwise pattern for the one with the lowest accessibility rating, checking tied squares for the lowest rating to find what's more practical
	{
			cout<<"Returned number from LAR is "<<lowestaccessibilityrating(gethorizontal(), getvertical())<<endl;
			switch(lowestaccessibilityrating(gethorizontal(), getvertical()))
			{
			
			case 1:
				Eastofnorth();
				break;
			case 2:
				Northofeast();
				break;
			case 3:
				Southofeast();
				break;
			case 4:
				Eastofsouth();
				break;
			case 5:
				Westofsouth();
				break;
			case 6:
				Southofwest();
				break;
			case 7:
				Northofwest();
				break;
			case 8:
				Westofnorth();
				break;
			default:
				cout<<"SOMETHING IS TERRIBLY WRONG\n";	
			}
		
			displayAR();
		
	
	
	
	
	}
};
void alltours()//a method of bruteforcing tours not currently in use
{
	int tours = 1;
	for(int x = 0; x<6; x++)//this double for loop cycles through the coordinates
	{
		for(int y = 0; y<6; y++)
		{
			for(int q = 0; q<8; q++)//this double for loop and the following one reset the tours
			{
				for(int r = 0; r<8; r++)
				{
			
				accessibilityratings[q][r] = 0;	
				}
			
			}
			for(int A = 0; A<8; A++)
			{
				for(int B = 0; B<8; B++)
				{
			
					board[A][B] = 0;	
				}
			
			}
			int counter = 1;
			knight wanderer(x,y);
			displayAR();
			displayboard();
			while(wanderer.getcounter()<64)
			{
			wanderer.move();
			}
			cout<<"End of tour "<<tours<<"\n";
			tours++;
		}
	}
			



}
int main()
{
	
	int counter = 1;//now that I think about it I'm not sure this is necessary
	knight wanderer(4,5);//instantiates a knight at 4,5
	displayAR();//displays the shadow board revealing accessibility values
	displayboard();//displays the board
	while(wanderer.getcounter()<64)//makes the knight go about his tour
	{
		wanderer.move();
	}

	

	
	
	
	







}