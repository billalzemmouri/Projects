//
// Ratatouille.cpp for  in /home/zemmou_b/rendu/piscine_cpp_d16
// 
// Made by Billal Zemmouri
// Login   <zemmou_b@epitech.net>
// 
// Started on  Thu Jan 21 00:05:26 2016 Billal Zemmouri
// Last update Fri Jan 22 09:32:07 2016 Billal Zemmouri
//
#include"Ratatouille.h"

Ratatouille::Ratatouille() { }

Ratatouille::Ratatouille(const Ratatouille& source)
{
  flux = source.flux; 
}

Ratatouille::~Ratatouille() { }


Ratatouille&Ratatouille::operator=(const Ratatouille& source) 
{
  flux = source.flux;
  return *this;
}

Ratatouille&Ratatouille::addVegetable(unsigned char vegetable) 
{
  std::stringstreams;
  s << flux << vegetable;
  flux = s.str();
  return *this;
}

Ratatouille&Ratatouille::addCondiment(unsigned int condiment) 
{
  std::stringstreams;
  s << flux << condiment;
  flux = s.str();
  return *this;
}

Ratatouille&Ratatouille::addSpice(double spice) 
{
  std::stringstreams;
  s << flux << spice;
  flux = s.str();
  return *this;
}

Ratatouille&Ratatouille::addSauce(std::string const& sauce) 
{
  std::stringstreams;
  s << flux << sauce;
  flux = s.str();
  return *this;
}

std::stringRatatouille::kooc() 
{
  return flux; 
}
