#if 1
#include<iostream>
using namespace std;
class Matrix
{
public:
	int m_row, m_col;
	int **matrix;

	//��������
	void creatMatrix()
	{
		int row, col;
		cout << "����������������" << endl;
		cin >> row >> col;
		int** m;
		m = (int**)malloc(row * sizeof(int*));
		for (int i = 0; i < row; i++)
			m[i] = (int*)malloc(col * sizeof(int));
		cout << "������ľ���" << endl;
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

	Matrix(){}       //�޲ι���

	//��������
	Matrix(const Matrix& m)
	{
		this->m_row = m.m_row;
		this->m_col = m.m_col;
		this->matrix = m.matrix;
	}

	//���������+
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

	//���������-
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

	//���������*
	Matrix operator*(Matrix& m)
	{
		Matrix temp;
		temp.m_row = this->m_row;
		temp.m_col = m.m_col;
		//����ռ� 
		temp.matrix= (int**)malloc(this->m_row * sizeof(int*));
		for (int i = 0; i < this->m_row; i++)
		{
			temp.matrix[i] = (int*)malloc(m.m_col * sizeof(int));
		}
		
		//�ÿ� 
		for (int i = 0; i < temp.m_row; i++)
		{
			for (int j = 0; j < temp.m_col; j++)
			{
				temp.matrix[i][j] = 0;
			}
		}
		
		//����˷���ʵ�� 
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

	//��ӡ����
	void Print()
	{
		cout << "������Ϊ��" << endl;
		for (int i = 0; i < this->m_row; i++)
		{
			for (int j = 0; j < this->m_col; j++)
			{
				cout << this->matrix[i][j] << " ";
			}
			cout << endl;
		}
	}

	//����
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
