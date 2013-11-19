#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	Person(char *name, int age)
	{
		pName = new char[strlen(name) + 1];
		strcpy(pName, name);
		this->age = age;
	}
	~Person()
	{
		delete [] pName;
		pName = NULL;
	}
	void showName()
	{
		cout << pName << endl;
	}
	void showAge()
	{
		cout << age << endl;
	}
private:
	char *pName;
	int age;
};
class Student: public Person
{
public:
	Student(char *name, int age, int id, char *pSpeciality)
		:Person(name, age)
	{
		this->id = id;
		this->pSpeciality = new char[strlen(pSpeciality) + 1];
		strcpy(this->pSpeciality, pSpeciality);
	}
	~Student()
	{
		delete [] pSpeciality;
		pSpeciality = NULL;
	}
	void showID()
	{
		cout << id << endl;
	}
private:
	int id;
	char *pSpeciality;
};
int main()
{
	Student s("zhangsan", 20, 1, "Computer");
	s.showName();
	s.showAge();
	s.showID();
	return 0;
}