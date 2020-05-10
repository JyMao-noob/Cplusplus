#if 0
#include<iostream>
#include<string>
using namespace std;
//����cpu��gpu��ram3�����࣬�����Զ���ʵ�ֹ��ܵĴ��麯��
class CPU {
public:
	virtual void count() = 0;               //����
};
class GPU {
public:
	virtual void display() = 0;             //��ʾ
};
class RAM {
public:
	virtual void storage() = 0;            //�洢
};
//���������࣬����cpu��gpu��ram������Ա����
class PC {
public:
	//���Խ��й���
	void work(CPU &a,GPU &b,RAM &c) {
		a.count();
		b.display();
		c.storage();
	}
private:
	//��ָ�뷽ʽ����3����Ա����
	CPU* m_cpu;
	GPU* m_gpu;
	RAM* m_ram;
};
//������3�������������
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
	//����Ϊ��ѡ���
	IU i7;	
	AU x3700;
	Nvidia rtx2080;
	AMD r580;
	Asus ddr4;
	WG ddr3;
	//��ʼ��װ
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