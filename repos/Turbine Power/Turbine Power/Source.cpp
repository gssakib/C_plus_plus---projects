#include <iostream>
#include <string>
#include<cmath>
#include <math.h>

using namespace std;

// defining base structure for storing components
struct Cmpnts
{
	double x, y, z;
};

// defining wind structure to hold wind info
struct Wind
{
	Cmpnts velocity;
	Cmpnts direction;
	double airdensity;

};

// defining turbine structure to hold turbine info
struct Turbine
{
	double R, CP, V, yaw, power;
	Cmpnts direction;
};

int main() {

	double const PI = acos(-1); //defining pi

	Wind wind1; //instantiating wind structure
	Turbine turbine1;  //instantiating turbine structure

	//defining wind & turbine constants

	wind1.airdensity = 1.225; // air density in kg/m^3
	turbine1.CP = 0.46; //for this specific turbine
	turbine1.R = 48;
	// asking for wind velocity components & turbine yaw angle
	cout << "Enter u (north-south velocity component) of wind:  "; cin >> wind1.velocity.x; 
	cout << "Enter v (west-east velocity component) of wind:  "; cin >> wind1.velocity.y;
	cout << "Enter w (vertical velocity component) of wind:  "; cin >> wind1.velocity.z;
	cout << "Enter yaw angle of turbine(in degrees):  "; cin >> turbine1.yaw;
	cout << endl;

	//calculating wind direction

	wind1.direction.x = wind1.velocity.x / sqrt(pow(wind1.velocity.x, 2) + pow(wind1.velocity.y, 2) + pow(wind1.velocity.z, 2));
	wind1.direction.y = wind1.velocity.y / sqrt(pow(wind1.velocity.x, 2) + pow(wind1.velocity.y, 2) + pow(wind1.velocity.z, 2));
	wind1.direction.z = wind1.velocity.z / sqrt(pow(wind1.velocity.x, 2) + pow(wind1.velocity.y, 2) + pow(wind1.velocity.z, 2));

	// calculating turbine pointing direction

	turbine1.direction.x = wind1.direction.x*cos(turbine1.yaw*(PI / 180)) - wind1.direction.y*sin(turbine1.yaw*(PI / 180));
	turbine1.direction.y = wind1.direction.x*sin(turbine1.yaw*(PI / 180)) + wind1.direction.y*cos(turbine1.yaw*(PI / 180));
	turbine1.direction.z = 0;


	// calculating the wind speed in rotor axial direction

	turbine1.V = wind1.velocity.x*turbine1.direction.x + wind1.velocity.y*turbine1.direction.y + wind1.velocity.z*turbine1.direction.z;
	
	//calcualting power using eq(1)
	turbine1.power = 0.5*wind1.airdensity*turbine1.CP*PI*pow(turbine1.R,2)*pow(turbine1.V, 3);

	cout << "Power Produced by Turbine: " << turbine1.power << " J" << endl << endl;

	system("pause");
}
