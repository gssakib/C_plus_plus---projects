/* Parsing example: evaluates arithmetic expressions composed of 1-digit numbers */
#include<iostream>
#include<cstring> 	// for strlen(), etc
using namespace std;
const int LEN = 80; 	// length of expressions, in characters
const int MAX = 40; 	// size of stack

class Stack
{
protected:
	char st[MAX];	// stack for an array of integers 
	int top; 	// index number of top of the stack
public:
	Stack() { top = 0; }

	void push(char var) { st[++top] = var; }  // put number on stack: ++top: increment, then assign var to st
	int pop() { return st[top--]; } 		// take number off stack: top--: retrun the var at top, then decrement
	int gettop() { return top; } 		// retrun top 
};

class Stack2 : public Stack
{
public:
	void push(char var)	// put number on stack 
	{
		if (top > MAX - 1) { cout << "Error: stack is full \n"; exit(1); } // Error: stack is full
		Stack::push(var); //call push() in Stack class
	}

	char pop()	// take number off stack 
	{
		if (top < 1) { cout << "\nError: stack is empty \n"; exit(1); } // Error: stack is empty
		return Stack::pop(); //call pop() in Stack class
	}
};

class express 		// expression class
{
private:
	Stack2 s;	// stack for analysis
	char* pStr;	// pointer to input string
	int len;	// length of input string		
public:
	express(char* ptr)		// constructor
	{
		pStr = ptr;		// set pointer to string
		len = strlen(pStr);	// set length
	}
	void parse();			// parse the input string
	int solve();			// evaluate the stack
};

void express::parse()	// add items to stack
{
	char ch; 	// char from input string
	char lastval;	// last value
	char lastop;	// last operator

	for (int j = 0; j<len; j++)	// for each input character
	{
		ch = pStr[j];		// get next character
		if (ch >= '0' && ch <= '9')
		{
			s.push(ch - '0');	// if digit, save numerical value 
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			if (s.gettop() == 1) s.push(ch); 	// if first OP, push
			else 				// not first OP
			{
				lastval = s.pop();	// get previous digit
				lastop = s.pop();	// get previous OP
									// if this is * or / AND last OP was + or - 
				if ((ch == '*' || ch == '/') && (lastop == '+' || lastop == '-'))
				{
					s.push(lastop);	// restore last two pops
					s.push(lastval);
				}
				else 			// in all other cases 
				{
					switch (lastop)
					{
					case '+': s.push(s.pop() + lastval); break;
					case '-': s.push(s.pop() - lastval); break;
					case '*': s.push(s.pop()*lastval); break;
					case '/': s.push(s.pop() / lastval); break;
					default: cout << "\nUnknown oper_parse\n"; exit(1);
					} // end swith
				} // end else, in all other cases
				s.push(ch);		// push current OP on stack
			} // end else, not first operator
		} // end else if, it is an operator 
		else { cout << "\nUnknown character\n"; exit(1); }	// Not known character
	} // end for
}

int express::solve() 	// remove items from stack
{
	char lastval; 	// previous value
	char last_last_val;
	char symb;
	while (s.gettop()>1)
	{
		lastval = s.pop();
		symb = s.pop();
		last_last_val = s.pop();
		switch (symb)
		{
		case '+': s.push(last_last_val + lastval); break;
		case '-': 

			switch (s.pop())
			{

			case '-':
				s.push('+');
				s.push(last_last_val + lastval);
			default:
				
				break;
			}





		case '*': s.push(last_last_val*lastval); break;
		case '/': s.push(last_last_val / lastval); break;
		default: cout << "\nUnknown oper_solve\n"; exit(1);
		}
	}

	return int(s.pop());	// last item on stack is the ans
}

int main()
{
	char ans;		// 'y' or 'n'
	char string[LEN];	// input string from user
	cout << "\nEnter an arithmetic expression"
		"\nof the form 2+3*4/3-2."
		"\nNo number may have more than one digit."
		"\nDon’t use any spaces or parentheses.";

	do {
		cout << "\nEnter expresssion: ";
		cin >> string; //input from user
		express* eptr = new express(string); //make expression
		eptr->parse(); //parse it
		cout << "\nThe numerical value is: "
			<< eptr->solve(); //solve it
		delete eptr; //delete expression
		cout << "\nDo another (Enter y or n)? ";
		cin >> ans;
	} while (ans == 'y');

	system("pause");
}



