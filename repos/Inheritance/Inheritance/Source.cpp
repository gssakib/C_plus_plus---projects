/* Stack example: overriding functions */
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<string>
using namespace std;

class Stack
{
protected:
	static const int MAX = 3;
	int st[MAX];	// stack for an array of integers 
	int top; 	// index number of top of the stack
public:
	Stack() { top = 0; }

	void push(int var) { st[top++] = var; }  	// put number on stack: ++top: increment, then assign var to st
	int pop() { return st[--top]; } 		// take number off stack: top--: retrun the var at top, then decrement
	int indx() { return top - 1; } 		// retrun top 

};

class Stack2 : public Stack
{
public:
	void push(int var)	// put number on stack 
	{
		if (top > MAX - 1) { cout << "Error: stack is full \n"; exit(1); } // Error: stack is full
		Stack::push(var); //call push() in Stack class
	}

	int pop()	// take number off stack 
	{
		if (top < 1) { cout << "\nError: stack is empty \n"; exit(1); } // Error: stack is empty
		return Stack::pop(); //call pop() in Stack class
	}
};


int main()
{
	Stack2 s1;

	s1.push(11);
	s1.push(22);
	s1.push(33);
	s1.push(44);

	cout << "value at " << s1.indx() << ": " << s1.pop() << endl;
	cout << "value at " << s1.indx() << ": " << s1.pop() << endl;
	cout << "value at " << s1.indx() << ": " << s1.pop() << endl;
	cout << "value at " << s1.indx() << ": " << s1.pop() << endl;

	system("pause");
}


