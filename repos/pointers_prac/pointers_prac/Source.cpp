/* pointers to pointers: sorting person based on names */
#include<iostream>
#include<string>
using namespace std;

class person // class of persons
{
protected:
	string name; // name of person
public:
	void setname() { cout << "Enter name: "; cin >> name; }
	void printname() { cout << endl << name; }
	string getname() { return name; }
};

void order(person** pp1, person** pp2)	// order two pointers
{
	if ((*pp1)->getname() > (*pp2)->getname())
	{
		person* tempptr = *pp1; // swap twp pointers
		*pp1 = *pp2; *pp2 = tempptr;
	}
}

void bsort(person** pp, int n)	// sort 'pointers to persons'
{
	for (int i = 0; i<n; i++)
		for (int j = i + 1; j<n; j++) order(pp + i, pp + j);
}
int main()
{
	person* persPtr[100]; 	// array of pointers to person
	int n = 0;		// number of persons in array
	char choice;		// inpur char

	do			// put persons in array
	{
		persPtr[n] = new person;
		persPtr[n]->setname();
		n++;
		cout << "Continue (y/n)?"; cin >> choice;
	} while (choice != 'n');

	cout << "unsorted list: ";
	for (int i = 0; i<n; i++) persPtr[i]->printname();

	bsort(persPtr, n);

	cout << "\n\nsorted list: ";
	for (int i = 0; i<n; i++) persPtr[i]->printname();
	cout << endl;

	system("pause");
}


