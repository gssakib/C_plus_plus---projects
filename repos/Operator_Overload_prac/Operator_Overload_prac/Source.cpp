/* creates safe arrays using overload [] and return by reference */
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

const int LIMIT = 10;
class safearray
{
private:
	int arr[LIMIT];
public:
	int& operator [](int n)		// access elements using overloade [] returning by reference
	{
		if (n<0 || n>LIMIT) { cout << "Index out of bounds \n"; exit(1); }
		return arr[n];
	}
};

int main()
{
	safearray a;
	int i;
	for (i = 0; i<LIMIT; i++) { a[i] = i; }	// incert elements

	for (i = 0; i<LIMIT; i++) { cout << a[i]; cout << " "; }	// display elements
	cout << endl;

	system("pause");
}

