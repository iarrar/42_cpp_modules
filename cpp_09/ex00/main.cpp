#include "BitcoinExchange.class.hpp"


int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Error : Put a file as argument" << std::endl;
		return (0);
	}
	else if (argc > 2)
	{
		std::cout << "Too much files as arguments" << std::endl;
		return (0);
	}
	else
	{
		BitcoinExchange btc;
		btc.exchange(argv[1]);
		return (0);
	}
}