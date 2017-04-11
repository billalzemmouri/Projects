//
// main.cpp for  in /home/victor/rendu/abstractVM/src/parser
//
// Made by victor
// Login   <victor@epitech.net>
//
// Started on  Fri Jul 15 23:30:41 2016 victor
// Last update Mon Jul 18 14:10:32 2016 victor
//

#include "parser.hh"
#include "ErrorHandler.hh"
#include "../../include/Controller.h"

int	main(int ac, char **av)
{
  Parser	parsounet;
  Controller  contro;
 
    try
      {
	      if (ac == 1)
          parsounet.ParseByLineLoop();
        else if (ac > 1)
          parsounet.ParseByFile(av[1]);
        contro.setinstruction(parsounet.GetParsedList());
        contro._core();
	    }
    catch (ErrorHandler err)
      {
	     std::cerr << err.what() << std::endl;
	     exit (84);
      }

  return (0);
}
