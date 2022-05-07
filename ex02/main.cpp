/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:18:25 by spoolpra          #+#    #+#             */
/*   Updated: 2022/05/07 19:24:24 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NANIMAL
# define NANIMAL 10
#endif
#include <iomanip>
#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void	showAnimal(Animal *subject, int i)
{
	std::cout << "Showing Animal #" << std::setfill('0') << std::setw(3) << i + 1 << std::endl;
	std::cout << "Type: " << subject->getType() << std::endl;
	std::cout << "Make some noise" << std::endl;
	subject->makeSound();
	std::cout << "Top 3 Idea in Brain??" << std::endl;
	Brain	*brain = subject->getBrain();
	for (int i = 0; i < 3; i++)
	{
		std::cout << i + 1 << ". " << brain->getIdea(i) << std::endl;
	}
	std::cout << std::endl;
}

int main(void)
{
	// Delete the below comment to unleash the compiler power
	//Animal	sureError = Animal();

	Animal*	AnimalArr[NANIMAL];

	for (int i = 0; i < NANIMAL; i++)
	{
		std::cout << "Creating Animal #" << std::setfill('0') << std::setw(3) << i + 1 << std::endl;
		if (i < NANIMAL / 2)
		{
			AnimalArr[i] = new Dog();
		}
		else
		{
			AnimalArr[i] = new Cat();
		}
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl << std::endl;

	// Show some Animal
	std::cout << "Animal Show Begin" << std::endl;
	showAnimal(AnimalArr[0], 0);
	showAnimal(AnimalArr[3], 3);
	showAnimal(AnimalArr[7], 7);
	showAnimal(AnimalArr[9], 9);

	std::cout << "Clone some Animal" << std::endl;
	Animal	*clone00 = new Dog(*(Dog*)AnimalArr[0]);
	Animal	*clone01 = new Cat(*(Cat*)AnimalArr[7]);
	std::cout << std::endl;
	std::cout << "Look like clone are smart than original" << std::endl << std::endl;
	clone00->getBrain()->setIdea(0, "I am smarter");
	clone00->getBrain()->setIdea(1, "I need some bone");
	clone00->getBrain()->setIdea(2, "I am a dog");
	clone01->getBrain()->setIdea(0, "I am smarter");
	clone01->getBrain()->setIdea(1, "Human are my slave");
	clone01->getBrain()->setIdea(2, "I can't clean my own sh*t");
	showAnimal(clone00, 0);
	showAnimal(clone01, 7);
	std::cout << std::endl;
	std::cout << "This is original idea" << std::endl << std::endl;
	showAnimal(AnimalArr[0], 0);
	showAnimal(AnimalArr[7], 7);

	delete clone00;
	delete clone01;
	std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
	for (int i = 0; i < NANIMAL; i++)
	{
		std::cout << "Killing Animal #" << std::setfill('0') << std::setw(3) << i + 1 << std::endl;
		delete AnimalArr[i];
		std::cout << std::endl;
	}
	return (0);
}
