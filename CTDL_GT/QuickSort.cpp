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
int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int left = low;
    int right = high - 1;
    while (true)
    {
        while (left <= right && a[left] < pivot)
            left++;
        while (right >= left && a[right] > pivot)
            right--;
        if (left >= right)
            break;
        swap(a[left], a[right]);
        left++;
        right--;
    }
    swap(a[left], a[high]);
    return left;
}
void QuickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int index = partition(a, low, high);
        QuickSort(a, low, index - 1);
        QuickSort(a, index + 1, high);
    }
}
int main()
{
    int a[1000];
    int n;
    NhapMang(a, n);
    QuickSort(a, 0, n - 1);
    cout << "Mang sau khi duoc sap xep la : ";
    XuatMang(a, n);
    cout << endl;
    return 0;
}