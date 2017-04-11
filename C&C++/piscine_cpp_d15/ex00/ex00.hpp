//
// ex00.hpp for  in /home/zemmou_b/rendu/piscine_cpp_d15/ex00
// 
// Made by Billal Zemmouri
// Login   <zemmou_b@epitech.net>
// 
// Started on  Wed Jan 20 09:59:59 2016 Billal Zemmouri
// Last update Wed Jan 20 13:35:44 2016 Billal Zemmouri
//
#ifndef EX00_H_
#define EX00_H_

template <typename T> void swap(T &A, T &B) 
{
  T tmp;
  tmp = A;
  A = B;
  B = tmp;
}

template <typename T> const T& min(T const& A, T const& B) 
{
  return A < B ? A : B;
}

template <typename T> const T& max(T const& A, T const& B) 
{
  return A > B ? A : B;
}

template <typename T>T add(T const& A, T const& B) 
{
  return A + B;
}

#endif /*EX00_H_*/
