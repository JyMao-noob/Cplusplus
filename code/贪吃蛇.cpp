#include<iostream> 
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>


void gotoxy(int x, int y);
void start();
void print();
void del();
void change(int a, int b);
int control();
void move();
void create_food();
void eat();
int fail();


typedef struct Snake
{
	int x;
	int y;
	Snake* next;
}snake;

struct Food
{
	int x;
	int y;
}food;


int num = 0;//食物数量 
snake* head;//头部 
snake* tail;//尾巴 
char key;//按键的获取 
int score = 0;//分数 
int count = 0;//小蛇身体长度 
char ans[10];
int left = 1;
int up = 1;
int down = 1;
int right = 1;


int main()
{
	
	start();
	if (!control())
	{
		std::cout<<"游戏结束！\n";
		system("pause");

		
	}

	return 0;
}
//光标的控制 
void gotoxy(int x, int y)
{
	HANDLE handle;
	COORD coord;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(handle, coord);
}
//打印空格来表示小蛇的身体 
void print(int x, int y)
{
	gotoxy(x, y);
	printf("■");
}
//打印空格来删除食物,或者小蛇的身体 
void del(int x, int y)
{
	gotoxy(x, y);
	printf("  ");
}

//游戏开始界面 
void start()
{
	int x = 0;
	int y = 0;
	system("cls");
	for (int i = 0; i < 20; i++)
	{
		printf("■");
	}
	gotoxy(x, y);
	for (int i = 0; i < 20; i++)
	{
		printf("■");
		gotoxy(x, y++);
	}
	gotoxy(x, y -= 1);
	for (int i = 0; i < 20; i++)
	{
		printf("■");
		gotoxy(x += 2, y);
	}
	gotoxy(x -= 2, y);
	for (int i = 0; i < 20; i++)
	{
		printf("■");
		gotoxy(x, y--);
	}

	//蛇的初始化
	head = (snake*)malloc(sizeof(snake));
	tail = (snake*)malloc(sizeof(snake));
	snake* p = (snake*)malloc(sizeof(snake));

	head->x = 10;
	head->y = 10;

	p->x = 12;
	p->y = 10;

	tail->x = 14;
	tail->y = 10;

	head->next = p;
	p->next = tail;
	tail->next = NULL;


}
//整个程序的控制 
int control()
{
	while (1)
	{

		if (_kbhit())
		{
			key = _getch();
		}
		if (num == 0)
			create_food();
		gotoxy(0, 22);
		move();
		gotoxy(0, 22);
		eat();
		gotoxy(0, 22);
		if (!fail()) return 0;
	}

	return 1;
}
//通过按键控制小蛇 
void move()
{
	snake* p = head;
	int a = p->x;
	int b = p->y;
	while (p->next != NULL)
	{
		del(p->x, p->y);
		p = p->next;
	}
	del(p->x, p->y);

	switch (key)
	{
	case 'w':
		if (up)
		{
			head->y -= 1;
			change(a, b);
			up = 1;
			down = 0;
			left = 1;
			right = 1;
			break;
		}
		break;
	case 's':
		if (down)
		{
			head->y += 1;
			change(a, b);
			up = 0;
			down = 1;
			left = 1;
			right = 1;
			break;
		}
		break;
	case 'a':
		if (left)
		{
			head->x -= 2;
			change(a, b);
			up = 1;
			down = 1;
			left = 1;
			right = 0;
			break;
		}
		break;
	case 'd':
		if (right)
		{
			head->x += 2;
			change(a, b);
			up = 1;
			down = 1;
			left = 0;
			right = 1;
			break;
		}
		break;
	default:
		break;
	}
	p = head;
	gotoxy(p->x, p->y);
	printf("⊙");
	p = p->next;
	while (p->next != NULL)
	{
		print(p->x, p->y);
		p = p->next;
	}
	print(p->x, p->y);
	Sleep(100 + count * 10);

}
//改变链表每个节点的x,y来实现移动 
void change(int a, int b)
{
	snake* p = head->next;
	int mid1, mid2, _mid1, _mid2;
	mid1 = a;
	mid2 = b;

	while (p->next != NULL)
	{
		_mid1 = p->x;
		_mid2 = p->y;
		p->x = mid1;
		p->y = mid2;
		mid1 = _mid1;
		mid2 = _mid2;
		p = p->next;
	}
	p->x = mid1;
	p->y = mid2;
}
//创造食物 
void create_food()
{
	srand(time(NULL));
	int r_x = rand() % 35 + 2;
	int r_y = rand() % 18 + 1;
	snake* p = head;

	while (1)
	{
		if ((r_x == p->x && r_y == p->y) || r_x % 2 != 0)
		{
			p = head;
			r_x = rand() % 35 + 2;
			r_y = rand() % 18 + 1;
		}
		if (p->next == NULL) break;
		else p = p->next;
	}

	food.x = r_x;
	food.y = r_y;
	num = 1;;
	gotoxy(r_x, r_y);
	printf("*");
}
//吃食物,增加蛇的长度 
void eat()
{
	snake* p = head;
	if (p->x == food.x && p->y == food.y)
	{
		snake* _new = (snake*)malloc(sizeof(snake));
		while (p->next != NULL)
			p = p->next;
		p->next = _new;
		_new->next = NULL;
		num = 0;
		score += 10;
		count++;
	}
}
//失败的条件 
int fail()
{
	snake* p = head;
	if (p->x <= 1 || p->x >= 38 ||
		p->y <= 0 || p->y >= 19)
		return 0;
	else
	{
		p = p->next;
		while (1)
		{
			if (head->x == p->x && p->y == head->y)
			{
				return 0;
			}
			if (p->next != NULL) p = p->next;
			else break;
		}
	}
	return 1;
}
