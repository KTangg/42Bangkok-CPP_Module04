/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 20:32:36 by spoolpra          #+#    #+#             */
/*   Updated: 2022/05/08 23:40:52 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AMATERIA_HPP__
# define __AMATERIA_HPP__

class ICharacter;

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	public:
		// Constructor
		AMateria(std::string const	&type);

		// Getter Part
		std::string const	&getType(void) const;

		// Member Functions
		virtual void		use(ICharacter &target) = 0;
		virtual AMateria	*clone(void) const = 0;

		// Deconstructor
		virtual	~AMateria(void){};

	protected:
		std::string	_type;
};

std::ostream	&operator<<(std::ostream &out, AMateria const &rhs);

#endif // **************************************************** __AMATERIA_HPP__ //
