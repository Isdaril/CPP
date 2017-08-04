#pragma once
#include <vector>
#include "CircuitNode.h"

typedef enum Node_Type_t {
	PARALLEL = 0,
	SERIAL = 1
};

class CircuitComplexNode : public CircuitNode
{
private:
	friend class CircuitBuilder;
	std::vector<std::shared_ptr<CircuitNode>> nodes;
	Node_Type_t type;
public:
	//constructors and desctructors
	CircuitComplexNode();
	~CircuitComplexNode();
	CircuitComplexNode(Node_Type_t type) : nodes(), type(type) {}
	//function unique to ComplexNode that adds a node to the end of its list of nodes
	void addNode(std::unique_ptr<CircuitNode> node);
	//implements interface CircuitNode
	virtual int getCapacity();
	virtual std::string toString();
	virtual int getSize();
};

