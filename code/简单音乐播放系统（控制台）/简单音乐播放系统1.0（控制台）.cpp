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
	//构造函数
	Music(string id,string name,string singer,string album)
	{
		this->m_id = id;
		this->m_name = name;
		this->m_singer = singer;
		this->m_album = album;
	}
	//成员属性
	string m_id;
	string m_name;
	string m_singer;
	string m_album;
};

//控制类
class Manager
{
public:
	vector<Music> v1;  //存放所有歌曲
	vector<Music> v2;  //存放喜爱歌曲

	//构造
	Manager()
	{
		init_v1();
		init_v2();
	};

	void show_Menu()
	{
		cout << "------欢迎使用简单音乐播放器系统------" << endl;
		cout << "***          1.浏览歌单            ***" << endl;
		cout << "***          2.点播歌曲            ***" << endl;
		cout << "***          3.查看喜爱歌曲        ***" << endl;
		cout << "***          4.增加喜爱歌曲        ***" << endl;
		cout << "***          5.删除喜爱歌曲        ***" << endl;
		cout << "***          0.退出系统            ***" << endl;
		cout << "--------------------------------------" << endl;
	}

	void exitSystem()
	{
		cout << "欢迎下次使用！" << endl;
		system("pause");
		exit(0);
	}

	void init_v1()
	{
		ifstream ifs;
		ifs.open("歌单.txt", ios::in);
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
		ifs.open("喜爱的歌曲.txt", ios::in);
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
			cout << "请输入点播歌名：" << endl;
			string name;
			
			int select;
			cin >> name;
			int ret = IsExist(name,v1);
			if (ret == -1)
			{
				cout << "抱歉，歌单中无此歌" << endl;
				system("pause");
				system("cls");
				return;
			}		
			MCI_OPEN_PARMS OpenParms;           //打开设备  
			OpenParms.lpstrDeviceType = NULL;   // "mpegvideo";

			string name1 = name + ".mp3";
			LPCSTR Name = name1.c_str();

			OpenParms.lpstrElementName = Name;
			OpenParms.wDeviceID = NULL;
			mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT, (DWORD)&OpenParms);

			MCI_PLAY_PARMS PlayParms; //播放文件  
			PlayParms.dwFrom = 0;

			cout << "*************************************************************" << endl;
			cout << "请输入操作:" << endl;
			cout << "         p:播放 a:暂停 r:继续播放  b:停止并跳出" << endl;
			cout << "*************************************************************" << endl;

			while (1) {
				char ch = getchar();
				if (ch == 'p') //播放  
				{
					mciSendCommand(OpenParms.wDeviceID, MCI_PLAY, MCI_FROM, (DWORD)&PlayParms);
				}
				if (ch == 'a') //暂停  
				{
					mciSendCommand(OpenParms.wDeviceID, MCI_PAUSE, NULL, (DWORD)&PlayParms);
				}
				if (ch == 'r') //继续播放  
				{
					mciSendCommand(OpenParms.wDeviceID, MCI_RESUME, NULL, (DWORD)&PlayParms);
				}				
				if (ch == 'b') //跳出 
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
		cout << "编号    歌名    歌手   专辑" << endl;
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
		cout << "请输入您要添加的喜爱歌曲名：" << endl;
		string name;
		cin >> name;
		int ret = IsExist(name, v2);
		if (ret == 1)
		{
			cout << "该歌曲已包含于喜爱歌曲列表中！" << endl;
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
			cout << "添加成功！" << endl;
		}
		saveFile();
		system("pause");
		system("cls");
		return;
	}

	void showFavoriteMusic()
	{
		cout << "编号    歌名    歌手   专辑" << endl;
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
		cout << "您选择按(  )删除喜爱的歌曲" << endl;
		cout << "1.编号" << endl;
		cout << "2.歌名" << endl;
		int select;
		string del;
		cin >> select;
		if (select == 1)
		{
			cout << "请输入歌曲编号：" << endl;
			cin >> del;
			for (vector<Music>::iterator it = v2.begin(); it != v2.end(); it++)
			{
				if (it->m_id == del)
				{
					v2.erase(it);
					cout << "删除成功！" << endl;
					break;
				}
			}

		}
		else if (select == 2)
		{
			cout << "请输入歌曲名：" << endl;
			cin >> del;
			for (vector<Music>::iterator it = v2.begin(); it != v2.end(); it++)
			{
				if (it->m_name == del)
				{
					v2.erase(it);
					cout << "删除成功！" << endl;
					break;
				}
			}

		}
		else
		{
			cout << "输入有误！" << endl;			
		}

		saveFile();

		system("pause");
		system("cls");
		

	}

	void saveFile()
	{
		ofstream ofs;
		ofs.open("喜爱的歌曲.txt", ios::out);
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
		cout << "请输入您要执行的操作：" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1://浏览歌单
			m.showAllMusic();
			break;
		case 2://点播歌曲
			m.playMusic();
			break;
		case 3://查看喜爱歌曲
			m.showFavoriteMusic();
			break;
		case 4://增加喜爱歌曲
			m.addFavoriteMusic();
			break;
		case 5://删除喜爱歌曲
			m.del_Music();
			break;
		case 0://退出系统
			m.exitSystem();
			break;
		}

	}

	system("pause");
	return 0;
}