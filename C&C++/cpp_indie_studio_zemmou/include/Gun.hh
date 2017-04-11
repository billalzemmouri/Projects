#ifndef GUN_HH_
# define GUN_HH_
# include "Weapon.hpp"

class Gun : public Weapon
{
public:
	Gun(std::string const& name = "gun", unsigned int damages = 50);
	~Gun();
	void 	shot();
};

#endif /* !GUN_HH_ */