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
    SElemType getTop(); // 获取栈顶元素
    void Push(SElemType e); // 元素 e 进栈
    void Pop(SElemType &e); // 栈顶元素出栈
    int EmptyStack();  // 判断栈链是否为空
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
    delete p; // 删除最后一个结点
}
// 获取栈顶元素
SElemType LinkStack::getTop()
{
    if (top->next == NULL)
    {
        cout<<"栈空, 无法获取栈顶元素"<<endl;
        exit(-1);
    }
    return top->next->data;
}
// 元素 e 进栈
void LinkStack::Push(SElemType e)
{
    LinkNode *s = new LinkNode;
    s->data = e;
    s->next = top->next;
    top->next = s;
} 
// 栈顶元素出栈
void LinkStack::Pop(SElemType &e)
{
    if (top->next == NULL) return;
    LinkNode *p = top->next;
    e = p->data;
    top->next = p->next;
    delete p;
}
// 判断栈链是否为空
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
    cout<<"请输入5个入栈的元素: ";
    for(int i = 0; i < 5; i++)
    {
        SElemType e;
        cin>>e;
        l.Push(e);
    }
    cout<<"当前栈内元素为: ";
    while(!l.EmptyStack())
    {
        SElemType e;
        cout<<l.getTop()<<" ";
        l.Pop(e);
    }
    cout<<endl;
    return 0;
}

