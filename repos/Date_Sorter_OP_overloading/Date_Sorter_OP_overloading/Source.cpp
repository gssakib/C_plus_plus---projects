#include<iostream>
#include<cmath>
#include<string>


using namespace std;
const int MAX = 5; //creating global variable defining size of the array
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
		//storing date as string variable
		cout << "Enter Date(in the shown format): MM/DD/YYYY: ";  cin >> str; cout << endl;
		
		month = atoi(str.substr(0, 2).c_str()); //converting month substring to integer
	
		day = atoi(str.substr(3, 5).c_str()); //converting day substring to integer
	
		year = atoi(str.substr(6, 9).c_str()); //converting year substring to integer
		

	}
	void showdate() 
	{
		cout << month << "/" << day << "/" << year << endl;// print date
	}

	// function declaration of overloaded <
	bool operator <= (date) const; //declaring boolean constructor to compare dates
	date operator = (date) ;//declaring assignment operator for intuitive swapping
};

//defining assignment operator for intuitive swapping
date date::operator = (date dt2) 
{
	month = dt2.month;
	day = dt2.day;
	year = dt2.year;

	return *this;

}

//defining boolean constructor to compare dates
bool date::operator <= (date dt2) const
{
	if ((year < dt2.year) || (year == dt2.year && month < dt2.month) || (year == dt2.year && month == dt2.month && day < dt2.day) || (year == dt2.year && month == dt2.month && day == dt2.day)) {
		return true;
	}
	else {
		return false;
	}
}


//function to define bubble sorting 
void bubbleSort(date d[]) {

	//iterate through each of the array members
	for (int i = 0; i < (MAX-1); i++) {
		
		//compare the members in front to see if it is bigger.
		for (int j = i; j < (MAX); j++) {
			
			bool stat = d[j + 1] <= d[i]; //see if the members in front are bigger
			
			if (d[j + 1] <= d[i]) { //if it is bigger than swap
				
				//swapping algorithm
				date tmpdate = d[j + 1]; // temporary variable for swapping
				d[j + 1] = d[i];
				d[i] = tmpdate;
				
			}

		}
	}


}
int main()
	{
	
	date dt[MAX];//defining array to store dates
	
	//loop to store user input dates
	for (int i = 0; i < MAX; i++) {
		dt[i].setdate();
		
	}

	//sorting dates using bubble sort function
	bubbleSort(dt);

	
	cout << "Sorted dates(in ascending order): " << endl << endl;
	//loop to print sorted dates
	for (int i = 0; i < MAX; i++) {
		dt[i].showdate(); 

	}
	
	cout << endl;

	system("pause");
		
}

