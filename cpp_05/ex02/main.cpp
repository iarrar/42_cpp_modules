#include "Bureaucrat.class.hpp"
#include "AForm.class.hpp"
#include "ShrubberyCreationForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"

int main()
{
	Bureaucrat crat;
	Bureaucrat Michel("Michel", 100);
	Michel.incrementGrade();
	std::cout << Michel << std::endl;
	std::cout << crat << std::endl;
	crat.decrementGrade();
	std::cout << crat << std::endl;
	std::cout <<"********************************************" << std::endl;
	ShrubberyCreationForm Shrub("./");
	PresidentialPardonForm Pardon("Gerard");
	RobotomyRequestForm Rob("AdM");
	Bureaucrat President("President", 1);

	Shrub.execute(Michel);
	Michel.signForm(Shrub);
	Shrub.execute(Michel);
	Rob.execute(Michel);
	Michel.signForm(Pardon);
	Pardon.execute(Michel);
	Rob.execute(President);
	President.signForm(Pardon);
	Pardon.execute(President);
	return (0);
}