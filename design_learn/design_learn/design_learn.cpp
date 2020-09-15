// design_learn.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "strategy.cpp"
#include "sharedptr.cpp"
using namespace designPattern::singleton;
Singleton* Singleton::Instance = NULL;

class mytest {
public:
	virtual void test() final {}
};
int main()
{
	//using namespace designPattern::strategy;
	//Bird* myDuck = new Duck;
	//myDuck->Quake();
	//myDuck->Fly();
	//Bird* myPeng = new Penguin;
	//myPeng->Quake();
	//myPeng->Fly();

	//using namespace designPattern::observe;
	//Subject mysub;
	//Oberse* o1 = new Licheng();
	//Oberse* o2 = new LiWei();
	//Oberse* o3 = new Poem();
	//mysub.registerObserver(o1);
	//mysub.registerObserver(o2);
	//mysub.registerObserver(o3);
	//mysub.Update();

	//using namespace designPattern::decorate;
	//std::cout << milk(&milk(new juice)).getDescribe();

	//Singleton* p = Singleton::getSingleton();
	//std::cout << std::endl;
	//Singleton* p1= Singleton::getSingleton();

	//using namespace designPattern::adapt;
	//DuckAdapt* myadpt = new DuckAdapt(new Chiken);
	//myadpt->quake();
	//using namespace designPattern::templatemode;
	//Process* myp = new ConcreteProcess;
	//myp->prepare();

	//std::cout << sizeof(mytest) << std::endl;
	//std::shared_ptr<A> pa(new A());
	//std::shared_ptr<B> pb(new B());
	//std::cout << pa.use_count() << std::endl;
	//std::cout << pb.use_count() << std::endl;
	//pa->pb = pb;
	//pb->pa = pa;
	//std::cout << pa.use_count() << std::endl;
	//std::cout << pb.use_count() << std::endl;
	const char* p = "123457";
	char a[] = "123";
	std::cout << sizeof(p) << std::endl;
	std::cout << sizeof(a) << std::endl;
}


