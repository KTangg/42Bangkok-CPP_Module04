/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 20:55:23 by spoolpra          #+#    #+#             */
/*   Updated: 2022/05/08 23:27:26 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Default Class Constructor
Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Ice construced with default mode" << std::endl;
}

// Copy Class Constructor
Ice::Ice(const Ice &src) : AMateria("ice")
{
	*this = src;
	std::cout << "Ice construced with copy mode" << std::endl;
}

// Class Deconstructor
Ice::~Ice(void)
{
	std::cout << "Ice deconstruced" << std::endl;
}

// Assign Operator Overload
Ice	&Ice::operator=(const Ice &rhs)
{
	// Make your Assignment here
	_type = rhs.getType();
	return (*this);
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria	*Ice::clone(void) const
{
	return (new Ice(*this));
}
