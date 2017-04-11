
#include <iostream>
#include "../include/Controller.h"

Controller::Controller()
{
	this->mexit = false;
}

Controller::~Controller()
{
}

void 		Controller::pop()
{
	std::string 	err = "Stack is empty";
	if (this->stack.empty() == true)
		throw ErrorHandler(err, new int(17));
	this->stack.pop();
}

void 		Controller::clear()
{
	while (this->stack.size() != 0)
		this->stack.pop();
}

void 		Controller::dup()
{
	IOperand 	*duplicate;
	std::string  err = "Stack is empty";

	if (this->stack.empty() == true)
		throw ErrorHandler(err, new int(34));
	duplicate = this->stack.top();
	this->stack.push(duplicate);
}

void 		Controller::swap()
{
	IOperand *first;
	IOperand *second;
	std::string err = "Less than 2 instructions in the stack";

	if (this->stack.size() < 2)
		throw ErrorHandler(err, new int(41));
	first = this->stack.top();
	this->stack.pop();
	second = this->stack.top();
	this->stack.pop();
	this->stack.push(first);
	this->stack.push(second);
}

void 		Controller::dump()
{
	std::stack<IOperand*> tmp;

	tmp = this->stack;
	while (tmp.size() != 0)
	{
		std::cout << tmp.top()->toString() << std::endl;
		tmp.pop();
	}
}

void 		Controller::add()
{
	IOperand 	*res;
	IOperand 	*first;
	IOperand 	*second;
	std::string  err = "Less than 2 instructions in the stack";

	if (this->stack.size() < 2)
		throw ErrorHandler(err, new int(69));
	first = this->stack.top();
	this->stack.pop();
	second = this->stack.top();
	this->stack.pop();
	res = *first + *second;
	this->stack.push(res);
}

void 		Controller::sub()
{
	IOperand 	*res;
	IOperand 	*first;
	IOperand 	*second;
	std::string err;

	err = "Less than 2 instructions in the stack";
	if (this->stack.size() < 2)
		throw ErrorHandler(err, new int(85));
	first = this->stack.top();
	this->stack.pop();
	second = this->stack.top();
	this->stack.pop();
	res = *second - *first;
	this->stack.push(res);
}

void 		Controller::mul()
{
	IOperand 	*res;
	IOperand 	*first;
	IOperand 	*second;
	std::string err;

	err = "Less than 2 instructions in the stack";
	if (this->stack.size() < 2)
		throw ErrorHandler(err, new int(101));
	first = this->stack.top();
	this->stack.pop();
	second = this->stack.top();
	this->stack.pop();
	res = *first * *second;
	this->stack.push(res);
}

void 		Controller::divi()
{
	IOperand 	*res;
	IOperand 	*first;
	IOperand 	*second;
	std::string err;

	err = "Less than 2 instructions in the stack";
	if (this->stack.size() < 2)
		throw ErrorHandler(err, new int(117));
	first = this->stack.top();
	this->stack.pop();
	second = this->stack.top();
	this->stack.pop();
	res = *second / *first;
	this->stack.push(res);
}

void 		Controller::mod()
{
	IOperand 	*res;
	IOperand 	*first;
	IOperand 	*second;
	std::string err;

	err = "Less than 2 instructions in the stack";
	if (this->stack.size() < 2)
		throw ErrorHandler(err, new int(133));
	first = this->stack.top();
	this->stack.pop();
	second = this->stack.top();
	this->stack.pop();
	res = *second % *first;
	this->stack.push(res);
}

void 		Controller::print()
{
	std::string 	err;

	if (this->stack.empty() == true)
	{
		err = "Stack is empty";
		throw ErrorHandler(err, new int(160));
	}
	err = "Value is not a int8. Throw exception";
	if (this->stack.top()->getType() == eOperandType::Int8)
		std::cout << static_cast<char>(std::stoi(this->stack.top()->toString())) << std::endl;
	else
		throw ErrorHandler(err, new int(147));
}

void 		Controller::_exit()
{
	this->mexit = true;
	exit(0);
}

void 		Controller::push(IOperand *op)
{
	this->stack.push(op);
}

int 		Controller::_core()
{
	std::vector<Instruction*>::iterator it = this->instruction.begin();

	while (it != this->instruction.end())
	{
		if ((*it)->getop() != NULL)
		{
				this->operand_arg_functions((*it)->getcmd(), *((*it)->getop()));
		}
		else
		{
				this->no_arg_functions((*it)->getcmd());
		}
		++it;
	}
	if (this->mexit == false)
	{
		std::string err = "You must exit the VM";
		throw ErrorHandler(err, new int(210));
	}
	return (0);
}

