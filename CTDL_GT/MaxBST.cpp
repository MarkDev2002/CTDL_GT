#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *pLeft;
    struct node *pRight;
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

int FindMax(Tree t)
{
    int max = INT_MIN;
    if (t != NULL)
    {
        if (max < t->data)
        {
            max = t->data;
        }
        FindMax(t->pLeft);
        FindMax(t->pRight);
    }
}

void CreateTree(Tree &t)
{
    Init(t); // Khởi tạo cây
    int LuaChon;
    do
    {
        cout << "\n1.Nhap du lieu";
        cout << "\n2.Find Max ";
        cout << "\n0.Ket thuc";
        cout << "\nNhap vao lua chon cua ban : ";
        cin >> LuaChon;
        if (LuaChon == 1)
        {
            int x;
            cout << "Nhap du lieu node can them : ";
            cin >> x;
            Insert(t, x); // Thêm x vào cây
        }
        if (LuaChon == 2)
        {
            cout << "Gia tri lon nhat cua BST la : " << FindMax(t);
        }
    } while (LuaChon != 0);
}

int main()
{
    Tree t; // Khai báo cây
    CreateTree(t);
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