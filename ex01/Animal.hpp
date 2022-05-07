/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:01:41 by spoolpra          #+#    #+#             */
/*   Updated: 2022/05/07 18:52:53 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

# include "Brain.hpp"
# include <iostream>

class Animal
{
	public:
		// Default Class Constructor
		Animal(void);
		// Copy Class Constructor
		Animal(const Animal &src);
		// Class Deconstructor
		virtual	~Animal(void);

		// Assign operator overload
		virtual Animal	&operator=(const Animal &rhs);

		// Getter Function part
		std::string	getType(void) const;
		virtual Brain	*getBrain(void) const = 0;

		// Function member part
		virtual void	makeSound(void) const;

	protected:
		std::string	type;

	private:
};

// Outstream overload
std::ostream	&operator<<(std::ostream &out, const Animal &rhs);

#endif // **************************************************** __ANIMAL_HPP__ //
