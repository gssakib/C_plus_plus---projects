/* return structure variables: add english distances */
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

struct Distance // english distance structure
{
	int feet; float inches;
};

// declarations
Distance addengl(Distance d1, Distance d2);
void engldisp(Distance d);

int main()
{
	Distance d1, d2, d3; // define three Distance structure varaibles
						 // get two distances from user
	cout << "Enter feet: "; cin >> d1.feet; cout << "Enter inches: "; cin >> d1.inches;
	cout << "Enter feet: "; cin >> d2.feet; cout << "Enter inches: "; cin >> d2.inches;
	d3 = addengl(d1, d2); // d3 = d1+d2 
	engldisp(d1); cout << " + "; engldisp(d2); cout << " = "; engldisp(d3); cout << endl;

	system("pause");
}

// add two Distance variables, and retrun the sum 
Distance addengl(Distance d1, Distance d2)		// function declarator 
{
	double totalinches = d1.feet * 12 + d2.feet * 12 + d1.inches + d2.inches;

	Distance d3;
	d3.feet = totalinches / 12; d3.inches = fmod(totalinches, 12);
	return d3;
}

// Display distance in feet and inches
void engldisp(Distance d)
{
	cout << d.feet << "\'-" << d.inches << "\"";
}
