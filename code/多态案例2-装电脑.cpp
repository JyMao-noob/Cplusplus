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
	PC(CPU& a, GPU& b, RAM& c) {
		m_cpu = &a;
		m_gpu = &b;
		m_ram = &c;

	}
	//���Խ��й���
	void work() {
		m_cpu->count();
		m_gpu->display();
		m_ram->storage();
	}
private:
	//��ָ�뷽ʽ����3����Ա����
	CPU *m_cpu;
	GPU *m_gpu;
	RAM *m_ram;
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
		//����Ϊ��ѡ���
	IU i7;	
	AU x3700;
	Nvidia rtx2080;
	AMD r580;
	Asus ddr4;
	WG ddr3;
	PC pc1(i7,r580,ddr4), pc2(x3700,rtx2080,ddr3);
	//��ʼ��װ
	pc1.work();
	cout << "---------------------" << endl;
	pc2.work();
}
int main() {
	test();
	system("pause");
	return 0;
}
#endif