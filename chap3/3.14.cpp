#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int main(void)
{
	string s;
	vector<string> svec;
	while(cin >> s)
	{
		svec.push_back(s);
	}
	for(vector<string>::size_type ix = 0;ix != svec.size();++ix)
	{
		for(string::size_type iy = 0;iy != svec[ix].size();++iy)
		{
			svec[ix][iy] = toupper(svec[ix][iy]);
		}
		cout << svec[ix] << endl;
	}
	return 0;
}
