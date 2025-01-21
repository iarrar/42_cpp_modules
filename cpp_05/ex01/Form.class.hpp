#ifndef FORM_H
#define FORM_H
#include <string>
#include <iostream>
#include "Bureaucrat.class.hpp"

class Bureaucrat;

class Form
{
	public:
							Form();
							Form(std::string name, int sign, int exec);
							Form(Form const & src);
		virtual ~Form();
		Form&				operator=(Form const & src);
		std::string const &	getName() const;
		int			getS_Grade() const;
		int			getE_Grade() const;
		bool				getStatus() const;
		void				beSigned(Bureaucrat const & crat);

	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};	
	
	private:
		const std::string   _name;
		const int			e_grade;
		const int			s_grade;
		bool				_signed;

};

std::ostream &	operator<<(std::ostream & o, Form const & cerfa);

#endif