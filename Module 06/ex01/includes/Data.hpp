#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>

class Data
{
	public:
		Data();
		Data(const Data& copy);
		const Data& operator=(const Data& copy);
		~Data();
	
		std::string _name;
		int _age;
		float _height;
		long _net_worth;
};

std::ostream& operator<<(std::ostream& outstream, const Data& copy);

#endif
