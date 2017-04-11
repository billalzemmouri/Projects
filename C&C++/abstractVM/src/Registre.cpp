#include "../include/Registre.h"

Registre::Registre()
{
	this->op = NULL;
}

Registre::~Registre()
{

}

IOperand 		*Registre::getop() const
{
	if (this->op == NULL)
		return (NULL);
	return (this->op);
}

void 			Registre::setop(IOperand *ope)
{
	this->op = ope;
}

