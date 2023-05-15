#include <iostream>
#include <math.h>
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

int Length(LIST l)
{
    int count = 0;
    NODE *node = l.pHead;
    while (node != NULL)
    {
        count++;
        node = node->pNext;
    }
    return count;
}

int Multiply(LIST l)
{
    int multiply = 1;
    for (NODE *p = l.pHead; p != NULL; p = p->pNext)
    {
        multiply *= p->data;
    }
    return multiply;
}

int Solve(LIST l)
{
    NODE *p;
    int result;
    double x;
    double min = -1;
    x = (sqrt(Multiply(l))) / Length(l);
    for (p = l.pHead; p != NULL; p = p->pNext)
    {
        if (min == -1 || abs(x - p->data) < min)
        {
            min = abs(x - p->data);
            result = p->data;
        }
    }
    return result;
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

int main()
{
    LIST l;
    int n;
    cout << "So node muon nhap : ";
    cin >> n;
    InPut(l, n);
    // OutPut(l);
    cout << "\nGia tri gan nhat cua phep tinh la : ";
    cout << Solve(l) << endl;
    GiaiPhong(l);
    return 0;
}
