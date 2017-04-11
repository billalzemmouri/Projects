#include <iostream>
#include <cmath>
#include "../../include/OperandClasses.h"
#include "../../include/Factory.h"

Int8::Int8()
{

}

/* --------------------------- Int8 FUNCTIONS ----------------------- */

std::string 		Int8::toString() const
{
	std::string 	ret;
	std::ostringstream 	stream;

	stream << this->value;
	ret = stream.str();
	return (ret);
}

eOperandType 		Int8::getType() const
{
	return (eOperandType::Int8);
}

IOperand 			*Int8::operator+(const IOperand &op) const
{
	Factory 		*tmp = new Factory();
	IOperand 		*ret;
	std::ostringstream 	stream;
	std::string 	value;

	if (eOperandType::Int8 >= op.getType())
	{
		stream << static_cast<int8_t>(std::stoi(op.toString())) + this->getvalue();
		value = stream.str();
		ret = tmp->createOperand(eOperandType::Int8, value);
	}
	else
	{
		switch (static_cast<int>(op.getType()))
		{
			case eOperandType::Int16:
				stream << std::stoi(op.toString()) + static_cast<int16_t>(this->getvalue());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Int16, value);
				break;
			case eOperandType::Int32:
				stream << std::stoi(op.toString()) + static_cast<int32_t>(this->getvalue());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Int32, value);
				break;
			case eOperandType::Float:
				stream << std::stof(op.toString()) + static_cast<float>(this->getvalue());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Float, value);
				break;
			case eOperandType::Double:
				stream << stod(op.toString()) + static_cast<double>(this->getvalue());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Double, value);
				break;
		}
	}
	delete tmp;
	return (ret);
}

IOperand 			*Int8::operator-(const IOperand &op) const
{
	Factory 		*tmp = new Factory();
	IOperand 		*ret;
	std::ostringstream 	stream;
	std::string 	value;

	if (eOperandType::Int8 >= op.getType())
	{
		stream << this->getvalue() - static_cast<int8_t>(std::stoi(op.toString()));
		value = stream.str();
		ret = tmp->createOperand(eOperandType::Int8, value);
	}
	else
	{
		switch (static_cast<int>(op.getType()))
		{
			case eOperandType::Int16:
				stream << static_cast<int16_t>(this->getvalue()) - std::stoi(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Int16, value);
				break;
			case eOperandType::Int32:
				stream << static_cast<int32_t>(this->getvalue()) - std::stoi(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Int32, value);
				break;
			case eOperandType::Float:
				stream << static_cast<float>(this->getvalue()) - std::stof(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Float, value);
				break;
			case eOperandType::Double:
				stream << static_cast<double>(this->getvalue()) - std::stod(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Double, value);
				break;
		}
	}
	delete tmp;
	return (ret);
}

IOperand 			*Int8::operator/(const IOperand &op) const
{
	Factory 		*tmp = new Factory();
	IOperand 		*ret;
	std::ostringstream 	stream;
	std::string 	value;

	if (std::stoi(op.toString()) == 0)
	{
		std::cerr << "Dividing by zero : Don't forget to throw exception" << std::endl;
		exit (84);
	}
	if (eOperandType::Int8 >= op.getType())
	{
		stream << this->getvalue() / static_cast<int8_t>(std::stoi(op.toString()));
		value = stream.str();
		ret = tmp->createOperand(eOperandType::Int8, value);
	}
	else
	{
		switch (static_cast<int>(op.getType()))
		{
			case eOperandType::Int16:
				stream <<  static_cast<int16_t>(this->getvalue()) / std::stoi(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Int16, value);
				break;
			case eOperandType::Int32:
				stream << static_cast<int32_t>(this->getvalue()) / std::stoi(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Int32, value);
				break;
			case eOperandType::Float:
				stream << static_cast<float>(this->getvalue()) / std::stof(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Float, value);
				break;
			case eOperandType::Double:
				stream << static_cast<double>(this->getvalue()) / std::stod(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Double, value);
				break;
		}
	}
	delete tmp;
	return (ret);
}

