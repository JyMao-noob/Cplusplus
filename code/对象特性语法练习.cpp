#if 0
#include<iostream>
#include<string>
using namespace std;
class Person {
public:
	int m_Age;
	int* m_Height;
	Person() {
		cout << "完成了无参构造函数." << endl;
	}

	Person(int age, int height) {
		cout << "完成了有参构造函数." << endl;
		m_Age = age;
		m_Height = new int(height);
	}

	Person(const Person& p) {
		cout << "完成了拷贝构造函数." << endl;
		m_Age = p.m_Age;
		m_Height = new int(*p.m_Height);    //深拷贝
	}
	~Person() {
		if (m_Height != NULL) {
			delete m_Height;
			m_Height = NULL;
		}
		cout << "完成了析构函数." << endl;
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
	Phone(){ cout << "Phone无参构造" << endl; }
	Phone(string num) {
		P_number = num;
		cout << "Phone有参构造" << endl;
	}
	~Phone() {
		cout << "Phone析构函数" << endl;
	}
};
class Person {
public:
	string m_name;
	Phone m_number;
	Person(string name, string number) {   //或可以采用初始化列表构造:m_name(name),m_number(number)
		m_name =name;
		m_number=number;
		cout << "Person有参构造" << endl;
	}
	~Person() {
		cout << "Person析构函数" << endl;
	}
	void func() {
		cout << m_name << "的手机号是：" << m_number.P_number << endl;		
	}
};

void test() {
	Person p1("张三","123456789");
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
	static void func()                       //静态成员函数只能访问静态成员变量
	{
		cout << "func调用" << endl;
		m_A = 100;
		//m_B = 100; //错误，不可以访问非静态成员变量
	}
	
};

int Person::m_A = 18;      //注意要加作用域Person::
int main() {
	Person p;
	cout << p.m_A << endl;
	Person p2;
	p2.m_A = 20;
	cout << p.m_A << endl;
	Person::func();                   //通过类名访问成员静态函数
	cout << Person::m_A << endl;      //也可以不用定义p1、p2，直接通过类名访问
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
	{		//1、当形参和成员变量同名时，可用this指针来区分
		this->age = age;     //虽然可以区分，不过同名是个坏习惯
	}
	Person& PersonAddPerson(Person p)               //链表思想，注意是Person&  ，引用！！！
	{
		this->age += p.age;
		//返回对象本身
		return *this;
	}
	int age;
};
void test01()
{	Person p1(10);
	cout << "p1.age = " << p1.age << endl;
	Person p2(10);
	p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);    //链表思想
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
	//this指针的本质是一个指针常量，指针的指向不可修改
	//如果想让指针指向的值也不可以修改，需要声明常函数
	void ShowPerson() const {                                     //const修饰成员函数
		//const Type* const pointer;
		//this = NULL; //不能修改指针的指向 Person* const this;
		//this->mA = 100; //但是this指针指向的对象的数据是可以修改的
		//const修饰成员函数，表示指针指向的内存空间的数据不能修改，除了mutable修饰的变量
		this->m_B = 100;
	}
	void MyFunc()  {
		//mA = 10000;
	}
public:
	int m_A;
	mutable int m_B; //可修改 可变的
};
//const修饰对象  常对象
void test01() {
	const Person person; //常量对象  
	cout << person.m_A << endl;
	//person.mA = 100; //常对象不能修改成员变量的值,但是可以访问
	person.m_B = 100; //但是常对象可以修改mutable修饰成员变量
	//常对象访问成员函数
	//person.MyFunc();        常对象只能调用常函数
}
int main() {
	test01();
	system("pause");
	return 0;
}
#endif

