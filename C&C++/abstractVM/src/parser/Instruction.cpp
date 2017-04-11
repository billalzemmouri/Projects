#include "../../include/Instruction.h"

Instruction::Instruction()
{

}

Instruction::Instruction(std::string cmd, IOperand *op)
{
  if (op)
    this->op = op;
  this->cmd = cmd;
  if (op)
    this->type = op->getType();
}

Instruction::~Instruction()
{

}

IOperand 		*Instruction::getop() const
{
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
