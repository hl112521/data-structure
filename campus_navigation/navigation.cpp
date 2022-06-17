#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <stack>
#include <windows.h>
#include<iomanip>
#define MAXNUM 100 //��󾰵�����
#define INF 1e6 //·����󳤶�,��ʾ��·��ͨ
using namespace std;
//����Ա�˺�  dxd
//����Ա���� 123456
void delay();//�ӳ�
void init ();//��ʼ��
void campus_maps();//��ͼȫò
int find_node(string name);//��λ��
void Dijkstra (int start,int end);//Dijkstra �����·��������ӡ����
void Visiter();//�ο�ϵͳ
void Administrator();//����Աϵͳ
void add_Info();//���Ӿ���
void delete_Info();//ɾ������
void add_path();//���ӵ�·
void delete_path();//ɾ����·

int path[MAXNUM][MAXNUM]; //������һ�����
int short_path[MAXNUM][MAXNUM]; //���·���ĳ���
struct building
{
    string name; //��������
    int code;//����
    string information;//������Ϣ
};
int building_number = 31;
struct building ve[MAXNUM];
//---------------�ڽӾ���洢����ͱ�
int weight[MAXNUM][MAXNUM] = {{0}}; //Ȩ�ؾ��ǳ���
//-----------�ӳ�----
void delay()
{
    for(long long i = 0; i < 1e9; i++);
}
void init ()
{
    //-------------����洢�����Ϣ
    ve[0] = {"Уҽ��", 0, "����Уҽ��"};
    ve[1] = {"��ʳ��", 1, "���Ƕ�ʳ��"};
    ve[2] = {"��ʳ��", 2, " "};
    ve[3] = {"һʳ��", 3, " "};
    ve[4] = {"�����ھ�", 4, " "};
    ve[5] = {"������", 5, " "};
    ve[6] = {"��A", 6, " "};
    ve[7] = {"��B", 7, " "};
    ve[8] = {"��C", 8, " "};
    ve[9] = {"ʵA", 9, " "};
    ve[10] = {"ʵB", 10, " "};
    ve[11] = {"ʵC", 11, " "};
    ve[12] = {"ͼ���", 12, " "};
    ve[13] = {"С������", 13, " "};
    ve[14] = {"�󱨸���", 14, " "};
    ve[15] = {"�Ͻ��", 15, " "};
    ve[16] = {"�ٳ�", 16, " "};
    ve[17] = {"������", 17, " "};
    ve[18] = {"����", 18, " "};
    ve[19] = {"����", 19, " "};
    ve[20] = {"����", 20, " "};
    ve[21] = {"����A��", 21, " "};
    ve[22] = {"����B��", 22, " "};
    ve[23] = {"����C��", 23, " "};
    ve[24] = {"����D��", 24, " "};
    ve[25] = {"�Ƽ�¥", 25, " "};
    ve[26] = {"����¥", 26, " "};
    ve[27] = {"����", 27, " "};
    ve[28] = {"������", 28, " "};
    ve[29] = {"����", 29, " "};
    ve[30] = {"��ʦ��Ԣ", 30, " "};
//----Ȩ�ر�ʾ���� �ڽӾ���洢
    weight[0][2]=weight[2][0] = 10;
    weight[0][16]=weight[16][0] = 30;
    weight[0][22]=weight[22][0] = 20;
    weight[22][16]=weight[16][22] = 40;
    weight[22][3]=weight[3][22] = 20;
    weight[22][4]=weight[4][22] = 60;
    weight[3][4] =weight[4][3]= 10;
    weight[4][21]=weight[21][4] = 20;
    weight[4][27]=weight[27][4] = 30;
    weight[2][30]=weight[30][2] = 30;
    weight[30][16] =weight[16][30]= 80;
    weight[16][20]=weight[20][16] = 25;
    weight[20][17]=weight[17][20] = 60;
    weight[17][19]=weight[19][17] = 30;
    weight[19][18]=weight[18][29] = 10;
    weight[21][17] =weight[17][21]= 15;
    weight[3][17]=weight[17][3] = 25;
    weight[18][28] =weight[28][18]= 50;
    weight[18][26] =weight[26][18]= 45;
    weight[26][6] =weight[6][26]= 20;
    weight[7][8] =weight[8][7]= 10;
    weight[6][7]=weight[7][6] = 10;
    weight[16][8]=weight[8][16] = 100;
    weight[7][15]=weight[15][7] = 30;
    weight[8][12]=weight[12][8] = 60;
    weight[12][13]=weight[13][12] = 10;
    weight[12][14]=weight[14][12] = 10;
    weight[15][10]=weight[10][15] = 20;
    weight[10][29]=weight[29][10] = 15;
    weight[9][10]=weight[10][9] = 10;
    weight[10][11]=weight[11][10] = 20;
    weight[29][25]=weight[25][29] = 10;
    weight[25][24]=weight[24][25] = 25;
    weight[24][23]=weight[23][24] = 10;
}
//--------------��ӡ��ͼ
void campus_maps()
{
    int count=0;
    printf(" ==========================================================================\n");
    cout << "||             *** �Ͼ�����ѧ�Ͻ�ѧԺ���о���***                        ||"<< endl;
    cout << "||                                                                        ||"<< endl;
    cout <<"||";
    for(int i=0; i<building_number; i++)
    {
        printf("%2d��",ve[i].code);
        cout <<setiosflags(ios::left)<<setw(20)<< ve[i].name;
        count++;
        if(count==3)
        {
            cout <<"||"<< endl;
            count=0;
            cout <<"||";
        }
    }
    cout << endl;
    printf(" ==========================================================================\n");

}

