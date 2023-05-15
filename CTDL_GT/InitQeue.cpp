#include <iostream>
using namespace std;

// khai báo cấu trúc của 1 node trong queue
struct node
{
    int data;           // queue đang chứa các số nguyên
    struct node *pNext; // con trỏ liên kết các node lại với nhau
};
typedef struct node NODE;

// khai báo cấu trúc queue
struct queue
{
    NODE *pHead; // con trỏ đầu
    NODE *pTail; // con trỏ cuối
};
typedef struct queue QUEUE;

void InitQueue(QUEUE &q)
{
    q.pHead = q.pTail = NULL;
}

int IsEmpty(QUEUE q)
{
    return q.pHead == NULL;
}

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

// Đếm số phần tử có trong hàng đợi
int Size(QUEUE q)
{
    NODE *p = q.pHead; // Khai báo node p nằm ở vị trí đầu tiên
    int count = 0;     // biến đếm
    while (p != NULL)  // node p khác rỗng
    {
        count++;      // biến đếm tăng
        p = p->pNext; // p trỏ tới các phần tử tiếp theo
    }
    return count;
}

// Trả về giá trị đầu tiên của hàng đợi
int Front(QUEUE q)
{
    // kiểm tra nếu hàng đợi tồn tại phần tử thì ta thực hiện return phần tử đầu tiên
    if (!IsEmpty(q))
    {
        return q.pHead->data;
    }
    // Nếu trong hàng đợi rỗng thì return 0 và kết thúc hàm
    return 0;
}

int Rear(QUEUE q)
{
    if (!IsEmpty(q))
    {
        return q.pTail->data;
    }
    return 0;
}
// Thêm đối tượng vào cuối hàng đợi
void EnQueue(QUEUE &q, NODE *p)
{
    if (IsEmpty(q)) // nếu danh sách rỗng
    {
        q.pHead = q.pTail = p; // hàng đợi đầu cũng là hàng đợi cuối và cũng là node p
    }
    else
    {
        q.pTail->pNext = p; // hàng đợi cuối liên kết với node cần thêm là p
        q.pTail = p;        // cập nhật hàng đợi cuối cũng là p
    }
}

// Lấy đối tượng ở đầu hàng đợi
int Dequeue(QUEUE &q)
{
    // kiểm tra nếu hàng đợi tồn tại thì thực hiện các câu lệnh
    if (!IsEmpty(q))
    {
        // tạo mới một Node p (là node thay thế cho node cần xóa)
        NODE *p = q.pHead;
        // trỏ con trỏ Next đến phần tử tiếp theo để có thể xóa phần tử đầu
        q.pHead = q.pHead->pNext;
        // gán data cho p và return nó
        return p->data;
        // sau khi return thì thực hiện xóa nó khỏi hàng đợi
        delete p;
    }
    return 0;
}

void Input(QUEUE &q)
{
    int n;
    cout << "Nhap so phan tu muon them vao QUEUE : ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cout << "\nNhap phan tu trong hang doi thu " << i << " : ";
        cin >> x;
        NODE *p = GetNode(x);
        EnQueue(q, p);
    }
}

void Output(QUEUE q)
{
    NODE *p = q.pHead;
    while (p)
    {
        cout << p->data << "\t";
        p = p->pNext;
    }
    cout << endl;
}

void Menu(QUEUE q)
{
    int choice;
    do
    {
        cout << "\n\n\t\t ============== Menu ==============";
        cout << "\n\t1. Input";
        cout << "\n\t2. Output";
        cout << "\n\t3. Count Elements";
        cout << "\n\t4. Front";
        cout << "\n\t5. Dequeue";
        cout << "\n\t6. Rear";
        cout << "\n\t0. Thoat";
        cout << "\n\n\t\t ============== End ==============";
        cout << "\nNhap lua chon : ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            break;
        case 1:
            Input(q);
            break;
        case 2:
            cout << "Cac phan tu trong hang doi la : ";
            Output(q);
            break;
        case 3:
            cout << "So phan tu co trong hang doi la : " << Size(q);
            break;
        case 4:
            cout << "Phan tu dau tien cua hang doi la : " << Front(q);
            break;
        case 5:
            Dequeue(q);
            cout << "Xoa thanh cong , Vui long nhap 2 de kiem tra lai!!";
            break;
        case 6:
            cout << "Phan tu cuoi hang doi la : " << Rear(q);
            break;
        default:
            cout << "\nNhap sai , Vui long nhap lai!";
        }
    } while (choice);
}

int main()
{
    QUEUE q;
    InitQueue(q);
    int choice;
    Menu(q);
    cout << endl;
    return 0;
}