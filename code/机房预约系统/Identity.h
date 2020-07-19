#pragma once
#include<iostream>
#include<string>
using namespace std;

//身份抽象基类
class Identity    
{
public:

	//子操作菜单的纯虚函数
	virtual void operMenu() = 0;



	string m_Name;//名字
	string m_Pwd; //密码
};