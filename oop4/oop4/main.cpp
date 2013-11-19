#include <iostream>

using namespace std;

const double PI = 3.14159;

class Shape
{
public:
	virtual void show() = 0;
	virtual double area() = 0;
	virtual ~Shape()
	{}
};
class Shape2D:public Shape
{
public:
	Shape2D(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
protected:
	double x;
	double y;
};
class Shape3D:public Shape
{
public:

protected:
	double x;
	double y;
	double z;
};
class Circle:public Shape2D
{
public:
	Circle(double x, double y, double radius):Shape2D(x, y)
	{
		this->radius = radius;
	}
	virtual void show()
	{
		cout << "Circle center: (" << x << ", " << y << ")" << endl;
	}
	virtual double area()
	{
		return PI*radius*radius;
	}
private:
	double radius;
};
class Sphere:public Shape3D
{
public:
	Sphere(double x, double y, double z, double radius)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->radius = radius;
	}
	void show()
	{
		cout << "Sphere center:(" << x << ", " << y << ", " << z << ")" << endl;
	}
	double area()
	{
		return PI*radius*radius*radius;
	}
private:
	double radius;
};
int main()
{
	{
		Shape *pShape = NULL;
		Shape *pShapeArray[] = {
			new Circle(1.0, 2.0, 3.0),
			new Sphere(1.0, 2.0, 3.0, 4.0)
		};
		for(int i = 0;i < 2;i++)
		{
			pShapeArray[i]->show();
			cout << "\t area = " << pShapeArray[i]->area() << endl;
			delete pShapeArray[i];
		}
	}
	int c;
	cin >> c;
	return 0;
}