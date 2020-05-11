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

	WorkerManager();   //���캯��
	void Show_Menu();  //���ܲ˵�չʾ
	void exitSystem(); //�˳�ϵͳ

	int m_EmpNum;      //ְ������
	Worker** m_EmpArray; //ְ������ָ��
	bool m_FileIsEmpty; //�ж��ļ��Ƿ�Ϊ��

	void Add_Emp();     //���Ա������
	void save();        //�����ļ�����
	int get_EmpNum();   //ͳ�������ļ�������
	void init_Emp();    //�������ļ�����Ϣ��ʼ��
	void Show_Emp();    //չʾְ����Ϣ
	int IsExist(int id ); //�ж�ְ���Ƿ����
	void Del_Emp();     //ɾ��ְ��
	void Mod_Emp();     //�޸�Ա����Ϣ
	void Find_Emp();    //����Ա����Ϣ
	void Sort_Emp();    //����
	void Clean_File();  //����ļ�
	~WorkerManager();   //��������
};