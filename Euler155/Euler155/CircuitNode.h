#pragma once
#include <memory>

class CircuitNode
{
private:
	CircuitComplexNode myFather;

public:
	CircuitNode();
	~CircuitNode();
	virtual int getCapacity() = 0;
	virtual std::string toString() = 0;
	virtual int getSize() = 0;
};

