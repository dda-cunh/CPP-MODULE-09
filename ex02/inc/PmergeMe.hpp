#pragma  once

#include <ctime>
#include <string>
#include <vector>
#include <deque>

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const&);
		PmergeMe &	operator=(PmergeMe const&);
		~PmergeMe(void);

		PmergeMe(int const& , char **);

	private:
		typedef std::pair<int, int> IntPair;

		static double	getElapsed(std::clock_t	const&);
		static void		sortInsertPairsVector(std::vector<int> &,
							std::vector<IntPair> &);
		static void		sortInsertPairsDeque(std::deque<int> &,
							std::deque<IntPair> &);
		static void		initVector(std::vector<int> &,
							std::vector<std::string> const&);
		static void		initDeque(std::deque<int> &,
							std::deque<std::string> const&);
		static void		printVector(std::vector<int> const&);
		static void		sortFordJohnsonVector(std::vector<int> &);
		static void		sortFordJohnsonDeque(std::deque<int> &);
		static void		validateNumbers(int ac, char **av);
		static void		validateNumber(long const&);
		static void		printResults(std::vector<int> const&, std::vector<int> const&,
							double const&, double const&, double const&, double const&);
		static bool		intPairCmp(IntPair const&, IntPair const&);
};
