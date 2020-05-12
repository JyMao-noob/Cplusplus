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
	void Show_Menu();          //�˵�����չʾ
	void exitsystem();         //�˳�ϵͳ����
	void add_Emp();            //����ְ��
	void save();               //���浽�ļ�
	int get_EmpNum();          //ͳ������
	void init_Emp();           //���ļ�������Ϣ��ʼ��Ա��
	void Show_Emp();           //��ʾ����ְ��
	void Show2_Emp();          //��ʾĳһ����ְ��
	void Del_Emp();            //ɾ��ְ��
	int IsExist1(int SSN);     //����ְ������ж�ְ���Ƿ����
	int IsExist2(string name); //����ְ�������ж�ְ���Ƿ����
	void Mod_Emp();            //�޸�ְ��
	void Find_Emp();           //����ְ��

	int m_EmpNum;	           //��¼�ļ��е���������
	Employee** m_EmpArray;     //Ա�������ָ��
	bool m_FileIsEmpty;        //�ļ��Ƿ�Ϊ�ձ�־
	~Management();
};