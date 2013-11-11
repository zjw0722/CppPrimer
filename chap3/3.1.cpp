#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	int base, exponent;
	long result = 1;

	cout << "Enter two numbers:" << endl;
	cin >> base >> exponent;

	if(exponent < 0)
	{
		cout << "Exponent can't samller than 0" << endl;
		return -1;
	}
	for(int cnt = 1; cnt <= exponent;++cnt)
	{
		result *= base;
	}
	cout << "Result is:" << result << endl;

	return 0;
}
