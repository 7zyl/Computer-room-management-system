#include<iostream>
using namespace std;
#include"Identity.h"
#include<fstream>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"

//�������Ա�Ӳ˵�����
void managerMenu(Identity*& manager)		//����һ������ָ������������,ָ�������
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		manager->operMenu();//����Ĵ��麯������̬��

		//������ָ��תΪ����ָ�룬���������е������ӿ�
		Manager* man = (Manager*)manager;

		int select = 0;
		cin >> select;

		if (select == 1)//����˺�
		{
			man->addPerson();
		}
		else if (select == 2)//�鿴�˺�
		{
			man->showPerson();
		}
		else if (select == 3)//�鿴����
		{
			man->showComputer();
		}
		else if (select == 4)//���ԤԼ
		{
			man->clearFile();
		}
		else if(select==0)
		{
			delete manager;//���ٵ���������
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "�����������������" << endl;
			system("pause");
			system("cls");
			manager->operMenu();
			system("cls");
		}

	}
}

//����ѧ���Ӳ˵�����
void studentMenu(Identity*& student)
{
	while (true)
	{
		//����ѧ���Ӳ˵�
		student->operMenu();

		//������ָ��תΪ����ָ�룬���������е������ӿ�
		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;
		if (select == 1)//����ԤԼ
		{
			stu->applyOrder();
		}
		else if (select == 2)//�鿴����ԤԼ
		{
			stu->showMyOrder();
		}
		else if (select == 3)//�鿴������ԤԼ
		{
			stu->showAllOrder();
		}
		else if (select == 4)//ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else if (select == 0)//ע����¼
		{
			delete student;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "�����������������" << endl;
			system("pause");
			system("cls");
			student->operMenu();
			system("cls");
		}
	}
}

//�����ʦ�Ӳ˵�����
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		cin >> select;
		if (select == 1)//�鿴����ԤԼ
		{
			tea->showAllOrder();
		}
		else if (select == 2)//���ԤԼ
		{
			tea->validOrder();
		}
		else if (select == 0)//ע����¼
		{
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "�����������������" << endl;
			system("pause");
			system("cls");
			teacher->operMenu();
			system("cls");
		}
	}
}


//��¼����--����1Ϊ�ļ���������2Ϊ�˵�����
void LoginIn(string fileName, int type)
{
	//����ָ��ָ����������ṩ��̬�ӿڣ�
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ļ����������
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//��ȡ��Ϣ
	int id = 0;
	string name;
	string pwd;

	//��ʵtypeֻ�ܴ�1��2��3������if�����else���Բ�д
	if (type == 1)
	{
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "��������Ľ�ʦ��ţ�" << endl;
		cin >> id;
	}
	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;


	//��¼��֤
	if (type == 1)
	{
		//ѧ����¼��֤
		int fid;				//���ļ��ж�ȡ��ID
		string fname;	//���ļ��л�ȡ������
		string fpwd;		//���ļ��л�ȡ����
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			//���û��������Ϣ���Ա�
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				//����ѧ������
				person = new Student(id, name, pwd);

				//����ѧ���Ӳ˵�
				studentMenu(person);
				return;//�˳�����
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ��¼��֤
		int fid;				//���ļ��ж�ȡ��ID
		string fname;	//���ļ��л�ȡ������
		string fpwd;		//���ļ��л�ȡ����
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			//���û��������Ϣ���Ա�
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				//������ʦ����
				person = new Teacher(id, name, pwd);

				//������ʦ�Ӳ˵�
				teacherMenu(person);
				return;//�˳�����
			}
		}
	}
	else if (type == 3)
	{
		//����Ա��¼��֤
		string fname;	//���ļ��л�ȡ������
		string fpwd;		//���ļ��л�ȡ����
		while (ifs >> fname && ifs >> fpwd)
		{
			//���û��������Ϣ���Ա�
			if (fname == name && fpwd == pwd)
			{
				cout << "����Ա��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				//��������Ա����
				person = new Manager(name, pwd);

				//�������Ա�Ӳ˵�
				managerMenu(person);
				return;//�˳�����
			}
		}
	}


	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
}


int main()
{
	int select = 0;
	while (true)
	{
		cout << "-------------------------------------��ӭ��������ԤԼϵͳ--------------------------------------" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t------------------------------------------------\n";
		cout << "\t\t|                                              |\n";
		cout << "\t\t|                   1.ѧ������                 |\n";
		cout << "\t\t|                                              | \n";
		cout << "\t\t|                                              | \n";
		cout << "\t\t|                   2.��ʦ                     | \n";
		cout << "\t\t|                                              | \n";
		cout << "\t\t|                                              | \n";
		cout << "\t\t|                   3.����Ա                   | \n";
		cout << "\t\t|                                              | \n";
		cout << "\t\t|                                              | \n";
		cout << "\t\t|                   0.�˳�                     | \n";
		cout << "\t\t|                                              | \n";
		cout << "\t\t------------------------------------------------ \n";
		cout << "��������ѡ��";

		cin >> select;
		switch (select)
		{
		case 1://ѧ�����
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա���
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://�˳�ϵͳ
			cout << "��ӭ��һ��ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}


	}



	system("pause");
	return 0;
} 