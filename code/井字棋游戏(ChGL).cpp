#if 0
//以下是ChGL库
#include <iostream>
using namespace std;
using color = char;  //定义一个表示颜色的color类型，每种字符就是一种颜色
color* framebuffer{ nullptr };          //帧缓冲器
int framebuffer_width, framebuffer_height;
color clear_color{ ' ' };                //清屏颜色  

bool initWindow(int width, int height);  //初始化一个窗口，返回bool值表示成功还是失败
void clearWindow();               //清空窗口内容
void destoryWindow();             //销毁窗口，释放帧缓冲器占用的内存
void show();                      //显示帧缓冲区的图像
void setPixel(const int x, const int y, color c = ' ');            //设置像素的颜色
color getPixel(const int x, const int y);                       //设置像素的颜色
void set_clear_color(color c) { clear_color = c; }
color get_clear_color() { return clear_color; }

//初始化一个窗口，返回bool值表示成功还是失败
bool initWindow(int width, int height) {

	framebuffer = new color[width * height];
	if (!framebuffer) return false;
	framebuffer_width = width;
	framebuffer_height = height;
	clearWindow();
	return true;
}

//用清屏颜色clear_color清空窗口内容
void clearWindow() {
	if (!framebuffer) return;
	for (int y = 0; y < framebuffer_height; y++)
		for (int x = 0; x < framebuffer_width; x++)
			framebuffer[y * framebuffer_width + x] = clear_color;

}

//销毁窗口，释放帧缓冲器占用的内存
void destoryWindow() {
	if (!framebuffer)return;
	delete[] framebuffer;
	framebuffer = nullptr;
}

//显示帧缓冲区的图像
void show() {
	for (int y = 0; y < framebuffer_height; y++) {
		for (int x = 0; x < framebuffer_width; x++)
			std::cout << framebuffer[y * framebuffer_width + x];
		std::cout << '\n';
	}
}

void setPixel(const int x, const int y, color c) {
	framebuffer[y * framebuffer_width + x] = c;
}

color getPixel(const int x, const int y) {
	return framebuffer[y * framebuffer_width + x];
}

//以下进行游戏设计

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <string>
using namespace std;
//落子函数
void Change(int& xy) {
	cout << "请输入落子种类(x或y):" << endl;
	char i;
	cin >> i;
	int x, y;
	x = xy / 10;
	y = xy % 10;
	if (x == 1 && y == 1) setPixel(0, 0, i);
	if (x == 1 && y == 2) setPixel(2, 0, i);
	if (x == 1 && y == 3) setPixel(4, 0, i);
	if (x == 2 && y == 1) setPixel(0, 2, i);
	if (x == 2 && y == 2) setPixel(2, 2, i);
	if (x == 2 && y == 3) setPixel(4, 2, i);
	if (x == 3 && y == 1) setPixel(0, 4, i);
	if (x == 3 && y == 2) setPixel(2, 4, i);
	if (x == 3 && y == 3) setPixel(4, 4, i);
}
//判断是否胜利的函数
int isWin() {
	if (getPixel(0, 0) == getPixel(0, 2) && getPixel(0, 0) == getPixel(0, 4) && getPixel(0, 0)!=' ' && getPixel(0, 2)!=' ' && getPixel(0, 4)!=' ')  return 1;
	if (getPixel(2, 0) == getPixel(2, 2) && getPixel(2, 0) == getPixel(2, 4) && getPixel(2, 0) != ' ' && getPixel(2, 2) != ' ' && getPixel(2, 4) != ' ')  return 1;
	if (getPixel(4, 0) == getPixel(4, 2) && getPixel(4, 0) == getPixel(4, 4) && getPixel(4, 0) != ' ' && getPixel(4, 2) != ' ' && getPixel(4, 4) != ' ')  return 1;
	if (getPixel(0, 0) == getPixel(2, 0) && getPixel(0, 0) == getPixel(4, 0) && getPixel(0, 0) != ' ' && getPixel(2, 0) != ' ' && getPixel(4, 0) != ' ')  return 1;
	if (getPixel(0, 2) == getPixel(2, 2) && getPixel(0, 2) == getPixel(4, 2) && getPixel(0, 2) != ' ' && getPixel(2, 2) != ' ' && getPixel(4, 2) != ' ')  return 1;
	if (getPixel(0, 4) == getPixel(2, 4) && getPixel(0, 4) == getPixel(4, 4) && getPixel(0, 4) != ' ' && getPixel(2, 4) != ' ' && getPixel(4, 4) != ' ')  return 1;
	if (getPixel(0, 0) == getPixel(2, 2) && getPixel(0, 0) == getPixel(4, 4) && getPixel(0, 0) != ' ' && getPixel(2, 2) != ' ' && getPixel(4, 4) != ' ')  return 1;
	if (getPixel(0, 4) == getPixel(2, 2) && getPixel(0, 4) == getPixel(4, 0) && getPixel(0, 4) != ' ' && getPixel(2, 2) != ' ' && getPixel(4, 0) != ' ')  return 1;
	else return -1;
	
}
int main() {
	if (!initWindow(5, 5)) {
		return 1;
	}
	set_clear_color(' ');
	clearWindow();
	 //绘制井字棋棋盘
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			if (x % 2 != 0 && y % 2 == 0) setPixel(x, y, '|');
			if(x%2==0 && y%2!=0) setPixel(x, y, '-');
		}
	}    
	      while(true){
			  show();
			  int xy;
			  cout << endl;
			  cout << "请输入落子位置(行+列，如12表示第一行第二列）：" << endl;
			  cin >> xy;
			  Change(xy);
			  int ret;
			  ret=isWin();
			   if (ret == 1) {
				  cout << "本轮游戏结束" << endl;
				  system("pause");
				  return 0;
				  break;
			  }			  
			  system("cls");
		  }
	
}
#endif