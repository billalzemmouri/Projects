/*
** Parser.h for  in /home/zemmou_b/rendu/piscine_cpp_d16/ex00
** 
** Made by Billal Zemmouri
** Login   <zemmou_b@epitech.net>
** 
** Started on  Thu Jan 21 10:26:50 2016 Billal Zemmouri
** Last update Fri Jan 22 09:58:43 2016 Billal Zemmouri
*/

#ifndef PARSER_H_
#define PARSER_H_

#include<iostream>
#include <stack>

class Parser
{
public:
  Parser();
  ~Parser();
  void feed(const std::string &);
  void result();
  void reset()
 private:
  std::stack<char> pile_of;
  std::stack<int> pile_nf;
  int result;
};

#endif /*PARSER_H_*/
