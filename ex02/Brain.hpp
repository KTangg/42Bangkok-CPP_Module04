#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

# include <iostream>

class Brain
{
	public:
		// Default Class Constructor
		Brain(void);
		// Copy Class Constructor
		Brain(const Brain &src);
		// Class Deconstructor
		virtual	~Brain(void);

		// Assign operator overload
		Brain	&operator=(const Brain &rhs);

		// Getter function part
		std::string	getIdea(int i) const;

		// Setter funcion part
		void	setIdea(int i, std::string idea);

		// Function member part

	private:
		std::string	_idea[100];
};

#endif // **************************************************** __BRAIN_HPP__ //
