#include "manager.h"

//构造函数
Manager::Manager(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
//显示个人信息
void Manager::showInfo() {
	cout << "职工编号： " << this->m_Id
		<< "\t职工姓名：  " << this->m_Name
		<< "\t 岗位：  " << this->getDeptName()
		<< "\t 职责：  完成老板交付的任务，并下发给员工" << endl;
}
//获取岗位信息
string Manager::getDeptName() {
	return string("经理");
}