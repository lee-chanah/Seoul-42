#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

using std::cout;
using std::endl;
using std::string;

class Zombie
{
private:
	string name;
public:
	Zombie();
	~Zombie();
	Zombie(string name);
	void announce(void);
	void setName(string name);
};

Zombie* zombieHorde(int N, std::string name );

#endif