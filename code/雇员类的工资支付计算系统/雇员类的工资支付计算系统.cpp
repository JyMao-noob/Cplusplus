#include<iostream>
#include<string>
#include "employee.h"
#include "Hourly_Employee.h"
#include "Salaried_Employee.h"
#include "Commission_Employee.h"
#include "BasePlus_Commission_Employee.h"
#include "Management.h"
#include<fstream>
using namespace std;
int main() {
	Management m;
	int choice;
	while (true) {
		m.Show_Menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice) {
		case 0://�˳�ϵͳ
			m.exitsystem();
			break;
		case 1://����ְ����Ϣ
			m.add_Emp();
			break;
		case 2://��ʾ����ְ����Ϣ
			m.Show_Emp();
			break;
		case 3://��ʾĳһ��������ְ����Ϣ
			m.Show2_Emp();
			break;
		case 4://ɾ��
			m.Del_Emp();
			break;
		case 5://�޸�
			m.Mod_Emp();
			break;
		case 6://����
			m.Find_Emp();
			break;
		
		}
	}
}