IOperand 			*Int8::operator%(const IOperand &op) const
{
	Factory 		*tmp = new Factory();
	IOperand 		*ret;
	std::ostringstream 	stream;
	std::string 	value;

	if (std::stoi(op.toString()) == 0)
	{
		std::cerr << "Dividing by zero : Don't forget to throw exception" << std::endl;
		exit (84);
	}
	if (eOperandType::Int8 >= op.getType())
	{
		stream << this->getvalue() % static_cast<int8_t>(std::stoi(op.toString()));
		value = stream.str();
		ret = tmp->createOperand(eOperandType::Int8, value);
	}
	else
	{
		switch (static_cast<int>(op.getType()))
		{
			case eOperandType::Int16:
				stream <<  static_cast<int16_t>(this->getvalue()) % std::stoi(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Int16, value);
				break;
			case eOperandType::Int32:
				stream << static_cast<int32_t>(this->getvalue()) % std::stoi(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Int32, value);
				break;
			case eOperandType::Float:
				std::string err = "Modulo float";
				throw ErrorHandler(err, new int(196))
				break;
			case eOperandType::Double:
				std::string err = "Modulo double";
				throw ErrorHandler(err, new int(196))
				break;
		}
	}
	delete tmp;
	return (ret);
}

IOperand 			*Int8::operator*(const IOperand &op) const
{
	Factory 		*tmp = new Factory();
	IOperand 		*ret;
	std::ostringstream 	stream;
	std::string 	value;

	if (eOperandType::Int8 >= op.getType())
	{
		stream << this->getvalue() * static_cast<int8_t>(std::stoi(op.toString()));
		value = stream.str();
		ret = tmp->createOperand(eOperandType::Int8, value);
	}
	else
	{
		switch (static_cast<int>(op.getType()))
		{
			case eOperandType::Int16:
				stream <<  static_cast<int16_t>(this->getvalue()) * std::stoi(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Int16, value);
				break;
			case eOperandType::Int32:
				stream << static_cast<int32_t>(this->getvalue()) * std::stoi(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Int32, value);
				break;
			case eOperandType::Float:
				stream << static_cast<float>(this->getvalue()) * std::stof(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Float, value);
				break;
			case eOperandType::Double:
				stream << static_cast<double>(this->getvalue()) * std::stod(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Double, value);
				break;
		}
	}
	delete tmp;
	return (ret);
}

int8_t 					Int8::getvalue() const
{
	return (this->value);
}

void 					Int8::setvalue(void* val)
{
	int8_t 				*tmp;

	tmp = static_cast<int8_t*>(val);
	this->value = *tmp;
}

/* ------------------- Int16 Functions ------------------------- */
Int16::Int16()
{

}


std::string 		Int16::toString() const
{
	std::string 	ret;
	std::ostringstream 	stream;

	stream << this->value;
	ret = stream.str();
	return (ret);
}

eOperandType 		Int16::getType() const
{
	return (eOperandType::Int16);
}

IOperand 			*Int16::operator+(const IOperand &op) const
{
	Factory 		*tmp = new Factory();
	IOperand 		*ret;
	std::ostringstream 	stream;
	std::string 	value;

	if (eOperandType::Int16 >= op.getType())
	{
		stream << static_cast<int16_t>(std::stoi(op.toString())) + this->getvalue();
		value = stream.str();
		ret = tmp->createOperand(eOperandType::Int16, value);
	}
	else
	{
		switch (static_cast<int>(op.getType()))
		{
			case eOperandType::Int32:
				stream << std::stoi(op.toString()) + static_cast<int32_t>(this->getvalue());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Int32, value);
				break;
			case eOperandType::Float:
				stream << std::stof(op.toString()) + static_cast<float>(this->getvalue());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Float, value);
				break;
			case eOperandType::Double:
				stream << std::stod(op.toString()) + static_cast<double>(this->getvalue());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Double, value);
				break;
		}
	}
	delete tmp;
	return (ret);
}

