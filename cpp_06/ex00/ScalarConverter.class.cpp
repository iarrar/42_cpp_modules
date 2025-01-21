/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:10:35 by iarrar            #+#    #+#             */
/*   Updated: 2024/05/07 16:10:38 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ScalarConverter.class.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter()
{

}

bool		ScalarConverter::IsDouble(char *str) 
{
	int i = 0;
	int	point =0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '.')
			return (false);
		else if (str[i] == '.')
			point++;
		i++;
	}
	if (point != 1)
		return (false);
	else
		return (true);
}

void		ScalarConverter::PrintDouble(char *str) 
{
	double	res;
	char	c = '\0';
	int		i;
	float	f;
	double check;

	res = strtod(str, NULL);

	i = static_cast<int>(res);
	c = static_cast<char>(i);
	f = static_cast<float>(res);
	check = res - i;
	
	if (i > 127)
		std::cout << "char =\t\tNon displayable" << std::endl;
	else if (!isprint(i))
		std::cout << "char =\t\timpossible" << std::endl;
	else
		std::cout << "char =\t\t" << c << std::endl;
	std::cout << "int =\t\t" << i << std::endl;
	if (check != 0)
	{
		std::cout << "float =\t" << f << "f" << std::endl;
		std::cout << "double =\t" << res << std::endl;
	}
	else
	{
		std::cout << "float =\t" << f << ".0f" << std::endl;
		std::cout << "double =\t" << res << ".0" << std::endl;
	}
}

bool		ScalarConverter::IsInt(char *str) 
{
	int i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}

void	ScalarConverter::PrintInt(char *str) 
{
	double	res;
	char	c = '\0';
	int		i;
	float	f;

	i = atoi(str);

	res = static_cast<double>(i);
	c = static_cast<char>(i);
	f = static_cast<float>(i);

	
	if (!isprint(i))
		std::cout << "char =\t\tNon displayable" << std::endl;
	else if (i > 127)
		std::cout << "char =\t\timpossible" << std::endl;
	else
		std::cout << "char =\t\t" << c << std::endl;
	std::cout << "int =\t\t" << i << std::endl;
	std::cout << "float =\t" << f << ".0f" << std::endl;
	std::cout << "double =\t" << res << ".0" << std::endl;
}

bool	ScalarConverter::IsFloat(char *str) 
{
	size_t i = 0;
	int	point =0;
	if (str[i] == '-')
		i++;
	while (i < (strlen(str) - 1))
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '.')
			return (false);
		else if (str[i] == '.')
			point++;
		i++;
	}
	if (str[i] != 'f')
		return (false);
	if (point != 1)
		return (false);
	else
		return (true);
}

void	ScalarConverter::PrintFloat(char *str) 
{
	double	res;
	char	c = '\0';
	int		i;
	float	f;
	float 	check;

	f = strtof(str, NULL);

	i = static_cast<int>(f);
	c = static_cast<char>(i);
	res = static_cast<float>(f);
	check = res - static_cast<float>(i);
	
	if (!isprint(i))
		std::cout << "char =\t\tNon displayable" << std::endl;
	else if (i > 127)
		std::cout << "char =\t\timpossible" << std::endl;
	else
		std::cout << "char =\t\t" << c << std::endl;
	std::cout << "int =\t\t" << i << std::endl;
	if (check != 0)
	{
		std::cout << "float =\t" << f << "f" << std::endl;
		std::cout << "double =\t" << res << std::endl;
	}
	else
	{
		std::cout << "float =\t" << f << ".0f" << std::endl;
		std::cout << "double =\t" << res << ".0" << std::endl;
	}

}

bool		ScalarConverter::IsChar(char *str) 
{
	if (strlen(str) != 1)
		return (false);
	else
		return (true);
}

void	ScalarConverter::PrintChar(char *str) 
{
	double	res;
	char	c = '\0';
	int		i;
	float	f;
	
	c = str[0];

	i = static_cast<int>(c);
	res = static_cast<double>(i);
	f = static_cast<float>(i);
	if (!isprint(i))
		std::cout << "char =\t\tNon displayable" << std::endl;
	else if (i > 127)
		std::cout << "char =\t\timpossible" << std::endl;
	else
		std::cout << "char =\t\t" << c << std::endl;
	std::cout << "int =\t\t" << i << std::endl;
	std::cout << "float =\t" << f << ".0f" << std::endl;
	std::cout << "double =\t" << res << ".0" << std::endl;

}


void		ScalarConverter::convert(char *str) 
{
	if (IsFloat(str))
		PrintFloat(str);
	else if (IsDouble(str))
		PrintDouble(str);
	else if (IsInt(str))
		PrintInt(str);
	else if (IsChar(str))
		PrintChar(str);
	else
	{
		std::cout << "char =\t\tImpossible" << std::endl;
		std::cout << "int =\t\tImpossible" << std::endl;
		std::cout << "float =\tnanf" << std::endl;
		std::cout << "double =\tnan" << std::endl;
	}
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & src)
{
	this->_type = src._type;
	this->_param = src._param;
	return (*this);
}
