#include <iostream>
using namespace std;
typedef int SElemType;
typedef struct LinkNode
{
    SElemType data;
    LinkNode *next;
}LinkNode;
class LinkStack
{
private:
    LinkNode *top;
public:
    LinkStack();
    ~LinkStack();
    SElemType getTop(); // ��ȡջ��Ԫ��
    void Push(SElemType e); // Ԫ�� e ��ջ
    void Pop(SElemType &e); // ջ��Ԫ�س�ջ
    int EmptyStack();  // �ж�ջ���Ƿ�Ϊ��
};

LinkStack::LinkStack()
{
    top = new LinkNode;
    top->next = NULL;
}

LinkStack::~LinkStack()
{
    LinkNode *p = top, *q = top->next;
    while(q)
    {
        delete p;
        p = q;
        q = q->next;
    }
    delete p; // ɾ�����һ�����
}
// ��ȡջ��Ԫ��
SElemType LinkStack::getTop()
{
    if (top->next == NULL)
    {
        cout<<"ջ��, �޷���ȡջ��Ԫ��"<<endl;
        exit(-1);
    }
    return top->next->data;
}
// Ԫ�� e ��ջ
void LinkStack::Push(SElemType e)
{
    LinkNode *s = new LinkNode;
    s->data = e;
    s->next = top->next;
    top->next = s;
} 
// ջ��Ԫ�س�ջ
void LinkStack::Pop(SElemType &e)
{
    if (top->next == NULL) return;
    LinkNode *p = top->next;
    e = p->data;
    top->next = p->next;
    delete p;
}
// �ж�ջ���Ƿ�Ϊ��
int LinkStack::EmptyStack()
{
    if (top->next == NULL)
        return 1;
    else
        return 0;
}

int main()
{
    LinkStack l;
    cout<<"������5����ջ��Ԫ��: ";
    for(int i = 0; i < 5; i++)
    {
        SElemType e;
        cin>>e;
        l.Push(e);
    }
    cout<<"��ǰջ��Ԫ��Ϊ: ";
    while(!l.EmptyStack())
    {
        SElemType e;
        cout<<l.getTop()<<" ";
        l.Pop(e);
    }
    cout<<endl;
    return 0;
}

