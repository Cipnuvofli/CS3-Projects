//Student: Joseph Penrod
//Solution to Programming Homework 3
//CSCE 3110
//Instructor: Dr. Robert Renka

#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool precedencechecker(char compare1, char compare2)//compares 1 and 2, if 2 is something of lower precedence then 1, returns true, otherwise, returns false
{
	switch (compare1)
	{
	case '^':
		if(compare2 == '*'||compare2 == '/'||compare2 == '-'||compare2 == '+'||compare2 == '^')
		{
			return true;
		}
		break;
	case '*':
		if(compare2=='*'||compare2 == '/'||compare2 == '-' ||compare2 == '+')
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case '/':
		if(compare2=='*'||compare2 == '/'||compare2 == '-' ||compare2 == '+')
		{
			return true;
		
		}
		else
		{
			return false;
		}
		break;
	case '+':
		if(compare2 == '+'||compare2 == '-')
		{
		return true;
		}
		else
		{
			return false;
		}
		break;
	case '-':
		if(compare2 == '+'||compare2 == '-')
		{
		return true;
		}
		else
		{
			return false;
		}
		break;

	}

}
bool mismatchedoperandcheck(string expression)//ensures an operator won't be the start or end of an expression, 
{
	stack<char> storage;
	for(int x = 0; x<expression.size(); x++)
	{
		if(expression[x] == '+'||expression[x] == '-'||expression[x] == '*'||expression[x] == '/'||expression[x] == '^')
		{
			
			if(x == 0||x == expression.size()-1)
			{
				return true;
			}
			
		}
	
	
	}

}
bool unbalancedsymbolcheck(string expression)//ensures parentheses and brackets are properly balanced
{
	stack<char> storage;
	for(int x = 0; x<expression.size(); x++)
	{
		if(expression[x] == '['||expression[x] == '(')
		{
			storage.push(expression[x]);
		}
		else if(expression[x] == ')'||expression[x] == ']')
		{
			if(storage.empty() == true)
			{
				cout<<"error\n";
				return true;
			}
			else
			{
				if(expression[x] == ']')
				{
					if(storage.top()!='[')
					{
						cout<<"error\n";
						return true;
					}
					else
					{
						storage.pop();
					}
				}
				else if(expression[x] == ')')
				{
					if(storage.top()!='(')
					{
						cout<<"error\n";
						return true;
					}
					else
					{
						storage.pop();
					}
				}
			}
		}
	}
	if(storage.empty() == false)
	{
		return true;
	}
	return false;

}
string inToPostfix(string expression)//returns the postfix version of an infix expression used as an argument
{
	string postfix;
	stack<char> storage;
	for(int x = 0; x<expression.size(); x++)
	{
		if(expression[x]>=97 && expression[x]<=122)//operands
		{
			postfix = postfix+expression[x];
		}
		else if(expression[x] == ')')
		{
			while(storage.top()!='(')
			{
				postfix = postfix+storage.top();
				storage.pop();
			}
			storage.pop();
		}
		else//+,-,*,/,^,(|(43,45,42,47,40)
		{
			switch(expression[x])
			{
			case '(':
				storage.push(expression[x]);
				break;
			case '^':
				while(!storage.empty() && storage.top()!='(' && precedencechecker(expression[x], storage.top()) == false)
				{
					postfix = postfix+storage.top();
					storage.pop();
				
				}
				storage.push(expression[x]);
				break;
			case '*':
				while(!storage.empty()&&storage.top()!='('&& precedencechecker(expression[x], storage.top()) == false)
				{
					postfix = postfix+storage.top();
					storage.pop();
				}
				storage.push(expression[x]);
				break;
			case '/':
				while(!storage.empty()&&storage.top()!='('&& precedencechecker(expression[x], storage.top()) == false)
				{
					postfix = postfix+storage.top();
					storage.pop();
				
				}
				storage.push(expression[x]);
				break;
			case '+':
				while(!storage.empty()&&storage.top()!='('&& precedencechecker(expression[x], storage.top()) == false)
				{
					postfix = postfix+storage.top();
					storage.pop();
				
				}
				storage.push(expression[x]);
				break;
			case '-':
				while(!storage.empty()&&storage.top()!='('&& precedencechecker(expression[x], storage.top()) == false)
				{
					postfix = postfix+storage.top();
					storage.pop();
				}
				storage.push(expression[x]);
				break;
			default:
				break;
			
			
			
			
			
			
			}
			

			
		}
	}
	while(!storage.empty())
	{
		postfix = postfix+storage.top();
		storage.pop();
	}
	return postfix;

}

int main()
{
	bool isgood = false;
	int sentinel = 0;
	while(sentinel!=1)//This while loop makes it possible to test multiple infix expressions
	{
	string expression;
	stack<char> storage;
	while(isgood == false)//Checks for various errors
	{
		cout<<"Give an expression in the infix format\n";
		cin >> expression;
		if(unbalancedsymbolcheck(expression)== true)
		{
			cout<<"Error in parentheses or bracket usage\n";
		}
		else if(mismatchedoperandcheck(expression) == true)
		{
			cout<<"Syntax error: Mismatched operand"<<endl;
		
		}
		else
		{
			isgood = true;
			
		}
	}
	cout<<"The Postfix version of your expression is: "+inToPostfix(expression)+"\n";//outputs postfix expression
	bool inputverified = false;
		while(inputverified == false)//queries user if they want to enter another expression while testing for errors such as chars
		{
			cout<<"Enter 1 to end program, any other int to continue\n";
			if(!(cin>>sentinel))
			{
				cout<<"Please enter an int\n";
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else
			{
				inputverified = true;
				isgood = false;
			}
		}
	}


}