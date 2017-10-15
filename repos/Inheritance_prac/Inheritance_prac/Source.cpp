/* Signed English distance example: inheritance */
#include<iostream>
#include<cmath>
#include<string>
using namespace std;

enum posneg { pos, neg }; 	// for sign in Distance
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

	void showdist() { cout << feet << "\'-" << inches << "\""; } // show dist
};

class signedDistance : protected Distance
{
private:
	posneg sign;	// sign is pos or neg	
public:
	// no-arg ctor; call base ctor; set sign = +
	signedDistance() : Distance() { sign = pos; }
	// 2- or 3-arg ctor;                            call base ctor;      set sign  
	signedDistance(int ft, double in, posneg sg = pos) : Distance(ft, in) { sign = sg; }
	void getdist()	// get distance from user
	{
		Distance::getdist();  // call base getdist()
		char ch;		// get sign from user 
		cout << feet;
		cout << "Enter sign (+ or -): "; cin >> ch;
		
		sign = ((ch == '+') ? pos : neg);
	}
	void showdist()	// display distance
	{
		cout << ((sign == pos) ? "(+)" : "(-)");
		Distance::showdist();
	}
};

int main()
{
	signedDistance dist1; 	// use no-arg ctor 
	dist1.getdist();

	signedDistance dist2(11, 2.5);
	signedDistance dist3(11, 2.5, neg);

	cout << "dist1: "; dist1.showdist();
	cout << "\ndist2: "; dist2.showdist();
	cout << "\ndist3: "; dist3.showdist();
	
	cout << endl;
	system("pause");
}


