/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:18:25 by spoolpra          #+#    #+#             */
/*   Updated: 2022/05/07 16:46:48 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	// Create wild Animal
	const Animal *wild = new Animal();
	// Create Dog
	const Animal *inu = new Dog();
	// Create Cat
	const Animal *neko = new Cat();

	std::cout << std::endl;
	// Get type define in Animal object
	std::cout << wild->getType() << std::endl;
	std::cout << inu->getType() << std::endl;
	std::cout << neko->getType() << std::endl;

	std::cout << std::endl;
	// Dog Bark
	inu->makeSound();
	// Cat Meow
	neko->makeSound();
	// Wild Roar
	wild->makeSound();

	std::cout << std::endl;
	std::cout << *wild << std::endl;
	delete wild;
	std::cout << *(Cat *)neko << std::endl;
	delete neko;
	std::cout << *(Dog *)inu << std::endl;
	delete inu;

	std::cout << std::endl;
	// Create weird Animal
	const WrongAnimal *subject0 = new WrongAnimal();
	// Create weird Cat
	const WrongAnimal *subject1 = new WrongCat();

	std::cout << std::endl;
	// Get type define in Animal object
	std::cout << subject0->getType() << std::endl;
	std::cout << subject1->getType() << std::endl;

	std::cout << std::endl;
	// Dog Bark
	subject0->makeSound();
	// Cat Meow
	subject1->makeSound();

	return (0);
}
