#include <iostream>
#include <list>
#include <string>
namespace designPattern {
	namespace strategy{
		class FlyBehavior
		{
		public:
			virtual ~FlyBehavior() {};
			virtual void fly() = 0;
		};

		class FlyWithWings :public FlyBehavior {
		public:
			void fly() {
				std::cout << "FlyWithWings";
			}
		};
		class FlyWithNoWings :public FlyBehavior {
		public:
			void fly() {
				std::cout << "FlyWithNoWings";
			}
		};
		class Bird
		{
		public:
			void Quake() {
				std::cout << "quake!quake!quake!";
			}
			virtual void Fly() {
				pFlyBehavior->fly();
			}
			Bird(FlyBehavior* p_FlyBehavior) :pFlyBehavior(p_FlyBehavior)
			{}
			virtual ~Bird() {
				delete pFlyBehavior;
			}
		private:
			FlyBehavior* pFlyBehavior;
		};

		class Duck :public Bird
		{
		public:
			~Duck() {};
			Duck(FlyBehavior* p_FlyBehavior = new FlyWithWings) :Bird(p_FlyBehavior) {

			}
		};
		class Penguin :public Bird
		{
		public:
			~Penguin() {};
			Penguin(FlyBehavior* p_FlyBehavior = new FlyWithNoWings) :Bird(p_FlyBehavior) {

			}
		};
	}
	namespace observe {
		class Oberse {
		public:
			virtual void update() = 0;
		};
		class Subject {
		private:
			std::list<Oberse*> Observers;
		public:
			void registerObserver(Oberse* myObser) {
				Observers.emplace_back(myObser);
			}
			void unRegisterObserver(Oberse* myObser) {
				Observers.remove(myObser);
			}
			void Update() {

				for (auto iter = Observers.begin(); iter != Observers.end(); iter++) {
					(*iter)->update();
				}


			}

		};


		class Licheng :public Oberse {
		public:

			void update() {
				std::cout << "Li accept" << std::endl;
			}
		};
		class LiWei :public Oberse {
		public:
			void update() {
				std::cout << "LiWei accept" << std::endl;
			}
		};
		class Poem :public Oberse {
		public:
			void update() {
				std::cout << "Poem accept" << std::endl;
			}
		};
	}
	namespace decorate {
		class beverage {
		public:
			virtual std::string getDescribe() = 0;
		protected:
			std::string mystring = "beverage";
		};

		class juice :public beverage {
		public:
			std::string getDescribe() {
				return mystring;
			}
			juice() {
				mystring = "juice";
			}
		};

		class addition :public beverage {
		protected:
			beverage* pbeverage;
		public:
			virtual std::string getDescribe() = 0;
		};

		class milk :public addition {
		public:
			std::string getDescribe() {
				return pbeverage->getDescribe() + "milk";
			}
			milk(beverage* myb){
				pbeverage = myb;
			}
		};
	}
	namespace singleton {
		class Singleton {
		private:
			Singleton() {
				std::cout << "constrµ÷ÓÃ"<<this;
			};
		public:
			static Singleton* Instance;
			static Singleton* getSingleton() {
				if (Instance == NULL) {
					Instance = new Singleton;
				}
				return Instance;
			}
		};


	}
	namespace adapt {
		class Duck {
		public:
			virtual void quake() = 0;
			virtual void fly() = 0;
		};

		class DuckIn :public Duck {
		public:
			void quake() {
				std::cout << "q q q" << std::endl;
			}
			void fly() {
				std::cout << "i'm fly" << std::endl;
			}
		};

		class Chiken {
		public:
			void speak() {
				std::cout << "s s s" << std::endl;
			};
			void fly() {
				std::cout << "i can't fly" << std::endl;
			}
 
		};

		class DuckAdapt :public Duck {
		public:
			DuckAdapt(Chiken* pchiken):chiken(pchiken){}
			void quake() {
				chiken->speak();
			}
			void fly() {
				chiken->fly();
			}
			~DuckAdapt() {
				delete  chiken;
			}
		private:
			Chiken* chiken;
		};
	}
	namespace templatemode {
		class Process {
		public:
			virtual void  prepare() final {
				work1();
				work2();
				if (hookofwork3()) {
					work3();
				}
			}
			void work1() {
				std::cout << "work1" << std::endl;
			}
			virtual void work2() = 0;
			void work3() {
				std::cout << "work3" << std::endl;
			}
			virtual bool hookofwork3() {
				return false;
			}
		};

		class ConcreteProcess :public Process {
		public:
			void work2() {
				std::cout << "work2" << std::endl;
			}
			bool hookofwork3() {
				return true;
			}
		};
	}
}