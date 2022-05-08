#ifndef __CHARACTER_HPP__
# define __CHARACTER_HPP__

# define BAGSIZE 4

# include <iostream>
# include <iomanip>
# include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		// Default Class Constructor
		Character(void);
		// Copy Class Constructor
		Character(Character const &src);
		// Class Deconstructor
		virtual	~Character(void);

		// Assign operator overload
		Character	&operator=(Character const &rhs);

		// String Class Constructor
		Character(std::string name);

		// Getter part
		std::string const	&getName(void) const;
		AMateria const		*getInventory(int idx) const;

		// Setter part
		void	setName(std::string const name);

		// Function members part
		void	equip(AMateria *m);
		void	unequip(int idx);
		void	use(int idx, ICharacter &target);

	private:
		std::string	_name;
		AMateria	*_inventory[BAGSIZE];
};

// outstream overload
std::ostream	&operator<<(std::ostream &out, Character const &rhs);

#endif // **************************************************** __CHARACTER_HPP__ //
