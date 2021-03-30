#include <iostream>
using namespace std;

class Interface
{
public:
	virtual ~Interface(){}
	virtual void test() = 0;
};

class Main
{
public:
	Main(Interface* i) :_interface(i){}
	~Main() {
		cout << "delete\n";
		delete _interface; 
	}

	void update() {
		_interface->test();
	}

	void change(Interface* i) {
		_interface = i;
	}
private:
	Interface* _interface;
};

class A : public Interface {
public:
	virtual void test()override
	{
		cout << "A\n";
	}
};

class B : public Interface {
public:
	virtual void test()override
	{
		cout << "B\n";
	}
};


int main()
{
	Main a(new A);
	a.update();
	a.change(new B);
	a.update();
}
