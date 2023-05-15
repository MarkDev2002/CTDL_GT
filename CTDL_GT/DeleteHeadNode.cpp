#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *pNext;
};
typedef struct node NODE;

struct list
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct list LIST;

void Init(LIST &l)
{
    l.pHead = l.pTail = NULL;
}

NODE *GetNode(int x)
{
    NODE *p = new NODE;
    if (p == NULL)
    {
        cout << "Not enough memory";
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}

void AddHead(LIST &l, NODE *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void AddTail(LIST &l, NODE *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void InPut(LIST &l, int n)
{

    Init(l);
    for (int i = 1; i <= n; i++)
    {

        int x;
        cout << "Nhap vao data thu " << i << " : ";
        cin >> x;

        NODE *p = GetNode(x);
        AddTail(l, p);
    }
}

void OutPut(LIST l)
{
    for (NODE *p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << p->data << " ";
    }
}

// Huỷ ở đầu
void DeleteHead(LIST &l)
{
    NODE *p = l.pHead;        // p trỏ vào đầu
    l.pHead = l.pHead->pNext; // p trở tới node đầu , node đầu trốn sang node bên cạnh
    delete p;                 // xoá node đầu
}

void GiaiPhong(LIST &l)
{
    NODE *p; // Khai báo node p
    while (l.pHead != NULL)
    {
        p = l.pHead;              // p trở tới Head
        l.pHead = l.pHead->pNext; // head trốn sang bên cạnh
        delete p;                 // giải phóng p cx chính là giải phóng head ban đầu
    }
}
int main()
{
    LIST l;
    int n;
    cout << "So node muon nhap : ";
    cin >> n;
    InPut(l, n);
    OutPut(l);
    DeleteHead(l);
    cout << "\nDanh sach sau khi xoa node dau : ";
    OutPut(l);
    GiaiPhong(l);
    cout << endl;
    return 0;
}