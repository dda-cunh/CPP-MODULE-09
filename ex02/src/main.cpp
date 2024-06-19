#include <iostream>

#include "../inc/ExceptionMaker.hpp"
#include "../inc/PmergeMe.hpp"

#define CLI_GREEN	"\033[32m"
#define CLI_RESET	"\033[0m"
#define CLI_CYAN	"\033[36m"
#define CLI_RED		"\033[31m"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << CLI_RED << "Usage: ./PmergeMe n1 n2 n3..." << '\n';
		std::cout << CLI_RESET;
		return (1);
	}
	try
	{
		std::cout << CLI_CYAN;
		PmergeMe	sort(ac, av);

	}
	catch (ExceptionMaker const& ex)
	{
		std::cout << CLI_RED << ex.what() << '\n';
	}
	std::cout << CLI_RESET;
	return (0);
}
