/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 23:10:18 by spoolpra          #+#    #+#             */
/*   Updated: 2022/05/09 19:08:37 by spoolpra         ###   ########.fr       */
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


	// Testing MateriaSource ********************************************************************************************//
	std::cout << "Testing ## MateriaSource ##" << std::endl;
	std::cout << std::setw(100) << std::setfill('-') << "";
	std::cout << std::endl << std::endl;
	// Creating new MateriaSource
	std::cout << "Creating New MateriaSource" << std::endl;
	IMateriaSource* src = new MateriaSource();
	std::cout << std::endl;
	// Learn Null
	std::cout << "Learn NULL" << std::endl;
	src->learnMateria(NULL);
	std::cout << std::endl;

	// Learn until full slot
	std::cout << "Learn 4 Materia" << std::endl;
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << std::endl;

	// Try to exceed maximum slot
	std::cout << "Try to Learn 5 Materia" << std::endl;
	tmp = new Cure();
	src->learnMateria(tmp);
	delete tmp;
	std::cout << std::endl;

	// Create something notexist
	std::cout << "Try to Create Materia that doen't exist" << std::endl;
	tmp = src->createMateria("fire");
	tmp = src->createMateria("Ice");
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << std::setw(100) << std::setfill('-') << "";
	std::cout << std::endl;

	// ********************************************************************************************************* End Test//

	// Testing Character ************************************************************************************************//

	// Creating new character
	std::cout << "Create new character name as Armel" << std::endl;
	ICharacter	*armel = new Character("Armel");
	std::cout << std::endl;

	// Assign 4 Materia to Armel
	std::cout << "Equip 4 Materia with NULL case" << std::endl;
	armel->equip(NULL);
	tmp = src->createMateria("ice");
	armel->equip(tmp);
	tmp = src->createMateria("cure");
	armel->equip(tmp);
	tmp = src->createMateria("cure");
	armel->equip(tmp);
	tmp = src->createMateria("ice");
	armel->equip(tmp);
	std::cout << std::endl;

	// Assign exceed limit
	std::cout << "Try to Equip 5 Materia to Armel" << std::endl;
	tmp = src->createMateria("cure");
	armel->equip(tmp);
	floor[0] = tmp;
	std::cout << std::endl;

	// Clone new character
	std::cout << "Clone Armel and giving clone name as Vlad" << std::endl;
	ICharacter *vlad = new Character(*(Character*)armel);
	((Character*)vlad)->setName("Vlad");
	std::cout << std::endl;

	// Show clone result
	std::cout << *(Character*)armel << std::endl;
	std::cout << *(Character*)vlad << std::endl;

	// Unequip Vlad Materia
	std::cout << "Uneqiup Vlad Materia" << std::endl;
	floor[1] = ((Character*)vlad)->getInventory(0);
	floor[2] = ((Character*)vlad)->getInventory(2);
	vlad->unequip(0);
	vlad->unequip(2);
	vlad->unequip(2);
	vlad->unequip(42);
	std::cout << *(Character*)vlad << std::endl;

	// Assign new Materia to Vlad
	std::cout << "Eqiup Materia to Vlad" << std::endl;
	tmp = src->createMateria("cure");
	vlad->equip(tmp);
	tmp = src->createMateria("ice");
	vlad->equip(tmp);
	std::cout << std::endl;

	// Display Armel and Vlad to show deep copy
	std::cout << *(Character*)armel << std::endl;
	std::cout << *(Character*)vlad << std::endl;


	// Testing Fire power
	std::cout << "Using equip Materia" << std::endl;
	armel->use(0, *vlad);
	armel->use(42, *vlad);
	vlad->use(1, *armel);
	std::cout << std::endl;

	// ********************************************************************************************************* End Test//

	// Deleting all variables ********************************************************************************************//
	std::cout << "Deleting MateriaSource" << std::endl;
	delete src;
	std::cout << std::endl;
	std::cout << "Deleting Armel Character" << std::endl;
	delete armel;
	std::cout << std::endl;
	std::cout << "Deleting Vlad Character" << std::endl;
	delete vlad;
	std::cout << std::endl;
	std::cout << "Deleting Materia on the floor" << std::endl;
	for (int i = 0; i < FLOORSIZE; i++)
	{
		if (floor[i] != NULL)
			delete floor[i];
	}
	std::cout << std::setw(100) << std::setfill('-') << "";
	std::cout << std::endl;
	// ********************************************************************************************************* End Test//
	return 0;
}
