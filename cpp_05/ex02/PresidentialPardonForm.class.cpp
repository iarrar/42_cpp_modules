#include "PresidentialPardonForm.class.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) :  AForm("Presidential", 25, 5), s_grade(25), e_grade(5), _target(target), _signed(false)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (reqCheck(executor))
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
