//第一题
#if 0
#include<iostream>
using namespace std;
int main() {
	int n;
	cout << "请输入一个正整数：";
	cin >> n;
	cout << "\n" << "小于" << n << "的质数有：\n";
	int i, j, flag;
	for (i = 2; i < n; i++) {
		flag = 1;
		for (j = 2; j < i; j++) {
			if (i % j == 0) flag = 0;
		}
		if (flag == 1) cout << i << "\t";
	}
}
#endif

//第二题
#if 0
#include<iostream>
using namespace std;
int main() {
	int n,i=1,j=0;
	cin >> n;
	for (i; i <= n; i++) {
		for (j; j < n - i; j++) { cout << "  "; };
		for (j; j < n; j++) { cout << "* "; };
		j = 0;
		cout << "\n";
	}
}
#endif

//第三题
#if 0
#include<iostream>
#include<cmath>
using namespace std;
int main() {
	double a,b,c,x1,x2,delta;
	cout << "请输入Ax^2+Bx+C=0的3项系数：\n";
	cin >> a >> b >> c;
	delta = b * b - 4 * a * c;
	if (delta > 0) {
		x1 = (-b + sqrt(delta)) / (2 * a);
		x2 = (-b - sqrt(delta)) / (2 * a);
		cout << "\n该方程有2个解，分别为"<<"x1="<<x1<<"和"<<"x2="<<x2;
	}
	if (delta == 0) { 
		x1 = (-b) / (2 * a); 
		x2 = x1;
		cout << "该方程有唯一解："<<"x1=x2="<<x1;
	}
	if (delta < 0) {
		cout << "该方程无解。";
	}
	
}
#endif