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

void InterChangeSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                swap(a[i], a[j]);
}
int main()
{
    int a[1000];
    int n;
    NhapMang(a, n);
    InterChangeSort(a, n);
    cout << "Mang sau khi duoc sap xep la : ";
    XuatMang(a, n);
    cout << endl;
    return 0;
}
//độ phức tạp O(n^2)
//Đổi chỗ trực tiếp