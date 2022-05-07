#ifndef __DOG_HPP__
# define __DOG_HPP__

# include "Animal.hpp"
# include <iostream>

class Dog : public Animal
{
	public:
		// Default Class Constructor
		Dog(void);
		// Copy Class Constructor
		Dog(const Dog &src);
		// Class Deconstructor
		virtual	~Dog(void);

		// Assign operator overload
		Dog	&operator=(const Dog &rhs);

		// Function member part
		virtual void	makeSound(void) const;

	private:
};

// outstream overload
std::ostream	&operator<<(std::ostream &out, const Dog &rhs);

#endif // **************************************************** __DOG_HPP__ //
