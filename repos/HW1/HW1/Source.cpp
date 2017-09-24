//temp_converter.cpp
//converts celcius to fahrenheit


#include <iostream> //preprocessor directive for I/O 
#include <string> //preprocessor directive for data types

using namespace std; //to avoid writing std all the time

// main function
int main(){
	float cel; //defining float to store temperature value in celcius 
	float far; //defining float to store temperature value in fahrenheit
	cout << "Enter temperature in Celius: ";  //asking for temperature input in celsius
	cin >> cel;  //using cin function to retract input

	far = 1.8*cel + 32; //formula to change celsius to fahrenheit
	
	//displaying the final conversion values
	cout << cel; 
	cout << " C is: ";
	cout << far;
	cout << " F" << endl;

	system("pause"); //so the console doensn't disappear.
}

