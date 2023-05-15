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

// Xoá lá
void DeleteLeaves(Tree &t)
{
    if (t->pLeft == NULL && t->pRight == NULL)
    {
        delete t;
        t = NULL;
    }
}

// Xoá node có 1 con
void DeleteChild(Tree &t)
{
    // Nếu Node có một cây con trái thì ta thực hiện
    // duyệt sang trái để cập nhật lại mối liên kết giữa Node cha và Node con của Node cần xóa
    if (t->pLeft == NULL && t->pRight != NULL)
    {
        NODE *temp = t;
        t = t->pRight;
        delete temp;
    }
    // Nếu Node có một cây con phải thì ta thực hiện
    // duyệt sang phải để cập nhật lại mối liên kết giữa Node cha và Node con của Node cần xóa.
    else if (t->pRight == NULL && t->pLeft != NULL)
    {
        NODE *temp = t;
        t = t->pLeft;
        delete temp;
    }
}

// Kiểm tra cây nhị phân
bool isBST(Tree t, int min, int max)
{
    // cơ sở , cây rỗng là 1 BST
    if (!t)
        return true;
    // Kiểm tra xem data có nằm ngoài phạm vi cho phép hay không.
    if (t->data < min)
        return false;
    if (t->data > max)
        return false;
    // cập nhật đến cây con bên phải và bên trái
    return isBST(t->pRight, t->data, max) &&
           isBST(t->pLeft, min, t->data);
}

// Tạo cây
void CreateTree(Tree &t)
{
    Init(t); // Khởi tạo cây
    int LuaChon;
    do
    {
        cout << "\n1.Nhap du lieu : ";
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
    } while (LuaChon != 0);
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

NODE *Search(Tree t, int x)
{
    if (t == NULL)
    {
        return NULL; // không tìm thấy
    }
    if (t->data > x)
    {
        Search(t->pLeft, x); // Tìm cây con bên trái
    }
    else if (t->data < x)
    {
        Search(t->pRight, x); // Tìm cây con bên phải
    }
    else
    {
        return t; // tìm thấy
    }
}

void removeTree(Tree &t)
{
    if (t != NULL)
    {
        removeTree(t->pLeft);  // huỷ cây con trái
        removeTree(t->pRight); // huỷ cây con phải
        delete t;              // xoá node gốc
    }
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
    int x;
    cout << "\nNhap vao node tim kiem : ";
    cin >> x;
    NODE *q = Search(t, x);
    if (q == NULL)
    {
        cout << "Khong tim thay!";
    }
    else
    {
        cout << "\nPhan tu x ton tai trong cay";
    }
    cout << endl;
    system("pause");
    return 0;
}