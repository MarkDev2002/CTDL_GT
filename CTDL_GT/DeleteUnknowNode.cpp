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

void DeleteHead(LIST &l)
{
    NODE *p = l.pHead;
    l.pHead = l.pHead->pNext;
    delete p;
}

void DeleteTail(LIST &l)
{
    NODE *p;
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        if (k == l.pTail)
        {
            l.pTail = p;
            l.pTail->pNext = NULL;
            delete k;
            return;
        }
        p = k;
    }
}

void XoaSauMotNode(LIST &l, NODE *q)
{
    NODE *g; // Node nằm sau q
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        // tìm q
        if (k->data == q->data) // q bây giờ chính là k
        {
            g = k->pNext;
            k->pNext = g->pNext;
            delete g;
            return;
        }
    }
}
// Xoá node bất kỳ
void XoaNodeBatKy(LIST &l, int x)
{
    // node g là node trỏ đến node nằm trước node cần xoá là x
    NODE *g = new NODE;
    // nếu node cần xoá nằm ở đầu danh sách
    if (l.pHead->data == x)
    {
        DeleteHead(l);
        return;
    }
    // nếu node cần xoá nằm ở cuối danh sách
    if (l.pTail->data == x)
    {
        DeleteTail(l);
        return;
    }
    // duyệt danh sách liên kết để tìm
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        // Phát hiện phần tử cần xoá
        if (k->data == x)
        {
            g->pNext = k->pNext; // cập nhật lại liên kết giữa node k với node h
            delete k;            // xoá node nằm sau node k
        }
        g = k; // cho node g trỏ đến node k là node cần xoá
    }
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
    int data;
    cout << "\nNhap khoa bat ky : ";
    cin >> data;
    cout << "Danh sach sau khi xoa node bat ky la : ";
    XoaNodeBatKy(l, data);
    OutPut(l);
    GiaiPhong(l);
    cout << endl;
    return 0;
}