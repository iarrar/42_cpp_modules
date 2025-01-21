#include "RPN.class.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (0);
	}
	else
	{
		RPN test;
		
		std::cout << test.doRpn(argv[1]) << std::endl;
		return (0);
	}
}