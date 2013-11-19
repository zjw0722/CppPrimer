/*
** 类型转换运算符重载，从对象到内置类型
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
public:
	operator double()
	{
		return real;
	}
private:
	double real;
	double image;
};

int main()
{
	double d = 1.1;
	Complex c(4.0, 5.0);

	d += c; // 此时c.operator double()返回4.0
	cout << d << endl;

	int i;
	cin >> i;
	return 0;
}