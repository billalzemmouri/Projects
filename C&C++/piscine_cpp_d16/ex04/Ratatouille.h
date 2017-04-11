/*
** Ratatouille.h for  in /home/zemmou_b/rendu/piscine_cpp_d16
** 
** Made by Billal Zemmouri
** Login   <zemmou_b@epitech.net>
** 
** Started on  Thu Jan 21 0O:07:25 2016 Billal Zemmouri
// Last update Fri Jan 22 09:30:55 2016 Billal Zemmouri
*/

#ifndef RATATOUILLE_H_
#define RATATOUILLE_H_

#include <string>
#include <sstream>
#include <iostream>

class Ratatouille 
{
 protected:
  std::string flux;

 public:
  Ratatouille();
  Ratatouille(const Ratatouille&);
  virtual ~Ratatouille();
  Ratatouille &operator=(const Ratatouille&);

  Ratatouille& addVegetable(unsigned char);
  Ratatouille& addCondiment(unsigned int);
  Ratatouille& addSpice(double);
  Ratatouille& addSauce(const std::string &);
  std::string kooc();
};

#endif /*RATATOUILLE_H_*/
