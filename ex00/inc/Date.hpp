#pragma  once

#include <iostream>

struct DateInfo
{
	long	_yy;
	long	_mm;
	long	_dd;
};

class Date
{
	public:
		Date(void);
		Date(Date const & src);
		Date &	operator=(Date const & rhs);
		~Date(void);

		Date(std::string const&);
		Date(DateInfo const&);

		unsigned short const&	getMonth()						const;
		unsigned short const&	getYear()						const;
		unsigned short const&	getDay()						const;
		bool					validDateInfo(DateInfo const&)	const;
		bool					setDateInfo(DateInfo const&);

		bool operator==(Date const & rhs)						const;
		bool operator>=(Date const & rhs)						const;
		bool operator<=(Date const & rhs)						const;
		bool operator>(Date const & rhs)						const;
		bool operator<(Date const & rhs)						const;

	private:
		unsigned short	_yy;
		unsigned short	_mm;
		unsigned short	_dd;
};

std::ostream &			operator<<(std::ostream &, Date const&);

std::string::size_type	charCount(char const&, std::string const&);
std::string				sTrim(const std::string& str);
bool					isNum(char const& c);
