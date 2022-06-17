#include <iostream>
using namespace std;
#define initlistsize 100
#define increment 10

// �û��Զ�������, �൱�� ElemType
typedef char DataType;
class SqList
{
private:
    DataType *elem;       // ���������׵�ַ
    int listsize, length; // ��ǰ˳���ռ��С��Ԫ������
public:
    SqList();                                  // ��ʼ��˳���
    void InsertList();                         // ����Ԫ��a, b,c,d,e
    void DisPlayList();                        // ���˳���
    void DisplayListLength();                  // ���˳���,��
    bool ListIsNull();                         // �ж�˳���L�Ƿ�Ϊ��
    DataType getList(int pos);                 //���˳���L�ĵ�����Ԫ��
    int LocateList(DataType x);                //  ���Ԫ��a λ��
    void InsertListInPos(int pos, DataType e); // �ڵ�4��Ԫ��λ���ϲ���f Ԫ��
    void DeleteList(int pos, DataType &e); // ɾ��˳���L�ĵ�3��Ԫ��
    ~SqList();                                 // ����˳���
};
// ��ʼ��˳��� ʵ��
SqList::SqList()
{
    elem = new DataType[initlistsize];
    listsize = initlistsize;
    length = 0;
}
// ����a-e
void SqList::InsertList()
{
    DataType letter = 'a';
    for (int i = 0; i < 5; i++) // ѭ���������Ա�, �����ַ�a-z
    {
        elem[i] = letter;
        letter++;
        length++;
    }
}
// ���˳���
void SqList::DisPlayList()
{
    int i;
    for (i = 0; i < length; i++) // �������Ա�ĳ��ȱ���������Ա��Ԫ��
    {
        cout << elem[i] << " ";
    }
    cout << endl;
}
// ���˳����
void SqList::DisplayListLength()
{
    cout << "˳���ĳ���Ϊ: " << length << endl;
}
// �ж�˳���L�Ƿ�Ϊ��
bool SqList::ListIsNull()
{
    if (length == 0)
        return true;
    else
        return false;
}
// ���˳���L�ĵ�����Ԫ��
DataType SqList::getList(int pos)
{
    if (pos > length && pos < 1) // �ж���Ҫ�����λ���Ƿ�Ƿ�, �Ƿ�����-1
    {
        return -1;
    }
    else
    {
        return elem[pos - 1];
    }
}
//  ���Ԫ��a λ��
int SqList::LocateList(DataType x)
{
    for (int i = 0; i < length; i++)
    {
        if (elem[i] == x)
            return i + 1; // �ҵ��˷�������Ǳ�+1
    }
    return -1; // ���������û���ҵ��ͷ���-1
}
// �ڵ�4��Ԫ��λ���ϲ���f Ԫ��
void SqList::InsertListInPos(int pos, DataType e)
{
    if (pos < 1 && pos > length + 1) // �жϲ����λ���Ƿ�Ƿ�
        return;
    if (length >= listsize) // ˳�������,�����µĿռ�
    {
        DataType *elem1 = new DataType[listsize + increment];
        for (int i = 0; i < length; i++)
            elem1[i] = elem[i];
        delete []elem;
        elem = elem1;
        listsize += increment;
    }
    DataType *p = &elem[pos-1], *q = &elem[length-1];
    for(;p<=q;q--) // �Ӻ���ǰ�ƶ�,��Ԫ������ƶ�һ��λ��
        *(q+1) = *q;
    *p = e;
    length++;
}
// ɾ��˳���L�ĵ�3��Ԫ��
void SqList::DeleteList(int pos, DataType &e){
    if (pos < 1 && pos > length + 1)
        return;
    DataType *p = &elem[pos-1], *q = &elem[length-1];
    e = *p;
    for(;p<q;p++) // �Ӻ���ǰ��һ��λ��
        *p = *(p+1); 
    length--;
}
SqList::~SqList()
{
    delete []elem; // ������new ������delete, ����һ�Թؼ���
    listsize = 0;
    length = 0;
    if (ListIsNull()) // �ж��Ƿ����ٳɹ�
        cout << "˳������ٳɹ�" << endl;
    else
        cout << "˳�������ʧ��" << endl;
}

int main()
{
    SqList L;
    L.InsertList();
    L.DisPlayList();
    L.DisplayListLength();
    if (L.ListIsNull())
        cout << "˳���Ϊ��" << endl;
    else
        cout << "˳���Ϊ��" << endl;
    cout << "������Ԫ��Ϊ: " << L.getList(3) << endl;
    cout << "Ԫ��a��λ��Ϊ: " << L.LocateList('a') << endl;
    L.InsertListInPos(4, 'f');
    cout<<"����Ԫ��֮���˳���Ϊ:";
    L.DisPlayList();
    DataType deleteData;
    L.DeleteList(3, deleteData);
    cout<<"ɾ����Ԫ��Ϊ: "<<deleteData<<endl;
    cout<<"ɾ��Ԫ��֮���˳���Ϊ:";
    L.DisPlayList();
    return 0;
}
