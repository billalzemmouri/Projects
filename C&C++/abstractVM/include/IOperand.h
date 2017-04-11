#ifndef IOPERAND_H_
# define IOPERAND_H_

#include <string>
#include <sstream>
#include "../include/ErrorHandler.hh"

# define INT8_MIN_LIM -128
# define INT8_MAX_LIM 127

# define INT16_MAX_LIM 32767
# define INT16_MIN_LIM -32768

# define INT32_MIN_LIM -2147483648
# define INT32_MAX_LIM 2147483647 

enum 		eOperandType
{
	Int8 = 0,
	Int16 = 1,
	Int32 = 2, 
	Float = 3,
	Double = 4,
	BigDecimal = 5,
};

class 		IOperand
{
public:
	virtual std::string 	toString() const = 0;
	virtual eOperandType 	getType()  const = 0;
	virtual IOperand 		*operator+(const IOperand &) const = 0;
	virtual IOperand 		*operator-(const IOperand &) const = 0;
	virtual IOperand 		*operator*(const IOperand &) const = 0;
	virtual IOperand 		*operator/(const IOperand &) const = 0;
	virtual IOperand 		*operator%(const IOperand &) const = 0;
	virtual void 			setvalue(void *) = 0;
	virtual 				~IOperand() {}
};


#endif /* !IOPERAND_H_ */
