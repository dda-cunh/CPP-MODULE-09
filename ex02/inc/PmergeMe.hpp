#pragma  once

#include <string>

#define CLI_GREEN	"\033[32m"
#define CLI_RESET	"\033[0m"
#define CLI_CYAN	"\033[36m"
#define CLI_RED		"\033[31m"

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const & src);
		PmergeMe &	operator=(PmergeMe const & rhs);
		~PmergeMe(void);

	private:
};
