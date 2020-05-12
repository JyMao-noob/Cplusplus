#include "employee.h"
#pragma once
#include<iostream>
using namespace std;

//派生固定工资的员工
class Salaried_Employee:public Employee {
public:
	
	Salaried_Employee(int kind,string name, int SSN, double m_earning);     //构造函数
	
	void showInfo();        //显示个人信息
	double count_earning(); //计算工资
	
	
};