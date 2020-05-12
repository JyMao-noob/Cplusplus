#include "Hourly_Employee.h"


Hourly_Employee::Hourly_Employee(int kind,string name, int SSN, double m_earning) {
	this->m_name = name;
	this->m_SSN = SSN;
	this->kind = 2;
	this->m_earning = m_earning;
}

void Hourly_Employee::showInfo() {
	
	cout << "职工类型：Hourly_Employee "
		<< "        \t职工SSN： " << this->m_SSN
		<< "\t职工姓名： " << this->m_name
		<< "  \t职工工资： " << this->m_earning << endl;
}

double Hourly_Employee::count_earning() {
	double earning;
	if (this->hours <= 40) { earning = this->wage * this->hours; }
	else { earning = 40 * wage + (hours - 40) * wage * 1.5; }

	return earning;
}