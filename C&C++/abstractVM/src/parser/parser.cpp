//
// parser.cpp for  in /home/victor/rendu/abstractVM/src/parser
//
// Made by victor
// Login   <victor@epitech.net>
//
// Started on  Sat Jul 16 00:06:44 2016 victor
// Last update Wed Jul 20 17:37:08 2016 Shark
//

#include <locale>
#include "parser.hh"
#include "Regex.hh"
#include "ErrorHandler.hh"
#include "string.h"

Parser::Parser()
{
}

Parser::~Parser()
{
  if (this->ParsedList.size() > 0)
    for (std::vector<Instruction*>::iterator it = this->ParsedList.begin();
	 it != this->ParsedList.end(); ++it)
      delete *it;
}

bool		Parser::CheckAscii(std::string &line)
{
std::locale	loc;

  for (std::string::const_iterator it = line.cbegin(); it != line.cend(); ++it)
if (!(std::isalnum(*it, loc)) && *it != ';' && *it != '.' &&
    *it != '(' && *it != ')' && *it != ' ' && *it != '-' && *it != '\t')
return false;
  return true;
}

void		Parser::ParseByFile(char *filename)
{
  std::ifstream	ifs(filename, std::ifstream::in);
  std::filebuf	*fbuf;
  char		*buffer;
  std::istringstream stream;
  std::string	     line;
  int		     pos = 0;

  if (ifs.is_open())
    {
      fbuf = ifs.rdbuf();
      std::streamsize size = fbuf->pubseekoff(0, ifs.end);
      fbuf->pubseekoff(0, ifs.beg);
      buffer = new char[size + static_cast<std::streamsize>(1)];
      bzero(buffer, size + static_cast<std::streamsize>(1));
      fbuf->sgetn(buffer, size + 1);
      std::string file(buffer);
      ifs.close();
      stream.str(file);
      this->CreateGrammar();
      while (std::getline(stream, line))
	{
	  ++pos;
	  if ((!this->ThisLineIsComment(line)) && line.size() > 0 && this->CheckAscii(line))
	    {
	      line.push_back('\n');
		try
		  {
		    if (!this->TestGrammarRules(line, pos))
		      {
			std::string str("Undefined error");
			throw ErrorHandler(str, &pos);
		      }
		  }
		catch (ErrorHandler err)
		  {
		    std::cerr << err.what() << std::endl;
		    exit (84);
		  }
	    }
	  line.clear();
	  this->cmd.clear();
	  this->value.clear();
	  this->type.clear();
	}
    }
  else
    {
      std::string str("Failure when opening file");
      throw ErrorHandler(str, &pos);
    }
}

void		Parser::ParseByLineLoop()
{
  std::string	line;
  int		pos = 0;

  this->CreateGrammar();
  while (getline(std::cin, line))
    {
      ++pos;
      if (line.size() > 0)
	{
	  line.push_back('\n');
	  if (line == ";;\n")
	    return;
	  else
	    try
	      {
		if (!this->TestGrammarRules(line, pos))
		  {
		    std::string str("Undefined error");
		    throw ErrorHandler(str, &pos);
		  }
	      }
	    catch (ErrorHandler err)
	      {
		std::cerr << err.what() << std::endl;
		exit (84);
	      }
	}
      line.clear();
      this->cmd.clear();
      this->value.clear();
      this->type.clear();
    }
}

void	Parser::EpurLine(std::string &line)
{
  std::string::iterator at = line.end();
  bool loop = true;

  while (loop && at != line.begin())
    {
      --at;
      if (isblank(*at))
	line.erase(at);
      else
	loop = false;
    }
}

bool		Parser::ThisLineIsComment(std::string &line)
{
  size_t			i;

  if ((i = line.find(";", 0)) == std::string::npos)
    return (false);
  if (i == 0)
    return (true);
  else
    {
      line[i] = ' ';
      line = line.substr(0, i);
      this->EpurLine(line);
      this->EpurLine(line);
      if (line.size() == 0)
	return true;
      else
	return false;
    }
  return true;
}

const std::vector<Instruction*>&	Parser::GetParsedList() const
{
  return (this->ParsedList);
}

