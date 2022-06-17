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
    void ArriveRoom(); // 到达诊室
    void Patient(QElemType &patientNum); // 取出下一位病人的病历, 该病人进入诊室就诊
    void LineUp(QElemType patientNum); // 排队, 进入病人队列
    void SeeADoctor(); // 就诊
    void PrintPatient(); // 查看队列, 输出就诊排队的病历号
    void NoLineUp(); // 不再排队
    void OffClinic(); // 休诊
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
        cout<<"队列为空, 无队头元素";
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
// 到达诊室
void LinkQueue::ArriveRoom(){
    int num;
    cout<<"请输入病历号: ";
    cin>>num;
    EnQueue(num);
    cout<<"第"<< QueueLength() << "个病人将病历交给护士, 正在排队候诊"<<endl;
}
// 取出下一位病人的病历, 该病人进入诊室就诊
void LinkQueue::Patient(QElemType &patientNum)
{
    DeQueue(patientNum);
    cout<<"请病历号为: "<<patientNum<<"的病人进入诊室就诊"<<endl;
    // cout<<"当前还有:"<<QueueLength()<<"个病人正在候诊"<<endl;
} 
// 排队, 进入病人队列
void LinkQueue::LineUp(QElemType patientNum)
{
    EnQueue(patientNum);
    cout<<"病历号: "<<patientNum<<"已加入就诊队列"<<endl;
    // cout<<"前面还有"<<QueueLength() << "个病人准备就诊"<<endl;
}
// 就诊
void LinkQueue::SeeADoctor()
{
    QElemType patientNum;
    DeQueue(patientNum);
    cout<<"病历号: "<<patientNum<<", 正在就诊"<<endl;
}
// 查看队列, 输出就诊排队的病历号
void LinkQueue::PrintPatient()
{
    QNode *p = q.front->next;           //从头开始遍历  
    if (q.front == q.rear)
    {   
        cout<<"当前没有病人排队"<<endl;
        return;
    }
    else 
    {
        cout<<"当前正在排队的就诊病人为: ";
        while(p)     //如果没有到达rear位置，就循环  
        {  
            cout<<p->data<<"  ";
            p = p->next;
        }
        cout<<endl;
    }
}
// 不再排队
void LinkQueue::NoLineUp()
{
    if (EmptyQueue())
    {
        cout<<"当前没有病人排队"<<endl;
        exit(-1);
    }
    QElemType num;
    cout<<"病历号: ";
    while(!EmptyQueue())
    {
        DeQueue(num);
        cout<<num<<" ";
    }
    cout<<"全部就诊"<<endl;
    exit(-1);
}
// 休诊
void LinkQueue::OffClinic()
{
    cout<<"诊室休诊!!"<<endl;
    exit(-1);
} 
void menu()
{
    cout<<"---欢迎来到xx医院---"<<endl;
    cout<<"---1. 排队      ---"<<endl;
    cout<<"---2. 就诊      ---"<<endl;
    cout<<"---3. 查看队列  ---"<<endl;
    cout<<"---4. 不再排队  ---"<<endl;
    cout<<"---5. 下班      ---"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"请选择您的操作: ";
}

int main()
{
    int operation; // 操作
    LinkQueue s; // 准备就诊队列
    LinkQueue l; // 就诊队列
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
            cout<<"输入出错, 请重新输入: ";
            break;
        }
    }
    return 0;  
}