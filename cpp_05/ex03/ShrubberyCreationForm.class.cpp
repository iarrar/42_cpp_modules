#include "ShrubberyCreationForm.class.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137), s_grade(145), e_grade(137)
{
	_target = target;
	_signed = false;
}


ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void					ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (reqCheck(executor))
	{
		std::string file = "banner.txt";
		std::string target = _target + "_shrubbery";
		std::ifstream is(file.c_str());
		std::ofstream os(target.c_str());
		std::string line;

		if (os.is_open())
		{
			while (getline(is, line))
			{
				os << line << std::endl;
			}
		}
	}
}
