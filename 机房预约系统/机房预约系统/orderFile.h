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

	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();

	//��¼������
	//map<string string>keyΪ���ԣ�date..����valueΪʵֵ
	//map<int,map<string,string>>keyΪԤԼ��¼�������м���ԤԼ��¼��valueΪһ����¼�е�������Ϣ(��ֵ��)���������Ժ�ʵֵ
	map<int, map<string, string>>m_orderData;

	//ԤԼ��¼������key��
	int m_size;
};