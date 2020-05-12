#pragma once
#include<iostream>
#include<string>
#include "employee.h"
#include "Hourly_Employee.h"
#include "Salaried_Employee.h"
#include "Commission_Employee.h"
#include "BasePlus_Commission_Employee.h"
#include<fstream>
#define filename "empFile.txt"
using namespace std;

class Management {
public:
	Management();
	void Show_Menu();          //菜单功能展示
	void exitsystem();         //退出系统函数
	void add_Emp();            //增加职工
	void save();               //保存到文件
	int get_EmpNum();          //统计人数
	void init_Emp();           //用文件已有信息初始化员工
	void Show_Emp();           //显示所有职工
	void Show2_Emp();          //显示某一部门职工
	void Del_Emp();            //删除职工
	int IsExist1(int SSN);     //按照职工编号判断职工是否存在
	int IsExist2(string name); //按照职工姓名判断职工是否存在
	void Mod_Emp();            //修改职工
	void Find_Emp();           //查找职工

	int m_EmpNum;	           //记录文件中的人数个数
	Employee** m_EmpArray;     //员工数组的指针
	bool m_FileIsEmpty;        //文件是否为空标志
	~Management();
};