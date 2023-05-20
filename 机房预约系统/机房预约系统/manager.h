//����Ա��
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
	//Ĭ�Ϲ���
	Manager();

	//�вι��죨����Ա���������룩
	Manager(string name, string pwd);

	//�Ӳ˵�����
	virtual void operMenu();//����Ĵ��麯�����������д

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void clearFile();

	//��ʼ������
	void initVector();
	//ѧ������
	vector<Student>vStu;
	//��ʦ����
	vector<Teacher>vTea;
	//����ظ�--����1�����ѧ��/��ʦ���   ����2���������
	bool checkRepeat(int id, int type);

	//��ʼ��������Ϣ
	void initComputerRoom();
	//������Ϣ����
	vector<ComputerRoom>vCom;

};
