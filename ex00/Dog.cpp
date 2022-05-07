#include "Dog.hpp"

// Default Class Constructor
Dog::Dog(void)
{
	type = "Dog";
	std::cout << type << " awaiting for master" << std::endl;
}

// Copy Class Constructor
Dog::Dog(const Dog &src) : Animal()
{
	*this = src;
	std::cout << src.getType() << " just copied" << std::endl;
}

// Class Deconstructor
Dog::~Dog(void)
{
	std::cout << type << " run away" << std::endl;
}

// Assign Operator Overload
Dog	&Dog::operator=(const Dog &rhs)
{
	// Make your Assignment here
	type = rhs.getType();
	return (*this);
}

// Outstream Overload
std::ostream	&operator<<(std::ostream &out, const Dog &rhs)
{
	out << rhs.getType() << " type";
	return (out);
}

void	Dog::makeSound(void) const
{
	std::cout << type << ": Barking at you!!" << std::endl;
}
