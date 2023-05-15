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
int LinearSearch(int a[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int a[1000];
    int n, key;
    NhapMang(a, n);
    cout << "Nhap key : ";
    cin >> key;
    cout << "Ket qua can tim nam o vi tri : " << LinearSearch(a, n, key);
    cout << endl;
    return 0;
}

//Ưu điểm : có thể áp dụng tất cả
//Khuyết điểm : chi phí cao (tỉ lệ O(n))
//Tìm kiếm tuần tự