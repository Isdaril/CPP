#include "stdafx.h"
#include <utility>

#include "CircuitBuilder.h"

CircuitBuilder::CircuitBuilder()
{
	root = CircuitComplexNode();
}

CircuitBuilder CircuitBuilder::withType(Node_Type_t type)
{
	root.type = type;
	return *this;
}

CircuitBuilder CircuitBuilder::withFather(CircuitComplexNode father)
{
	root.myFather = father;
	return *this;
}

CircuitBuilder CircuitBuilder::withComplexNode(CircuitComplexNode node)
{
	std::unique_ptr<CircuitNode> child_node = std::make_unique<CircuitComplexNode>(node);
	root.addNode(std::move(child_node));
	return CircuitBuilder();
}

CapacitorBuilder CircuitBuilder::withCapacitor()
{

	return CapacitorBuilder(root);
}

CircuitBuilder::operator CircuitComplexNode()
{
}

CapacitorBuilder CapacitorBuilder::withCapacity(int capacity)
{
	return CapacitorBuilder();
}

CapacitorBuilder CapacitorBuilder::withFather(CircuitComplexNode father)
{
	return CapacitorBuilder();
}
