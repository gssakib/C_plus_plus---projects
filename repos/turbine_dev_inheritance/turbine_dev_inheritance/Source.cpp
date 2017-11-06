/* create a derived class turbine_dev adding capability for computing incoming turbulence intensity of each turbine */
#include<iostream>
#include<cmath>
#include<string>
using namespace std;

//defining global variables
const double PI = acos(-1.0); //pi
const double rho = 1.225; //density of air
double windspeed_freeincoming; 
double amb_turb_inten;

//original turbine class
class turbine	// define a turbine class
{
public:
	double turbinecoor; 		// location of the turbine
	double radius_rotor;		// rotor radius
	double inductionfactor_axis; 	// axial induction factor
	double coeff_power; 		// power coefficient
	double windspeed_incoming;	// incoming wind speed for this turbine
	double power;			// produced power
	double coeff_entrainment;	// entrainment coefficient
	int facefreewind;		// facing free wind: 1-yes, 0-no
public:
	// ctor
	turbine() : coeff_entrainment(0.1) {  }

	// ask user to enter turbine characteristics
	void getturbine()
	{
		cout << "Enter turbine characteristics: " << endl;
		cout << "\t turbine location (m): "; cin >> turbinecoor;
		cout << "\t rotor radius (m): "; cin >> radius_rotor;
		cout << "\t axial induction factor: "; cin >> inductionfactor_axis;
		cout << "\t facing free wind?: "; cin >> facefreewind;
	}

	// compute wake radius at x downwind from this turbine
	double radius_wake(double x) { return (radius_rotor + coeff_entrainment * x); }

	// compute wake velocity at x downwind from this turbine
	double velocity_wake(double x)
	{
		return (windspeed_incoming * (1.0 - 2 * inductionfactor_axis*pow(radius_rotor / radius_wake(x), 2)));
	}

	// compute the incoming wind speed if this turbine facing undisturbed wind 
	void comput_incomingwind()
	{
		windspeed_incoming = windspeed_freeincoming;
	}

	// compute the incoming wind speed if this turbine in the downwind of Turbine_upwind 
	void comput_incomingwind(turbine Turbine_upwind)
	{
		double Sx = fabs(turbinecoor - Turbine_upwind.turbinecoor);
		windspeed_incoming = Turbine_upwind.velocity_wake(Sx);
	}

	// compute power coefficient of this turbine
	double CP() { return 4. * inductionfactor_axis * pow(1. - inductionfactor_axis, 2.); }

	// compute power of this turbine
	void comput_power()
	{
		coeff_power = CP();
		power = 0.5 * coeff_power * rho * PI * pow(radius_rotor, 2) * pow(windspeed_incoming, 3);
	}

	// display the performance of this turbine
	void dispturbine() const
	{
		cout << "Turbine located at " << turbinecoor << " m" << endl;
		cout << "\t Incoming wind speed: " << windspeed_incoming << " m/s" << endl;
		cout << "\t Power output: " << power / 1e6 << " MW" << endl;
	}

};

//derived turbine class extending capabilities to calculate total intensity and added turbulence intensity
class turbine_dev : public turbine 
{
private:
	double added_turb_in; //new variables to store added intensity
	double total_turb_in; //new variables to store total intensity



public:

	void compute_turb_in() {//no arg memeber function, means added turbine intensity is 0.
		
		added_turb_in = 0; 


	}

	void compute_turb_in(turbine Turbine_upwind) {//one arg member function to calculate added turbine intensity based on the turbine characterisitcs in front of it
		 //calculating absolute value of downwind distance x.
		double Sx = fabs(turbinecoor - Turbine_upwind.turbinecoor); 
		
		//calculating added turbine intensity
		added_turb_in = 0.73*pow(Turbine_upwind.inductionfactor_axis,0.83)*pow(amb_turb_inten,-0.0325)*pow(((Turbine_upwind.radius_rotor*2)/Sx),0.32);
		

	}

	void compute_total_turb_in() {//member function to calculate total turbine intensity
		
		total_turb_in = pow((pow(added_turb_in, 2) + pow(amb_turb_inten, 2)), 0.5);


	}

	void dispturbine_dev() const
	{//member function to display the calculated intensities
		turbine::dispturbine();
		cout << "         incoming total turbulence intensity (u_rms/U): " << total_turb_in <<  endl;
		cout << "         incoming turbine-added turbulence intensity (u_rms/U): " << added_turb_in << endl;
		
	}

};





// ask user to enter incoming wind info
void getwind()
{
	cout << "Enter undisturbed wind (m/s): "; cin >> windspeed_freeincoming;
}

void getundirb_turb_inten()
{
	cout << "Enter turbulent intensity of undisturbed wind(u_rms / U): "; cin >> amb_turb_inten;
}

int main()
{
	// create two derived turbine objects, Turbine2 in the downwind of Turbine1
	turbine_dev Turbine1, Turbine2;
	
	// get undisturbed wind speed
	getwind();

	//get turbulence internsity of undisturbed wind
	getundirb_turb_inten();

	// get turbine parameters
	Turbine1.getturbine(); Turbine2.getturbine();

	// compute incoming wind speed
	Turbine1.comput_incomingwind();
	Turbine2.comput_incomingwind(Turbine1);

	// compute produced power
	Turbine1.comput_power();
	Turbine2.comput_power();

	// compute added turbulence intensity
	Turbine1.compute_turb_in();
	Turbine2.compute_turb_in(Turbine1);

	// compute total turbulence intensity
	Turbine1.compute_total_turb_in();
	Turbine2.compute_total_turb_in();

	// display turbine performance
	Turbine1.dispturbine_dev();
	Turbine2.dispturbine_dev();
	

	
	system("pause");
}


