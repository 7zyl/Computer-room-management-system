//老师类
#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include<fstream>
#include<string>
#include"orderFile.h"
#include<vector>


class Teacher :public Identity
{
public:
	//默认构造
	Teacher();

	//有参构造（老师编号，姓名，密码）
	Teacher(int empid, string name, string pwd);

	//子菜单界面
	virtual void operMenu();//父类的纯虚函数子类必须重写

	//查看所有预约
	void showAllOrder();

	//审核预约
	void validOrder();

	//老师编号
	int m_empid;
};