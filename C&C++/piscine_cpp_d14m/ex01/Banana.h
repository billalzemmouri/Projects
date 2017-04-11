/*
** Banana.h for  in /home/zemmou_b/rendu/piscine_cpp_d14m
** 
** Made by Billal Zemmouri
** Login   <zemmou_b@epitech.net>
** 
** Started on  Wed Jan 20 00:03:38 2016 Billal Zemmouri
** Last update Wed Jan 20 09:16:01 2016 Billal Zemmouri
*/


#ifndef BANANA_H_
#define BANANA_H__

#include "Fruit.h"

class Banana : public Fruit 
{
 public:
  Banana();
  ~Banana();
  virtual std::string getName() const;
  virtual int getVitamins() const;
};
#endif /* BANANA_H */
