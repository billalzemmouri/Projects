/*
** FruitNode.h for  in /home/zemmou_b/rendu/piscine_cpp_d14m/ex00
** 
** Made by Billal Zemmouri
** Login   <zemmou_b@epitech.net>
** 
** Started on  Wed Jan 20 00:07:56 2016 Billal Zemmouri
** Last update Wed Jan 20 09:32:22 2016 Billal Zemmouri
*/

#ifndef FRUITNODE_H
#define FRUITNODE_H

#include "Fruit.h"

typedef struct          s_FruitNode 
{
  Fruit               *fruit;
  struct s_FruitNode  *next;
}                       FruitNode;

#endif /*FRUITNODE_H*/
