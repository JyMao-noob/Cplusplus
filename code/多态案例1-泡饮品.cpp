#if 0
#include<iostream>
using namespace std;
class abstractDrink {     //抽象饮品的基类
public:
	//3个步骤-----纯虚函数
	virtual void boolwater() = 0;  //烧水
	virtual void brew() = 0;       //冲泡
	virtual void addsth() = 0;     //加料
	//流程
	void makeDrink() {
		boolwater();
		brew() ;
		addsth() ;
	}
};

class coffee :public abstractDrink {
public:
	void boolwater() {
		cout << "烧一杯矿泉水" << endl;
	}
	void brew() {
		cout << "冲泡咖啡" << endl;
	}
	void addsth() {
		cout << "加入糖和牛奶" << endl;
	}
};

class tea :public abstractDrink {
public:
	void boolwater() {
		cout << "烧一杯矿泉水" << endl;
	}
	void brew() {
		cout << "冲泡茶叶" << endl;
	}
	void addsth() {
		cout << "加入枸杞" << endl;
	}
};
void doWork(abstractDrink& p) {             //此处可以引用、可以指针，只要基类引用（指向）派生类
	p.makeDrink();
}
void test(){
	coffee cup1;	
	doWork(cup1);
	cout << "---------------------" << endl;	
	tea cup2;
	doWork(cup2);
}
int main() {
	test();
	system("pause");
	return 0;
}
#endif