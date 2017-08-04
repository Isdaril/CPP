// Euler155.cpp : définit le point d'entrée pour l'application console.
//

// Euler155.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Euler155.h"
#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>


//using namespace std;
/*const int standardCapacity = 60;

//Node
Node::Node() {
	this->myFather = NULL;
}

Node* Node::getFather() {
	return this->myFather;
}

void Node::setFather(Node* node) {
	this->myFather = node;
}

//Capacitor
Capacitor::Capacitor(int capacity) : Node() {
	this->capacity = capacity;
}

Capacitor::Capacitor(Node& node) {
	this->setFather(node.getFather);
	this->capacity = node.getCapacity();
}

std::string Capacitor::toString() {
	return std::to_string(this->capacity);
}

std::vector<Node*> Capacitor::addACapacitor(int capacity) {
	std::vector<Node*> result;
	ComplexNode* parNode = new ComplexNode(PARALLEL);
	ComplexNode* serNode = new ComplexNode(SERIAL);
	if (this->getFather() == NULL) {
		//ComplexNode* parNode = new ComplexNode(NULL, PARALLEL);
		Capacitor* copyNode = new Capacitor(*this);
		copyNode->setFather(parNode);
		//parNode->addNode(copyNode);
		//parNode->addNode(&Capacitor(parNode, capacity));
		//result.push_back(parNode);
		//ComplexNode* serNode = new ComplexNode(NULL, SERIAL);
		Capacitor* anOtherCopyNode(this);
		anOtherCopyNode->setFather(serNode);
		serNode->addNode(anOtherCopyNode);
		serNode->addNode(anOtherCopyNode);
		serNode->addNode(&Capacitor(serNode, capacity));
		result.push_back(serNode);
	}
	else {
		ComplexNode *fatherNode = dynamic_cast<ComplexNode*> (this->getFather());
		if (fatherNode->getType() == SERIAL) {
			ComplexNode* parNode = new ComplexNode(this->getFather(), PARALLEL);
			parNode->addNode(this);
			parNode->addNode(&Capacitor(parNode, capacity));
			result.push_back(parNode);
		}
		else {
			ComplexNode serNode(this->getFather(), SERIAL);
			serNode.addNode(this);
			serNode.addNode(&Capacitor(&serNode, capacity));
			result.push_back(&serNode);
		}
	}
	return result;
}

int Capacitor::getCapacity() {
	return this->capacity;
}

bool Capacitor::isSimple() {
	return true;
}

int Capacitor::getSize() {
	return 1;
}

//ComplexNode
ComplexNode::ComplexNode(Node_Type_t type) : Node(myFather) {
	this->type = type;
}
std::string ComplexNode::toString() {
	std::string result;
	result += '(';
	int size = this->getSize();
	for (int i = 0; i < size; i++) {
		if (i == size - 1) result += this->getNodes()[i]->toString() + ")";
		else {
			if (this->getType() == SERIAL) {
				result += this->getNodes()[i]->toString() + " + ";
			}
			else {
				result += this->getNodes()[i]->toString() + " * ";
			}
		}

	}
	return result;
}

Node_Type_t ComplexNode::getType() {
	return this->type;
}

std::vector<Node*> ComplexNode::getNodes() {
	return this->nodes;
}

int ComplexNode::getCapacity() {
	return 0;
}

void ComplexNode::addNode(Node* node) {
	this->nodes.push_back(node);
}

bool ComplexNode::isSimple() {
	return false;
}

int ComplexNode::getSize() {
	return int(nodes.size());
}

std::vector<Node*> ComplexNode::addACapacitor(int capacity) {
	std::vector<Node*> result;
	if (this->getFather() == NULL) {
		if (this->getType() == SERIAL) {
			ComplexNode parNode(NULL, PARALLEL);
			parNode.addNode(this);
			parNode.addNode(&Capacitor(&parNode, capacity));
			ComplexNode serNode = *this;
			serNode.addNode(&Capacitor(&serNode, capacity));
			result.push_back(&parNode);
			result.push_back(&serNode);
		}
		else {
			ComplexNode serNode(NULL, SERIAL);
			serNode.addNode(this);
			serNode.addNode(&Capacitor(&serNode, capacity));
			ComplexNode parNode = *this;
			parNode.addNode(&Capacitor(&parNode, capacity));
			result.push_back(&parNode);
			result.push_back(&serNode);
		}
	}
	else {
		ComplexNode newNode = *this;
		newNode.addNode(&Capacitor(this, capacity));
		result.push_back(&newNode);
	}
	std::vector<Node*> result = Node::addACapacitor(capacity);
	std::vector<Node*> tmpList;
	std::vector<Node*>::iterator iterNodes;
	std::vector<Node*>::iterator iterCreatedNodes;
	int curSize = 0;
	int n = this->getSize();
	for (int i = 0; i < n; i++) {
		if (i != 0 && this->nodes[i]->getSize() < curSize) {
			tmpList = this->nodes[i]->addACapacitor(capacity);
			for (iterNodes = tmpList.begin(); iterNodes < tmpList.end(); iterNodes++) {
				ComplexNode newNode = *this;
				newNode.getNodes()[i] = *iterNodes;
				result.push_back(&newNode);
			}
			curSize = this->nodes[i]->getSize();
		}
		else break;
	}
	return result;
}

std::vector<Node*> findNodes(int n) {
	std::vector<Node*> result;
	std::vector<Node*> circuits;
	if (n == 1) {
		Capacitor node = Capacitor(NULL, standardCapacity);
		result.push_back(&node);
		return result;
	}
	circuits = findNodes(n - 1);
	std::vector<Node*>::iterator it;
	for (it = circuits.begin(); it < circuits.end(); it++) {
		std::vector<Node*> tmpList = dynamic_cast<Node*>(*it)->addACapacitor(standardCapacity);
		result.insert(result.end(), tmpList.begin(), tmpList.end());
	}
	return result;
}

std::vector<Node*> findAllNodes(int n) {
	std::vector<Node*> result;
	for (int i = 0; i < n; i++) {
		std::vector<Node*> tmpList = findNodes(i);
		result.insert(result.end(), tmpList.begin(), tmpList.end());
	}
	return result;
}

std::string printVector(std::vector<Node*> v) {
	size_t size = v.size();
	std::string result;
	for (int i = 0; i < size; i++) {
		result += v[i]->toString() + '\n';
	}
	return result;
}
*/
int main() {
	//std::vector<Node*> nodesFound = findNodes(1);
	//std::vector<Node*> nodesFound;
	//Capacitor aSimpleNode(NULL, standardCapacity);
	//nodesFound = aSimpleNode.addACapacitor(standardCapacity);
	/*ComplexNode newNode(NULL, SERIAL);
	newNode.addNode(&Capacitor(&newNode,standardCapacity));
	newNode.addNode(&Capacitor(&newNode, standardCapacity));
	nodesFound.push_back(&newNode);
	ComplexNode anOtherNewNode = ComplexNode(NULL, PARALLEL);
	anOtherNewNode.addNode(&Capacitor(&anOtherNewNode, standardCapacity));
	anOtherNewNode.addNode(&Capacitor(&anOtherNewNode, standardCapacity));
	nodesFound.push_back(&anOtherNewNode);
	nodesFound.push_back(&Capacitor(NULL, standardCapacity));*/

	//std::cout << printVector(nodesFound);
	return 0;
}



