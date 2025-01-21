#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H
#include "AForm.class.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(std::string target);
		virtual ~ShrubberyCreationForm();
		void	execute(Bureaucrat const & executor) const;
	private:
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const & src);
		ShrubberyCreationForm(std::string name, int s_grade, int e_grade);
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		const std::string   _name;
		const int			s_grade;
		const int			e_grade;
		bool				_signed;
		std::string			_target;
};

#endif