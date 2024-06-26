#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Default Brain Constructor called" << std::endl ;

    this->ideas = new std::string[100];
}

Brain::Brain(const Brain& copy)
{
    std::cout << "Copy Brain Constructor called" << std::endl ;

    *this = copy;
}

Brain &
Brain::operator =(const Brain &copy)
{
    if (this != &copy)
    {
        if (this->ideas)
            delete[] (this->ideas);
        ideas = new std::string[100];
        for (int i = 0; i < 100; i++)
            ideas[i] = copy.ideas[i];
    }    
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Default Brain Destructor called" << std::endl ;

    delete[] (this->ideas);
}
