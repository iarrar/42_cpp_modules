#include "Bureaucrat.class.hpp"

Bureaucrat::Bureaucrat() : _name("Mr Lambda"), _grade(150)
{
	std::cout << "Il est 9h, " << *this << " vient d'arriver au bureau." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw(Bureaucrat::GradeTooHighException());
	else
		_grade = grade;
	std::cout << "Il est 9h, " << getName() << " vient d'arriver au bureau." << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high exception!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low exception!");
}

void		Bureaucrat::incrementGrade()
{
	try
	{
		if (_grade <= 1)
			throw GradeTooHighException();
		else
			_grade--;
	}
	catch(const Bureaucrat::GradeTooHighException & e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void		Bureaucrat::decrementGrade()
{
	try
	{
		if (_grade >= 150)
			throw GradeTooLowException();
		else
			_grade++;
	}
	catch(const Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << e.what() << '\n';
	}
}

std::string const &		Bureaucrat::getName() const
{
	return (this->_name);
}

int						Bureaucrat::getGrade() const
{
	return (this->_grade);
}


Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	*this = src;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Il est 17h, Bureaucrat " << getName() << " rentre chez lui" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src)
{
	_grade = src.getGrade();

	return (*this);
}

void		Bureaucrat::signForm(AForm & cerfa) const
{
		if (cerfa.getStatus())
		{
			std::cout << getName() << " couldn't sign " << cerfa.getName() << " because ";
			std::cout << "Form : " << cerfa.getName() << " is already signed" << std::endl;
		}
		else if (cerfa.getS_Grade() >= getGrade())
		{
			std::cout << getName() << " signed the form : " << cerfa.getName() << std::endl;
			cerfa.beSigned(*this);
		}
		else
		{
			std::cout << getName() << " couldn't sign " << cerfa.getName() << " because he's is not important enough" << std::endl;
		}
}

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & crat)
{
	o << crat.getName() << ", bureaucrat grade " << crat.getGrade();
	return (o);
}
