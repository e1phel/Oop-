#include<iostream>
#include<conio.h>
#include<Windows.h>

using namespace std;

class frame
{
protected:
	char map[15][25];
public:
	void generate_map()
	{
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				map[i][j] = 'x';
			}
		}
	}
	void display_map()
	{

		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				cout<<map[i][j];
			}
			cout << endl;
		}
	}
};
class actor :public frame
{
protected:
	char sprite = '*',input;
	int x, y;
public:
	actor() :x(0), y(0),input(' ') {};
	void generate_pos()
	{
		srand(time(0));
	    x = rand() % 15;
	}
	void place_sprite()
	{
		generate_pos();
		map[y][x] = sprite;
	}
	void run()
	{
		generate_map();
		while (true)
		{
			place_sprite();
			display_map();
			input = _getch();
			static int i = 1;
			if (input == 'a' || input == 'A')
			{
				map[y + i][x] = sprite;
				i++;
				map[y][x] = 'x';
				
			}
			cout << endl;
		}
	}
};
int main()
{
	actor a;
	a.run();
}
