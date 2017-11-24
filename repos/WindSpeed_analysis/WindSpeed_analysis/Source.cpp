// including all the libraries needed
#include<iostream>
#include<string>
#include <fstream> 
#include <math.h> 
#include <stdlib.h> 
using namespace std;
const int N = 5000; // no of data points from each files

string filename[1000];
string start_date;
string end_date;
string start_time;
string end_time;
int nofiles = 0; //number of fies to be read in

int incre = 0;

int start_index = 0;
int end_index = 0;
class wind {
private:
	//string files[100]; //name of files to be read in
	string values[N]; // number of information data points / file
	string time[1441];
	string speed[1441];
	string direction[1441];

	//for storing the range of speed & direction values whose mean and rms is to be calculated
	string speedRange[1441];
	string directionRange[1441];

	//for storing the index of range of speed & direction values whose mean and rms is to be calculated
	int i_start = 0;
	int i_end = 0;

	//variable for storing mean and rms values of wind speed
	double mean_speed = 0;
	double rms_speed = 0;

	//variable for storing mean and rms values of wind direction
	double mean_direc = 0;
	double rms_direc = 0;


public:
	void print() {


		//for (int i = 0; i < 4324; i++) {
		//	cout << values[i];
			
			//cout << endl;
		//}
		
		
		//cout << "Speeds for the given range is: "; cout << endl;
		//for (int i = 0; i <= (i_end - i_start); i++) {
			//cout << speedRange[i]; cout << " ";   cout << directionRange[i];
		//cout << endl;
		
		//}
		cout << endl;
		cout << "Mean speed for the given range is: "; cout << mean_speed;
		cout << endl;
		cout << "RMS speed value for the given range is: "; cout << rms_speed;
		cout << endl;  
		cout << endl;
		cout << "Mean direction for the given range is: "; cout << mean_direc;
		cout << endl;
		cout << "RMS direction value for the given range is: "; cout << rms_direc;
	}


	void read() { //member function to read wind data from "csv files"


	



		ifstream imyfile;
		imyfile.open(filename[0]);


		cout << endl;



		// read in all the information from the file

		if (imyfile.is_open()) // check if the file is open
		{


			
			for (int i = 0; i < N; i++)
			{
				getline(imyfile, values[i], ','); // read raw data and store it in "values" array
			}

		}

		// extract the time information from the value array

		for (int i = 0; i < 1440; i++) {
			time[i] = values[4 + 3 * i]; // 4+3n is the pattern to extract the time values
		}



		// extract the speed information from the value array

		for (int i = 0; i < 1440; i++) {
			speed[i] = values[5 + 3 * i]; // 5+3n is the pattern to extract the speed values
		}





		// extract the direction information from the value array
		int pos;
		for (int i = 0; i < 1440; i++) {
			pos = values[6 + 3 * i].find('\n');
		   direction[i] =  values[6 + 3 * i].substr(0,pos);// 6+3n is the pattern to extract the speed values
			
		}



		//matches the index of start time and end time in the array time to create an array of speed and direction values whose mean is to be taken.
		bool flag = false;

		for (int i = 0; i < 1440; i++) {

			if (start_time == time[i]) {
				flag == true;
				i_start = i;
			}
			if (end_time == time[i]) {
				flag == false;
				i_end = i;
			}
		}

		for (int i = 0; i <= (i_end - i_start); i++) {
			speedRange[i] = speed[i_start + i];
			directionRange[i] = direction[i_start + i];
		}




	}

	//for summing up the wind speed & wind direc
	double sum_speed = 0;
	double sum_direc = 0;

	void windAnalyze() {
		//summin up the speed & direction values
		for (int i = 0; i <= (i_end - i_start); i++) {
			sum_speed = sum_speed + atof(speedRange[i].c_str()); //converting the string to double and then summing it up for speed
			sum_direc = sum_direc + atof(directionRange[i].c_str()); //converting the string to double and then summing it up for direction
		
		}

		//calculating mean
		mean_speed = sum_speed / ((i_end - i_start) + 1);
		mean_direc = sum_direc / ((i_end - i_start) + 1);
		
		//calculating rms
		sum_speed = 0; //using this variable again
		sum_direc = 0;

		for (int i = 0; i <= (i_end - i_start); i++) {
			sum_speed = sum_speed + pow((atof(speedRange[i].c_str()) - mean_speed), 2); //converting the string to double and then summing it up
			sum_direc = sum_direc + pow((atof(directionRange[i].c_str()) - mean_direc), 2);
		}

		rms_speed = pow((sum_speed / ((i_end - i_start) + 1)), 0.5); //rms formula provided
		rms_direc = pow((sum_direc / ((i_end - i_start) + 1)), 0.5);

	}



	



};

class turbine {
private:
	double rho = 1;
	double c_p = 1;
	double PI = 3.142;
	double R = 3;
	double mean_speed;



public:
	turbine(double x) : mean_speed(x) {}

	void print() {

		cout << "Turbine Power is: " << (0.5*rho*c_p*PI*pow(R, 2) * pow(mean_speed, 3));
		cout << endl; cout << endl;
	}



};

int main() {
	/*
	cout << "Welcome to turbine power calculations program!" << endl;
	cout << endl;
	*/
	//cout << "Enter start date(mm/dd/yyyy): "; cin >> start_date;
	//cout << "Enter start time(hh/mm/ss): "; cin >> start_time;
	//cout << endl;

	//cout << "Enter end date(mm/dd/yyyy): "; cin >> end_date;
	//cout << "Enter end time(hh/mm/ss): "; cin >> end_time;
	//cout << endl;


	//cout << "Enter number of files to be read: "; cin >> N;
	//cout << endl;
	
	bool opt = 1;
	
	while (opt) {
		cout << "Enter name of file to be read: "; cin >> filename[incre++]; cout << endl;
		
		cout << "Enter another file: ?....Enter 0 for 'no' and 1 for 'yes'..... "; cin >> opt;
		cout << endl; cout << endl;

	}
	

	cout << "Enter start time(h:mm:ss): "; cin >> start_time;
	cout << "Enter end time(h:mm:ss): "; cin >> end_time;
	
	wind w1;
	w1.read();
	w1.windAnalyze();
	w1.print();

	//turbine t1(8.24);
	//t1.print();

	cout << endl;
	system("pause");


}