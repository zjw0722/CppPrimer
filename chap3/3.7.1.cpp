#include <iostream>
#include <string>

using namespace std;

int main(void)
{	
	string s1, s2;
	cout << "Enter two strings:" << endl;
	cin >> s1 >> s2;
	if(s1 == s2)
		cout << "The two string is same." << endl;
	else
		cout << "The two string is different." << endl;

	return 0;
}
