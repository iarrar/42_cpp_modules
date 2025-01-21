#ifndef RPN_H
#define RPN_H
#include <string>
#include <stack>
#include <iostream>


class RPN
{
	public:
		RPN();
		RPN(RPN const & src);
		virtual ~RPN();
	RPN& operator=(RPN const & src);
	bool	isOk(char *str);
	bool	isOperand(char c);
	bool	checkInput(char *str);
	int		doRpn(char *str);
	int		doOp(char op, int a, int b);
	bool	isNumber(char c);	

	protected:
		std::stack<int>	_pile;

};

#endif