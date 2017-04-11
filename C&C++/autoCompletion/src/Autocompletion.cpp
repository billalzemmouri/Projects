//
// Autocompletion.cpp for  in /home/shark/rendu/piscine_de_synthese/autocompletion
// 
// Made by Shark
// Login   <zemmou_b@epitech.net>
// 
// Started on  Fri Jul  1 19:31:14 2016 Shark
// Last update Wed Jul  6 23:33:36 2016 Shark
//

#include "Autocompletion.hh"
#include <sstream> 
#include <algorithm>
#include <cstdio>

Autocompletion::Autocompletion()
{
  cityIsValid = false;
  number = 0;
}

Autocompletion::~Autocompletion()
{
}

std::string Supprime_espace(const std::string & Str, char c) 
{  
  return Str.substr(Str.find_first_not_of(c));
}  

bool	Autocompletion::addDict(std::string address)
{
  Dict				newDict;
  std::istringstream		iss(address); 
  std::istringstream		iss2;
  std::string			city;
  std::string			streetType;
  std::string			streetName;
  std::string			tmp;
  int				number;
  
  if(address.find(',') == -1)
    return false;
  std::getline(iss, tmp, ',');
  city = tmp;
  std::getline(iss, tmp, ',');
  iss2.str(Supprime_espace(tmp,' '));
  iss2 >> number;
  if(number == 0)
    return false;
  iss2.str(iss2.str().substr(iss2.str().find(' ') + 1));
  std::getline(iss2, tmp, ' ');
  streetType = tmp;
  streetName = iss2.str().substr(iss2.str().find(' ') + 1);
  newDict.setaddress(address);
  newDict.setcity(city);
  newDict.setnumber(number);
  newDict.setstreetType(streetType);
  newDict.setstreetName(streetName);
  dictionnary.push_back(newDict);
  return true;
}

bool	Autocompletion::parsingDict(char *Dictionnary)
{
  std::ifstream	FileDict(Dictionnary);
  std::string	adresse;
  char		c;
  int		i;
 
  if(FileDict)
    {
      getline(FileDict, adresse);
      if(FileDict.eof())
	{
	  std::cerr << "Invalid argument" << std::endl;
	  return false;
	}
      if(addDict(adresse) == false)
	dictErrorFormat.push_back(adresse);
      while(getline(FileDict, adresse))
	{
	  if(addDict(adresse) == false)
	    {
	      std::cerr << adresse << std::endl;
	      dictErrorFormat.push_back(adresse);
	    }
	}
      FileDict.close();
    }
  else
    {    
      std::cerr << "Invalid argument" << std::endl;
      return false;
    }
  return true;
}

int	checkDoublon(std::string str, std::vector<std::string>  result)
{
  int	i;
  int	doublon;

  i = 0;
  doublon = 0;
  while (i < result.size())
    {
      if (str == result[i])
	doublon = doublon + 1;
      i = i + 1;
    }
  return doublon;
}

bool	checkVector(std::vector<std::string> v1, std::vector<std::string> v2)
{
  int	i;
  
  i = 0;
  if (v1.size() != v2.size())
    return false;
  while (i < v1.size())
    {
      if (v1[i] != v2[i])
	return false;
      i = i = 1;
    }
  return true;
}

bool	Autocompletion::checkCityDict()
{
  int	i;

  i = 0;
  while(i < dictionnary.size() -1)
    {
      if (checkVector(dictionnary[i].getcity(), dictionnary[i + 1].getcity()) == false)
	return	false;
      i = i + 1;
    }
  return true;
}

