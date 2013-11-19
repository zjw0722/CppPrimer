#include <iostream>

using namespace std;

class Animal
{
public:
	void walk()
	{
		cout << "Animal walk.\n";
	}
	void walk(int walkWay)
	{
		switch(walkWay)
		{
		case 0:
			cout << "Animal jump...\n";
			break;
		case 1:
			cout << "Animal fly...\n";
			break;
		default:
			cout << "Animal scrawling...\n";
		}
	}
	void sleep()
	{
		cout << "Animal sleeping..." << endl;
	}
};
class Human:public Animal
{
public:
	void sleep()
	{
		cout << "Human sleep, lying...\n";
	}
};

int main()
{
	Animal *pAnimal = NULL;
	Animal animal;
	Human human;

	pAnimal = &animal;
	pAnimal->sleep();

	pAnimal = &human;
	pAnimal->sleep();

	Human *pHuman = &human;
	pHuman->sleep();

	pHuman->walk(1);
	pHuman->walk();

	int c;
	cin >> c;
	return 0;
}