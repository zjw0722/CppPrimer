#include <iostream>

using namespace std;

class Animal
{
public:
	void getName()
	{
		cout << "Animal.\n";
	}
private:
};
class Cat:public Animal
{
public:
	void getName()
	{
		cout << "True Name:Cat.\n";
	}
	void getAnimal()
	{
		Animal::getName();
	}
private:
};

int main()
{
	Cat cat;

	Animal animal(cat);
	animal.getName();
	cat.getName();
	cout << "Now get the animal name:";
	cat.getAnimal();
	int c;
	cin >> c;
	return 0;
}