#include <iostream>
using namespace std;
typedef int ElemType; // 自定义数据类型 ElemType
typedef struct LNode // 创建结点类型的结构体
{
    ElemType data;
    LNode *next;
} LNode;
class LinkList
{
private:
    LNode *head; // 头结点

public:
    LinkList();                           // 创建头结点
    void CreateList_h(int n);             // 头插法-依次从键盘读入数据，建立带头结点的单链表
    void DisplayLinkList();               // 输出单链表中的数据元素
    int ListLength();                     // 求单链表的长度
    void InsertList(int pos, ElemType e); // 实现在指定位置插入元素
    void DeleteList(int pos, ElemType &e); // 实现在指定位置删除元素的功能。
    int GetElem(int pos, ElemType &e);// 根据指定条件能够取元素
    void UpdateElem(int pos, ElemType e); //根据指定条件能够修改元素
    ~LinkList();
};

LinkList::LinkList()
{
    head = new LNode;
    head->next = NULL;
}
// 头插法-依次从键盘读入数据，建立带头结点的单链表
/* void LinkList::CreateList_h(int n)
{
    LNode *s;
    cout << "请输入" << n << "个结点的值: ";
    for (int i = 0; i < n; i++)
    {
        s = new LNode;
        cin >> s->data; 
        s->next = head->next;
        head->next = s;
    }
} */
// 尾插法-依次从键盘读入数据，建立带头结点的单链表
void LinkList::CreateList_h(int n)
{
    LNode *rear=head, *s;
    cout << "请输入" << n << "个结点的值: ";
    for (int i = 0; i < n; i++)
    {
        s = new LNode;
        cin >> s->data; 
        rear->next = s;
        rear = s;
    }
    s->next = NULL;
}
// 输出单链表中的数据元素
void LinkList::DisplayLinkList()
{
    LNode *p = head->next;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
// 求单链表的长度
int LinkList::ListLength()
{
    LNode *p = head->next;
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}
// 实现在指定位置插入元素
void LinkList::InsertList(int pos, ElemType e)
{
    LNode *p = head, *s;
    int j = 0;
    while (p->next && j < pos - 1)
    {
        p = p->next;
        j++;
    }
    if (!p || j > pos - 1)
        return;
    else
    {
        s = new LNode;
        s->data = e;
        s->next = p->next;
        p->next = s;
    }
}
// 实现在指定位置删除元素的功能。
void LinkList::DeleteList(int pos, ElemType &e){
    LNode *p = head, *q;
    int j = 0;
    while (p->next && j < pos-1)
    {
        p = p->next;
        j++;
    }
    if (!p || j > pos-1)
        return;
    else
    {
        q = p->next;
        e = q->data;
        p->next = q->next;
        delete q;
    }
}
// 根据指定条件能够取元素
int LinkList::GetElem(int pos, ElemType &e)
{
    int j = 0;
    LNode *p = head;
    while (j<pos && p)
    {
        p = p->next;
        j++;
    }
    if (j>pos || !p)
        return 0;
    else
    {
        e = p->data;
        return 1;
    }
}
//根据指定条件能够修改元素
void LinkList::UpdateElem(int pos, ElemType e)
{
    int j = 0;
    LNode *p = head;
    while (j<pos && p)
    {
        p = p->next;
        j++;
    }
    if (j>pos || !p)
        return;
    else
    {
        p->data = e;
    }
} 
LinkList::~LinkList()
{
    LNode *p = head;
    while (p)
    {
        head = head->next;
        delete p;
        p = head;
    }
    
}

int main()
{
    LinkList L;
    L.CreateList_h(5);
    cout << "当前单链表的数据元素为: ";
    L.DisplayLinkList();
    cout << "当前单链表的长度为: " << L.ListLength() << endl;
    L.InsertList(2, 10);
    cout << "插入之后单链表的数据元素为: ";
    L.DisplayLinkList();
    ElemType e;
    L.DeleteList(1, e);
    cout<<"删除的元素为: "<<e<<endl;
    cout << "删除之后单链表的数据元素为: ";
    L.DisplayLinkList();
    ElemType e1;
    if(L.GetElem(4, e1) == 0)
        cout<<"没有找到!"<<endl;
    else
        cout<<"查找的元素为: "<<e1<<endl;
    cout << "修改单链表之前的数据元素为: ";
    L.DisplayLinkList();
    L.UpdateElem(2, 18);
    cout << "修改单链表之后的数据元素为: ";
    L.DisplayLinkList();
    return 0;
}
