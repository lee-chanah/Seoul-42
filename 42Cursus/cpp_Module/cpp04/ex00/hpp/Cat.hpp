#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "./Animal.hpp"

using std::cout;
using std::endl;
using std::string;

class Cat :public Animal
{
private:
public:
	Cat();
	Cat(const Cat &cat);
	Cat &operator =(const Cat &cat);
	void makeSound() const;
	~Cat();
};
#endif