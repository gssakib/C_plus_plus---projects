/* Better first array */
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

void max(int a[]) {
	cout << "Max Length: " << sizeof(a) << endl;
	for (int  i = 0; i < sizeof(a); i++)
	{
		cout << a[i] << " position is: " << i << endl;


	}

}

int main()
{
	const int N = 4;	// specify the size of array using a const int N
	int a[N];		// define an array 'a' with size N

	cout << "Enter " << N << " values: ";
	for (int i = 0; i<N; i++) cin >> a[i]; 	// get the value of the array elemet with array index i,
											// which starts from 0

	cout << "The values you entered: ";
	for (int i = 0; i < N; i++) cout << " " << a[i] << endl;

	cout << endl;


	max(a);
	system("pause");
}


