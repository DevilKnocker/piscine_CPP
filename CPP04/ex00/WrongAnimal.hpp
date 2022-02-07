#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{

	public:

		WrongAnimal();
		WrongAnimal( WrongAnimal const & src );
		~WrongAnimal();

		WrongAnimal &		operator=( WrongAnimal const & rhs );

		std::string getType() const;
		void makeSound() const;

	protected:

		std::string _type;
		
	private:

};

std::ostream &			operator<<( std::ostream & o, WrongAnimal const & i );

#endif /* ***************************************************** WRONGANIMAL_H */