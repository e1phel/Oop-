#include<iostream>
using namespace std;

class student
{
	int id, n;
	string name;
	string* subjects = new string[n];
	string* marks = new string[n];

public:
	student() : id(0), n(0), subjects(nullptr), marks(nullptr) {}
	void input()
	{
		cout << "\n================ Portal ===============";
		cout << "\n\t Enter Your Name : ";
		cin >> name;
		cout << "\n\t Enter Your ID : ";
		cin >> id;
		cout << "\n\t Enter the Number of your Subjects : ";
		cin >> n;
		subjects = new string[n];
		marks = new string[n];
	}
	void subs()
	{
		cout << "\n----------------------------------------";
		cout << "\n\t Enter Your Subjects : ";
		for (int i = 0; i < n; i++)
		{
			cout << "\n\t Enter Subject No  " << i + 1 << "\t";
			cin >> subjects[i];
			cout << "\n=======================================";
			cout << "\n\t Enter Your Marks in Subject No  " << i + 1 << "\t";
			cin >> marks[i];
			cout << endl;
		}
	}
	void display()
	{
		cout << "\n\t Name : " << name << "  ID : " << id;
		for (int i = 0; i < n; i++)
		{
			cout << "\n\t Subject No  " << i + 1 << " is : " << subjects[i] << "|  " << marks[i];
		}
	}
	~student()
	{
		delete[] subjects;
		delete[] marks;
	}
};
int main()
{
	student s[3];
	for (int i = 0; i < 3; i++)
	{
		s[i].input();
		s[i].subs();
	}
	cout << "\n============= Student Details ========";
	for (int i = 0; i < 3; i++)
	{
		s[i].display();
	}
	return 0;
}