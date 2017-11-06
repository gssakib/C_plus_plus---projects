/* English distance example: two functions  "bsort" and "order" function are written to sort user-entered
* English distances in an decending order using "pointers to pointers"
* when passing an array of pointers to the sorting fuctions */
#include<iostream>
#include<cmath>
#include<string>
using namespace std;

class Distance	// define a class
{
private:
	int feet;
	double inches;
public:
	Distance() : feet(0), inches(0) {}
	Distance(int ft, double in) : feet(ft), inches(in) {}

	void getdist() // get data from user
	{
		cout << "Enter feet: "; cin >> feet;
		cout << "Enter inches: "; cin >> inches;
	}

	void showdist() // show data
	{
		cout << feet << "\'-" << inches << "\"";
	}

	// function declaration of overloaded <
	bool operator < (Distance) const;
};

// compare this distance with dist2
bool Distance::operator < (Distance dist2) const
{
	double ft = feet + inches / 12;
	double ft2 = dist2.feet + dist2.inches / 12;
	return (ft < ft2) ? true : false;
}

//defining the sorting function
void order(Distance** pp1, Distance** pp2)	// order two pointers
{
	if ((**pp1) < (**pp2))
	{
		Distance* tempptr = *pp1; // swap twp pointers
		*pp1 = *pp2; *pp2 = tempptr;
	}
}

//defining ordering function
void bsort(Distance** pp, int n)	// sort 'pointers to persons'
{
	for (int i = 0; i<n; i++)
		for (int j = i + 1; j<n; j++) order(pp + i, pp + j);
}


int main()
{
	Distance* distPtr[100]; //creating pointer array

	int n = 0;		// number of persons in array
	char choice;		// inpur char

	do			// put persons in array
	{
		distPtr[n] = new Distance; //initializing pointer to array
		distPtr[n]->getdist();  //deferencing function to get distance
		n++;
		cout << "Continue (y/n)?"; cin >> choice;
	} while (choice != 'n');

	cout << "unsorted English distance list: \n";
	//print out unsorted dates
	for (int i = 0; i<n; i++)
	{
		distPtr[i]->showdist();
		cout << endl;
	}

	bsort(distPtr, n); //bubble sort fucntion to sort dates


	//print out sorted dates
	cout << "\n\nsorted list: " << endl;
	for (int i = 0; i < n; i++) {
		distPtr[i]->showdist();
		cout << endl;
	}
		
	cout << endl;


	system("pause");
}


