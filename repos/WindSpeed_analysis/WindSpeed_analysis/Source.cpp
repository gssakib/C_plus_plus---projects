// including all the libraries needed
#include<iostream>
#include<string>
#include <fstream> 
#include <math.h> 
#include <stdlib.h> 
#include <conio.h>
#include <vector>

using namespace std;

const int N = 5000; // no of data points from each files

string filename[1000];
string finalFilename[1000];
string startFile = "";
string endFile = "";
string start_date;
string end_date;
string start_time;
string end_time;
int nofiles = 0; //number of fies to be read in

int incre = 0;






vector< vector<string> > speedRange(1441, vector<string>(10));

vector< vector<string> > directionRange(1441, vector<string>(10));

class wind {
private:
	//string files[100]; //name of files to be read in
	string values[N]; // number of information data points / file
	string time[1441];
	string speed[1441];
	string direction[1441];

	int start_index = 0;
	int end_index = 0;


	//for summing up the wind speed & wind direc
	double sum_speed = 0;
	double sum_direc = 0;
	
	
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


		cout << "mean speed: "; cout << mean_speed;
		cout << endl;
		cout << "rms speed: "; cout << rms_speed;
		cout << endl;
		
		
		
		cout << "mean direc: "; cout << mean_direc;
		cout << endl;
		cout << "rms direc: "; cout << rms_direc;
		cout << endl; cout << endl; 
	}

	double givSpeed() {

		return mean_speed; // returns mean speed
	}
	void fileAnalyze() {//this function analyzes which of the files should be read based on the start and the end dates provided.


		for (int i = 0; i < incre; i++) {
			ifstream imyfile;
			imyfile.open(filename[i]);
			if (imyfile.is_open()) // check if the file is open
			{



				for (int j = 0; j < 4; j++)
				{
					getline(imyfile, values[j], ','); // read raw data and store it in "values" array
				}

			}
			
			
			if (start_date.compare(values[3].substr(5, sizeof(values[3]))) == 0 ) {
				startFile = filename[i];
				

			}

			
			if (end_date.compare(values[3].substr(5, sizeof(values[3]))) == 0) {
				
				endFile = filename[i];
				
			}
			
			imyfile.close();

			

		}
		
		//cout << "startFile: "; cout << startFile; cout << endl;
		//cout << "endFile: "; cout << endFile;
		
		
		
		
		
	//	cout << start_date.find_first_of('/');
		//cout << endl;
		//cout << start_date.find_last_of('/');
		//cout << endl;

		

	}

	void readMultiple() {


		for (int j = 0; j < incre; j++) {

			ifstream imyfile;
			imyfile.open(filename[j]);

			



			



			// read in all the information from the file

			if (imyfile.is_open()) // check if the file is open
			{



				for (int i = 0; i < N; i++)
				{
					getline(imyfile, values[i], ','); // read raw data and store it in "values" array
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
					direction[i] = values[6 + 3 * i].substr(0, pos);// 6+3n is the pattern to extract the speed values

				}

				

				
			






				
					//matches the index of start time and end time in the array time to create an array of speed and direction values whose mean is to be taken.
					bool flag = false;

					for (int i = 0; i < 1440; i++) {

						if (start_time == time[i] && j == 0) {
							flag == true;
							i_start = i;
							i_end = 1440;
						}else if (j == (incre - 1) && end_time == time[i]) {
							flag == false;
							i_start = 0;
							i_end = i;
						}else if (j > 0 && j< (incre - 1)) {
							i_start = 0;
							i_end = 1440;
							
						}
					}


					for (int i = 0; i <= (i_end - i_start); i++) {
						speedRange[i][j] = speed[i_start + i];
						directionRange[i][j] = direction[i_start + i];
					}


			











			}

			


		}
	
		

		

	}


	void read(string file) { //member function to read wind data from "csv files"






		ifstream imyfile;
		imyfile.open(file);


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
			speedRange[i][1] = speed[i_start + i];
			directionRange[i][1] = direction[i_start + i];
		}

		


	}

	

	void windAnalyze() {
		
		//summin up the speed & direction values
		for (int i = 0; i <= (i_end - i_start); i++) {
			sum_speed = sum_speed + atof(speedRange[i][1].c_str()); //converting the string to double and then summing it up for speed
			sum_direc = sum_direc + atof(directionRange[i][1].c_str()); //converting the string to double and then summing it up for direction
		
		}

		//calculating mean
		mean_speed = sum_speed / ((i_end - i_start) + 1);
		mean_direc = sum_direc / ((i_end - i_start) + 1);
		
		//calculating rms
		sum_speed = 0; //using this variable again
		sum_direc = 0;

		for (int i = 0; i <= (i_end - i_start); i++) {
			sum_speed = sum_speed + pow((atof(speedRange[i][1].c_str()) - mean_speed), 2); //converting the string to double and then summing it up
			sum_direc = sum_direc + pow((atof(directionRange[i][1].c_str()) - mean_direc), 2);
		}

		rms_speed = pow((sum_speed / ((i_end - i_start) + 1)), 0.5); //rms formula provided
		rms_direc = pow((sum_direc / ((i_end - i_start) + 1)), 0.5);

	}

	void windAnalyzeMultiple() {
		//for summing up the wind speed & wind direc
		double sum_speed = 0;
		double sum_direc = 0;
		double num = 0;
		for (int j = 0; j < incre; j++) {
			for (int i = 0; i < speedRange.size(); i++) {

				if (atof(speedRange[i][j].c_str()) != NULL) {
					sum_speed = sum_speed + atof(speedRange[i][j].c_str()); //converting the string to double and then summing it up for speed
					sum_direc = sum_direc + atof(directionRange[i][j].c_str()); //converting the string to double and then summing it up for direction
					num++; //increment counter
				}

			}

		}
		
		

		//calculating mean
		mean_speed = sum_speed / num;
		mean_direc = sum_direc / num;

		//calculating rms
		sum_speed = 0; //using this variable again
		sum_direc = 0;


		for (int j = 0; j < incre; j++) {
			for (int i = 0; i < speedRange.size(); i++) {

				if (atof(speedRange[i][j].c_str()) != NULL) {
					sum_speed = sum_speed + pow((atof(speedRange[i][j].c_str()) - mean_speed), 2); //converting the string to double and then summing it up for speed
					sum_direc = sum_direc + pow((atof(directionRange[i][j].c_str()) - mean_direc), 2); //converting the string to double and then summing it up for direction
					
				}

			}

		}



	

		rms_speed = pow((sum_speed / num), 0.5); //rms formula provided
		rms_direc = pow((sum_direc / num), 0.5);


		

	}

	



};

