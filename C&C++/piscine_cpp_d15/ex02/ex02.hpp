//
// ex02.hpp for  in /home/zemmou_b/rendu/piscine_cpp_d15/ex02
// 
// Made by Billal Zemmouri
// Login   <zemmou_b@epitech.net>
// 
// Started on  Wed Jan 20 14:26:43 2016 Billal Zemmouri
// Last update Wed Jan 20 18:25:19 2016 Billal Zemmouri
//

#ifndef EX02_H_
#define EX02_H_

#include <iostream>

template <typename T> T min( T const& A, T const& B)
{
  std::cout << "template min" << std::endl;
  if (A <=  B)
    return A;
  else
    return B;
}

int min(int A , int B)
{
  std::cout << "non-template min" << std::endl;
  if (A <=  B)
    return A;
  else
    return B;
}

template<typename T> int templateMin(T const& A, size_t const& B) 
{
unsigned  int	i;
  int	res;

  i = 1;
  res = A[0];
  while(i <  B)
    {
      res = min <int> (res,A[i]);
      i += 1;
    }
  return (res);
}

int  nonTemplateMin(int  *A, size_t  B) 
{
  unsigned  int	i;
  int	res;
  
  i = 1;
  res = A[0];
  while(i <  B)
    {
      res = min(res,A[i]);
      i += 1;
    }
  return (res);
}

#endif /*EX02_H_*/
