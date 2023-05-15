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

// Thêm node p vào sau node q
void ThemSau(LIST &l, NODE *p, NODE *q)
{
    for (NODE *k = l.pHead; k != NULL; k = k->pNext) // duyệt đầu mảng tới cuối mảng
    {
        if (k->data == q->data) // duyệt nếu như tìm thấy k = q (tìm thấy q)
        {
            NODE *g = k->pNext; // lưu biến k hiện tại trỏ đến next
            k->pNext = p;       // từ k trỏ đến next = p
            p->pNext = g;       // p trở đến next = g
            return;
        }
    }
}

void GiaiPhong(LIST &l)
{
    NODE *p; // Khai báo node p
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
    OutPut(l);
    int q, p;
    cout << "\nNhap q : ";
    cin >> q;
    NODE *Q = GetNode(q);
    cout << "Nhap p : ";
    cin >> p;
    NODE *P = GetNode(p);
    ThemSau(l, P, Q);
    cout << "Danh sach sau khi them : ";
    OutPut(l);
    GiaiPhong(l);
    cout << endl;
    return 0;
}