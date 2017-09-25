#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

class fraction
{

private:
	int a;
	int b;
	int c;
	int d;

public:

	void In(string frac1, string frac2) {
		string delimeter = "/";

		//cout << stoi(frac1.substr(0)) << endl;
		setter(stoi(frac1.substr(0)), stoi(frac1.substr(2)), stoi(frac2.substr(0)), stoi(frac2.substr(2)));

	}
	void setter(int e,  int f, int g, int h) {
		a = e;
		b = f;
		c = g;
		d = h;
		//cout << a;
		//cout << b;
		//cout << c;
		//cout << d;


	}

	void sum() {

		int num = a*d + b*c;
	
		int denom = b*d;

		cout << "result: " << num << "/" << denom << endl;
	}
};



int main() {
	string frac1;
	string frac2;
	bool decision = true;
	fraction f;
	while (decision)
	{
		
		cout << "Enter 1st fraction: "; 
		
	   getline(cin, frac1);

		cout << endl;
		cout << "Enter 2nd fraction: ";
		getline(cin, frac2);

		cout << endl;

		f.In(frac1, frac2);

		f.sum();
		cout << endl;

		cout << "Do you want to do another one ? Enter 1 for yes, and 0 for no..........";
		

		cin >> decision;
		cout << endl;
		
	}


	



	system("pause");
	
}