#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string s1, s2;
	cout << "Enter two strings:" << endl;
	cin >> s1 >> s2;
	if(s1.size() > s2.size())
		cout << s1 << " is longer than " << s2 << endl;
	else if(s1.size() < s2.size())
		cout << s1 << " is shorter than " << s2 << endl;
	else
		cout << s1 << " is same length with " << s2 << endl;
	
	return 0;
}
