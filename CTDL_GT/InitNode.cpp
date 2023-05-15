#include <iostream>
using namespace std;
struct Node // khai báo cấu trúc 1 cái node
{
    int data;           // dữ liệu sẽ chứa trong 1 cái node
    struct Node *pNext; // con trỏ dùng để liên kết các node lại với nhau
};
// thay thế tên struct node thành tên duy nhất NODE
typedef struct Node NODE;

// khai báo cấu trúc danh sách liên kết đơn
struct List
{
    NODE *pHead; // node quản lí đầu danh sách
    NODE *pTail; // node quản lí cuối danh sách
};
// thay thế tên struct list thành tên duy nhất LIST
typedef struct List LIST;

// 2. Khởi tạo danh sách liên kết đơn
void Init(LIST &l) // Khởi tạo List
{
    // cho 2 node trỏ đến NULL vì DSLK đơn lúc này chưa có phần tử  nào
    l.pHead = l.pTail = NULL;
}

int isEmpty(LIST l) // kiểm tra danh sách liên kết rỗng
{
    return l.pHead == NULL;
}

// 3. Tạo Node trong danh sách
NODE *GetNode(int x) // x chính là dữ liệu đưa vào Data
{
    // Cấp phát vùng nhớ cho  Node
    NODE *p = new NODE;

    if (p == NULL)
    {
        cout << "Khong du bo nho de cap phat";
        return NULL;
    }
    p->data = x;     // truyền giá trị x vào data
    p->pNext = NULL; // đầu tiên khởi tạo node thì node chưa có liên kết tới node nào khác => con trỏ sẽ trỏ đến NULL
    return p;        // trả về node p vừa khởi tạo
}

// 4. Thêm Node (thêm đầu hoặc cuối)

// 1 2 3 4 5 : Thêm cuối
// 5 4 3 2 1 : Thêm đầu

// Thêm Node p vào đầu danh sách
void AddHead(LIST &l, NODE *p) // Thêm vào đầu danh sách
{
    if (l.pHead == NULL) // Tức là danh sách bị rỗng
    {
        l.pHead = l.pTail = p; // node đầu cũng chính là node cuối
    }
    else
    {
        p->pNext = l.pHead; // cho con trỏ của node cần thêm là node p liên kết với node đầu ( pHead )
        l.pHead = p;        // cập nhật lại phead cũng chính là node p
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
        l.pTail->pNext = p; // cho con trỏ pTail liên kết với p
        l.pTail = p;        // cập nhật lại node p là node pTail
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

// Huỷ ở cuối
void DeleteTail(LIST &l)
{
    // Nếu danh sách rỗng
    if (isEmpty(l))
    {
        return;
    }
    // duyệt từ đầu danh sách đến node nằm trước pTail
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        // phát hiện pTail
        if (k->pNext == l.pTail)
        {
            delete l.pTail;  // xoá đi phần tử cuối
            k->pNext = NULL; // cho con trỏ của node kế pTail trỏ đến NULL
            l.pTail = k;     // cập nhật lại l.pTail
            return;          // kết thúc
        }
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
int main()
{
    LIST l;
    int n;
    cout << "So node muon nhap : ";
    cin >> n;
    InPut(l, n);
    OutPut(l);
    cout << endl;
    return 0;
}