//---------��ѯģʽ--��ӡ��ص����Ϣ

int find_node(string name)
{
    for(int i = 0; i < building_number; i++)
    {
        if(ve[i].name == name)
        {
            return i; //�ҵ��ˣ��������Ӧ��λ��
            break;
        }
    }
    return -1;//û���ҵ�����-1

}

//��·ģʽ------Dijkstra �����·��������ӡ����
void Dijkstra (int start, int end)
{
    int dis[building_number];
    int path[building_number];
    for(int i = 0; i < building_number; i++) //��ʼ��dis path
    {
        if(start != i && weight[start][i] == 0)
            dis[i] = INF;
        else if(weight[start][i] != 0)
            dis[i] = weight[start][i];
        else if(start == i)
            dis[i] = 0;
        path[i] = -1;
    }
    bool visited[building_number] = {false};
    // int s=start;
    visited[start] = true;
    while(1)
    {
        int j;
        bool flag = false;
        for(j = 0; j < building_number; j++)
        {
            if(visited[j] == false)
            {
                flag = true;
                break;
            }
        }
        int min = j;
        if(flag == false)
            break;
        for(int i = 0; i < building_number; i++)
        {
            if(visited[i] == false)
                if(dis[min] > dis[i])
                    min = i;

        }
        visited[min] = true; //��¼����������dis������С��
        for(int i = 0; i < building_number; i++)
        {
            if(weight[min][i] != 0 && visited[i] == false) //i��min���ڽӵ�
                if(dis[i] > dis[min] + weight[min][i])
                {
                    dis[i] = dis[min] + weight[min][i];
                    //��ʱ�ģ����������룬��ȷ���ǲ���dist��С�ģ����߲�ȷ��������û�и�С��
                    path[i] = min; //��ʱ��
                }

        }
    }
    if(dis[end]==INF)
        cout << "��" << ve[start].name << "->" << ve[end].name<<"��ͨ"<< endl;
    else
    {
        cout << "��" << ve[start].name << "->" << ve[end].name << "�����·��Ϊ��  " << dis[end] << "km\n"<< "·��Ϊ��";
        int n = end;
        stack<int> st;
        st.push(end);
        while(path[n] != -1)
        {
            st.push(path[n]);
            n = path[n];
        }
        st.push(start);
        cout << ve[st.top()].name;
        st.pop();
        while (!st.empty())
        {
            cout << "->" << ve[st.top()].name;
            st.pop();
        }
        cout << endl;
    }
}
//-------�ο�ϵͳ
void Visiter()
{
    campus_maps();
    int a = 1;
    char ch;
    while(a == 1)
    {
        printf(" ================================================================ \n");
        printf("||            ��ӭ�����Ͼ�����ѧ�Ͻ�ѧԺУ԰����ϵͳ          ||\n");
        printf("||                                                              ||\n");
        printf("||                    ***�ο�ϵͳ***                            ||\n");
        printf("||                                                              ||\n");
        printf("||                  <1>��ѯ���⾰��                             ||\n");
        printf("||                  <2>��·��ѯ                                 ||\n");
        printf("||                  <3>�˳�ϵͳ                                 ||\n");
        printf("||                                                              ||\n");
        printf(" ================================================================ \n");
        printf("����������ָ��:  ");
        cin >> ch;
        if(ch != '1' && ch != '2' && ch != '3')
        {
            cout << "�����������������" << endl;
            cin >> ch;
        }
        //------��ѯģʽ
        while(ch == '1')
        {
            string find_name;
            cout << "����Ҫ�飺";
            cin >> find_name;
            int i = find_node(find_name);
            while(i == -1)
            {
                cout << "�޴���Ϣ������������" ;
                cin >> find_name;
                i = find_node(find_name);
            }
            cout << "������ϢΪ��" << ve[i].name << endl;
            cout << "��飺" << ve[i].information << endl;
            delay();
            break;
        }
        //----��·ģʽ
        while(ch == '2')
        {
            string start_name;
            cout << "������㣺";
            cin >> start_name;
            int i = find_node(start_name);
            while(i == -1)
            {
                cout << "�޴���Ϣ������������" << endl;
                cin >> start_name;
                i = find_node(start_name);
            }
            string end_name;
            cout << "�����յ㣺";
            cin >> end_name;
            int j = find_node(end_name);
            while(j == -1)
            {
                cout << "�޴���Ϣ������������" << endl;
                cin >> end_name;
                j = find_node(end_name);
            }
            Dijkstra(i, j);
            delay();
            break;
        }
        while(ch == '3')
        {
            cout << "лл���ټ���" << endl;
            a=0;
            break;
            exit(0);
        }
    }
}
//--------����Աϵͳ
void Administrator()
{
    int a = 1;
    char ch;
    campus_maps();
    while(a == 1)
    {
        printf(" ================================================================ \n");
        printf("||            ��ӭ�����Ͼ�����ѧ�Ͻ�ѧԺУ԰����ϵͳ          ||\n");
        printf("||                                                              ||\n");
        printf("||                    ***����Աϵͳ***                          ||\n");
        printf("||                                                              ||\n");
        printf("||                  <1>��ѯ���⾰��                             ||\n");
        printf("||                  <2>��·��ѯ                                 ||\n");
        printf("||                  <3>���Ӿ���                                 ||\n");
        printf("||                  <4>ɾ������                                 ||\n");
        printf("||                  <5>���ӵ�·                                 ||\n");
        printf("||                  <6>ɾ����·                                 ||\n");
        printf("||                  <7>�˳�ϵͳ                                 ||\n");
        printf("||                                                              ||\n");
        printf(" ================================================================ \n");
        printf("����������ָ��:  ");
        cin >> ch;
        if(ch != '1' && ch != '2' && ch != '3'&&ch!='4'&&ch!='5'&&ch!='6'&&ch!='7')
        {
            cout << "�����������������" << endl;
            cin >> ch;
        }
        //------��ѯģʽ
        while(ch == '1')
        {
            string find_name;
            cout << "����Ҫ�飺";
            cin >> find_name;
            int i = find_node(find_name);
            while(i == -1)
            {
                cout << "�޴���Ϣ������������" ;
                cin >> find_name;
                i = find_node(find_name);
            }
            cout << "������ϢΪ��" << ve[i].name << endl;
            cout << "��飺" << ve[i].information << endl;
            delay();
            break;
        }
        //----��·ģʽ
        while(ch == '2')
        {
            string start_name;
            cout << "������㣺";
            cin >> start_name;
            int i = find_node(start_name);
            string end_name;
            cout << "�����յ㣺";
            cin >> end_name;
            int j = find_node(end_name);
            while(i == -1||j==-1)
            {
                cout << "�޴���Ϣ������������" << endl;
                cout << "������㣺";
                cin >> start_name;
                i=find_node(start_name);
                cout << "�����յ㣺";
                cin >> end_name;
                j=find_node(end_name);
            }
            Dijkstra(i, j);
            delay();
            break;
        }
        while(ch == '3')
        {
            add_Info();
            break;
        }
        while(ch == '4')
        {
            delete_Info();
            break;
        }
        while(ch == '5')
        {
            add_path();
            break;
        }
        while(ch == '6')
        {
            delete_path();
            break;
        }
        while(ch == '7')
        {
            cout << "лл���ټ���" << endl;
            a=0;
            exit(0);
            break;
        }

    }


}




