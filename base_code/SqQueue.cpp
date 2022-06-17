#include <iostream>
using namespace std;
#define QueueSize 100
typedef int QElemType;

class SqQueue
{
private:
    QElemType *base; // ����ռ��׵�ַ
    int front, rear; // frontΪ��ͷָ��, rearΪ��βָ��
public:
    SqQueue(); // �����ն���
    ~SqQueue();
    QElemType GetHead(); // ��ȡ��ͷָ��
    void EnQueue(QElemType e); // Ԫ��e���
    void DeQueue(QElemType &e); // Ԫ��e���
    int EmptyQueue(); // �ж��Ƿ�Ϊ��
    int QueueLength(); // ��ǰ�����ж��ٸ�Ԫ��
    void ArriveRoom(int num); // ��������
    void Patient(QElemType &patientNum); // ȡ����һλ���˵Ĳ���, �ò��˽������Ҿ���
    void LineUp(QElemType patientNum); // �Ŷ�, ���벡�˶���
    void SeeADoctor(); // ����
    void PrintPatient(); // �鿴����, ��������ŶӵĲ�����
    void NoLineUp(); // �����Ŷ�
    void OffClinic(); // ����
};

SqQueue::SqQueue()
{
    base = new QElemType[QueueSize];
    front=rear=0;
}
// ��ȡ��ͷָ��
QElemType SqQueue::GetHead()
{
    if (front == rear)
    {
        cout<<"���п�, �޶�ͷԪ��";
        exit(-1);
    }
    return base[front];
}
// Ԫ��e���
void SqQueue::EnQueue(QElemType e)
{
    if (front == (rear + 1) % QueueSize) return; // ������
    base[rear] = e;
    rear = (rear + 1) % QueueSize;
}
// Ԫ��e���
void SqQueue::DeQueue(QElemType &e)
{
    if (front == rear) return;
    e = base[front];
    front = (front + 1) % QueueSize;
}
// �ж��Ƿ�Ϊ��
int SqQueue::EmptyQueue()
{
    if(front == rear)
        return 1;
    else
        return 0;
}
SqQueue::~SqQueue()
{
    delete []base;
    front=rear=0;
}
// ��ǰ�����ж��ٸ�Ԫ��
int SqQueue::QueueLength() 
{
    int i = front;           //��ͷ��ʼ����  
    int length = 0;
    if (front == rear) return length;
    else 
    {
        while(i != rear)     //���û�е���rearλ�ã���ѭ��  
        {  
            length++;
            i = (i+1) % QueueSize;              //�Ƶ���һλ��  
        }
        return length; 
    }
}
// ��������
void SqQueue::ArriveRoom(int num){
    for(int i = 0; i < num; i++)
    {
        EnQueue(1040 + i);
        cout<<"��"<< QueueLength() << "�����˽�����������ʿ, �����ŶӺ���"<<endl;
    }
}
// ȡ����һλ���˵Ĳ���, �ò��˽������Ҿ���
void SqQueue::Patient(QElemType &patientNum)
{
    DeQueue(patientNum);
    cout<<"�벡����Ϊ: "<<patientNum<<"�Ĳ��˽������Ҿ���"<<endl;
    // cout<<"��ǰ����:"<<QueueLength()<<"���������ں���"<<endl;
} 
// �Ŷ�, ���벡�˶���
void SqQueue::LineUp(QElemType patientNum)
{
    EnQueue(patientNum);
    cout<<"������: "<<patientNum<<"�Ѽ���������"<<endl;
    // cout<<"ǰ�滹��"<<QueueLength() << "������׼������"<<endl;
}
// ����
void SqQueue::SeeADoctor()
{
    QElemType patientNum;
    DeQueue(patientNum);
    cout<<"������: "<<patientNum<<", ���ھ���"<<endl;
    
}
// �鿴����, ��������ŶӵĲ�����
void SqQueue::PrintPatient()
{
    int i = front;           //��ͷ��ʼ����  
    if (front == rear) return;
    else 
    {
        while(i != rear)     //���û�е���rearλ�ã���ѭ��  
        {  
            cout<<base[i]<<"  ";
            i = (i+1) % QueueSize;              //�Ƶ���һλ��  
        }
        cout<<endl;
    }
}
// �����Ŷ�
void SqQueue::NoLineUp()
{
    QElemType num;
    cout<<"������: ";
    while(!EmptyQueue())
    {
        DeQueue(num);
        cout<<num<<" ";
    }
    cout<<"ȫ������"<<endl;
    exit(-1);
}
// ����
void SqQueue::OffClinic()
{
    cout<<"��������!!"<<endl;
    exit(-1);
} 

int main()
{
    cout<<"---------������-----------"<<endl;
    SqQueue s; // ׼���������
    SqQueue q; // �������
    s.ArriveRoom(5); // 5�����˵�������
    for(int i = 0; i < 3; i++) // ��3�����˽�������
    {
        QElemType patientNumber; // �����Ҿ���Ĳ�����
        s.Patient(patientNumber); // ��ʿ�����������Ҿ���
        cout<<"---------������-----------"<<endl;
        q.LineUp(patientNumber);
    }
    // cout<<"---------������-----------"<<endl;
    
    // q.LineUp(patientNumber);
    cout<<"�����ŶӵĲ�����Ϊ: ";
    q.PrintPatient();
    q.SeeADoctor();
    cout<<"ǰ�滹��"<<q.QueueLength() << "������׼������"<<endl;
    cout<<"�����ŶӵĲ�����Ϊ: ";
    q.PrintPatient();
    q.NoLineUp(); // �����ŶӺ�����ֻ����һ����������
    q.OffClinic();
    return 0;
}