#ifndef __WRONGANIMAL_HPP__
# define __WRONGANIMAL_HPP__

# include <iostream>

class WrongAnimal
{
	public:
		// Default Class Constructor
		WrongAnimal(void);
		// Copy Class Constructor
		WrongAnimal(const WrongAnimal &src);
		// Class Deconstructor
		virtual	~WrongAnimal(void);

		// Assign operator overload
		WrongAnimal	&operator=(const WrongAnimal &rhs);

		// Getter function part
		std::string	getType(void) const;

		// Function member part
		void	makeSound(void) const;

	protected:
		std::string	type;

	private:
};

// outstream overload
std::ostream	&operator<<(std::ostream &out, const WrongAnimal &rhs);

#endif // **************************************************** __WRONGANIMAL_HPP__ //