void	Autocompletion::displayPossibilities()
{
  int				i;
  int				y;
  std::string			tmp;
  std::vector<std::string>	tri;
  
  i = 0;
  std::sort(result.begin(), result.end());
  tri.push_back(result[0]);
  while(i < result.size())
    {
      y = 0;
      while(checkDoublon(result[i], allresult) <= checkDoublon(tri[y], allresult) && y < tri.size() - 1)
	y = y + 1;
      tri.insert(tri.begin() + y, result[i]);
      i = i + 1;
    }
  tri.pop_back();
  i = 0;
  if(cityIsValid == false)
    {
      while (i < tri.size() && i < 5)
	{
	  tmp = tri[i];
	  std::transform(tmp.begin(), tmp.end() - 1, tmp.begin(), toupper);
	  std::cout << "{" << tmp << "}";
	  if (i < tri.size() - 1 && i < 4)
	    std::cout << " ";
	  else
	    std::cout << std::endl;
	  i = i + 1;
	}
    }
  else
    {
      while (i < tri.size() && i < 5)
  	{
  	  tmp = tri[i];
  	  std::transform(tmp.begin(), tmp.end() - 1, tmp.begin(), toupper);
  	  std::cout << "{" << city << ", " << tmp << "}";
  	  if (i < tri.size() - 1 && i < 4)
  	    std::cout << " ";
  	  else
  	    std::cout << std::endl;
  	  i = i + 1;
  	}
    } 
}


bool	Autocompletion::check(std::string s, Dict adresse)
{
  int				y;
  bool				add;  
  std::string			s2;  
  std::string			tmp;

  y = 0;
  add = false;

  tmp = s;
  std::transform(tmp.begin(), tmp.end(), tmp.begin(), tolower);
  if (cityIsValid == false)
    {
      while (y < adresse.getcity().size())
	{
	  s2 = adresse.getcity()[y];
	  std::transform(s2.begin(), s2.end(), s2.begin(), tolower);
	  if(s2.substr(0, s.size()) == s)
	    {
	      if (checkDoublon(s2.substr(0, s.size() + 1), result) == false)
		result.push_back(s2.substr(0, s.size() + 1));
	      allresult.push_back(s2.substr(0, s.size() + 1));
	      add = true;
	    }
	  y = y + 1;
	}
    }
  else
    {
      while (y < adresse.getstreetName().size())
	{
	  s2 = adresse.getstreetName()[y];
	  std::transform(s2.begin(), s2.end(), s2.begin(), tolower);
	  if(s2.substr(0, s.size()) == s)
	    {
	      if (checkDoublon(s2.substr(0, s.size() + 1), result) == false)
		result.push_back(s2.substr(0, s.size() + 1));
	      allresult.push_back(s2.substr(0, s.size() + 1));
	      add = true;
	    }
	  y = y + 1;
	}
    }
  if(add == true)
    return true;
  else
    return false;
}

bool	Autocompletion::validCity(std::string s)
{
  int				i;
  int				y;
  std::string			tmp1;
  std::string			tmp2;

  i = 0;

  tmp2 = s;
  std::transform(tmp2.begin(), tmp2.end(), tmp2.begin(), tolower);
  while (i < dictionnary.size())
    {
      y = 0;
      while (y < dictionnary[i].getcity().size())
	{
	  tmp1 = dictionnary[i].getcity()[y];
	  std::transform(tmp1.begin(), tmp1.end(), tmp1.begin(), tolower);
	  if(tmp1 == tmp2)
	    return true;
	  y = y + 1;
	}
      i = i + 1;
    }
  return false;
}

bool	Autocompletion::validStreetName(std::string s, Dict dict)
{
  int				i;
  int				y;
  std::string			tmp1;
  std::string			tmp2;

  tmp2 = s;
  std::transform(tmp2.begin(), tmp2.end(), tmp2.begin(), tolower);
  y = 0;
  while (y < dict.getstreetName().size())
    {
      tmp1 = dict.getstreetName()[y];
      std::transform(tmp1.begin(), tmp1.end(), tmp1.begin(), tolower);
      if(tmp1 == tmp2)
	return true;
      y = y + 1;
    }
  return false;
}

