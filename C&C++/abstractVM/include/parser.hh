//
// parser.hh for  in /home/victor/rendu/abstractVM/src/parser
//
// Made by victor
// Login   <victor@epitech.net>
//
// Started on  Fri Jul 15 23:30:55 2016 victor
// Last update Mon Jul 18 22:19:18 2016 victor
//

#ifndef PARSER_HH_
# define PARSER_HH_

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <fstream>
# include <sstream>
# include <iterator>
# include "./../../include/IOperand.h"
# include "./../../include/Factory.h"
# include "./../../include/Instruction.h"

class		Parser
{
 public:
  Parser();
  ~Parser();
  void			ParseByFile(char*);
  void			ParseByLineLoop();
  const std::vector<Instruction*>&	GetParsedList() const;
 private:
  ////				RULES_FCT
  bool				TestGrammarRules(std::string&, int);
  bool				CheckOrder(std::string&, int);
  bool				RuleN(std::string&, int);
  bool				RuleZ(std::string&, int);
  bool				RuleValue(std::string&, int);
  bool				RuleValueNT(std::string&, int);
  bool				RuleInstr(std::string&, int);
  bool				RuleSep(std::string&, int) const;
  ////                          GRAMMAR
  void				CreateGrammar();
  std::vector<std::string>	typeN;
  std::vector<std::string>	typeZ;
  std::vector<std::string>	instr;
  std::vector<std::string>	instrNP;
  std::vector<std::string>	instrNT;
  ////				RESEARCH_FCT
  bool				FindInstrNP(std::string&);
  bool				FindInstrNT(std::string&);
  bool				FindInstr(std::string&);
  bool				FindTypeN(std::string&);
  bool				FindTypeZ(std::string&);
  bool				ThisLineIsComment(std::string&) const;
  ////				PARSING_VARIABLES
  std::string			cmd;
  std::string			value;
  std::string			type;
  ////				RESULT
  void				MakeNewInstr();
  std::vector<Instruction*>	ParsedList;
};

#endif /*PARSER_HH_*/
