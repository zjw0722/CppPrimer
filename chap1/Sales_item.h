/*
 * This file contains code form "C++ Primer, Fourth Edition".
*/
#ifndef SALE_ITEM_H
#define SALE_ITEM_H

#include <iostream>
#include <string>

class Sales_item
{
	friend std::istream& operator>>(std::istream&, Sales_item&);
	friend std::ostream& operator<<(std::ostream&, Sales_item&);
	friend bool operator<(const Sales_item&, const Sales_item&);
	friend bool operator==(const Sales_item&, const Sales_item&);
	
public:
	// default constructor needed to initialize member of built-in type
	Sales_item():units_sold(0), revenue(0.0){ };
	Sales_item(const std::string &book):
		bookNo(book), units_sold(0), revenue(0.0){ }
	Sales_item(std::istream &is){is >> *this; }
public:
	// operations on Sales_item objects
	Sales_item& operator+=(const Sales_item&);
	std::string isbn() const {return bookNo; }
	double avg_price() const;
private:
	// private members as before
	std::string bookNo;
	unsigned units_sold;
	double revenue;
};

inline bool compareIsbn(const Sales_item &lhs, const Sales_item &rhs)
{
	return lhs.isbn() == rhs.isbn();
}

Sales_item operator+(const Sales_item&, const Sales_item&);

inline bool operator==(const Sales_item &lhs, const Sales_item &rhs)
{
	return lhs.units_sold == rhs.units_sold &&
		lhs.revenue == rhs.revenue &&
		lhs.isbn() == rhs.isbn();
}
// 不需要访问私有成员，所以不用声明为友元
inline bool operator!=(const Sales_item &lhs, const Sales_item &rhs)
{
	return !(lhs == rhs);
}
// 定义为成员函数
Sales_item& Sales_item::operator+=(const Sales_item& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_item operator+(const Sales_item& lhs, const Sales_item& rhs)
{
	Sales_item ret(lhs);
	ret += rhs;
	return ret;
}

std::istream& operator>>(std::istream& in, Sales_item& s)
{
	double price;
	in >> s.bookNo >> s.units_sold >> price;
	if(in)
		s.revenue = s.units_sold*price;
	else
		s = Sales_item();
	
	return in;
}

std::ostream& operator<<(std::ostream& out, Sales_item& s)
{
	out << s.isbn() << " " << s.units_sold << " " 
		<< s.revenue << " " << s.avg_price();

	return out;
}

double Sales_item::avg_price() const
{
	if(units_sold)
		return revenue/units_sold;
	else
		return 0;
}
#endif
