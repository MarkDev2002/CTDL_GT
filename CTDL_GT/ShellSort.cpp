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
void ShellSort(int a[], int n)
{
    int interval, temp;
    for (interval = n / 2; interval > 0; interval /= 2)
    {
        for (int i = interval; i < n; i++)
        {
            temp = a[i];
            for (int j = i; j >= interval && a[j - interval] > temp; j -= interval)
            {
                a[j] = a[j - interval];
            }
            a[j] = temp;
        }
    }
}
int main()
{
    int a[1000];
    int n;
    NhapMang(a, n);
    ShellSort(a, n);
    cout << "Mang sau khi duoc sap xep : ";
    XuatMang(a, n);
    cout << endl;
    return 0;
}

// Sắp xếp theo độ dài giảm dần