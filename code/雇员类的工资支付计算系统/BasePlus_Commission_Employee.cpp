#include "BasePlus_Commission_Employee.h"


BasePlus_Commission_Employee::BasePlus_Commission_Employee(int kind,string name, int SSN, double m_earning) {
	this->m_name = name;
	this->m_SSN = SSN;
	this->kind = 4;
	this->m_earning = m_earning;
}

void BasePlus_Commission_Employee::showInfo() {
	
	cout<<"ְ�����ͣ�BasePlus_Commission_Employee "
		<< "\tְ��SSN�� " << this->m_SSN
		<< "\tְ�������� " << this->m_name
		<< "  \tְ�����ʣ� " << this->m_earning << endl;
}

double BasePlus_Commission_Employee::count_earning() {
	double earning;
	earning = Commission_rate * Gross_Sale+this->baseSalary;
	return earning;
}