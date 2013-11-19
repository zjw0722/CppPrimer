#include <iostream>

using namespace std;

class Base
{
public:
	Base(int a)
	{
		this->a = a;
		cout << "common base sub object being constructed.\n";
	}
	void show()
	{
		cout << a << endl;
	}
	~Base()
	{
		cout << "deleting common base sub object.\n";
	}
private:
	int a;
};
class B1:public Base
{
public:
	B1(int a, int b1):Base(a)
	{
		this->b1 = b1;
		cout << "base1 sub object being constructed.\n";
	}
	void showBase()
	{
		show();
	}
	~B1()
	{
		cout << "deleting base1 sub object.\n";
	}
private:
	int b1;
};
class B2:public Base
{
public:
	B2(int a, int b2):Base(a)
	{
		this->b2 = b2;
		cout << "base2 sub object being constructed.\n";
	}
	void showBase()
	{
		show();
	}
	~B2()
	{
		cout << "deleting base2 sub object.\n";
	}
private:
	int b2;
};
class D:public B2, public B1
{
public:
	D(int a1, int b1, int a2, int b2, int d):B1(a1, b1), B2(a2, b2)
	{
		this->d = d;
		cout << "derived sub object being constructed.\n";
	}
	void showB1Base()
	{
		B1::showBase();
	}
	void showB2Base()
	{
		B2::showBase();
	}
	~D()
	{
		cout << "deleting derived sub object.\n";
	}
private:
	int d;
};

int main()
{
	{
		D d(11, 2, 12, 3, 4);
		d.B1::show();
		d.B2::show();
		d.B1::showBase();
		d.B2::showBase();
		d.showB1Base();
		d.showB2Base();
	}
	int c;
	cin >> c;
	return 0;
}