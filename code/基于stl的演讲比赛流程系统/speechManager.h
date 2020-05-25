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

//设计管理类
class SpeechManager
{
public:
	//构造
	SpeechManager();

	//菜单展示
	void show_Menu();

	//初始化属性
	void initSpeech();

	//创建选手（12人）
	void createSpeaker();

	//开始比赛 控制流程
	void startSpeech();

	//抽签
	void speechDraw();

	//比赛
	void speechContest();

	//显示比赛分数
	void showScore();

	//保存记录到文件
	void saveRecord();

	//读取往届记录
	void loadRecord();

	//显示往届记录
	void showRecord();

	//清空记录
	void clearRecord();

	//退出系统
	void exitSystem();

	//析构
	~SpeechManager();

//成员属性：	
	vector<int>v1;         //选手容器 12人	
	vector<int>v2;         //晋级的6人	
	vector<int>vVictory;   //胜利的前3人	
	map<int, Speaker> m_Speaker; //存放编号及对应选手
	int m_index;	       //比赛轮数
	map<int, vector<string>>m_Record;//往届记录的信息
	bool fileIsEmpty;	   //文件是否为空
};