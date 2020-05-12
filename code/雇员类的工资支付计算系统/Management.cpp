#include "Management.h"

Management::Management(){
	ifstream ifs;
	ifs.open(filename, ios::in);
	//1.文件不存在
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl; //测试输出
		this->m_EmpNum = 0;  //初始化人数
		this->m_FileIsEmpty = true; //初始化文件为空标志
		this->m_EmpArray = NULL; //初始化数组
		ifs.close(); //关闭文件
		return;
	}
	//2.文件存在，并且没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空!" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	//3.文件存在且有记录
	int num = this->get_EmpNum();
	this->m_EmpNum = num;
	this->m_EmpArray = new Employee * [this->m_EmpNum];
	init_Emp();

}

void Management::Show_Menu() {
	cout << "*******************************************" << endl;
	cout << "***  欢迎使用雇员类的工资支付计算系统！ ***" << endl;
	cout << "************* 0.退出管理系统  *************" << endl;
	cout << "************* 1.增加职工信息  *************" << endl;
	cout << "************* 2.显示所有职工信息  *********" << endl;
	cout << "********* *** 3.显示某一部门职工信息  *****" << endl;
	cout << "************* 4.删除职工信息  *************" << endl;
	cout << "************* 5.修改职工信息  *************" << endl;
	cout << "************* 6.查找职工信息  *************" << endl;
	cout << "*******************************************" << endl;
	cout << endl;
}

void Management::exitsystem() {
	cout << "欢迎下次再使用！" << endl;
	system("pause");
	exit(0);
}

void Management::add_Emp() {
	cout << "请输入增加职工数量： " << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum <= 0) { cout << "输入有误，操作失败！" << endl; }
	else {
		int newSize = this->m_EmpNum + addNum; //计算新空间大小
		Employee** newSpace = new Employee * [newSize];//开辟新空间
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
			cout << "请输入要添加的职工类型：" << endl
				<< "1.Salaried-Employee" << endl
				<< "2.Hourly-Employee" << endl
				<< "3.Commission-Employee" << endl
				<< "4.Basesalaryed-commission-Employee" << endl;
			cin >> select;
			switch (select) {
			case 1:
			{   cout << "请输入该员工的姓名：" << endl;
			    cin >> name;
			    cout << "请输入该员工的SSN（9位数字）：" << endl;
				cin >> SSN;
				cout << "请输入该员工的固定工资（0-10000）：" << endl;
				cin >> baseSalary;			
				earning = baseSalary;
				newSpace[this->m_EmpNum + i] = new Salaried_Employee(select,name, SSN,earning);
				newSpace[this->m_EmpNum + i]->baseSalary = baseSalary;
				break;
			}
			case 2:
			{
				cout << "请输入该员工的姓名：" << endl;
				cin >> name;
				cout << "请输入该员工的SSN（9位数字）：" << endl;
				cin >> SSN;
				cout << "请输入该员工的时薪（0.1-100）：" << endl;
				cin >> wage;
				cout << "请输入该员工的工作时长：" << endl;
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
				cout << "请输入该员工的姓名：" << endl;
				cin >> name;
				cout << "请输入该员工的SSN（9位数字）：" << endl;
				cin >> SSN;
				cout << "请输入该员工的销售提成率（0-0.5）：" << endl;
				cin >> Commission_rate;
				cout << "请输入该员工的销售量（0-500）：" << endl;
				cin >> Gross_Sale;
				earning = Commission_rate * Gross_Sale;
				newSpace[this->m_EmpNum + i] = new Commission_Employee(select, name, SSN,earning);
				newSpace[this->m_EmpNum + i]->Commission_rate= Commission_rate;
				newSpace[this->m_EmpNum + i]->Gross_Sale = Gross_Sale;
				break;
			}
			case 4:
			{
				cout << "请输入该员工的姓名：" << endl;
				cin >> name;
				cout << "请输入该员工的SSN（9位数字）：" << endl;
				cin >> SSN;
				cout << "请输入该员工的固定工资（0-10000）：" << endl;
				cin >> baseSalary;
				cout << "请输入该员工的销售提成率（0-0.5）：" << endl;
				cin >> Commission_rate;
				cout << "请输入该员工的销售量（0-500）：" << endl;
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
		this->m_FileIsEmpty = false;//更新职工不为空标志
		cout << "成功添加" << addNum << "名新职工" << endl;
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
	{		cout << "文件不存在或记录为空！" << endl;
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
	{		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入查找职工类型：" << endl;
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
	{		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "您想按(     )删除" << endl;
		cout << "1.姓名" << endl;
		cout << "2.职工SSN编号" << endl;
		int t;
		cin >> t;
		if (t == 2) {
			//按职工SSN删除
			cout << "请输入想要删除的职工SSN号：" << endl;
			int SSN = 0;
			cin >> SSN;
			int index = this->IsExist1(SSN);
			if (index != -1)  //说明index上位置数据需要删除
			{
				for (int i = index; i < this->m_EmpNum - 1; i++)
				{
					this->m_EmpArray[i] = this->m_EmpArray[i + 1];
				}
				this->m_EmpNum--;
				this->save(); //删除后数据同步到文件中
				cout << "删除成功！" << endl;
			}
			else
			{
				cout << "删除失败，未找到该职工" << endl;
			}
		}
		if (t == 1)
		{
			cout << "请输入想要删除的职工姓名：" << endl;
			string name;
			cin >> name;
			int index = this->IsExist2(name);
			if (index != -1)  //说明index上位置数据需要删除
			{
				for (int i = index; i < this->m_EmpNum - 1; i++)
				{
					this->m_EmpArray[i] = this->m_EmpArray[i + 1];
				}
				this->m_EmpNum--;
				this->save(); //删除后数据同步到文件中
				cout << "删除成功！" << endl;
			}
			else
			{
				cout << "删除失败，未找到该职工" << endl;
			}
		}
	}

	system("pause");
	system("cls");

}
void Management::Mod_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入修改职工的SSN号：" << endl;
		int SSN;
		cin >> SSN;

		int ret = this->IsExist1(SSN);
		if (ret != -1)
		{	//查找到编号的职工
			int newkind = 0;
			string newName = " ";			
			cout << "查到此职工，请输入职工新部门： " << endl;
			cin >> newkind;
			cout << "请输入新姓名： " << endl;
			cin >> newName;
			this->m_EmpArray[ret]->m_name = newName;
			this->m_EmpArray[ret]->kind = newkind;			
			cout << "修改成功！" << endl;
			//保存到文件中
			this->save();
		}
		else
		{			cout << "修改失败，查无此人" << endl;
		}
	}

	//按任意键 清屏
	system("pause");
	system("cls");
}
void Management::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入查找的职工SSN号：" << endl;
		int ssn;
		cin >> ssn;
		int ret = IsExist1(ssn);
			if (ret != -1)
			{
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else { cout << "查无此人！" << endl; }
	
	}


	system("pause");
	system("cls");
}
Management::~Management()
{    //析构
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
	}
}