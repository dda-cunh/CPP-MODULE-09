#include <iostream>

#include "../inc/ExceptionMaker.hpp"
#include "../inc/RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << CLI_RED << "Usage: ./RPN \"RPN_STRING\"" << '\n';
		std::cerr << CLI_RESET;
		return (1);
	}
	try
	{
		RPN	rpn;

		std::cout << CLI_CYAN;
		std::cout << rpn.calculate(av[1]) << '\n';
	}
	catch (ExceptionMaker const& ex)
	{
		std::cerr << CLI_RED << ex.what() << '\n';
	}
	std::cout << CLI_RESET;
	std::cerr << CLI_RESET;
	return (0);
}
