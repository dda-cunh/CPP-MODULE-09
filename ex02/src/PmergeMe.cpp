#include <sstream>
#include <stack>

#include "../inc/ExceptionMaker.hpp"
#include "../inc/PmergeMe.hpp"

//------------------------------  CANONICAL  ------------------------------//
PmergeMe::PmergeMe(void)
{}

PmergeMe::PmergeMe(PmergeMe const & src)
{
	*this = src;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs)
{
	(void) rhs;
	return (*this);
}

PmergeMe::~PmergeMe(void)
{}
//-------------------------------------------------------------------------//

//-------------------------------  MEMBERS  -------------------------------//

//-------------------------------------------------------------------------//

