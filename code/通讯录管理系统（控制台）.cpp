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
	cout << "***  1�������ϵ��  ***" << endl;
	cout << "***  2����ʾ��ϵ��  ***" << endl;
	cout << "***  3��ɾ����ϵ��  ***" << endl;
	cout << "***  4��������ϵ��  ***" << endl;
	cout << "***  5���޸���ϵ��  ***" << endl;
	cout << "***  6�����ͨѶ¼  ***" << endl;
	cout << "***  0���˳�ͨѶ¼  ***" << endl;
}

void Add_person(phonebook* abs) {
	if (abs->Size == max)  cout << "ͨѶ¼����" << endl;
	else {
		cout << "������������" << endl;
		string name;
		cin >> name;
		abs->person_array[abs->Size].Name = name;

		cout << "�������Ա�" << endl;
		string sex;
		cin >>sex;
		abs->person_array[abs->Size].Sex = sex;

		cout << "���������䣺" << endl;
		int age;
		cin >>age;
		abs->person_array[abs->Size].Age = age;

		cout << "������绰���룺" << endl;
		string number;
		cin >>number;
		abs->person_array[abs->Size].Phone_number = number;

		abs->Size++;
		cout << "��ӳɹ���" << endl;
	}
}

void print_abs(phonebook *abs) {
	for (int i = 0; i < abs->Size; i++) {
		cout << "����Ϊ��" << abs->person_array[i].Name << "\t�Ա�Ϊ��" << abs->person_array[i].Sex << "\t����Ϊ��" 
			<< abs->person_array[i].Age << "\t�绰����Ϊ��"
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
	cout << "������Ҫɾ������ϵ��������" << endl;
	string name;
	cin >> name;

	int result = isExist(abs, name);
	if (result == -1)  cout << "���޴���"<<endl;
	else {
		for (int i = result; i < abs->Size; i++) {
			abs->person_array[i] = abs->person_array[i + 1];
		}
		abs->Size--;
		cout << "��ɾ����" << endl;
	}


}

void Search_person(phonebook *abs) {
	cout << "��������Ҫ���ҵ��˵�������" << endl;
	string name;
	cin >> name;
	int result = isExist(abs, name);
	if (result == -1)  cout << "���޴���" << endl;
	else {
		cout << "����Ϊ��" << abs->person_array[result].Name << "\t�Ա�Ϊ��" << abs->person_array[result].Sex << "\t����Ϊ��" 
			<< abs->person_array[result].Age << "\t�绰����Ϊ��"
			<< abs->person_array[result].Phone_number << endl;
	}
}

void modify_info(phonebook* abs) {
	cout << "��������Ҫ�޸���Ϣ�ߵ����֣�" << endl;
	string name;
	cin >> name;
	int result = isExist(abs, name);
	if (result == -1)  cout << "���޴���" << endl;
	else {
		cout << "��������������Ϣ�޸ģ�" << endl;
		cout << "������������" << endl;
		string name;
		cin >> name;
		abs->person_array[result].Name = name;

		cout << "�������Ա�" << endl;
		string sex;
		cin >> sex;
		abs->person_array[result].Sex = sex;

		cout << "���������䣺" << endl;
		int age;
		cin >> age;
		abs->person_array[result].Age = age;

		cout << "������绰���룺" << endl;
		string number;
		cin >> number;
		abs->person_array[result].Phone_number = number;

	}
}

void clean_book(phonebook* abs) {
	abs->Size = 0;
	cout << "ͨѶ¼�������ɣ�" << endl;
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
			cout << "�˳��ɹ���" << endl;
			system("pause");
			return 0;
			break; }
		default: break;

		}
	}

	
}
#endif