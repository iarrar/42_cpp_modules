#include "BitcoinExchange.class.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange()
{

}

int		BitcoinExchange::convDate(std::string date) const
{
	if (date.size() != 10)
	{
		return (0);
	}
	else
	{
		int y;
		int m;
		int d;
		int result;
		std::string year = date.substr(0, 4);
		std::string month = date.substr(5, 2);
		std::string day = date.substr(8, 2);

		y = atoi(year.c_str());
		m = atoi(month.c_str());
		d = atoi(day.c_str());
		if (m > 12 || m < 1 || d < 1 || d > 31 || y < 0)
			return (0);
		else
			result = (y * 365) + (m * 12) + d;
		return (result);
	}
}

int		BitcoinExchange::checkValue(std::string value) const
{
	size_t i = 0;
	int point = 0;
	if (value[i] == 32)
		i++;
	if (value[i] == '-')
		i++;
	while (value[i])
	{
		if (value[i] == '.')
			point++;
		else if (!(value[i] >= '0' && value[i] <= '9') && value[i] != 32)
			return (-1);
		i++;
	}
	if (point > 1)
		return (-1);
	return (0);
}

float	BitcoinExchange::convValue(std::string value) const
{
	float	result;
	if (checkValue(value) == -1)
	{
		std::cout << value << std::endl;
		std::cout << "Error value" << std::endl;
		return (-3);
	}
	else
	{
		result = atof(value.c_str());
		return (result);
	}
}

void	BitcoinExchange::getData (std::string data)
{
	std::ifstream	file(data.c_str());
	std::string		line;
	int				date;
	float			value;
	if (!file.is_open())
	{
		std::cout << "Error : couldn't open the csv file" << std::endl;
		this->_error = 1;
		return ;
	}
	else
	{
		getline(file, line);
		while (getline(file, line))
		{
			std::string sdate;
			std::string	svalue;
			std::istringstream ss(line);
			getline(ss, sdate, ',');
			getline(ss, svalue, '\n');
			date = convDate(sdate);
			value = convValue(svalue);
			_data.insert(std::pair<int, float>(date, value));
		}
		file.close();
	}
	return ;
}

void	BitcoinExchange::getInput(char *str)
{
	std::ifstream	file(str);
	std::string		line;
	int				date;
	float			value;
	if (!file.is_open())
	{
		std::cout << "Error : Couldn't open Input file" << std::endl;
		return ;
	}
	else
	{
		getline(file, line);
		while (getline(file, line))
		{
			std::string			sdate;
			std::string			svalue;
			std::istringstream	ss(line);
			if (line.find('|') != std::string::npos)
			{
				getline(ss, sdate, '|');
				getline(ss, svalue, '\n');
				sdate = sdate.substr(0, 10);
				date = convDate(sdate);
				value = convValue(svalue);
			}
			else
			{
				getline(ss, sdate);
				date = convDate(sdate);
				value = 0;
			}
			if (value < 0)
				value = -1;
			else if (value > 1000)
				value = -2;
			_input.insert(std::pair<int, float> (date, value));
		}
		file.close();
	}
	return ;
}

std::string	BitcoinExchange::dateToString(int date) const
{
	std::string year;
	std::string month;
	std::string day;
	std::string result;
	std::ostringstream as;
	std::ostringstream bs;
	std::ostringstream cs;

	int buff;

	buff = date / 365;
	as << buff;
	year = as.str();
	buff = (date % 365) / 12;
	bs << buff;
	month = bs.str();
	buff = (date % 365) % 12;
	cs << buff;
	day = cs.str();
	result = year + "-" + month + "-" + day;
	return (result);
}

void			BitcoinExchange::setOutput(char *str)
{
	std::multimap<int, float>::iterator it = _data.begin();
	std::ifstream 						file(str);
	std::string							line;
	int									date;
	float								value;
	float								refvalue;
	std::size_t							pos;
	getline(file, line);
	while (getline(file, line))
	{
		date = convDate(line.substr(0, 10));
		if (date == 0)
		{
			std::cout << "Wrong date format/value" << std::endl;
		}
		else
		{
			std::cout << line.substr(0, 10) << " ====> ";
			if (line.find('|') == std::string::npos)
				std::cout << "No value or wrong format" << std::endl;
			else
			{
				if (checkValue(line.substr(13)) == -1)
					std::cout << "Input Value is not a number" << std::endl;
				else if (checkValue(line.substr(line.find('|'))) == -2)
					std::cout << "Input Value is out of range" << std::endl;
				else
				{
					pos = line.find('|') + 2;
					value = convValue(line.substr(pos));
					if (value > 1000)
						std::cout << "Input Value is out of range" << std::endl;
					else if (value < 0)
						std::cout << "Input Value is negative" << std::endl;
					else
					{
						if (date < 733299)
						{
							std::cout << "Bitcoin doesn't exists yet. Portfolio value = 0" << std::endl;
						}
						else
						{
							it++;
							while (date >= it->first)
							{
								refvalue = it->second;
								it++;
							}
							std::cout << value * refvalue << std::endl;
							it = _data.begin();
						}
					}
				}				
			}
		}
	}
}

void	BitcoinExchange::exchange(char *str)
{
	getData("data.csv");
	getInput(str);
	setOutput(str);
	return ;
}
BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & src)
{
	this->_data = src._data;
	this->_output = src._output;
	this->_input = src._input;
	this->_error = src._error;
	return (*this);
}
