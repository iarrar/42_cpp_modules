#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H
#include "AForm.class.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(std::string target);
		virtual ~PresidentialPardonForm();
		void	execute(Bureaucrat const & executor) const;

	protected:
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const & src);
	PresidentialPardonForm& operator=(PresidentialPardonForm const & src);
		const std::string   _name;
		const int			s_grade;
		const int			e_grade;
		std::string			_target;
		bool				_signed;

};

#endif