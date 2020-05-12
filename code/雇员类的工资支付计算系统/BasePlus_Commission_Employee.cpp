#include "BasePlus_Commission_Employee.h"


BasePlus_Commission_Employee::BasePlus_Commission_Employee(int kind,string name, int SSN, double m_earning) {
	this->m_name = name;
	this->m_SSN = SSN;
	this->kind = 4;
	this->m_earning = m_earning;
}

void BasePlus_Commission_Employee::showInfo() {
	
	cout<<"职工类型：BasePlus_Commission_Employee "
		<< "\t职工SSN： " << this->m_SSN
		<< "\t职工姓名： " << this->m_name
		<< "  \t职工工资： " << this->m_earning << endl;
}

double BasePlus_Commission_Employee::count_earning() {
	double earning;
	earning = Commission_rate * Gross_Sale+this->baseSalary;
	return earning;
}