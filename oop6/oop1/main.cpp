#include <iostream>

using namespace std;

class Complex
{
public:
	Complex(double real = 0.0, double image = 0.0)
	{
		this->real = real;
		this->image = image;
	}
public:
	Complex operator+(const Complex &c)
	{
		Complex complexTemp;
		complexTemp.real = real + c.real;
		complexTemp.image = image + c.image;
		return complexTemp;
	}
	Complex operator-(const Complex &c)
	{
		Complex complexTemp;
		complexTemp.real = real - c.real;
		complexTemp.image = image - c.image;
		return complexTemp;
	}
	void displayComplex()
	{
		if(image > 0)
			cout << "(" << real << '+' << image << 'i' << ")";
		else
			cout << "(" << real << image << 'i' << ")";
	}
private:
	double real;
	double image;
};

int main()
{
	Complex c, c1(1.1, 2.2), c2(3.3, 4.4);
	c = c1 + c2;
	c1.displayComplex();
	cout << "+";
	c2.displayComplex();
	cout << "=";
	c.displayComplex();
	
	int i;
	cin >> i;
	return 0;
}