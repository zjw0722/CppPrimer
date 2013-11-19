/*
** 类型转换运算符重载，从内置类型到对象
*/
#include <iostream>

using namespace std;

class Complex
{
public:
	Complex(double real, double image)
	{
		this->real = real;
		this->image = image;
	}
	Complex(const Complex &c)
	{
		real = c.real;
		image = c.image;
		cout << "copy constructor called..." << endl;
	}
	Complex(double real)
	{
		this->real = real;
		this->image = 0;
		cout << "one parameter called..." << endl;
	}
	~Complex()
	{}
public:
	Complex& operator+=(const Complex &c)
	{
		real += c.real;
		image += c.image;
		cout << "overload operator+= called..." << endl;
		return *this;
	}
	void show()
	{
		cout << real;
		if(image >= 0)
			cout << "+" << image << "i" << endl;
		else
			cout << image << "i" << endl;
	}
private:
	double real;
	double image;
};

int main()
{
	Complex c1(0, 1.1);
	c1 += 3.3;
	c1.show();

	int i;
	cin >> i;
	return 0;
}