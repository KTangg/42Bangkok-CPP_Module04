/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:01:41 by spoolpra          #+#    #+#             */
/*   Updated: 2022/05/07 16:44:51 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

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
		Animal	&operator=(const Animal &rhs);

		// Getter Function part
		std::string	getType(void) const;

		// Function member part
		virtual void	makeSound(void) const;

	protected:
		std::string	type;

	private:
};

// Outstream overload
std::ostream	&operator<<(std::ostream &out, const Animal &rhs);

#endif // **************************************************** __ANIMAL_HPP__ //
