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

// Kiểm tra cây nhị phân
bool isBST(Tree t, int min, int max)
{
    // cơ sở , cây rỗng là 1 BST
    if (!t)
        return true;
    // Kiểm tra xem data có nằm ngoài phạm vi cho phép hay không.
    if (t->data < min && t->data > max && isBST(t->pLeft, min, t->data) && isBST(t->pRight, t->data, max))
        return true;
    else
        return false;
}

void isBinarySearchTree(Tree t)
{
    if (isBST(t, INT_MIN, INT_MAX))
    {
        cout << "The tree is a BST";
    }
    else
    {
        cout << "The tree is not a BST!";
    }
}
int main()
{
    Tree t; // Khai báo cây
    int n;
    cout << "So du lieu muon them : ";
    cin >> n;
    CreateTree(t, n);
    isBinarySearchTree(t);
    cout << endl;
    return 0;
}