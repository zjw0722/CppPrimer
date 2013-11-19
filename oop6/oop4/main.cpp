/*
** ��ֵ�������=������
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
		// ��Ϊͬһ��������ֱ�ӷ��ؼ���
		if(this == &student) // ע��������Ҫ��ָ��Ƚϣ���Ϊû��ʵ�ֶ���Ƚϵ��������
		{
			cout<< "\tExact the same object." << endl;
			return *this;
		}
		delete pName; // �������ͷ���Դ
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