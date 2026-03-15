#include<iostream>
#include<windows.h>
#include<fstream>
#include<conio.h>
using namespace std;

void menu();
class staff
{
	int n;
	int* ids = nullptr;
	int* salaries = nullptr;
	string* names = nullptr;
	static ofstream data;
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
		system("cls");
	}
	void output()
	{
		if (ids == nullptr)
		{
			cout << "\n====== Enter Details Before Displaying ============================" << endl;
			Sleep(500);
			system("cls");
	        return;	
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
			Sleep(900);
			system("cls");
			return;
		
		}
        else
		{
		cout << "\n============ Enter Staff Member's ID :\t";
		cin >> id;
		bool found = false;
			while (exit == false)
			{
				for (int i = 0; i < n; i++)
				{
					if ( id == ids[i])
					{
						found = true;
						exit = true;
						cout << "\n============  Staff Member Results  ======================";
						cout << "\n== Name : " << names[i] << " ==============================";
						cout << "\n== ID : " << ids[i] << " ==================================";
						cout << "\n== Salary : " << salaries[i] << " =========================";
						cout << "\n==========================================================="<<endl;
						break;
					}
				}
				if (!found)
				{
					cout << "\n======== ID YOU ENTERED WAS INCORRECT !!!!, Please Retry :\t";
					cin >> id;
					system("cls");
					exit = false;
				}
			}
		}
	}
	static void file_open()
	{
		data.open("data.txt");
	
	}
	void data_insert()
	{
		data << "\n==================== Details =================================";
		for (int i = 0; i < n; i++)
		{
			data << "\n============ Staff Member "<< i + 1 << " =================";
			data << "\n== Name : " << names[i] ;
			data << "\n== ID : " << ids[i] ;
			data << "\n== Salary : " << salaries[i] ;
			data << "\n===========================================================" << endl;
		}
	}
	static void file_close()
	{
		data.close();
	}
	void save()
	{
		if (ids == nullptr)
		{
			cout << "\n====== Enter Details Before Displaying ============================" << endl;
			Sleep(1500);
			system("cls");
			return;
		}
		else
		{
			file_open();
			data_insert();
			file_close();
		}
	}
	~staff()
	{
		delete[]names;
		delete[]ids;
		delete[]salaries;
	}
};
ofstream staff::data;
void menu(staff&a)
{
	char ans;
	bool stop = false;
	while (stop == false)
	{
		cout << "\n============================================== Welcome To Staff Portal ===================================================";
		cout << "\n================================================= Select an Option =======================================================";
		cout << "\n== (A) Add Staff Details == (B) Display Staff Details == (C) Look Up a Staff Member ====== (D) Save Data to a File =======" << endl;
		ans = _getch();
		char ent;
		if (ans == 'a' || ans == 'A')
		{
			system("cls");
			a.input();
			
		}
		else if (ans == 'b' || ans == 'B')
		{
			system("cls");
			a.output();
			cout << "\n\n========================= Press Enter to Continue....."<<endl;
			ent = _getch();
			if (ent == 13)
			{
				system("cls");
				continue;
				
			}	
		}
		else if (ans == 'c' || ans == 'C')
		{
			system("cls");
			a.search();
		}
		else if (ans == 'd' || ans == 'D')
		{
			system("cls");
			cout << "\n======================= Data Saved to the File ";
			a.save();
			Sleep(500);
		}
		else if (ans == 27)
		{
			system("cls");
			cout << "\n Press again to Exit" << endl;
			exit(0);
		}
		else
		{
			cout << "\n=============== Please Enter a Valid Input :\t";
			cin >> ans;
			system("cls");
			stop = false;
		}
	}
}
int main()
{
	staff s;
	menu(s);
}