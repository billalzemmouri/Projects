//
// main.cpp for  in /home/shark/rendu/piscine_de_synthese/autocompletion
// 
// Made by Shark
// Login   <zemmou_b@epitech.net>
// 
// Started on  Thu Jun 30 10:06:05 2016 Shark
// Last update Wed Jul  6 23:30:40 2016 Shark
//
#include "Autocompletion.hh"

void	help()
{
  std::cout << "USAGE" << std::endl;
  std::cout << "     ./autocompletion dictionnary" << std::endl;
  std::cout << "\nDESCRIPTION" << std::endl;
  std::cout << "     dictionnary   file, containing one address per line, serving as knowledge base" << std::endl;

}

int	autocompletion(char *dictionnary)
{
  int	ret;
  Autocompletion autocompletion;
  ret = 0;

  if (autocompletion.parsingDict(dictionnary) == false)
    return 84;
  return (autocompletion.Run());

}


int	main(int ac, char **av)
{
  if (ac == 2)
    {
      if(!strcmp(av[1], "-h"))
	help();
      else
	return autocompletion(av[1]);
    }
  else
    {
      std::cout << "Invalid argument" << std::endl;
      return 84;
    }
}
