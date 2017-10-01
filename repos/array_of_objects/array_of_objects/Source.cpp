/* English distance example: arrays of objects */
#include<iostream>
#include<string>
using namespace std;

class Distance	// define a class
{
private:
	int feet; double inches;
public:
	Distance() : feet(0), inches(0) {}

	void getdist() // get data from user
	{
		cout << "Enter feet: "; cin >> feet; cout << "Enter inches: "; cin >> inches;
	}

	void showdist() { cout << feet << "\'-" << inches << "\""; }

	void sum() { cout << "Total Distance: " << (feet * 12 + inches); }
};

int main()
{
	Distance dist[100]; 	// define an array of objects of class Distance

	int n = 0;		// count the entries
	char ans;		// user response y/n	

	do			// get distances from user
	{
		cout << "enter distance" << endl;
		dist[n++].getdist();	// call the class member function to store the distance in object dist[n] and increment of n
		cout << "continue? (y/n): "; cin >> ans;
	} while (ans != 'n');

	for (int i = 0; i<n; i++) // display entered distances 
	{
		cout << "distance " << i << endl;
		dist[i].showdist(); cout << endl;// call the class member function to show the distance of object dist[i]
		dist[i].sum(); cout << endl;
	}

	system("pause");
}


