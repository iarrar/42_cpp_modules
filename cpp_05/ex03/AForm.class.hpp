#ifndef AFORM_H
#define AFORM_H
#include <string>
#include <iostream>
#include <fstream>
#include "Bureaucrat.class.hpp"

class Bureaucrat;

class AForm
{
	public:
							AForm(std::string name, int sign, int exec);
							AForm(AForm const & src);
		virtual 			~AForm();
		AForm&				operator=(AForm const & src);
		std::string const &	getName() const;
		int					getS_Grade() const;
		int					getE_Grade() const;
		bool				getStatus() const;
		void				beSigned(Bureaucrat const & crat);
		virtual void		execute(Bureaucrat const & executor) const;
		bool				reqCheck(Bureaucrat const & executor) const;

	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};

	protected :

		AForm();
	
	private:
		const std::string   _name;
		const int			e_grade;
		const int			s_grade;
		bool				_signed;

};

std::ostream &	operator<<(std::ostream & o, AForm const & cerfa);

#endif