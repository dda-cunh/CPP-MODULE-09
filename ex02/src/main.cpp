#include <iostream>
#include <vector>

#include "../inc/ExceptionMaker.hpp"
#include "../inc/PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << CLI_RED << "Usage: ./RPN \"RPN_STRING\"" << '\n';
		std::cout << CLI_RESET;
		return (1);
	}
	try
	{
		PmergeMe	sorting(std::vector<std::string>(av + 1, av + ac));

		std::cout << CLI_CYAN;
		//TODO:
	}
	catch (ExceptionMaker const& ex)
	{
		std::cout << CLI_RED << ex.what() << '\n';
	}
	std::cout << CLI_RESET;
	return (0);
}
