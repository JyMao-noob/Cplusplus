#include "Salaried_Employee.h"


Salaried_Employee::Salaried_Employee(int kind,string name, int SSN, double m_earning) {
	this->kind = 1;
	this->m_name = name;
	this->m_SSN = SSN;	
	this->m_earning = m_earning;
}

void Salaried_Employee::showInfo() {
	
	cout<<"ְ������:Salaried_Employee "
		<< "        \tְ��SSN�� " << this->m_SSN
		<< "\tְ�������� " << this->m_name
		<< "  \tְ�����ʣ� " << this->m_earning <<endl;
}

double Salaried_Employee::count_earning() {
	double earning;
	earning = this->baseSalary;
	return earning;
}