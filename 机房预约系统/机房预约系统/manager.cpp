#include"manager.h"

//Ĭ�Ϲ���
Manager:: Manager()
{

}

//�вι��죨����Ա���������룩
Manager::Manager(string name, string pwd)
{
	//��ʼ������Ա��Ϣ
	this->m_name = name;
	this->m_pwd = pwd;

	//��ʼ������
	this->initVector();

	//��ʼ��������Ϣ
	this->initComputerRoom();
}

//�Ӳ˵�����
void Manager::operMenu()//����Ĵ��麯�����������д
{
	cout << "��ӭ����Ա��" << this->m_name << "��¼��" << endl;
	cout << "\t\t------------------------------------------------\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t|                   1.����˺�                 |\n";
	cout << "\t\t|                                              | \n";
	cout << "\t\t|                                              | \n";
	cout << "\t\t|                   2.�鿴�˺�                 | \n";
	cout << "\t\t|                                              | \n";
	cout << "\t\t|                                              | \n";
	cout << "\t\t|                   3.�鿴����                 | \n";
	cout << "\t\t|                                              | \n";
	cout << "\t\t|                                              | \n";
	cout << "\t\t|                   4.���ԤԼ                 | \n";
	cout << "\t\t|                                              | \n";
	cout << "\t\t|                                              | \n";
	cout << "\t\t|                   0.ע����¼                 | \n";
	cout << "\t\t|                                              | \n";
	cout << "\t\t------------------------------------------------ \n";
	cout << "����������ѡ��" << endl;
}

//����˺�
void Manager::addPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;

	string filename;		//�����ļ���
	string tip;					//��ʾid��

	ofstream ofs;
	
	int select = 0;
	cin >> select;

	string errorTip;				//�����ظ���ʾ

	if (select == 1)
	{
		filename = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ������������룺";
	}
	else if(select==2)
	{
		filename = TEACHER_FILE;
		tip = "�������ʦ��ţ�";
		errorTip = "��ʦ����ظ������������룺";
	}
	else
	{
		cout << "�����������������" << endl;
		system("pause");
		system("cls");
		return;
	}

	ofs.open(filename, ios::out | ios::app);
	int id;
	string name;
	string pwd;

	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret = this->checkRepeat(id, select); //selectһ����һ��
		if (ret)				//���ظ�
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "������������" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ���" << endl;
	system("pause");
	system("cls");
	
	ofs.close();

	//���ó�ʼ�������ӿڣ����»�ȡ�ļ��е����ݣ���ʱ��������
	this->initVector();

}
//��ӡѧ����Ϣ
void printStudent(Student& s)
{
	cout << "ѧ�ţ�" << s.m_id << " ������" << s.m_name << " ���룺" << s.m_pwd << endl;
}
//��ӡ��ʦ��Ϣ
void printTeacher(Teacher& t)
{
	cout << "��ʦ��ţ�" << t.m_empid << " ������" << t.m_name << " ���룺" << t.m_pwd << endl;
}

//�鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1.�鿴����ѧ��" << endl;
	cout << "2.�鿴������ʦ" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else if(select==2)
	{
		cout << "������ʦ��Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	else
	{
		cout << "������������������" << endl;
		system("pause");
		system("cls");
		return;
	}
	system("pause");
	system("cls");
}

//�鿴������Ϣ
void Manager::showComputer()
{
	cout << "��������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "������ţ�" << it->m_comid << " �������������" << it->m_maxnum << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::clearFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

//��ʼ������
void Manager::initVector()
{
	//�������
	vStu.clear();
	vTea.clear();

	//��ȡѧ���ļ�����Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_pwd)
	{
		vStu.push_back(s);
	}
	//cout << "��ǰѧ������Ϊ��" << vStu.size() << endl;
	ifs.close();

	//��ȡ��ʦ�ļ�����Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_empid && ifs >> t.m_name && ifs >> t.m_pwd)
	{
		vTea.push_back(t);
	}
	//cout << "��ǰ��ʦ����Ϊ��" << vTea.size() << endl;
	ifs.close();

}

//����ظ�--����1�����ѧ��/��ʦ���   ����2���������
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//���ѧ��
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_id)
			{
				return true;
			}
		}

	}
	else
	{
		//�����ʦ
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_empid)
			{
				return true;
			}
		}
	}
	return false;
}

//��ʼ��������Ϣ
void Manager::initComputerRoom()
{
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_comid && ifs >> com.m_maxnum)	//���ļ�
	{
		vCom.push_back(com);
	}
	ifs.close();
	//cout << "����������Ϊ��" << vCom.size() << endl;
}