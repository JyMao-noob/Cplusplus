#pragma once
#include "employee.h"
#include<iostream>
using namespace std;

//���������۶���ʵ�Ա��
class Commission_Employee :public Employee {
public:
	
	Commission_Employee(int kind,string name, int SSN,double m_earning);     //���캯��

	void showInfo();        //��ʾ������Ϣ
	double count_earning(); //���㹤��	
	
};