#ifndef WEAPON_HPP_
# define WEAPON_HPP_
# include <string>

class Weapon
{
public:
	virtual Weapon() {};
	virtual ~Weapon() {};
	virtual shot() = 0;

protected:
	std::string 	name;
	unsigned int 	damages;
};

#endif /* !WEAPON_HPP_ */