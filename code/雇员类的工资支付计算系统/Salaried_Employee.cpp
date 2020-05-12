#include "Salaried_Employee.h"


Salaried_Employee::Salaried_Employee(int kind,string name, int SSN, double m_earning) {
	this->kind = 1;
	this->m_name = name;
	this->m_SSN = SSN;	
	this->m_earning = m_earning;
}

void Salaried_Employee::showInfo() {
	
	cout<<"职工类型:Salaried_Employee "
		<< "        \t职工SSN： " << this->m_SSN
		<< "\t职工姓名： " << this->m_name
		<< "  \t职工工资： " << this->m_earning <<endl;
}

double Salaried_Employee::count_earning() {
	double earning;
	earning = this->baseSalary;
	return earning;
}