bool	Autocompletion::validCity2(std::string s, Dict dict)
{
  int				i;
  int				y;
  std::string			tmp1;
  std::string			tmp2;

  tmp2 = s;
  std::transform(tmp2.begin(), tmp2.end(), tmp2.begin(), tolower);
  y = 0;
  while (y < dict.getcity().size())
    {
      tmp1 = dict.getcity()[y];
      std::transform(tmp1.begin(), tmp1.end(), tmp1.begin(), tolower);
      if(tmp1 == tmp2)
	return true;
      y = y + 1;
    }
  return false;
}

bool	Autocompletion::validStreetName2(std::string s)
{
  int				i;
  int				y;
  std::string			tmp1;
  std::string			tmp2;

  i = 0;

  tmp2 = s;
  std::transform(tmp2.begin(), tmp2.end(), tmp2.begin(), tolower);
  while (i < dictionnary.size())
    {
      y = 0;
      while (y < dictionnary[i].getstreetName().size())
	{
	  tmp1 = dictionnary[i].getstreetName()[y];
	  std::transform(tmp1.begin(), tmp1.end(), tmp1.begin(), tolower);
	  if(tmp1 == tmp2)
	    return true;
	  y = y + 1;
	}
      i = i + 1;
    }
  return false;
}

std::vector<std::string>	Autocompletion::constructChoises()
{

  int				i;
  int				y;
  std::vector<std::string>	allchoices;  
  std::vector<std::string>	allwords;
  std::string			tmp;
  std::string			tmp2;
  std::string			tmp3;

  i = 0;
  while(i < dictionnary.size())
    {
      y = 0;
      if (validStreetName(result[0], dictionnary[i]) == true)
	{
	  tmp3 = dictionnary[i].getstreetType();
	  std::transform(tmp3.begin(), tmp3.end(), tmp3.begin(), tolower);
	  allwords.push_back(tmp3);
	  while (y < dictionnary[i].getstreetName().size())
	    {
	      tmp3 = dictionnary[i].getstreetName()[y];
	      std::transform(tmp3.begin(), tmp3.end(), tmp3.begin(), tolower);
	      allwords.push_back(tmp3);
	      y = y + 1;
	    }
	}
      i = i + 1;
    }
  i = 0;
  std::transform(result[0].begin(), result[0].end(), result[0].begin(), tolower);
  while(i < dictionnary.size())
    {
      y = 0;
      if (validStreetName(result[0], dictionnary[i]) == true)
	{
	  tmp2 = city + ", " + std::to_string(dictionnary[i].getnumber()) + " ";
	  tmp = dictionnary[i].getstreetType();
	  tmp3 = dictionnary[i].getstreetType();
	  std::transform(tmp3.begin(), tmp3.end(), tmp3.begin(), tolower);
	  if (checkDoublon(tmp3, allwords) > 1)
	    transform(tmp.begin(), tmp.end(), tmp.begin(),toupper);
	  else
	    transform(tmp.begin(), tmp.end(), tmp.begin(),tolower);
	  tmp2 = tmp2 + tmp + " ";
	  while (y < dictionnary[i].getstreetName().size())
	    {
	      tmp = dictionnary[i].getstreetName()[y];
	      tmp3 = dictionnary[i].getstreetName()[y];
	      std::transform(tmp3.begin(), tmp3.end(), tmp3.begin(), tolower);
	      if (checkDoublon(tmp3, allwords) > 1 || result[0] == tmp3)
		std::transform(tmp.begin(), tmp.end(), tmp.begin(),toupper);
	      else
	      	transform(tmp.begin(), tmp.end(), tmp.begin(),tolower);
	      if (y < dictionnary[i].getstreetName().size() - 1)
		tmp2 = tmp2 + tmp + " ";
	      else
		tmp2 = tmp2 + tmp;
              y = y + 1;
	    }
	  allchoices.push_back(dictionnary[i].getaddress());
	  allchoices.push_back(tmp2);
        }
      i = i + 1;
    }
  return allchoices;
}

