#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	Person()
	{
		pName = NULL;
	}
	Person(char *name, int age)
	{
		pName = new char[strlen(name) + 1];
		strcpy(pName, name);
		this->age = age;
	}
	Person& operator=(const Person &person)
	{
		if(this == &person)
			return *this;
		delete pName;
		pName = new char[strlen(person.pName) + 1];
		strcpy(pName, person.pName);
		age = person.age;
		return *this;
	}
	~Person()
	{
		cout << "deleting base sub object.\n" 
			<< pName << endl;
		delete [] pName;
		pName = NULL;
	}
public:
	void showPersonInfo()
	{
		cout << "(" << pName << " ," << age << ")\n";
	}
private:
	char *pName;
	int age;
};
class Student:public Person
{
public:
	Student(char *name, int age, int id, char *pSpeciality)
		:Person(name, age)
	{
		this->id = id;
		this->pSpeciality = new char[strlen(pSpeciality) + 1];
		strcpy(this->pSpeciality, pSpeciality);
	}
	Student()
	{
		pSpeciality = NULL;
	}
	Student& operator=(const Student &s)
	{
		Person::operator=(s);
		id = s.id;
		pSpeciality = new char[strlen(s.pSpeciality) + 1];
		strcpy(pSpeciality, s.pSpeciality);
		return *this;
	}
	~Student()
	{
		cout << "deleting derived class sub object.\n" 
			<< pSpeciality << endl;
		delete [] pSpeciality;
		pSpeciality = NULL;
	}
public:
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
	{
		Person p("person", 28);
		Student s("student", 21, 1, "computer");
		Student s1;
		s1 = s;
		cout << "before executing \"p = s;\"";
		p.showPersonInfo();
		p = s;
		cout << "after executing \"p = s;\"";
		p.showPersonInfo();
	
		Person *pPerson = new Student("wangwu", 22, 2, "computer_soft");
		pPerson->showPersonInfo();

		delete pPerson;
	}
	int c;
	cin >> c;
	return 0;
}