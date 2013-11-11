#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> ivec(10, 2);
	for(vector<int>::iterator iter = ivec.begin();
			iter != ivec.end();++iter)
	{
		*iter *= 2;
		cout << *iter << endl;
	}
	
	return 0;
}
