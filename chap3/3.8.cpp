#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string totle;
	string tmp;
	cout << "Enter some strings:" << endl;
	while(cin >> tmp)
	{
		totle += tmp;
	}
	cout << totle << endl;
	return 0;
}


