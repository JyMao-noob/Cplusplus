#include "Commission_Employee.h"


Commission_Employee::Commission_Employee(int kind,string name, int SSN, double m_earning) {
	this->m_name = name;
	this->m_SSN = SSN;
	this->kind = 3;
	this->m_earning = m_earning;
}

void Commission_Employee::showInfo() {
	
	cout << "ְ�����ͣ�Commission_Employee "
		<< "        \tְ��SSN�� " << this->m_SSN
		<< "\tְ�������� " << this->m_name
		<< "  \tְ�����ʣ� " << this->m_earning << endl;
}

double Commission_Employee::count_earning() {
	double earning;
	earning = Commission_rate * Gross_Sale;
	return earning;
}