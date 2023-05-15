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

void BinaryInsertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = a[i], left = 0, right = i - 1;
        while (left <= right) //tìm vị trí chèn x
        {
            //giống như thuật toán chèn trực tiếp nhưng sử dụng thuật toán BinarySearch để chọn được vị trí phù hợp cho a[i]
            int mid = (left + right) / 2;
            //tìm vị trí thích hợp cho m
            if (x < a[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        for (int j = i - 1; j >= left; j--)
            a[j + 1] = a[j]; //dời các phần tử đứng sau x
        a[left] = x;         //chèn x vào dãy
    }
}

int main()
{
    int a[1000];
    int n;
    NhapMang(a, n);
    cout << "Mang sau khi duoc sap xep la : ";
    BinaryInsertionSort(a, n);
    XuatMang(a, n);
    cout << endl;
    return 0;
}

//thuật toán chèn nhị phân
//Bản cải tiến của thuật toán chèn trực tiếp