#if 0
//实战1 ：立方体
#include<iostream>
#include<string>
using namespace std;
class Cube {
private:
	int m_L, m_W, m_H;
public:
	//读写长宽高
	void setL(int l) {
		m_L = l;
	}
	void setW(int l) {
		m_W = l;
	}
	void setH(int l) {
		m_H = l;
	}

	int getL() {
		return m_L;
	}
	int getW() {
		return m_W;
	}
	int getH() {
		return m_H;
	}
	//求出面积和体积  
	int findS() {
		return 2*(m_L * m_H + m_H * m_W + m_W * m_L);
	}
	int findV() {
		return m_L * m_W * m_H;
	}

	bool isSame(Cube &b) {
		if (getH() == b.getH() && getL() == b.getL() && getW() == b.getW()) return true;
		else return false;
	}
};

bool isSame(Cube &a, Cube &b) {
	if (a.getH ()== b.getH() && a.getL() == b.getL() && a.getW() == b.getW()) return true;
	else return false;
}

int main() {
	Cube c1, c2;
	c1.setH(10);
	c1.setL(10);
	c1.setW(10);
	cout << "S of c1 is " << c1.findS() << endl;
	cout << "V of c1 is " << c1.findV() << endl;
	c2.setH(10);
	c2.setL(10);
	c2.setW(10);
	cout << "S of c1 is " << c2.findS() << endl;
	cout << "V of c1 is " << c2.findV() << endl;

	bool ret1;
	ret1 = isSame(c1, c2);
	cout << "c1 and c2 are " << (ret1 == 1 ? "same" : "not same") << endl;;

	bool ret2;
	ret2 = c1.isSame(c2);
	cout << "c1 and c2 are " << (ret2 == 1 ? "same" : "not same")<<endl;
}
#endif

#if 0
//实战2 ：点与圆的关系
#include<iostream>
#include<string>
using namespace std;

class Point {
private:
	double m_X;
	double m_Y;
public:
	//读写坐标（x，y）
	void setX(double x) {
		m_X = x;
	}
	void setY(double x) {
		m_Y = x;
	}
	double getX() {
		return m_X;
	}
	double getY() {
		return m_Y;
	}
};

class Circle {
	//读写半径、圆心
private:
	double m_R;
	Point m_Center;
public:
	void setR(double r) {
		m_R = r;
	}
	void setCenter(Point r) {
		m_Center = r;
	}
	double getR() {
		return m_R;
	}
	Point getCenter() {
		return m_Center;
	}

};

void func(Circle& a, Point& b) {
	double R = a.getR()* a.getR();    //半径平方
	double D = (b.getX() - a.getCenter().getX()) * (b.getX() - a.getCenter().getX()) +
		(b.getY() - a.getCenter().getY()) * (b.getY() - a.getCenter().getY());  //距离平方
	
	if (R == D) cout << "点在圆上！" << endl;
	if (R > D) cout << "点在圆内！" << endl;
	if (R < D) cout << "点在圆外！" << endl;
}

int main() {
	Point p,center;
	Circle c1;
	p.setX(10);
	p.setY(10);
	c1.setR(10);
	center.setX(10);
	center.setY(0);
	c1.setCenter(center);
	func(c1, p);
}
#endif