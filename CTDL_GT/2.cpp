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

// 2. Khởi tạo danh sách liên kết đơn
void Init(LIST &l)
{
    l.pHead = l.pTail = NULL;
}

// 3. Tạo Node trong danh sách
NODE *GetNode(int x) // x chính là dữ liệu đưa vào Data
{
    // Cấp phát 1 Node
    NODE *p = new NODE;

    if (p == NULL)
    {
        return NULL;
    }
    p->data = x;     // Lưu x vào data
    p->pNext = NULL; // Khởi tạo mối liên kết
    return p;
}

// 4. Thêm Node (thêm đầu hoặc cuối)

// 1 2 3 4 5 : Thêm cuối
// 5 4 3 2 1 : Thêm đầu

// Thêm Node p vào đầu danh sách
void AddHead(LIST &l, NODE *p)
{
    if (l.pHead == NULL) // Tức là danh sách bị rỗng
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead; // p quăng dây để tham gia vào danh sách
        l.pHead = p;        // p chính thức đã đứng dầu danh sách
    }
}

// Thêm Node p vào cuối danh sách
void AddTail(LIST &l, NODE *p)
{
    if (l.pHead == NULL) // Tức là danh sách bị rỗng
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p; // l.pTail quăng dây nối với p
        l.pTail = p;
    }
}

// 5. Nhập dữ liệu cho danh sách
void InPut(LIST &l, int n)
{

    Init(l); // Khởi tạo danh sách.
    for (int i = 1; i <= n; i++)
    {
        // Mỗi lần vòng lặp chạy là ta nhập 1 Node
        int x;
        cout << "Nhap vao data thu " << i << " : ";
        cin >> x;

        NODE *p = GetNode(x); // Đưa data vào Node p, tạo ra node p
        AddTail(l, p);        // Thêm Node p vào cuối danh sách.
                              // AddHead(l, p);
    }
}

void OutPut(LIST l)
{
    // for(int i = 0; i < n; i++)
    for (NODE *p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << p->data << " ";
    }
}

void Sort(LIST &l)
{
    for (NODE *p = l.pHead; p != l.pTail; p = p->pNext)
    {
        for (NODE *q = p->pNext; q != NULL; q = q->pNext)
        {
            if (p->data < q->data)
            {
                swap(p->data, q->data);
            }
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
    int n, x, i;
    cout << "So node muon nhap : ";
    cin >> n;
    InPut(l, n);
    OutPut(l);
    Sort(l);
    cout << "\nDanh sach sau khi sap xep giam dan la : ";
    OutPut(l);
    cout << "\nNhap k : ";
    cin >> x;
    do
    {
        if (x > n)
        {
            cout << "Nhap lai !";
        }
        else
        {
            NODE *p = l.pHead;      // khai báo node p đang ở đầu danh sách
            for (i = 0; i < x; i++) // duyệt từ 0 đến nhỏ hơn x nhập vào
            {
                cout << p->data << " "; // xuất ra giá trị lớn nhất
                p = p->pNext;           // xuất ra các giá trị gần nhau nhất theo điều kiện
                break;
            }
        }
    } while (x > n);
    GiaiPhong(l);
    cout << endl;
    return 0;
}