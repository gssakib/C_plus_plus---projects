/* static local variables */
#include<iostream>
#include<string>
using namespace std;

// function declaration 
double getavg(double val);

int main()
{
	double val = 1;
	while (val != 0)
	{
		cout << "Enter a real number: ";
		cin >> val;
		cout << "The averaged value is: " << getavg(val) << endl;
	}
	system("pause");
}

// function definition 
double getavg(double val)		// function declarator 
{
	static double sum = 0., count = 0.;
	sum += val; count++;
	return sum / (count + 1.e-19);
}

