#pragma  once

#include <string>

#include "ExceptionMaker.hpp"

class Date
{
	public:
		Date(void);
		Date(Date const & src);
		Date	&operator=(Date const & rhs);
		~Date(void);

		Date(std::string const&);

		unsigned short const&	getYear()	const;
		unsigned short const&	getMonth()	const;
		unsigned short const&	getDay()	const;

	private:
		unsigned short	_yy;
		unsigned short	_mm;
		unsigned short	_dd;
};

bool	isNum(char const& c);
std::string::size_type	charCount(char const&, std::string const&);