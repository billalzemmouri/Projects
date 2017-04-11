#ifndef FIST_HH_
# define FIST_HH_
# include "Weapon.hpp"

class Fist : public Weapon
{
public:
  Fist(std::string const& name = "fist", unsigned int damages = 30);
  ~Fist();
  void 	shot();
};

#endif /* !FIST_HH_ */
