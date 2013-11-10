#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item trans1, trans2;

	std::cout << "Enter two transaction:" << std::endl;
    std::cin >> trans1 >> trans2;	

	if (trans1 == trans2)
		std::cout << "THe total information:" << std::endl
			<< "ISBN, number of copies sold, "
			<< "total revenue, and average price are:"
			<< std::endl << trans1 + trans2;
	else
		std::cout << "The two transactions have dirrerent ISBN."
			<< std::endl;

	return 0;
}
