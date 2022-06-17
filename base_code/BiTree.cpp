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
    void Rcreate(BiTNode *&t);          //递归创建二叉树
    void PreTraverse(BiTNode *t);       //先序遍历递归函数
    void InTraverse(BiTNode *t);        //中序遍历递归函数
    void PostTraverse(BiTNode *t);      //后序遍历递归函数
    void gradationTraverse(BiTNode *t); //层次遍历递归函数
public:
    BiTree() { bt = NULL; };
    void CreateBTNode(BiTNode *&b, char *str);
    void RcreateBitree();     //创建二叉树
    void PreTraverse();       //先序遍历二叉树
    void InTraverse();        //中序遍历二叉树
    void PostTraverse();      //后序遍历二叉树
    void gradationTraverse(); //层次遍历二叉树
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
            sq.push(p->lchild); //左孩子入队
        if (p->rchild != NULL)
            sq.push(p->rchild); //右孩子入队
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
    b = NULL; /*建立的二叉树初始时为空*/
    ch = str[j];
    while (ch != '\0') /*str未扫描完时循环*/
    {
        switch (ch)
        {
        case '(':
            top++;
            St[top] = p;
            k = 1;
            break;
            /*为左孩子结点*/
        case ')':
            top--;
            break;
        case ',':
            k = 2;
            break;
        /*为孩子结点右结点*/
        default:
            p = new BiTNode;
            p->data = ch;
            p->lchild = p->rchild = NULL;
            if (b == NULL) /**p为二叉树的根结点*/
                b = p;
            else /*已建立二叉树根结点*/
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
    cout << "先序遍历: ";
    biTree.PreTraverse();
    cout << endl
         << "中序遍历: ";
    biTree.InTraverse();
    cout << endl
         << "后序遍历: ";
    biTree.PostTraverse();
    cout << endl
         << "层次遍历: ";
    biTree.gradationTraverse();
    return 0;
}
