#pragma once
class Test
{
public:
	
	~Test();
	static void funcTest();
private:
	int varTest;
	Test(int n);
};

class TestChild : public Test
{
public:
	TestChild();
	~TestChild();
	void funcTestChild();
};

