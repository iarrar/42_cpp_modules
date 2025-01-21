#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"

int main()
{
	Bureaucrat crat;
	Bureaucrat Michel("Michel", 150);
	Michel.incrementGrade();
	std::cout << Michel << std::endl;
	std::cout << crat << std::endl;
	crat.decrementGrade();
	std::cout << crat << std::endl;
	std::cout <<"********************************************" << std::endl;
	Form cerfa;
	Form cerfa2("Demande de crayon", 149, 150);
	std::cout << std::endl;
	std::cout << cerfa << std::endl;
	std::cout << std::endl;
	crat.signForm(cerfa);
	std::cout << std::endl;
	Michel.signForm(cerfa);
	std::cout <<std::endl;
	crat.signForm(cerfa2);
	Michel.signForm(cerfa2);
	std::cout << std::endl;

	return (0);
}