IOperand 			*Int16::operator-(const IOperand &op) const
{
	Factory 		*tmp = new Factory();
	IOperand 		*ret;
	std::ostringstream 	stream;
	std::string 	value;

	if (eOperandType::Int16 >= op.getType())
	{
		stream << this->getvalue() - static_cast<int16_t>(std::stoi(op.toString()));
		value = stream.str();
		ret = tmp->createOperand(eOperandType::Int16, value);
	}
	else
	{
		switch (static_cast<int>(op.getType()))
		{
			case eOperandType::Int32:
				stream << static_cast<int32_t>(this->getvalue()) - std::stoi(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Int32, value);
				break;
			case eOperandType::Float:
				stream << static_cast<float>(this->getvalue()) - std::stof(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Float, value);
				break;
			case eOperandType::Double:
				stream << static_cast<double>(this->getvalue()) - std::stod(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Double, value);
				break;
		}
	}
	delete tmp;
	return (ret);
}

IOperand 			*Int16::operator/(const IOperand &op) const
{
	Factory 		*tmp = new Factory();
	IOperand 		*ret;
	std::ostringstream 	stream;
	std::string 	value;

	if (std::stoi(op.toString()) == 0)
	{
		std::cerr << "Dividing by zero : Don't forget to throw exception" << std::endl;
		exit (84);
	}
	if (eOperandType::Int16 >= op.getType())
	{
		stream << this->getvalue() / static_cast<int16_t>(std::stoi(op.toString()));
		value = stream.str();
		ret = tmp->createOperand(eOperandType::Int16, value);
	}
	else
	{
		switch (static_cast<int>(op.getType()))
		{
			case eOperandType::Int32:
				stream << static_cast<int32_t>(this->getvalue()) / std::stoi(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Int32, value);
				break;
			case eOperandType::Float:
				stream << static_cast<float>(this->getvalue()) / std::stof(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Float, value);
				break;
			case eOperandType::Double:
				stream << static_cast<double>(this->getvalue()) / std::stod(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Double, value);
				break;
		}
	}
	delete tmp;
	return (ret);
}

IOperand 			*Int16::operator%(const IOperand &op) const
{
	Factory 		*tmp = new Factory();
	IOperand 		*ret;
	std::ostringstream 	stream;
	std::string 	value;

	if (std::stoi(op.toString()) == 0)
	{
		std::cerr << "Dividing by zero : Don't forget to throw exception" << std::endl;
		exit (84);
	}
	if (eOperandType::Int16 >= op.getType())
	{
		stream << this->getvalue() % static_cast<int16_t>(std::stoi(op.toString()));
		value = stream.str();
		ret = tmp->createOperand(eOperandType::Int16, value);
	}
	else
	{
		switch (static_cast<int>(op.getType()))
		{
			case eOperandType::Int32:
				stream << static_cast<int32_t>(this->getvalue()) % std::stoi(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Int32, value);
				break;
			case eOperandType::Float:
				std::string err = "Modulo float";
				throw ErrorHandler(err, new int(196))
				break;
			case eOperandType::Double:
				std::string err = "Modulo double";
				throw ErrorHandler(err, new int(196))

		}
	}
	delete tmp;
	return (ret);
}

IOperand 			*Int16::operator*(const IOperand &op) const
{
	Factory 		*tmp = new Factory();
	IOperand 		*ret;
	std::ostringstream 	stream;
	std::string 	value;

	if (eOperandType::Int16 >= op.getType())
	{
		stream << this->getvalue() * static_cast<int16_t>(std::stoi(op.toString()));
		value = stream.str();
		ret = tmp->createOperand(eOperandType::Int16, value);
	}
	else
	{
		switch (static_cast<int>(op.getType()))
		{
			case eOperandType::Int32:
				stream << static_cast<int32_t>(this->getvalue()) * std::stoi(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Int32, value);
				break;
			case eOperandType::Float:
				stream << static_cast<float>(this->getvalue()) * std::stof(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Float, value);
				break;
			case eOperandType::Double:
				stream << static_cast<double>(this->getvalue()) * std::stod(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Double, value);
				break;
		}
	}
	delete tmp;
	return (ret);
}

