/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 22:53:10 by spoolpra          #+#    #+#             */
/*   Updated: 2022/05/08 23:15:07 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATERIASOURCE_HPP__
# define __MATERIASOURCE_HPP__

# define SOURCESIZE 4

# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		// Default Class Constructor
		MateriaSource(void);
		// Copy Class Constructor
		MateriaSource(MateriaSource const &src);
		// Class Deconstructor
		virtual	~MateriaSource(void);

		// Assign operator overload
		MateriaSource	&operator=(MateriaSource const &rhs);

		// Function member part
		void		learnMateria(AMateria *m);
		AMateria	*createMateria(std::string const &type);

	private:
		AMateria	*_source[SOURCESIZE];
};

#endif // **************************************************** __MATERIASOURCE_HPP__ //
