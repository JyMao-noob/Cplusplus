#pragma once
#include<iostream>
#include<string>
using namespace std;

class Employee {                    //����employee����
public:
	int m_SSN;                           
	string m_name;
	int kind;
	double m_earning;

	double baseSalary;
	int hours;
	double wage;
	int Gross_Sale;
	double Commission_rate;
	

	virtual double count_earning()=0;      //�������㹤�ʵĴ��麯��
	virtual void showInfo()=0;              //������ʾ��Ϣ����
};