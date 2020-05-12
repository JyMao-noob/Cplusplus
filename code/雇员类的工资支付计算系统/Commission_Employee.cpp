#include "Commission_Employee.h"


Commission_Employee::Commission_Employee(int kind,string name, int SSN, double m_earning) {
	this->m_name = name;
	this->m_SSN = SSN;
	this->kind = 3;
	this->m_earning = m_earning;
}

void Commission_Employee::showInfo() {
	
	cout << "职工类型：Commission_Employee "
		<< "        \t职工SSN： " << this->m_SSN
		<< "\t职工姓名： " << this->m_name
		<< "  \t职工工资： " << this->m_earning << endl;
}

double Commission_Employee::count_earning() {
	double earning;
	earning = Commission_rate * Gross_Sale;
	return earning;
}