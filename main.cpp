#include "SSN.hpp"
#include <iostream>
#include <algorithm>

int main()
{

    //need < > operator. need = assignment
	uniqueNum un1("1234567890");
	//std::string a = un1.getArr();
	std::cout << "un1 reads as: " << un1.getArr() << std::endl;
	return 0;
}
