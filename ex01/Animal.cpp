/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:01:45 by spoolpra          #+#    #+#             */
/*   Updated: 2022/05/07 16:22:25 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Default Class Constructor
Animal::Animal(void) : type("Unknown")
{
	std::cout << "Animal type " << type << " spawn" << std::endl;
}

// Copy Class Constructor
Animal::Animal(const Animal &src)
{
	*this = src;
	std::cout << "Animal type " << type << " copied" << std::endl;
}

// Class Deconstructor
Animal::~Animal(void)
{
	std::cout << "Animal type " << type << " disappear" << std::endl;
}

// Assign Operator Overload
Animal	&Animal::operator=(const Animal &rhs)
{
	// Make your Assignment here
	type = rhs.getType();
	return (*this);
}

// Outstream Overload
std::ostream	&operator<<(std::ostream &out, const Animal &rhs)
{
	out << rhs.getType() << " animal";
	return (out);
}

// Getter Function
std::string	Animal::getType(void) const
{
	return (type);
}


// Member Function
void	Animal::makeSound(void) const
{
	std::cout << "Some animal roar from distant..." << std::endl;
}
