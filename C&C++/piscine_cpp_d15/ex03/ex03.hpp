//
// ex03.hpp for  in /home/zemmou_b/rendu/piscine_cpp_d15/ex03
// 
// Made by Billal Zemmouri
// Login   <zemmou_b@epitech.net>
// 
// Started on  Wed Jan 20 15:19:24 2016 Billal Zemmouri
// Last update Wed Jan 20 18:19:59 2016 Billal Zemmouri
//
#ifndef EX03_HPP_
#define EX03_HPP_

#include <iostream>

template <typename T> void print(T const& A)
{
  std::cout << A << std::endl;
}

template <typename T> void foreach( T const* A,void (*print)(const T &),size_t const B)
{
unsigned int i;

  i = 0;
  while(i < B)
    {
      print(A[i]);
      i = i + 1;
    }  
}

#endif /*EX03_HPP_*/
