#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *pNext;
};
typedef struct Node NODE;

struct List
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct List LIST;

void Init(LIST &l)
{
    l.pHead = l.pTail = NULL;
}

NODE *GetNode(int x)
{

    NODE *p = new NODE;

    if (p == NULL)
    {
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

int TimMin(LIST l)
{
    int Min = l.pHead->data;
    for (NODE *p = l.pHead->pNext; p != NULL; p = p->pNext)
    {
        if (p->data < Min)
        {
            Min = p->data;
        }
    }
    return Min;
}

int Compare(LIST &l, int x)
{
    NODE *p = GetNode(x);
    cout << "Nhap node k : ";
    cin >> x;
    int fm = TimMin(l);
    if (x < fm)
    {
        x = fm;
        return x;
    }
    return -1;
}

void GiaiPhong(LIST &l)
{
    NODE *p;
    while (l.pHead != NULL)
    {
        p = l.pHead;
        l.pHead = l.pHead->pNext;
        delete p;
    }
}

int main()
{
    LIST l;
    int n, x;
    cout << "So node muon nhap : ";
    cin >> n;
    InPut(l, n);
    OutPut(l);
    cout << endl;
    int result = Compare(l, x);
    cout << "Khoa nho nhat nhung lon hon gia tri k cho truoc la : " << result;
    GiaiPhong(l);
    cout << endl;
    return 0;
}
