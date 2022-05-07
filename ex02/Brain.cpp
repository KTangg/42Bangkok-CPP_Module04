#include "Brain.hpp"

// Default Class Constructor
Brain::Brain(void)
{
	for (int i = 0; i < 100; i++)
	{
		_idea[i] = "Brainless idea";
	}
	std::cout << "Look like you got some brain" << std::endl;
}

// Copy Class Constructor
Brain::Brain(const Brain &src)
{
	*this = src;
	std::cout << "Copy other brain isn't good" << std::endl;
}

// Class Deconstructor
Brain::~Brain(void)
{
	std::cout << "No more brain like you!!" << std::endl;
}

// Assign Operator Overload
Brain	&Brain::operator=(const Brain &rhs)
{
	std::cout << "Copy Brain" << std::endl;
	// Make your Assignment here
	for (int i = 0; i < 100; i++)
	{
		_idea[i] = rhs.getIdea(i);
	}
	return (*this);
}

std::string	Brain::getIdea(int i) const
{
	if (i >= 100 || i < 0)
		return ("");
	return (_idea[i]);
}

void	Brain::setIdea(int i, std::string idea)
{
	_idea[i] = idea;
}
