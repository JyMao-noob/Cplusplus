#include "employee.h"
#pragma once
#include<iostream>
using namespace std;

//�����̶����ʵ�Ա��
class Salaried_Employee:public Employee {
public:
	
	Salaried_Employee(int kind,string name, int SSN, double m_earning);     //���캯��
	
	void showInfo();        //��ʾ������Ϣ
	double count_earning(); //���㹤��
	
	
};