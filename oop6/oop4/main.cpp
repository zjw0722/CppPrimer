/*
** 赋值运算符“=”重载
*/
#include <iostream>
#include <cstring>

using namespace std;

class Student
{
public:
	Student(char *name = "")
	{
		pName = new char[strlen(name) + 1];
		strcpy(pName, name);
	}
	~Student()
	{
		delete pName;
		pName = NULL;
	}
public:
	Student &operator=(const Student &student)
	{
		cout << "assignment called..." << endl;
		// 若为同一个对象则直接返回即可
		if(this == &student) // 注意这里需要用指针比较，因为没有实现对象比较的运算符呢
		{
			cout<< "\tExact the same object." << endl;
			return *this;
		}
		delete pName; // 否则，先释放资源
		pName = new char[strlen(student.pName) + 1];
		strcpy(pName, student.pName);
		return *this;
	}
	void show()
	{
		cout << pName << endl;
	}
private:
	char *pName;
};

int main()
{
	Student s1, s2("zhangsan");
	s1 = s1;

	s1 = s2;
	s1.show();
	
	int i;
	cin >> i;
	return 0;
}