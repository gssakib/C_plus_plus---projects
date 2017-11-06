/* computing shape area using virtual function */
#include<iostream>
#include<string>
using namespace std;

// shape class. an abstract class. No shape objects can ever be created because of pure virtual function
class shape
{
protected:
	double dimen; // to store key shape dimensions
	double const PI = 3.142;
public:
	
	virtual void input() = 0; // pure virtual function to get key shape dimensions
	virtual void compute_area() = 0; // pure virtual function to compute area of shape
};


class square : public shape	// child square class
{
private:
	// no private variable needed
public:
	void input()	// get square width
	{
	//storing in dimen variable from parent class
		cout << "Enter width of square: "; cin >> dimen;
	}
	void compute_area() // compute area of square (area = width^2)
	{
		cout << "The area of square is: " << (shape::dimen*shape::dimen); //using dimen variable from parent class
	}
};

class circle : public shape	// child circle class
{
private:
	// no private variable needed
public:
	void input()	// get circle radius
	{
		//storing in dimen variable from parent class
		cout << "Enter radius of square: "; cin >> dimen;
	}
	void compute_area()  // compute area of square (area = PI*radius^2)
	{
		cout << "The area of circle is: " << (shape::dimen*shape::dimen*shape::PI); //using dimen variable from parent class
	}
};

int main()
{
	shape* ptrsp[100];	// array of pointers shape parent class
	int n = 0; //index for array
	char choice; // to store choice

	//loop to fill array of shapes
	do
	{
		cout << "Enter square or circle (s/c)? "; cin >> choice; //entering choice 
		if (choice == 's') {
			ptrsp[n] = new square; //instantiating square object

		} else if (choice == 'c') {
			ptrsp[n] = new circle; //instantiating circle object
		}
		else { //if improper choice, then the program quits after giving warning.
			cout << "Not valid choice.Try again later." << endl;
			system("pause");
			exit(0);
		}
		ptrsp[n++]->input(); //get dimension using overriden virtual functions

		cout << "Enter another shape (y/n)? "; cin >> choice; //option to continue filling array
	} while (choice == 'y');
	cout << endl;
	
	
	//print out area of the shapes from the array using overriden compute area function
	for (int j = 0; j<n; j++)
	{
		ptrsp[j]->compute_area();
		cout << endl;
		
	}
	cout << endl;
	system("pause");
}