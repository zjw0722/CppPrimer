#include <iostream>
#include <cstring>

using namespace std;

template<typename T, unsigned int len>
class UserArray // 带非类型化参数的类模板
{
public:
	UserArray(T *pT)
	{
		this->length = len;
		this->pT = new T[length];
		for(unsigned int i = 0;i < length;i++)
		{
			this->pT[i] = pT[i];
		}
	}
	~UserArray()
	{
		delete [] pT;
		pT = NULL;
	}
public:
	T sum();
private:
	T *pT;
	unsigned int length;
};
template<typename T, unsigned int len>
T UserArray<T, len>::sum()
{
	T temp = 0;
	for(unsigned int i = 0;i < length;i++)
	{
		temp += this->pT[i];
	}
	return temp;
}

template<unsigned int len> // 部分特化类模板
class UserArray<char*, len>
{
public:
	UserArray(char *pStr)
	{
		length = len;
		this->pStr = new char[length + 1];
		strcpy(this->pStr, pStr);
	}
public:
	char *sum(char *buffer) const;
private:
	char *pStr;
	unsigned int length;
};
template<unsigned int len>
char* UserArray<char*, len>::sum(char *buffer) const
{
	strcat(buffer, pStr);
	return buffer;
}

int main()
{
	int iArray[] = {1, 2, 3, 4, 5};
	const unsigned int iLength = sizeof(iArray)/sizeof(iArray[0]);
	UserArray<int, iLength> iArrayObj(iArray);
	cout << "elements sum:" << iArrayObj.sum() << endl;

	char Str[] = "Test partial specialization.";
	const unsigned int sLength = 28;
	char buffer[200] = "The added string is :";

	UserArray<char*, sLength> userStringObj(Str);
	cout << "Adding string to buffer" << endl  
		<< userStringObj.sum(buffer) << endl;

	int c;
	cin >> c;
	return 0;
}