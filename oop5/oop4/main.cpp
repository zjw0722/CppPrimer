/*
 * 类模板完全特化的应用
*/

#include <iostream>

using namespace std;

template<typename T>
class Compare
{
public:
	Compare(T x, T y)
	{
		this->x = x;
		this->y = y;
	}
public:
	T max()
	{
		return (x>y)?x:y;
	}
private:
	T x;
	T y;
};
template<>
class Compare<char*>
{
public:
	Compare(char *str1, char *str2)
	{
		this->str1 = new char[strlen(str1) + 1];
		strcpy(this->str1, str1);
		this->str2 = new char[strlen(str2) + 1];
		strcpy(this->str2, str2);
	}
public:
	int max()
	{
		return strcmp(str1, str2);
	}
private:
	char *str1;
	char *str2;
};

int main()
{
	Compare<int> iCom(1, 2);
	cout << iCom.max() << endl;

	char str1[] = "str1";
	char str2[] = "str2";
	Compare<char*> sCom(str1, str2);
	cout << sCom.max() << endl;

	int c;
	cin >> c;
	return 0;
}