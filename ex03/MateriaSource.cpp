/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 22:53:11 by spoolpra          #+#    #+#             */
/*   Updated: 2022/05/08 23:37:52 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Default Class Constructor
MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < SOURCESIZE; i++)
	{
		_source[i] = NULL;
	}
	std::cout << "MateriaSource Founded" << std::endl;
}

// Copy Class Constructor
MateriaSource::MateriaSource(MateriaSource const &src)
{
	*this = src;
	std::cout << "MateriaSource Copied" << std::endl;
}

// Class Deconstructor
MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < SOURCESIZE; i++)
	{
		if (_source[i] != NULL)
			delete _source[i];
	}
	std::cout << "MateriaSource Destroyed" << std::endl;
}

// Assign Operator Overload
MateriaSource	&MateriaSource::operator=(MateriaSource const &rhs)
{
	// Make your Assignment here
	for (int i = 0; i < SOURCESIZE; i++)
	{
		if (_source[i] != NULL)
			delete _source[i];
		if (rhs._source[i] == NULL)
			_source[i] = NULL;
		else
			_source[i] = rhs._source[i]->clone();
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (m == NULL)
	{
		std::cout << "MateriaSource: Couldn't learn empty Materia" << std::endl;
		return ;
	}
	for (int i = 0; i < SOURCESIZE; i++)
	{
		if (_source[i] == NULL)
		{
			_source[i] = m;
			std::cout << "Learned " << *m << std::endl;
			return ;
		}
	}
	std::cout << "No available slot in MateriaSource" << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < SOURCESIZE; i++)
	{
		if (_source[i] == NULL)
			continue ;
		if (_source[i]->getType() == type)
		{
			return (_source[i]->clone());
		}
	}
	std::cout << "Couldn't create Unknown type" << std::endl;
	return (NULL);
}