/*

//-----------��·ģʽ---ʵ��ָ���㵽���е�����·��

void short_path_floyd(int weight[][MAXNUM], int path[][MAXNUM], int short_path[][MAXNUM])
{
    for (int i = 0; i < building_number; i++)//��ʼ��  path_matrix  ��  short_path_table
    {
        for (int j = 0; j < building_number; j++)
        {
            short_path[i][j] = weight[i][j];
            path[i][j] = j;
        }
    }
    for (int i = 0; i < building_number; i++)
    {
        for (int j = 0; j < building_number; j++)
        {
            for (int k = 0; k< building_number; k++)
            {
                if (short_path[j][k] > short_path[j][i] + short_path[i][k])
                {
                    short_path[j][k] = short_path[j][i] + short_path[i][k];
                    path[j][k] = path[j][i];
                }
            }
        }
    }
}

*/




//-------���Ӿ���

void add_Info()
{
    struct building info;
    string add_name;
    cout << "���������ӵľ������ƣ�" ;
    cin >> add_name;
    int i=find_node(add_name);
    while(i!=-1)
    {
        cout << "�þ����Ѵ��ڣ�����������"<< endl;
        cout << "���������Ӿ������ƣ�";
        cin >> add_name;
        i=find_node(add_name);
    }
    string brief;
    cout << "�����뾰����Ϣ��飺";
    cin >> brief;
    info.code = building_number ;
    info.name = add_name;
    info.information = brief;
    ve[building_number]=info;
    building_number++;
    cout << "������ӳɹ���" << endl;
    campus_maps();

}

