#include <iostream>
using namespace std;
#define QueueSize 100
typedef int QElemType;

class SqQueue
{
private:
    QElemType *base; // 储存空间首地址
    int front, rear; // front为队头指针, rear为队尾指针
public:
    SqQueue(); // 建立空队列
    ~SqQueue();
    QElemType GetHead(); // 读取队头指针
    void EnQueue(QElemType e); // 元素e入队
    void DeQueue(QElemType &e); // 元素e离队
    int EmptyQueue(); // 判断是否为空
    int QueueLength(); // 当前队列有多少个元素
    void ArriveRoom(int num); // 到达诊室
    void Patient(QElemType &patientNum); // 取出下一位病人的病历, 该病人进入诊室就诊
    void LineUp(QElemType patientNum); // 排队, 进入病人队列
    void SeeADoctor(); // 就诊
    void PrintPatient(); // 查看队列, 输出就诊排队的病历号
    void NoLineUp(); // 不再排队
    void OffClinic(); // 休诊
};

SqQueue::SqQueue()
{
    base = new QElemType[QueueSize];
    front=rear=0;
}
// 读取队头指针
QElemType SqQueue::GetHead()
{
    if (front == rear)
    {
        cout<<"队列空, 无队头元素";
        exit(-1);
    }
    return base[front];
}
// 元素e入队
void SqQueue::EnQueue(QElemType e)
{
    if (front == (rear + 1) % QueueSize) return; // 队列满
    base[rear] = e;
    rear = (rear + 1) % QueueSize;
}
// 元素e离队
void SqQueue::DeQueue(QElemType &e)
{
    if (front == rear) return;
    e = base[front];
    front = (front + 1) % QueueSize;
}
// 判断是否为空
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
// 当前队列有多少个元素
int SqQueue::QueueLength() 
{
    int i = front;           //从头开始遍历  
    int length = 0;
    if (front == rear) return length;
    else 
    {
        while(i != rear)     //如果没有到达rear位置，就循环  
        {  
            length++;
            i = (i+1) % QueueSize;              //移到下一位置  
        }
        return length; 
    }
}
// 到达诊室
void SqQueue::ArriveRoom(int num){
    for(int i = 0; i < num; i++)
    {
        EnQueue(1040 + i);
        cout<<"第"<< QueueLength() << "个病人将病历交给护士, 正在排队候诊"<<endl;
    }
}
// 取出下一位病人的病历, 该病人进入诊室就诊
void SqQueue::Patient(QElemType &patientNum)
{
    DeQueue(patientNum);
    cout<<"请病历号为: "<<patientNum<<"的病人进入诊室就诊"<<endl;
    // cout<<"当前还有:"<<QueueLength()<<"个病人正在候诊"<<endl;
} 
// 排队, 进入病人队列
void SqQueue::LineUp(QElemType patientNum)
{
    EnQueue(patientNum);
    cout<<"病历号: "<<patientNum<<"已加入就诊队列"<<endl;
    // cout<<"前面还有"<<QueueLength() << "个病人准备就诊"<<endl;
}
// 就诊
void SqQueue::SeeADoctor()
{
    QElemType patientNum;
    DeQueue(patientNum);
    cout<<"病历号: "<<patientNum<<", 正在就诊"<<endl;
    
}
// 查看队列, 输出就诊排队的病历号
void SqQueue::PrintPatient()
{
    int i = front;           //从头开始遍历  
    if (front == rear) return;
    else 
    {
        while(i != rear)     //如果没有到达rear位置，就循环  
        {  
            cout<<base[i]<<"  ";
            i = (i+1) % QueueSize;              //移到下一位置  
        }
        cout<<endl;
    }
}
// 不再排队
void SqQueue::NoLineUp()
{
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
void SqQueue::OffClinic()
{
    cout<<"诊室休诊!!"<<endl;
    exit(-1);
} 

int main()
{
    cout<<"---------候诊室-----------"<<endl;
    SqQueue s; // 准备就诊队列
    SqQueue q; // 就诊队列
    s.ArriveRoom(5); // 5个病人到达诊室
    for(int i = 0; i < 3; i++) // 喊3个病人进入诊室
    {
        QElemType patientNumber; // 入诊室就诊的病历号
        s.Patient(patientNumber); // 护士喊病人入诊室就诊
        cout<<"---------就诊室-----------"<<endl;
        q.LineUp(patientNumber);
    }
    // cout<<"---------就诊室-----------"<<endl;
    
    // q.LineUp(patientNumber);
    cout<<"正在排队的病历号为: ";
    q.PrintPatient();
    q.SeeADoctor();
    cout<<"前面还有"<<q.QueueLength() << "个病人准备就诊"<<endl;
    cout<<"正在排队的病历号为: ";
    q.PrintPatient();
    q.NoLineUp(); // 不再排队和休诊只能有一个可以运行
    q.OffClinic();
    return 0;
}