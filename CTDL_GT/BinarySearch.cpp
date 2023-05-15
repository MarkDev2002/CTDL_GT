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
        cout << a[i] << "\t";
    }
}
int BinarySearch(int a[], int l, int r, int x)
{
    while (l <= r) //trong khi left nhỏ hơn right
    {
        int m = l + (r - l) / 2; //mid bằng left +(right-left)/2
        if (a[m] == x)           //nếu a[mid] = x cần tìm xuất ra mid
        {
            return m;
        }
        if (a[m] < x) //nếu a[mid] < giá trị cần tìm
        {
            l = m + 1; //left = mid + 1 (tìm từ phía phải của mid)
        }
        if (a[m] > x)
        {
            r = m - 1; //right = mid -1 (tìm từ phía trái của mid)
        }
    }
    return -1; //nếu không tìm thấy return false;
}
int main()
{
    int a[1000];
    int n, x;
    NhapMang(a, n);
    XuatMang(a, n);
    cout << "Nhap gia tri can tim : ";
    cin >> x;
    int index = BinarySearch(a, 0, n - 1, x);
    if (index != -1)
    {
        cout << "Ton tai gia tri " << x << endl;
    }
    else
    {
        cout << "Khong ton tai gia tri " << x << endl;
    }
    cout << endl;
    return 0;
}
//Ưu điểm : Chi phí thấp log2(n)
//Khuyết điểm : Không thể áp dụng trên mọi tiêu chuẩn tìm kiếm