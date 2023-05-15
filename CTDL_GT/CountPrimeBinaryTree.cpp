#include <iostream>
using namespace std;
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

bool CheckPrime(int x)
{
    if (x < 2)
    {
        return false;
    }
    else
    {
        if (x == 2)
        {
            return true;
        }
        else
        {
            if (x % 2 == 0)
            {
                return false;
            }
            else
            {
                for (int i = 2; i < x; i++)
                {
                    if (x % i == 0)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void NumberOfPrime(Tree t, int &dem)
{
    if (t != NULL)
    {
        if (CheckPrime(t->data) == true)
        {
            dem++;
        }
        NumberOfPrime(t->pLeft, dem);
        NumberOfPrime(t->pRight, dem);
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

int main()
{
    Tree t; // Khai báo cây
    int n;
    int dem = 0;
    cout << "Nhap du lieu can them : ";
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
    NumberOfPrime(t, dem);
    cout << "\nSo luong so nguyen to co trong BST : " << dem;
    cout << endl;
    return 0;
}