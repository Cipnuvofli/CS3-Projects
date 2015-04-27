//Solution to Homework 5
//CSCE 2050, Fall 2011
//Student: Joseph Penrod
//Instructor: Dr. Xiaohui Yuan



#include<iostream>
#include<iomanip>
using namespace std;


char maze[12][12] = {{'#','#','#','#','#','#','#','#','#','#','#','#'},
{'#','.','.','.','#','.','.','.','.','.','.','#'},
{'.','.','#','.','#','.','#','#','#','#','.','#'},
{'#','#','#','.','#','.','.','.','.','#','.','#'},
{'#','.','.','.','.','#','#','#','.','#','.','.'},
{'#','#','#','#','.','#','.','#','.','#','.','#'},
{'#','.','.','#','.','#','.','#','.','#','.','#'},
{'#','#','.','#','.','#','.','#','.','#','.','#'},
{'#','.','.','.','.','.','.','.','.','#','.','#'},
{'#','#','#','#','#','#','.','#','#','#','.','#'},
{'#','.','.','.','.','.','.','#','.','.','.','#'},
{'#','#','#','#','#','#','#','#','#','#','#','#'}};
int firstOBcorridor = 0;//used to determine if the exit is reached
char walker = 'x';
void displaymaze()
{
	for(int x = 0; x<12; x++)
	{
		for(int y = 0; y<12; y++)
		{
			cout<<maze[y][x];//for some reazon this needs to be reversed for everthing to work properly

		}
		cout<<"\n";
	}
	cout<<"\n";
}

