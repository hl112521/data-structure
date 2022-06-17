#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <time.h>
#include <windows.h>
#include <stdio.h>
using namespace std;

/*
�������û���
*/
class User
{
public:
	int userID; // ��λ���֤��
	string name;
	User()
	{
		name = "";
		userID = 0;
	}
	User(string n, int id) { userID = id, name = n; }
};
/*
�����ⴰ����
*/
class NucleicAcidWindow
{
public:
	int id; //��ǰ���ᴰ��id ���ĸ�����
	bool isBusy;
	User personnel; // �����Ŷӵ��û�
	int serviceStartTime = 0;
	NucleicAcidWindow() { isBusy = false; }
	NucleicAcidWindow(int i)
	{
		id = i;
		isBusy = false;
	}
};
/*
ģ������, ģ�����кŵĸ��ֹ���
*/
class Simulater
{
private:
	int serviceTime[3] = {2, 4, 6};
	int userIdList[100];
	struct User Conduit[5][20]; // �ṹ������, ���ڴ��ͬ�ܼ����Ա
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
		// ��ʼ�������ⴰ��, ����5������
		nucleicAcidWindow0.id = 0;
		nucleicAcidWindow1.id = 1;
		nucleicAcidWindow2.id = 2;
		nucleicAcidWindow3.id = 3;
		nucleicAcidWindow4.id = 4;
		srand(unsigned(time(0))); // ���ڸ�rand()�����趨���ӣ�����seed��rand()�����ӣ�������ʼ��rand()����ʼֵ
	}
	// �к��Ŷ�
	void enterQueue(User user)
	{
		cout << "\t\t����û�: " << user.userID << " �����Ŷ�"
			 << ", ����: " << user.name << endl;
		NormalUserQueue.push(user);
		cout << "\t\t��ǰ�Ŷ�����Ϊ: " << NormalUserQueue.size();
	}
	// �鿴�Ŷ������͵ȴ�ʱ��
	void showCountTime()
	{
		cout << "\t\t��ǰ�Ŷ�����Ϊ: " << NormalUserQueue.size() << endl;
		cout << "\t\t��Ҫ�ȴ�:" << NormalUserQueue.size() << " ����" << endl;
		getchar();
	}
	void output(User user)
	{
		cout << "\t\t����û� " << user.userID
			 << ", ����Ϊ: " << user.name;
	}
	void output2(User user)
	{
		cout << "  �������: "
			 << "����  "
			 << "����û�: " << user.name;
	}
	// ���ں����Ŷ�
	void enterWindow()
	{
		// ���ڿ���, �������û����ŶӶ�����
		if (nucleicAcidWindow0.isBusy == false && !NormalUserQueue.empty())
		{
			nucleicAcidWindow0.personnel = NormalUserQueue.front();
			output(nucleicAcidWindow0.personnel);
			cout << "\t�뵽0�Ŵ��ڽ��к�����" << endl;
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
			cout << "\t�뵽1�Ŵ��ڽ��к�����" << endl;
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
			cout << "\t�뵽2�Ŵ��ڽ��к�����" << endl;
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
			cout << "\t�뵽3�Ŵ��ڽ��к�����" << endl;
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
			cout << "\t�뵽4�Ŵ��ڽ��к�����" << endl;
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
	// �鿴ͬ����Ա
	void sameTube()
	{
		for (int i = 0; i < 5; i++)
		{
			cout << "��" << i << "����Ա��: ";
			for (int j = 0; j < 20; j++)
			{
				if (Conduit[i][0].name.size() == 0)
				{
					cout << "-�����˼��-" << endl;
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
	// ���ᴰ��״̬չʾ
	void display()
	{
		cout << "��ǰ���ᴰ��״̬: " << endl;
		windowCondition(nucleicAcidWindow0);
		windowCondition(nucleicAcidWindow1);
		windowCondition(nucleicAcidWindow2);
		windowCondition(nucleicAcidWindow3);
		windowCondition(nucleicAcidWindow4);
		getchar();
		// ��ȡ���ʱ��, �޸Ĵ��ڷ�æ���
		int time = (rand() % (6 - 1 + 1)) + 1;
		isBusy(time);
	}
	// �кż��
	void acidTest()
	{
		enterWindow();
		display();
		getchar();
	}
	// �������֤���Ƿ����ŶӶ����д���
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
		cout << "\t\t������Ҫ���ҵ�����: ";
		cin >> sname;
		for (int i = 0; i < 5; i++)
			for(int j = 0; j < 20; j++)
				if(Conduit[i][j].name == sname)
				{
					pos = i;
					break;
				} 
					
		if(pos == -1)
			cout<<"\t\t�û�: "<<sname<<" û���ҵ�!"<<endl;
		else
		{
			cout<<"\t\t�� "<<sname<<" ͬ�ܼ����û���: ";
			for(int i = 0;i<20;i++)
				cout << Conduit[pos][i].name << " ";
			cout<<endl<<"\t\t���ܺ�Ϊ: "<<pos<<endl;
		}
		getchar();
	}
	// �����û���Ϣ
	void customerEnter()
	{
		string name, id;
		int userId;
		cout << "\t\t����������: ";
		cin >> name;
		cout << "\t\t���������֤��: ";
		cin >> id;
		userId = stoi(id.substr(0, 4)); // ���ַ���תΪ����
										// std::stoi(str):�ַ���ת����  std::to_string(int):����ת�ַ���
		while (searchQueue(NormalUserQueue, userId))
		{
			cout << "\t\t��ǰ���֤���ظ�, ����������: ";
			cin >> id;
			userId = stoi(id.substr(0, 4));
		}
		User u(name, userId);
		enterQueue(u);
		getchar();
	}
	// �鿴���ڵ�״̬
	void windowCondition(NucleicAcidWindow nucleicAcidWindow)
	{
		cout << "\t\t���ں�:" << nucleicAcidWindow.id << "   ";
		if (nucleicAcidWindow.isBusy == true)
		{
			cout << "\t-���ڷ���-";
			output2(nucleicAcidWindow.personnel);
		}
		else
		{
			cout << "\t-�ȴ����-";
		}
		cout << endl;
	}
	void isBusy(int time) //ɨ��һ�鴰��,�������Ƿ����
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
	// 	cout << "--------ģ�⿪ʼ--------" << endl;
	// 	cout << "��ʼ���û�:" << endl;
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
	// 			customerEnter(); //û����������һλ�ͻ�.
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
// �˵����
int showsel() //��ʾ���˵�
{
	int sel;
	cout << "\t\t�����Ŷӽк�ϵͳ" << endl;
	cout << "\t---------------------------------------" << endl;
	cout << "\t\t0. �˳�" << endl;
	cout << "\t\t1. ���������Ϣ" << endl;
	cout << "\t\t2. �鿴�Ŷ������͵ȴ�ʱ��" << endl;
	cout << "\t\t3. ����ͬ�ܲ�����Ա" << endl;
	cout << "\t\t4. �鿴���ڼ�����" << endl;
	cout << "\t\t5. �鿴����״̬" << endl;
	cout << "\t\t6. �кż��" << endl;
	cout << "\t----------------------------------------" << endl;
	cout << "\t\t������Ҫѡ��Ĺ��ܱ�ţ�";
	cin >> sel;
	return sel;
}
// ���������÷���
int main()
{
	Simulater simulater;
	// simulater.simulate();
	int sel;
	do
	{
		system("cls");	 //����
		sel = showsel(); //�������˵��е�ѡ����
		switch (sel)	 //����ѡ������ö�Ӧ�ĺ���
		{
		case 0:
			break;
		case 1:
			system("cls");
			simulater.customerEnter();
			getchar();
			break; // ���������Ϣ
		case 2:
			system("cls");
			simulater.showCountTime();
			getchar();
			break; // �鿴�Ŷ��������Ŷ�ʱ��
		case 3:
			system("cls");
			simulater.findAcid();
			getchar();
			break; // �鿴ͬ������
		case 4:
			system("cls");
			simulater.sameTube();
			getchar();
			break; // �鿴ͬ������
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
	} while (sel); //��ѡ�����˵������0ʱ����������
	return 0;
}
