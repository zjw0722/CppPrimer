/**
 * 类模板显示实例化
**/
#include <iostream>

using namespace std;

template<typename T, unsigned int len>
class UserArray
{
public:
	UserArray(T *pT)
	{
		this->length = len;
		this->pT = new T[length];
		for(unsigned int i = 0;i < length;i++)
			this->pT[i] = pT[i];
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
		temp += this->pT[i];

	return temp;
}

// 类模板显示实例化
typedef UserArray<int, 5> MyIntArray;

template class UserArray<double, 3>; // 没有必要

int main()
{
	int iArray[] = {1, 2, 3, 4, 5};
	double dArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	const unsigned int iLength = sizeof(iArray)/sizeof(iArray[0]);

	MyIntArray myIntArray(iArray);
	UserArray<double, 3> d(dArray);

	cout << myIntArray.sum() << endl;
	cout << d.sum() << endl;
	
	int c;
	cin >> c;
	return 0;
}