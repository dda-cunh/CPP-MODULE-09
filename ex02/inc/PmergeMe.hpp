#pragma  once

#include <string>
#include <vector>
#include <deque>
#include <ctime>

#define CLI_GREEN	"\033[32m"
#define CLI_RESET	"\033[0m"
#define CLI_CYAN	"\033[36m"
#define CLI_RED		"\033[31m"

template
<
	typename Allocator,
	template
	<
		typename,
		typename
	> class T
>
class PmergeMe
{
	public:
	typedef	T<int, Allocator> IntContainer;

		PmergeMe(void);
		PmergeMe(PmergeMe const&);
		PmergeMe &	operator=(PmergeMe const&);
		~PmergeMe(void);

		PmergeMe(T<std::string, Allocator> const& numbers_s)
		{
			std::vector<std::string>	numbers;
			std::clock_t				start;
			std::clock_t				end;

			start = std::clock();
			for (std::vector<std::string>::size_type i = 0;
				i < numbers_s.size();
				i++)
			{

			}	
		}

		static bool isValidNumber(long const&);
	private:
		void	insertSortDeque(IntContainer &container, int const& start, int const& end)
		{
			for(int i = start + 1; i <= end; i++)
			{
				int hold = container[i];
				int j = i - 1;
				for(; j >= start && container[j] > hold; --j)
					container[j + 1] = container[j];
				container[j + 1] = hold;
			}
		}

		void	sortMerge(IntContainer &container, int start, int mid, int end)
		{
			IntContainer	left(mid - start + 1);
			IntContainer	right(end - mid);
			int				container_i;
			int				right_i;
			int				left_i;

			for(left_i = 0; left_i < (mid - start + 1); left_i++)
				left[left_i] = container[start + left_i];
			for(right_i = 0; right_i < (end - mid); right_i++)
				right[right_i] = container[mid + 1 + right_i];
			left_i = 0;
			right_i = 0;
			container_i = start;
			while(left_i < (mid - start + 1) && right_i < (end - mid))
			{
				if (left[left_i] <= right[right_i])
					container[container_i++] = left[left_i++];
				else
					container[container_i++] = right[right_i++];
			}
			while(left_i < (mid - start + 1))
				container[container_i++] =  left[left_i++];
			while (right_i < (end - mid))
				container[container_i++] = right[right_i++];
		}

		void	sortFordJohnson(IntContainer &container, int const& start, int const& end)
		{
			int	len;
			int	mid;

			if (start < end)
			{
				len = end - start;
				if (len < _insert_heuristic)
					sortInsert(container, start, end);
				else
				{
					mid = start + len / 2;
					sortFordJohnson(container,  start, mid);
					sortFordJohnson(container, mid + 1, end);
					sortMerge(container, start, mid, end);
				}
			}
		}

		void	print(IntContainer const& container)
		{
			typename IntContainer::iterator	it;

			for (it = container.begin(); it != container.end(); it++)
				
		}

		IntContainer		_unsorted;
		static int const	_insert_heuristic;
};
