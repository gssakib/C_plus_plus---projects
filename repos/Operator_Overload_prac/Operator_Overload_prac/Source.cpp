/*
* Two kinds of time case: conversion between objects of different classes:
* conversion operator in the source object
*/
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

/** civilian time */
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
	// conversion operator
};
class time12
{
private:
	bool pm;	// true: pm; false: am 
	int hrs;	// 1 - 12
	int mins;	// 0 - 59
public:
	time12() : pm(true), hrs(0), mins(0) {} // no-arg constructor
	time12(bool ap, int h, int m) : pm(ap), hrs(h), mins(m) {} // three-arg constructor
	void display()
	{
		cout << hrs << ':';
		cout << setw(2) << setfill('0') << mins << ' ';;
		string am_pm = pm ? "p.m. " : "a.m. ";
		cout << am_pm;
	}
	operator time24() const;
};

/** military time */


time12::operator time24() const
{
	int secs = 0;
	int hrs12 = hrs;
	int mins12 = mins;
	if (pm == true && hrs12 >= 1 && hrs12 != 12) {
		hrs12 += 12;
	}
	else if (pm == false && hrs12 >= 12) {
		hrs12 -= 12;
	}

	if (mins12 == 60) {
		hrs12++;
		mins12 = 0;
	}
	if (hrs12 == 24) {
		hrs12 = 0;
	}

	return time24(hrs12, mins12, secs);
}

int main()
{
	int h, m ;
	bool pm;

	cout << "enter hour (0-12): "; cin >> h;
	cout << "enter minutes (0-59): "; cin >> m;
	cout << "Enter '1' for pm or '0' for am : "; cin >> pm;
	time12 t12(pm, h, m);
	cout << "12-hour time: "; t12.display(); cout << endl;

	time24 t24 = t12;

	cout << "24-hour time: "; t24.display(); cout << endl;
	system("pause");
}


