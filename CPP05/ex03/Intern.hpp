#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		Form* makeForm(std::string formname, std::string targetname);
		
		Intern &		operator=( Intern const & rhs );

	private:

		Form* makepres(std::string target);
		Form* makerobo(std::string target);
		Form* makeshrub(std::string target);
};


#endif /* ********************************************************** INTERN_H */