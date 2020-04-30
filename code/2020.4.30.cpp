#if 0
//1.��ŵ���ĵݹ����
#include<iostream>
using namespace std;
void moveDisk(int i, const char x, const char y) {
	cout << "Moving disk " << i << " from " << x << " to " << y << endl;
}

//aΪ��ʼ������b����c
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
//2.�Թ�����ĵݹ����
#include<iostream>
using namespace std;
//����һ��8x8���Թ�������1��ʾ����ͨ�е�ǽ�ڣ�0��ʾ��ͨ�е�·��
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
			if (maze[i][j] == 1)  cout << "*";           //*��ʾǽ��
			else if (maze[i][j] == -1) cout << "o";      //o��ʾ���Թ��Ĺ켣
			else cout << " ";                            //��ͨ�е��ÿո��ʾ
		}
		cout << endl;
	}
}

void pass(int x, int y) {
	maze[x][y] = -1;
	if (x == 6 && y == 6) {                               //�������꣨6��6��
		cout << "�Թ��߷���" << endl;
		print();
		cout << endl;
	};
	//�ݹ�
	if (maze[x][y + 1] == 0) pass(x, y + 1);
	if (maze[x + 1][y] == 0) pass(x + 1, y);
	if (maze[x - 1][y] == 0) pass(x - 1, y);
	if (maze[x][y - 1] == 0) pass(x, y - 1);
	maze[x][y] = 0;

}
int main() {
	int a = 1, b = 1;                           //������꣨1��1��
	cout << "��ͼ��ϢΪ��" << endl;
	print();
	cout << endl;
	pass(a, b);
	return 0;
}
#endif