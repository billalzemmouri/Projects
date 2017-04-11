//
// dict.hh for  in /home/shark/rendu/piscine_de_synthese/autocompletion
// 
// Made by Shark
// Login   <zemmou_b@epitech.net>
// 
// Started on  Thu Jun 30 13:54:06 2016 Shark
// Last update Wed Jul  6 13:02:58 2016 Shark
//

#ifndef DICT_HH_
#define DICT_HH_

#include <iostream>
#include <vector>
#include <sstream>


class Dict
{
public:
  Dict();
  ~Dict();
  std::string			getaddress();
  std::vector<std::string>	getcity();
  int				getnumber();
  std::string			getstreetType();
  std::vector<std::string>	getstreetName();
  void				setaddress(std::string _address);
  void				setcity(std::string _city);
  void				setnumber(int _number);
  void				setstreetType(std::string _streetType);
  void				setstreetName(std::string _streetName);

private:
  std::string			address;
  std::vector<std::string>	city;
  int				number;
  std::string			streetType;
  std::vector<std::string>	streetName;
};
#endif /* DICT_HH_ */
