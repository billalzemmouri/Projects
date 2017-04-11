//
// BigDecimal.hpp for  in /home/shark/rendu/piscine_de_synthese/abstractVM/BigDecimal/include
// 
// Made by Shark
// Login   <zemmou_b@epitech.net>
// 
// Started on  Sat Jul 16 18:38:33 2016 Shark
// Last update Wed Jul 20 11:51:03 2016 Shark
//

#ifndef BIGDECIMAL_H
#define BIGDECIMAL_H

#include <vector>
#include <iostream>
#include "IOperand.h"

class BigDecimal : public IOperand
{
public:
BigDecimal();
BigDecimal(std::string bigdecimal);
~BigDecimal();
void		setNumber(const std::string& xs);
void		setisPositive(bool _isPositive);
std::string	getNumberPos() const;
std::string	getNumber() const;
std::string	getInteger();
  std::string	getDecimal();
bool		getIsPositive();
void		display();
std::string   toString() const;
eOperandType  getType() const;
void          setvalue(void *);

//BigDecimal& operator =(BigDecimal other);
  IOperand *operator +(IOperand const &other) const;
  IOperand *operator -(IOperand const &other) const;
  IOperand *operator *(IOperand const &other) const;
  IOperand *operator /(IOperand const &other) const;
  IOperand *operator %(IOperand const &other) const;
private:
  std::string	integer;
  std::string	decimal;
  bool		isPositive;
};

int		countint(std::string s);
int		addpoint(std::string* s1, std::string* s2);
void		formatstring(std::string* s1, std::string* s2);
void		erasez(std::string *s);
std::string     add(std::string s1, std::string s2);
std::string     sub(std::string s1, std::string s2);
bool		compareBigDecimal(class BigDecimal b1, class BigDecimal b2);
std::string     multcal(std::string s1, char c);
std::string     multaddv(std::string result, std::string s1, std::string s2);
std::string     multaddz(std::string s1, int y);
std::string     multsum(std::vector<std::string> tabresult);
std::string     mult(std::string s1, std::string s2);
bool		compareString(std::string s1, std::string s2);
std::string     divaddz(std::string rest, std::string s1, int  y);
std::string	div(std::string s1, std::string s2);
#endif /* BIGDECIMAL_H */
