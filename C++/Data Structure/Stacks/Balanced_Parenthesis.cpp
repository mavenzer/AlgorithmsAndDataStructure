// CPP Program to Check whether for Balanced Parenthesis in a string
// 
#include<bits/stdc++.h>
using namespace std;
// Function to check whether two characters are opening or closing characters are same
bool are_pair(char open,char close)
{
	if(open == '(' && close == ')') return true;
	else if(open == '{' && close == '}') return true;
	else if(open == '[' && close == ']') return true;
	return false;
}
bool are_parantheses_balanced(string expression)
{
	stack<char>  Stk;
	for(int current =0;current<expression.length();current++)
	{
		if(expression[current] == '(' || expression[current] == '{' || expression[current] == '[')
			Stk.push(expression[current]);
		else if(expression[current] == ')' || expression[current] == '}' || expression[current] == ']')
		{
			if(Stk.empty() || !are_pair(Stk.top(),expression[current]))
				return false;
			else
				Stk.pop();
		}
	}
	return Stk.empty() ? true:false;
}

int main()
{
	/*Code to test the function AreParanthesesBalanced*/
	string expression;
	cout<<"Enter an expression:  "; // input expression from STDIN/Console
	cin>>expression;
	if(are_parantheses_balanced(expression))
		cout<<"Balanced\n";
	else
		cout<<"Not Balanced\n";
}