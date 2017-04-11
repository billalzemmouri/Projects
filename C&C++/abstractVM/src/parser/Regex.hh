//
// Regex.hh for  in /home/victor/rendu/abstractVM/src/parser
//
// Made by victor
// Login   <victor@epitech.net>
//
// Started on  Sat Jul 16 20:36:54 2016 victor
// Last update Sat Jul 16 20:39:12 2016 victor
//

#ifndef REGEX_HH_
# define REGEX_HH_
# include <regex.h>
# include <vector>
# include <string>
# include <iostream>

class Regex
{
public:
	Regex(std::string const& regex = "", std::string const& buf = "");
	~Regex();
	void				init(std::string const&, std::string const&);
	std::vector<std::string> 	fetchMatch() const;

private:
	std::string 	regex;
	std::string 	buf;
};

#endif /*REGEX_HH_*/
