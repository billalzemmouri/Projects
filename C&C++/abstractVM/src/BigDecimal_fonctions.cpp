//
// BigDecimal_fonctions.cpp for  in /home/shark/rendu/piscine_de_synthese/abstractVM
// 
// Made by Shark
// Login   <zemmou_b@epitech.net>
// 
// Started on  Tue Jul 19 11:07:12 2016 Shark
// Last update Wed Jul 20 19:17:48 2016 Shark
//
#include "../include/BigDecimal.hpp"

int     countint(std::string s)
{
  if (s.find(".") == std::string::npos)
    return s.size();
  else
    return (s.find("."));
}

int     addpoint(std::string* s1, std::string* s2)
{
  if (s2->find(".") == std::string::npos && s1->find(".") != std::string::npos)
    s2->insert(s2->size(), ".");
  if (s1->find(".") == std::string::npos && s2->find(".") != std::string::npos)
    s1->insert(s1->size(), ".");
  if (s1->find(".") == std::string::npos && s2->find(".") == std::string::npos)
    return - 1;
  return 0;
}

void    formatstring(std::string* s1, std::string* s2)
{
  int   i;
  int   n;

  i = 0;
  if (countint(*s1) > countint(*s2))
    {
      n = countint(*s1) - countint(*s2);
      while (i < n)
        {
          s2->insert(0, "0");
          i = i + 1;
        }
    }
  else
    {
      n = countint(*s2) - countint(*s1);
      while (i < n)
        {
          s1->insert(0, "0");
          i = i + 1;
        }
    }
  if (addpoint(s1, s2) != -1)
    {
      if ((s1->size() - s1->find(".")) > (s2->size() - s2->find(".")))
        {
          i = (s1->size() - s1->find(".")) - (s2->size() - s2->find("."));
          while (i > 0)
            {
              s2->insert(s2->size(), "0");
	      i = i - 1;
            }
        }
      else
        {
          i = (s2->size() - s2->find(".")) - (s1->size() - s1->find("."));
          while (i > 0)
            {
              s1->insert(s1->size(), "0");
              i = i - 1;
            }
        }
    }
}

void    erasez(std::string *s)
{
  if (s->find(".") == std::string::npos)
    {
      while ((*s)[0] == '0' && s->size() > 1)
        {
          s->erase(0, 1);
        }
    }
  else
    {
      while ((*s)[0] == '0' && s->find(".") > 1)
        s->erase(0, 1);
      while ((*s)[s->size() - 1] == '0')
        s->erase(s->size() - 1, s->size());
      if ((*s)[s->size() - 1] == '.')
        s->erase(s->size() - 1, s->size());
    }
}

std::string     add(std::string s1, std::string s2)
{
  int   i;
  int   ret;
  std::string result;
  std::string tmp;

  i = 0;
  ret = 0;
  formatstring(&s1, &s2);
  i = s1.size() - 1;
  while (i >= 0)
    {
      if (s2[i] == '.')
        result.insert(0,".");
      else if ((s1[i] + s2[i] + ret - 48) > '9')
        {
          tmp = (s1[i] + s2[i] + ret - 96) % 10 + 48;
          result.insert(0,tmp);
          ret = (s1[i] + s2[i] + ret - 96) / 10;
        }
      else
        {
          if (s1[i] != 0 && s1[i] != 0)
            tmp = (s1[i] + s2[i] - 96 + ret) + 48;
	  result.insert(0,tmp);   
          ret = 0;
        }
      i = i - 1;
      if (ret != 0 && i < 0)
	{
	  tmp = std::to_string(ret);
	  result.insert(0,tmp);   
	}
    }
  erasez(&result);
  return result;
}

std::string     sub(std::string s1, std::string s2)
{
  int   i;
  int   ret;
  std::string result;
  std::string tmp;

  i = 0;
  ret = 0;

  if (compareString(s1, s2) ==  true)
    return "-";
  formatstring(&s1, &s2);
  i = s1.size() - 1;
  while (i >= 0)
    {
      if (s2[i] == '.')
        result.insert(0,".");
      else if ((s1[i] - s2[i] - ret + 48) < '0')
        {
          tmp = s1[i] - s2[i] - ret + 10 + 48;
          result.insert(0,tmp);
          ret = 1;
        }
      else
        {
          if (s1[i] != 0 && s1[i] != 0)
            tmp = (s1[i] - s2[i] - ret) + 48;
          result.insert(0,tmp);
          ret = 0;
        }
      i = i - 1;
      if (ret != 0 && i < 0)
	{
	  tmp = std::to_string(ret);
	  result.insert(0,tmp);   
	}
    }
  erasez(&result);
  return result;
}

