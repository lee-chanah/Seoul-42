#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "./Animal.hpp"

using std::cout;
using std::endl;
using std::string;

class Dog :public Animal
{
private:
public:
	Dog();
	Dog(const Dog &dog);
	Dog &operator =(const Dog &dog);
	void makeSound() const;
	~Dog();
};
#endif