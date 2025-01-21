#include "RPN.class.hpp"

RPN::RPN()
{

}

RPN::RPN(RPN const & src)
{
	*this = src;
}

RPN::~RPN()
{

}

RPN & RPN::operator=(RPN const & src)
{
	_pile = src._pile;
	return (*this);
}

bool    RPN::isOperand(char c)
{
	if (c == '-' || c == '/' || c == '*' || c == '+')
		return (true);
	else
		return (false);
}

bool    RPN::checkInput(char *str)
{
	int i = 0;
	int n = 0;
	int o = 0;

	if (!isOk(str))
		return (false);
	while (str[i] == 32)
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
	{
		std::cout << "Error, first parameter is not a number" << std::endl;
		return (false);
	}
	i++;
	while (str[i])
	{
		while ((str[i] >= '0' && str[i] <= '9') || str[i] == 32)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				if (isNumber(str[i - 1]))
				{
					std::cout << "Error : Input number > 10 : " << str[i - 1] << str[i] << std::endl;
				}
				n++;
			}
			i++;
		}
		while (isOperand(str[i]) || str[i] == 32)
		{
			if (isOperand(str[i]))
				o++;
			i++;
		}
		if (o != n)
		{
			std::cout << "Erreur dans la formule" << std::endl;
			return (false);
		}
	}
	return (true);
}

bool    RPN::isOk(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && !isOperand(str[i]) && str[i] != 32)
		{
			std::cout << "Invalid character in the sequence : " << str[i] << std::endl;
			return (false);
		}
		i++;
	}
	return (true);
}

bool	RPN::isNumber(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);
}

int		RPN::doOp(char c, int a, int b)
{
	if (c == '*')
		return (a * b);
	if (c == '+')
		return (a + b);
	if (c == '-')
		return (b - a);
	if (c == '/')
		return (b / a);
	std::cout << "operation error" << std::endl;
	return (0);
}

int		RPN::doRpn(char *str)
{
	int i = 0;
	int a = 0;
	int b = 0;

	if (!checkInput(str))
		return (-1);
	else
	{
		while (str[i])
		{
			if (isNumber(str[i]))
			{
				_pile.push(str[i] - 48);
				i++;
			}
			else if (isOperand(str[i]))
			{
				a = _pile.top();
				_pile.pop();
				b = _pile.top();
				_pile.pop();
				_pile.push(doOp(str[i], a, b));
				i++;
			}
			else
				i++;
		}
	}
	return(_pile.top());
}


