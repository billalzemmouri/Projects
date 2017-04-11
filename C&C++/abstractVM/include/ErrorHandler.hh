//
// ErrorHandler.hh for  in /home/victor/rendu/abstractVM/src/parser
//
// Made by victor
// Login   <victor@epitech.net>
//
// Started on  Sat Jul 16 20:45:21 2016 victor
// Last update Mon Jul 18 14:11:09 2016 victor
//
#ifndef ERRORHANDLER_HH_
#define ERRORHANDLER_HH_
# include <exception>
# include <string>

class		ErrorHandler : public std::exception
{
 public:
  ErrorHandler(std::string&, int*) throw();
  virtual ~ErrorHandler() throw();
  virtual const char	*what() const throw();
 private:
  std::string	exception;
};

#endif /*ERRORHANDLER_HH_*/
