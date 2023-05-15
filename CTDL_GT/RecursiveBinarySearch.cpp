#include <iostream>
using namespace std;

void NhapMang(int a[], int &n)
{
    cout << "Nhap n : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap a[" << i << "] : ";
        cin >> a[i];
    }
}

void XuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int BinarySearch(int a[], int l, int h, int x)
{
    if (l <= h)
    {
        int m = l + (h - l) / 2;

        if (a[m] == x)
        {
            return m;
        }

        if (a[m] < x)
        {
            return BinarySearch(a, m + 1, h, x);
        }
        else
        {
            return BinarySearch(a, l, m - 1, x);
        }
    }
    return -1;
}

int main()
{
    int a[100];
    int n;
    int x;
    NhapMang(a, n);
    cout << "Mang vua nhap : ";
    XuatMang(a, n);
    cout << "\nNhap gia tri can tim : ";
    cin >> x;
    int index = BinarySearch(a, 0, n - 1, x);
    if (index != -1)
    {
        cout << "Ton tai gia tri " << x << " trong mang";
    }
    else
    {
        cout << "Khong ton tai gia tri " << x << " trong mang";
    }
    cout << endl;
    return 0;
}