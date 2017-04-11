#ifndef OPERANDCLASSES_H_
# define OPERANDCLASSES_H_

#include "../include/IOperand.h"


class 		Int8 : public IOperand
{
	int8_t 	value;

public:
	Int8();
	virtual ~Int8(){};
	virtual std::string 	toString() const;
	virtual eOperandType 	getType()  const;
	virtual IOperand 		*operator+(const IOperand &) const;
	virtual IOperand 		*operator-(const IOperand &) const;
	virtual IOperand 		*operator*(const IOperand &) const;
	virtual IOperand 		*operator/(const IOperand &) const;
	virtual IOperand 		*operator%(const IOperand &) const;
	int8_t 					getvalue() const;
	void 					setvalue(void*);
};

class 		Int16 : public IOperand
{
	int16_t 	value;

public:
	Int16();
	virtual ~Int16(){};
	virtual std::string 	toString() const;
	virtual eOperandType 	getType()  const;
	virtual IOperand 		*operator+(const IOperand &) const;
	virtual IOperand 		*operator-(const IOperand &) const;
	virtual IOperand 		*operator*(const IOperand &) const;
	virtual IOperand 		*operator/(const IOperand &) const;
	virtual IOperand 		*operator%(const IOperand &) const;
	int16_t 				getvalue() const;
	void 					setvalue(void*);
};

class 		Int32 : public IOperand
{
	int32_t 	value;

public:
	Int32();
	virtual ~Int32(){};
	virtual std::string 	toString() const;
	virtual eOperandType 	getType()  const;
	virtual IOperand 		*operator+(const IOperand &) const;
	virtual IOperand 		*operator-(const IOperand &) const;
	virtual IOperand 		*operator*(const IOperand &) const;
	virtual IOperand 		*operator/(const IOperand &) const;
	virtual IOperand 		*operator%(const IOperand &) const;
	int32_t 				getvalue() const;
	void 					setvalue(void*);
};

class 		Float : public IOperand
{
	float 	value;

public:
	Float();
	virtual ~Float(){};
	virtual std::string 	toString() const;
	virtual eOperandType 	getType()  const;
	virtual IOperand 		*operator+(const IOperand &) const;
	virtual IOperand 		*operator-(const IOperand &) const;
	virtual IOperand 		*operator*(const IOperand &) const;
	virtual IOperand 		*operator/(const IOperand &) const;
	virtual IOperand 		*operator%(const IOperand &) const;
	float 					getvalue() const;
	void 					setvalue(void*);

};

class 		Double : public IOperand
{
	double 	value;

public:
	Double();
	virtual ~Double(){};
	virtual std::string 	toString() const;
	virtual eOperandType 	getType()  const;
	virtual IOperand 		*operator+(const IOperand &) const;
	virtual IOperand 		*operator-(const IOperand &) const;
	virtual IOperand 		*operator*(const IOperand &) const;
	virtual IOperand 		*operator/(const IOperand &) const;
	virtual IOperand 		*operator%(const IOperand &) const;
	double 					getvalue() const;
	void 					setvalue(void*);
};


#endif /* !OPERANDCLASSES_H_ */