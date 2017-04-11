#include <list>
#include "../include/Instruction.h"

Instruction::Instruction()
{
	this->op = NULL;
}

Instruction::Instruction(std::string cmd, IOperand *op)
{
	if (op != NULL)
		this->op = op;
	else
		op = NULL;
	this->cmd = cmd;
	if (op != NULL)
		this->type = op->getType();
}

Instruction::~Instruction()
{

}

IOperand 		*Instruction::getop() const
{
	if (this->op == NULL)
		return (NULL);
	return (this->op);
}

eOperandType 	Instruction::gettype() const
{
	return (this->type);
}

std::string const	&Instruction::getcmd() const
{
	return (this->cmd);
}

void 			Instruction::setop(IOperand *new_op)
{
	this->op = new_op;
}

void 			Instruction::settype(eOperandType new_type)
{
	this->type = new_type;
}

void 			Instruction::setcmd(std::string str)
{
	this->cmd = str;
}
