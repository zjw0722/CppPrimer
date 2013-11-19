#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
	Employee(char name[], int id)
	{
		this->id = id;
		pName = new char[strlen(name) + 1];
		strcpy(pName, name);
	}
	virtual ~Employee()
	{
		cout << "deleting(Employee)...:" << pName << endl;
		delete [] pName;
	}
public:
	int getID()
	{
		return id;
	}
	const char *getName()
	{
		return pName;
	}
	virtual int pay() = 0;
	virtual void print() = 0;
protected:
	char *pName;
	int id;
};
class Manager:public Employee
{
public:
	Manager(char name[], int id, int salary):Employee(name, id)
	{
		this->salary = salary;
	}
	~Manager()
	{
		cout << "deleting(Manager)..." << endl;
	}
public:
	int getSalary()
	{
		return salary;
	}
	void setSalary(int Salary)
	{
		this->salary = salary;
	}
	// override
	int pay()
	{
		return salary;
	}
	void print()
	{
		cout << "name:" << pName << ", ID:" << id << ", pay:" << pay() << endl;
	}
protected:
	int salary;
};
class HourlyWorker:public Employee
{
public:
	HourlyWorker(char name[], int id, int wage, int hours)
		:Employee(name, id)
	{
		this->wage = wage;
		this->hours = hours;
	}
	~HourlyWorker()
	{
		cout << "deleting(HourlyWorker)..." << endl;
	}
public:
	int getWage()
	{
		return wage;
	}
	void setWage(int wage)
	{
		this->wage = wage;
	}
	int getHours()
	{
		return hours;
	}
	void setHours(int hours)
	{
		this->hours = hours;
	}
	// override
	int pay()
	{
		return wage*hours;
	}
	void print()
	{
		cout << "name: " << pName << ", ID:" << id << ", pay:" << pay() << endl;
	}
protected:
	int wage;
	int hours;
};
int main()
{
	{
		Employee *pEmArray[] = {
			new Manager("zhang", 101, 3900),
			new HourlyWorker("li", 111, 20, 8*20),
			new HourlyWorker("wang", 112, 25, 8*20)
		};
		int total = sizeof(pEmArray)/sizeof(Employee*);
		for(int i = 0;i <total;i++)
		{
			pEmArray[i]->print();
			delete pEmArray[i];
		}
	}
	int c;
	cin >> c;
	return 0;
}