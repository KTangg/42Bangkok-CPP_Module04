/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 20:32:34 by spoolpra          #+#    #+#             */
/*   Updated: 2022/05/08 23:40:56 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "Materia type: " << _type << " constructed" << std::endl;
	return ;
}

std::string const	&AMateria::getType(void) const
{
	return (_type);
}

std::ostream	&operator<<(std::ostream &out, AMateria const &rhs)
{
	out << "Materia[" << rhs.getType() << "]";
	return (out);
}
