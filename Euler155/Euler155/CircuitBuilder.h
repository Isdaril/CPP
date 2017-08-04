#pragma once
#include <memory>
#include "Euler155.h"
#include "CircuitNode.h"
#include "CircuitCapacitor.h"
#include "CircuitComplexNode.h"


class CircuitBuilder {
	CircuitComplexNode root;
protected:
	CircuitComplexNode& circuit;
	CircuitBuilder(CircuitComplexNode& node) : circuit(node) {}
public:
	CircuitBuilder() : circuit(root) {}
	CircuitBuilder withType(Node_Type_t type);
	CircuitBuilder withFather(CircuitComplexNode father);
	CircuitBuilder withComplexNode(CircuitComplexNode node);
	CapacitorBuilder withCapacitor();
	operator CircuitComplexNode();	
};


class CapacitorBuilder : public CircuitBuilder {
public:
	CapacitorBuilder(CircuitComplexNode node) : CircuitBuilder(node) {}
	CapacitorBuilder withCapacity(int capacity);
	CapacitorBuilder withFather(CircuitComplexNode father);
};

