#include <iostream>

using namespace std;

class Animal
{
public:
	virtual void walk()
	{
		cout << "Animal walk." << endl;
	}
	void walk(int walkWay)
	{
		switch(walkWay)
		{
		case 0:
			cout << "Animal jump..." << endl;
			break;
		case 1:
			cout << "Animal fly..." << endl;
			break;
		default:
			cout << "Animal scraling..." << endl;
		}
	}
	virtual void sleep()
	{
		cout << "Animal sleeping..." << endl;
	}
private:
};

class Human:public Animal
{
public:
	virtual void walk()
	{
		cout << "Human walk by feet." << endl;
	}
	virtual void sleep()
	{
		cout << "Human sleep, lying..." << endl;
	}
	virtual void talk()
	{
		cout << "Human talking..." << endl;
	}
private:
};
int main()
{
	Animal *pAnimalArray[] = {
		new Animal, new Human
	};
	for(int i = 0;i < 2;i++)
	{
		pAnimalArray[i]->walk();
		pAnimalArray[i]->sleep();
		delete pAnimalArray[i];
	}
	int c;
	cin >> c;
	return 0;
}