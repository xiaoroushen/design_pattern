#include <memory>
#include <iostream>
class A;
class B;
class A
{
public:
	std::weak_ptr<B> pb;
	~A() {
		std::cout << "����A����";
	}

};

class B
{
public:
	std::shared_ptr<A> pa;
	~B() {
		std::cout << "����B����";
	}
};


