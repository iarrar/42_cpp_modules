#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

class BitcoinExchange
{
	public:
						BitcoinExchange();
						BitcoinExchange(BitcoinExchange const & src);
	virtual 			~BitcoinExchange();
	BitcoinExchange&	operator=(BitcoinExchange const & src);
		void			getInput(char *str); //prends le fichier d'input et le transforme en map
		void			setOutput(char *str);
		void			display(std::multimap<int, std::string> maps); //fonction test pour l'affichage des map
		void			displayValue() const; //affiche _output
		int				convDate(std::string) const;
		void			getData(std::string); //prends le fichier csv et le transforme en map
		float			convValue(std::string) const;
		std::string		dateToString(int date) const;
		void			exchange(char *str);
		int				checkValue(std::string) const;
	protected:
		std::multimap<int, float>					_data;
		std::multimap<int, float>					_input;
		std::multimap<std::string, std::string>		_output;
		int										_error;


};

#endif