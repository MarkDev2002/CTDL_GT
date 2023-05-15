#include <iostream>
using namespace std;
struct node
{
    int data;            // dữ liệu chứa trong node
    struct node *pLeft;  // cây con trái
    struct node *pRight; // cây con phải
};
typedef struct node NODE;
typedef NODE *Tree;
void Init(Tree &t)
{
    t = NULL;
}
// Thêm phần tử vào cây
void Insert(Tree &t, int x)
{
    if (t == NULL) // cây rỗng => x sẽ là node gốc
    {
        NODE *q = new NODE;          // tạo ra con trỏ q
        q->data = x;                 // q trỏ đến data sẽ bằng x
        q->pLeft = q->pRight = NULL; // lúc này là node gốc nên left và right đều bằng NULL
        t = q;                       // cho con trỏ t(lúc này là con trỏ gốc) trỏ đến q (t sẽ nằm cùng địa chỉ vs q)
    }
    else
    {
        if (t->data > x) // nếu t trỏ đến data > x node gốc
        {
            Insert(t->pLeft, x); // thêm vào bên trái
        }
        else if (t->data < x) // ngược lại x lớn hơn
        {
            Insert(t->pRight, x); // thêm vào bên phải
        }
    }
}

// Tạo cây
void CreateTree(Tree &t, int n)
{
    Init(t); // Khởi tạo cây
    for (int i = 1; i <= n; i++)
    {
        int x;
        cout << "Nhap vao du lieu thu " << i << " : ";
        cin >> x;
        Insert(t, x);
    }
}

void NLR(Tree t)
{
    if (t != NULL)
    {
        NLR(t->pLeft);
        NLR(t->pRight);
        cout << t->data << " ";
    }
}

void LNR(Tree t)
{
    if (t != NULL)
    {
        NLR(t->pLeft);
        cout << t->data << " ";
        NLR(t->pRight);
    }
}

void LRN(Tree t)
{
    if (t != NULL)
    {
        LRN(t->pLeft);
        LRN(t->pRight);
        cout << t->data << " ";
    }
}

void NRL(Tree t)
{
    if (t != NULL)
    {
        cout << t->data << " ";
        NRL(t->pRight);
        NRL(t->pLeft);
    }
}

void RNL(Tree t)
{
    if (t != NULL)
    {
        RNL(t->pRight);
        cout << t->data << " ";
        RNL(t->pLeft);
    }
}

void RLN(Tree t)
{
    if (t != NULL)
    {
        RLN(t->pRight);
        RLN(t->pLeft);
        cout << t->data << " ";
    }
}

int main()
{
    Tree t; // Khai báo cây
    int n;
    cout << "So du lieu muon them : ";
    cin >> n;
    CreateTree(t, n);
    cout << "\nNRL\n";
    NRL(t);
    cout << "\nLNR\n";
    LNR(t);
    cout << "\nNLR\n";
    NLR(t);
    cout << "\nLRN\n";
    LRN(t);
    cout << endl;
    system("pause");
    return 0;
}