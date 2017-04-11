#include <iostream> 
#include "../include/IOperand.h"
#include "../include/Factory.h"
#include "../include/Controller.h"

int		main(int ac, __attribute__((unused))char **av)
{
  Factory     construct;
	Controller 	contro;
	
  //contro.getinstruction().push_back(Instruction("push", construct.createOperand(Int8, "98")));
  //contro.getinstruction().push_back(Instruction("assert", construct.createOperand(Double, "98.001")));
  //contro.getinstruction().push_back(Instruction("push", construct.createOperand(Float, "54.87")));
  //contro.getinstruction().push_back(Instruction("add", NULL));
  //contro.getinstruction().push_back(Instruction("store 5", NULL));
  //contro.getinstruction().push_back(Instruction("load 6", NULL));
  //contro.getinstruction().push_back(Instruction("dump", NULL));
  //std::cout << contro.getinstruction().size() << std::endl;
  //contro._core();
  
  if (ac > 2)
  {
  	std::cerr << "Usage ./abstractVM [file]" << std::endl;
  	exit (84);
  }
  return (0);
}
