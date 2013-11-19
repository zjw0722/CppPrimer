/*
** 将模板作为参数
*/
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template<typename T>
class Stack
{
public:
	Stack()
	{
		top = 0;
	}
	bool isEmpty()
	{
		return 0 == top;
	}
	bool isFull()
	{
		return MAX == top;
	}
	bool push(const T &item)
	{
		if(top < MAX)
		{
			items[top++] = item;
			return true;
		}
		else
		{
			return false;
		}
	}
	bool pop(T &item)
	{
		if(top > 0)
		{
			item = items[--top];
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	enum{MAX = 10};
	T items[MAX];
	int top;
};
template<template<typename T> class Thing>
class Crab
{
public:
	Crab()
	{ }
public:
	bool push(int a, double b)
	{
		return s1.push(a) && s2.push(b);
	}
	bool pop(int &a, double &b)
	{
		return s1.pop(a) && s2.pop(b);
	}
private:
	Thing<int> s1;
	Thing<double> s2;
};
int main()
{
	int ni;
	double nb;
	Crab<Stack> nebula;
	cout << "Enter int double pair, such as 4 3.5(0 0 to be end);" << endl;
	while(cin >> ni >> nb && ni > 0 && nb >0)
	{
		if(!nebula.push(ni, nb))
			break;
	}
	while(nebula.pop(ni, nb))
		cout << ni << ", " << nb << endl;
	cout << "Done." << endl;

	int c;
	cin >> c;

	return 0;
}