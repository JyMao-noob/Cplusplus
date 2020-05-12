#include "Management.h"

Management::Management(){
	ifstream ifs;
	ifs.open(filename, ios::in);
	//1.�ļ�������
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl; //�������
		this->m_EmpNum = 0;  //��ʼ������
		this->m_FileIsEmpty = true; //��ʼ���ļ�Ϊ�ձ�־
		this->m_EmpArray = NULL; //��ʼ������
		ifs.close(); //�ر��ļ�
		return;
	}
	//2.�ļ����ڣ�����û�м�¼
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��!" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	//3.�ļ��������м�¼
	int num = this->get_EmpNum();
	this->m_EmpNum = num;
	this->m_EmpArray = new Employee * [this->m_EmpNum];
	init_Emp();

}

void Management::Show_Menu() {
	cout << "*******************************************" << endl;
	cout << "***  ��ӭʹ�ù�Ա��Ĺ���֧������ϵͳ�� ***" << endl;
	cout << "************* 0.�˳�����ϵͳ  *************" << endl;
	cout << "************* 1.����ְ����Ϣ  *************" << endl;
	cout << "************* 2.��ʾ����ְ����Ϣ  *********" << endl;
	cout << "********* *** 3.��ʾĳһ����ְ����Ϣ  *****" << endl;
	cout << "************* 4.ɾ��ְ����Ϣ  *************" << endl;
	cout << "************* 5.�޸�ְ����Ϣ  *************" << endl;
	cout << "************* 6.����ְ����Ϣ  *************" << endl;
	cout << "*******************************************" << endl;
	cout << endl;
}

