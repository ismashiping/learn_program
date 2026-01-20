#include "workerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

void WorkerManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
};

WorkerManager::WorkerManager()
{
	// 文件不存在
	ifstream ifs;

	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	// 文件存在但是没有记录
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
	// 文件存在且有记录
	int num = this->get_EmpNum();
	cout << "职工个数为" << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArray = new Worker *[this->m_EmpNum];
	init_Emp();

	// for(int i = 0;i<this->m_EmpNum;i++){
	// 	cout<<"职工号"<<this->m_EmpArray[i]->m_Id
	// 	<<"职工姓名"<<this->m_EmpArray[i]->m_Name
	// 	<<"部门编号"<<this->m_EmpArray[i]->m_DeptId<<endl;
	// }

	// this->m_EmpNum = 0;

	// //初始化数组指针
	// this->m_EmpArray = NULL;
};
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
	}
};
void WorkerManager::exitSystem()
{
	cout << "*************  退出系统  *************" << endl;
	exit(0);
}

void WorkerManager::Add_Emp()
{
	// 提示一下输入员工的数量
	cout << "请输入你要添加的员工数量: " << endl;
	int num_worker = 0;
	cin >> num_worker;
	if (num_worker > 0)
	{
		// 计算新空间的大小
		int new_size = this->m_EmpNum + num_worker;
		Worker **new_space = new Worker *[new_size];
		// 将原空间下的内容存放到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				new_space[i] = this->m_EmpArray[i];
			}
		}
		for (int i = 0; i < num_worker; i++)
		{
			/* code */
			int id = 0;
			string name;
			int dSelect;
			cout << "请输出您要输入的第" << i + 1 << "职工的编号: " << endl;
			cin >> id;
			cout << "请输出您要输入的第" << i + 1 << "职工的姓名: " << endl;
			cin >> name;
			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;
			Worker *worker = NULL;
			switch (dSelect)
			{
			case 1: // 普通员工
				worker = new Employee(id, name, 1);
				break;
			case 2: // 经理
				worker = new Manager(id, name, 2);
				break;
			case 3: // 老板
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			new_space[this->m_EmpNum + i] = worker;
		}

		delete[] this->m_EmpArray;
		this->m_EmpArray = new_space;

		// 更新新的个数
		this->m_EmpNum = new_size;

		// 提示信息
		cout << "成功添加" << num_worker << "名新职工！" << endl;
	}
	else
	{
		/* code */
		cout << "输入有误" << endl;
	}
	this->save();

	this->m_FileIsEmpty = false;

	// 输入新数据
};

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		/* code */
		num++;
	}

	return num;
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker *worker = NULL;
		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3)
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
}

void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	// system("read -n 1");

	// system("clear");
}
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for(int i=0;i<this->m_EmpNum;i++){
		if(this->m_EmpArray[i]->m_Id==id){
			index=i;
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
	else
	{
		//按职工编号删除
		cout << "请输入想要删除的职工号：" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

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
	
	system("pause");
}