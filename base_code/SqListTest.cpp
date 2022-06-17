#include <iostream>
using namespace std;
#define Maxsize 15
 
typedef int DataType;
typedef struct{
    DataType data[Maxsize];   //����һά����
    int SqLength;    //���Ա���
}SqList;

//��ʼ��˳���
SqList *Init_SqList();
//����˳��������
void Define_SqList(SqList *L,int n);
//ȡ��˳����е�Ԫ��
void DisPlay_SqLIst(SqList *L);
//���Ԫ�ص�ָ����λ��
int InSert_SqList(SqList *L,int i,DataType x);
//ɾ��ָ��λ��Ԫ��
int Delete_SqList(SqList *L, int i);


//˳�򻯳�ʼ���㷨����ձ�
SqList *Init_SqList()
{
    SqList *L;
    L=new SqList;
    L->SqLength=0;  //��������Ϊ-1
    return L;
}

//��˳������Ԫ������
void Define_SqList(SqList *L,int n)
{
    cout<<"����������˳���Ҫ�洢��Ԫ��"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>L->data[i];    //��������Ԫ��
        L->SqLength++;
    }
}

//ȡ��˳���Ԫ������
void DisPlay_SqLIst(SqList *L)
{
    int i;
    for(i=0;i<=L->SqLength-1;i++)
    {
        cout<<L->data[i]<<" ";
    }
    cout<<endl;
}

//���Ԫ�ص�ĳ��λ��
int InSert_SqList(SqList *L,int i,DataType x)
{
    cout<<"��Ԫ��"<<x<<"λ����"<<endl;

    if (i < 1 || i > L->SqLength + 1) // �ж��Ƿ���
    {
        cout<<"����λ�ô���"<<endl;
        return 0;
    }

    if (L->SqLength == Maxsize-1)     //���鳤���趨Ϊ-1 ����
    {
        cout<<"����"<<endl;
        return -1;
    }
    for(int j = L-> SqLength - 1; j>=1; j--)  //i֮��ȫ��������
    {
        L->data[j+1]=L->data[j];
    }
    L->data[i-1] = x;                   //����
    L->SqLength++;
    cout<<"����ɹ�"<<endl;
    DisPlay_SqLIst(L);
    return 1;
}

//ɾ������
int Delete_SqList(SqList *L, int i)
{
    cout<<"��λ��"<<i<<"��Ԫ��ɾ��"<<endl;
    int j;
    if(i<1||i<L->SqLength-1)
    {
        cout<<"�����ڵ�"<<i<<"��Ԫ��"<<endl;
        return 0;
    }
    for(j=i;j<L->SqLength-1;j++)
    {
        L->data[j]=L->SqLength-1;
    }
    L->SqLength--;
    cout<<"ɾ���ɹ�"<<endl;
    DisPlay_SqLIst(L);
    return 1;
}
int main()
{
    SqList *L;  //˳�����
    L=Init_SqList();  //˳����ʼ��
    Define_SqList(L,6); //����˳���
    DisPlay_SqLIst(L);  //˳�������
    InSert_SqList(L,4,3); //˳���Ĳ���
    Delete_SqList(L,5);  //˳���ɾ��
    return 0;
}