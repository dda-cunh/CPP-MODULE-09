#include <limits>
#include <vector>
#include <stack>

#include "../inc/ExceptionMaker.hpp"
#include "../inc/PmergeMe.hpp"

//------------------------------  CANONICAL  ------------------------------//
template <typename TT, typename Allocator>
PmergeMe<TT, Allocator>::PmergeMe(void)
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

//-----------------------------  CONSTRUCTORS  ----------------------------//
PmergeMe::PmergeMe(std::vector<std::string> const& numbers_s)
{

}
//-------------------------------------------------------------------------//


//-------------------------------  MEMBERS  -------------------------------//

//-------------------------------------------------------------------------//

//----------------------------  STAIC MEMBERS  ----------------------------//
static bool	isValidNumber(long const& i)
{
	return (i > 0 && i <= std::numeric_limits<int>::max());
}

int const	_insert_heuristic = 12;
//-------------------------------------------------------------------------//