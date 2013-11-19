#include <iostream>

using namespace std;

template<typename T>
T sum(const T userArray[], const int n)
{
	T tmp = 0;
	for(int i = 0;i < n;i++)
		tmp += userArray[i];

	return tmp;
}

int main()
{
	int iArray[] = {1, 2, 3, 4, 5};
	double dArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	float fArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};

	cout << "Total(int):" << sum(iArray, 5) << endl;
	cout << "Total(double):" << sum(dArray, 5) << endl;
	cout << "Total(float):" << sum(fArray, 5) << endl;

	int c;
	cin >> c;
	return 0;
}