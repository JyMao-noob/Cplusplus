#pragma once
#include<iostream>
#include<string>
using namespace std;

class Employee {                    //抽象employee基类
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
	

	virtual double count_earning()=0;      //声明计算工资的纯虚函数
	virtual void showInfo()=0;              //声明显示信息函数
};