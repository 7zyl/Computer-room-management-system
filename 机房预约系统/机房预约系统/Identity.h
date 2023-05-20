//身份的基类
#pragma once
#include<iostream>

using namespace std;

//身份的抽象基类（只有头文件即可）
class Identity
{
public:

	//操作菜单（每种身份对应的子菜单） 纯虚函数
	virtual void operMenu() = 0;//父类的纯虚函数，子类必须重写


	string m_name;//用户名
	string m_pwd;//密码
};