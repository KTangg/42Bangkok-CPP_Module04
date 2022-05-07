#include "WrongCat.hpp"

// Default Class Constructor
WrongCat::WrongCat(void)
{
	type = "WrongCat";
	std::cout << type << " has been synthesis" << std::endl;
}

// Copy Class Constructor
WrongCat::WrongCat(const WrongCat &src) : WrongAnimal()
{
	*this = src;
	std::cout << src.getType() << " has been cloned" << std::endl;
}

// Class Deconstructor
WrongCat::~WrongCat(void)
{
	std::cout << type << " turn in to dust" << std::endl;
}

// Assign Operator Overload
WrongCat	&WrongCat::operator=(const WrongCat &rhs)
{
	// Make your Assignment here
	type = rhs.getType();
	return (*this);
}

// Outstream Overload
std::ostream	&operator<<(std::ostream &out, const WrongCat &rhs)
{
	out << rhs.getType();
	return (out);
}

void	WrongCat::makeSound(void) const
{
	std::cout << type << ": Moew? Moew?? Moew???" << std::endl;
}
