#include"student.h"

//默认构造
Student::Student()
{

}

//有参构造（学号，姓名，密码）
Student::Student(int id, string name, string pwd)
{
	this->m_id = id;
	this->m_name = name;
	this->m_pwd = pwd;

	//初始化机房信息
	this->initComputerRoom();
}

//子菜单界面
void Student::operMenu()//父类的纯虚函数子类必须重写
{
	cout << "欢迎学生：" << this->m_name << "登录！" << endl;
	cout << "\t\t------------------------------------------------\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t|                   1.申请预约                 |\n";
	cout << "\t\t|                                              | \n";
	cout << "\t\t|                                              | \n";
	cout << "\t\t|                   2.查看我的预约             | \n";
	cout << "\t\t|                                              | \n";
	cout << "\t\t|                                              | \n";
	cout << "\t\t|                   3.查看所有预约             | \n";
	cout << "\t\t|                                              | \n";
	cout << "\t\t|                                              | \n";
	cout << "\t\t|                   4.取消预约                 | \n";
	cout << "\t\t|                                              | \n";
	cout << "\t\t|                                              | \n";
	cout << "\t\t|                   0.注销登录                 | \n";
	cout << "\t\t|                                              | \n";
	cout << "\t\t------------------------------------------------ \n";
	cout << "请输入您的选择：" << endl;
}


//申请预约
void Student::applyOrder()
{
	cout << "机房开放时间为周一至周五！" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;

	int date = 0;			//日期
	int interval = 0;	//时间段
	int room = 0;		//机房编号

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}
	cout << "请输入申请预约时间段：" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1&&interval <= 2)
		{
			break;
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}
	cout << "请选择机房：" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_comid << "号机房容量为：" << vCom[i].m_maxnum << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}
	cout << "预约成功！审核中" << endl;


	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_id << " ";
	ofs << "stuName:" << this->m_name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;			//1表示审核中
	cout << endl;
	ofs.close();
	system("pause");
	system("cls");
}

//查看我的预约
void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_size; i++)
	{
		//string 转 int
		//string利用.c_str()转成const char*
		//利用atoi（const char *)转int
		if (this->m_id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			cout << "预约日期：周" << of.m_orderData[i]["date"] << " ";
			cout << "时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
			cout << "机房：" << of.m_orderData[i]["roomId"] << " ";
			string status = "状态：";
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "审核未通过，预约失败";
			}
			else
			{
				status += "预约已取消";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");

}

//查看所有预约
void Student::showAllOrder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_size; i++)
	{
		cout << i + 1 << "、";
		cout << "预约日期：周" << of.m_orderData[i]["date"] << " ";
		cout << "时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
		cout << "学号：" << of.m_orderData[i]["stuId"] << " ";
		cout << "姓名：" << of.m_orderData[i]["stuName"] << " ";
		cout << "机房：" << of.m_orderData[i]["roomId"] << " ";
		string status = "状态：";
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "审核未通过，预约失败";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;

	}
	system("pause");
	system("cls");

}

//取消预约
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或预约成功的记录可以取消，请输入取消的记录：" << endl;
	vector<int>v;//存放在最大容器中的下标编号
	int index = 1;//给用户提示的下标
	for (int i = 0; i < of.m_size; i++)
	{
		//先判断是自身学号
		if (this->m_id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			//再筛选状态 审核中或预约成功
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "、";
				cout << "预约日期：周" << of.m_orderData[i]["date"] << " ";
				cout << "时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
				cout << "机房：" << of.m_orderData[i]["roomId"] << " ";
				string status = "状态：";
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "预约成功";
				}
				cout << status << endl;
			}
		}
	}
	cout << "请输入取消的记录，0代表返回" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				//cout<<"记录所在位置："<<v[select-1]<<endl;
				of.m_orderData[v[select - 1]]["status"] = "0";//vector中对应的信息需要-1
				of.updateOrder();
				cout << "已取消预约" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
}

//初始化机房信息
void Student::initComputerRoom()
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