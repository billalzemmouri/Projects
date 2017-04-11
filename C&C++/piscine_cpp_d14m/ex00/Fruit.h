/*
** Fruit.h for  in /home/zemmou_b/rendu/piscine_cpp_d14m
** 
** Made by Billal Zemmouri
** Login   <zemmou_b@epitech.net>
** 
** Started on  Wed Jan 20 00:11:12 2016 Billal Zemmouri
** Last update Wed Jan 20 09:20:15 2016 Billal Zemmouri
*/

#ifndef FRUIT_H_
#define FRUIT_H_

#include <string>

class Fruit 
{
 public:
  Fruit(int, std::string const&);
  ~Fruit();
   
  virtual int getVitamins() const = 0;
  virtual std::string getName() const = 0;
 protected:
  int _vitamins;
  std::string m_name;
};

#endif /*FRUIT_H_*/
