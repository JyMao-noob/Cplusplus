#pragma once
#include<iostream>
#include<string>
using namespace std;

//��ݳ������
class Identity    
{
public:

	//�Ӳ����˵��Ĵ��麯��
	virtual void operMenu() = 0;



	string m_Name;//����
	string m_Pwd; //����
};