#include<iostream>
#include<windows.h>
using namespace std;

void menu();
class staff
{
	int n;
	int* ids = nullptr;
	int* salaries = nullptr;
	string* names = nullptr;
public:
	void input()
	{
		cout << "\n========= Enter the NO of Staff Members in this Compaany :\t";
		cin >> n;
		ids = new int[n];
		names = new string[n];
		salaries = new int[n];
		for (int i = 0; i < n; i++)
		{
			cout << "\n========= Enter Details For Staff Member " << i + 1 << " =======";
			cout << "\n========= Enter Your Name : \t";
			cin >> names[i];
			cout << "\n========= Enter Your ID : \t";
			cin >> ids[i];
			cout << "\n========= Enter Your Salary : \t";
			cin >> salaries[i];
			cout << "\n==============================================================="<<endl;
		}
	}
	void output()
	{
		if (ids == nullptr)
		{
			cout << "\n====== Enter Details Before Displaying ============================" << endl;
	    menu();	
		}
		else
		{
			cout << "\n==================== Details =================================";
			for (int i = 0; i < n; i++)
			{
				cout << "\n============ Staff Member " << i + 1 << " =================";
				cout << "\n== Name : " << names[i] << " ==============================";
				cout << "\n== ID : " << ids[i] << " ==================================";
				cout << "\n== Salary : " << salaries[i] << " =========================";
				cout << "\n==========================================================="<<endl;
			}
		}	
	}
	void search()
	{
		int id;
		bool exit = false;
		
		if (ids == nullptr)
		{
			cout << "\n====== Enter Details Before Searching ============================" << endl;
			menu();
		}
        else
		{
		cout << "\n============ Enter Staff Member's ID :\t";
		cin >> id;
			while (exit == false)
			{
				for (int i = 0; i < n; i++)
				{
					if (id == ids[i])
					{
						cout << "\n============  Staff Member Results  ======================";
						cout << "\n== Name : " << names[i] << " ==============================";
						cout << "\n== ID : " << ids[i] << " ==================================";
						cout << "\n== Salary : " << salaries[i] << " =========================";
						cout << "\n==========================================================="<<endl;
						exit = true;
					}
					else
					{
						cout << "\n======== ID YOU ENTERED WAS INCORRECT !!!!, Please Retry :\t";
						cin >> id;
						exit = false;
					}
				}
			}
		}
	}
	~staff()
	{
		delete[]names;
		delete[]ids;
		delete[]salaries;
	}
};
void menu()
{
	char ans;
	staff s;
	bool stop = false;
	while (stop == false)
	{
		cout << "\n======================== Welcome To Staff Portal ====================================";
		cout << "\n=========================== Select an Option ========================================";
		cout << "\n== (A) Add Staff Details == (B) Display Staff Details == (C) Look Up a Staff Member =" << endl;
		cin >> ans;
		if (ans == 'a' || ans == 'A')
		{
			s.input();
			
		}
		else if (ans == 'b' || ans == 'B')
		{
			s.output();
			
		}
		else if (ans == 'c' || ans == 'C')
		{
			s.search();
			
		}
		else
		{
			cout << "\n=============== Please Enter a Valid Input :\t";
			cin >> ans;
			stop = false;
		}
	}
}
int main()
{
	menu();
}