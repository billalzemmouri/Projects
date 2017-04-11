#ifndef FACTORY_H_
# define FACTORY_H_

#include "../include/IOperand.h"
#include "../include/OperandClasses.h"

class 		Factory
{

 	IOperand 	*createInt8(const std::string &value);
 	IOperand 	*createInt16(const std::string &value);
 	IOperand 	*createInt32(const std::string &value);
 	IOperand 	*createFloat(const std::string &value);
 	IOperand 	*createDouble(const std::string &value);
 	IOperand	*createBigDecimal(const std::string &value);
public:
	Factory();
	~Factory(){}
	static IOperand		*createOperand(eOperandType, const std::string &value);
};

#endif /* !FACTORY_H_ */