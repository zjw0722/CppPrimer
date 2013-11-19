#include <iostream>

using namespace std;

class Animal
{
public:
	Animal()
	{
		cout << "creating Animal sub object.\n";
	}
	~Animal()
	{
		cout << "destructing Animal sub object.\n";
	}
private:
};
class Cat:public Animal
{
public:
	Cat()
	{
		cout << "creating Cat sub object.\n";
	}
	~Cat()
	{
		cout << "destructing Cat sub object.\n";
	}
private:
};

int main()
{
	{
		Cat c;
	}
	int i;
	cin >> i;
	return 0;
}