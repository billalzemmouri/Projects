#include "Gun.hh"

Gun::Gun(std::string const& name, unsigned int damages)
{
	this->name = name;
	this->damages = damages;
}

Gun::~Gun()
{

}

void 	Gun::shot()
{

}
