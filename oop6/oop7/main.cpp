/*
** ÔËËã·û¡°++¡¢--¡±ÖØÔØ
*/
#include <iostream>

using namespace std;

class Integer
{
public:
	Integer(int data)
	{
		this->data = data;
	}
	Integer(const Integer &i)
	{
		this->data = i.data;
	}
	~Integer()
	{ }
public:
	Integer operator++(int)
	{
		Integer temp(*this);
		data++;
		return temp;
	}
	Integer operator++()
	{
		data++;
		return *this;
	}
	void show()
	{
		cout << data << endl;
	}
private:
	int data;
};

int main()
{
	Integer x(1);
	(x++).show();
	(++x).show();

	int i;
	cin >> i;
	return 0;
}