#if 0
#include<iostream>
using namespace std;
class abstractDrink {     //������Ʒ�Ļ���
public:
	//3������-----���麯��
	virtual void boolwater() = 0;  //��ˮ
	virtual void brew() = 0;       //����
	virtual void addsth() = 0;     //����
	//����
	void makeDrink() {
		boolwater();
		brew() ;
		addsth() ;
	}
};

class coffee :public abstractDrink {
public:
	void boolwater() {
		cout << "��һ����Ȫˮ" << endl;
	}
	void brew() {
		cout << "���ݿ���" << endl;
	}
	void addsth() {
		cout << "�����Ǻ�ţ��" << endl;
	}
};

class tea :public abstractDrink {
public:
	void boolwater() {
		cout << "��һ����Ȫˮ" << endl;
	}
	void brew() {
		cout << "���ݲ�Ҷ" << endl;
	}
	void addsth() {
		cout << "�������" << endl;
	}
};
void doWork(abstractDrink& p) {             //�˴��������á�����ָ�룬ֻҪ�������ã�ָ��������
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