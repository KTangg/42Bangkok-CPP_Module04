/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:06:01 by spoolpra          #+#    #+#             */
/*   Updated: 2022/05/07 19:18:52 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Default Class Constructor
Cat::Cat(void)
{
	type = "Cat";
	_brain = new Brain();
	std::cout << type << " jump in" << std::endl;
}

// Copy Class Constructor
Cat::Cat(const Cat &src) : Animal(), _brain(new Brain())
{
	*this = src;
	std::cout << src.getType() << " just copied" << std::endl;
}

// Class Deconstructor
Cat::~Cat(void)
{
	delete _brain;
	std::cout << type << " jump away" << std::endl;
}

// Assign Operator Overload
Cat	&Cat::operator=(const Cat &rhs)
{
	// Make your Assignment here
	type = rhs.getType();
	*_brain = *rhs.getBrain();
	return (*this);
}

// Outstream Overload
std::ostream	&operator<<(std::ostream &out, const Cat &rhs)
{
	out << rhs.getType() << " type";
	return (out);
}

void	Cat::makeSound(void) const
{
	std::cout << type << ": Meowww~" << std::endl;
}

Brain	*Cat::getBrain(void) const
{
	return (_brain);
}
