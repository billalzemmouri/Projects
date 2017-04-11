#ifndef INSTRUCTION_H_
# define INSTRUCTION_H_

#include "../include/IOperand.h"

class 				Instruction
{
	IOperand 		*op;
	eOperandType 	type;
	std::string  	cmd;
public:
	Instruction();
	Instruction(std::string, IOperand *op = NULL);
	~Instruction();

	IOperand 		*getop() const;
	eOperandType 	gettype() const;
	std::string const	&getcmd() const;
	void 			setop(IOperand *);
	void 			settype(eOperandType);
	void 			setcmd(std::string);
};

#endif /* !INSTRUCTION_H_ */