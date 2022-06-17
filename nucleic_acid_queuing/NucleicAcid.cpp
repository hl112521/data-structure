#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <time.h>
#include <windows.h>
#include <stdio.h>
using namespace std;

/*
核酸检测用户类
*/
class User
{
public:
	int userID; // 四位身份证号
	string name;
	User()
	{
		name = "";
		userID = 0;
	}
	User(string n, int id) { userID = id, name = n; }
};
/*
核酸检测窗口类
*/
class NucleicAcidWindow
{
public:
	int id; //当前核酸窗口id 给四个窗口
	bool isBusy;
	User personnel; // 核酸排队的用户
	int serviceStartTime = 0;
	NucleicAcidWindow() { isBusy = false; }
	NucleicAcidWindow(int i)
	{
		id = i;
		isBusy = false;
	}
};
/*
模拟器类, 模拟核酸叫号的各种功能
*/
class Simulater
{
private:
	int serviceTime[3] = {2, 4, 6};
	int userIdList[100];
	struct User Conduit[5][20]; // 结构体数组, 用于存放同管检测人员
	int initID = 1000;
	NucleicAcidWindow nucleicAcidWindow0;
	NucleicAcidWindow nucleicAcidWindow1;
	NucleicAcidWindow nucleicAcidWindow2;
	NucleicAcidWindow nucleicAcidWindow3;
	NucleicAcidWindow nucleicAcidWindow4;
	queue<User> NormalUserQueue;

public:
	Simulater()
	{
		// 初始化核酸检测窗口, 开放5个窗口
		nucleicAcidWindow0.id = 0;
		nucleicAcidWindow1.id = 1;
		nucleicAcidWindow2.id = 2;
		nucleicAcidWindow3.id = 3;
		nucleicAcidWindow4.id = 4;
		srand(unsigned(time(0))); // 用于给rand()函数设定种子，参数seed是rand()的种子，用来初始化rand()的起始值
	}
	// 叫号排队
	void enterQueue(User user)
	{
		cout << "\t\t检测用户: " << user.userID << " 进入排队"
			 << ", 姓名: " << user.name << endl;
		NormalUserQueue.push(user);
		cout << "\t\t当前排队人数为: " << NormalUserQueue.size();
	}
	// 查看排队人数和等待时间
	void showCountTime()
	{
		cout << "\t\t当前排队人数为: " << NormalUserQueue.size() << endl;
		cout << "\t\t需要等待:" << NormalUserQueue.size() << " 分钟" << endl;
		getchar();
	}
	void output(User user)
	{
		cout << "\t\t检测用户 " << user.userID
			 << ", 姓名为: " << user.name;
	}
	void output2(User user)
	{
		cout << "  检测类型: "
			 << "核酸  "
			 << "检测用户: " << user.name;
	}
	// 窗口喊人排队
	void enterWindow()
	{
		// 窗口空闲, 并且有用户在排队队列中
		if (nucleicAcidWindow0.isBusy == false && !NormalUserQueue.empty())
		{
			nucleicAcidWindow0.personnel = NormalUserQueue.front();
			output(nucleicAcidWindow0.personnel);
			cout << "\t请到0号窗口进行核酸检测" << endl;
			nucleicAcidWindow0.isBusy = true;
			nucleicAcidWindow0.serviceStartTime = 0;
			NormalUserQueue.pop();
			int size;
			for (int i = 0; i < 20; i++)
			{
				if (Conduit[0][i].name.size() == 0)
				{
					size = i;
					break;
				}
			}
			Conduit[0][size] = nucleicAcidWindow0.personnel;
		}
		if (nucleicAcidWindow1.isBusy == false && !NormalUserQueue.empty())
		{
			nucleicAcidWindow1.personnel = NormalUserQueue.front();
			output(nucleicAcidWindow1.personnel);
			cout << "\t请到1号窗口进行核酸检测" << endl;
			nucleicAcidWindow1.isBusy = true;
			nucleicAcidWindow1.serviceStartTime = 0;
			NormalUserQueue.pop();
			int size;
			for (int i = 0; i < 20; i++)
			{
				if (Conduit[1][i].name.size() == 0)
				{
					size = i;
					break;
				}
			}
			Conduit[1][size] = nucleicAcidWindow1.personnel;
		}
		if (nucleicAcidWindow2.isBusy == false && !NormalUserQueue.empty())
		{
			nucleicAcidWindow2.personnel = NormalUserQueue.front();
			output(nucleicAcidWindow2.personnel);
			cout << "\t请到2号窗口进行核酸检测" << endl;
			nucleicAcidWindow2.isBusy = true;
			nucleicAcidWindow2.serviceStartTime = 0;
			NormalUserQueue.pop();
			int size;
			for (int i = 0; i < 20; i++)
			{
				if (Conduit[2][i].name.size() == 0)
				{
					size = i;
					break;
				}
			}
			Conduit[2][size] = nucleicAcidWindow2.personnel;
		}
		if (nucleicAcidWindow3.isBusy == false && !NormalUserQueue.empty())
		{
			nucleicAcidWindow3.personnel = NormalUserQueue.front();
			output(nucleicAcidWindow3.personnel);
			cout << "\t请到3号窗口进行核酸检测" << endl;
			nucleicAcidWindow3.isBusy = true;
			nucleicAcidWindow3.serviceStartTime = 0;
			NormalUserQueue.pop();
			int size;
			for (int i = 0; i < 20; i++)
			{
				if (Conduit[3][i].name.size() == 0)
				{
					size = i;
					break;
				}
			}
			Conduit[3][size] = nucleicAcidWindow3.personnel;
		}
		if (nucleicAcidWindow4.isBusy == false && !NormalUserQueue.empty())
		{
			nucleicAcidWindow4.personnel = NormalUserQueue.front();
			output(nucleicAcidWindow4.personnel);
			cout << "\t请到4号窗口进行核酸检测" << endl;
			nucleicAcidWindow4.isBusy = true;
			nucleicAcidWindow4.serviceStartTime = 0;
			NormalUserQueue.pop();
			int size;
			for (int i = 0; i < 20; i++)
			{
				if (Conduit[4][i].name.size() == 0)
				{
					size = i;
					break;
				}
			}
			Conduit[4][size] = nucleicAcidWindow4.personnel;
		}
	}
	// 查看同管人员
	void sameTube()
	{
		for (int i = 0; i < 5; i++)
		{
			cout << "第" << i << "管人员有: ";
			for (int j = 0; j < 20; j++)
			{
				if (Conduit[i][0].name.size() == 0)
				{
					cout << "-暂无人检测-" << endl;
					break;
				}
				else if (Conduit[i][j].name.size() == 0)
				{
					break;
				}
				cout << Conduit[i][j].name << " ";
			}
			cout << endl;
		}
		getchar();
	}
	// 核酸窗口状态展示
	void display()
	{
		cout << "当前核酸窗口状态: " << endl;
		windowCondition(nucleicAcidWindow0);
		windowCondition(nucleicAcidWindow1);
		windowCondition(nucleicAcidWindow2);
		windowCondition(nucleicAcidWindow3);
		windowCondition(nucleicAcidWindow4);
		getchar();
		// 获取随机时间, 修改窗口繁忙情况
		int time = (rand() % (6 - 1 + 1)) + 1;
		isBusy(time);
	}
	// 叫号检测
	void acidTest()
	{
		enterWindow();
		display();
		getchar();
	}
	// 查找身份证号是否在排队队列中存在
	bool searchQueue(queue<User> q, int searchValue)
	{
		int pos = 0;
		bool searchFlag = false;
		for (int i = 0; i < q.size(); ++i)
		{
			if (q.front().userID == searchValue && !searchFlag)
			{
				searchFlag = true;
				return true;
			}
			else
			{
				q.push(q.front());
				q.pop();
				pos++;
				return false;
			}
		}
	}
	void findAcid()
	{
		string sname;
		int pos = -1;
		cout << "\t\t请输入要查找的姓名: ";
		cin >> sname;
		for (int i = 0; i < 5; i++)
			for(int j = 0; j < 20; j++)
				if(Conduit[i][j].name == sname)
				{
					pos = i;
					break;
				} 
					
		if(pos == -1)
			cout<<"\t\t用户: "<<sname<<" 没有找到!"<<endl;
		else
		{
			cout<<"\t\t与 "<<sname<<" 同管检测的用户有: ";
			for(int i = 0;i<20;i++)
				cout << Conduit[pos][i].name << " ";
			cout<<endl<<"\t\t检测管号为: "<<pos<<endl;
		}
		getchar();
	}
	// 输入用户信息
	void customerEnter()
	{
		string name, id;
		int userId;
		cout << "\t\t请输入姓名: ";
		cin >> name;
		cout << "\t\t请输入身份证号: ";
		cin >> id;
		userId = stoi(id.substr(0, 4)); // 将字符串转为数字
										// std::stoi(str):字符串转数字  std::to_string(int):数字转字符串
		while (searchQueue(NormalUserQueue, userId))
		{
			cout << "\t\t当前身份证号重复, 请重新输入: ";
			cin >> id;
			userId = stoi(id.substr(0, 4));
		}
		User u(name, userId);
		enterQueue(u);
		getchar();
	}
	// 查看窗口的状态
	void windowCondition(NucleicAcidWindow nucleicAcidWindow)
	{
		cout << "\t\t窗口号:" << nucleicAcidWindow.id << "   ";
		if (nucleicAcidWindow.isBusy == true)
		{
			cout << "\t-正在服务-";
			output2(nucleicAcidWindow.personnel);
		}
		else
		{
			cout << "\t-等待检测-";
		}
		cout << endl;
	}
	void isBusy(int time) //扫描一遍窗口,检测服务是否结束
	{
		if (nucleicAcidWindow0.isBusy == true)
		{
			if (time - nucleicAcidWindow0.serviceStartTime >= serviceTime[0])
			{
				nucleicAcidWindow0.isBusy = false;
			}
		}
		if (nucleicAcidWindow1.isBusy == true)
		{
			if (time - nucleicAcidWindow1.serviceStartTime >= serviceTime[1])
			{
				nucleicAcidWindow1.isBusy = false;
			}
		}
		if (nucleicAcidWindow2.isBusy == true)
		{
			if (time - nucleicAcidWindow2.serviceStartTime >= serviceTime[2])
			{
				nucleicAcidWindow2.isBusy = false;
			}
		}
		if (nucleicAcidWindow3.isBusy == true)
		{
			if (time - nucleicAcidWindow3.serviceStartTime >= serviceTime[0])
			{
				nucleicAcidWindow3.isBusy = false;
			}
		}
		if (nucleicAcidWindow4.isBusy == true)
		{
			if (time - nucleicAcidWindow4.serviceStartTime >= serviceTime[1])
			{
				nucleicAcidWindow4.isBusy = false;
			}
		}
	}
	// void simulate()
	// {
	// 	int time = 0;
	// 	cout << "--------模拟开始--------" << endl;
	// 	cout << "初始化用户:" << endl;
	// 	for (int i = 0; i < 10; i++)
	// 	{
	// 		customerEnter();
	// 	}
	// 	enterWindow(time);
	// 	while (1)
	// 	{
	// 		display(time);
	// 		enterWindow(time);
	// 		isBusy(time);
	// 		if (time / 2 != 0)
	// 		{
	// 			customerEnter(); //没间隔两秒进入一位客户.
	// 		}
	// 		Sleep(1000);
	// 		time++;
	// 		if (time == 21)
	// 		{
	// 			break;
	// 		}
	// 	}
	// }
};
// 菜单面板
int showsel() //显示主菜单
{
	int sel;
	cout << "\t\t核酸排队叫号系统" << endl;
	cout << "\t---------------------------------------" << endl;
	cout << "\t\t0. 退出" << endl;
	cout << "\t\t1. 输入个人信息" << endl;
	cout << "\t\t2. 查看排队人数和等待时间" << endl;
	cout << "\t\t3. 查找同管采样人员" << endl;
	cout << "\t\t4. 查看窗口检测情况" << endl;
	cout << "\t\t5. 查看窗口状态" << endl;
	cout << "\t\t6. 叫号检测" << endl;
	cout << "\t----------------------------------------" << endl;
	cout << "\t\t请输入要选择的功能编号：";
	cin >> sel;
	return sel;
}
// 主函数调用方法
int main()
{
	Simulater simulater;
	// simulater.simulate();
	int sel;
	do
	{
		system("cls");	 //清屏
		sel = showsel(); //返回主菜单中的选择项
		switch (sel)	 //根据选择项调用对应的函数
		{
		case 0:
			break;
		case 1:
			system("cls");
			simulater.customerEnter();
			getchar();
			break; // 输入个人信息
		case 2:
			system("cls");
			simulater.showCountTime();
			getchar();
			break; // 查看排队人数和排队时间
		case 3:
			system("cls");
			simulater.findAcid();
			getchar();
			break; // 查看同管人数
		case 4:
			system("cls");
			simulater.sameTube();
			getchar();
			break; // 查看同管人数
		case 5:
			system("cls");
			simulater.display();
			getchar();
			break;
		case 6:
			system("cls");
			simulater.acidTest();
			break;
		}
	} while (sel); //当选择主菜单中序号0时，结束程序
	return 0;
}
