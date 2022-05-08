/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 20:46:25 by spoolpra          #+#    #+#             */
/*   Updated: 2022/05/08 20:54:46 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CURE_HPP__
# define __CURE_HPP__

# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		// Default Class Constructor
		Cure(void);
		// Copy Class Constructor
		Cure(const Cure &src);
		// Class Deconstructor
		virtual	~Cure(void);

		// Assign operator overload
		Cure	&operator=(const Cure &rhs);

		// Function member part
		virtual void		use(ICharacter &target);
		virtual AMateria	*clone(void) const;

	private:

};

#endif // **************************************************** __CURE_HPP__ //
