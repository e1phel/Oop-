#include<iostream>
#include<fstream>
using namespace std;

class Employee
{
    int id,salary;
    string name;
	static ofstream records;
public:
	static void openfile() 
	{
		records.open("records.txt");
	}
	void input()
	{
		cout << "\n Enter Your Name, ID and Salary";
		cin >> name >> id >> salary;
	}
	void output()
	{
		if (records.is_open())
		{
			records << "\n Name : " << name << "\t ID : " << id << "\t Salary : " << salary << endl;
		}
	}
	static void closefile()
	{
		cout << "\n Records Stored in the File.";
		records.close();
	}
	~Employee(){}
};
int main()
{
	Employee e[3];
	Employee::openfile();
	for (int i = 0; i < 3; i++)
	{
		e[i].input();
	}
	for (int i = 0; i < 3; i++)
	{
		e[i].output();
	}
	Employee::closefile();
	return 0;
}
