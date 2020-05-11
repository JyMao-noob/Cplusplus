#pragma once
#include<iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include<fstream>
#define filename "empfile.txt"
using namespace std;
class WorkerManager {
public:

	WorkerManager();   //构造函数
	void Show_Menu();  //功能菜单展示
	void exitSystem(); //退出系统

	int m_EmpNum;      //职工人数
	Worker** m_EmpArray; //职工数组指针
	bool m_FileIsEmpty; //判断文件是否为空

	void Add_Emp();     //添加员工函数
	void save();        //保存文件函数
	int get_EmpNum();   //统计已有文件中人数
	void init_Emp();    //将已有文件中信息初始化
	void Show_Emp();    //展示职工信息
	int IsExist(int id ); //判断职工是否存在
	void Del_Emp();     //删除职工
	void Mod_Emp();     //修改员工信息
	void Find_Emp();    //查找员工信息
	void Sort_Emp();    //排序
	void Clean_File();  //清空文件
	~WorkerManager();   //析构函数
};