#include <iostream>
using namespace std;
void NhapMang(int a[], int &n)
{
    cout << "Nhap n : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap a[" << i << "]: ";
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

void ShakerSort(int a[], int n)
{
    int r, l, m;
    l = 0;         //chỉ sô phần tử đầu
    r = m = n - 1; // chỉ số phần tử cuối || m là mark là biến đánh dấu
    while (l < r)  //lặp tới khi left == right thì thu được dãy đã sắp xếp
    {
        //vòng lặp đầu
        //phần tử nhỏ nhất nổi lên trên || chạy từ phải đến bên trái
        for (int i = r; i > l; i--)
        {
            if (a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                m = i;
            }
        }
        l = m; //sau vòng lặp thứ nhất cập nhật giá trị cho left chặn đầu phía bên trái

        //vòng lặp thứ hai
        //phần tử lớn nhất lặn xuống
        for (int j = l; j < r; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                m = j;
            }
        }
        r = m; //chặn đầu phía bên phải
    }
}

int main()
{
    int a[1000];
    int n;
    NhapMang(a, n);
    cout << "Mang sau khi duoc sap xep la : ";
    ShakerSort(a, n);
    XuatMang(a, n);
    cout << endl;
    return 0;
}
//cải tiến của thuật toán bubble sort
//chặn 2 đầu để thu hẹp khoảng cách so sánh