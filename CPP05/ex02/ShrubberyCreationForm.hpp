#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{

	public:

		class FileAlreadyExistException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("FileAlreadyExistException : Cannot create file as it already exists");
				}
		};

		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		~ShrubberyCreationForm();

		void	action() const;

		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs );

	protected:

		ShrubberyCreationForm();

	private:

};

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i );

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */