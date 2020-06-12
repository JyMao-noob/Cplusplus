#include<iostream>
#include<string>
#include<stdio.h>
#include<vector>
#include<fstream>
#include<windows.h>
#include<Mmsystem.h>
#pragma comment(lib, "winmm.lib")
using namespace std;



class Music
{
public:
	//���캯��
	Music(string id,string name,string singer,string album)
	{
		this->m_id = id;
		this->m_name = name;
		this->m_singer = singer;
		this->m_album = album;
	}
	//��Ա����
	string m_id;
	string m_name;
	string m_singer;
	string m_album;
};

//������
class Manager
{
public:
	vector<Music> v1;  //������и���
	vector<Music> v2;  //���ϲ������

	//����
	Manager()
	{
		init_v1();
		init_v2();
	};

	void show_Menu()
	{
		cout << "------��ӭʹ�ü����ֲ�����ϵͳ------" << endl;
		cout << "***          1.����赥            ***" << endl;
		cout << "***          2.�㲥����            ***" << endl;
		cout << "***          3.�鿴ϲ������        ***" << endl;
		cout << "***          4.����ϲ������        ***" << endl;
		cout << "***          5.ɾ��ϲ������        ***" << endl;
		cout << "***          0.�˳�ϵͳ            ***" << endl;
		cout << "--------------------------------------" << endl;
	}

	void exitSystem()
	{
		cout << "��ӭ�´�ʹ�ã�" << endl;
		system("pause");
		exit(0);
	}

	void init_v1()
	{
		ifstream ifs;
		ifs.open("�赥.txt", ios::in);
		string id;
		string name;
		string singer;
		string album;
		while (ifs >> id && ifs >> name && ifs >> singer && ifs >> album)
		{
			Music m(id, name, singer, album);
			v1.push_back(m);
		}
		ifs.close();

	}

	void init_v2()
	{
		ifstream ifs;
		ifs.open("ϲ���ĸ���.txt", ios::in);
		string id;
		string name;
		string singer;
		string album;
		while (ifs >> id && ifs >> name && ifs >> singer && ifs >> album)
		{
			Music m(id, name, singer, album);
			v2.push_back(m);
		}
		ifs.close();

	}

	int IsExist(string name,vector<Music>&v)
	{
		int index = -1;
		for (vector<Music>::iterator it = v.begin(); it != v.end(); it++)
		{
			if (it->m_name == name)
			{
				index = 1;
				break;
			}
		}
		return index;
	}

	void playMusic()
	{
			cout << "������㲥������" << endl;
			string name;
			
			int select;
			cin >> name;
			int ret = IsExist(name,v1);
			if (ret == -1)
			{
				cout << "��Ǹ���赥���޴˸�" << endl;
				system("pause");
				system("cls");
				return;
			}		
			MCI_OPEN_PARMS OpenParms;           //���豸  
			OpenParms.lpstrDeviceType = NULL;   // "mpegvideo";

			string name1 = name + ".mp3";
			LPCSTR Name = name1.c_str();

			OpenParms.lpstrElementName = Name;
			OpenParms.wDeviceID = NULL;
			mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT, (DWORD)&OpenParms);

			MCI_PLAY_PARMS PlayParms; //�����ļ�  
			PlayParms.dwFrom = 0;

			cout << "*************************************************************" << endl;
			cout << "���������:" << endl;
			cout << "         p:���� a:��ͣ r:��������  b:ֹͣ������" << endl;
			cout << "*************************************************************" << endl;

			while (1) {
				char ch = getchar();
				if (ch == 'p') //����  
				{
					mciSendCommand(OpenParms.wDeviceID, MCI_PLAY, MCI_FROM, (DWORD)&PlayParms);
				}
				if (ch == 'a') //��ͣ  
				{
					mciSendCommand(OpenParms.wDeviceID, MCI_PAUSE, NULL, (DWORD)&PlayParms);
				}
				if (ch == 'r') //��������  
				{
					mciSendCommand(OpenParms.wDeviceID, MCI_RESUME, NULL, (DWORD)&PlayParms);
				}				
				if (ch == 'b') //���� 
				{
					mciSendCommand(OpenParms.wDeviceID, MCI_STOP, NULL, (DWORD)&PlayParms);
					break;
				}
			}
			
			system("pause");
			system("cls");
			
	}

	void showAllMusic()
	{
		cout << "���    ����    ����   ר��" << endl;
		for (vector<Music>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << it->m_id << "\t" << it->m_name << "\t"
				<< it->m_singer << "\t" << it->m_name << "\t" << endl;
		}
		cout << endl;
		system("pause");
		system("cls");
	}

	void addFavoriteMusic()
	{
		cout << "��������Ҫ��ӵ�ϲ����������" << endl;
		string name;
		cin >> name;
		int ret = IsExist(name, v2);
		if (ret == 1)
		{
			cout << "�ø����Ѱ�����ϲ�������б��У�" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			for (vector<Music>::iterator it = v1.begin(); it != v1.end(); it++)
			{
				if (it->m_name == name)
				{
					Music m(it->m_id, it->m_name, it->m_singer, it->m_album);
					v2.push_back(m);
					break;
				}
			}
			cout << "��ӳɹ���" << endl;
		}
		saveFile();
		system("pause");
		system("cls");
		return;
	}

	void showFavoriteMusic()
	{
		cout << "���    ����    ����   ר��" << endl;
		for (vector<Music>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << it->m_id << "\t" << it->m_name << "\t"
				<< it->m_singer << "\t" << it->m_name << "\t" << endl;
		}
		cout << endl;
		system("pause");
		system("cls");
	}



	void del_Music()
	{
		cout << "��ѡ��(  )ɾ��ϲ���ĸ���" << endl;
		cout << "1.���" << endl;
		cout << "2.����" << endl;
		int select;
		string del;
		cin >> select;
		if (select == 1)
		{
			cout << "�����������ţ�" << endl;
			cin >> del;
			for (vector<Music>::iterator it = v2.begin(); it != v2.end(); it++)
			{
				if (it->m_id == del)
				{
					v2.erase(it);
					cout << "ɾ���ɹ���" << endl;
					break;
				}
			}

		}
		else if (select == 2)
		{
			cout << "�������������" << endl;
			cin >> del;
			for (vector<Music>::iterator it = v2.begin(); it != v2.end(); it++)
			{
				if (it->m_name == del)
				{
					v2.erase(it);
					cout << "ɾ���ɹ���" << endl;
					break;
				}
			}

		}
		else
		{
			cout << "��������" << endl;			
		}

		saveFile();

		system("pause");
		system("cls");
		

	}

	void saveFile()
	{
		ofstream ofs;
		ofs.open("ϲ���ĸ���.txt", ios::out);
		for (vector<Music>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			ofs << it->m_id << " "
				<< it->m_name << " "
				<< it->m_singer << " "
				<< it->m_album << endl;
		}
		ofs.close();
	}
};


int main()
{
	Manager m;
	while (1)
	{
		m.show_Menu();
		cout << "��������Ҫִ�еĲ�����" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1://����赥
			m.showAllMusic();
			break;
		case 2://�㲥����
			m.playMusic();
			break;
		case 3://�鿴ϲ������
			m.showFavoriteMusic();
			break;
		case 4://����ϲ������
			m.addFavoriteMusic();
			break;
		case 5://ɾ��ϲ������
			m.del_Music();
			break;
		case 0://�˳�ϵͳ
			m.exitSystem();
			break;
		}

	}

	system("pause");
	return 0;
}