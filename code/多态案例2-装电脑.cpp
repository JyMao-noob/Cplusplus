#if 0
#include<iostream>
#include<string>
using namespace std;
//创建cpu、gpu、ram3个基类，并各自定义实现功能的纯虚函数
class CPU {
public:
	virtual void count() = 0;               //计算
};
class GPU {
public:
	virtual void display() = 0;             //显示
};
class RAM {
public:
	virtual void storage() = 0;            //存储
};
//创建电脑类，包含cpu、gpu、ram三个成员属性
class PC {
public:
	//电脑进行工作
	void work(CPU &a,GPU &b,RAM &c) {
		a.count();
		b.display();
		c.storage();
	}
private:
	//以指针方式创建3个成员属性
	CPU* m_cpu;
	GPU* m_gpu;
	RAM* m_ram;
};
//以下由3个基类进行派生
class IU :public CPU {
public:
	void count() {
		cout << "intel cpu is working." << endl;
	 }
};
class AU :public CPU {
public:
	void count() {
		cout << "amd cpu is working." << endl;
	}
};
class Nvidia :public GPU {
public:
	void display() {
		cout << "Nvidia gpu is displaying." << endl;
	}
};
class AMD :public GPU {
public:
	void display() {
		cout << "AMD gpu is displaying." << endl;
	}
};
class Asus :public RAM {
public:
	void storage() {
		cout << "Asus ram is storaging" << endl;
	}
};
class WG :public RAM {
public:
	void storage() {
		cout << "WG ram is storaging" << endl;
	}
};

void test() {
	PC pc1,pc2;
	//以下为可选配件
	IU i7;	
	AU x3700;
	Nvidia rtx2080;
	AMD r580;
	Asus ddr4;
	WG ddr3;
	//开始组装
	pc1.work(i7, rtx2080, ddr3);
	cout << "---------------------" << endl;
	pc2.work(x3700, r580, ddr4);
}
int main() {
	test();
	system("pause");
	return 0;
}
#endif