void 		Controller::_assert(IOperand *op)
{
	std::string 	err;

	err = "Assert has failed";
	if (this->stack.empty() == true)
		throw ErrorHandler(err, new int(226));
	if (op->getType() >= this->stack.top()->getType())
	{
		switch (static_cast<int>(op->getType()))
		{
			case eOperandType::Int8:
				if (static_cast<int8_t>(std::stoi(this->stack.top()->toString())) != static_cast<int8_t>(std::stoi(op->toString())))
					throw ErrorHandler(err, new int(213));
				break;
			case eOperandType::Int16:
				if (static_cast<int16_t>(std::stoi(this->stack.top()->toString())) != static_cast<int16_t>(std::stoi(op->toString())))
					throw ErrorHandler(err, new int(216));
				break;
			case eOperandType::Int32:
				if (static_cast<int32_t>(std::stoi(this->stack.top()->toString())) != static_cast<int32_t>(std::stoi(op->toString())))
					throw ErrorHandler(err, new int(220));
				break;
			case eOperandType::Float:
				if (static_cast<float>(std::stof(this->stack.top()->toString())) != static_cast<float>(std::stof(op->toString())))
					throw ErrorHandler(err, new int(224));
				break;
			case eOperandType::Double:
				if (static_cast<double>(std::stod(this->stack.top()->toString())) != static_cast<double>(std::stod(op->toString())))
					throw ErrorHandler(err, new int (228));
				break;
		}
	}
	else
	{
		switch (static_cast<int>(this->stack.top()->getType()))
		{
			case eOperandType::Int16:
				if (static_cast<int16_t>(std::stoi(this->stack.top()->toString())) != static_cast<int16_t>(std::stoi(op->toString())))
					throw ErrorHandler(err, new int(238));
				break;
			case eOperandType::Int32:
				if (static_cast<int32_t>(std::stoi(this->stack.top()->toString())) != static_cast<int32_t>(std::stoi(op->toString())))
					throw ErrorHandler(err, new int(242));
				break;
			case eOperandType::Float:
				if (static_cast<float>(std::stof(this->stack.top()->toString())) != static_cast<float>(std::stof(op->toString())))
					throw ErrorHandler(err, new int (246));
				break;
			case eOperandType::Double:
				if (static_cast<double>(std::stod(this->stack.top()->toString())) != static_cast<double>(std::stod(op->toString())))
					throw ErrorHandler(err, new int(250));
				break;
		}
	}
}

void 		Controller::operand_arg_functions(std::string const &cmd, IOperand &op)
{
	static std::vector<void (Controller::*)(IOperand *)> funcs = {&Controller::push, &Controller::_assert, &Controller::load, &Controller::store};
	static std::vector<std::string> cmd_array = {"push", "assert", "load", "store"};
	std::string 	err = "Unknown command";
	int 	index = 0;

	while (index < static_cast<int>(cmd_array.size()))
	{
		if (cmd == cmd_array[index])
		{
			(this->*funcs[index])(&op);
			return ;
		}
		++index;
	}
	throw ErrorHandler(err, new int(272));
}

void 		Controller::load(IOperand *reg)
{
	std::string 	err;

	err = "Load command failed";
	if (this->regs[reg->toString()].getop() == NULL)
		throw ErrorHandler(err, new int(291));
	this->stack.push(this->regs[reg->toString()].getop());
	this->regs[reg->toString()].setop(NULL);
}

void 		Controller::store(IOperand *reg)
{
	std::string err = "Store command failed";
	if (this->stack.empty() == true)
		throw ErrorHandler(err, new int (304));
	if (std::stoi(reg->toString()) >= 16)
		throw ErrorHandler(err, new int(298));
	this->regs[reg->toString()].setop(this->stack.top());
	this->stack.pop();
}

void 		Controller::no_arg_functions(std::string const &cmd)
{
	static std::vector<void (Controller::*)()> funcs = {&Controller::pop, &Controller::clear, &Controller::dup, &Controller::swap, &Controller::dump, &Controller::add, &Controller::sub, &Controller::mul, &Controller::divi, &Controller::mod, &Controller::print, &Controller::_exit};
	static std::vector<std::string> cmd_array = {"pop", "clear", "dup", "swap", "dump", "add", "sub", "mul", "div", "mod", "print", "exit"};
	int 	index = 0;
	std::string 	err = "Unknown command";

	while (index < static_cast<int>(cmd_array.size()))
	{
		if (cmd == cmd_array[index])
		{
			(this->*funcs[index])();
			return ;
		}
		++index;
	}
	throw ErrorHandler(err, new int(320));
}

std::vector<Instruction*> 	&Controller::getinstruction()
{
	return (this->instruction);
}

void 					Controller::setinstruction(std::vector<Instruction*> const &victor)
{
	this->instruction = victor;
}
