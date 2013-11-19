#include <iostream>

using namespace std;

class Vehicle
{
public:
	Vehicle(int power)
	{
		this->power = power;
	}
	virtual ~Vehicle()
	{
		cout << "deleting Vehicle sub object..." << endl;
	}
public:
	virtual void run()
	{
		cout << "Vehicle running..." << endl;
	}
private:
	int power;
};
class Plane:public Vehicle
{
public:
	Plane(int power, double height):Vehicle(power)
	{
		this->height = height;
	}
	virtual ~Plane()
	{
		cout << "deleting Plane sub object..." << endl;
	}
public:
	void run()
	{
		cout << "Plane fly..." << endl;
	}
private:
	double height;
};
int main()
{
	{
		Vehicle *pVehicle = new Plane(30, 3005);
		delete pVehicle;
	}
	int c;
	cin >> c;
	return 0;
}