//
// Lemon.cpp for  in /home/zemmou_b/rendu/piscine_cpp_d14m/ex00
// 
// Made by Billal Zemmouri
// Login   <zemmou_b@epitech.net>
// 
// Started on  Wed Jan 20 00:12:21 2016 Billal Zemmouri
// Last update Wed Jan 20 09:33:45 2016 Billal Zemmouri
//


#include "Lemon.h"

Lemon::Lemon() : Fruit(3, "lemon") {}

Lemon::~Lemon() {}

std::string Lemon::getName() const 
{
return this->m_name; 
}

int Lemon::getVitamins() const 
{
return this->_vitamins; 
}
