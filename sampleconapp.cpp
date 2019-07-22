
#include<iostream>
using namespace std;

//struct CA
class CA
{
private:
	int a, b;
public:
	void input()   // void input(CA* const this)
	{
		cout << "enter 2 nos" << endl;
		cin >> this->a >> this->b;
	}
	void print()   // void print(CA* const this)
	{
		cout << "a=" << this->a << ",b=" << this->b << endl;
	}
};
//--- class consumer code----
int main()
{
	cout << "size of CA object" << sizeof(CA) << endl;
	CA obj1;
	obj1.input();   // CA::input(&obj1);
	obj1.print();   // CA::print(&obj1);
	cin.ignore();
	cin.get();
	return 0;
}
