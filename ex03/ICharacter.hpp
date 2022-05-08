/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 20:46:24 by spoolpra          #+#    #+#             */
/*   Updated: 2022/05/08 23:21:46 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICHARACTER_HPP__
# define __ICHARACTER_HPP__

class AMateria;

# include <iostream>
# include "AMateria.hpp"

class ICharacter
{
	public:
		virtual	~ICharacter() {}
		virtual std::string const	&getName(void) const = 0;
		virtual void	equip(AMateria *m) = 0;
		virtual void	unequip(int idx) = 0;
		virtual void	use(int idx, ICharacter &target) = 0;
};

#endif // **************************************************** __ICHARACTER_HPP__ //
