#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <string>
#include <utility>
#include <vector>
#include <ctime>
#include <deque>

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

//-----------------------------  CONSTRUCTORS  ----------------------------//
PmergeMe::PmergeMe(int const& ac, char **av)
{
	std::vector<int>	before;
	std::vector<int>	vec;
	std::deque<int>		deq;
	std::clock_t		start;
	double				init_vec_time;
	double				init_deq_time;
	double				sort_vec_time;
	double				sort_deq_time;

	PmergeMe::validateNumbers(ac, av);
	start = std::clock();
	PmergeMe::initVector(vec,std::vector<std::string>(av + 1, av + ac));
	init_vec_time = PmergeMe::getElapsed(start);
	before = vec;
	start = std::clock();
	PmergeMe::initDeque(deq,std::deque<std::string>(av + 1, av + ac));
	init_deq_time = PmergeMe::getElapsed(start);
	start = std::clock();
	PmergeMe::sortFordJohnsonVector(vec);
	sort_vec_time = PmergeMe::getElapsed(start);
	start = std::clock();
	PmergeMe::sortFordJohnsonDeque(deq);
	sort_deq_time = PmergeMe::getElapsed(start);
	PmergeMe::printResults(before, vec, init_vec_time, init_deq_time,
							sort_vec_time, sort_deq_time);
}
//-------------------------------------------------------------------------//

//----------------------------  STAIC MEMBERS  ----------------------------//
double	PmergeMe::getElapsed(std::clock_t	const& start)
{
	return ((std::clock() - start) / (double) CLOCKS_PER_SEC);
}

void	PmergeMe::initVector(std::vector<int> &vec,
			std::vector<std::string> const& argv)
{
	for (std::vector<std::string>::size_type i = 0;
			i < argv.size();
			i++)
		vec.push_back(std::atol(argv[i].c_str()));
}

void	PmergeMe::initDeque(std::deque<int> &vec,
			std::deque<std::string> const& argv)
{
	for (std::deque<std::string>::size_type i = 0;
			i < argv.size();
			i++)
		vec.push_back(std::atol(argv[i].c_str()));
}

bool	PmergeMe::intPairCmp(IntPair const& p1, IntPair const& p2)
{
	    return (p1.second < p2.second);
}

void	PmergeMe::sortFordJohnsonVector(std::vector<int> & container)
{
	std::vector<IntPair>	pairs;

	if (container.size() <= 1)
		return ;
	for (std::vector<int>::size_type i = 1; i < container.size(); i += 2)
	{
		if (container[i - 1] < container[i])
			pairs.push_back(std::make_pair(container[i - 1], container[i]));
		else
			pairs.push_back(std::make_pair(container[i], container[i - 1]));
	}
	if (container.size() & 1)
		pairs.push_back(IntPair(-1, container[container.size() - 1]));
	std::sort(pairs.begin(), pairs.end(), PmergeMe::intPairCmp);
	sortInsertPairsVector(container, pairs);
}

void	PmergeMe::sortInsertPairsVector(std::vector<int> & container,
										std::vector<IntPair> & sorted_pairs)
{
	std::vector<int>::iterator	position;
	std::vector<int>			sorted_sequence;
	int							smaller;

	for (std::vector<IntPair>::size_type i = 0; i < sorted_pairs.size(); i++)
		sorted_sequence.push_back(sorted_pairs[i].second);
	for (std::vector<int>::size_type i = 0; i < sorted_pairs.size(); ++i)
	{
		if (sorted_pairs[i].first <= 0)
			continue ;
		smaller = sorted_pairs[i].first;
		position = std::upper_bound(sorted_sequence.begin(),
									sorted_sequence.end(), smaller);
		sorted_sequence.insert(position, smaller);
	}
	container = sorted_sequence;
}\
void	PmergeMe::sortFordJohnsonDeque(std::deque<int> & container)
{
	std::deque<IntPair>	pairs;

	if (container.size() <= 1)
		return ;
	for (std::deque<int>::size_type i = 1; i < container.size(); i += 2)
	{
		if (container[i - 1] < container[i])
			pairs.push_back(std::make_pair(container[i - 1], container[i]));
		else
			pairs.push_back(std::make_pair(container[i], container[i - 1]));
	}
	if (container.size() & 1)
		pairs.push_back(IntPair(-1, container[container.size() - 1]));
	std::sort(pairs.begin(), pairs.end(), PmergeMe::intPairCmp);
	sortInsertPairsDeque(container, pairs);
}

void	PmergeMe::sortInsertPairsDeque(std::deque<int> & container,
										std::deque<IntPair> & sorted_pairs)
{
	std::deque<int>::iterator	position;
	std::deque<int>				sorted_sequence;
	int							smaller;

	for (std::deque<IntPair>::size_type i = 0; i < sorted_pairs.size(); i++)
		sorted_sequence.push_back(sorted_pairs[i].second);
	for (std::deque<int>::size_type i = 0; i < sorted_pairs.size(); ++i)
	{
		if (sorted_pairs[i].first <= 0)
			continue ;
		smaller = sorted_pairs[i].first;
		position = std::upper_bound(sorted_sequence.begin(),
									sorted_sequence.end(), smaller);
		sorted_sequence.insert(position, smaller);
	}
	container = sorted_sequence;
}

void	PmergeMe::validateNumbers(int ac, char **av)
{
	long				num;
	char				*end_ptr;

	for (int i = 1; i < ac; i++)
	{
		num = std::strtol(av[i], &end_ptr, 10);
		if (end_ptr == av[i])
			throw (ExceptionMaker("Value not an int"));
		PmergeMe::validateNumber(num);

	}
}

void	PmergeMe::validateNumber(long const& i)
{
	if (i <= 0)
		throw (ExceptionMaker(std::string("Value must be positive")));
	if (i > std::numeric_limits<int>::max())
		throw (ExceptionMaker(std::string("Value must fit in a int")));
}

void	PmergeMe::printVector(std::vector<int> const& container)
{
	for (std::vector<int>::const_iterator it = container.begin();
			it != container.end();
			it++)
		std::cout << *it << " ";
	std::cout << '\n';
}

void	PmergeMe::printResults(std::vector<int> const& before,
								std::vector<int> const& after,
								double const& init_vec_time,
								double const& init_deq_time,
								double const& sort_vec_time,
								double const& sort_deq_time)
{
	std::cout << "Before:\t";
	printVector(before);
	std::cout << "After:\t";
	printVector(after);
	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time to initialize a range of\t" << before.size();
	std::cout << " elements with std::vector\t:" << init_vec_time << " seconds\n";
	std::cout << "Time to initialize a range of\t" << before.size();
	std::cout << " elements with std::deque\t:" << init_deq_time << " seconds\n";
	std::cout << "Time to sort a range of\t\t" << before.size();
	std::cout << " elements with std::vector\t:" << sort_vec_time << " seconds\n";
	std::cout << "Time to sort a range of\t\t" << before.size();
	std::cout << " elements with std::deque\t:" << sort_deq_time << " seconds\n";
	std::cout << std::scientific;
}
//-------------------------------------------------------------------------//