int junctionchecker(char area[][12], int x, int y)
{
	if(area[x+1][y] == '.' && area[x-1][y] == '.' && area[x][y+1] == '.' && area[x][y-1] == '.')
	{
		
			return 1;
	}
	else if(area[x+1][y] == '#' && area[x-1][y] == '#' && y-1<0 || y+1>11)
	{
			
			
			
				return 16;
			
	}
	else if(area[x][y+1] == '#' && area[x][y-1] == '#' && x-1<0 || x+1>11)
	{
			
				
				return 17;
			
	}
	else if(area[x+1][y] == '#' && area[x-1][y] == '.' && area[x][y+1] == '.' && area[x][y-1] == '.')
	{
			
			return 2;
	
	}
	else if(area[x+1][y] == '#' && area[x-1][y] == '#' && area[x][y+1] == '.' && area[x][y-1] == '.')
	{
	
			return 3;
		
	}
	else if(area[x+1][y] == '#' && area[x-1][y] == '.' && area[x][y+1] == '#' && area[x][y-1] == '.')
	{
			
			return 4;
	
	}
	else if(area[x+1][y] == '#' && area[x-1][y] == '.' && area[x][y+1] == '.' && area[x][y-1] == '#')
	{
			
			return 5;
	
	}
	else if(area[x+1][y] == '#' && area[x-1][y] == '#' && area[x][y+1] == '.' && area[x][y-1] == '#')
	{
			
			return 6;
	
	}
	else if(area[x+1][y] == '#' && area[x-1][y] == '.' && area[x][y+1] == '#' && area[x][y-1] == '#')
	{
		
			return 7;
	
	}
	else if(area[x+1][y] == '#' && area[x-1][y] == '#' && area[x][y+1] == '#' && area[x][y-1] == '.')
	{
		
			return 8;
	
	}
	else if(area[x+1][y] == '.' && area[x-1][y] == '#' && area[x][y+1] == '.' && area[x][y-1] == '.')
	{
			
			return 9;
	}
	else if(area[x+1][y] == '.' && area[x-1][y] == '#' && area[x][y+1] == '#' && area[x][y-1] == '.')
	{
		
			return 10;
	}
	else if(area[x+1][y] == '.' && area[x-1][y] == '#' && area[x][y+1] == '.' && area[x][y-1] == '#')
	{
			
			return 11;
	}
	else if(area[x+1][y] == '.' && area[x-1][y] == '#' && area[x][y+1] == '#' && area[x][y-1] == '#')
	{
			
			return 12;	
	}
	else if(area[x+1][y] == '.' && area[x-1][y] == '.' && area[x][y+1] == '#' && area[x][y-1] == '.')
	{
		
			return 13;
	}
	else if(area[x+1][y] == '.' && area[x-1][y] == '.' && area[x][y+1] == '#' && area[x][y-1] == '#')
	{
			
			return 14;
	}
	else if(area[x+1][y] == '.' && area[x-1][y] == '.' && area[x][y+1] == '.' && area[x][y-1] == '#')
	{
			
			return 15;
	}
	return -1;
	


}
void mazeTraverse(char area[][12], int x, int y, int previousx, int previousy)
{

	
	maze[x][y] = walker;
	displaymaze();
	switch(junctionchecker(area, x, y))
	{
	case 1://four way junction
		if(previousy == y+1)
		{
			maze[x][y] = '.';
			mazeTraverse(maze, x+1,y, x, y);
		}
		else if(previousy == y-1)
		{
			maze[x][y] = '.';
			mazeTraverse(maze, x-1, y, x, y);
		}
		else if(previousx == x+1)
		{
			maze[x][y] = '.';
			mazeTraverse(maze, x, y-1, x, y);
		}
		else if(previousx == x-1)
		{
			maze[x][y] = '.';
			mazeTraverse(maze, x, y+1, x, y);
		}
		break;
	case 2://right facing t junction
		if(previousx == x-1)
		{
		maze[x][y] = '.';
		mazeTraverse(maze, x, y+1, x, y);
		}
		else if(previousy == y-1)
		{
		maze[x][y] = '.';
		mazeTraverse(maze, x-1, y, x, y);
		}
		else if(previousy == y+1)
		{
		maze[x][y] = '.';
		mazeTraverse(maze, x, y-1, x, y);
		}
		break;
	case 3://vertical corridor
	
		if(previousy == y+1)
		{
			maze[x][y] = '.';
			mazeTraverse(maze, x, y-1, x, y);
		}
		else if(previousy == y-1)
		{
			maze[x][y] = '.';
			mazeTraverse(maze, x, y+1, x, y);
		}
		break;
	case 4:// reverse L path
		if(previousy == y-1)
		{
			maze[x][y] = '.';
			mazeTraverse(maze, x-1, y, x, y);
		}
		else if(previousx == x-1)
		{
			maze[x][y] = '.';
			mazeTraverse(maze, x, y-1, x, y);
		}
		break;
	case 5:// reverse r path
		if(previousy == y+1)
		{
			maze[x][y] = '.';
			mazeTraverse(maze, x-1, y, x, y);
		}
		else if(previousx == x-1)
		{
			maze[x][y] = '.';
			mazeTraverse(maze, x, y+1, x, y);
		}
		break;
	case 6://upward facing dead end
		maze[x][y] = '.';
		mazeTraverse(maze, x, y+1, x, y);
		break;
	case 7://rightward facing dead end
		maze[x][y] = '.';
		mazeTraverse(maze, x-1, y, x, y);
		break;
	case 8://downward facing dead end
		maze[x][y] = '.';
		mazeTraverse(maze, x, y-1, x, y);
		break;
	case 9://left facing t junction
		if(previousx == x+1)
		{
		maze[x][y] = '.';
		mazeTraverse(maze, x, y-1, x, y);
		}
		else if(previousy == y+1)
		{
		maze[x][y] = '.';
		mazeTraverse(maze, x+1, y, x, y);
		}
		else if(previousy == y-1)
		{
		maze[x][y] = '.';
		mazeTraverse(maze, x, y+1, x, y);
		}
		break;
	case 10://L  path
		if(previousy == y-1)
		{
			maze[x][y] = '.';
			mazeTraverse(maze, x+1, y, x, y);
		}
		else if(previousx == x+1)
		{
			maze[x][y] = '.';
			mazeTraverse(maze, x, y-1, x, y);
		}	
		break;
	case 11://r path
		if(previousy == y+1)
		{
			maze[x][y] = '.';
			mazeTraverse(maze, x+1, y, x, y);
		}
		else if(previousx == x+1)
		{
			maze[x][y] = '.';
			mazeTraverse(maze, x, y+1, x, y);
		}
		break;
	case 12://leftward facing dead end
		maze[x][y] = '.';
		mazeTraverse(maze, x+1, y, x, y);
		break;
	case 13://downward facing T junction
		if(previousy == y-1)
		{
		maze[x][y] = '.';
		mazeTraverse(maze, x-1, y, x, y);
		}
		else if(previousx == x+1)
		{
		maze[x][y] = '.';
		mazeTraverse(maze, x, y-1, x, y);
		
		}
		else if(previousx == x-1)
		{
		maze[x][y] = '.';
		mazeTraverse(maze, x+1, y, x,y);
		}
		break;
	case 14://horizontal corridor
		if(previousx == x+1)
		{
			maze[x][y] = '.';
			mazeTraverse(maze, x-1, y, x, y);
		}
		else if(previousx == x-1)
		{
			maze[x][y] = '.';
			mazeTraverse(maze, x+1, y, x, y);
		}
		break;
	case 15://upward facing T junction
		if(previousy == y+1)
		{
		maze[x][y] = '.';
		mazeTraverse(maze, x+1, y, x, y);
		}
		else if(previousx == x-1)
		{
		maze[x][y] = '.';
		mazeTraverse(maze, x, y+1, x, y);
		}
		else if(previousx == x+1)
		{
		maze[x][y] = '.';
		mazeTraverse(maze, x-1, y, x, y);
		}
		break;
	case 16://vertical corridor that exits maze 
	
		if(firstOBcorridor == 0)
		{
			firstOBcorridor = 1;
			
			if(previousy == y+1)
			{
				maze[x][y] = '.';
				mazeTraverse(maze, x, y-1, x, y);
			}
			else if(previousy == y-1)
			{
				maze[x][y] = '.';
				mazeTraverse(maze, x, y+1, x, y);
			}
		}
		break;
	case 17://horizontal corridor that exits maze

	
		if(firstOBcorridor == 0)
		{
			firstOBcorridor = 1;
			if(previousx == x+1)
			{
				maze[x][y] = '.';
				mazeTraverse(maze, x-1, y, x, y);
			}
			else if(previousx == x-1)
			{
				maze[x][y] = '.';
				mazeTraverse(maze, x+1, y, x, y);
			}
		}
		break;
		
	}
		
}

int main()//the mazetraverse method here implements the always go right algorithm
{
	
	mazeTraverse(maze, 2, 0, 2, -1);

}