void		Parser::CreateGrammar()
{
  this->typeN.push_back("int8");
  this->typeN.push_back("int16");
  this->typeN.push_back("int32");
  this->typeZ.push_back("float");
  this->typeZ.push_back("double");
  this->typeZ.push_back("bigdecimal");
  this->instr.push_back("push");
  this->instr.push_back("assert");
  this->instr.push_back("load");
  this->instr.push_back("store");
  this->instrNP.push_back("pop");
  this->instrNP.push_back("dump");
  this->instrNP.push_back("clear");
  this->instrNP.push_back("dup");
  this->instrNP.push_back("swap");
  this->instrNP.push_back("add");
  this->instrNP.push_back("sub");
  this->instrNP.push_back("mul");
  this->instrNP.push_back("div");
  this->instrNP.push_back("mod");
  this->instrNP.push_back("print");
  this->instrNP.push_back("exit");
}

void		Parser::MakeNewInstr()
{
  Instruction	*instr;
  Factory	maker;

  try
    {
      instr = new Instruction;
    }
  catch (ErrorHandler &err)
    {
      std::cerr << err.what() << std::endl;
      exit (84);
    }
  instr->settype(static_cast<eOperandType>(-1));
  for (int i = 0; i < 3; i++)
    {
      if (this->type == this->typeN[i])
	instr->settype(static_cast<eOperandType>(i));
      else if (this->type == this->typeZ[i])
	instr->settype(static_cast<eOperandType>(i + 3));
    }
 if (!this->value.empty())
    instr->setop(maker.createOperand(instr->gettype(), this->value));
  instr->setcmd(this->cmd);
  this->ParsedList.push_back(instr);
 }

bool		Parser::TestGrammarRules(std::string &line, int pos)
{
  std::string	recon;

  if (this->RuleInstr(line, pos) && this->RuleSep(line, pos))
  {
    if (this->CheckOrder(line, pos))
      {
	this->MakeNewInstr();
	return true;
      }
    }
  return false;
}

bool		Parser::CheckBlank(std::string &recon, std::string &line)
{
  size_t	i;
  std::string	str;

  if (this->FindInstr(this->cmd))
    {
      for (std::string::iterator it = line.begin(); it != line.end(); it++)
	{
	  if (!isblank(*it))
	    str.append(1, *it);
	}
      line = str;
      i = line.find(this->cmd, 0);
      i += this->cmd.size();
      line.insert(i, " ");
    }
  else if (this->FindInstrNP(this->cmd))
    {
      for (std::string::iterator it = line.begin(); it != line.end(); ++it)
	{
	  if (!isblank(*it))
	    str.append(1, *it);
	}
      line = str;
    }
  if (recon == line)
    return true;
  return false;
}

bool		Parser::CheckOrder(std::string &line, int pos)
{
  std::string	recon;

  if (this->FindInstrNP(this->cmd) && this->type.empty() && this->value.empty())
    recon = this->cmd + "\n";
  else if (this->FindInstr(this->cmd) && !this->type.empty() && !this->value.empty())
    recon = this->cmd + " " + this->type + "(" + this->value + ")" + "\n";
  if (recon == line || this->CheckBlank(recon, line))
    return true;
  else
    {
      std::string str("bad formatted line, please use the form '[instruction] [type]([value])' and avoid any useless or blanks characters");
      throw ErrorHandler(str, &pos);
    }
  return false;
}

bool		Parser::RuleSep(std::string &line, int pos) const
{
  if (line.back() != '\n')
    {
      std::string str("missing end of line character");
      throw ErrorHandler(str, &pos);
    }
  return true;
}

bool		Parser::RuleInstr(std::string &line, int pos)
{
  if (this->FindInstrNP(line))
    return true;
  else if (this->FindInstr(line) && this->RuleValue(line, pos))
    return true;
  else
    {
      std::string str("no valid instruction found");
      throw ErrorHandler(str, &pos);
    }
  return false;
}

/*bool				Parser::RuleValueNT(std::string &line, int pos)
{
  size_t			i;
  std::string			reg("-?[0-9a-zA-Z]+");
  std::vector<std::string>	match;

  if ((i = line.find(this->cmd, 0)) != std::string::npos)
    {
      i += this->cmd.size();
      Regex regex(reg, line.substr(i, std::string::npos));
      match = regex.fetchMatch();
      if (match.size() == 1)
	this->value = match[0];
      else if (match.size() > 1 || match[0].find("-", 0) != std::string::npos)
	{
	  std::string str("bad register value for " + this->cmd);
	  throw ErrorHandler(str, &pos);
	}
      else
	{
	  std::string str("missing value (register number)");
	  throw ErrorHandler(str, &pos);
	}
    }
  else
    {
      std::string str("Instruction missing or invalid");
      throw ErrorHandler(str, &pos);
    }
  return true;
}*/

