#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>
#include "Form.class.hpp"

class Form;


class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & src);
		virtual ~Bureaucrat();
	Bureaucrat& operator=(Bureaucrat const & src);
	std::string const & getName() const;
	int					getGrade() const;
	void				incrementGrade();
	void				decrementGrade();
	void				signForm(Form & cerfa) const;

	class GradeTooHighException : public std::exception
	{
		public :
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public :
		virtual const char* what() const throw();
	};

	protected:
		const std::string	_name;
		int                 _grade;

};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & crat);

#endif