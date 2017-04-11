/*
** Lemon.h for  in /home/zemmou_b/rendu/piscine_cpp_d14m/ex00
** 
** Made by Billal Zemmouri
** Login   <zemmou_b@epitech.net>
** 
** Started on  Wed Jan 20 00:15:39 2016 Billal Zemmouri
** Last update Wed Jan 20 09:35:35 2016 Billal Zemmouri
*/

#ifndef LEMON_H_
#define LEMON_H_

#include "Fruit.h"

class Lemon : public Fruit 
{
 public:
  Lemon();
  ~Lemon();
  
  virtual std::string getName() const;
  virtual int getVitamins() const;
};

#endif /*LEMON_H_*/
