#ifndef __CAT_HPP__
# define __CAT_HPP__

# include "Animal.hpp"
# include <iostream>

class Cat : public Animal
{
	public:
		// Default Class Constructor
		Cat(void);
		// Copy Class Constructor
		Cat(const Cat &src);
		// Class Deconstructor
		virtual	~Cat(void);

		// Assign operator overload
		Cat	&operator=(const Cat &rhs);

		// Function member part
		virtual void	makeSound(void) const;

	private:
};

// outstream overload
std::ostream	&operator<<(std::ostream &out, const Cat &rhs);

#endif // **************************************************** __CAT_HPP__ //
