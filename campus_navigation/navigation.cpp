#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <stack>
#include <windows.h>
#include<iomanip>
#define MAXNUM 100 //最大景点数量
#define INF 1e6 //路径最大长度,表示此路不通
using namespace std;
//管理员账号  dxd
//管理员密码 123456
void delay();//延迟
void init ();//初始化
void campus_maps();//地图全貌
int find_node(string name);//找位置
void Dijkstra (int start,int end);//Dijkstra 求最短路径，并打印出来
void Visiter();//游客系统
void Administrator();//管理员系统
void add_Info();//增加景点
void delete_Info();//删除景点
void add_path();//增加道路
void delete_path();//删除道路

int path[MAXNUM][MAXNUM]; //保存下一个结点
int short_path[MAXNUM][MAXNUM]; //最短路径的长度
struct building
{
    string name; //建筑名称
    int code;//代号
    string information;//建筑信息
};
int building_number = 31;
struct building ve[MAXNUM];
//---------------邻接矩阵存储顶点和边
int weight[MAXNUM][MAXNUM] = {{0}}; //权重就是长度
//-----------延迟----
void delay()
{
    for(long long i = 0; i < 1e9; i++);
}
void init ()
{
    //-------------数组存储相关信息
    ve[0] = {"校医室", 0, "这是校医室"};
    ve[1] = {"二食堂", 1, "这是二食堂"};
    ve[2] = {"三食堂", 2, " "};
    ve[3] = {"一食堂", 3, " "};
    ve[4] = {"龙门镖局", 4, " "};
    ve[5] = {"鱼米乡", 5, " "};
    ve[6] = {"教A", 6, " "};
    ve[7] = {"教B", 7, " "};
    ve[8] = {"教C", 8, " "};
    ve[9] = {"实A", 9, " "};
    ve[10] = {"实B", 10, " "};
    ve[11] = {"实C", 11, " "};
    ve[12] = {"图书馆", 12, " "};
    ve[13] = {"小报告厅", 13, " "};
    ve[14] = {"大报告厅", 14, " "};
    ve[15] = {"紫金湖", 15, " "};
    ve[16] = {"操场", 16, " "};
    ve[17] = {"体育馆", 17, " "};
    ve[18] = {"篮球场", 18, " "};
    ve[19] = {"排球场", 19, " "};
    ve[20] = {"网球场", 20, " "};
    ve[21] = {"宿舍A区", 21, " "};
    ve[22] = {"宿舍B区", 22, " "};
    ve[23] = {"宿舍C区", 23, " "};
    ve[24] = {"宿舍D区", 24, " "};
    ve[25] = {"科技楼", 25, " "};
    ve[26] = {"行政楼", 26, " "};
    ve[27] = {"东门", 27, " "};
    ve[28] = {"东南门", 28, " "};
    ve[29] = {"西门", 29, " "};
    ve[30] = {"教师公寓", 30, " "};
//----权重表示长度 邻接矩阵存储
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
//--------------打印地图
void campus_maps()
{
    int count=0;
    printf(" ==========================================================================\n");
    cout << "||             *** 南京理工大学紫金学院所有景点***                        ||"<< endl;
    cout << "||                                                                        ||"<< endl;
    cout <<"||";
    for(int i=0; i<building_number; i++)
    {
        printf("%2d、",ve[i].code);
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

//---------查询模式--打印相关点的信息

int find_node(string name)
{
    for(int i = 0; i < building_number; i++)
    {
        if(ve[i].name == name)
        {
            return i; //找到了，返回相对应的位置
            break;
        }
    }
    return -1;//没有找到返回-1

}

//问路模式------Dijkstra 求最短路径，并打印出来
void Dijkstra (int start, int end)
{
    int dis[building_number];
    int path[building_number];
    for(int i = 0; i < building_number; i++) //初始化dis path
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
        visited[min] = true; //收录的条件就是dis里面最小的
        for(int i = 0; i < building_number; i++)
        {
            if(weight[min][i] != 0 && visited[i] == false) //i是min的邻接点
                if(dis[i] > dis[min] + weight[min][i])
                {
                    dis[i] = dis[min] + weight[min][i];
                    //暂时的，还不能收入，不确定是不是dist最小的，或者不确定后面有没有更小的
                    path[i] = min; //暂时的
                }

        }
    }
    if(dis[end]==INF)
        cout << "从" << ve[start].name << "->" << ve[end].name<<"不通"<< endl;
    else
    {
        cout << "从" << ve[start].name << "->" << ve[end].name << "的最短路径为：  " << dis[end] << "km\n"<< "路径为：";
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
//-------游客系统
void Visiter()
{
    campus_maps();
    int a = 1;
    char ch;
    while(a == 1)
    {
        printf(" ================================================================ \n");
        printf("||            欢迎来到南京理工大学紫金学院校园导航系统          ||\n");
        printf("||                                                              ||\n");
        printf("||                    ***游客系统***                            ||\n");
        printf("||                                                              ||\n");
        printf("||                  <1>查询任意景点                             ||\n");
        printf("||                  <2>问路查询                                 ||\n");
        printf("||                  <3>退出系统                                 ||\n");
        printf("||                                                              ||\n");
        printf(" ================================================================ \n");
        printf("请输入您的指令:  ");
        cin >> ch;
        if(ch != '1' && ch != '2' && ch != '3')
        {
            cout << "输入错误，请重新输入" << endl;
            cin >> ch;
        }
        //------查询模式
        while(ch == '1')
        {
            string find_name;
            cout << "你想要查：";
            cin >> find_name;
            int i = find_node(find_name);
            while(i == -1)
            {
                cout << "无此信息，请重新输入" ;
                cin >> find_name;
                i = find_node(find_name);
            }
            cout << "所查信息为：" << ve[i].name << endl;
            cout << "简介：" << ve[i].information << endl;
            delay();
            break;
        }
        //----问路模式
        while(ch == '2')
        {
            string start_name;
            cout << "输入起点：";
            cin >> start_name;
            int i = find_node(start_name);
            while(i == -1)
            {
                cout << "无此信息，请重新输入" << endl;
                cin >> start_name;
                i = find_node(start_name);
            }
            string end_name;
            cout << "输入终点：";
            cin >> end_name;
            int j = find_node(end_name);
            while(j == -1)
            {
                cout << "无此信息，请重新输入" << endl;
                cin >> end_name;
                j = find_node(end_name);
            }
            Dijkstra(i, j);
            delay();
            break;
        }
        while(ch == '3')
        {
            cout << "谢谢，再见！" << endl;
            a=0;
            break;
            exit(0);
        }
    }
}
//--------管理员系统
void Administrator()
{
    int a = 1;
    char ch;
    campus_maps();
    while(a == 1)
    {
        printf(" ================================================================ \n");
        printf("||            欢迎来到南京理工大学紫金学院校园导航系统          ||\n");
        printf("||                                                              ||\n");
        printf("||                    ***管理员系统***                          ||\n");
        printf("||                                                              ||\n");
        printf("||                  <1>查询任意景点                             ||\n");
        printf("||                  <2>问路查询                                 ||\n");
        printf("||                  <3>增加景点                                 ||\n");
        printf("||                  <4>删除景点                                 ||\n");
        printf("||                  <5>增加道路                                 ||\n");
        printf("||                  <6>删除道路                                 ||\n");
        printf("||                  <7>退出系统                                 ||\n");
        printf("||                                                              ||\n");
        printf(" ================================================================ \n");
        printf("请输入您的指令:  ");
        cin >> ch;
        if(ch != '1' && ch != '2' && ch != '3'&&ch!='4'&&ch!='5'&&ch!='6'&&ch!='7')
        {
            cout << "输入错误，请重新输入" << endl;
            cin >> ch;
        }
        //------查询模式
        while(ch == '1')
        {
            string find_name;
            cout << "你想要查：";
            cin >> find_name;
            int i = find_node(find_name);
            while(i == -1)
            {
                cout << "无此信息，请重新输入" ;
                cin >> find_name;
                i = find_node(find_name);
            }
            cout << "所查信息为：" << ve[i].name << endl;
            cout << "简介：" << ve[i].information << endl;
            delay();
            break;
        }
        //----问路模式
        while(ch == '2')
        {
            string start_name;
            cout << "输入起点：";
            cin >> start_name;
            int i = find_node(start_name);
            string end_name;
            cout << "输入终点：";
            cin >> end_name;
            int j = find_node(end_name);
            while(i == -1||j==-1)
            {
                cout << "无此信息，请重新输入" << endl;
                cout << "输入起点：";
                cin >> start_name;
                i=find_node(start_name);
                cout << "输入终点：";
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
            cout << "谢谢，再见！" << endl;
            a=0;
            exit(0);
            break;
        }

    }


}




/*

//-----------问路模式---实现指定点到所有点的最短路径

void short_path_floyd(int weight[][MAXNUM], int path[][MAXNUM], int short_path[][MAXNUM])
{
    for (int i = 0; i < building_number; i++)//初始化  path_matrix  和  short_path_table
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




//-------增加景点

void add_Info()
{
    struct building info;
    string add_name;
    cout << "请输入增加的景点名称：" ;
    cin >> add_name;
    int i=find_node(add_name);
    while(i!=-1)
    {
        cout << "该景点已存在，请重新输入"<< endl;
        cout << "请输入增加景点名称：";
        cin >> add_name;
        i=find_node(add_name);
    }
    string brief;
    cout << "请输入景点信息简介：";
    cin >> brief;
    info.code = building_number ;
    info.name = add_name;
    info.information = brief;
    ve[building_number]=info;
    building_number++;
    cout << "景点添加成功！" << endl;
    campus_maps();

}

void delete_Info()
{
    string info_name;
    cout << "请输入您要删除的景点：";
    cin >> info_name;
    int i = find_node(info_name);
    while(i == -1)
    {
        cout << "无此信息，请重新输入"  << endl;
        cin >> info_name;
        i = find_node(info_name);
    }
    cout << "您要删除的景点名称：" << ve[i].name << endl;
    cout << "是否确认删除？确认输入1" << endl;
    char ch;
    cin >> ch;
    if(ch == '1')
    {
        cout << "正在删除景点...." << endl;
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
        cout << "景点删除成功" << endl;
        campus_maps();
    }
}


void add_path()
{
    cout << "请输入要增加道路的两个景点:" << endl;
    string name1, name2;
    cin >> name1 >> name2;
    int i = find_node(name1);
    int j = find_node(name2);
    while(i == -1 || j == -1)
    {
        cout << "两个景点名称有错误，请重新输入" ;
        cin >> name1 >> name2;
    }
    int distance;
    cout << "请输入" << name1 << "与" << name2 << "之间道路的长度：";
    cin >> distance;
    cout << "正在添加道路......" << endl;
    weight[i][j] = distance;
    weight[j][i] = distance;
    cout << "道路添加成功" << endl;
}

void delete_path()
{
    cout << "请输入要删除道路的两个景点：" << endl;
    string name1, name2;
    cin >> name1 >> name2;
    int i = find_node(name1);
    int j = find_node(name2);
    while(i == -1 || j == -1)
    {
        cout << "两个景点名称有错误，请重新输入" ;
        cin >> name1 >> name2;
    }
    cout << "您要删除的是" << name1  << "与" << name2 << "之间的道路，是否确认删除这条道路？" << endl;
    cout << "确认请输入1" << endl;
    char ch;
    cin >> ch;
    if(ch == '1')
    {
        cout << "正在删除道路" << endl;
        weight[i][j] = 0;
        weight[j][i] = 0;
        delay();
        cout << "道路删除成功" << endl;
    }
}



int main()
{
    init(); //初始化，存储相关数据
    char mode;
    int a = 1;
    while(a == 1)
    {
        printf(" ================================================================ \n");
        printf("||            欢迎来到南京理工大学紫金学院校园导航系统          ||\n");
        printf("||                                                              ||\n");
        printf("||                                                              ||\n");
        printf("||                  <1>游客登录                                 ||\n");
        printf("||                  <2>管理员登录                               ||\n");
        printf("||                  <3>退出系统                                 ||\n");
        printf("||                                                              ||\n");
        printf(" ================================================================ \n");
        printf("请输入您的指令:  ");
        cin >> mode;
        while(mode != '1' && mode != '2' && mode != '3')
        {
            cout << "输入有误，请重新输入！" << endl;
            cin >> mode;
        }
        //--------游客登录界面
        while(mode == '1')
        {
            system("cls");
            Visiter();
            exit(0);
        }
        while(mode == '2')
        {
            cout << "请输入账号：";
            string account;
            string  password;
            cin >> account;
            cout << "请输入密码：";
            cin >> password;
            while(account != "dxd" && password != "123456")
            {
                cout << "账号或密码错误！请重新输入" << endl;
                cout << "请输入账号：";
                cin >> account;
                cout << "请输入密码：";
                cin >> password;
            }
            cout << "\t\t\t登录成功......" << endl;
            delay();
            Administrator();
            exit(0);
            a=0;
        }
        while(mode == '3')
        {
            cout << "谢谢，再见！" << endl;
            a = 0;
            exit(0);
        }
    }
}

