/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 23:10:18 by spoolpra          #+#    #+#             */
/*   Updated: 2022/05/09 00:32:41 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

#define FLOORSIZE 10

int main(void)
{
	AMateria* tmp;
	AMateria const	*floor[FLOORSIZE];

	for (int i = 0; i < FLOORSIZE; i++)
	{
		floor[i] = NULL;
	}


	// Testing MateriaSource
	std::cout << "Testing ## MateriaSource ##" << std::endl;
	std::cout << std::setw(100) << std::setfill('-') << "";
	std::cout << std::endl << std::endl;
	IMateriaSource* src = new MateriaSource();
	std::cout << std::endl;
	src->learnMateria(NULL);
	std::cout << std::endl;
	src->learnMateria(new Ice());
	std::cout << std::endl;
	src->learnMateria(new Cure());
	std::cout << std::endl;
	src->learnMateria(new Ice());
	std::cout << std::endl;
	src->learnMateria(new Ice());
	std::cout << std::endl;
	tmp = new Ice();
	src->learnMateria(tmp);
	delete tmp;
	std::cout << std::endl;
	std::cout << std::setw(100) << std::setfill('-') << "";
	std::cout << std::endl << std::endl;

	// Testing Character && Materia
	std::cout << "Testing ## Character && Materia ##" << std::endl;
	std::cout << std::setw(100) << std::setfill('-') << "";
	std::cout << std::endl << std::endl;
	ICharacter* armel = new Character("Armel");
	std::cout << std::endl;
	tmp = src->createMateria("fire");
	std::cout << std::endl;
	tmp = src->createMateria("ice");
	armel->equip(tmp);
	std::cout << std::endl;
	tmp = src->createMateria("cure");
	armel->equip(tmp);
	std::cout << std::endl;
	tmp = src->createMateria("ice");
	armel->equip(tmp);
	std::cout << std::endl;
	tmp = src->createMateria("ice");
	armel->equip(tmp);
	std::cout << std::endl;
	std::cout << *(Character *)armel << std::endl;
	tmp = src->createMateria("ice");
	armel->equip(tmp);
	delete tmp;

	ICharacter* vlad = new Character(*(Character *)armel);
	((Character *)vlad)->setName("Vlad");
	std::cout << std::endl;
	std::cout << *(Character *)vlad << std::endl;
	floor[0] = ((Character *)vlad)->getInventory(0);
	vlad->unequip(5);
	std::cout << std::endl;
	vlad->unequip(0);
	vlad->equip(src->createMateria("cure"));
	std::cout << std::endl;
	std::cout << *(Character *)vlad << std::endl;
	std::cout << std::endl;
	std::cout << *(Character *)armel << std::endl;

	std::cout << std::setw(100) << std::setfill('-') << "";
	std::cout << std::endl << std::endl;

	std::cout << "Testing ## Fire Power ##" << std::endl;
	std::cout << std::setw(100) << std::setfill('-') << "";
	std::cout << std::endl << std::endl;

	armel->use(5, *vlad);
	armel->use(0, *vlad);
	vlad->use(0, *armel);

	std::cout << std::endl;
	std::cout << *(Character *)vlad << std::endl;
	std::cout << *(Character *)armel << std::endl;

	*(Character *)armel = *(Character *)vlad;
	std::cout << std::endl;
	std::cout << *(Character *)vlad << std::endl;
	std::cout << *(Character *)armel << std::endl;

	std::cout << std::setw(100) << std::setfill('-') << "";
	std::cout << std::endl << std::endl;

	delete floor[0];
	delete vlad;
	delete armel;
	delete src;
	return 0;
}
