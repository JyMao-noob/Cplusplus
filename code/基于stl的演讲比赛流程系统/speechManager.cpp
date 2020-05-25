#include "speechManager.h"
//构造
SpeechManager::SpeechManager()
{
	//初始化(置空)
	this->initSpeech();

	//创建12名选手
	createSpeaker();

	//加载往届记录
	this->loadRecord();
}

//菜单展示
void SpeechManager::show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//退出系统
void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

//初始化
void SpeechManager::initSpeech()
{
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	this->m_Record.clear();
	this->m_index = 1;
}

//创建选手
void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];

		//创建选手
		Speaker sp;
		sp.m_Name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}
		//创建选手编号，放入v1容器
		this->v1.push_back(i + 10001);
		//选手编号+名字，放入map容器
		this->m_Speaker.insert(pair<int, Speaker>(i + 10001, sp));


	}
}

//开始比赛 控制流程
void SpeechManager::startSpeech()
{
	//第一轮
	//1.抽签
	this->speechDraw();

	//2.比赛
	this->speechContest();

	//3.显示晋级信息
	this->showScore();

	//第二轮
	this->m_index++;

	//1.抽签
	this->speechDraw();

	//2.比赛
	this->speechContest();

	//3.显示最终结果
	this->showScore();

	//4.保存到文件
	this->saveRecord();

	//重置比赛
	this->initSpeech();
	
	createSpeaker();
	
	this->loadRecord();


	cout << "本届比赛结束！" << endl;
	system("pause");
	system("cls");
}

//抽签
void SpeechManager::speechDraw()
{
	cout << "第《 " << this->m_index << " 》轮选手正在抽签" << endl;
	cout << "-------------------------------" << endl;
	cout << "抽签后顺序如下：" << endl;
	if (this->m_index == 1)
	{
		//第一轮抽签
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "-------------------------------" << endl;
	system("pause");
	cout << endl;
}

//比赛
void SpeechManager::speechContest()
{
	//准备临时容器存放小组成绩
	multimap<double, int, greater<double>> groupScore;
	int num = 0;   //统计人员个数 6人一组
	cout << "------第" << this->m_index << "轮比赛开始------" << endl;
	vector<int>v_Src;   //比赛选手
	if (this->m_index == 1)
	{
		v_Src = v1;
	}
	else 
	{
		v_Src = v2;
	}
	//遍历所有选手，进行比赛
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//评委打分
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			//cout << score << "\t";
			d.push_back(score);
		}
		//cout << endl;
		//排序
		sort(d.begin(), d.end(), greater<double>());

		//去除最低分、最高分
		d.pop_back();
		d.pop_front();

		//总分
		double sum = accumulate(d.begin(), d.end(), 0.0f);

		//平均分
		double avg = sum / (double)d.size();

		//平均分放入容器
		this->m_Speaker[*it].m_Score[this->m_index - 1] = avg;

		//将打分，放入临时小组容器
		groupScore.insert(make_pair(avg, *it));

		//每6人取前3
		if (num % 6 == 0) 
		{
			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{  
				cout << "编号： " << it->second << "姓名： " << this->m_Speaker[it->second].m_Name << " 成绩： "
					<< this->m_Speaker[it->second].m_Score[this->m_index - 1] << endl;
			}
			//取走前3名
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
			{
				if (this->m_index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}
			groupScore.clear();
			cout << endl;
		}
	}

	cout << "------第" << this->m_index << "轮比赛完毕------" << endl;
	system("pause");
}

//显示比赛分数
void SpeechManager::showScore()
{
	cout << "-----第" << this->m_index << "轮晋级选手如下：------" << endl;
	vector<int>v;
	if (this->m_index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "选手编号： " << *it << " 姓名： " << this->m_Speaker[*it].m_Name
			<< " 得分： " << this->m_Speaker[*it].m_Score[this->m_index - 1] << endl;

	}
	cout << endl;
	system("pause");
	system("cls");
	this->show_Menu();
}

//保存记录到文件
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);
	//写入数据
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";

	}
	ofs << endl;
	ofs.close();
	cout << "记录已保存！" << endl;

	//更新文件状态
	this->fileIsEmpty = false;
}

//读取往届记录
void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv",ios::in);

	//文件不存在
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		//cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}
	//文件为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->fileIsEmpty = true;
		//cout << "文件为空！" << endl;
		ifs.close();
		return;
	}

	//文件存在
	this->fileIsEmpty = false;

	ifs.putback(ch);   //将上面读取的ch字符放回

	string data;
	int index = 0;
	while (ifs >> data)
	{
		//cout << data << endl;
		vector<string>v;//存放6个string字符串
		int pos = -1;  //查逗号位置
		int start = 0;
		while (true) {
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;
			}
			string temp;
			temp = data.substr(start, pos - start);
			//cout << temp << endl;
			v.push_back(temp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();

}

//显示往届记录
void SpeechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "文件为空或不存在" << endl;
	}
	else {
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "第" << i + 1 << "届 " <<
				"冠军编号：" << this->m_Record[i][0] << " 得分：" << this->m_Record[i][1] << " "
				"亚军编号：" << this->m_Record[i][2] << " 得分：" << this->m_Record[i][3] << " "
				"季军编号：" << this->m_Record[i][4] << " 得分：" << this->m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");

}

//清空记录
void SpeechManager::clearRecord()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//初始化属性
		this->initSpeech();

		//创建选手
		this->createSpeaker();

		//获取往届记录
		this->loadRecord();

		cout << "清空成功！" << endl;
	}

	system("pause");
	system("cls");
}

//析构
SpeechManager::~SpeechManager()
{

}