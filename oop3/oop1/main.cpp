#include <iostream>

using namespace std;

class EmbededA_Root
{
public:
	EmbededA_Root()
	{
		cout << "1_a:constructing embedded sub object A.\n";
	}
	~EmbededA_Root()
	{
		cout << "1_a:destructing embedded sub object A.\n";
	}
private:
};
class EmbededB_Root
{
public:
	EmbededB_Root()
	{
		cout << "1_b:constructing embedded sub object B.\n";
	}
	~EmbededB_Root()
	{
		cout << "1_b:destructing embedded sub object B.\n";
	}
private:
};
class RootBase
{
public:
	RootBase():embedA(), embedB()
	{
		cout << "1:constructing root base sub object.\n";
	}
	~RootBase()
	{
		cout << "1:destructing root base sub object.\n";
	}
private:
	EmbededA_Root embedA;
	EmbededB_Root embedB;
};
class Base:RootBase
{
public:
	Base()
	{
		cout << "2:constructing base sub object.\n";
	}
	~Base()
	{
		cout << "2:destructing base sub object.\n";
	}
private:
};
class Derived:public Base
{
public:
	Derived()
	{
		cout << "3:constructing derived sub object.\n";
	}
	~Derived()
	{
		cout << "3:destructing derived sub object.\n";
	}
private:
};

int main()
{
	{
		Derived d;
	}
	int c;
	cin >> c;
	return 0;
}