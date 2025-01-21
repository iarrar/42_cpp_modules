#include "Bureaucrat.class.hpp"

int main()
{
	Bureaucrat crat;
	Bureaucrat Michel("Michel", 150);
	Michel.incrementGrade();
	std::cout << Michel << std::endl;
	std::cout << crat << std::endl;
	crat.decrementGrade();
	std::cout << crat << std::endl;
	return (0);
}