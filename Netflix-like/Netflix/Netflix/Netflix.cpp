#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<fstream>

using namespace std;

class profile
{
protected:
	string name, gender ;
	string genres[3] = { " "," ", " " };
	int watched;
	string history[10];
	int pin;
public:
	profile()
	{
		name = " ";
		gender = " ";
		watched = 0;
		pin = 0;
	}
	void create_prof()
	{
		cout << "\n================== Enter Your Details ====================";
		cout << "\n==================== Name :\t";
		cin >> name;
		cout << "\n==================== Gender :\t";
		cin >> gender;
		cout << "\n==================== Set a PIN :\t";
		cin >> pin;
		cout << "\n==================== Pick Any Three Genres :\t";
		cout << "\n===== (i) Action ===== (ii) Fantasy ===== (iii) Sci-Fi ===";
		cout << "\n===== (iv) Adventure = (v) Classics ===== (vi) Drama =====";
		cout << "\n===== (vii) History ===== (vii) Horror == (ix) Animated =="<<endl;
		for (int i = 0; i < 3; i++)
		{
			cin>>genres[i];
			
		}	
	}
	string get_name()
	{
		return name;
	}
	int get_pin()
	{
		return pin;
	}
	void feed()
	{
		cout << "\n========================= Featured =========================";
		for (int j = 0; j < 3; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				cout << "\n===========> " << genres[j] << " Film  " << i + 1;
			}
		}
		cout << "\n================= What are You Watching today ?(press w)" << endl;
		char get = _getch();
		bool quit = false;
		string choice;
		char move;
		if (get == 'w' || get == 'W')
		{
			while (quit == false)
			{
				for (int i = 0; i < 10; i++)
				{
					cout << "\n==== Film Name";
					cin >> choice;
					history[watched] = choice;
					watched++;
					cout << "\n=== Press E to Continue or Esc to Move back";
					move = _getch();
					if (move == 27)
					{
						quit = true;
						break;
					}
					else if (move == 'e')
					{
						continue;
					}
				}
			}
		}
	}
	void disp_history()
	{
		cout << "\n========================= History =========================";
		for (int i = 0; i < watched + 1; i++)
		{
			cout << "\n==================="<< history[i];
		}
	}
	~profile(){};
};
class account :public profile
{
protected:
	int counter;
	profile p[4];
public:
	account() :counter(0) {};
	void acc()
	{
		if (counter >= 4)
		{
			cout << "================= Profile Limit Reached =================";
		}
		else
		{
			p[counter].create_prof();
			counter++;
		}
	}
	void fyp()
	{
		int prof=0,check;
		cout << "\n==================== Choose a Profile =================";
		for (int i = 0; i < counter; i++)
		{
			cout << "\n==" << p[i].get_name() << "==" << "\t";
		}
		cout << endl;
		cin >> prof;
		cout << "\n============ Enter Profile PIN :" << endl;
		cin >> check;
		bool end = false;
		while (end == false)
		{
			if (check == p[prof - 1].get_pin())
			{
				p[prof - 1].feed();
				end = true;
			}
			else
			{
				cout << "\n============  Wrong Pin , Please Re-Enter : ";
				cin >> check;
			}
		}
		
	}
	void run()
	{
		cout << "=================== Movies ========================";
		cout << "\n  ========== Create Account(enter) =========           ";
		cout << "\n      ========== Quit(Esc) =========           " << endl;
		char input = _getch();
		if(input == 13)
		{
			cout << "\n============ Create a Profile ===============";
			acc();
			bool quit = false;
			char c;
			while (quit == false)
			{
				cout << "\n================ Home ===================";
				cout << "\n=(a) History == (b) New Profile =(f) Load Fyp = (Esc) Exit="<<endl;
				cin >> c;
				if (c == 'a')
				{
					p[counter].disp_history();
				}
				else if (c == 'b' || c == 'B')
				{
					acc();
				}
				else if (c == 'f' || c == 'F')
				{
					fyp();
				}
				else if (c == 27)
				{
					return;
				}
			}
		}
		else if(input == 27)
		{
			exit(0);
		}

	}
};
int main()
{
	account a;
	a.run();
	return 0;
}