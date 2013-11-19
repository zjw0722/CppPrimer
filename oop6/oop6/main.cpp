/*
** �±��������[]������
*/
#include <iostream>

using namespace std;

class UserString
{
public:
	UserString(char *str)
	{
		len = strlen(str);
		this->str = new char[len + 1];
		strcpy(this->str, str);
	}
	~UserString()
	{
		delete str;
		str = NULL;
	}
public:
	char operator[](int index)
	{
		if(index >= 0 && index < len) // �ж�Խ��
			return str[index];
		else
		{
			cout << "beyond scope..." << endl;
			return ' ';
		}
	}
	int getLength()
	{
		return len;
	}
private:
	char *str;
	int len;
};

int main()
{
	UserString us("zhangsan");
	cout << "\"zhangsan\" length:" << us.getLength() << endl;
	int length = us.getLength();
	int i;
	for(i = 0;i < length;i++)
		cout << us[i]; // ʹ��[]����
	cout << endl;
	cout << us[i];

	cin >> i;
	return 0;
}