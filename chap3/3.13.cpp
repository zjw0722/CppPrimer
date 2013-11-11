#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> ivec;
	int ival;

	cout << "Enter some numbers:" << endl;
	while(cin >> ival)
		ivec.push_back(ival);

	if(ivec.size() == 0)
	{
		cout << "No element" << endl;
		return -1;
	}
	cout << "Sum of each pair of adjacent elements in the vector:"
		<< endl;
	vector<int>::size_type first, last;
	int cnt = 0;
	for(first = 0, last = ivec.size() - 1;first < last;++first, --last)
	{
		cout << ivec[first] + ivec[last] << "\t";
		++ cnt;
		if(cnt % 6 == 0)
			cout << endl;
	}

	if(first == last)
		cout << "The single number is " << ivec[first] << endl;

	return 0;

	return 0;
}
