/*
** º¯Êı·û¡°£¨£©¡±ÖØÔØ
*/
#include <iostream>

using namespace std;

class Student 
{
public:
	Student(int chinese, int math, int english)
	{
		this->chinese = chinese;
		this->math = math;
		this->english = english;
	}
	~Student()
	{ }
public:
	void operator()(int index = 0)
	{
		switch(index)
		{
		case 0:
			cout << "chinese:" << chinese << endl;
			break;
		case 1:
			cout << "math:" << math << endl;
			break;
		case 2:
			cout << "english:" << math << endl;
			break;
		default:
			cout << "not found" << endl;
		}
	}
private:
	int chinese;
	int math;
	int english;
};
int main()
{
	Student student(80, 90, 92);
	student();
	student(0);
	student(1);
	student(2);
	student(3);
	student(4);

	int i;
	cin >> i;
	return 0;
}