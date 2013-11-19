/*
** 重载运算符，返回不同类型的差别
*/
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
	Complex(const Complex &c) // 拷贝构造函数
	{
		real = c.real;
		image = c.image;
		cout << "copy constructing..." << endl;
	}
public:
	Complex operator+(const Complex &c)
	{
		Complex complexTemp;
		complexTemp.real = real + c.real;
		complexTemp.image = image + c.image;
		return complexTemp; // 此时会调用拷贝构造函数，构造一个临时对象
	}
	Complex& operator-(const Complex &c)
	{
		real -= c.real;
		image -= c.image;
		return *this;
	}
	void displayComplex()
	{
		if(image >= 0)
			cout << "(" << real << "+" << image << "i" << ")";
		else
			cout << "(" << real << image << "i" << ")";
	}
private:
	double real;
	double image;
};
int main()
{
	Complex c, c1(1.1, 2.2), c2(3.3, 4.4);
	(c1 + c2).displayComplex();
	cout << "Before c1 - c2" << endl;
	c1.displayComplex();
	cout << endl;
	cout << "After c1 - c2" << endl;
	(c1 - c2).displayComplex();
	cout << endl;
	int i;
	cin >> i;
	return 0;
}