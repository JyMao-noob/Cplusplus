#include "workerManager.h"

WorkerManager::WorkerManager() {	
	ifstream ifs;
	ifs.open(filename, ios::in); //读文件
//1.文件不存在
	if(!ifs.is_open())   {
		//cout << "文件不存在" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
//2.文件存在，但无记录
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//cout << "文件为空" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
//3.文件存在，且有记录
	int num = this->get_EmpNum();
	//cout << "职工人数为： " << num << endl;
	this->m_EmpNum = num;
	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件中已有的数据存到数组中
	this->init_Emp();
}

void WorkerManager::Show_Menu() {
	cout << "*******************************" << endl;
	cout << "***  欢迎使用职工管理系统！ ***" << endl;
	cout << "******* 0.退出管理系统  *******" << endl;
	cout << "******* 1.增加职工信息  *******" << endl;
	cout << "******* 2.显示职工信息  *******" << endl;
	cout << "******* 3.删除离职职工  *******" << endl;
	cout << "******* 4.修改职工信息  *******" << endl;
	cout << "******* 5.查找职工信息  *******" << endl;
	cout << "******* 6.按照编号排序  *******" << endl;
	cout << "******* 7.清空所有文件  *******" << endl;
	cout << "*******************************" << endl;
	cout << endl;
}
void WorkerManager::exitSystem() {
	cout << "欢迎下次再使用！" << endl;
	system("pause");
	exit(0);
}
void WorkerManager::Add_Emp() {
	cout << "请输入添加职工数量：" << endl;
	int addNum=0;
	cin >> addNum;
	if(addNum>0){
		//计算新空间大小
		int newSize = this->m_EmpNum + addNum; //原来+新增
		//开辟新空间
		Worker** newSpace=new Worker* [newSize];

		//原空间数据拷贝到新空间
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
         }
		//添加新数据
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int dSelect;
			cout << "请输入第 " << i + 1 << "个新职工编号：" << endl;
			cin >> id;
			cout << "请输入第 " << i + 1 << "个新职工姓名：" << endl;
			cin >> name;
			cout << "请选择该职工岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//职工指针保存到数组
			newSpace[this->m_EmpNum + i] = worker;
		}
		//释放原空间
		delete[] this->m_EmpArray;
		//更改新空间指向
		this->m_EmpArray = newSpace;
		//更新人数
		this->m_EmpNum = newSize;
		//更新职工不为空标志
		this->m_FileIsEmpty = false;
		//提示
		cout << "成功添加" << addNum << "名新职工" << endl;
		//保存到文件中
		this->save();
	}
	else { cout << "输入有误" << endl; }
	system("pause");
	system("cls");
}

void WorkerManager::save() {
	ofstream ofs;
	ofs.open(filename, ios::out);
	//写入
	for (int i = 0; i < m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

int WorkerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(filename, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		num++;
	}
	return num;
}
void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(filename, ios::in);
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker* worker = NULL;
		if (dId == 1) {
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) {
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3) {
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}
void WorkerManager::Show_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++) {
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
int WorkerManager::IsExist(int id){
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_Id == id) {
			index = i;
			break;
		}
	}
	return index;
}
void WorkerManager::Del_Emp(){
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		cout << "请输入要删除的职工编号：" << endl;
		int id = 0;
		cin >> id;
		int index=this->IsExist(id);
		if (index != -1) {
			for (int i = index; i < this->m_EmpNum-1; i++) {
				this->m_EmpArray[index] = this->m_EmpArray[index + 1];

			}
			this->m_EmpNum--;
			this->save();
			cout << "删除成功！" << endl;
		}
		else {
			cout << "未找到该职工！" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::Mod_Emp(){
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	 }
	else {
		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1) {
			delete this->m_EmpArray[ret];
			int newid;
			string newname;
			int newdSelect;
			cout << "查到 " << id << "号职工，请输入新职工号：" << endl;
			cin >> newid;
			cout << "请输入新姓名：" << endl;
			cin >> newname;
			cout << "请输入新岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> newdSelect;
			Worker* worker = NULL;
			switch (newdSelect) {
			case 1:
				worker = new Employee(newid, newname, newdSelect);
				break;
			case 2:
				worker = new Manager(newid, newname, newdSelect);
				break;
			case 3:
				worker = new Boss(newid, newname, newdSelect);
				break;
			default:
				break;

			}
			this->m_EmpArray[ret] = worker;
			cout << "修改成功！" << endl;
			this->save();
		}
		else {
			cout << "修改失败，查无此人！" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::Find_Emp(){
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
   }
	else {
		cout << "请输入查找的方式：" << endl;
		cout << "1.按编号查找" << endl;
		cout << "2.按姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1) {
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1) {
				cout << "查找成功！信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else {
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if (select == 2) {
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i]->m_Name == name) {
					cout << "查找成功，编号为："
						<< this->m_EmpArray[i]->m_Id
						<< "的员工信息如下：" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}

			}
			if (flag == false) {
				cout << "查找失败，查无此人" << endl;
			}
		}
		
	}
	system("pause");
	system("cls");
}
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{	cout << "请选择排序方式： " << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1) //升序
				{
					if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else  //降序
				{
					if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}
			if (i != minOrMax)
			{
				Worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "排序成功,排序后结果为：" << endl;
		this->save();
		this->Show_Emp();
	}

}
void WorkerManager::Clean_File()
{	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs(filename, ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}
WorkerManager::~WorkerManager() {
	if (this->m_EmpArray != NULL) {
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}