void Management::exitsystem() {
	cout << "��ӭ�´���ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

void Management::add_Emp() {
	cout << "����������ְ�������� " << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum <= 0) { cout << "�������󣬲���ʧ�ܣ�" << endl; }
	else {
		int newSize = this->m_EmpNum + addNum; //�����¿ռ��С
		Employee** newSpace = new Employee * [newSize];//�����¿ռ�
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		for (int i = 0; i < addNum; i++)
		{
			int SSN;
			string name;
			int hours;
			double earning;
			double wage;
			double baseSalary;
			int Gross_Sale;
			double Commission_rate;
			int select;
			cout << "������Ҫ��ӵ�ְ�����ͣ�" << endl
				<< "1.Salaried-Employee" << endl
				<< "2.Hourly-Employee" << endl
				<< "3.Commission-Employee" << endl
				<< "4.Basesalaryed-commission-Employee" << endl;
			cin >> select;
			switch (select) {
			case 1:
			{   cout << "�������Ա����������" << endl;
			    cin >> name;
			    cout << "�������Ա����SSN��9λ���֣���" << endl;
				cin >> SSN;
				cout << "�������Ա���Ĺ̶����ʣ�0-10000����" << endl;
				cin >> baseSalary;			
				earning = baseSalary;
				newSpace[this->m_EmpNum + i] = new Salaried_Employee(select,name, SSN,earning);
				newSpace[this->m_EmpNum + i]->baseSalary = baseSalary;
				break;
			}
			case 2:
			{
				cout << "�������Ա����������" << endl;
				cin >> name;
				cout << "�������Ա����SSN��9λ���֣���" << endl;
				cin >> SSN;
				cout << "�������Ա����ʱн��0.1-100����" << endl;
				cin >> wage;
				cout << "�������Ա���Ĺ���ʱ����" << endl;
				cin >> hours;
				if (hours <= 40) earning = wage * hours;
				else earning = 40 * wage + (hours - 40) * wage * 1.5;
				newSpace[this->m_EmpNum + i] = new Hourly_Employee(select, name, SSN,earning);
				newSpace[this->m_EmpNum + i]->hours = hours;
				newSpace[this->m_EmpNum + i]->wage = wage;
				break;

			}
			case 3:
			{
				cout << "�������Ա����������" << endl;
				cin >> name;
				cout << "�������Ա����SSN��9λ���֣���" << endl;
				cin >> SSN;
				cout << "�������Ա������������ʣ�0-0.5����" << endl;
				cin >> Commission_rate;
				cout << "�������Ա������������0-500����" << endl;
				cin >> Gross_Sale;
				earning = Commission_rate * Gross_Sale;
				newSpace[this->m_EmpNum + i] = new Commission_Employee(select, name, SSN,earning);
				newSpace[this->m_EmpNum + i]->Commission_rate= Commission_rate;
				newSpace[this->m_EmpNum + i]->Gross_Sale = Gross_Sale;
				break;
			}
			case 4:
			{
				cout << "�������Ա����������" << endl;
				cin >> name;
				cout << "�������Ա����SSN��9λ���֣���" << endl;
				cin >> SSN;
				cout << "�������Ա���Ĺ̶����ʣ�0-10000����" << endl;
				cin >> baseSalary;
				cout << "�������Ա������������ʣ�0-0.5����" << endl;
				cin >> Commission_rate;
				cout << "�������Ա������������0-500����" << endl;
				cin >> Gross_Sale;
				earning = baseSalary + Commission_rate * Gross_Sale;
				newSpace[this->m_EmpNum + i] = new BasePlus_Commission_Employee(select, name, SSN,earning);
				newSpace[this->m_EmpNum + i]->baseSalary = baseSalary;
				newSpace[this->m_EmpNum + i]->Commission_rate = Commission_rate;
				newSpace[this->m_EmpNum + i]->Gross_Sale = Gross_Sale;
				break;
			}
			}


		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = newSpace;
		this->m_EmpNum = newSize;		
		this->m_FileIsEmpty = false;//����ְ����Ϊ�ձ�־
		cout << "�ɹ����" << addNum << "����ְ��" << endl;
		this->save();
	}
	system("pause");
	system("cls");

}

void Management::save()
{
	ofstream ofs;
	ofs.open(filename, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{     
		ofs <<this->m_EmpArray[i]->kind<<" "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_SSN << " "
			<< this->m_EmpArray[i]->m_earning << endl;
	}
	ofs.close();
}

int Management::get_EmpNum()
{
	ifstream ifs;
	ifs.open(filename, ios::in);
	int kind;
	string name;
	int SSN;
	int num = 0;
	double earning;
	while (ifs>>kind && ifs >> name && ifs >> SSN && ifs >> earning) {
		num++;
	}
	ifs.close();
	return num;
}

void Management::init_Emp()
{
	ifstream ifs;
	ifs.open(filename, ios::in);
	string name;
	int SSN;
	int kind;
	double earning;
	int index = 0;
	while (ifs>>kind && ifs >> name && ifs >> SSN && ifs >> earning) {
		Employee* emp = NULL;
		if (kind ==1)
		{
			emp = new Salaried_Employee(kind, name, SSN,earning);			
		}
		if (kind == 3)
		{
			emp = new Commission_Employee(kind, name, SSN, earning);
		}
		if (kind == 2)
		{
			emp = new Hourly_Employee(kind, name, SSN, earning);
		}
		if (kind ==4)
		{
			emp = new BasePlus_Commission_Employee(kind, name, SSN, earning);
		}
		this->m_EmpArray[index] = emp;
		
		index++;
		
	}
}

void Management::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{		for (int i = 0; i < m_EmpNum; i++)
		{			
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
void Management::Show2_Emp()
{
	if (this->m_FileIsEmpty)
	{		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "���������ְ�����ͣ�" << endl;
		cout << "1.Salaried_Employee" << endl;
		cout << "2.Hourly_Employee" << endl;
		cout << "3.Commission_Employee" << endl;
		cout << "4.BasePlus_Commission_Employee" << endl;
		int select;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
			{
				if(this->m_EmpArray[i]->kind==select) this->m_EmpArray[i]->showInfo();
			}
		
	}
	system("pause");
	system("cls");
}
int Management::IsExist1(int SSN)
{
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_SSN == SSN)
		{
			index = i;
			break;
		}
	}
	return index;
}
int Management::IsExist2(string name)
{
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_name == name)
		{
			index = i;
			break;
		}
	}
	return index;
}
void Management::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "���밴(     )ɾ��" << endl;
		cout << "1.����" << endl;
		cout << "2.ְ��SSN���" << endl;
		int t;
		cin >> t;
		if (t == 2) {
			//��ְ��SSNɾ��
			cout << "��������Ҫɾ����ְ��SSN�ţ�" << endl;
			int SSN = 0;
			cin >> SSN;
			int index = this->IsExist1(SSN);
			if (index != -1)  //˵��index��λ��������Ҫɾ��
			{
				for (int i = index; i < this->m_EmpNum - 1; i++)
				{
					this->m_EmpArray[i] = this->m_EmpArray[i + 1];
				}
				this->m_EmpNum--;
				this->save(); //ɾ��������ͬ�����ļ���
				cout << "ɾ���ɹ���" << endl;
			}
			else
			{
				cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
			}
		}
		if (t == 1)
		{
			cout << "��������Ҫɾ����ְ��������" << endl;
			string name;
			cin >> name;
			int index = this->IsExist2(name);
			if (index != -1)  //˵��index��λ��������Ҫɾ��
			{
				for (int i = index; i < this->m_EmpNum - 1; i++)
				{
					this->m_EmpArray[i] = this->m_EmpArray[i + 1];
				}
				this->m_EmpNum--;
				this->save(); //ɾ��������ͬ�����ļ���
				cout << "ɾ���ɹ���" << endl;
			}
			else
			{
				cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
			}
		}
	}

	system("pause");
	system("cls");

}
void Management::Mod_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "�������޸�ְ����SSN�ţ�" << endl;
		int SSN;
		cin >> SSN;

		int ret = this->IsExist1(SSN);
		if (ret != -1)
		{	//���ҵ���ŵ�ְ��
			int newkind = 0;
			string newName = " ";			
			cout << "�鵽��ְ����������ְ���²��ţ� " << endl;
			cin >> newkind;
			cout << "�������������� " << endl;
			cin >> newName;
			this->m_EmpArray[ret]->m_name = newName;
			this->m_EmpArray[ret]->kind = newkind;			
			cout << "�޸ĳɹ���" << endl;
			//���浽�ļ���
			this->save();
		}
		else
		{			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	}

	//������� ����
	system("pause");
	system("cls");
}
void Management::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������ҵ�ְ��SSN�ţ�" << endl;
		int ssn;
		cin >> ssn;
		int ret = IsExist1(ssn);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else { cout << "���޴��ˣ�" << endl; }
	
	}


	system("pause");
	system("cls");
}
Management::~Management()
{    //����
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
	}
}