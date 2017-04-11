#ifndef CONTROLLER_H_
# define CONTROLLER_H_

#include <list>
#include <stack>
#include <map>
#include <vector>
#include "../include/Instruction.h"
#include "../include/Registre.h"


class 		Controller
{
	std::vector<Instruction*> instruction;
	std::stack<IOperand*> 	stack;
	std::map<std::string, Registre> regs;
	bool 					mexit;
public:
	Controller();
	~Controller();

	int 	_core();

	void 	operand_arg_functions(std::string const &, IOperand &);
	void 	push(IOperand *);
	void 	_assert(IOperand *);
	void 	load(IOperand *);
	void 	store(IOperand *);

	/* ----- */
	void 	no_arg_functions(std::string const &);
	void 	pop();
	void 	clear();
	void 	dup();
	void 	swap();
	void 	dump();
	void 	add();
	void	sub();
	void 	mul();
	void 	divi();
	void 	mod();
	void 	print();
	void 	_exit();

	std::vector<Instruction*> 	&getinstruction();
	void 						setinstruction(std::vector<Instruction *> const &);					
};

#endif /* !CONTROLLER_H_ */