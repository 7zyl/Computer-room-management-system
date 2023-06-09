#include"orderFile.h"

//构造函数
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;					//日期
	string interval;				//时间段
	string stuId;					//学生编号
	string stuName;			//学生姓名
	string roomId;				//机房编号
	string status;				//预约状态

	this->m_size = 0;			//预约条数初始为0

	while (ifs>>date&&ifs>>interval&&ifs>>stuId&&ifs>>stuName&&ifs>>roomId&&ifs>>status)
	{
		//测试代码
		//cout << date << endl;
		//cout << interval << endl;
		//cout << stuId << endl;
		//cout << stuName << endl;
		//cout << roomId << endl;
		//cout << status << endl;
		//cout << endl;

		//拆分键值对  date:1
		string key;
		string value;
		map<string, string>m;

		int pos=date.find(":"); //4--此时的date是  date:1
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);//date:1111 size=9，pos=4，截取4个，即size-pos-1

			m.insert(make_pair(key, value));

		}

		pos = interval.find(":"); 
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		pos = stuId.find(":");
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		pos = stuName.find(":");
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		pos = roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		//将小map容器放入到大map容器中
		this->m_orderData.insert(make_pair(this->m_size, m));//key是预约条数，value是小容器m
		this->m_size++;

	}
	ifs.close();

	//测试代码
	//for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
	//{
	//	cout << "条数为：" << it->first << "value=" << endl;
	//	for (map<string, string>::iterator mit = (*it).second.begin(); mit != (*it).second.end(); mit++)
	//	{
	//		cout << " key=" << mit->first << " value=" << mit->second << " ";

	//	}
	//	cout << endl;
	//}
}

//更新预约记录
void OrderFile::updateOrder()
{
	if (this->m_size == 0)
	{
		return;		//预约记录0条，直接return
	}
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out|ios::trunc);

	for (int i = 0; i < this->m_size; i++)
	{
		ofs << "date:" << this->m_orderData[i]["date"] << " ";		//["date"]是小容器的key值，通过key值查value值
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << " ";
	}
	ofs.close();
}