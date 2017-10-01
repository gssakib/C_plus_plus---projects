//Script to calculate the mean & standard deviation of 3 velocity components from raw data file "mettower.txt"
//created by : Gazi Sakib // MEC 510 HW

//including all the libraries needed 
#include<iostream>
#include<string>
#include <fstream> 
#include <math.h> 
#include <stdlib.h> 
using namespace std;

const int N = 7215; //exact number of raw data in the "mettower.txt". The number was found by a code that calculated the size of the raw data array.
const int K = 1200; // number of data points for the 3 velocity vectors (given)



class wind{
	private:
		
		string a[N]; //array to store raw data from "mettower.txt"

		double x_vel[K]; //array to store the X velocity vector data points
		double sumX = 0; //variable for summing the X Velocity data points
		double relX = 0; //variable to store the relative differences between X velocity data points and the mean

		double y_vel[K]; //array to store the Y velocity vector data points
		double sumY = 0; //variable for summing the Y Velocity data points
		double relY = 0; //variable to store the relative differences between Y velocity data points and the mean



		double z_vel[K]; //array to store the Z velocity vector data points
		double sumZ = 0; //variable for summing the Z Velocity data points
		double relZ = 0; //variable to store the relative differences between Z velocity data points and the mean
		
	public:
		void read() { //member function to read velocity data from "mettower.txt"
		
								
					   

		// create an object for reading a file
			ifstream imyfile;

		// open example.txt
			imyfile.open("mettower.txt");

			if (imyfile.is_open()) // check if the file is open 
			{
				

				for (int i = 0; i<N; i++)
				{
					imyfile >> a[i]; // read raw data and store it in "a" array
				}

				
				int size = 0;

				for (int i = 0; i < N; i++) {
					
					
					if (a[i] == "PM") { //this is the pattern I saw after printing out raw data. The velocity vectors are always the next 3 values after the string "PM"
						x_vel[size] = atof(a[i + 1].c_str()); //store first velocity data
						y_vel[size] = atof(a[i + 2].c_str()); //store second velocity data
						z_vel[size] = atof(a[i + 3].c_str()); //store third velocity data
						size++; //increment counter
					}


				}
				// close the file
				imyfile.close();
			}
			else
			{
				cout << "unable to open the file"; //exception case handler
				exit(0);
			}

			

		

			

			
	}

	void mean() { //member function to calculate the mean of the 3 velocity vectors
		for (int i = 0; i < 1200; i++) {
			sumX += x_vel[i]; //summing up the X velocity vectors
			sumY += y_vel[i]; //summing up the Y velocity vectors
			sumZ += z_vel[i]; //summing up the Z velocity vectors
		}

		//print the results

		cout << "Mean of X vector veloctiy: " << (sumX/K) << endl;
		cout << "Mean of Y vector veloctiy: " << (sumY / K) << endl;
		cout << "Mean of Z vector veloctiy: " << (sumZ / K) << endl;
		cout << endl;
	}

	void std_dev() {//member function to calculate the standard deviation for each of the velocity vectors
		
		sumX = 0;
		sumY = 0;
		sumZ = 0;


		for (int i = 0; i < 1200; i++) {
			sumX += x_vel[i]; //summing up the X velocity vectors
			sumY += y_vel[i]; //summing up the Y velocity vectors
			sumZ += z_vel[i]; //summing up the Z velocity vectors
		}
		
		double mX = (sumX / K); //storing X velocity mean
		double mY = (sumY / K); //storing Y velocity mean
		double mZ = (sumZ / K); //storing Z velocity mean

		for (int i = 0; i < K; i++) {
			relX += pow((x_vel[i] - mX), 2); //storing X velocity relative difference
			relY += pow((y_vel[i] - mY), 2); //storing Y velocity relative difference
			relZ += pow((z_vel[i] - mZ), 2); //storing Z velocity relative difference

		}

		//Printing the standard deviation for X,Y & Z velocity vectors.
		cout << "Standard Deviation of X vector velocity: " << sqrt(relX / K) << endl;
		cout << "Standard Deviation of Y vector velocity: " << sqrt(relY / K) << endl;
		cout << "Standard Deviation of Z vecotr velocity: " << sqrt(relZ / K) << endl;
		cout << endl;
	}
};


int main() {

	wind w1; //instantiating wind object

	w1.read(); //using member function to read from "mettower.txt"
	
	w1.mean(); //using member function to calculate and display mean of the 3 velocity components

	w1.std_dev(); //using member function to calculate and display standard deviation of the 3 velocity components

	system("pause");



}