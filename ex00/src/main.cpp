#include <iostream>

#include "../inc/BitcoinExchange.hpp"
#include "../inc/ExceptionMaker.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << CLI_RED << "Usage: ./btc [ input file ]" << '\n';
		std::cerr << CLI_RESET;
		return (1);
	}
	try
	{
		BitcoinExchange	bEx;

		std::cout << CLI_CYAN;
		bEx.run(av[1]);
	}
	catch (ExceptionMaker const& ex)
	{
		std::cerr << CLI_RED << ex.what() << '\n' << CLI_RESET;
	}
	std::cout << CLI_RESET;
	std::cerr << CLI_RESET;
	return (0);
}
