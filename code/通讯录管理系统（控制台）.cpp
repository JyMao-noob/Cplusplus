#if 1
#include<iostream>
#include<string>
using namespace std;
#define max 100

struct Person {
	string Name;
	string Sex;
	int Age;
	string Phone_number;
};

struct phonebook {
	Person person_array[max];
	int Size=0;
};

void showMenu() {
	cout << "***  1、添加联系人  ***" << endl;
	cout << "***  2、显示联系人  ***" << endl;
	cout << "***  3、删除联系人  ***" << endl;
	cout << "***  4、查找联系人  ***" << endl;
	cout << "***  5、修改联系人  ***" << endl;
	cout << "***  6、清空通讯录  ***" << endl;
	cout << "***  0、退出通讯录  ***" << endl;
}

void Add_person(phonebook* abs) {
	if (abs->Size == max)  cout << "通讯录已满" << endl;
	else {
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		abs->person_array[abs->Size].Name = name;

		cout << "请输入性别：" << endl;
		string sex;
		cin >>sex;
		abs->person_array[abs->Size].Sex = sex;

		cout << "请输入年龄：" << endl;
		int age;
		cin >>age;
		abs->person_array[abs->Size].Age = age;

		cout << "请输入电话号码：" << endl;
		string number;
		cin >>number;
		abs->person_array[abs->Size].Phone_number = number;

		abs->Size++;
		cout << "添加成功！" << endl;
	}
}

void print_abs(phonebook *abs) {
	for (int i = 0; i < abs->Size; i++) {
		cout << "姓名为：" << abs->person_array[i].Name << "\t性别为：" << abs->person_array[i].Sex << "\t年龄为：" 
			<< abs->person_array[i].Age << "\t电话号码为："
			<< abs->person_array[i].Phone_number << endl;
	}
}

int isExist(phonebook* abs,string searchName) {
	for (int i = 0; i < abs->Size; i++) {
		if (abs->person_array[i].Name == searchName)  return i;
	}
	return -1;
}

void deletePerson(phonebook* abs) {
	cout << "请输入要删除的联系人姓名：" << endl;
	string name;
	cin >> name;

	int result = isExist(abs, name);
	if (result == -1)  cout << "查无此人"<<endl;
	else {
		for (int i = result; i < abs->Size; i++) {
			abs->person_array[i] = abs->person_array[i + 1];
		}
		abs->Size--;
		cout << "已删除！" << endl;
	}


}

void Search_person(phonebook *abs) {
	cout << "请输入你要查找的人的姓名：" << endl;
	string name;
	cin >> name;
	int result = isExist(abs, name);
	if (result == -1)  cout << "查无此人" << endl;
	else {
		cout << "姓名为：" << abs->person_array[result].Name << "\t性别为：" << abs->person_array[result].Sex << "\t年龄为：" 
			<< abs->person_array[result].Age << "\t电话号码为："
			<< abs->person_array[result].Phone_number << endl;
	}
}

void modify_info(phonebook* abs) {
	cout << "请输入你要修改信息者的名字：" << endl;
	string name;
	cin >> name;
	int result = isExist(abs, name);
	if (result == -1)  cout << "查无此人" << endl;
	else {
		cout << "接下来将进行信息修改！" << endl;
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		abs->person_array[result].Name = name;

		cout << "请输入性别：" << endl;
		string sex;
		cin >> sex;
		abs->person_array[result].Sex = sex;

		cout << "请输入年龄：" << endl;
		int age;
		cin >> age;
		abs->person_array[result].Age = age;

		cout << "请输入电话号码：" << endl;
		string number;
		cin >> number;
		abs->person_array[result].Phone_number = number;

	}
}

void clean_book(phonebook* abs) {
	abs->Size = 0;
	cout << "通讯录已清空完成！" << endl;
}

int main() {
	phonebook abs;
	int select = 0;
	while (true) {
		showMenu();
		cin >> select;
		switch (select) {
		case 1: {Add_person(&abs);
			     system("pause");
			     system("cls");
			     break; }
			
		case 2: {print_abs(&abs);
			     system("pause");
		       	 system("cls");
			     break; }
			
		case 3: {deletePerson(&abs);
			system("pause");
			system("cls");
			break; }
			
		case 4: {Search_person(&abs);
			system("pause");
			system("cls");
			break; }
			
		case 5: {modify_info(&abs);
			system("pause");
			system("cls");
			break; }
			
		case 6: {clean_book(&abs);
			system("pause");
			system("cls");
			break; }
			
		case 0: {
			cout << "退出成功！" << endl;
			system("pause");
			return 0;
			break; }
		default: break;

		}
	}

	
}
#endif