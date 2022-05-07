/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:05:59 by spoolpra          #+#    #+#             */
/*   Updated: 2022/05/07 18:47:40 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP__
# define __CAT_HPP__

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Cat : public Animal
{
	public:
		// Default Class Constructor
		Cat(void);
		// Copy Class Constructor
		Cat(const Cat &src);
		// Class Deconstructor
		virtual	~Cat(void);

		// Assign operator overload
		virtual Cat	&operator=(const Cat &rhs);

		// Getter function part
		virtual Brain	*getBrain(void) const;

		// Function member part
		virtual void	makeSound(void) const;

	private:
		Brain	*_brain;
};

// outstream overload
std::ostream	&operator<<(std::ostream &out, const Cat &rhs);

#endif // **************************************************** __CAT_HPP__ //
