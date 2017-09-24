//Snakes & Ladders CMD Game
#include <iostream>
#include <string>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
using namespace std;


int randnum(int limit) {
	/* initialize random seed: */
	srand(time(NULL));
	return (rand() % limit + 1);
}
int main() {
	string name; //defining name vars

	//defining game statistics vars
	int pos = 1;
	int current_roll;
	int decision;

	cout << "Welcome to Snakes & Ladders!" << endl;
	cout << endl;
	cout << "Enter Name: " ;
	cin >> name;


	// do while loop until position 30 is reached.
	do {

		cout << "Current Position: " << pos << endl;
		cout << endl;
		
		
			cout << "Pick from the following options: a)Roll Dice-(Enter 1)    b)Exit-(Enter 0)...........";

			while (!(cin >> decision)) {
				cout << "Bad value! Try Again" << endl; //handler, to reject bad values.
				cout << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Pick from the following options: a)Roll Dice-(Enter 1)    b)Exit-(Enter 0)...........";
				
			}
			
			cout << endl;
	
		
			
		
		
			
			
			

		//different scenarios of snakes & ladder based on fig 1.
		
		if (decision == 1) {
			current_roll = randnum(6); //rolling dice
			cout << "You rolled a "<< current_roll << endl;
			pos = pos + current_roll;
			cout << endl;
			if (pos == 3) {
				cout << "Current Position: " << pos << endl;
				cout << "YAY!..You have come across a ladder that will take you to position 22." << endl;
				pos = 22;
				
			}
			else if(pos == 5){
				cout << "Current Position: " << pos << endl;
				cout << "YAY!..You have come across a ladder that will take you to position 8." << endl;
				pos = 8;
				
			}
			else if(pos == 11){
				cout << "Current Position: " << pos << endl;
				cout << "YAY!..You have come across a ladder that will take you to position 26." << endl;
				pos = 26;
				
			}
			else if (pos == 20) {
				cout << "Current Position: " << pos << endl;
				cout << "YAY!..You have come across a ladder that will take you to position 29." << endl;
				pos = 29;
				
			}
			else if (pos == 17) {
				cout << "Current Position: " << pos << endl;
				cout << "Oh No!...You have come across a snake that will take you to position 4." << endl;
				pos = 4;
			
			}
			else if(pos == 19){
				cout << "Current Position: " << pos << endl;
				cout << "Oh No!...You have come across a snake that will take you to position 7." << endl;
				pos = 7;
				
			}
			else if (pos == 21) {
				cout << "Current Position: " << pos << endl;
				cout << "Oh No!...You have come across a snake that will take you to position 9." << endl;
				pos = 9;
				
			}
			else if (pos == 27) {
				cout << "Current Position: " << pos << endl;
				cout << "Oh No!...You have come across a snake that will take you to position 1." << endl;
				pos = 1;
				
			}
			else if (pos >= 30) {
				pos = 30;
				cout << "Current Position: " << pos << endl;
				cout << "YAY!!!! You won the game, " << name << endl;
				cout << endl;
				system("pause");
				exit(0);
			}
			else {
				continue;
			}

		}
		else if(decision == 0) {
			cout << "Sorry that you quit.." << name << "..See you next time!!"<< endl;
			cout << endl;
			system("pause");
			exit(0);

		}
		

		
	
	
	} while (pos != 30);
	
	
	
	system("pause");
	exit(0);



	

}

