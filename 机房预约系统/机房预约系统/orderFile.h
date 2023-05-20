#pragma once
#include<iostream>
using namespace std;
#include<map>
#include"globalFile.h"
#include<fstream>
#include<string>

class OrderFile
{
public:

	//构造函数
	OrderFile();

	//更新预约记录
	void updateOrder();

	//记录的容器
	//map<string string>key为属性（date..），value为实值
	//map<int,map<string,string>>key为预约记录条数，有几条预约记录，value为一条记录中的所有信息(键值对)，包括属性和实值
	map<int, map<string, string>>m_orderData;

	//预约记录条数（key）
	int m_size;
};