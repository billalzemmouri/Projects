//
// BigDecimal.cpp for  in /home/shark/rendu/piscine_de_synthese/abstractVM/BigDecimal/src
// 
// Made by Shark
// Login   <zemmou_b@epitech.net>
// 
// Started on  Sat Jul 16 18:37:50 2016 Shark
// Last update Wed Jul 20 11:46:44 2016 Shark
//

#include "../include/BigDecimal.hpp"

BigDecimal::BigDecimal()
{
  integer = "0";
  decimal = "0";
  isPositive = true;
}

BigDecimal::BigDecimal(std::string s)
{
  size_t	i;

  integer = "0";
  decimal = "0";
  isPositive = true;
  i = 0; 
  if (s[0] == '-')
    {
      s.erase(0,1);
      isPositive = false;
    }
  while (i < s.length())
    {
      if (s[i] == '.')
	{
	  integer = s.substr(0, i);
	  decimal = s.substr(i + 1, (s.length()) - 1);
	}
      if (s.find('.') == std::string::npos)
	{
	  integer = s;
	  decimal = "0";
	}
      i = i + 1;
    }
}

BigDecimal::~BigDecimal()
{
}

void	BigDecimal::setNumber(const std::string& xs)
{
  std::string s;
  size_t	i;

  s = xs;
  i = 0; 
  if (s[0] == '-')
    {
      s.erase(0,1);
      isPositive = false;
    }
  while (i < s.length())
    {
      if (s[i] == '.')
	{
	  integer = s.substr(0, i);
	  decimal = s.substr(i + 1, (s.length()) - 1);
	}
      if (s.find('.') == std::string::npos)
	{
	  integer = s;
	  decimal = "0";
	}
      i = i + 1;
    }
}

void	BigDecimal::setisPositive(bool _isPositive)
{
  isPositive = _isPositive;
}

void	BigDecimal::display()
{
  std::cout << integer << "." << decimal << std::endl;
}

std::string   BigDecimal::getNumberPos() const
{
  std::string new_n;
  
  if (decimal == "0")
    return integer;
  else
    {
      new_n = integer + "." + decimal;
      return new_n;
    }
}

std::string   BigDecimal::getNumber() const
{
  std::string new_n;
  
  if (decimal == "0")
    {
      if (isPositive == false)
	new_n = "-" + integer;
      else
	new_n = integer;
      return new_n;
    }
  else
    {
      if (isPositive == false)
	new_n = "-" + integer + "." + decimal;
      else
	new_n = integer + "." + decimal;
      return new_n;
    }
}

std::string	BigDecimal::getInteger()
{
  return integer;
}

std::string	BigDecimal::getDecimal()
{
  return decimal;
}
bool	BigDecimal::getIsPositive()
{
  return isPositive;
}

std::string   BigDecimal::toString() const
{
  return (this->getNumber());
}

void          BigDecimal::setvalue(__attribute__((unused))void *data)
{

}

eOperandType  BigDecimal::getType() const
{
  return (eOperandType::BigDecimal);
}

IOperand   *BigDecimal::operator +(IOperand const &other) const
{
  BigDecimal first;
  BigDecimal second(other.toString());
  BigDecimal *resultB;
  std::string result;

  resultB = new class BigDecimal();
  first = *this;
  if ((first.getIsPositive() == true && second.getIsPositive() == false) || (first.getIsPositive() == false && second.getIsPositive() == true))
    {
      if (compareBigDecimal(first.getNumberPos(), second.getNumberPos()) == false)
	{
	  result = sub(first.getNumberPos(), second.getNumberPos());
	  if (first.getIsPositive() == false)
	    resultB->setisPositive(false);
	  else
	    resultB->setisPositive(true);
	  resultB->setNumber(result);
	}
      else
	{
	  result = sub(second.getNumberPos(), first.getNumberPos());
	  if (second.getIsPositive() == false)
	    resultB->setisPositive(false);
	  else
	    resultB->setisPositive(true);
	  resultB->setNumber(result);
	}
    }
  else if (first.getIsPositive() == false && second.getIsPositive() == false)
    {
      result = add(first.getNumberPos(), second.getNumberPos());
      resultB->setisPositive(false);
      resultB->setNumber(result);
    }
  else
    {
      result = add(first.getNumberPos(), second.getNumberPos());
      resultB->setisPositive(true);
      resultB->setNumber(result);
    }
  return resultB;
}

IOperand *BigDecimal::operator -(IOperand const &other) const
{
  BigDecimal first;
  BigDecimal second(other.toString());
  BigDecimal* resultB;
  std::string result;

  first = *this;
  resultB = new class BigDecimal; 
  if ((first.getIsPositive() == true && second.getIsPositive() == false) || (first.getIsPositive() == false && second.getIsPositive() == true))
    {
      result = add(first.getNumberPos(), second.getNumberPos());
      if (first.getIsPositive() == true && second.getIsPositive() == false)
	resultB->setisPositive(true);
      else
	resultB->setisPositive(false);
      resultB->setNumber(result);
    }
  else if (first.getIsPositive() == false && second.getIsPositive() == false)
    {
       if (compareBigDecimal(first.getNumberPos(), second.getNumberPos()) == false)
	{
	  result = sub(first.getNumberPos(), second.getNumberPos());
	  resultB->setisPositive(false);
	  resultB->setNumber(result);
	}
      else
	{
	  result = sub(second.getNumberPos(), first.getNumberPos());
	  resultB->setisPositive(true);
	  resultB->setNumber(result);
	}
    }
    else
      {
       if (compareBigDecimal(first.getNumberPos(), second.getNumberPos()) == false)
	{
	  result = sub(first.getNumberPos(), second.getNumberPos());
	  resultB->setisPositive(true);
	  resultB->setNumber(result);
	}
       else
	 {
	   result = sub(second.getNumberPos(), first.getNumberPos());
	   resultB->setisPositive(false);
	   resultB->setNumber(result);
	}
      }
  return resultB;
}

IOperand *BigDecimal::operator*(IOperand const &other) const
{
  BigDecimal first;
  BigDecimal second(other.toString());
  BigDecimal* resultB;
  std::string result;
  std::string err = "NON";

  throw ErrorHandler(err, new int(259));
  first = *this;
  resultB = new class BigDecimal; 
  if ((first.getIsPositive() == true && second.getIsPositive() == false) || (first.getIsPositive() == false && second.getIsPositive() == true))
    {
      resultB->setNumber(mult(first.getNumberPos(), second.getNumberPos()));
      resultB->setisPositive(false);
    }
  else
    {
      resultB->setNumber(mult(first.getNumberPos(), second.getNumberPos()));
      resultB->setisPositive(true);
    }
  return resultB;
}

IOperand  *BigDecimal::operator/(IOperand const &other) const
{
  BigDecimal first;
  BigDecimal second(other.toString());
  BigDecimal* resultB;
  std::string result;
  std::string err = "NON";

  throw ErrorHandler(err, new int(283));
  first = *this;
  resultB = new class BigDecimal; 
  if ((first.getIsPositive() == true && second.getIsPositive() == false) || (first.getIsPositive() == false && second.getIsPositive() == true))
    {
      resultB->setNumber(div(first.getNumberPos(), second.getNumberPos()));
      resultB->setisPositive(false);
    }
  else
    {
      resultB->setNumber(div(first.getNumberPos(), second.getNumberPos()));
      resultB->setisPositive(true);
    }
  return resultB;

}

IOperand  *BigDecimal::operator%(__attribute__((unused))IOperand const &other) const
{
  std::string   err = "Dividing with BD is not good";
  throw ErrorHandler(err, new int(284));
  return (NULL);
}
