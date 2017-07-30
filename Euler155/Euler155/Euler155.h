#pragma once
#include <vector>

typedef enum Node_Type_t {
	PARALLEL = 0, 
	SERIAL = 1
};

class Node {
private:
	Node* myFather;
public:
	Node();
	Node* getFather();
	void setFather(Node* node);
	virtual bool isSimple() = 0;
	virtual int getCapacity() = 0;
	virtual std::vector<Node*> addACapacitor(int capacity) = 0;
	virtual int getSize() = 0;
	virtual std::string toString() = 0;
};

class Capacitor : public Node {
private:
	int capacity;
public:
	Capacitor(int capacity);
	Capacitor(Node& node);
	virtual bool isSimple();
	int getCapacity();
	virtual int getSize();
	virtual std::vector<Node*> addACapacitor(int capacity);
	virtual std::string toString();
	//virtual std::vector<Node*> addACapacitor(int capacity);
};

class ComplexNode : public Node {
private:
	std::vector<Node*> nodes;
	Node_Type_t type;
public:
	ComplexNode(Node_Type_t type);
	ComplexNode(Node& node);
	virtual bool isSimple();
	Node_Type_t getType();
	std::vector<Node*> getNodes();
	int getCapacity();
	void addNode(Node* node);
	virtual std::vector<Node*> addACapacitor(int capacity);
	virtual int getSize();
	virtual std::string toString();
};