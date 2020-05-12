#pragma once
#include "employee.h"
#include<iostream>
using namespace std;

//派生按销售额发工资的员工
class BasePlus_Commission_Employee :public Employee {
public:
	
	BasePlus_Commission_Employee(int kind,string name, int SSN,double m_earning);     //构造函数

	void showInfo();        //显示个人信息
	double count_earning(); //计算工资	
	
};