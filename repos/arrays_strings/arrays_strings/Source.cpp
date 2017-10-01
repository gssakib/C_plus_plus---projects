/* access a charater in a string using at */
#include <iostream>
#include <string>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	char a[80];
	string word;

	cout << "Enter a word: "; cin >> word;

	int wlen = word.length(); // length of a string object

	int i;
	for (i = 0; i<wlen; i++)
	{
		cout << word.at(i); // exception if out-of-bounds
							//cout << word[i]; // no warning if out-of-bounds
	}

	cout << endl;

	word.copy(a, wlen, 0); 	//copy string object to array
	a[wlen] = 0;		// terminate with "\0"
	for (i = 0; i<wlen; i++) cout << a[i]; // no warning if out-of-bounds
	cout << endl;

	cout << "maximum length: " << word.max_size() << endl; // The maximum length the string can reach
	cout << "capacity: " << word.capacity() << endl; // The size of the storage capacity currently allocated for the string
	system("pause");
}


