/* virtual functions in person example */
#include<iostream>
#include<string>
using namespace std;

// person class. an abstract class. No person objects can ever be created.
class person
{
protected:
	char name[40];
public:
	void getName() { cout << "Enter name: "; cin >> name; }
	void putName() { cout << "Name: " << name << endl; }
	virtual void getData() = 0; // pure virtual function
	virtual bool isOutstanding() = 0; // pure virtual function
};

class student : public person	// student class
{
private:
	double gpa;	// grade point average
public:
	void getData()	// get student data
	{
		person::getName();
		cout << "Enter GPA: "; cin >> gpa;
	}
	bool isOutstanding()
	{
		return (gpa>3.5) ? true : false;
	}
};


class professor : public person	// professor class
{
private:
	int numPubs;	// number of publications
public:
	void getData()	// get student data
	{
		person::getName();
		cout << "Enter number of publications: "; cin >> numPubs;
	}
	bool isOutstanding()
	{
		return (numPubs>100) ? true : false;
	}
};

int main()
{
	person* persPtr[100];	// array of pointers to person
	int n = 0;
	char choice;

	do
	{
		cout << "Enter student or professor (s/p)? "; cin >> choice;
		if (choice == 's') persPtr[n] = new student;
		else persPtr[n] = new professor;

		persPtr[n++]->getData();

		cout << "Enter another (y/n)? "; cin >> choice;
	} while (choice == 'y');

	for (int j = 0; j<n; j++)
	{
		persPtr[j]->putName();
		if (persPtr[j]->isOutstanding())
			cout << "\tThis person is outstanding\n";
	}
	system("pause");
}

