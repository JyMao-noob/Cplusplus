#if 0
//1.汉诺塔的递归求解
#include<iostream>
using namespace std;
void moveDisk(int i, const char x, const char y) {
	cout << "Moving disk " << i << " from " << x << " to " << y << endl;
}

//a为起始，借助b，到c
void move(int n, const char a, const char b, const char c) {
	if (n < 1) return;
	move(n - 1, a, c, b);
	moveDisk(n, a, c);
	move(n - 1, b, a, c);
}
int main() {
	
	move(4, 'A', 'B', 'C');

}
#endif

#if 1
//2.迷宫问题的递归求解
#include<iostream>
using namespace std;
//创建一个8x8的迷宫，其中1表示不可通行的墙壁，0表示可通行的路径
int maze[8][8] = {
{1,1,1,1,1,1,1,1},
{1,0,0,0,0,0,1,1},
{1,1,1,0,0,0,1,1},
{1,0,0,0,1,0,0,1},
{1,0,1,1,0,0,1,1},
{1,0,1,0,0,1,0,1},
{1,0,1,0,0,0,0,1},
{1,1,1,1,1,1,1,1}
};
void print() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (maze[i][j] == 1)  cout << "*";           //*表示墙壁
			else if (maze[i][j] == -1) cout << "o";      //o表示走迷宫的轨迹
			else cout << " ";                            //可通行的用空格表示
		}
		cout << endl;
	}
}

void pass(int x, int y) {
	maze[x][y] = -1;
	if (x == 6 && y == 6) {                               //出口坐标（6，6）
		cout << "迷宫走法：" << endl;
		print();
		cout << endl;
	};
	//递归
	if (maze[x][y + 1] == 0) pass(x, y + 1);
	if (maze[x + 1][y] == 0) pass(x + 1, y);
	if (maze[x - 1][y] == 0) pass(x - 1, y);
	if (maze[x][y - 1] == 0) pass(x, y - 1);
	maze[x][y] = 0;

}
int main() {
	int a = 1, b = 1;                           //入口坐标（1，1）
	cout << "地图信息为：" << endl;
	print();
	cout << endl;
	pass(a, b);
	return 0;
}
#endif