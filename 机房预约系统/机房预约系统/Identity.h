//��ݵĻ���
#pragma once
#include<iostream>

using namespace std;

//��ݵĳ�����ֻࣨ��ͷ�ļ����ɣ�
class Identity
{
public:

	//�����˵���ÿ����ݶ�Ӧ���Ӳ˵��� ���麯��
	virtual void operMenu() = 0;//����Ĵ��麯�������������д


	string m_name;//�û���
	string m_pwd;//����
};