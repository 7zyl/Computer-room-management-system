//ѧ����
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

	//Ĭ�Ϲ���
	Student();

	//�вι��죨ѧ�ţ����������룩
	Student(int id, string name, string pwd);

	//�Ӳ˵�����
	virtual void operMenu();//����Ĵ��麯�����������д

	//����ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	//ѧ��ѧ��
	int m_id;


	//��ʼ��������Ϣ
	void initComputerRoom();
	//������Ϣ����
	vector<ComputerRoom>vCom;
};