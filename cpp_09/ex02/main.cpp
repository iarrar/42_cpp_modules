#include "PmergeMe.class.hpp"

int main (int argc, char **argv)
{
	if (argc >= 2)
	{
		PmergeMe Merge(&argv[1]);
		Merge.sort();
	}
	else
	{
		std::cout << "No input" << std::endl;

	}
	return (0);

}