/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 23:04:43 by spoolpra          #+#    #+#             */
/*   Updated: 2022/05/09 00:20:28 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Default Class Constructor
Character::Character(void) : _name("Unname")
{
	for (int i = 0; i < BAGSIZE; i++)
	{
		_inventory[i] = NULL;
	}
	std::cout << "New Character born without a name" << std::endl;
}

// String Class Constructor
Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < BAGSIZE; i++)
	{
		_inventory[i] = NULL;
	}
	std::cout << _name << " Character born " << std::endl;
}


// Copy Class Constructor
Character::Character(Character const &src)
{
	*this = src;
	std::cout << _name << " Character born by cloning process" << std::endl;
}

// Class Deconstructor
Character::~Character(void)
{
	for (int i = 0; i < BAGSIZE; i++)
	{
		if (_inventory[i] != NULL)
			delete _inventory[i];
	}
	std::cout << _name << " Character passed away" << std::endl;
}

// Assign Operator Overload
Character	&Character::operator=(Character const &rhs)
{
	AMateria const	*tmpMat;
	// Make your Assignment here
	_name = rhs.getName();

	// Delete Old inventory && Clone new one
	for (int i = 0; i < BAGSIZE; i++)
	{
		if (_inventory[i] != NULL)
			delete _inventory[i];
		tmpMat = rhs.getInventory(i);
		if (tmpMat == NULL)
			_inventory[i] = NULL;
		else
			_inventory[i] = tmpMat->clone();
	}
	return (*this);
}

// Outstream Overload
std::ostream	&operator<<(std::ostream &out, Character const &rhs)
{
	AMateria const	*tmpMat;
	out << std::setfill(' ');
	out << "Character Name: " << rhs.getName() << std::endl << std::endl;
	out << " -------------------- -------------------- " << std::endl;
	out << "|" << std::setw(20) << "Slot number";
	out << "|" << std::setw(20) << "Materia type";
	out << "|" << std::endl;
	out << " -------------------- -------------------- " << std::endl;

	for (int i = 0; i < BAGSIZE; i++)
	{
		tmpMat = rhs.getInventory(i);
		out << "|" << std::setw(20) << i + 1;
		if (tmpMat == NULL)
			out << "|" << std::setw(20) << "(None)";
		else
			out << "|" << std::setw(20) << tmpMat->getType();
		out << "|" << std::endl;
	}
	out << " -------------------- -------------------- " << std::endl;
	return (out);
}

// Getter Part ************************************************************** //

std::string const	&Character::getName(void) const
{
	return (_name);
}

AMateria const	*Character::getInventory(int idx) const
{
	if (idx >= 0 && idx < BAGSIZE)
		return (_inventory[idx]);
	return (NULL);
}

// ************************************************************** Getter Part //

void	Character::setName(std::string const name)
{
	_name = name;
}


// Member Function ********************************************************** //

void	Character::equip(AMateria	*m)
{
	if (m == NULL)
	{
		std::cout << _name << ": Couldn't equip empty Materia" << std::endl;
		return ;
	}
	AMateria const	*tmpMat;
	for (int i = 0; i < BAGSIZE; i++)
	{
		tmpMat = _inventory[i];
		if (tmpMat == NULL)
		{
			_inventory[i] = m;
			std::cout << _name << ": Slot #" << std::setw(2) << std::setfill('0') << i + 1;
			std::cout << " equiped with " << *_inventory[i] << std::endl;
			return ;
		}
	}
	std::cout << _name << ": Full Inventory" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > BAGSIZE)
	{
		std::cout << _name << ": only got " << BAGSIZE << " slots" << std::endl;
		return ;
	}
	if (_inventory[idx] == NULL)
	{
		std::cout << _name << ": Slot #" << std::setw(2) << std::setfill('0') << idx + 1;
		std::cout << " has nothing" << std::endl;
	}
	else
	{

		std::cout << _name << ": drop " << *_inventory[idx] << " on the ground" << std::endl;
		_inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > BAGSIZE)
	{
		std::cout << _name << ": only got " << BAGSIZE << " slots" << std::endl;
		return ;
	}
	if (_inventory[idx] == NULL)
	{
		std::cout << _name << ": Slot #" << std::setw(2) << std::setfill('0') << idx + 1;
		std::cout << " has nothing" << std::endl;
	}
	else
	{
		std::cout << _name << ": using " << _inventory[idx]->getType() << std::endl;
		_inventory[idx]->use(target);
	}
}

// ********************************************************** Member Function //
