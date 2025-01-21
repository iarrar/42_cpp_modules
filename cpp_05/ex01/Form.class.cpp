#include "Form.class.hpp"

Form::Form() : _name("Cerfa 001"), e_grade(150), s_grade(150)
{
    _signed = false;
}

Form::Form(std::string name, int sign, int exec) : _name(name), e_grade(exec), s_grade(sign)
{
    if (e_grade > 150)
		throw(Form::GradeTooLowException());
	else if (e_grade < 1)
		throw(Form::GradeTooHighException());
    else if (s_grade > 150)
		throw(Form::GradeTooLowException());
	else if (s_grade < 1)
		throw(Form::GradeTooHighException());
	else
        _signed = false;
}

Form::Form(Form const & src) : _name(src.getName()), e_grade(src.getE_Grade()), s_grade(src.getS_Grade())
{
    _signed = src.getStatus();
    *this = src;
}

Form::~Form()
{

}

std::string const & Form::getName() const
{
    return (_name);
}

int            Form::getE_Grade() const
{
    return (e_grade);
}

int           Form::getS_Grade() const
{
    return (s_grade);
}

bool                Form::getStatus() const
{
    return (_signed);
}

const char*         Form::GradeTooHighException::what() const throw()
{
    return("Form grade too high exception");
}

const char*         Form::GradeTooLowException::what() const throw()
{
    return ("Form grade too low exception");
}

Form & Form::operator=(Form const & src)
{
    _signed = src.getStatus();
    return (*this);
}

void                Form::beSigned(Bureaucrat  const & crat)
{
    if (s_grade >= crat.getGrade())
    {
        _signed = true;
    }
    return ;
}

std::ostream &      operator<<(std::ostream & o, Form const & cerfa)
{
    o << "Form " << cerfa.getName() << ". Grade to be signed : " << cerfa.getS_Grade() << "\nGrade to be executed : " << cerfa.getE_Grade();
    return (o);
}