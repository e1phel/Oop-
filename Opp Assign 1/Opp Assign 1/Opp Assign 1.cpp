#include<iostream>

using namespace std;

class character
{
public:
	int id, hp;
	string name;
	int damage, posture,stamina,focus;
	character(int id = 0, int hp = 100,string=" ")
	{ }
	void create_acc()
	{
		cout << "\n== Enter Your Username :\t";
		cin >> name;
		cout << "\n== Enter Your ID :\t";
		cin >> id;
	}
	~character(){}
};
class Vagabond : public character
{
protected:
	string weapon;
public:
	Vagabond()
	{
		weapon = "N/A";
		damage = 0;
		posture = 80;
		stamina = 200;
		focus = 30;
	}
	void choose_weapon()
	{
		char choice;
		cout << "\n================= Pick a Starting Weapon ==============";
		cout << "\n======== SABER ======= Katana ========= Great Sword ===";
		cout << "\n========   A   =======   B    ===========   C   ======="<<endl;
		cin >> choice;
		if (choice == 'A' || choice == 'a')
		{
			weapon = "Saber";
			damage = 65;
			posture = 50;
			stamina -= 30;
		}
		else if (choice == 'B' || choice == 'b')
		{
			weapon = "Katana";
			damage  = 50;
			posture = 60;
			stamina -= 15;
		}
		else if (choice == 'C' || choice == 'c')
		{
			weapon = "Great Sword";
			damage = 85;
			posture = 35;
			stamina -= 65;
		}
		else
		{
			cout << "\n Invalid Input ! ";
		}
	}
	void disp()
	{
		cout << "\n=========================  Character Details  =========================";
		cout << "\n== Name : " << name << " --- " << id;
		cout << "\n== Class : Vagabond";
		cout << "\n== Weapon : " << weapon;
		cout << "\n== Damage : " << damage;
		cout << "\n== Stamina and Focus on Using Weapon : " << stamina << "\t" << focus;
		cout << "\n== Posture : " << posture;
	}
  ~Vagabond(){}
};
class Scholar : public character
{
protected:
	string spell,affinity;
public:
	Scholar()
	{
		damage = 0;
		posture = 55;
		stamina = 100;
		focus = 30;
	}
	void choose_spells()
	{
		char choice;
		cout << "\n=========================  Pick an Incantaion  =========================";
		cout << "\n======== Comet Azure ======= Destined Death ========= Flame Finnesse ===";
		cout << "\n============    A    ===========     B      =========     C   =========="<<endl;
		cin >> choice;
		if (choice == 'A' || choice == 'a')
		{
			spell = "Comet Azure";
			affinity = "Frost";
			damage = 25;
			stamina -= 10;
			focus -= 25;
		}
		else if (choice == 'B' || choice == 'b')
		{
			spell = "Destined Death";
			affinity = "Blight";
			damage = 50;
			stamina -= 15;
			focus -= 40;
		}
		else if (choice == 'C' || choice == 'c')
		{
			spell = "Flame Finnesse";
			affinity = "Fire";
			damage = 60;
			stamina -= 15;
			focus -= 60;
		}
		else
		{
			cout << "\n Invalid Input ! ";
		}
	}
	void disp()
	{
		cout << "\n=========================  Character Details  =========================";
		cout << "\n== Name : " << name << " --- " << id;
		cout << "\n== Class : Scholar";
		cout << "\n== Weapon : Staff With Spell : " << spell;
		cout << "\n== Damage : " << damage;
		cout << "\n== Spell Affinity : " << affinity;
		cout << "\n== Stamina and Focus on Using Weapon : " << stamina << "\t" << focus;
		cout << "\n== Posture : " << posture;
	}
	~Scholar(){}
};
class Ironeye : public character
{
protected:
	string bow,fire_rate,range;
public:
	Ironeye()
	{
		bow = "N/A";
		range = "N/A";
		fire_rate = "N/A";
		damage = 0;
		posture = 85;
		stamina = 250;
		focus = 50;
	}
	void choose_bow()
	{
		char choice;
		cout << "\n=========================  Pick a Bow  =========================";
		cout << "\n======== Dark Bow ======= Cross-Bow ========= Golem Bow ========";
		cout << "\n========     A    =======     B     =========      C   =========" << endl;
		cin >> choice;
		if (choice == 'A' || choice == 'a')
		{
			bow = "Dark Bow";
			damage = 30;
			stamina -= 7;
			focus -= 10;
			range = "Mid-Range";
			fire_rate = "Mid";

		}
		else if (choice == 'B' || choice == 'b')
		{
			bow = "Cross-Bow";
			damage = 18;
			stamina -= 2;
			focus -= 5;
			range = "Close-Range";
			fire_rate = "High";
		}
		else if (choice == 'C' || choice == 'c')
		{
	
			bow = "Golem Bow";
			damage = 65;
			stamina -= 45;
			focus -= 60;
			range = "Long-Range";
			fire_rate = "Low";
		}
		else
		{
			cout << "\n Invalid Input ! ";
		}
	}
	void disp()
	{
		cout << "\n=========================  Character Details  =========================";
		cout << "\n== Name : " << name<<" --- "<<id;
		cout << "\n== Class : Ironeye";
		cout << "\n== Weapon : "<<bow;
		cout << "\n== Damage : " << damage;
		cout << "\n== Range : " << range;
		cout << "\n== Fire_rate : " << fire_rate;
		cout << "\n== Stamina and Focus on Using Weapon : " << stamina << "\t" << focus;
		cout << "\n== Posture : " << posture;
	}
	~Ironeye() {}
};

int main()
{
	char pick;
	character c;
	cout << "\n=========================  Character Creation  =========================";
	c.create_acc();
	cout << "\n=========================     Pick a Class     =========================";
	cout << "\n========== Vagabond ============= Scholar ============= Ironeye ========";
	cout << "\n==========     A    =============    B    =============    C    ========"<<endl;
	cin >> pick;
	if (pick == 'A' || pick == 'a')
	{
		Vagabond*a = new Vagabond(); 
		a->choose_weapon();
		a->disp();
	}
	else if (pick == 'B' || pick == 'b')
	{
		Scholar*a = new Scholar();
		a->choose_spells();
		a->disp();
	}
	else if (pick == 'C' || pick == 'c')
	{
		Ironeye*a = new Ironeye();
		a->choose_bow();
		a->disp();
	}
	else
	{
		cout << "\n Invalid Input !";
	}
	char ans;
	cout << "\n Would you Like to Duplicate this Character";
	cin >> ans;
	return 0;
}