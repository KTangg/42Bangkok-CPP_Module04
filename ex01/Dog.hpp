#ifndef __DOG_HPP__
# define __DOG_HPP__

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Dog : public Animal
{
	public:
		// Default Class Constructor
		Dog(void);
		// Copy Class Constructor
		Dog(const Dog &src);
		Dog(const Animal &src);
		// Class Deconstructor
		virtual	~Dog(void);

		// Assign operator overload
		virtual Dog	&operator=(const Dog &rhs);

		// Getter function
		virtual Brain	*getBrain(void) const;

		// Function member part
		virtual void	makeSound(void) const;

	private:
		Brain	*_brain;
};

// outstream overload
std::ostream	&operator<<(std::ostream &out, const Dog &rhs);

#endif // **************************************************** __DOG_HPP__ //