bool compareString(const std::string& lhs, const std::string& rhs)
{
  std::istringstream	iss(lhs);
  std::istringstream	iss2;
  std::string		s1;
  std::string		s2;
  std::string	        tmp;
  int			a;
  int			b;
  
  std::getline(iss, tmp, ',');
  std::getline(iss, tmp, ',');
  iss2.str(Supprime_espace(tmp,' '));
  iss2 >> a;
  s1 = iss2.str().substr(iss2.str().find(" "));
  iss.clear();
  iss2.clear();
  iss.str(rhs);
  std::getline(iss, tmp, ',');
  std::getline(iss, tmp, ',');
  iss2.str(Supprime_espace(tmp,' '));
  iss2 >> b;
  s2 = iss2.str().substr(iss2.str().find(" "));
  if(a != b)
    return a < b;
  else
    return s1.compare(s2) < 0;
}

bool compareString2(const std::string& lhs, const std::string& rhs)
{
   return lhs.compare(rhs) < 0;
}


bool	Autocompletion::chooseStreet()
{
  int				i;
  int				y;
  int				z;
  int				nchoice;
  std::istringstream		iss;
  std::string			choice;
  std::vector<std::string>	allchoices;  
  std::vector<std::string>	allwords;
  std::string			tmp;

  i = 0;
  z = 1;
  nchoice = 0;
  allchoices =  constructChoises();
  if(allchoices.size() > 2)
    std::sort(allchoices.begin(), allchoices.end(), compareString);
  else
    std::sort(allchoices.begin(), allchoices.end());
  while(i < allchoices.size())
    {
      std::cout << "{" << z  << " :  " << allchoices[i] << "}";
      std::cout << " ";
      i = i + 2;
      z = z + 1;
      if (i >= allchoices.size())
  	std::cout << std::endl;
    }
  nchoice = 0;
  std::cin >> choice;
  iss.str(choice);
  iss >> nchoice;
  if(nchoice < 0 || nchoice > allchoices.size())
    return chooseStreet();
  if(nchoice == 0)
    {
      mot = result[0]; 
      mot = mot + choice;
      result[0] = mot;
      return true;
    }
  std::cout << "=> " << allchoices[(nchoice) * (nchoice - 1) + 1] << std::endl;
  return false;
}

bool	Autocompletion::updateDict(int	nchoice, std::vector<std::string> allchoices)
{
  std::string	tmp;
  std::string	tmp2;
  int		i;
  
  i = 0;
  while(i < dictionnary.size() && dictionnary.size() != 0)
    {
      tmp = dictionnary[i].getaddress();
      tmp2 = dictionnary[i].getaddress();
      std::transform(tmp.begin(), tmp.end(), tmp.begin(), tolower);
      std::transform(tmp2.begin() + tmp.find(result[0]),tmp2.begin() +tmp.find(result[0]) + result[0].size(),tmp2.begin() + tmp.find(result[0]), toupper);
      if (tmp2.substr(0, tmp2.find(",")) != allchoices[nchoice - 1])
	dictionnary.erase(dictionnary.begin() + i);
      i = i + 1;
    }
  if(dictionnary.size() == 1)
    {
      std::cout << "=> " << dictionnary[0].getaddress() << std::endl;
      return false;
    }
  return true;
}

