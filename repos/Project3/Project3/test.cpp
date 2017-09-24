
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

double func(double x) {
	double y;
	y = pow(x, 3) + 2 * pow(x, 2) - 3 * x - 7;
	return y;
}

double deriv(double x) {
	double y;
	y = 2 * pow(x, 2) + 4 * x - 3;
	return y;
}

int main() {
	double x = 1;
	double y = func(x);
	double derivY = deriv(x);
	double x_n = x - y / derivY;
	double limit = pow(10,-6);
	double y_n = func(x_n);

	double diff = abs(y_n - y);

		while (limit > diff) {
			y = y_n;
			x = x_n;
			derivY = deriv(x);
			 x_n = x - y / derivY;
			
			 y_n = func(x_n);
			 diff = abs(y_n - y);

		}

	cout << "Ans: " << x_n; 

	system("pause");

	
	
}

