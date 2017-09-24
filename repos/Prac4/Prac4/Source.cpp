
#include <iostream>
#include <string>
using namespace std;
int times = 0;

int disp(int times){
	times++;
	return times;

}

int my_Function(void) {
	static unsigned int call_count = 0;
	call_count++;
	return call_count;
}
int main(){

	//int x = disp(times);
	my_Function();
	my_Function();
	my_Function();
	my_Function();
	cout << "I have been called " << my_Function() << " times." << endl;

	system("pause");
}




