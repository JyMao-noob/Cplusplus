#include"speechManager.h"
#include<iostream>
#include<string>
#include<ctime>
using namespace std;


int main()
{
	srand((unsigned int)time(NULL));
	SpeechManager sm;   // �����������
	int choice;

	while (1)
	{
		sm.show_Menu();
		cout << "���������Ĳ���ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1://��ʼ����
			sm.startSpeech();
			break;
		case 2://�鿴��¼
			sm.showRecord();
			break;
		case 3://��ռ�¼
			sm.clearRecord();
			break;
		case 0://�˳�ϵͳ
			sm.exitSystem();
			break;
		default:
			system("cls");
			break;
		}

	}

	


	system("pause");
	return 0;
}