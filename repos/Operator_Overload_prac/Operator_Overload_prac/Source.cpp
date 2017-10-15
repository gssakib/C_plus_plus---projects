/*
* Two kinds of time case: conversion between objects of different classes
* one-arg constructor in destination object - [initial code modified to include operator overlading to convert back to 24 hour time by Gazi Sakib.] 
*/
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

/** military time */
class time24
{
private:
	int hours;	// 0 - 23 
	int minutes;	// 0 - 59
	int seconds;	// 0 - 59
public:
	time24() : hours(0), minutes(0), seconds(0) {} 				// no-arg constructor
	time24(int h, int m, int s) : hours(h), minutes(m), seconds(s) {} 	// three-arg constructor
	void display()
	{
		cout << setw(2) << setfill('0') << hours << ':';
		cout << setw(2) << setfill('0') << minutes << ':';
		cout << setw(2) << setfill('0') << seconds;
	}

	//operator time12() const;						// conversion operator
	int gethrs() const { return hours; };
	int getmins() const { return minutes; };
	int getsecs() const { return seconds; };
};

/** civilian time */
class time12
{
private:
	bool pm;	// true: pm; false: am 
	int hrs;	// 1 - 12
	int mins;	// 0 - 59
public:
	time12() : pm(true), hrs(0), mins(0) {} // no-arg constructor
	time12(bool ap, int h, int m) : pm(ap), hrs(h), mins(m) {} // three-arg constructor
	time12(time24); // one-arg constructor
	void display()
	{
		cout << hrs << ':';
		cout << setw(2) << setfill('0') << mins << ' ';;
		string am_pm = pm ? "p.m. " : "a.m. ";
		cout << am_pm;
	}
	operator time24() const; // operator overloading function
};

// one-arg constructor defined for converting time24 to time12
time12::time12(time24 t24)
{
	int hrs24 = t24.gethrs();
	pm = (hrs24<12) ? false : true;

	mins = t24.getsecs() < 30 ? t24.getmins() : t24.getmins() + 1; 	// round seconds

	if (mins == 60)					// carry mins 
	{
		mins = 0;
		++hrs24;
		if (hrs24 == 12 || hrs24 == 24) pm = (pm == true) ? false : true; // carry hrs? yes toggle pm/am
	}

	hrs = (hrs24 > 13) ? hrs24 - 12 : hrs24;
	if (hrs == 0) { hrs = 12; pm = false; }
}

// operator overloading function for converting time12 back to time24
time12::operator time24() const
{
	int secs12 = 0; //turning seconds to 0
	int hrs12 = hrs; //reinitializing hrs
	int mins12 = mins; //reinitializing mins

	//conditionals to convert to hours to 24 hour time.
	if (pm == true && hrs12 >= 1 && hrs12 != 12) {
		hrs12 += 12;
	}
	else if (pm == false && hrs12 >= 12) {
		hrs12 -= 12;
	}

	//conditionals if 60 mins is input
	if (mins12 == 60) {
		hrs12++;
		mins12 = 0;
	}
	//conditional if hour becomes 24, then it should be set to 0.
	if (hrs12 == 24) {
		hrs12 = 0;
	}
	// returning time24 object with new values
	return time24(hrs12, mins12, secs12);
}


int main()
{
	int h, m, s; //variables initialized to store user input

	// user inputs
	cout << "enter hour (0-23): "; cin >> h;
	cout << "enter minutes (0-59): "; cin >> m;
	cout << "enter seconds (0-59): "; cin >> s;
	
	time24 t24(h, m, s); //making t24 object
	
	//displaying the 24- hours time input
	cout << "24-hour time: "; t24.display(); cout << endl;

	//converting to 12 hour time using one arg constructor
	time12 t12 = t24;

	//printing 12-hr time
	cout << "12-hour time: "; t12.display(); cout << endl << endl;

	//converting back to 24 hour time using operator overloading
	time24 t24_cnvrt_back = t12;

	//printing converted 24 hours time
	cout << "Now converted back to 24 hour time...." << endl << endl;
	cout << "24-hour time: "; t24_cnvrt_back.display(); cout << endl<< endl;
	
	
	system("pause");

	
}
