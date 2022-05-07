#include "WrongAnimal.hpp"

// Default Class Constructor
WrongAnimal::WrongAnimal(void) : type("Unknown")
{
	std::cout << "Wrong Animal type " << type << " spawn" << std::endl;
}

// Copy Class Constructor
WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	*this = src;
	std::cout << "Wrong Animal type " << type << " copied" << std::endl;
}

// Class Deconstructor
WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Wrong Animal type " << type << " disappear" << std::endl;
}

// Assign Operator Overload
WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &rhs)
{
	// Make your Assignment here
	type = rhs.getType();
	return (*this);
}

// Outstream Overload
std::ostream	&operator<<(std::ostream &out, const WrongAnimal &rhs)
{
	out << rhs.getType() << " animal";	out << rhs.getType() << " animal";
	return (out);
}

std::string	WrongAnimal::getType(void) const
{
	return (type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << type << ": Roarrrrrr!!!!" << std::endl;
}
