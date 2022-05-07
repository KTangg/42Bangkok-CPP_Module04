#ifndef __WRONGCAT_HPP__
# define __WRONGCAT_HPP__

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		// Default Class Constructor
		WrongCat(void);
		// Copy Class Constructor
		WrongCat(const WrongCat &src);
		// Class Deconstructor
		virtual	~WrongCat(void);

		// Assign operator overload
		WrongCat	&operator=(const WrongCat &rhs);

		// Function member part
		void	makeSound(void) const;

	private:
};

// outstream overload
std::ostream	&operator<<(std::ostream &out, const WrongCat &rhs);

#endif // **************************************************** __WRONGCAT_HPP__ //
