#ifndef SSN_HPP
#define SSN_HPP
#include <bitset>
#include <string>

	class uniqueNum
	{
	private:
		short len;
		std::bitset<40> *bitArr;
		std::string int_to_bin(int) const;
		char bin_to_int(std::string) const;
	public:
		uniqueNum()
			: len(0), bitArr(new std::bitset<40>) { };
		uniqueNum(char const*);
		~uniqueNum() {};
		std::bitset<40>* begin() { return bitArr; };
		std::bitset<40>* end() { return bitArr + len * 4; };
		const std::bitset<40>* begin() const { return bitArr; };
		const std::bitset<40>* end() const { return bitArr + len * 4; };

		std::string getArr() const;
	};
#endif

/*
ces95@z
ajn24@z
zao1@z
jdr67@z

dsh29
*/
