#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "../inc/BitcoinExchange.hpp"
#include "../inc/ExceptionMaker.hpp"
#include "../inc/Date.hpp"

//------------------------------  CANONICAL  ------------------------------//
BitcoinExchange::BitcoinExchange(void)
	:	_dateExchange(DateFloatMap())
{
	std::ifstream	dbFile(BitcoinExchange::_db_path.c_str());
	std::string		line;

	if (!dbFile.is_open())
		throw (ExceptionMaker("Couldn't open db file"));
	while (std::getline(dbFile, line))
	{
		std::vector<std::string>	colls;
		std::stringstream			ss;
		std::string					coll;
		float						exchange;
		char						*end_ptr;

		if (line == "date,exchange_rate")
			continue ;
		ss << line;
		while (std::getline(ss, coll, ','))
			colls.push_back(coll);
		if (colls.size() != 2)
			throw (ExceptionMaker("Invalid line on db file"));
		Date	date(colls[0]);
		exchange = std::strtof(colls[1].c_str(), &end_ptr);
		if (end_ptr == colls[1].c_str())
			throw (ExceptionMaker("Invalid number on db file"));
		this->_dateExchange.insert(DateFloatMap::value_type(date, exchange));
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
	*this = src;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
	this->_dateExchange = rhs._dateExchange;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{}
//-------------------------------------------------------------------------//
//-------------------------------  MEMBERS  -------------------------------//
float	BitcoinExchange::retrieveRate(Date const& date)	const
{
	for (DateFloatMap::const_reverse_iterator it = this->_dateExchange.rbegin();
		it != this->_dateExchange.rend();
		it++)
	{
		if (it->first <= date)
			return (it->second);
	}
	return (0.0f);
}

void	BitcoinExchange::parseInFileLine(std::string const& line)	const
{
	std::vector<std::string>	colls;
	std::stringstream			ss;
	std::string					coll;
	float						converted;
	float						value;
	char						*end_ptr;

	if (line == "date | value")
		return ;
	ss << line;
	while (std::getline(ss, coll, '|'))
		colls.push_back(coll);
	if (colls.size() != 2)
		throw (ExceptionMaker("Error: Invalid line on infile"));
	Date	date(colls[0]);
	value = std::strtof(colls[1].c_str(), &end_ptr);
	if (end_ptr == colls[1].c_str())
		throw (ExceptionMaker("Error: Invalid number on infile"));
	if (value < MIN_VALUE)
		throw (ExceptionMaker("Error: Value too low"));
	if (value > MAX_VALUE)
		throw (ExceptionMaker("Error: Value too large"));
	converted = retrieveRate(date) * value;
	std::cout << date << " => " << value << " = " << converted;
}

void	BitcoinExchange::run(std::string const& filePath)
{
	std::ifstream	inFile(filePath.c_str());
	std::string		line;

	if (!inFile.is_open())
		throw (ExceptionMaker("Couldn't open infile"));
	while (std::getline(inFile, line))
	{
		try
		{
			parseInFileLine(line);
		}
		catch (ExceptionMaker const& ex)
		{
			std::cout << CLI_RED << ex.what() << CLI_CYAN;
		}
		std::cout << '\n';
	}
}
//-------------------------------------------------------------------------//

//----------------------------  STATIC MEMBERS  ---------------------------//
std::string BitcoinExchange::_db_path = "data.csv";
//-------------------------------------------------------------------------//