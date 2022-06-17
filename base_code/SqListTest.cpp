#include <iostream>
using namespace std;
#define Maxsize 15
 
typedef int DataType;
typedef struct{
    DataType data[Maxsize];   //建立一维数组
    int SqLength;    //线性表长度
}SqList;

//初始化顺序表
SqList *Init_SqList();
//插入顺序表的内容
void Define_SqList(SqList *L,int n);
//取出顺序表中的元素
void DisPlay_SqLIst(SqList *L);
//添加元素到指定的位置
int InSert_SqList(SqList *L,int i,DataType x);
//删除指定位置元素
int Delete_SqList(SqList *L, int i);


//顺序化初始化算法并清空表
SqList *Init_SqList()
{
    SqList *L;
    L=new SqList;
    L->SqLength=0;  //长度设置为-1
    return L;
}

//给顺序表插入元素内容
void Define_SqList(SqList *L,int n)
{
    cout<<"请依次输入顺序表要存储的元素"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>L->data[i];    //输入数组元素
        L->SqLength++;
    }
}

//取出顺序表元素内容
void DisPlay_SqLIst(SqList *L)
{
    int i;
    for(i=0;i<=L->SqLength-1;i++)
    {
        cout<<L->data[i]<<" ";
    }
    cout<<endl;
}

//添加元素到某个位置
int InSert_SqList(SqList *L,int i,DataType x)
{
    cout<<"把元素"<<x<<"位置上"<<endl;

    if (i < 1 || i > L->SqLength + 1) // 判断是否插错
    {
        cout<<"插入位置错误"<<endl;
        return 0;
    }

    if (L->SqLength == Maxsize-1)     //数组长度设定为-1 表满
    {
        cout<<"表满"<<endl;
        return -1;
    }
    for(int j = L-> SqLength - 1; j>=1; j--)  //i之后全部往后移
    {
        L->data[j+1]=L->data[j];
    }
    L->data[i-1] = x;                   //插入
    L->SqLength++;
    cout<<"插入成功"<<endl;
    DisPlay_SqLIst(L);
    return 1;
}

//删除操作
int Delete_SqList(SqList *L, int i)
{
    cout<<"将位置"<<i<<"的元素删除"<<endl;
    int j;
    if(i<1||i<L->SqLength-1)
    {
        cout<<"不存在第"<<i<<"个元素"<<endl;
        return 0;
    }
    for(j=i;j<L->SqLength-1;j++)
    {
        L->data[j]=L->SqLength-1;
    }
    L->SqLength--;
    cout<<"删除成功"<<endl;
    DisPlay_SqLIst(L);
    return 1;
}
int main()
{
    SqList *L;  //顺序表定义
    L=Init_SqList();  //顺序表初始化
    Define_SqList(L,6); //定义顺序表
    DisPlay_SqLIst(L);  //顺序表的输出
    InSert_SqList(L,4,3); //顺序表的插入
    Delete_SqList(L,5);  //顺序表删除
    return 0;
}