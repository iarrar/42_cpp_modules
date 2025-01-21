#include "RobotomyRequestForm.class.hpp"


RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45), s_grade(72), e_grade(45), _target(target), _time(1)
{
    _signed = false;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void        RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (reqCheck(executor))
    {
        if (_time % 2 == 0)
            std::cout << _target << " has been robotomized successfully by " << executor.getName() << std::endl;
        else
            std::cout << executor.getName() << "failed to robotomize " << _target << std::endl;
    }
}