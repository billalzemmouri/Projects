/*
** FruitBox.h for  in /home/zemmou_b/rendu/piscine_cpp_d14m
** 
** Made by Billal Zemmouri
** Login   <zemmou_b@epitech.net>
** 
** Started on  Wed Jan 20 00:24:50 2016 Billal Zemmouri
** Last update Wed Jan 20 09:26:24 2016 Billal Zemmouri
*/


#ifndef FRUITBOX_H_
#define FRUITBOX_H_

#include "Fruit.h"
#include "FruitNode.h"

class FruitBox 
{
 public:
  FruitBox(int);
  ~FruitBox();
    
  int nbFruits() const;
  bool putFruit(Fruit* f);
  Fruit* pickFruit();
  FruitNode* head();
 private:
  int         m_size;
  int         m_nbrFruits;
  FruitNode   *m_list;
};

#endif /*FRUITBOX_H_*/
