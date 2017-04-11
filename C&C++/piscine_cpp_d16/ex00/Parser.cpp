//
// Parser.cpp for  in /home/zemmou_b/rendu/piscine_cpp_d16/ex00
// 
// Made by Billal Zemmouri
// Login   <zemmou_b@epitech.net>
// 
// Started on  Thu Jan 21 10:29:12 2016 Billal Zemmouri
// Last update Fri Jan 22 09:57:41 2016 Billal Zemmouri
//

#include "Parser.h"
#include <stack> 
#include <stdlib.h>
Parser::Parser()
{
  this->result = 0;
}

Parser::~Parser()
{
}

void Parser::feed(const std::string &A)
{
  std::string cpy;
  int	i;
  int	res;
  std::stack<int> pile_n;
  std::stack<char> pile_o;
  
  i = 0;
  while (i < A.length())
    {
      if (A[i] != ' ')
	cpy += A[i];
      i += 1;
    }
  i = 0;
  std::cout << cpy << std::endl;
  while(i < cpy.length())
    {
      std::cout << i << std::endl;
      if (cpy[i] > 47 && cpy[i] < 58)
	{
	  pile_n.push(atoi(&(cpy[i])));
	  while (cpy[i] > 47 && cpy[i] < 58 && i <  cpy.length())
	    i = i + 1;
	}
      if(cpy[i] != '(' && cpy[i] != ')')  
	pile_o.push(cpy[i]);
      i = i + 1;
    }
  while(!pile_o.empty())
    {
      this->pile_of.push(pile_o.top());
      pile_o.pop();
    }
  while(!pile_n.empty())
    {
      this->pile_nf.push(pile_n.top());
      pile_n.pop();
    }
  res = this->pile_nf.top();
  this->pile_nf.pop();
  while(!this->pile_of.empty())
    {
      switch(pile_of.top())
	{
	case'+':
	  res += pile_nf.top();
	  break;
	case'-':
	  res -= pile_nf.top();
	  break;
	case'*':
	  res = res * pile_nf.top();
	  break;
	case'/':
	  res = res / pile_nf.top();
	  break;
	case'%':
	  res = res % pile_nf.top();
	  break;
	}
      this->pile_nf.pop();
      this->pile_of.pop();
    }  
  this->result += res;
  std::cout << "res = "  << res << std::endl;
  std::cout << "result = "  << this->result << std::endl;
}

int Parser::result() const 
{
  return this->result; 
}

void Parser::reset() 
{
  this->result = 0;
  while (!this->pile_nf.empty())
     this->pile_nf.pop();
  while (!this->pile_of.empty())
     this->pile_of.pop();
}

