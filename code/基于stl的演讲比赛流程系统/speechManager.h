#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include "speaker.h"
#include<algorithm>
#include<deque>
#include <functional>
#include<numeric>
#include<fstream>
using namespace std;

//��ƹ�����
class SpeechManager
{
public:
	//����
	SpeechManager();

	//�˵�չʾ
	void show_Menu();

	//��ʼ������
	void initSpeech();

	//����ѡ�֣�12�ˣ�
	void createSpeaker();

	//��ʼ���� ��������
	void startSpeech();

	//��ǩ
	void speechDraw();

	//����
	void speechContest();

	//��ʾ��������
	void showScore();

	//�����¼���ļ�
	void saveRecord();

	//��ȡ�����¼
	void loadRecord();

	//��ʾ�����¼
	void showRecord();

	//��ռ�¼
	void clearRecord();

	//�˳�ϵͳ
	void exitSystem();

	//����
	~SpeechManager();

//��Ա���ԣ�	
	vector<int>v1;         //ѡ������ 12��	
	vector<int>v2;         //������6��	
	vector<int>vVictory;   //ʤ����ǰ3��	
	map<int, Speaker> m_Speaker; //��ű�ż���Ӧѡ��
	int m_index;	       //��������
	map<int, vector<string>>m_Record;//�����¼����Ϣ
	bool fileIsEmpty;	   //�ļ��Ƿ�Ϊ��
};