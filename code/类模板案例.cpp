#if 0
#include<iostream>
#include<string>
using namespace std;
template<class T>
class MyArray
{
private:
	T* pAddress;
	int m_Capacity;
	int m_Size;
public:
	//构造函数
	MyArray(int capacity) {
		this->m_Capacity = capacity;
		this->m_Size = 0;
		pAddress = new T[this->m_Capacity];
	}
	//拷贝构造
	MyArray(const MyArray& arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	//重载= 操作符  防止浅拷贝问题
	MyArray& operator=(const MyArray& myarray) {
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		this->m_Capacity = myarray.m_Capacity;
		this->m_Size = myarray.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++) {
			this->pAddress[i] = myarray.pAddress[i];
		}
		return *this;
	}
	//重载[] 操作符  arr[0]
	T& operator[](int i) {
		return this->pAddress[i];
	}
	//尾插法
	void Push_back(const T& val) {
		if (this->m_Capacity == this->m_Size) {
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}
	//尾删法
	void Pop_back() {
		if (this->m_Size == 0) {
			return;
		}
		this->m_Size--;
	}
	//获取数组容量
	int getCapacity()
	{
		return this->m_Capacity;
	}
	//获取数组大小
	int	getSize()
	{
		return this->m_Size;
	}
	//析构
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
	}
};

void printIntArray(MyArray<int>& arr) {
	for (int i = 0; i < arr.getSize(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

//测试内置数据类型
void test01()
{
	MyArray<int> array1(10);
	for (int i = 0; i < 10; i++)
	{
		array1.Push_back(i);
	}
	cout << "array1打印输出：" << endl;
	printIntArray(array1);
	cout << "array1的大小：" << array1.getSize() << endl;
	cout << "array1的容量：" << array1.getCapacity() << endl;

	cout << "--------------------------" << endl;

	MyArray<int> array2(array1);
	array2.Pop_back();
	cout << "array2打印输出：" << endl;
	printIntArray(array2);
	cout << "array2的大小：" << array2.getSize() << endl;
	cout << "array2的容量：" << array2.getCapacity() << endl;
}

//测试自定义数据类型
class Person {
public:
	Person() {}
	Person(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}
public:
	string m_Name;
	int m_Age;
};

void printPersonArray(MyArray<Person>& personArr)
{
	for (int i = 0; i < personArr.getSize(); i++) {
		cout << "姓名：" << personArr[i].m_Name << " 年龄： " << personArr[i].m_Age << endl;
	}

}

void test02()
{
	//创建数组
	MyArray<Person> pArray(10);
	Person p1("孙悟空", 30);
	Person p2("韩信", 20);
	Person p3("妲己", 18);
	Person p4("王昭君", 15);
	Person p5("赵云", 24);

	//插入数据
	pArray.Push_back(p1);
	pArray.Push_back(p2);
	pArray.Push_back(p3);
	pArray.Push_back(p4);
	pArray.Push_back(p5);

	printPersonArray(pArray);

	cout << "pArray的大小：" << pArray.getSize() << endl;
	cout << "pArray的容量：" << pArray.getCapacity() << endl;

}
int main() {
	//test01();

	test02();
	system("pause");
	return 0;
}
#endif