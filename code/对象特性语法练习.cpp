#if 0
#include<iostream>
#include<string>
using namespace std;
class Person {
public:
	int m_Age;
	int* m_Height;
	Person() {
		cout << "������޲ι��캯��." << endl;
	}

	Person(int age, int height) {
		cout << "������вι��캯��." << endl;
		m_Age = age;
		m_Height = new int(height);
	}

	Person(const Person& p) {
		cout << "����˿������캯��." << endl;
		m_Age = p.m_Age;
		m_Height = new int(*p.m_Height);    //���
	}
	~Person() {
		if (m_Height != NULL) {
			delete m_Height;
			m_Height = NULL;
		}
		cout << "�������������." << endl;
	}
};

void test() {
	Person p1(18,175);
	Person p2(p1);
	cout << p2.m_Age << endl;
	cout << *p2.m_Height << endl;


}
int main() {

	test();
	system("pause");
	return 0;
}
#endif

#if 0
#include<iostream>
#include<string>
using namespace std;
class Phone {
public:
	string P_number;
	Phone(){ cout << "Phone�޲ι���" << endl; }
	Phone(string num) {
		P_number = num;
		cout << "Phone�вι���" << endl;
	}
	~Phone() {
		cout << "Phone��������" << endl;
	}
};
class Person {
public:
	string m_name;
	Phone m_number;
	Person(string name, string number) {   //����Բ��ó�ʼ���б���:m_name(name),m_number(number)
		m_name =name;
		m_number=number;
		cout << "Person�вι���" << endl;
	}
	~Person() {
		cout << "Person��������" << endl;
	}
	void func() {
		cout << m_name << "���ֻ����ǣ�" << m_number.P_number << endl;		
	}
};

void test() {
	Person p1("����","123456789");
	p1.func();
}
int main() {
	test();
	system("pause");
	return 0;
}
#endif

#if 0
#include<iostream>
#include<string>
using namespace std;
class Person {
public:
	static int m_A;
	int m_B;
	static void func()                       //��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
	{
		cout << "func����" << endl;
		m_A = 100;
		//m_B = 100; //���󣬲����Է��ʷǾ�̬��Ա����
	}
	
};

int Person::m_A = 18;      //ע��Ҫ��������Person::
int main() {
	Person p;
	cout << p.m_A << endl;
	Person p2;
	p2.m_A = 20;
	cout << p.m_A << endl;
	Person::func();                   //ͨ���������ʳ�Ա��̬����
	cout << Person::m_A << endl;      //Ҳ���Բ��ö���p1��p2��ֱ��ͨ����������
	system("pause");
	return 0;
}
#endif

#if 0
#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
	Person(int age)
	{		//1�����βκͳ�Ա����ͬ��ʱ������thisָ��������
		this->age = age;     //��Ȼ�������֣�����ͬ���Ǹ���ϰ��
	}
	Person& PersonAddPerson(Person p)               //����˼�룬ע����Person&  �����ã�����
	{
		this->age += p.age;
		//���ض�����
		return *this;
	}
	int age;
};
void test01()
{	Person p1(10);
	cout << "p1.age = " << p1.age << endl;
	Person p2(10);
	p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);    //����˼��
	cout << "p2.age = " << p2.age << endl;
	}
int main() {
    test01();
	system("pause");
	return 0;
}
#endif

#if 0
#include<iostream>
#include<string>
using namespace std;
class Person {
public:
	Person() {
		m_A = 0;
		m_B = 0;
	}
	//thisָ��ı�����һ��ָ�볣����ָ���ָ�򲻿��޸�
	//�������ָ��ָ���ֵҲ�������޸ģ���Ҫ����������
	void ShowPerson() const {                                     //const���γ�Ա����
		//const Type* const pointer;
		//this = NULL; //�����޸�ָ���ָ�� Person* const this;
		//this->mA = 100; //����thisָ��ָ��Ķ���������ǿ����޸ĵ�
		//const���γ�Ա��������ʾָ��ָ����ڴ�ռ�����ݲ����޸ģ�����mutable���εı���
		this->m_B = 100;
	}
	void MyFunc()  {
		//mA = 10000;
	}
public:
	int m_A;
	mutable int m_B; //���޸� �ɱ��
};
//const���ζ���  ������
void test01() {
	const Person person; //��������  
	cout << person.m_A << endl;
	//person.mA = 100; //���������޸ĳ�Ա������ֵ,���ǿ��Է���
	person.m_B = 100; //���ǳ���������޸�mutable���γ�Ա����
	//��������ʳ�Ա����
	//person.MyFunc();        ������ֻ�ܵ��ó�����
}
int main() {
	test01();
	system("pause");
	return 0;
}
#endif

