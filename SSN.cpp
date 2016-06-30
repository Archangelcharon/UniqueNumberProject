#include "SSN.hpp"
#include <cstring>
#include <bitset>
#include <algorithm>
#include <iostream>
using namespace std::regex_constants;

uniqueNum::uniqueNum(char const* s)
 : len(std::strlen(s)), bitArr(new std::bitset<40>)
{
    std::string tempS;
    if (len == 9){
        std::cout << "This is a SSN." << std::endl;
        for (int i = 0; i < len; ++i)
        {
            tempS = int_to_bin(s[i]-'0');

            //demonstration only
            std::cout << "digit #" << i << " stored as: "<< tempS << std::endl;

            for (int j = 0; j < 4; ++j)
            {
                bitArr->set((i * 4 + j), (tempS[j]-'0'));
            }
        }
    }
    else if (len == 10)
    {
        std::cout << "This is a phone number." << std::endl;
        for (int i = 0; i < len; ++i)
        {
            tempS = int_to_bin(s[i]-'0');

            //demonstration only
            std::cout << "digit #" << i << " stored as: "<< tempS << std::endl;

            for (int j = 0; j < 4; ++j)
            {
                bitArr->set((i * 4 + j), (tempS[j]-'0'));
            }
        }
    }
    else
    {
        len = 0;
        std::cout << "Incorrect format." << std::endl;
    }
}

std::string uniqueNum::getArr() const
{
	std::string tempS, returnS;
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			(bitArr->test((i * 4 + j)) ? tempS += '1' : tempS += '0');
		}

		//demonstration only
		std::cout << "digit #" << i << " retrieved as: " << tempS << std::endl;
		std::cout << "digit #" << i << " restored as: " << bin_to_int(tempS) << std::endl;

		returnS += bin_to_int(tempS);
		tempS.clear();
	}
	return returnS;
}
 //converts the passed number to a string representation of the binary equvalent
std::string uniqueNum::int_to_bin(int number) const
{
    const std::string result = std::bitset<4>(number).to_string();
    return result;
}

//converts the passed string(as binary) back to a digit
//and returns as a character to rebuild the string of digits
char uniqueNum::bin_to_int(std::string s) const
{
	short temp = 0;
	for (int i = 0; i < 4; ++i)
	{
		temp += (s[i]-'0') * pow(2, 3 - i);
	}
	return temp+'0';
}

int uniqueNum::parse_input(const char* &s)
{
	if (isdigit(s[0]) && isdigit(s[1])
     && isdigit(s[2]) && s[3] == '-' && isdigit(s[4])
     && isdigit(s[5]) && s[6] == '-' &&
     isdigit(s[7]) && isdigit(s[8]) &&
     isdigit(s[9]) && isdigit(s[10]))
	{
        std::cout << "success!!" << std::endl;
        std::cin.get();
        return 0;
	}

	return 0;
}



/*
SSN s;
SSN s = "111-55-1234";
SSN s2 = "123456789";
SSN s2 = s;
s2 = s;

assert(s2 == s);
bool b = (s == s2);
assert(s2 != s);
bool b = (s1 != s2);
//find space optimal storage ---> array of bits

Pnum p;
Pnum p1 = "1234567";
PNum p2 = "1234567890";
Pnum p3 = "330-123-4567";
Pnum p4 = "111-2222";
Pnum p5 = "18002226666";
Pnum p6 = "1-800-123-4567";
Pnum p7 = p6;
p7 = p6;

assert(p1 == p2);
bool b = (p1 == p2);
assert(p1 != p2);
bool b = (p1 != p2);
// assert(p1.areacode == p2.areacode);   ???

*/
