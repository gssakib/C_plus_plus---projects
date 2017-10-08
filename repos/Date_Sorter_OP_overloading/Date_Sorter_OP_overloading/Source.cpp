#include<iostream>
#include<cmath>
#include<string>
using namespace std;
const int MAX = 5;
class date	// define a class
{
private:
	int day;
	int month;
	int year;
public:
	date() : day(0), month(0), year(0) {}
	date(int mn, int dy, int yr) : day(dy), month(mn), year(yr) {}
	void setdate() // show data
	{
		string str;
		cout << "Enter Date(in the shown format): MM/DD/YYYY: ";  cin >> str; cout << endl;
		
		month = atoi(str.substr(0, 2).c_str());
	//	cout << month << endl;
		day = atoi(str.substr(3, 5).c_str());
	//	cout << day << endl;
		year = atoi(str.substr(6, 9).c_str());
		

	}
	void showdate() // show data
	{
		cout << month << "/" << day << "/" << year << endl;
	}

	// function declaration of overloaded <
	bool operator <= (date) const;
	date operator = (date) ;
};

date date::operator = (date dt2) 
{
	month = dt2.month;
	day = dt2.day;
	year = dt2.year;

	return *this;

}
bool date::operator <= (date dt2) const
{
	if ((year < dt2.year) || (year == dt2.year && month < dt2.month) || (year == dt2.year && month == dt2.month && day < dt2.day) || (year == dt2.year && month == dt2.month && day == dt2.day)) {
		return true;
	}
	else {
		return false;
	}
}

void bubbleSort(date d[]) {
	for (int i = 0; i < (MAX-1); i++) {
		
		for (int j = i; j < (MAX); j++) {
			
			bool stat = d[j + 1] <= d[i];
			
			if (d[j + 1] <= d[i]) {
				
				
				date tmpdate = d[j + 1];
				d[j + 1] = d[i];
				d[i] = tmpdate;
				
			}

		}
	}


}
int main()
	{
	
	date dt[MAX];
	
	for (int i = 0; i < MAX; i++) {
		dt[i].setdate();
		
	}

	bubbleSort(dt);

	
	cout << "Sorted dates(in ascending order): " << endl << endl;

	for (int i = 0; i < MAX; i++) {
		dt[i].showdate(); 

	}
	
	cout << endl;

	system("pause");
		
}

