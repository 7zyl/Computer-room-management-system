//学生类
#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include<vector>
#include"computerRoom.h"
#include<fstream>
#include"globalFile.h"
#include"orderFile.h"

class Student :public Identity
{
public:

	//默认构造
	Student();

	//有参构造（学号，姓名，密码）
	Student(int id, string name, string pwd);

	//子菜单界面
	virtual void operMenu();//父类的纯虚函数子类必须重写

	//申请预约
	void applyOrder();

	//查看我的预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	//学生学号
	int m_id;


	//初始化机房信息
	void initComputerRoom();
	//机房信息容器
	vector<ComputerRoom>vCom;
};