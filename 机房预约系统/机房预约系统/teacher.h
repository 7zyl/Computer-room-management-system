//��ʦ��
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
	//Ĭ�Ϲ���
	Teacher();

	//�вι��죨��ʦ��ţ����������룩
	Teacher(int empid, string name, string pwd);

	//�Ӳ˵�����
	virtual void operMenu();//����Ĵ��麯�����������д

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	//��ʦ���
	int m_empid;
};