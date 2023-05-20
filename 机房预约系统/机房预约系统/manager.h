//管理员类
#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#include"Identity.h"
#include"globalFile.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computerRoom.h"

class Manager :public Identity
{
public:
	//默认构造
	Manager();

	//有参构造（管理员姓名，密码）
	Manager(string name, string pwd);

	//子菜单界面
	virtual void operMenu();//父类的纯虚函数子类必须重写

	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空预约记录
	void clearFile();

	//初始化容器
	void initVector();
	//学生容器
	vector<Student>vStu;
	//老师容器
	vector<Teacher>vTea;
	//检测重复--参数1：检测学号/教师编号   参数2：检测类型
	bool checkRepeat(int id, int type);

	//初始化机房信息
	void initComputerRoom();
	//机房信息容器
	vector<ComputerRoom>vCom;

};
