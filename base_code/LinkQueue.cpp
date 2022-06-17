#include <iostream>
using namespace std;

typedef int QElemType;
typedef struct QNode
{
    QElemType data;
    QNode *next;
} QNode;
typedef struct
{
    QNode *front;
    QNode *rear;
} LinkQNode;

class LinkQueue
{
private:
    LinkQNode q;

public:
    LinkQueue();
    ~LinkQueue();
    QElemType GetHead();
    void EnQueue(QElemType e);
    void DeQueue(QElemType &e);
    int EmptyQueue();
    int QueueLength();
    void ArriveRoom(); // ��������
    void Patient(QElemType &patientNum); // ȡ����һλ���˵Ĳ���, �ò��˽������Ҿ���
    void LineUp(QElemType patientNum); // �Ŷ�, ���벡�˶���
    void SeeADoctor(); // ����
    void PrintPatient(); // �鿴����, ��������ŶӵĲ�����
    void NoLineUp(); // �����Ŷ�
    void OffClinic(); // ����
};

LinkQueue::LinkQueue()
{
    q.front = q.rear = new QNode;
    q.front->next = NULL;
}

LinkQueue::~LinkQueue()
{
    QNode *p  = q.front->next;
    while(p)
    {
        q.front->next = p->next;
        delete p;
        p = q.front->next;
    }
    delete q.front;
}
QElemType LinkQueue::GetHead() 
{
    if (q.front == q.rear)
    {
        cout<<"����Ϊ��, �޶�ͷԪ��";
        exit(-1);
    }
    return q.front->next->data;
    
}
void LinkQueue::EnQueue(QElemType e) 
{
    QNode *s = new QNode;
    s->data = e;
    s->next = NULL;
    q.rear->next = s;
    q.rear = s;
}
void LinkQueue::DeQueue(QElemType &e) 
{
    if (q.rear == q.front) return;
    QNode *p = q.front->next;
    q.front->next = p->next;
    e = p->data;
    if (p == q.rear)
        q.rear = q.front;
    delete p;    
}
int LinkQueue::EmptyQueue() 
{
    if (q.front == q.rear) return 1;
    else return 0;
    
}
int LinkQueue::QueueLength() 
{
    QNode *p = q.front->next;
    int count = 0;
    while(p) 
    {
        count++;
        p = p->next;
    }
    return count;
}
// ��������
void LinkQueue::ArriveRoom(){
    int num;
    cout<<"�����벡����: ";
    cin>>num;
    EnQueue(num);
    cout<<"��"<< QueueLength() << "�����˽�����������ʿ, �����ŶӺ���"<<endl;
}
// ȡ����һλ���˵Ĳ���, �ò��˽������Ҿ���
void LinkQueue::Patient(QElemType &patientNum)
{
    DeQueue(patientNum);
    cout<<"�벡����Ϊ: "<<patientNum<<"�Ĳ��˽������Ҿ���"<<endl;
    // cout<<"��ǰ����:"<<QueueLength()<<"���������ں���"<<endl;
} 
// �Ŷ�, ���벡�˶���
void LinkQueue::LineUp(QElemType patientNum)
{
    EnQueue(patientNum);
    cout<<"������: "<<patientNum<<"�Ѽ���������"<<endl;
    // cout<<"ǰ�滹��"<<QueueLength() << "������׼������"<<endl;
}
// ����
void LinkQueue::SeeADoctor()
{
    QElemType patientNum;
    DeQueue(patientNum);
    cout<<"������: "<<patientNum<<", ���ھ���"<<endl;
}
// �鿴����, ��������ŶӵĲ�����
void LinkQueue::PrintPatient()
{
    QNode *p = q.front->next;           //��ͷ��ʼ����  
    if (q.front == q.rear)
    {   
        cout<<"��ǰû�в����Ŷ�"<<endl;
        return;
    }
    else 
    {
        cout<<"��ǰ�����Ŷӵľ��ﲡ��Ϊ: ";
        while(p)     //���û�е���rearλ�ã���ѭ��  
        {  
            cout<<p->data<<"  ";
            p = p->next;
        }
        cout<<endl;
    }
}
// �����Ŷ�
void LinkQueue::NoLineUp()
{
    if (EmptyQueue())
    {
        cout<<"��ǰû�в����Ŷ�"<<endl;
        exit(-1);
    }
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
void LinkQueue::OffClinic()
{
    cout<<"��������!!"<<endl;
    exit(-1);
} 
void menu()
{
    cout<<"---��ӭ����xxҽԺ---"<<endl;
    cout<<"---1. �Ŷ�      ---"<<endl;
    cout<<"---2. ����      ---"<<endl;
    cout<<"---3. �鿴����  ---"<<endl;
    cout<<"---4. �����Ŷ�  ---"<<endl;
    cout<<"---5. �°�      ---"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"��ѡ�����Ĳ���: ";
}

int main()
{
    int operation; // ����
    LinkQueue s; // ׼���������
    LinkQueue l; // �������
    QElemType patientNumber;
    menu();
    while(true)
    {
        cin>>operation;
        switch (operation)
        {
        case 1:
            s.ArriveRoom();
            menu();
            break;
        case 2:
            // s.DeQueue(patientNumber);
            s.SeeADoctor();
            // l.LineUp(patientNumber);
            menu();
            break;
        case 3:
            s.PrintPatient();
            menu();
            break;
        case 4:
            s.NoLineUp();
            menu();
            break;
        case 5:
            s.OffClinic();
            break;
        default:
            cout<<"�������, ����������: ";
            break;
        }
    }
    return 0;  
}