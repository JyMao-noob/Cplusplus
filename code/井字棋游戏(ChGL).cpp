#if 0
//������ChGL��
#include <iostream>
using namespace std;
using color = char;  //����һ����ʾ��ɫ��color���ͣ�ÿ���ַ�����һ����ɫ
color* framebuffer{ nullptr };          //֡������
int framebuffer_width, framebuffer_height;
color clear_color{ ' ' };                //������ɫ  

bool initWindow(int width, int height);  //��ʼ��һ�����ڣ�����boolֵ��ʾ�ɹ�����ʧ��
void clearWindow();               //��մ�������
void destoryWindow();             //���ٴ��ڣ��ͷ�֡������ռ�õ��ڴ�
void show();                      //��ʾ֡��������ͼ��
void setPixel(const int x, const int y, color c = ' ');            //�������ص���ɫ
color getPixel(const int x, const int y);                       //�������ص���ɫ
void set_clear_color(color c) { clear_color = c; }
color get_clear_color() { return clear_color; }

//��ʼ��һ�����ڣ�����boolֵ��ʾ�ɹ�����ʧ��
bool initWindow(int width, int height) {

	framebuffer = new color[width * height];
	if (!framebuffer) return false;
	framebuffer_width = width;
	framebuffer_height = height;
	clearWindow();
	return true;
}

//��������ɫclear_color��մ�������
void clearWindow() {
	if (!framebuffer) return;
	for (int y = 0; y < framebuffer_height; y++)
		for (int x = 0; x < framebuffer_width; x++)
			framebuffer[y * framebuffer_width + x] = clear_color;

}

//���ٴ��ڣ��ͷ�֡������ռ�õ��ڴ�
void destoryWindow() {
	if (!framebuffer)return;
	delete[] framebuffer;
	framebuffer = nullptr;
}

//��ʾ֡��������ͼ��
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

//���½�����Ϸ���

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <string>
using namespace std;
//���Ӻ���
void Change(int& xy) {
	cout << "��������������(x��y):" << endl;
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
//�ж��Ƿ�ʤ���ĺ���
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
	 //���ƾ���������
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
			  cout << "����������λ��(��+�У���12��ʾ��һ�еڶ��У���" << endl;
			  cin >> xy;
			  Change(xy);
			  int ret;
			  ret=isWin();
			   if (ret == 1) {
				  cout << "������Ϸ����" << endl;
				  system("pause");
				  return 0;
				  break;
			  }			  
			  system("cls");
		  }
	
}
#endif