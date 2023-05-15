#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *pNext;
    struct node *pPrev;
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
    p->pPrev = NULL;
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
        l.pHead->pPrev = p;
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
        p->pPrev = l.pTail;
        l.pTail = p;
    }
}

void Input(LIST &l, int n)
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

void Output(LIST l)
{
    cout << "Xuat theo chieu xuoi : ";
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        cout << k->data << " ";
    }
    cout << "\nXuat theo chieu nguoc : ";
    for (NODE *k = l.pTail; k != NULL; k = k->pPrev)
    {
        cout << k->data << " ";
    }
}
int main()
{
    LIST l;
    int n;
    cout << "So node muon nhap : ";
    cin >> n;
    Input(l, n);
    Output(l);
    cout << endl;
    return 0;
}