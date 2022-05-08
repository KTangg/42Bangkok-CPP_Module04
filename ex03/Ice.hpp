/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 20:55:30 by spoolpra          #+#    #+#             */
/*   Updated: 2022/05/08 20:57:56 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICE_HPP__
# define __ICE_HPP__

# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		// Default Class Constructor
		Ice(void);
		// Copy Class Constructor
		Ice(const Ice &src);
		// Class Deconstructor
		virtual	~Ice(void);

		// Assign operator overload
		Ice	&operator=(const Ice &rhs);

		// Function member part
		virtual void		use(ICharacter &target);
		virtual AMateria	*clone(void) const;

	private:

};

#endif // **************************************************** __ICE_HPP__ //
