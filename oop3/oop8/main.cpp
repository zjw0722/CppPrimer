#include <iostream>

using namespace std;

class Employee
{
public:
	Employee(char *name)
	{
		no = companyEmployee++;
		grade = 1;
		pName = new char[strlen(name) + 1];
		strcpy(pName, name);
		totalPay = 0.0;
	}
	~Employee()
	{
		delete [] pName;
	}
public:
	void pay(){}
	void promote(int increment)
	{
		grade += increment;
	}
	void displayInfo(){}
protected:
	char *pName;
	int no;
	int grade;
	double totalPay;
	static int companyEmployee;
private:
};
int Employee::companyEmployee = 100; // ��̬������ʼ��

class Technician:public Employee
{
public:
	Technician(char *name, int workHours = 0):Employee(name)
	{
		rate = 100; // 100Ԫ/Сʱ
		this->workHours = workHours;
	}
	void setWorkhours(int workHours)
	{
		this->workHours = workHours;
	}
	void pay()
	{
		totalPay = workHours*rate;
	}
	void displayInfo()
	{
		promote(2);
		cout << "��ְ������Ա��" << pName << "����ţ�" << no 
			<< "������" << grade << "���Ѹ����¹��ʣ�" 
			<< totalPay << endl;
	}
private:
	double rate;
	int workHours;
};
class SaleMan:virtual public Employee
{
public:
	SaleMan(char *name, int sales = 0):Employee(name)
	{
		ratio = 0.004;
		this->sales = sales;
	}
	void setSales(double sales)
	{
		this->sales = sales;
	}
	void pay()
	{
		totalPay = sales*ratio;
	}
	void displayInfo()
	{
		promote(2);
		cout << "����Ա��" << pName << "����ţ�" << no 
			<< "������" << grade << "���Ѹ����¹��ʣ�" 
			<< totalPay << endl;
	}
protected:
	double sales;
	double ratio;
};
class Manager:virtual public Employee
{
public:
	Manager(char *name, int monthlyPay = 6000):Employee(name)
	{
		this->monthlyPay = monthlyPay;
	}
	void setMonthlyPay(double monthlyPay)
	{
		this->monthlyPay = monthlyPay;
	}
	void pay()
	{
		totalPay = monthlyPay;
	}
	void displayInfo()
	{
		promote(3);
		cout << "����" << pName << "����ţ�" << no 
			<< "������" << grade << "���Ѹ����¹��ʣ�" 
			<< totalPay << endl;
	}
protected:
	double monthlyPay;
};
class SaleManager:public SaleMan, public Manager
{
public:
	SaleManager(char *name):SaleMan(name), Manager(name), Employee(name)
	{
		monthlyPay = 4000;
		ratio = 0.002;
	}
	void pay()
	{
		totalPay = monthlyPay + sales*ratio;
	}
	void displayInfo()
	{
		promote(2);
		cout << "���۾���" << pName << "����ţ�" << no
			<< "������" << grade << "���Ѹ����¹��ʣ�" 
			<< totalPay << endl;
	}
private:
};

int main()
{
	Technician t("zhang san");
	t.setWorkhours(100);
	t.pay();
	t.displayInfo();

	SaleManager sm("li si");
	sm.setMonthlyPay(7000);
	sm.setSales(1000);
	sm.pay();
	sm.displayInfo();
	int c;
	cin >> c;
	return 0;
}