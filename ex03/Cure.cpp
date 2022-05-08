/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 20:46:27 by spoolpra          #+#    #+#             */
/*   Updated: 2022/05/08 21:03:23 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// Default Class Constructor
Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure construced with default mode" << std::endl;
}

// Copy Class Constructor
Cure::Cure(const Cure &src) : AMateria("cure")
{
	*this = src;
	std::cout << "Cure construced with copy mode" << std::endl;
}

// Class Deconstructor
Cure::~Cure(void)
{
	std::cout << "Cure deconstruced" << std::endl;
}

// Assign Operator Overload
Cure	&Cure::operator=(const Cure &rhs)
{
	// Make your Assignment here
	_type = rhs.getType();
	return (*this);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria	*Cure::clone(void) const
{
	return (new Cure(*this));
}
