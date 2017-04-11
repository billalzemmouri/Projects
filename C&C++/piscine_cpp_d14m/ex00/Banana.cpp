//
// Banana.cpp for  in /home/zemmou_b/rendu/piscine_cpp_d14m
// 
// Made by Billal Zemmouri
// Login   <zemmou_b@epitech.net>
// 
// Started on  Wed Jan 20 00:02:04 2016 Billal Zemmouri
// Last update Wed Jan 20 09:13:31 2016 Billal Zemmouri
//

#include "Banana.h"

Banana::Banana() : Fruit(5, "banana") 
{
}

Banana::~Banana() {}

std::string Banana::getName() const 
{
return this->m_name;
}

int Banana::getVitamins() const 
{
return this->_vitamins;
}
