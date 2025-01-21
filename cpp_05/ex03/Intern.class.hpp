#ifndef INTERN_H
#define INTERN_H
#include "AForm.class.hpp"
#include "ShrubberyCreationForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"

class Intern
{
	public:
								Intern();
								Intern(Intern const & src);
		virtual 				~Intern();
		Intern&					operator=(Intern const & src);
		AForm*					makeForm(std::string type, std::string target) const;

	protected:
		AForm*	makeShrub(std::string target) const;
		AForm*	makePres(std::string target) const;
		AForm*	makeRob(std::string target) const;

};

#endif