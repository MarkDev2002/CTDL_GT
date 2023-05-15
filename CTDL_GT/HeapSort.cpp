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
void Heapify(int a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (a[l] > a[largest] && l < n)
    {
        largest = l;
    }
    if (a[r] > a[largest] && r < n)
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(a[i], a[largest]);
        Heapify(a, n, largest);
    }
}
void HeapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        Heapify(a, n, i);
    }
    for (int i = n - 1; i >= 0; --i)
    {
        swap(a[0], a[i]);
        Heapify(a, i, 0);
    }
}

int main()
{
    int a[1000];
    int n;
    NhapMang(a, n);
    HeapSort(a, n);
    cout << "Mang sau khi duoc sap xep la : ";
    XuatMang(a, n);
    cout << endl;
    return 0;
}