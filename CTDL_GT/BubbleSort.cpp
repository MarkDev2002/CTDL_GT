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
void BubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1]) //nếu a[j] > a[j-1] thì đưa a[j+1] vào temp chờ để so sánh với phần tử kế tiếp
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
int main()
{
    int a[1000];
    int n;
    NhapMang(a, n);
    BubbleSort(a, n);
    cout << "Mang sau khi da duoc sap xep la : ";
    XuatMang(a, n);
    cout << endl;
    return 0;
}

//độ phức tạp O(n^2)
//Nổi Bọt