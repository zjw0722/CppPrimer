#include <iostream>

// using namespace std;
using std::cin;
using std::cout;
using std::endl;

template<typename T>
void swap(T &a, T &b);

template<typename T>
void swap(T *a, T *b, int n);

void showArray(int a[], int n);


int main()
{
	int i = 1, j = 2;
	cout << "(i, j) = " << "(" << i << ", " << j << ")" << endl;
	swap(i, j);
	cout << "(i, j) = " << "(" << i << ", " << j << ")" << endl;
	int iArray1[] = {1, 2, 3, 4, 5};
	int iArray2[] = {6, 7, 8, 9, 10};
	const int length = sizeof(iArray1)/sizeof(iArray1[0]);
	cout << "before exchange iArray1 and iArray2" << endl;
	showArray(iArray1, length);
	showArray(iArray2, length);

	swap(iArray1, iArray2, length);
	cout << "after exchange iArray1 and iArray2" << endl;

	showArray(iArray1, length);
	showArray(iArray2, length);
	
	int c;
	cin >> c;
	return 0;
}
template<typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}
template<typename T>
void swap(T a[], T b[], int n)
{
	T temp;
	for(int i = 0;i < n;i++)
	{
		/*temp = a[i];
		a[i] = b[i];
		b[i] = temp;*/
		swap(a[i], b[i]);
	}
}
void showArray(int a[], int n)
{
	cout << "(";
	for(int i = 0;i < n;i++)
	{
		cout << a[i];
		if(i < n - 1)
			cout << ",";
	}
	cout << ")" << endl;
}