#include<iostream>

using namespace std;

class staff
{
	int id,salary;
	string name;
	staff()
	{
		id = 0;
		salary = 0;
		name = " ";
	}
	void input()
	{
		cout << "\n Enter Your Name : ";
		cin >> name;
		cout << "\n Enter Your ID : ";
		cin >> id;
		cout << "\n Enter your salary";
		cin >> salary;
	}
	void output()
	{
		cout << "\n==================== Details ==================";
		cout << "\n== Name : " << name << "=======================";
		cout << "\n== ID : " << id << "===========================";
		cout << "\n== Salary : " << salary << "===================";
		cout << "\n===============================================";
	}
};