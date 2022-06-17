#include <iostream>
#include <queue>
using namespace std;
typedef struct BiTNode
{
    char data;
    BiTNode *lchild;
    BiTNode *rchild;
} BiTNode;
class BiTree
{
private:
    BiTNode *bt;
    void Rcreate(BiTNode *&t);          //�ݹ鴴��������
    void PreTraverse(BiTNode *t);       //��������ݹ麯��
    void InTraverse(BiTNode *t);        //��������ݹ麯��
    void PostTraverse(BiTNode *t);      //��������ݹ麯��
    void gradationTraverse(BiTNode *t); //��α����ݹ麯��
public:
    BiTree() { bt = NULL; };
    void CreateBTNode(BiTNode *&b, char *str);
    void RcreateBitree();     //����������
    void PreTraverse();       //�������������
    void InTraverse();        //�������������
    void PostTraverse();      //�������������
    void gradationTraverse(); //��α���������
};
void BiTree::Rcreate(BiTNode *&t)
{
    char ch;
    cin >> ch;
    if (ch == '.')
        t = NULL;
    else
    {
        t = new BiTNode;
        t->data = ch;
        Rcreate(t->lchild);
        Rcreate(t->rchild);
    }
}
void BiTree::RcreateBitree()
{
    BiTNode *t;
    Rcreate(t);
    bt = t;
}
void BiTree::PreTraverse(BiTNode *t)
{
    if (t)
    {
        cout << t->data;
        PreTraverse(t->lchild);
        PreTraverse(t->rchild);
    }
}
void BiTree::PreTraverse()
{
    BiTNode *p = bt;
    PreTraverse(p);
}
void BiTree::InTraverse(BiTNode *t)
{
    if (t)
    {
        InTraverse(t->lchild);
        cout << t->data;
        InTraverse(t->rchild);
    }
}
void BiTree::InTraverse()
{
    BiTNode *p = bt;
    InTraverse(p);
}
void BiTree::PostTraverse(BiTNode *t)
{
    if (t)
    {
        PostTraverse(t->lchild);
        PostTraverse(t->rchild);
        cout << t->data;
    }
}
void BiTree::PostTraverse()
{
    BiTNode *p = bt;
    PostTraverse(p);
}
void BiTree::gradationTraverse(BiTNode *t)
{
    BiTNode *p = t;
    queue<BiTNode *> sq;
    sq.push(p);
    while (!sq.empty())
    {
        p = sq.front();
        sq.pop();
        cout << p->data;
        if (p->lchild != NULL)
            sq.push(p->lchild); //�������
        if (p->rchild != NULL)
            sq.push(p->rchild); //�Һ������
    }
}
void BiTree::gradationTraverse()
{
    BiTNode *p = bt;
    gradationTraverse(p);
}
void BiTree::CreateBTNode(BiTNode *&b, char *str)
{
    BiTNode *St[100], *p = NULL;
    int top = -1, k, j = 0;
    char ch;
    b = NULL; /*�����Ķ�������ʼʱΪ��*/
    ch = str[j];
    while (ch != '\0') /*strδɨ����ʱѭ��*/
    {
        switch (ch)
        {
        case '(':
            top++;
            St[top] = p;
            k = 1;
            break;
            /*Ϊ���ӽ��*/
        case ')':
            top--;
            break;
        case ',':
            k = 2;
            break;
        /*Ϊ���ӽ���ҽ��*/
        default:
            p = new BiTNode;
            p->data = ch;
            p->lchild = p->rchild = NULL;
            if (b == NULL) /**pΪ�������ĸ����*/
                b = p;
            else /*�ѽ��������������*/
            {
                switch (k)
                {
                case 1:
                    St[top]->lchild = p;
                    break;
                case 2:
                    St[top]->rchild = p;
                    break;
                }
            }
        }
        j++;
        ch = str[j];
    }
    bt = b;
}

int main()
{
    BiTree biTree;
    char *ch = "A(B(D(,G)),C(E,F))";
    BiTNode *t;
    biTree.CreateBTNode(t, ch);
    cout << "�������: ";
    biTree.PreTraverse();
    cout << endl
         << "�������: ";
    biTree.InTraverse();
    cout << endl
         << "�������: ";
    biTree.PostTraverse();
    cout << endl
         << "��α���: ";
    biTree.gradationTraverse();
    return 0;
}
