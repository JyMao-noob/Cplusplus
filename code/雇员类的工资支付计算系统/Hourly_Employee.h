#pragma once
#include "employee.h"
#include<iostream>
using namespace std;

//������Сʱ�����ʵ�Ա��
class Hourly_Employee :public Employee {
public:
	
	Hourly_Employee(int kind,string name, int SSN,double m_earning);     //���캯��

	void showInfo();        //��ʾ������Ϣ
	double count_earning(); //���㹤��	
	
};