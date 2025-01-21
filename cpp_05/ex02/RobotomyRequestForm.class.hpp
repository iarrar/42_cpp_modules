#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H
#include "AForm.class.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(std::string target);
		virtual ~RobotomyRequestForm();
		void	execute(Bureaucrat const & executor) const;

	protected:
		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const & src);
	RobotomyRequestForm& operator=(RobotomyRequestForm const & src);
		const std::string   _name;
		const int			s_grade;
		const int			e_grade;
		bool				_signed;
		std::string			_target;
		int					_time;

};

#endif