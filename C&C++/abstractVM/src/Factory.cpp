#include <iostream>
#include <vector>
#include "../include/OperandClasses.h"
#include "../include/Factory.h"
#include "../include/BigDecimal.hpp"
#include <limits>
#include <cfloat>
#include <cmath>
#include <cstdlib>
Factory::Factory()
{

}

IOperand 		*Factory::createInt8(const std::string &value)
{
	IOperand 	*ret = new class Int8;
	int8_t 		val;
	long double		detect;
	std::string err("Overflow");

	detect = std::stold(value);
	if (detect > INT8_MAX_LIM || detect < INT8_MIN_LIM)
		throw ErrorHandler(err, new int(21));
	val = static_cast<int8_t>(std::stoi(value));
	ret->setvalue(&val);
	return (ret);
}

IOperand 		*Factory::createInt16(const std::string &value)
{
	IOperand 	*ret = new class Int16;
	int16_t 	val;
	long double		detect;
	std::string err("Overflow");

	detect = std::stold(value);
	if (detect > INT16_MAX_LIM || detect < INT16_MIN_LIM)
		throw ErrorHandler(err, new int(36));
	val = static_cast<int16_t>(std::stoi(value));
	ret->setvalue(&val);
	return (ret);
}

IOperand 		*Factory::createInt32(const std::string &value)
{
	IOperand 	*ret = new class Int32;
	int32_t 	val;
	long double	detect;
	std::string err("Overflow");
	
	detect = std::stold(value);
	if (detect > INT32_MAX_LIM || detect < INT32_MIN_LIM)
		throw ErrorHandler(err, new int(51));
	val = static_cast<int32_t>(std::stoi(value));
	ret->setvalue(&val);
	return (ret);
}

IOperand 		*Factory::createFloat(const std::string &value)
{
	IOperand 	*ret = new class Float;
	float 		val;

	long double detect;
	std::string 	err = "Overflow on float"; 
	
	detect = std::stold(value);
	if (std::fabs(detect) > FLT_MAX || std::fabs(detect) < FLT_MIN)
		throw ErrorHandler(err, new int(74));
	val = std::stof(value);
	ret->setvalue(&val);
	return (ret);
}

IOperand 		*Factory::createDouble(const std::string &value)
{
	IOperand 	*ret = new class Double;
	double 		val;
	long double detect;
	std::string 	err = "Overflow on double"; 
	
	detect = std::stold(value);
	if (std::fabs(detect) > DBL_MAX || std::fabs(detect) < DBL_MIN)
		throw ErrorHandler(err, new int(74));
	val = std::stod(value);
	ret->setvalue(&val);
	return (ret);
}

IOperand 		*Factory::createBigDecimal(const std::string &value)
{
	IOperand 	*ret = new class BigDecimal(value);

	return (ret);
}

IOperand 		*Factory::createOperand(eOperandType type, const std::string &value)
{
	static  	std::vector<IOperand *(Factory::*)(const std::string&)> functions = {&Factory::createInt8, &Factory::createInt16, &Factory::createInt32, &Factory::createFloat, &Factory::createDouble, &Factory::createBigDecimal};
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
		case 	eOperandType::BigDecimal:
			return ((tmp.*functions[5])(value));
	}
	return (NULL);
}