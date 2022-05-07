#include "Dog.hpp"

// Default Class Constructor
Dog::Dog(void)
{
	type = "Dog";
	_brain = new Brain();
	std::cout << type << " awaiting for master" << std::endl;
}

// Copy Class Constructor
Dog::Dog(const Dog &src) : Animal(), _brain(new Brain())
{
	*this = src;
	std::cout << src.getType() << " just copied" << std::endl;
}

// Class Deconstructor
Dog::~Dog(void)
{
	delete _brain;
	std::cout << type << " run away" << std::endl;
}

// Assign Operator Overload
Dog	&Dog::operator=(const Dog &rhs)
{
	// Make your Assignment here
	type = rhs.getType();
	*_brain = *rhs.getBrain();
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

Brain	*Dog::getBrain(void) const
{
	return (_brain);
}
