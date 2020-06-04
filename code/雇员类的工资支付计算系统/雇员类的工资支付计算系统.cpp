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
		cout << "请输入操作选择：" << endl;
		cin >> choice;
		switch (choice) {
		case 0://退出系统
			m.exitsystem();
			break;
		case 1://增加职工信息
			m.add_Emp();
			break;
		case 2://显示所有职工信息
			m.Show_Emp();
			break;
		case 3://显示某一部门所有职工信息
			m.Show2_Emp();
			break;
		case 4://删除
			m.Del_Emp();
			break;
		case 5://修改
			m.Mod_Emp();
			break;
		case 6://查找
			m.Find_Emp();
			break;
		
		}
	}
}
