#if 1
#include<iostream>
using namespace std;
class Matrix
{
public:
	int m_row, m_col;
	int **matrix;

	//创建矩阵
	void creatMatrix()
	{
		int row, col;
		cout << "输入行数与列数：" << endl;
		cin >> row >> col;
		int** m;
		m = (int**)malloc(row * sizeof(int*));
		for (int i = 0; i < row; i++)
			m[i] = (int*)malloc(col * sizeof(int));
		cout << "输入你的矩阵：" << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cin >> m[i][j];
			}
		}
		this->m_col = col;
		this->m_row = row;
		this->matrix = m;
		cout << endl;
	}

	Matrix(){}       //无参构造

	//拷贝构造
	Matrix(const Matrix& m)
	{
		this->m_row = m.m_row;
		this->m_col = m.m_col;
		this->matrix = m.matrix;
	}

	//重载运算符+
	Matrix operator+(Matrix &m)
	{
		Matrix temp;
		temp = m;
		for (int i = 0; i < this->m_row; i++)
		{
			for (int j = 0; j < this->m_col; j++)
			{
				temp.matrix[i][j] = this->matrix[i][j] + m.matrix[i][j];
			}
		}
		return temp;
	}

	//重载运算符-
	Matrix operator-(Matrix& m)
	{
		Matrix temp;
		temp = m;
		for (int i = 0; i < this->m_row; i++)
		{
			for (int j = 0; j < this->m_col; j++)
			{
				temp.matrix[i][j] = this->matrix[i][j] - m.matrix[i][j];
			}
		}
		return temp;
	}

	//重载运算符*
	Matrix operator*(Matrix& m)
	{
		Matrix temp;
		temp.m_row = this->m_row;
		temp.m_col = m.m_col;
		//分配空间 
		temp.matrix= (int**)malloc(this->m_row * sizeof(int*));
		for (int i = 0; i < this->m_row; i++)
		{
			temp.matrix[i] = (int*)malloc(m.m_col * sizeof(int));
		}
		
		//置空 
		for (int i = 0; i < temp.m_row; i++)
		{
			for (int j = 0; j < temp.m_col; j++)
			{
				temp.matrix[i][j] = 0;
			}
		}
		
		//具体乘法的实现 
		for (int i = 0; i < this->m_row; i++)
		{
			for (int j = 0; j < m.m_col; j++)
			{
				for (int k = 0; k < this->m_col; k++) {
					
					temp.matrix[i][j] += this->matrix[i][k] * m.matrix[k][j];
				}

			}
		}
		return temp;
	}

	//打印矩阵
	void Print()
	{
		cout << "计算结果为：" << endl;
		for (int i = 0; i < this->m_row; i++)
		{
			for (int j = 0; j < this->m_col; j++)
			{
				cout << this->matrix[i][j] << " ";
			}
			cout << endl;
		}
	}

	//析构
	~Matrix()
	{
		this->m_row = 0;
		this->m_col = 0;
		this->matrix = NULL;
	}
};


int main()
{
	Matrix m1,m2;
	Matrix m;
	m1.creatMatrix();
	m2.creatMatrix();	

	//m = m1 + m2;   

	//m = m1 - m2;

	m = m1 * m2;

	m.Print();

	system("pause");
	return 0;
}
#endif
