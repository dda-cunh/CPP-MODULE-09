#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <string>

#include "../inc/ExceptionMaker.hpp"
#include "../inc/Date.hpp"

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
/*	std::string constructor expects format:
 *	yyyy-mm-dd
 *	
 */
Date::Date(std::string const& str)
{
	std::string	const	verbose = "Error: bad date => " + str;

	std::stringstream	ss(str);
	std::string			number_s;
	long				numbers[3];
	char				*end_ptr;
	int					numbers_i;

	numbers_i = 0;
	if (charCount('-', str) != 2)
		throw (ExceptionMaker(verbose));
	if (!isNum(*str.begin()) || !isNum(*str.rbegin()))
		throw (ExceptionMaker(verbose));
	while(std::getline(ss, number_s, '-'))
	{
		numbers[numbers_i++] = strtol(number_s.c_str(), &end_ptr, 10);
		if (end_ptr == number_s.c_str())
			throw (ExceptionMaker(verbose));
	}
	if (numbers_i != 3)
		throw (ExceptionMaker(verbose));
	if (!this->setDateInfo((DateInfo){numbers[0], numbers[1], numbers[2]}))
		throw (ExceptionMaker(verbose));
}

Date::Date(DateInfo const& date)
{
	if (!this->setDateInfo(date))
	{
		std::stringstream	ss;

		ss << "Error: bad date => ";
		ss << std::setfill('0') << std::setw(4) << date._yy;
		ss << '-' << std::setw(2) << date._mm;
		ss << '-' << std::setw(2) << date._dd << std::setfill(' ');
		throw (ExceptionMaker(ss.str()));
	}
}
//-------------------------------------------------------------------------//


//-----------------------------  OP OVERLOADS  ----------------------------//
bool	Date::operator==(Date const & rhs)	const
{
	return (this->_yy == rhs._yy
			&& this->_mm == rhs._mm
			&& this->_dd == rhs._dd);
}

bool	Date::operator>=(Date const & rhs)	const
{
	return (!(*this < rhs));
}

bool	Date::operator<=(Date const & rhs)	const
{
	return (*this < rhs || *this == rhs);
}

bool	Date::operator>(Date const & rhs)	const
{
	return (!(*this <= rhs));
}

bool	Date::operator<(Date const & rhs)	const
{
	if (this->_yy != rhs._yy)
		return (this->_yy < rhs._yy);
	if (this->_mm != rhs._mm)
		return (this->_mm < rhs._mm);
	return (this->_dd < rhs._dd);
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

bool	Date::validDateInfo(DateInfo const& date)	const
{
	if (date._yy < 0 || date._yy > 15999)
		return (false);
	if (date._mm < 1 || date._mm > 12)
		return (false);
	if (date._dd < 1 || date._dd > 31)
		return (false);
	return (true);
}

bool	Date::setDateInfo(DateInfo const& date)
{
	if (!this->validDateInfo(date))
		return (false);
	this->_yy = date._yy;
	this->_mm = date._mm;
	this->_dd = date._dd;
	return (true);
}

//-------------------------------------------------------------------------//

//-------------------------  NON-MEMBER FUNCTIONS  ------------------------//
std::ostream &			operator<<(std::ostream & o, Date const& date)
{
	o << std::setfill('0') << std::setw(4) << date.getYear();
	o << '-' << std::setw(2) << date.getMonth();
	o << '-' << std::setw(2) << date.getDay() << std::setfill(' ');
	return (o);
}

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
