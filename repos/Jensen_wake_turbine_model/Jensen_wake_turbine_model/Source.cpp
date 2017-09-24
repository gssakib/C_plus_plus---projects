//This program utilizes Jensen Model to estimate wake radius(r) and wake velocity inside turbine(v).

//defining libraries used
#include<iostream>
#include<string>
#include<math.h>
using namespace std;


const double alpha = 0.1; //setting entrainment constant

struct turbine
{
	//defining turbine characteristic variable 


	const double r_o; //rotor radius
	double a; //axial induction factor


};

//defining function to calculate wake velocity behind turbine
double wake_vel_behind(double a, double u) {
	
	return ((1 - 2 * a)*u);

}

//defining function to calculate wake radius
double wake_radius(double r_o, double alpha, double x) {

	return (r_o + alpha*x);

}

//defining function to calculate wake velocity inside turbine
double wake_velocity_in(double& u, double& a, double& r_o, double& r) {

	return (u*(1 - 2*a*pow((r_o/ r),2)));

}

int main() {
	double u = 0; //incoming wind speed
	double a = 0; //axial induction factor
	double r_o = 0; // rotor radius
	double x = 0; // downwind distance from turbine
	double r = 0; //wake radius
	double v = 0; //wake velocity inside turbine
	double v_o = 0; //wake velocity behind turbine

	//outputting instructions to screen
	cout << "This program utilizes Jensen Model to estimate wake radius(r) and wake velocity inside turbine(v)." << endl;
	cout << "Please input the following parameters in meteric units" << endl << endl;
	cout << "Enter Incoming wind speed (u): "; cin >> u; 
	cout << "Enter Axial induction factor (a): "; cin >> a; 
	cout << "Enter Rotor radius (r_o): "; cin >> r_o; 
	cout << "Enter Downwind distance from turbine (x): "; cin >> x;
	cout << endl;

	////calculating the resutls
	r = wake_radius( r_o,  alpha,  x);

	v_o = wake_vel_behind(a, u);

	v = wake_velocity_in(u, a, r_o, r);

	//outputting the resutls
	cout << "wake radius(r): " << r << " m" << endl;
	cout << "wake velocity behind turbine(v): " << v << " m/s" << endl;
	cout << endl;
	system("pause");
}