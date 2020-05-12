#include "Hourly_Employee.h"


Hourly_Employee::Hourly_Employee(int kind,string name, int SSN, double m_earning) {
	this->m_name = name;
	this->m_SSN = SSN;
	this->kind = 2;
	this->m_earning = m_earning;
}

void Hourly_Employee::showInfo() {
	
	cout << "ְ�����ͣ�Hourly_Employee "
		<< "        \tְ��SSN�� " << this->m_SSN
		<< "\tְ�������� " << this->m_name
		<< "  \tְ�����ʣ� " << this->m_earning << endl;
}

double Hourly_Employee::count_earning() {
	double earning;
	if (this->hours <= 40) { earning = this->wage * this->hours; }
	else { earning = 40 * wage + (hours - 40) * wage * 1.5; }

	return earning;
}