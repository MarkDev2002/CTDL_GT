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
    if (l.pHead == NULL) // Tức là danh sách bị rỗng
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

bool CheckOpposite(int n)
{
    int tam = n;
    int daonguoc = 0;
    while (n != 0)
    {
        int x = n % 10;
        daonguoc = daonguoc * 10 + x;
        n /= 10;
    }
    if (daonguoc == tam)
    {
        return true;
    }
    return false;
}

void OuputOpposite(LIST &l)
{
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        if (CheckOpposite(k->data) == true)
        {
            cout << k->data << " ";
        }
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
    OuputOpposite(l);
    cout << "\nCac so doi xung cua danh sach : ";
    OutPut(l);
    GiaiPhong(l);
    cout << endl;
    return 0;
}