bool    compareBigDecimal(class BigDecimal b1, class BigDecimal b2)
{
  size_t        i;

  i = 0;
  if (b1.getInteger().size() > b2.getInteger().size())
    return false;
  else if (b1.getInteger().size() < b2.getInteger().size())
    return true;
  else
    {
      while (b1.getInteger()[i] == b2.getInteger()[i] && i < b2.getInteger().size())
        i = i + 1;
      if (b1.getInteger()[i] > b2.getInteger()[i])
        return false;
      else if (b1.getInteger()[i] < b2.getInteger()[i])
        return true;
      else
        {
          i = 0;
          if (b1.getDecimal().size() > b2.getDecimal().size())
            return false;
          else if (b1.getDecimal().size() < b2.getDecimal().size())
            return true;
          else
            {
              while (b1.getDecimal()[i] == b2.getDecimal()[i] && i < b2.getDecimal().size())
                i = i + 1;
              if (b1.getDecimal()[i] > b2.getDecimal()[i])
                return false;
              else if (b1.getDecimal()[i] < b2.getDecimal()[i])
                return true;
            }
        }
    }
  return false;
}


std::string     multcal(std::string s1, char c)
{
  int   i;
  int   ret;
  std::string result;
  std::string tmp;

  ret = 0;
  i = s1.size() - 1;
  while (i >= 0 || ret != 0)
    {
      if (s1[i] == '.')
	i = i - 1;
      if (((s1[i] - 48) * (c - 48) + ret) > 9)
        {
          tmp = ((s1[i] - 48) * (c - 48) + ret) % 10 + 48;
          result.insert(0, tmp);
          ret = ((s1[i] - 48) * (c - 48) + ret) / 10;
        }
      else
        {
          if (i >= 0)
            tmp = (s1[i] - 48) * (c - 48) + ret + 48;
          else
            tmp = ret + 48;
          result.insert(0, tmp);
          ret = 0;
        }
      i = i - 1;
    }
  return result;
}

std::string     multaddv(std::string result, std::string s1, std::string s2)
{
  int   a;
  int   b;
  int   c;
 
  (s1.find(".") == std::string::npos) ? (a = 0) : (a = s1.size() - s1.find(".") - 1);
  (s2.find(".") == std::string::npos) ? (b = 0) : (b = s2.size() - s2.find(".") - 1);
  c = a + b;
  
  if ( c > 0)
    result.insert(result.size() - c,".");
  return result;
}

std::string	multaddz(std::string s1, int y)
{
  int   i;

  i = 0;
  while (i < y)
    {
      s1 = s1 + "0";
      i = i + 1;
    }
  return s1;
}

std::string	multsum(std::vector<std::string> tabresult)
{
  size_t   i;
  std::string result;

  i = 0;
  result = "0";
  while (tabresult.size() > i)
    {
      result = add(result,tabresult[i]);
      i = i + 1;
    }
  return result;
}

std::string     mult(std::string s1, std::string s2)
{
  std::vector<std::string> tabresult;
  std::string result;
  std::string resultf;
  int   i;
  int   y;

  y = 0;
  i =  s2.size() -1;
  while (i >= 0)
    {
      if (s2[i] == '.')
	i = i - 1;
      tabresult.push_back(multaddz(multcal(s1,s2[i]), y));
      y = y + 1;
      i = i - 1;
    }
  resultf = multaddv(multsum(tabresult), s1, s2);
  erasez(&resultf);
  return (resultf);
}

bool    compareString(std::string s1, std::string s2)
{
  class BigDecimal    b1(s1);
  class BigDecimal    b2(s2);

  return (compareBigDecimal(b1, b2));
}

std::string     divaddz(std::string rest, std::string s1, int  y)
{
  size_t   i;

  i = y;
  while (i < s1.size())
    {
      if (s1[i] != '.')
        rest = rest + "0";
      else
        rest = rest + ".";
      i = i + 1;
    }
  erasez(&rest);
  return rest;
}

std::string	div(std::string s1, std::string s2)
{
  std::string   result;
  std::string   tmp;
  std::string   tmp1;
  std::string   rest;
  bool          v;
  int           i;
  int           y;
  int           p;
  size_t        z;

  while (s1.find(".") != std::string::npos || s2.find(".") != std::string::npos)
    {
      s1 = mult(s1, "10");
      s2 = mult(s2, "10");
      erasez(&s1);
      erasez(&s2);
    }
  (s2.find(".") == std::string::npos) ? (y = s2.size()) : (y = s2.find("."));
  z = s2.size();
  rest = s1;
  result = "0";
  v  = false;
  p = 0;
  while ((rest !=  "0" || z <= s1.size()) && p < 100)
    {
      i = 0;
      tmp1 = rest.substr(0, y);
      while (sub(tmp1, s2) != "-")
        {
          tmp1 = sub(tmp1, s2);
          i = i + 1;
        }
      tmp = std::to_string(i);
      rest = sub(rest, divaddz(mult(s2,tmp), s1, z));
      if(z > (s1.size()) && rest != "0")
        rest = mult(rest, "10");
      if (tmp == "0")
        y = y + 1;
      else if (z > s1.size() )
        y = rest.size();
      else
        y = y + 1;
      if(z >= (s1.size()) + 1 && rest != "0" && v == false)
        {
          result.insert(result.size(),".");
          v = true;
        }
      else
        result = result + tmp;
      (result.find(".") == std::string::npos) ? ( p = 0) :
        (p = result.size() - result.find("."));
      z = z + 1;
    }
  erasez(&result);
  return result;
}
