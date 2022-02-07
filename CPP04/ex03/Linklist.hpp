#ifndef LINKLIST_HPP
# define LINKLIST_HPP

# include <iostream>
# include <string>
# include <AMateria.hpp>

struct Node
{
    AMateria* data;
    Node* next;
};

class Linklist
{

	private:
        Node* _first;
        int _count;
        Node* CreateNode (AMateria* value);
     
    public:
        Linklist ();
		Linklist (int const & value);
		Linklist( const Linklist & src );
        ~Linklist ();
		void empty ();
        void add (AMateria* value);

		Linklist &				operator=( Linklist const & rhs );
		Linklist &				operator=( int const & value );
};

#endif /* ******************************************************** LINKLIST_H */