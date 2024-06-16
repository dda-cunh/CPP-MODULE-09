#pragma  once

#include <string>
#include <map>

class	Date;

typedef std::map<Date, float>	DateFloatMap;

enum Range
{
	MIN_VALUE = 0,
	MAX_VALUE = 1000
};

#define CLI_GREEN	"\033[32m"
#define CLI_RESET	"\033[0m"
#define CLI_CYAN	"\033[36m"
#define CLI_RED		"\033[31m"

class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const & src);
		BitcoinExchange &	operator=(BitcoinExchange const & rhs);
		~BitcoinExchange(void);

		float	retrieveRate(Date const&)			const;
		void	parseInFileLine(std::string const&)	const;
		void	run(std::string const&);

	private:
		DateFloatMap	_dateExchange;

		static std::string		_db_path;

};
