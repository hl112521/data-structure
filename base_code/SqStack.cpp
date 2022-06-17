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
    SElemType GetTop();     // ��ȡջ��Ԫ��
    void Push(SElemType e); // ��ջ
    void Pop(SElemType &e); // ��ջ
    int EmptyStack();       // �ж�ջ�Ƿ�Ϊ��
    void PrintStack();      // ���ջ��Ԫ��
    void conversion(int n, int binary); // 10����ת��Ϊ��������
    int OtherToDe(string str, int binary); // ��������תʮ����
};

SqStack::SqStack()
{
    base = top = new SElemType[InitStackSize];
    stacksize = InitStackSize;
}
// ��ȡջ��Ԫ��
SElemType SqStack::GetTop()
{
    if (top == base)
    {
        cout << "ջ��, ջ����Ԫ��" << endl;
        exit(-1);
    }
    return *(top - 1);
}
// ��ջ
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
// ��ջ
void SqStack::Pop(SElemType &e)
{
    if (top == base)
        return;
    e = *--top;
}
// �ж�ջ�Ƿ�Ϊ��
int SqStack::EmptyStack()
{
    if (top == base) return 1;
    else return 0;
}
// ���ջ��Ԫ��
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
// 10����ת��Ϊ��������
void SqStack::conversion(int n, int binary)
{
    SqStack s;
    SElemType e;
    string hex;
    switch (binary)
    {
    case 2: hex= "��";
        break;
    case 8: hex = "��"; break;
    case 16: hex = "ʮ��";
    }
    cout<<"ת��Ϊ"<<hex<<"����: ";
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
// ��������תʮ����
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
    cout<<"---����ת����---"<<endl;
    cout<<"---1. ʮ����ת��������---"<<endl;
    cout<<"---2. ��������ת��Ϊʮ����---"<<endl;
    cout<<"---3. �������ת��---"<<endl;
    cout<<"---4. �˳�---"<<endl;
    cout<<"��������Ҫִ�еĲ���: ";
    cin>>n;
    while (n >0&& n<4)
    {
        if (n == 1)
        {
            cout<<"��������Ҫת����ʮ������: ";
            cin>>num;
            cout<<"��������Ҫת���Ľ�����: ";
            cin>>binary;
            sqStack.conversion(num, binary);
            cout<<"��������Ҫִ�еĲ���: ";
            cin>>n;
            continue;
        }
        else if (n == 2)
        {
            cout<<"��������Ҫת��������: ";
            cin>>str;
            cout<<"�����뵱ǰ���ƵĽ���: ";
            cin>>toBinary;
            num =sqStack.OtherToDe(str, toBinary);
            cout<<"ת��Ϊʮ������Ϊ: "<<num<<endl;
            cout<<"��������Ҫִ�еĲ���: ";
            cin>>n;
            continue;
        }
        else if (n == 3)
        {
            cout<<"�����뵱ǰ����: ";
            cin>>binary;
            cout<<"������Ҫת���Ľ���: ";
            cin>>toBinary;
            if (binary == 10)
            {
                cout<<"������Ҫת��������: ";
                cin>>num;
                sqStack.conversion(num, toBinary);
            }
            else
            {
                cout<<"������Ҫת��������: ";
                cin>>str;
                num = sqStack.OtherToDe(str, binary);
                sqStack.conversion(num, toBinary);
            }
            cout<<"��������Ҫִ�еĲ���: ";
            cin>>n;
            continue;
        }
        else if (n == 4)
        {
            exit(-1);
        }
        else
        {
            cout<<"�������, ��������"<<endl;
            cout<<"��������Ҫִ�еĲ���: ";
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
    // cout<<"��������Ҫת����ʮ������: ";
    // cin>>num;
    // cout<<"��������Ҫת���Ľ�����: ";
    // cin>>binary;
    // sqStack.conversion(num, binary);
    // cout<<"��������Ҫת����������: ";
    // cin>>str;
    // sqStack.OtherToDe(str);
    return 0;
}
