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

// Tìm 1 phần tử
NODE *TimKiem(LIST l, int data)
{
    NODE *p = l.pHead;
    // duyệt danh sách nếu chưa tìm thấy tiếp tục duyệt

    while (p != NULL && p->data != data)
        p = p->pNext;

    // kết thúc duyệt nếu node duyệt khác NULL thì trả về địa chỉ của node đó
    if (p != NULL)
        return p;
    return NULL;
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
    int n, data;
    cout << "So node muon nhap : ";
    cin >> n;
    InPut(l, n);
    OutPut(l);
    cout << "\nNhap khoa bat ky : ";
    cin >> data;
    TimKiem(l, data);
    GiaiPhong(l);
    cout << endl;
    return 0;
}