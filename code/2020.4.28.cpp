//1.ѡ������
#if 0
#include<iostream>
#define len 10
int main() {
	int a[len] = {62,45,91,14,26,38,71,61,55,41};    //��10����������Ϊ��
	int times = 0,temp;
	int i = 0, j = 0;
	for (i; i < len - 1; i++) {
		for (j = i + 1; j < len; j++) {
			if (a[i] > a[j]) {
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
				times++;
			}
		}
	}
	std::cout << "һ���ȽϺ��ƶ�������" << times << "�Ρ�\n" << "��С�����˳��Ϊ��\n";
	for (i = 0; i < len; i++)
		std::cout << a[i] << "\t";

}
#endif

//2.Floyd�㷨
#if 0
#include<iostream>
using namespace std;
int main() {
	int n = 4;
	int max = 10000;
	double D[][4] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
	cout << "���������ͼ��(����ͨ������Ϊ10000)\n";
	for(auto u=0;u<n;u++)
		for (auto v = 0; v < n; v++) {
			cin >> D[u][v];
		}
	unsigned int P[][4] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
	for (auto u = 0; u < n; u++)
		for (auto v = 0; v < n; v++)
			P[u][v] = u;
	cout << "��ʼ��D��P����\n";
	for (auto& row : D) {
		for (auto col : row)
			cout << col << "\t";
		cout << "\n";
	}
	cout << "\n";
	for (auto& row : P) {
		for (auto col : row)
			cout << col << "\t";
		cout << "\n";
	}
	cout << std::endl;

	for(auto w=0;w<n;w++)
		for(auto u=0;u<n;u++)
			for(auto v=0;v<n;v++)
				if (w != u && w != v && D[u][w] + D[w][v] < D[u][v]) {
					D[u][v] = D[u][w] + D[w][v];
					P[u][v] = P[w][v];
				}

	cout << "���յ�D��P����\n";
	for (auto& row : D) {
		for (auto col : row)
			cout << col << "\t";
		cout << "\n";
	}
	cout << "\n";
	for (auto& row : P) {
		for (auto col : row)
			cout << col << "\t";
		cout << "\n";
	}
	cout << std::endl;

	cout << "����Ҫ��ѯ��2���㣨A->B����\n";
	int u, v;
	cin >> u >> v;

			cout << u << "��" << v << "���������·��Ϊ��";
			cout << v << ",";
			auto w{ P[u][v] };
			for (auto w{ P[u][v] }; w != u;) {
				cout << w << ",";
				w = P[u][w];
			}
			cout << u << std::endl;

		
}
#endif
