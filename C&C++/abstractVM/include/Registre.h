#ifndef REGISTRE_H_
# define REGISTRE_H_

#include "../include/IOperand.h"

class 			Registre
{
	IOperand 	*op;
public:
	Registre();
	~Registre();

	IOperand 	*getop() const;
	void 		setop(IOperand *);
};

#endif /* !REGISTRE_H_ */