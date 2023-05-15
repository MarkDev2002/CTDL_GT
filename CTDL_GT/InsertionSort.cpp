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
void InsertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = a[i];                  //biến tạm temporary
        int pos = i - 1;               //gán pos bằng phần tử đứng trước i
        while (pos >= 0 && x < a[pos]) //nếu như phần tử đứng trước i lớn hơn bằng 0 và biến tạm nhỏ hơn phần tử tại vị trí a[phần tử đứng trước i]
        {
            a[pos + 1] = a[pos]; //đổi chổ 2 vị trí với nhau
            --pos;
        }
        a[pos + 1] = x; //lưu vị trí của pos + 1 vào biến tạm
    }
}
int main()
{
    int a[1000];
    int n;
    NhapMang(a, n);
    InsertionSort(a, n);
    cout << "Mang sau khi duoc sap xep : ";
    XuatMang(a, n);
    cout << endl;
    return 0;
}

//Chèn trực tiếp