bool		Parser::RuleValue(std::string &line, int pos)
{
  if (!((this->FindTypeN(line) && this->RuleN(line, pos)) || (this->FindTypeZ(line) && this->RuleZ(line, pos))))
    {
      std::string str("TYPE(VALUE) missing or invalid");
      throw ErrorHandler(str, &pos);
    }
  return true;
}

bool		Parser::RuleN(std::string &line, int pos)
{
  std::string			reg("-?[0-9]+");
  std::vector<std::string>	match;
  size_t			i, j;

  if ((i = line.find("(", 0)) == std::string::npos)
    {
      std::string str("missing open bracket '('");
      throw ErrorHandler(str, &pos);
    }
  if ((j = line.find(")", i)) == std::string::npos)
    {
      std::string str("missing close bracket ')'");
      throw ErrorHandler(str, &pos);
    }
  Regex regex(reg, line.substr((i + 1), (j - i - 1)));
  match = regex.fetchMatch();
 /* for (size_t i = 0; i < match.size(); i++)
  {
    if (match[i].size() == 0)
      match.pop_back();
  }*/
  if (match.size() == 1 && line.substr((i + 1), (j - i - 1)).find(".", 0) == std::string::npos)
{
    this->value = match[0];

}
  else if (match.size() == 1 && line.substr((i + 1), (j - i - 1)).find(".", 0) != std::string::npos)
    {
      std::string str("value must be integer for type int8 int16 int32");
      throw ErrorHandler(str, &pos);
    }
  else
    {
      std::string str("missing value(N) between brackets");
      throw ErrorHandler(str, &pos);
    }
  return true;
}

bool		Parser::RuleZ(std::string &line, int pos)
{
  std::string			reg2("-?[0-9]+");
  std::string			reg("-?[0-9]+.[0-9]+");
  std::vector<std::string>	match;
  Regex				regex;
  size_t			i, j;

  if ((i = line.find("(", 0)) == std::string::npos)
    {
      std::string str("missing open bracket '('");
      throw ErrorHandler(str, &pos);
    }
  if ((j = line.find(")", i)) == std::string::npos)
    {
      std::string str("missing close bracket ')'");
      throw ErrorHandler(str, &pos);
    }
  if ((line.substr(i, (j - i))).find(".", 0) != std::string::npos)
    regex.init(reg, line.substr((i + 1), (j - i - 1)));
  else
    regex.init(reg2, line.substr((i + 1), (j - i - 1)));
  match = regex.fetchMatch();

  if (match.size() > 0)
    this->value = match[0];
  else
    {
      std::string str("missing value(Z) between brackets");
      throw ErrorHandler(str, &pos);
    }
  return true;
}

bool		Parser::FindInstrNP(std::string &line)
{
  for (std::vector<std::string>::const_iterator it = this->instrNP.begin();
       it != this->instrNP.end(); ++it)
    {
      if (line.find(*it, 0) != std::string::npos)
	{
	  if (this->cmd.size() == 0)
	    this->cmd = *it;
	  return true;
	}
    }
  return false;
}

/*bool		Parser::FindInstrNT(std::string &line)
{
  for (std::vector<std::string>::const_iterator it = this->instrNT.begin();
       it != this->instrNT.end(); ++it)
    {
      if (line.find(*it, 0) != std::string::npos)
	{
	  if (this->cmd.size() == 0)
	    this->cmd = *it;
	  return true;
	}
    }
  return false;
}*/

bool		Parser::FindInstr(std::string &line)
{
  for (std::vector<std::string>::const_iterator it = this->instr.begin();
       it != this->instr.end(); ++it)
    if (line.find(*it, 0) != std::string::npos)
      {
	if (this->cmd.size() == 0)
	  this->cmd = *it;
	return true;
      }
  return false;
}

bool		Parser::FindTypeN(std::string &line)
{
  for (std::vector<std::string>::const_iterator it = this->typeN.begin();
       it != this->typeN.end(); ++it)
    if (line.find(*it, 0) != std::string::npos)
      {
	if (this->type.size() == 0)
	  this->type = *it;
	return true;
      }
  return false;
}

bool		Parser::FindTypeZ(std::string &line)
{
  for (std::vector<std::string>::const_iterator it = this->typeZ.begin();
       it != this->typeZ.end(); ++it)
    if (line.find(*it, 0) != std::string::npos)
      {
	if (this->type.size() == 0)
	  this->type = *it;
	return true;
      }
  return false;
}
