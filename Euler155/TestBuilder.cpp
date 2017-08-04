// TestBuilder.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <memory>
#include <utility>

using namespace std;

class Builder;
class Object {
	friend class Builder;
	string name;
	vector<shared_ptr<Object>> elements;
public:
	Object() : 
		name(),
		elements()
	{}
	Object(string name) : 
		name(name),
		elements()
	{}
	void addChild(Object child) {
		shared_ptr<Object> crPtr = make_shared<Object>(child);
		elements.push_back(crPtr);
	}
	string to_string() {
		string result = "<";
		result += name + ">\n";
		vector<shared_ptr<Object>>::iterator it;
		for (it = elements.begin(); it < elements.end(); it = next(it) ){
			result += (*it)->to_string();
		}
		result += "</" + name + ">\n";
		return result;
	}
	static Builder Build();
};

class Builder {
	Object root;
public:
	Builder() {
		root = Object();
	}

	Builder withName(string name) {
		root.name = name;
		return *this;
	}
	Builder withChild(Object child) {
		root.addChild(child);
		return *this;
	}

	operator Object() { return root; }
};

Builder Object::Build() {
	return Builder();
}

int main() {

	Builder test2 = Builder().withName("test2");
	Object test = Object::Build().withName("test");
	Object test1 = Object::Build().withName("test1").withChild(test);


	Object obj = Object::Build().withName("truc").withChild(Object::Build().withName("machin").withChild(Object::Build().withName("bidule")));

	cout << obj.to_string();
	return 0;
}
