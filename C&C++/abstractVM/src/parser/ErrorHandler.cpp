//
// ErrorHandler.cpp for  in /home/victor/rendu/abstractVM/src/parser
//
// Made by victor
// Login   <victor@epitech.net>
//
// Started on  Sat Jul 16 20:48:15 2016 victor
// Last update Mon Jul 18 14:08:28 2016 victor
//

#include "ErrorHandler.hh"

ErrorHandler::ErrorHandler(std::string &report, int *line) throw()
{
  if (line == NULL)
    *line = 0;
  this->exception = "Error at line " + std::to_string(*line) + " : " + report;
}

ErrorHandler::~ErrorHandler() throw()
{
}

const char	*ErrorHandler::what() const throw()
{
  return(this->exception.c_str());
}