int16_t 					Int16::getvalue() const
{
	return (this->value);
}

void 					Int16::setvalue(void* val)
{
	int16_t 				*tmp;

	tmp = static_cast<int16_t*>(val);
	this->value = *tmp;
}


/* --------------------------- Int32 Function --------------------------- */

Int32::Int32()
{

}

std::string 		Int32::toString() const
{
	std::string 	ret;
	std::ostringstream 	stream;

	stream << this->value;
	ret = stream.str();
	return (ret);
}

eOperandType 		Int32::getType() const
{
	return (eOperandType::Int16);
}

IOperand 			*Int32::operator+(const IOperand &op) const
{
	Factory 		*tmp = new Factory();
	IOperand 		*ret;
	std::ostringstream 	stream;
	std::string 	value;

	if (eOperandType::Int32 >= op.getType())
	{
		stream << static_cast<int32_t>(std::stoi(op.toString())) + this->getvalue();
		value = stream.str();
		ret = tmp->createOperand(eOperandType::Int32, value);
	}
	else
	{
		switch (static_cast<int>(op.getType()))
		{
			case eOperandType::Float:
				stream << std::stof(op.toString()) + static_cast<float>(this->getvalue());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Float, value);
				break;
			case eOperandType::Double:
				stream << std::stod(op.toString()) + static_cast<double>(this->getvalue());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Double, value);
				break;
		}
	}
	delete tmp;
	return (ret);
}

IOperand 			*Int32::operator-(const IOperand &op) const
{
	Factory 		*tmp = new Factory();
	IOperand 		*ret;
	std::ostringstream 	stream;
	std::string 	value;

	if (eOperandType::Int32 >= op.getType())
	{
		stream << this->getvalue() - static_cast<int32_t>(std::stoi(op.toString()));
		value = stream.str();
		ret = tmp->createOperand(eOperandType::Int32, value);
	}
	else
	{
		switch (static_cast<int>(op.getType()))
		{
			case eOperandType::Float:
				stream << static_cast<float>(this->getvalue()) - std::stof(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Float, value);
				break;
			case eOperandType::Double:
				stream << static_cast<double>(this->getvalue()) - std::stod(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Double, value);
				break;
		}
	}
	delete tmp;
	return (ret);
}

IOperand 			*Int32::operator/(const IOperand &op) const
{
	Factory 		*tmp = new Factory();
	IOperand 		*ret;
	std::ostringstream 	stream;
	std::string 	value;

	if (std::stoi(op.toString()) == 0)
	{
		std::cerr << "Dividing by zero : Don't forget to throw exception" << std::endl;
		exit (84);
	}
	if (eOperandType::Int32 >= op.getType())
	{
		stream << this->getvalue() / static_cast<int32_t>(std::stoi(op.toString()));
		value = stream.str();
		ret = tmp->createOperand(eOperandType::Int32, value);
	}
	else
	{
		switch (static_cast<int>(op.getType()))
		{
			case eOperandType::Float:
				stream << static_cast<float>(this->getvalue()) / std::stof(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Float, value);
				break;
			case eOperandType::Double:
				stream << static_cast<double>(this->getvalue()) / std::stod(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Double, value);
				break;
		}
	}
	delete tmp;
	return (ret);
}

