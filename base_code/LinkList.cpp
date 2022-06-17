#include <iostream>
using namespace std;
typedef int ElemType; // �Զ����������� ElemType
typedef struct LNode // ����������͵Ľṹ��
{
    ElemType data;
    LNode *next;
} LNode;
class LinkList
{
private:
    LNode *head; // ͷ���

public:
    LinkList();                           // ����ͷ���
    void CreateList_h(int n);             // ͷ�巨-���δӼ��̶������ݣ�������ͷ���ĵ�����
    void DisplayLinkList();               // ����������е�����Ԫ��
    int ListLength();                     // ������ĳ���
    void InsertList(int pos, ElemType e); // ʵ����ָ��λ�ò���Ԫ��
    void DeleteList(int pos, ElemType &e); // ʵ����ָ��λ��ɾ��Ԫ�صĹ��ܡ�
    int GetElem(int pos, ElemType &e);// ����ָ�������ܹ�ȡԪ��
    void UpdateElem(int pos, ElemType e); //����ָ�������ܹ��޸�Ԫ��
    ~LinkList();
};

LinkList::LinkList()
{
    head = new LNode;
    head->next = NULL;
}
// ͷ�巨-���δӼ��̶������ݣ�������ͷ���ĵ�����
/* void LinkList::CreateList_h(int n)
{
    LNode *s;
    cout << "������" << n << "������ֵ: ";
    for (int i = 0; i < n; i++)
    {
        s = new LNode;
        cin >> s->data; 
        s->next = head->next;
        head->next = s;
    }
} */
// β�巨-���δӼ��̶������ݣ�������ͷ���ĵ�����
void LinkList::CreateList_h(int n)
{
    LNode *rear=head, *s;
    cout << "������" << n << "������ֵ: ";
    for (int i = 0; i < n; i++)
    {
        s = new LNode;
        cin >> s->data; 
        rear->next = s;
        rear = s;
    }
    s->next = NULL;
}
// ����������е�����Ԫ��
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
// ������ĳ���
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
// ʵ����ָ��λ�ò���Ԫ��
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
// ʵ����ָ��λ��ɾ��Ԫ�صĹ��ܡ�
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
// ����ָ�������ܹ�ȡԪ��
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
//����ָ�������ܹ��޸�Ԫ��
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
    cout << "��ǰ�����������Ԫ��Ϊ: ";
    L.DisplayLinkList();
    cout << "��ǰ������ĳ���Ϊ: " << L.ListLength() << endl;
    L.InsertList(2, 10);
    cout << "����֮�����������Ԫ��Ϊ: ";
    L.DisplayLinkList();
    ElemType e;
    L.DeleteList(1, e);
    cout<<"ɾ����Ԫ��Ϊ: "<<e<<endl;
    cout << "ɾ��֮�����������Ԫ��Ϊ: ";
    L.DisplayLinkList();
    ElemType e1;
    if(L.GetElem(4, e1) == 0)
        cout<<"û���ҵ�!"<<endl;
    else
        cout<<"���ҵ�Ԫ��Ϊ: "<<e1<<endl;
    cout << "�޸ĵ�����֮ǰ������Ԫ��Ϊ: ";
    L.DisplayLinkList();
    L.UpdateElem(2, 18);
    cout << "�޸ĵ�����֮�������Ԫ��Ϊ: ";
    L.DisplayLinkList();
    return 0;
}
