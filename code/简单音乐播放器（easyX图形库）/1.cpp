#include <graphics.h>      // 引用图形库头文件
#include <conio.h>
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<windows.h>
#include<Mmsystem.h>
#pragma comment(lib, "winmm.lib")
using namespace std;

class Music
{
public:
    //构造函数
    Music(string id, string name, string singer, string album)
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

class Manager
{
public:
    vector<Music> v;  //存放歌单

    Manager()
    {
        init_v();
    };

    void show_menu()
    {
        initgraph(640, 480);   // 创建绘图窗口，大小为 640x480 像素
        loadimage(0, ("1.jpg"));
        setbkmode(TRANSPARENT);
        outtextxy(220, 30, "欢迎使用简单音乐播放系统");

        for (int j = 100; j <= 300;)
        {
            rectangle(150, j, 490, j + 50);
            j += 100;

        }
        settextcolor(BLACK);
        outtextxy(280, 120, "查看歌单");
        outtextxy(280, 220, "点播歌曲");
        outtextxy(280, 320, "退出系统");
    }

    void init_v()
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
            v.push_back(m);
        }
        ifs.close();

    }

    void Music_system()
    {
        show_menu();
        MOUSEMSG k;
        while (1)
        {
            
            k = GetMouseMsg();
            if (k.x > 150 && k.x < 490 && k.y>100 && k.y < 150)
            {
                if (k.uMsg == WM_LBUTTONDOWN)
                {
                    showAllmusic();
                    goback();
                    break;
                }
            }
            if (k.x > 150 && k.x < 490 && k.y>200 && k.y < 250)
            {
                if (k.uMsg == WM_LBUTTONDOWN)
                {
                    string name;
                    name=chooseMusic();
                    PlayMusic(name);
                    break;
                }

            }
            if (k.x > 150 && k.x < 490 && k.y>300 && k.y < 350)
            {
                if (k.uMsg == WM_LBUTTONDOWN)
                {
                    MessageBox(0, "欢迎下次使用！", "程序结束", MB_OK | MB_SYSTEMMODAL);
                    exit(0);
                }
            }
        }
    }

    void showAllmusic()
    {
        loadimage(0, ("1.jpg"));
        settextcolor(BLACK);
        outtextxy(220, 20, "以下为所有歌单信息");
        int j = 90;
        outtextxy(140, 50, "编号");
        outtextxy(220, 50, "歌名");
        outtextxy(300, 50, "歌手");
        outtextxy(380, 50, "专辑");
        for (vector<Music>::iterator it = v.begin(); it != v.end(); it++)
        {
            outtextxy(140, j, it->m_id.c_str());
            outtextxy(220, j,it->m_name.c_str() );
            outtextxy(300, j, it->m_singer.c_str());
            outtextxy(380, j, it->m_album.c_str());
            j += 30;
        }

    }

    void goback()
    {
        setcolor(BLACK);
        rectangle(530, 420, 640, 480);
        outtextxy(570, 450, "返回");
        MOUSEMSG g;
        while (1)
        {
            g = GetMouseMsg();
            if (g.x > 530 && g.x < 640 && g.y>420 && g.y < 480)
            {
                if (g.uMsg == WM_LBUTTONDOWN)
                {
                    break;
                }

            }
        }

            
    }

    string chooseMusic()
    {
        loadimage(0, "3.jpg");
        int j = 10;
        string name;
        for (vector<Music>::iterator it = v.begin(); it != v.end(); it++)
        {
            setcolor(BLACK);
            rectangle(270, j - 10, 340, j + 20);
            outtextxy(280, j, it->m_name.c_str());
           
            j += 40;
        }
        MOUSEMSG i;
        while (1)
        {
            i = GetMouseMsg();
            if (i.x > 270 && i.x < 340 && i.y>0 && i.y < 30)
            {
                if (i.uMsg == WM_LBUTTONDOWN)
                {
                    name = "红豆"; break;
                }
            }
            if (i.x > 270 && i.x < 340 && i.y>40 && i.y < 70)
            {
                if (i.uMsg == WM_LBUTTONDOWN)
                {
                    name = "十年"; break;
                }
            }
            if (i.x > 270 && i.x < 340 && i.y>80 && i.y < 110)
            {
                if (i.uMsg == WM_LBUTTONDOWN)
                {
                    name = "处处吻"; break;
                }
            }
            if (i.x > 270 && i.x < 340 && i.y>120 && i.y < 150)
            {
                if (i.uMsg == WM_LBUTTONDOWN)
                {
                    name = "李白"; break;
                }
            }
            if (i.x > 270 && i.x < 340 && i.y>160 && i.y < 190)
            {
                if (i.uMsg == WM_LBUTTONDOWN)
                {
                    name = "夜曲"; break;
                }
            }
            if (i.x > 270 && i.x < 340 && i.y>200 && i.y < 230)
            {
                if (i.uMsg == WM_LBUTTONDOWN)
                {
                    name = "约定"; break;
                }
            }
            if (i.x > 270 && i.x < 340 && i.y>240 && i.y < 270)
            {
                if (i.uMsg == WM_LBUTTONDOWN)
                {
                    name = ("苦瓜"); break;
                }
            }
            if (i.x > 270 && i.x < 340 && i.y>280 && i.y < 310)
            {
                if (i.uMsg == WM_LBUTTONDOWN)
                {
                    name = "陀飞轮"; break;
                }
            }
            if (i.x > 270 && i.x < 340 && i.y>320 && i.y < 350)
            {
                if (i.uMsg == WM_LBUTTONDOWN)
                {
                    name = "淘汰"; break;
                }
            }
            if (i.x > 270 && i.x < 340 && i.y>360 && i.y < 390)
            {
                if (i.uMsg == WM_LBUTTONDOWN)
                {
                    name = "青鸟"; break;
                }
            }
    
        }
        
        return name;
    }

    void PlayMusic(string &name)
    {
        
        
        loadimage(0, "2.jpg");
        setcolor(BLACK);
        rectangle(290, 180, 340, 230);
        outtextxy(300, 200, "播放");
        rectangle(390, 180, 440, 230);
        outtextxy(400, 200, "暂停");
        rectangle(490, 180, 540, 230);
        outtextxy(500, 200, "继续");
        rectangle(530, 420, 640, 480);
        outtextxy(570, 450, "返回");
        MOUSEMSG h;
        MCI_OPEN_PARMS OpenParms;           //打开设备  
        OpenParms.lpstrDeviceType = NULL;   // "mpegvideo";

        string name1 = name + ".mp3";
        LPCSTR Name = name1.c_str();

        OpenParms.lpstrElementName = Name;
        OpenParms.wDeviceID = NULL;
        mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT, (DWORD)&OpenParms);

        MCI_PLAY_PARMS PlayParms; //播放文件  
        PlayParms.dwFrom = 0;
        while (1)
        {
            h = GetMouseMsg();
            if (h.x > 290 && h.x < 340 && h.y>180 && h.y < 230)
            {
                if (h.uMsg == WM_LBUTTONDOWN)
                {
                    mciSendCommand(OpenParms.wDeviceID, MCI_PLAY, MCI_FROM, (DWORD)&PlayParms);
                }

            }
            if (h.x > 390 && h.x < 440 && h.y>180 && h.y < 230)
            {
                if (h.uMsg == WM_LBUTTONDOWN)
                {
                    mciSendCommand(OpenParms.wDeviceID, MCI_PAUSE, NULL, (DWORD)&PlayParms);
                }

            }
            if (h.x > 490 && h.x < 540 && h.y>180 && h.y < 230)
            {
                if (h.uMsg == WM_LBUTTONDOWN)
                {
                    mciSendCommand(OpenParms.wDeviceID, MCI_RESUME, NULL, (DWORD)&PlayParms);
                }

            }
            if (h.x > 530 && h.x < 640 && h.y>420 && h.y < 480)
            {
                if (h.uMsg == WM_LBUTTONDOWN)
                {                   
                    mciSendCommand(OpenParms.wDeviceID, MCI_STOP, NULL, (DWORD)&PlayParms);
                    break;
                }

            }
        }
    }
};






int main()
{
    Manager m;
    while (1) {
       
        m.Music_system();
    }
    closegraph();          // 关闭绘图窗口
}