//
// ex01.hpp for  in /home/zemmou_b/rendu/piscine_cpp_d15/ex01
// 
// Made by Billal Zemmouri
// Login   <zemmou_b@epitech.net>
// 
// Started on  Wed Jan 20 12:54:20 2016 Billal Zemmouri
// Last update Wed Jan 20 14:28:20 2016 Billal Zemmouri
//

#ifndef EX01_H_
#define EX01_H_

#include <string>
#include <cstring>
#include <iostream>

template <typename T> int compare( T const& A, T const& B)
{
  if (A == B)
    return 0;
  else if (A < B)
    return (-1);
  else 
    return (1);
}

#endif /*EX01_H_*/