IOperand 			*Int32::operator%(const IOperand &op) const
{
	Factory 		*tmp = new Factory();
	IOperand 		*ret;
	std::ostringstream 	stream;
	std::string 	value;

	if (std::stoi(op.toString()) == 0)
	{
		std::cerr << "Dividing by zero : Don't forget to throw exception" << std::endl;
		exit (84);
	}
	if (eOperandType::Int32 >= op.getType())
	{
		stream << this->getvalue() % static_cast<int32_t>(std::stoi(op.toString()));
		value = stream.str();
		ret = tmp->createOperand(eOperandType::Int32, value);
	}
	else
	{
		switch (static_cast<int>(op.getType()))
		{
			case eOperandType::Float:
				std::string err = "Modulo float";
				throw ErrorHandler(err, new int(196))
				break;
			case eOperandType::Double:
				std::string err = "Modulo double";
				throw ErrorHandler(err, new int(196))
		}
	}
	delete tmp;
	return (ret);
}

IOperand 			*Int32::operator*(const IOperand &op) const
{
	Factory 		*tmp = new Factory();
	IOperand 		*ret;
	std::ostringstream 	stream;
	std::string 	value;

	if (eOperandType::Int32 >= op.getType())
	{
		stream << this->getvalue() * static_cast<int32_t>(std::stoi(op.toString()));
		value = stream.str();
		ret = tmp->createOperand(eOperandType::Int32, value);
	}
	else
	{
		switch (static_cast<int>(op.getType()))
		{
			case eOperandType::Float:
				stream << static_cast<float>(this->getvalue()) * std::stof(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Float, value);
				break;
			case eOperandType::Double:
				stream << static_cast<double>(this->getvalue()) * std::stod(op.toString());
				value = stream.str();
				ret = tmp->createOperand(eOperandType::Double, value);
				break;
		}
	}
	delete tmp;
	return (ret);
}

int32_t 					Int32::getvalue() const
{
	return (this->value);
}

void 					Int32::setvalue(void* val)
{
	int32_t 				*tmp;

	tmp = static_cast<int32_t*>(val);
	this->value = *tmp;
}


/* -------------------------- Float Function -------------------------------------- */

Float::Float()
{

}

std::string 		Float::toString() const
{
	std::string 	ret;
	std::ostringstream 	stream;

	stream << this->value;
	ret = stream.str();
	return (ret);
}

eOperandType 		Float::getType() const
{
	return (eOperandType::Float);
}

IOperand 			*Float::operator+(const IOperand &op) const
{
	Factory 		*tmp = new Factory();
	IOperand 		*ret;
	std::ostringstream 	stream;
	std::string 	value;

	if (eOperandType::Float >= op.getType())
	{
		stream << static_cast<float>(std::stof(op.toString())) + this->getvalue();
		value = stream.str();
		ret = tmp->createOperand(eOperandType::Float, value);
	}
	else
	{
		if (std::stoi(op.toString()) == eOperandType::Double)
		{
			stream << std::stod(op.toString()) + static_cast<double>(this->getvalue());
			value = stream.str();
			ret = tmp->createOperand(eOperandType::Double, value);
		}
	}
	delete tmp;
	return (ret);
}

IOperand 			*Float::operator-(const IOperand &op) const
{
	Factory 		*tmp = new Factory();
	IOperand 		*ret;
	std::ostringstream 	stream;
	std::string 	value;

	if (eOperandType::Float >= op.getType())
	{
		stream << this->getvalue() - static_cast<float>(std::stof(op.toString()));
		value = stream.str();
		ret = tmp->createOperand(eOperandType::Float, value);
	}
	else
	{
		if (op.getType() == eOperandType::Double)
		{
			stream << static_cast<double>(this->getvalue()) - std::stod(op.toString());
			value = stream.str();
			ret = tmp->createOperand(eOperandType::Double, value);
		}
	}
	delete tmp;
	return (ret);
}

IOperand 			*Float::operator/(const IOperand &op) const
{
	Factory 		*tmp = new Factory();
	IOperand 		*ret;
	std::ostringstream 	stream;
	std::string 	value;

	if (std::stoi(op.toString()) == 0)
	{
		std::cerr << "Dividing by zero : Don't forget to throw exception" << std::endl;
		exit (84);
	}
	if (eOperandType::Float >= op.getType())
	{
		stream << this->getvalue() / static_cast<float>(std::stof(op.toString()));
		value = stream.str();
		ret = tmp->createOperand(eOperandType::Float, value);
	}
	else
	{
		if (op.getType() == eOperandType::Double)
		{
			stream << static_cast<double>(this->getvalue()) / std::stod(op.toString());
			value = stream.str();
			ret = tmp->createOperand(eOperandType::Double, value);
		}
	}
	delete tmp;
	return (ret);
}

