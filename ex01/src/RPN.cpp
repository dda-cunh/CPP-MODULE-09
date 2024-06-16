#include <sstream>
#include <stack>

#include "../inc/ExceptionMaker.hpp"
#include "../inc/RPN.hpp"

//------------------------------  CANONICAL  ------------------------------//
RPN::RPN(void)
{}

RPN::RPN(RPN const & src)
{
	*this = src;
}

RPN & RPN::operator=(RPN const & rhs)
{
	(void) rhs;
	return (*this);
}

RPN::~RPN(void)
{}
//-------------------------------------------------------------------------//

//-------------------------------  MEMBERS  -------------------------------//
long	RPN::calculate(std::string const& rpn_string)
{
	std::stringstream	ss(rpn_string);
	std::stack<long>	stack;
	std::string			curr;
	long				right;
	long				left;

	while (std::getline(ss, curr, ' '))
	{
		if (curr.length() != 1)
			throw (ExceptionMaker("Value with more than one char"));
		if (RPN::_possible_nums.find(curr[0]) != std::string::npos)
			stack.push(curr[0] - '0');
		else if (RPN::_possible_ops.find(curr[0]) != std::string::npos)
		{
			if (stack.size() < 2)
				throw (ExceptionMaker("Invalid rpn, not enough operands to do op"));
			right = stack.top();
			stack.pop();
			left = stack.top();
			stack.pop();
			switch (curr[0])
			{
				case '+':
				{
					stack.push(left + right);
					break ;
				}
				case '-':
				{
					stack.push(left - right);
					break ;
				}
				case '*':
				{
					stack.push(left * right);
					break ;
				}
				case '/':
				{
					if (right == 0)
						throw (ExceptionMaker("Division by zero"));
					stack.push(left / right);
					break ;
				}
			}
		}
		else
			throw (ExceptionMaker("Invalid value in rpn"));
	}
	if (stack.size() != 1)
		throw (ExceptionMaker("Invalid rpn, extra operand(s)"));
	return (stack.top());
}
//-------------------------------------------------------------------------//

//----------------------------  STATIC MEMBERS  ---------------------------//
const std::string RPN::_possible_nums = "0123456789";
const std::string RPN::_possible_ops = "+-*/";
//-------------------------------------------------------------------------//
