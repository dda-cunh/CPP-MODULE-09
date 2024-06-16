#include <iostream>

#include "../inc/BitcoinExchange.hpp"
#include "../inc/ExceptionMaker.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << CLI_RED << "Usage: ./btc [ input file ]" << '\n';
		std::cout << CLI_RESET;
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
		std::cout << CLI_RED << ex.what() << '\n' << CLI_RESET;
	}
	std::cout << CLI_RESET;
	return (0);
}