IOperand 			*Float::operator%(const IOperand &op) const
{
	std::string err = "Modulo float";
	throw ErrorHandler(err, new int(196))
	return (NULL);
}

IOperand 			*Float::operator*(const IOperand &op) const
{
	Factory 		*tmp = new Factory();
	IOperand 		*ret;
	std::ostringstream 	stream;
	std::string 	value;

	if (eOperandType::Float >= op.getType())
	{
		stream << this->getvalue() * static_cast<float>(std::stof(op.toString()));
		value = stream.str();
		ret = tmp->createOperand(eOperandType::Float, value);
	}
	else
	{
		if (op.getType() == eOperandType::Double)
		{
			stream << static_cast<double>(this->getvalue()) * std::stod(op.toString());
			value = stream.str();
			ret = tmp->createOperand(eOperandType::Double, value);
		}
	}
	delete tmp;
	return (ret);
}

float 					Float::getvalue() const
{
	return (this->value);
}

void 					Float::setvalue(void* val)
{
	float 				*tmp;

	tmp = static_cast<float*>(val);
	this->value = *tmp;
}


/* --------------------------------- Double Function ------------------------------- */

Double::Double()
{

}

std::string 		Double::toString() const
{
	std::string 	ret;
	std::ostringstream 	stream;

	stream << this->value;
	ret = stream.str();
	return (ret);
}

eOperandType 		Double::getType() const
{
	return (eOperandType::Double);
}

IOperand 			*Double::operator+(const IOperand &op) const
{
	Factory 		*tmp = new Factory();
	IOperand 		*ret;
	std::ostringstream 	stream;
	std::string 	value;

	stream << static_cast<double>(std::stod(op.toString())) + this->getvalue();
	value = stream.str();
	ret = tmp->createOperand(eOperandType::Double, value);

	delete tmp;
	return (ret);
}

IOperand 			*Double::operator-(const IOperand &op) const
{
	Factory 		*tmp = new Factory();
	IOperand 		*ret;
	std::ostringstream 	stream;
	std::string 	value;

	stream << this->getvalue() - static_cast<double>(std::stod(op.toString()));
	value = stream.str();
	ret = tmp->createOperand(eOperandType::Double, value);

	delete tmp;
	return (ret);
}

IOperand 			*Double::operator/(const IOperand &op) const
{
	Factory 		*tmp = new Factory();
	IOperand 		*ret;
	std::ostringstream 	stream;
	std::string 	value;

	if (std::stoi(op.toString()) == 0)
	{
		std::cerr << "Dividing by zero : Don't forget to throw exception" << std::endl;
		exit (84);
	}
	stream << this->getvalue() / static_cast<double>(std::stod(op.toString()));
	value = stream.str();
	ret = tmp->createOperand(eOperandType::Double, value);

	delete tmp;
	return (ret);
}

IOperand 			*Double::operator%(const IOperand &op) const
{
	std::string 	err = "Modulo with double";
	throw ErrorHandler(err, new int(943))
	return (NULL);
}

IOperand 			*Double::operator*(const IOperand &op) const
{
	Factory 		*tmp = new Factory();
	IOperand 		*ret;
	std::ostringstream 	stream;
	std::string 	value;

	stream << this->getvalue() * static_cast<double>(std::stod(op.toString()));
	value = stream.str();
	ret = tmp->createOperand(eOperandType::Double, value);

	delete tmp;
	return (ret);
}

double 					Double::getvalue() const
{
	return (this->value);
}

void 					Double::setvalue(void* val)
{
	double 				*tmp;

	tmp = static_cast<double*>(val);
	this->value = *tmp;
}
