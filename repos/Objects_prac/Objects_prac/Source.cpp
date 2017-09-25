/* const object */
#include<iostream>
#include<string>
using namespace std;

class foo
{
private:
	int num;
public:
	foo(int n) : num(n) {};
	void setnum() { num = 100; }
	int shownum() const { return num; }
};

int main()
{
	const foo f1(1);

	//f1.setnum();
	cout << "the number of f1 is " << f1.shownum() << endl;

	system("pause");
}


