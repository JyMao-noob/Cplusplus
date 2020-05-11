#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker {     //抽象职工基类
public:
	//显示个人信息
	virtual void showInfo() = 0;
	//获取岗位信息
	virtual string getDeptName() = 0;

	int m_Id;    //职工编号
	string m_Name;   //姓名
	int m_DeptId;    //部门编号
};