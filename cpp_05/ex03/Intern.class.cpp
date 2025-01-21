#include "Intern.class.hpp"

Intern::Intern()
{

}

Intern::Intern(Intern const & src)
{
	*this = src;
}

Intern::~Intern()
{

}

Intern & Intern::operator=(Intern const & src)
{
	(void)src;
	return (*this);
}


AForm*	Intern::makeShrub(std::string target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makePres(std::string target) const
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeRob(std::string target) const
{
	return (new RobotomyRequestForm(target));
}

AForm*				Intern::makeForm(std::string name, std::string target) const
{
	AForm* (Intern::*func_ptr[])(std::string) const = {&Intern::makePres, &Intern::makeRob, &Intern::makeShrub};
	std::string forms[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	int i = 0;
	while (i < 3)
	{
		if (forms[i] == name)
		{
			std::cout << "Intern create " << *(this->*func_ptr[i])(target) << std::endl;
			return ((this->*func_ptr[i])(target));
		}
		i++;
		if (i == 3)
		{
			std::cout << "Unknown form requested, le stagiaire en sureur" << std::endl;
			return (NULL);
		}
	}
	return (NULL);
}

