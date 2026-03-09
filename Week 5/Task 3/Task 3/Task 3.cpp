#include<iostream>

using namespace std;

class circle
{
	float radius, area;
public:
	circle() : radius(0), area(0) {}
	void get()
	{
		cout << "\n Enter Radius : ";
		cin >> radius;
	}
	void calculate()
	{
		area = (3.14) * (radius * radius);
	}
	void disp_area()
	{
		cout << "\n Area of the Circle is :   " << area<<" cm";
	}
	~circle() {}
};
int main()
{
	circle c;
	c.get();
	c.calculate();
	c.disp_area();
	return 0;
}