bool	Autocompletion::chooseCity()
{
  int				i;
  int				nchoice;
  std::istringstream		iss;
  std::string			choice;
  std::string			tmp;
  std::string			tmp2;
  std::vector<std::string>	allchoices;  

  i = 0;
  while(i < dictionnary.size())
    {
      tmp = dictionnary[i].getaddress();
      tmp2 = dictionnary[i].getaddress();
      std::transform(tmp.begin(), tmp.end(), tmp.begin(), tolower);
      std::transform(tmp2.begin(), tmp2.end(), tmp2.begin(), tolower);
      std::transform(tmp2.begin() + tmp.find(result[0]),tmp2.begin() + tmp.find(result[0]) + result[0].size(),tmp2.begin() + tmp.find(result[0]), toupper);
      if (checkDoublon(tmp2.substr(0, tmp2.find(",")), allchoices) == false && validCity2(result[0] ,dictionnary[i]) == true)	
	allchoices.push_back(tmp2.substr(0, tmp2.find(",")));
      i = i + 1;
    }
  i = 0;
  nchoice = 0;
  std::sort(allchoices.begin(), allchoices.end(),compareString2);
  while(i < allchoices.size())
    {
      std::cout << "{" << nchoice + 1 << " :  " << allchoices[i] << "}";
      nchoice = nchoice + 1;
      if(i + 1 == allchoices.size())
	std::cout << std::endl;
      else
	std::cout << " ";
      i = i + 1;
    }
  nchoice = 0;
  std::cin >> choice;
  iss.str(choice);
  iss >> nchoice;
  if(nchoice == 0)
    {
      mot = result[0]; 
      mot = mot + choice;
      result[0] = mot;
      return true;
    }
  if (updateDict(nchoice, allchoices) == false)
    return false;
  if(nchoice < 0 || nchoice > allchoices.size())
    return chooseCity();
  i = 0;
  if(nchoice > 0 && nchoice < allchoices.size())
    {
      std::cout << "toto" << std::endl;
      city = allchoices[nchoice - 1];
      std::transform(city.begin(), city.end(), city.begin(), toupper);
      cityIsValid = true;
      result.clear();
      mot.clear();
    }
  return true;
}

int	Autocompletion::checkAuto()
{
  int	ret;

  ret = 0;
  if(dictionnary.size() == 0)
    {
      std::cerr << "unknown address" << std::endl;
      return 84;
    }
  if(dictionnary.size() == 1)
    {
      std::cout << "=> " << dictionnary[0].getaddress() << std::endl;
      return 0;
    }
  if(cityIsValid == true && result.size() > 0)
    {
      if(result.size() == 1 && validStreetName2(result[0]) == false)
        {
          mot = result[0];
	  ret = checkInDict(mot);
	  return (ret);
        }
      if(validStreetName2(result[0]) == true)
        if(chooseStreet() == false)
          return 0;
	else if ((ret = checkAuto()) == 84)
	  return ret;
	else if (ret == 0)
	  return ret;
    } 
  if(result.size() > 0)
    { 
      if(result.size() == 1 && validCity(result[0]) == false)
	{
	  mot = result[0];
	  ret = checkInDict(mot);
	  return (ret);
        }
      else  if (validCity(result[0]) == true && cityIsValid == false)
	{
	  if (checkCityDict() == true && cityIsValid == false)
	    {
	      cityIsValid = true;
	      city = result[0];
	      std::transform(city.begin(), city.end(), city.begin(), toupper);
	      result.clear();
	      allresult.clear();
	      mot.clear();
	      checkInDict("");
	    }
	  else if (cityIsValid == false)
	    {
	      if (chooseCity() == false)
		return 0;
	    }
	}
      else
	displayPossibilities();
    }
  return 1;
}

int	Autocompletion::checkInDict(std::string	s)
{
  int				i;
  int				y;
  std::string			s2;  
  std::string			s3;

  i = 0;
  result.clear();
  std::transform(s.begin(), s.end(), s.begin(), tolower);
  while (i < dictionnary.size())
    {
      if (check(s,dictionnary[i]) == false)
       	{
	  dictionnary.erase(dictionnary.begin() + i);
	  i = i - 1;
	}
      i = i + 1;
    }
  return checkAuto();
}

int	Autocompletion::Run()
{
  std::string	s;
  int		ret;
  
  checkInDict("");
  while (0 == 0)
    {
      ret = 0;
      std::cin >> s;
      mot = mot + s;
      ret = checkInDict(mot);
      if (ret == 0 || s == "ABORT")
	return 0;
      else if (ret == 84)
	return 84;
    }
}
