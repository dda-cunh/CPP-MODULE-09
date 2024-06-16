#pragma  once

#include <string>

#define CLI_GREEN	"\033[32m"
#define CLI_RESET	"\033[0m"
#define CLI_CYAN	"\033[36m"
#define CLI_RED		"\033[31m"

class RPN
{
	public:
		RPN(void);
		RPN(RPN const & src);
		RPN &	operator=(RPN const & rhs);
		~RPN(void);

		long	calculate(std::string const&);
	private:

		static const std::string	_possible_nums;
		static const std::string	_possible_ops;
};
