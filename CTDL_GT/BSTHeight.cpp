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
    // Cây rỗng => x sẽ là node gốc
    if (t == NULL)
    {
        NODE *q = new NODE;
        q->data = x;
        q->pLeft = q->pRight = NULL;
        t = q;
    }
    else
    {
        if (t->data > x)
        {
            Insert(t->pLeft, x);
        }
        else if (t->data < x)
        {
            Insert(t->pRight, x);
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

int ChieuCao(Tree t)
{
    if (t == NULL)
    {
        return 0;
    }

    int a = (ChieuCao(t->pLeft));
    int b = (ChieuCao(t->pRight));
    if (a > b)
    {
        return a + 1;
    }
    return b + 1;
}

int main()
{
    Tree t; // Khai báo cây
    int n;
    cout << "Nhap du lieu : ";
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
    cout << "Chieu cao cua cay : " << ChieuCao(t);
    cout << endl;
    return 0;
}