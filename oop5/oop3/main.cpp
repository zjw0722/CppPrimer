#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template<typename T>
void swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
struct Job
{
	char name[40];
	double salary;
	int floor;
};
// 显示完全具体化
template<>
void swap<Job>(Job &j1, Job &j2)
{
	char name[40] = {'\0'};
	double salary;
	int floor;
	// 交换工作名称
	strcpy(name, j1.name);
	strcpy(j1.name, j2.name);
	strcpy(j2.name, name);
	// 交换年薪
	salary = j1.salary;
	j1.salary = j2.salary;
	j2.salary = salary;
	// 交换级别
	floor = j1.floor;
	j1.floor = j2.floor;
	j2.floor = floor;
}

void show(const Job &j)
{
	cout << "(" << j.name << ", " << j.salary << "," << j.floor << ")" << endl;
}
int main()
{
	int i = 1, j = 2;
	cout << "---- ordinary function template called ----" << endl;
	cout << "(i, j) = " << "(" << i << ", " << j << ")" << endl;
	swap(i, j);
	cout << "(i, j) = " << "(" << i << ", " << j << ")" << endl;

	Job weldor = {"Wedding", 50000, 5};
	Job electrician = {"Electrician", 60000, 6};
	cout << "---- explicit specialization function template called ----" << endl;
	show(weldor);
	show(electrician);
	
	swap(weldor, electrician);
	show(weldor);
	show(electrician);

	int c;
	cin >> c;
	return 0;
}