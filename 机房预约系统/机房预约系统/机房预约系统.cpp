#include<iostream>
using namespace std;
#include"Identity.h"
#include<fstream>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"

//进入管理员子菜单界面
void managerMenu(Identity*& manager)		//创建一个父类指针来调用子类,指针的引用
{
	while (true)
	{
		//调用管理员子菜单
		manager->operMenu();//父类的纯虚函数（多态）

		//将父类指针转为子类指针，调用子类中的其他接口
		Manager* man = (Manager*)manager;

		int select = 0;
		cin >> select;

		if (select == 1)//添加账号
		{
			man->addPerson();
		}
		else if (select == 2)//查看账号
		{
			man->showPerson();
		}
		else if (select == 3)//查看机房
		{
			man->showComputer();
		}
		else if (select == 4)//清空预约
		{
			man->clearFile();
		}
		else if(select==0)
		{
			delete manager;//销毁掉堆区对象
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "输入错误，请重新输入" << endl;
			system("pause");
			system("cls");
			manager->operMenu();
			system("cls");
		}

	}
}

//进入学生子菜单界面
void studentMenu(Identity*& student)
{
	while (true)
	{
		//调用学生子菜单
		student->operMenu();

		//将父类指针转为子类指针，调用子类中的其他接口
		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;
		if (select == 1)//申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2)//查看自身预约
		{
			stu->showMyOrder();
		}
		else if (select == 3)//查看所有人预约
		{
			stu->showAllOrder();
		}
		else if (select == 4)//取消预约
		{
			stu->cancelOrder();
		}
		else if (select == 0)//注销登录
		{
			delete student;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "输入错误，请重新输入" << endl;
			system("pause");
			system("cls");
			student->operMenu();
			system("cls");
		}
	}
}

//进入教师子菜单界面
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		cin >> select;
		if (select == 1)//查看所有预约
		{
			tea->showAllOrder();
		}
		else if (select == 2)//审核预约
		{
			tea->validOrder();
		}
		else if (select == 0)//注销登录
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "输入错误，请重新输入" << endl;
			system("pause");
			system("cls");
			teacher->operMenu();
			system("cls");
		}
	}
}


//登录功能--参数1为文件名，参数2为人的类型
void LoginIn(string fileName, int type)
{
	//父类指针指向子类对象（提供多态接口）
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	//文件不存在情况
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//获取信息
	int id = 0;
	string name;
	string pwd;

	//其实type只能传1，2，3。所以if语句中else可以不写
	if (type == 1)
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入你的教师编号：" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;


	//登录验证
	if (type == 1)
	{
		//学生登录验证
		int fid;				//从文件中读取的ID
		string fname;	//从文件中获取的姓名
		string fpwd;		//从文件中获取密码
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			//与用户输入的信息做对比
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				//创建学生对象
				person = new Student(id, name, pwd);

				//进入学生子菜单
				studentMenu(person);
				return;//退出函数
			}
		}
	}
	else if (type == 2)
	{
		//老师登录验证
		int fid;				//从文件中读取的ID
		string fname;	//从文件中获取的姓名
		string fpwd;		//从文件中获取密码
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			//与用户输入的信息做对比
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "老师验证登录成功！" << endl;
				system("pause");
				system("cls");
				//创建老师对象
				person = new Teacher(id, name, pwd);

				//进入老师子菜单
				teacherMenu(person);
				return;//退出函数
			}
		}
	}
	else if (type == 3)
	{
		//管理员登录验证
		string fname;	//从文件中获取的姓名
		string fpwd;		//从文件中获取密码
		while (ifs >> fname && ifs >> fpwd)
		{
			//与用户输入的信息做对比
			if (fname == name && fpwd == pwd)
			{
				cout << "管理员验证登录成功！" << endl;
				system("pause");
				system("cls");
				//创建管理员对象
				person = new Manager(name, pwd);

				//进入管理员子菜单
				managerMenu(person);
				return;//退出函数
			}
		}
	}


	cout << "验证登录失败！" << endl;
	system("pause");
	system("cls");
	return;
}


int main()
{
	int select = 0;
	while (true)
	{
		cout << "-------------------------------------欢迎来到机房预约系统--------------------------------------" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t------------------------------------------------\n";
		cout << "\t\t|                                              |\n";
		cout << "\t\t|                   1.学生代表                 |\n";
		cout << "\t\t|                                              | \n";
		cout << "\t\t|                                              | \n";
		cout << "\t\t|                   2.老师                     | \n";
		cout << "\t\t|                                              | \n";
		cout << "\t\t|                                              | \n";
		cout << "\t\t|                   3.管理员                   | \n";
		cout << "\t\t|                                              | \n";
		cout << "\t\t|                                              | \n";
		cout << "\t\t|                   0.退出                     | \n";
		cout << "\t\t|                                              | \n";
		cout << "\t\t------------------------------------------------ \n";
		cout << "输入您的选择：";

		cin >> select;
		switch (select)
		{
		case 1://学生身份
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://老师身份
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://管理员身份
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://退出系统
			cout << "欢迎下一次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}


	}



	system("pause");
	return 0;
} 