void delete_Info()
{
    string info_name;
    cout << "��������Ҫɾ���ľ��㣺";
    cin >> info_name;
    int i = find_node(info_name);
    while(i == -1)
    {
        cout << "�޴���Ϣ������������"  << endl;
        cin >> info_name;
        i = find_node(info_name);
    }
    cout << "��Ҫɾ���ľ������ƣ�" << ve[i].name << endl;
    cout << "�Ƿ�ȷ��ɾ����ȷ������1" << endl;
    char ch;
    cin >> ch;
    if(ch == '1')
    {
        cout << "����ɾ������...." << endl;
        for(int k=i; k<building_number-1; k++)
        {
            ve[k].name=ve[k+1].name;
            ve[k].information=ve[k+1].information;
        }
        int m,n;
        for(int m=i; m<building_number-1; m++)
        {
            for(int n=0; n<building_number; n++)
            {
                weight[m][n]=weight[m+1][n];
            }
        }
        building_number--;
        cout << "����ɾ���ɹ�" << endl;
        campus_maps();
    }
}


void add_path()
{
    cout << "������Ҫ���ӵ�·����������:" << endl;
    string name1, name2;
    cin >> name1 >> name2;
    int i = find_node(name1);
    int j = find_node(name2);
    while(i == -1 || j == -1)
    {
        cout << "�������������д�������������" ;
        cin >> name1 >> name2;
    }
    int distance;
    cout << "������" << name1 << "��" << name2 << "֮���·�ĳ��ȣ�";
    cin >> distance;
    cout << "������ӵ�·......" << endl;
    weight[i][j] = distance;
    weight[j][i] = distance;
    cout << "��·��ӳɹ�" << endl;
}

void delete_path()
{
    cout << "������Ҫɾ����·���������㣺" << endl;
    string name1, name2;
    cin >> name1 >> name2;
    int i = find_node(name1);
    int j = find_node(name2);
    while(i == -1 || j == -1)
    {
        cout << "�������������д�������������" ;
        cin >> name1 >> name2;
    }
    cout << "��Ҫɾ������" << name1  << "��" << name2 << "֮��ĵ�·���Ƿ�ȷ��ɾ��������·��" << endl;
    cout << "ȷ��������1" << endl;
    char ch;
    cin >> ch;
    if(ch == '1')
    {
        cout << "����ɾ����·" << endl;
        weight[i][j] = 0;
        weight[j][i] = 0;
        delay();
        cout << "��·ɾ���ɹ�" << endl;
    }
}



int main()
{
    init(); //��ʼ�����洢�������
    char mode;
    int a = 1;
    while(a == 1)
    {
        printf(" ================================================================ \n");
        printf("||            ��ӭ�����Ͼ�����ѧ�Ͻ�ѧԺУ԰����ϵͳ          ||\n");
        printf("||                                                              ||\n");
        printf("||                                                              ||\n");
        printf("||                  <1>�ο͵�¼                                 ||\n");
        printf("||                  <2>����Ա��¼                               ||\n");
        printf("||                  <3>�˳�ϵͳ                                 ||\n");
        printf("||                                                              ||\n");
        printf(" ================================================================ \n");
        printf("����������ָ��:  ");
        cin >> mode;
        while(mode != '1' && mode != '2' && mode != '3')
        {
            cout << "�����������������룡" << endl;
            cin >> mode;
        }
        //--------�ο͵�¼����
        while(mode == '1')
        {
            system("cls");
            Visiter();
            exit(0);
        }
        while(mode == '2')
        {
            cout << "�������˺ţ�";
            string account;
            string  password;
            cin >> account;
            cout << "���������룺";
            cin >> password;
            while(account != "dxd" && password != "123456")
            {
                cout << "�˺Ż������������������" << endl;
                cout << "�������˺ţ�";
                cin >> account;
                cout << "���������룺";
                cin >> password;
            }
            cout << "\t\t\t��¼�ɹ�......" << endl;
            delay();
            Administrator();
            exit(0);
            a=0;
        }
        while(mode == '3')
        {
            cout << "лл���ټ���" << endl;
            a = 0;
            exit(0);
        }
    }
}

