#include "AForm.class.hpp"

AForm::AForm() : _name("Cerfa 001"), e_grade(150), s_grade(150)
{
    _signed = false;
}

AForm::AForm(std::string name, int sign, int exec) : _name(name), e_grade(exec), s_grade(sign)
{
    _signed = false;
}

AForm::AForm(AForm const & src) : _name(src.getName()), e_grade(src.getE_Grade()), s_grade(src.getS_Grade())
{
    _signed = src.getStatus();
    *this = src;
}

AForm::~AForm()
{

}

std::string const & AForm::getName() const
{
    return (_name);
}

int            AForm::getE_Grade() const
{
    return (e_grade);
}

int           AForm::getS_Grade() const
{
    return (s_grade);
}

bool                AForm::getStatus() const
{
    return (_signed);
}

const char*         AForm::GradeTooHighException::what() const throw()
{
    return("AForm grade too high exception");
}

const char*         AForm::GradeTooLowException::what() const throw()
{
    return ("AForm grade too low exception");
}

AForm & AForm::operator=(AForm const & src)
{
    _signed = src.getStatus();
    return (*this);
}

void                AForm::beSigned(Bureaucrat  const & crat)
{
    if (s_grade >= crat.getGrade())
    {
        _signed = true;
    }
    return ;
}

std::ostream &      operator<<(std::ostream & o, AForm const & cerfa)
{
    o << "Form " << cerfa.getName() << ". Grade to be signed : " << cerfa.getS_Grade() << "\nGrade to be executed : " << cerfa.getE_Grade();
    return (o);
}

bool				AForm::reqCheck(Bureaucrat const & executor) const
{
    if (!getStatus())
    {
        std::cout << "Form " << getName() << " needs to be signed prior to execution" << std::endl;
        return (false);
    }
    else if (executor.getGrade() <= getE_Grade())
        return (true);
    else
    {
        std::cout << "Bureaucrat " << executor.getName() << " cannot execute the form " << getName() << std::endl;
        return (false);
    }
}
