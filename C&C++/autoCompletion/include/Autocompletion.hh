//
// autocompletion.hh for  in /home/shark/rendu/piscine_de_synthese/autocompletion
// 
// Made by Shark
// Login   <zemmou_b@epitech.net>
// 
// Started on  Thu Jun 30 13:50:32 2016 Shark
// Last update Wed Jul  6 23:06:14 2016 Shark
//

#ifndef AUTOCOMPLETION_HH_
#define AUTOCOMPLETION_HH_

#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <string.h>

#include "Dict.hh"

class Autocompletion
{
public:
  Autocompletion();
  ~Autocompletion();
  int				checkInDict(std::string s);
  int				Run();
  int				checkAuto();
  void				displayPossibilities();
  bool				updateDict(int  nchoice, std::vector<std::string> allchoices);
  bool				updateDict();
  bool				parsingDict(char* Dictionnary);
  bool				addDict(std::string adresse);
  bool				check(std::string s, Dict adresse);
  bool				validCity(std::string s);
  bool				validCity2(std::string s, Dict dict);
  bool				validStreetName2(std::string s);
  bool				validStreetName(std::string s, Dict dict);
  std::vector<std::string>      constructChoises();
  bool				checkCityDict();
  bool				checkStreetNameDict();
  bool				chooseCity();
  bool				chooseStreet();

private:
  bool				cityIsValid;
  std::vector<Dict>		dictionnary;
  std::vector<std::string>	dictErrorFormat;
  std::string			city;
  int				number;
  std::string			streetType;
  std::string			streetName;
  std::string			mot;
  std::vector<std::string>      result;
  std::vector<std::string>      allresult;
};
#endif /* AUTOCOMPLETION_HH_ */
