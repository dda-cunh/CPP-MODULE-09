#include "../inc/Date.hpp"
#include <string>

//------------------------------  CANONICAL  ------------------------------//
Date::Date(void)
	:	_yy(1998),
		_mm(6),
		_dd(18)
{}

Date::Date(Date const & src)
{
	*this = src;
}

Date & Date::operator=(Date const & rhs)
{
	this->_yy = rhs.getYear();
	this->_mm = rhs.getMonth();
	this->_dd = rhs.getDay();
	return (*this);
}

Date::~Date(void)
{}
//-------------------------------------------------------------------------//

//-----------------------------  CONSTRUCTORS  ----------------------------//
Date::Date(std::string const& str)
{
	std::string::size_type	i;
	std::string	const 		verbose = "Error: bad date => " + str;
	std::string				num;
	char					curr;
	int						start;

	start = 0;
	if (charCount('-', str) != 2)
		throw (ExceptionMaker(verbose));
	while (str.size() != 0)
	{
		for (i = 0; i < str.size(); i++)
		{
			curr = str[i];
			if (!isNum(curr))
				if (i == 0 || i == str.size() - 1 || curr != '-')
					throw (ExceptionMaker(verbose));
			if (curr == '-')
				break ;
		}
		start += i + 1;
		num = str.substr(start, i);

	}
}
//-------------------------------------------------------------------------//

//---------------------------  MEMBER FUNCTIONS  --------------------------//
unsigned short const&	Date::getMonth()	const
{
	return (this->_mm);
}

unsigned short const&	Date::getYear()	const
{
	return (this->_yy);
}

unsigned short const&	Date::getDay()	const
{
	return (this->_dd);
}
//-------------------------------------------------------------------------//
//-------------------------  NON-MEMBER FUNCTIONS  ------------------------//
bool	isNum(char const& c)
{
	return (c >= '0' && c <= '9');
}

std::string::size_type	charCount(char const& c, std::string const& s)
{
	std::string::size_type	count;

	count = 0;
	for (std::string::const_iterator it = s.begin();
			it != s.end();
			it++)
	{
		if (*it == c)
			count++;
	}
	return (count);
}
//-------------------------------------------------------------------------//