class turbine {
private:
	//default values of the constants
	double rho = 1;
	double c_p = 1;
	double PI = 3.142;
	double R = 3;
	double mean_speed;



public:
	turbine(double x) : mean_speed(x) {}

	void print() {
		cout << "Enter air density(rho): "; cin >> rho; cout << endl;
		cout << "Enter power coefficient(C_p): "; cin >> c_p; cout << endl;
		cout << "Enter rotor radius(R): "; cin >> R; cout << endl;
		


		cout << "Turbine Power is: " << (0.5*rho*c_p*PI*pow(R, 2) * pow(mean_speed, 3));
		cout << endl; cout << endl;
	}



};

int main() {
	
	
	bool opt = 1;
	
	while (opt) {
		cout << "Enter name of file to be read: "; cin >> filename[incre++]; cout << endl;
		
		cout << "Enter another file: ?....Enter 0 for 'no' and 1 for 'yes'..... "; cin >> opt;
		cout << endl; cout << endl;

	}
	
	cout << "Enter start date(mm/dd/yyyy): "; cin >> start_date;
	cout << "Enter start time(h:mm:ss): "; cin >> start_time;
	cout << endl;

	
	cout << "Enter end date(mm/dd/yyyy): "; cin >> end_date;
	cout << "Enter end time(h:mm:ss): "; cin >> end_time;
	cout << endl;






	
	




	//creating wind class

	wind w1;
	w1.fileAnalyze();
	w1.readMultiple();
	w1.windAnalyzeMultiple();
	w1.print();

	//calculating power 
	turbine t1(w1.givSpeed());
	t1.print();
	
	
	
	
	
	//for (int k = 0; k < incre; k++) {
		
	//	w1.read(filename[k]);
	//	w1.windAnalyze();
	//	w1.print();
		
	//	cout << endl; cout << endl;

	//}

	

	
	
	
	
	

	cout << endl;
	system("pause");


}