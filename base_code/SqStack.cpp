#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#define InitStackSize 100
#define StackIncrement 10
typedef int SElemType;
class SqStack
{
private:
    SElemType *base, *top;
    int stacksize;
    char hexNum [16]= {'0', '1', '2', '3', '4',
                        '5', '6', '7', '8', '9',
                        'A', 'B', 'C', 'D', 'E', 'F'};
public:
    SqStack();
    ~SqStack();
    SElemType GetTop();     // 获取栈顶元素
    void Push(SElemType e); // 进栈
    void Pop(SElemType &e); // 出栈
    int EmptyStack();       // 判断栈是否为空
    void PrintStack();      // 输出栈中元素
    void conversion(int n, int binary); // 10进制转换为其他进制
    int OtherToDe(string str, int binary); // 其他进制转十进制
};

SqStack::SqStack()
{
    base = top = new SElemType[InitStackSize];
    stacksize = InitStackSize;
}
// 获取栈顶元素
SElemType SqStack::GetTop()
{
    if (top == base)
    {
        cout << "栈空, 栈顶无元素" << endl;
        exit(-1);
    }
    return *(top - 1);
}
// 进栈
void SqStack::Push(SElemType e)
{
    if (top - base == stacksize)
    {
        SElemType *base1 = new SElemType[stacksize + StackIncrement];
        for (int i = 0; i < stacksize; i++)
        {
            base1[i] = base[i];
        }
        delete[] base;
        base = base1;
        top = base + stacksize;
        stacksize += StackIncrement;
    }
    *top++ = e;
}
// 出栈
void SqStack::Pop(SElemType &e)
{
    if (top == base)
        return;
    e = *--top;
}
// 判断栈是否为空
int SqStack::EmptyStack()
{
    if (top == base) return 1;
    else return 0;
}
// 输出栈中元素
void SqStack::PrintStack()
{
    SElemType *p = base;
    while (p != top)
    {
        cout<<*p<<" ";
        p++;
    }
    cout<<endl;
}
// 10进制转换为其他进制
void SqStack::conversion(int n, int binary)
{
    SqStack s;
    SElemType e;
    string hex;
    switch (binary)
    {
    case 2: hex= "二";
        break;
    case 8: hex = "八"; break;
    case 16: hex = "十六";
    }
    cout<<"转换为"<<hex<<"进制: ";
    while(n)
    {
        s.Push(n % binary);
        n = n / binary;
    }
    while(!s.EmptyStack())
    {
        s.Pop(e);
        cout<<hexNum[e];
    }
    cout<<endl;
}
// 其他进制转十进制
int SqStack::OtherToDe(string str, int binary)
{
    SqStack s;
    SElemType e;
    int num=0, n;
    for (int i = str.length()-1; i >= 0; i--)
    {
        switch (str[i])
        {
        case 'A': n = 10; break;  
        case 'B': n = 11; break;  
        case 'C': n = 12; break;  
        case 'D': n = 13; break;  
        case 'E': n = 14; break;  
        case 'F': n = 15; break;  
        default: n = str[i]-'0'; break; 
        }
        s.Push(n);
    }
    for (int i = str.length(); !s.EmptyStack(); i--)
    {
        s.Pop(e);
        num += e * pow(binary,i-1);
    }
    return num;
}
SqStack::~SqStack()
{
    delete[] base;
    stacksize = 0;
}
void menu()
{
    system("cls");
    int n;
    SqStack sqStack;
    int num, binary, toBinary;
    string str;
    cout<<"---进制转换器---"<<endl;
    cout<<"---1. 十进制转其他进制---"<<endl;
    cout<<"---2. 其他进制转换为十进制---"<<endl;
    cout<<"---3. 任意进制转换---"<<endl;
    cout<<"---4. 退出---"<<endl;
    cout<<"请输入你要执行的操作: ";
    cin>>n;
    while (n >0&& n<4)
    {
        if (n == 1)
        {
            cout<<"请输入需要转换的十进制数: ";
            cin>>num;
            cout<<"请输入需要转换的进制数: ";
            cin>>binary;
            sqStack.conversion(num, binary);
            cout<<"请输入你要执行的操作: ";
            cin>>n;
            continue;
        }
        else if (n == 2)
        {
            cout<<"请输入需要转换的数据: ";
            cin>>str;
            cout<<"请输入当前进制的进制: ";
            cin>>toBinary;
            num =sqStack.OtherToDe(str, toBinary);
            cout<<"转换为十进制数为: "<<num<<endl;
            cout<<"请输入你要执行的操作: ";
            cin>>n;
            continue;
        }
        else if (n == 3)
        {
            cout<<"请输入当前进制: ";
            cin>>binary;
            cout<<"请输入要转换的进制: ";
            cin>>toBinary;
            if (binary == 10)
            {
                cout<<"请输入要转换的数据: ";
                cin>>num;
                sqStack.conversion(num, toBinary);
            }
            else
            {
                cout<<"请输入要转换的数据: ";
                cin>>str;
                num = sqStack.OtherToDe(str, binary);
                sqStack.conversion(num, toBinary);
            }
            cout<<"请输入你要执行的操作: ";
            cin>>n;
            continue;
        }
        else if (n == 4)
        {
            exit(-1);
        }
        else
        {
            cout<<"输入出错, 重新输入"<<endl;
            cout<<"请输入你要执行的操作: ";
            cin>>n;
        }
    }
}
int main()
{
    menu();
    // SqStack sqStack;
    // int num, binary;
    // string str;
    // cout<<"请输入需要转换的十进制数: ";
    // cin>>num;
    // cout<<"请输入需要转换的进制数: ";
    // cin>>binary;
    // sqStack.conversion(num, binary);
    // cout<<"请输入需要转换的其他数: ";
    // cin>>str;
    // sqStack.OtherToDe(str);
    return 0;
}
