#include<iostream>

using namespace std;

int main()
{
	int* i = new int;
	*i = 10;
	cout << "\n The Value for int i is : " << *i;
	delete i;
	cout << "\n Int i holds no value after its deleted : " << *i;
}