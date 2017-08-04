#pragma once
#include <string>
#include "CircuitNode.h"
class CircuitCapacitor :
	public CircuitNode
{
private:
	int capacity;
public:
	//constructors and destructors
	CircuitCapacitor();
	~CircuitCapacitor();
	CircuitCapacitor(int capacity) : capacity(capacity) {}
	//implements interface CircuitNode
	virtual int getCapacity();
	virtual std::string toString();
	virtual int getSize();
};

