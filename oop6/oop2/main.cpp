/*
** 重载全局运算符“+”、“-”，代码如下：
*/
#include <iostream>

using namespace std;

//class Complex;
//Complex operator+(const Complex &c1, const Complex &c2);
//Complex operator-(const Complex &c1, const Complex &c2);
// 我的疑问：声明为全局的有什么好处的，或者说有什么必要的么？
class Complex
{
public:
	Complex(double real = 0.0, double image = 0.0)
	{
		this->real = real;
		this->image = image;
	}
public:
	void displayComplex()
	{
		if(image >= 0)
			cout << "(" << real << '+' << image << 'i' << ")";
		else
			cout << "(" << real << image << 'i' << ")";
	}
	friend Complex operator+(const Complex &c1, const Complex &c2);
	friend Complex operator-(const Complex &c1, const Complex &c2);
private:
	double real;
	double image;
};

Complex operator+(const Complex &c1, const Complex &c2)
{
	Complex complexTemp;
	complexTemp.real = c1.real + c2.real;
	complexTemp.image = c1.image + c2.image;
	return complexTemp;
}
Complex operator-(const Complex &c1, const Complex &c2)
{
	Complex complexTemp;
	complexTemp.real = c1.real - c2.real;
	complexTemp.image = c1.image - c2.image;
	return complexTemp;
}
int main()
{
	Complex c, c1(1.1, 2.2), c2(3.3, 4.4);
	c = c1 + c2;
	c = c1 - c2; // operator-(c1, c2);
	c1.displayComplex();
	cout << "-";
	c2.displayComplex();
	cout << "=";
	c.displayComplex();
	cout << endl;

	int i;
	cin >> i;
	return 0;
}