//��һ��
#if 0
#include<iostream>
using namespace std;
int main() {
	int n;
	cout << "������һ����������";
	cin >> n;
	cout << "\n" << "С��" << n << "�������У�\n";
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

//�ڶ���
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

//������
#if 0
#include<iostream>
#include<cmath>
using namespace std;
int main() {
	double a,b,c,x1,x2,delta;
	cout << "������Ax^2+Bx+C=0��3��ϵ����\n";
	cin >> a >> b >> c;
	delta = b * b - 4 * a * c;
	if (delta > 0) {
		x1 = (-b + sqrt(delta)) / (2 * a);
		x2 = (-b - sqrt(delta)) / (2 * a);
		cout << "\n�÷�����2���⣬�ֱ�Ϊ"<<"x1="<<x1<<"��"<<"x2="<<x2;
	}
	if (delta == 0) { 
		x1 = (-b) / (2 * a); 
		x2 = x1;
		cout << "�÷�����Ψһ�⣺"<<"x1=x2="<<x1;
	}
	if (delta < 0) {
		cout << "�÷����޽⡣";
	}
	
}
#endif