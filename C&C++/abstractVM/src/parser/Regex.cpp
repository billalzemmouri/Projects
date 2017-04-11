//
// Regex.cpp for  in /home/victor/rendu/abstractVM/src/parser
//
// Made by victor
// Login   <victor@epitech.net>
//
// Started on  Sat Jul 16 20:38:58 2016 victor
// Last update Sat Jul 16 21:46:40 2016 victor
//

#include "Regex.hh"

Regex::Regex(std::string const& regex, std::string const& buf)
{
  this->regex = regex;
  this->buf = buf;
}

Regex::~Regex()
{

}

void 		Regex::init(std::string const& regex, std::string const& buf)
{
  this->regex = regex;
  this->buf = buf;
}

std::vector<std::string> 		Regex::fetchMatch() const
{
  regex_t 					preg;
  regmatch_t 					pmatch;
  int 						match;
  const char					*buf;
  std::vector<std::string>	result;

  if (this->regex == "" || this->buf == "")
    {
      std::cerr << "Regex : regex and string not set" << std::endl;
      return (result);
    }
  if (regcomp(&preg, this->regex.c_str(), REG_EXTENDED) != 0)
    {
      std::cerr << "Regex: regcomp error" << std::endl;
      return (result);
    }
  buf = this->buf.c_str();
 // while (42)
   // {
      if ((match = regexec(&preg, buf, 1, &pmatch, 0)) == 0)
	{
    result.push_back(this->buf.substr(pmatch.rm_so, pmatch.rm_eo - pmatch.rm_so));
    buf = &buf[pmatch.rm_eo + 1];
	}
      else if (match == REG_NOMATCH)
	{
	  regfree(&preg);
	  return (result);
	}
    //}
  regfree(&preg);
  return (result);
}
