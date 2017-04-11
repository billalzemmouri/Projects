//
// Dict.cpp for  in /home/shark/rendu/piscine_de_synthese/autocompletion
// 
// Made by Shark
// Login   <zemmou_b@epitech.net>
// 
// Started on  Thu Jun 30 14:16:57 2016 Shark
// Last update Wed Jul  6 16:12:11 2016 Shark
//

# include"Dict.hh"

Dict::Dict()
{
}

Dict::~Dict()
{
}

std::string	Dict::getaddress()
{
  return this->address;
}

std::vector<std::string>	Dict::getcity()
{
  return this->city;
}

int				Dict::getnumber()
{
  return this->number;
}

std::string			Dict::getstreetType()
{
  return this->streetType;
}

std::vector<std::string>	Dict::getstreetName()
{
  return this->streetName;
}


void				Dict::setaddress(std::string _address)
{
  this->address = _address;
}

void				Dict::setcity(std::string _city)
{
  std::istringstream            iss(_city);
  std::string			mot;

  while(std::getline(iss, mot, ' '))
    {
      if (mot.find("'") != -1)
	mot.erase(mot.find("'"), 1);
      this->city.push_back(mot);
    }
}


void				Dict::setnumber(int _number)
{
  this->number = _number;
}

void				Dict::setstreetType(std::string _streetType)
{
  this->streetType = _streetType;
}

void				Dict::setstreetName(std::string _streetName)
{
  std::istringstream            iss(_streetName);
  std::string			mot;

 while(std::getline(iss, mot, ' '))
    {
      if (mot.find("'") != -1)
	mot.erase(mot.find("'"), 1);
      this->streetName.push_back(mot);
    }
}
