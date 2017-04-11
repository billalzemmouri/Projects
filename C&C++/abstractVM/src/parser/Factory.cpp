#include <vector>
#include "../../include/OperandClasses.h"
#include "../../include/Factory.h"

Factory::Factory()
{

}

IOperand 		*Factory::createInt8(const std::string &value)
{
	IOperand 	*ret = new class Int8;
	int8_t 		val;

	val = static_cast<int8_t>(std::stoi(value));
	ret->setvalue(&val);
	return (ret);
}

IOperand 		*Factory::createInt16(const std::string &value)
{
	IOperand 	*ret = new class Int16;
	int16_t 	val;

	val = static_cast<int16_t>(std::stoi(value));
	ret->setvalue(&val);
	return (ret);
}

IOperand 		*Factory::createInt32(const std::string &value)
{
	IOperand 	*ret = new class Int32;
	int32_t 	val;

	val = static_cast<int32_t>(std::stoi(value));
	ret->setvalue(&val);
	return (ret);
}

IOperand 		*Factory::createFloat(const std::string &value)
{
	IOperand 	*ret = new class Float;
	float 		val;

	val = std::stof(value);
	ret->setvalue(&val);
	return (ret);
}

IOperand 		*Factory::createDouble(const std::string &value)
{
	IOperand 	*ret = new class Double;
	double 		val;

	val = std::stod(value);
	ret->setvalue(&val);
	return (ret);
}

IOperand 		*Factory::createOperand(eOperandType type, const std::string &value)
{
	static  	std::vector<IOperand *(Factory::*)(const std::string&)> functions = {&Factory::createInt8, &Factory::createInt16, &Factory::createInt32, &Factory::createFloat, &Factory::createDouble};
	Factory 	tmp;

	switch (type)
	{
		case 	eOperandType::Int8:
			return ((tmp.*functions[0])(value));
		case 	eOperandType::Int16:
			return ((tmp.*functions[1])(value));
		case 	eOperandType::Int32:
			return ((tmp.*functions[2])(value));
		case 	eOperandType::Float:
			return ((tmp.*functions[3])(value));
		case 	eOperandType::Double:
			return ((tmp.*functions[4])(value));
	}
	return (NULL);
}
