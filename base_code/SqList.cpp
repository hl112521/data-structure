#include <iostream>
using namespace std;
#define initlistsize 100
#define increment 10

// 用户自定义类型, 相当于 ElemType
typedef char DataType;
class SqList
{
private:
    DataType *elem;       // 存放数组的首地址
    int listsize, length; // 当前顺序表空间大小和元素数量
public:
    SqList();                                  // 初始化顺序表
    void InsertList();                         // 插入元素a, b,c,d,e
    void DisPlayList();                        // 输出顺序表
    void DisplayListLength();                  // 输出顺序表,表长
    bool ListIsNull();                         // 判断顺序表L是否为空
    DataType getList(int pos);                 //输出顺序表L的第三个元素
    int LocateList(DataType x);                //  输出元素a 位置
    void InsertListInPos(int pos, DataType e); // 在第4个元素位置上插入f 元素
    void DeleteList(int pos, DataType &e); // 删除顺序表L的第3个元素
    ~SqList();                                 // 销毁顺序表
};
// 初始化顺序表 实现
SqList::SqList()
{
    elem = new DataType[initlistsize];
    listsize = initlistsize;
    length = 0;
}
// 插入a-e
void SqList::InsertList()
{
    DataType letter = 'a';
    for (int i = 0; i < 5; i++) // 循环遍历线性表, 输入字符a-z
    {
        elem[i] = letter;
        letter++;
        length++;
    }
}
// 输出顺序表
void SqList::DisPlayList()
{
    int i;
    for (i = 0; i < length; i++) // 根据线性表的长度遍历输出线性表的元素
    {
        cout << elem[i] << " ";
    }
    cout << endl;
}
// 输出顺序表表长
void SqList::DisplayListLength()
{
    cout << "顺序表的长度为: " << length << endl;
}
// 判断顺序表L是否为空
bool SqList::ListIsNull()
{
    if (length == 0)
        return true;
    else
        return false;
}
// 输出顺序表L的第三个元素
DataType SqList::getList(int pos)
{
    if (pos > length && pos < 1) // 判断需要输出的位置是否非法, 非法返回-1
    {
        return -1;
    }
    else
    {
        return elem[pos - 1];
    }
}
//  输出元素a 位置
int SqList::LocateList(DataType x)
{
    for (int i = 0; i < length; i++)
    {
        if (elem[i] == x)
            return i + 1; // 找到了返回数组角标+1
    }
    return -1; // 遍历完如果没有找到就返回-1
}
// 在第4个元素位置上插入f 元素
void SqList::InsertListInPos(int pos, DataType e)
{
    if (pos < 1 && pos > length + 1) // 判断插入的位置是否非法
        return;
    if (length >= listsize) // 顺序表满了,申请新的空间
    {
        DataType *elem1 = new DataType[listsize + increment];
        for (int i = 0; i < length; i++)
            elem1[i] = elem[i];
        delete []elem;
        elem = elem1;
        listsize += increment;
    }
    DataType *p = &elem[pos-1], *q = &elem[length-1];
    for(;p<=q;q--) // 从后往前移动,将元素向后移动一个位置
        *(q+1) = *q;
    *p = e;
    length++;
}
// 删除顺序表L的第3个元素
void SqList::DeleteList(int pos, DataType &e){
    if (pos < 1 && pos > length + 1)
        return;
    DataType *p = &elem[pos-1], *q = &elem[length-1];
    e = *p;
    for(;p<q;p++) // 从后往前移一个位置
        *p = *(p+1); 
    length--;
}
SqList::~SqList()
{
    delete []elem; // 创建用new 销毁用delete, 这是一对关键字
    listsize = 0;
    length = 0;
    if (ListIsNull()) // 判断是否销毁成功
        cout << "顺序表销毁成功" << endl;
    else
        cout << "顺序表销毁失败" << endl;
}

int main()
{
    SqList L;
    L.InsertList();
    L.DisPlayList();
    L.DisplayListLength();
    if (L.ListIsNull())
        cout << "顺序表为空" << endl;
    else
        cout << "顺序表不为空" << endl;
    cout << "第三个元素为: " << L.getList(3) << endl;
    cout << "元素a的位置为: " << L.LocateList('a') << endl;
    L.InsertListInPos(4, 'f');
    cout<<"插入元素之后的顺序表为:";
    L.DisPlayList();
    DataType deleteData;
    L.DeleteList(3, deleteData);
    cout<<"删除的元素为: "<<deleteData<<endl;
    cout<<"删除元素之后的顺序表为:";
    L.DisPlayList();
    return 0;
}
