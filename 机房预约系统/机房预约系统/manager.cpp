#include"manager.h"

//默认构造
Manager:: Manager()
{

}

//有参构造（管理员姓名，密码）
Manager::Manager(string name, string pwd)
{
	//初始化管理员信息
	this->m_name = name;
	this->m_pwd = pwd;

	//初始化容器
	this->initVector();

	//初始化机房信息
	this->initComputerRoom();
}

//子菜单界面
void Manager::operMenu()//父类的纯虚函数子类必须重写
{
	cout << "欢迎管理员：" << this->m_name << "登录！" << endl;
	cout << "\t\t------------------------------------------------\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t|                   1.添加账号                 |\n";
	cout << "\t\t|                                              | \n";
	cout << "\t\t|                                              | \n";
	cout << "\t\t|                   2.查看账号                 | \n";
	cout << "\t\t|                                              | \n";
	cout << "\t\t|                                              | \n";
	cout << "\t\t|                   3.查看机房                 | \n";
	cout << "\t\t|                                              | \n";
	cout << "\t\t|                                              | \n";
	cout << "\t\t|                   4.清空预约                 | \n";
	cout << "\t\t|                                              | \n";
	cout << "\t\t|                                              | \n";
	cout << "\t\t|                   0.注销登录                 | \n";
	cout << "\t\t|                                              | \n";
	cout << "\t\t------------------------------------------------ \n";
	cout << "请输入您的选择：" << endl;
}

//添加账号
void Manager::addPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;

	string filename;		//操作文件名
	string tip;					//提示id号

	ofstream ofs;
	
	int select = 0;
	cin >> select;

	string errorTip;				//错误重复提示

	if (select == 1)
	{
		filename = STUDENT_FILE;
		tip = "请输入学号：";
		errorTip = "学号重复，请重新输入：";
	}
	else if(select==2)
	{
		filename = TEACHER_FILE;
		tip = "请输入教师编号：";
		errorTip = "教师编号重复，请重新输入：";
	}
	else
	{
		cout << "输入错误，请重新输入" << endl;
		system("pause");
		system("cls");
		return;
	}

	ofs.open(filename, ios::out | ios::app);
	int id;
	string name;
	string pwd;

	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret = this->checkRepeat(id, select); //select一环扣一环
		if (ret)				//有重复
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功！" << endl;
	system("pause");
	system("cls");
	
	ofs.close();

	//调用初始化容器接口，重新获取文件中的数据，及时更新容器
	this->initVector();

}
//打印学生信息
void printStudent(Student& s)
{
	cout << "学号：" << s.m_id << " 姓名：" << s.m_name << " 密码：" << s.m_pwd << endl;
}
//打印老师信息
void printTeacher(Teacher& t)
{
	cout << "教师编号：" << t.m_empid << " 姓名：" << t.m_name << " 密码：" << t.m_pwd << endl;
}

//查看账号
void Manager::showPerson()
{
	cout << "请选择查看内容：" << endl;
	cout << "1.查看所有学生" << endl;
	cout << "2.查看所有老师" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		cout << "所有学生信息如下：" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else if(select==2)
	{
		cout << "所有老师信息如下：" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	else
	{
		cout << "输入有误，请重新输入" << endl;
		system("pause");
		system("cls");
		return;
	}
	system("pause");
	system("cls");
}

//查看机房信息
void Manager::showComputer()
{
	cout << "机房的信息如下：" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房编号：" << it->m_comid << " 机房最大容量：" << it->m_maxnum << endl;
	}
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::clearFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}

//初始化容器
void Manager::initVector()
{
	//清空容器
	vStu.clear();
	vTea.clear();

	//读取学生文件中信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_pwd)
	{
		vStu.push_back(s);
	}
	//cout << "当前学生数量为：" << vStu.size() << endl;
	ifs.close();

	//读取老师文件中信息
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_empid && ifs >> t.m_name && ifs >> t.m_pwd)
	{
		vTea.push_back(t);
	}
	//cout << "当前老师数量为：" << vTea.size() << endl;
	ifs.close();

}

//检测重复--参数1：检测学号/教师编号   参数2：检测类型
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//检测学生
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_id)
			{
				return true;
			}
		}

	}
	else
	{
		//检测老师
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_empid)
			{
				return true;
			}
		}
	}
	return false;
}

//初始化机房信息
void Manager::initComputerRoom()
{
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_comid && ifs >> com.m_maxnum)	//读文件
	{
		vCom.push_back(com);
	}
	ifs.close();
	//cout << "机房的数量为：" << vCom.size() << endl;
}