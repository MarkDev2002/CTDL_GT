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

// Hàm trộn 2 mảng con
// Chia làm 2 mảng con
// Mảng l là mảng con đầu tiên chứa các phần tử nữa trước
// Mảng r là mảng con thứ hai chứa các phần tử nữa sau
void merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1; // chiều dài mảng con bên trái
    int n2 = r - m;     // chiều dài mảng con bên phải

    int L[n1], R[n2]; // Mảng tạm lưu lại tiến trình trộn

    // Copy các dữ liệu của các phần tử sang mảng tạm
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    i = 0; // Khởi tạo chỉ số bắt đầu của mảng con đầu tiên
    j = 0; // Khởi tại chỉ số bắt đầu của mảng con thứ hai
    k = l; // Khởi tạo chỉ số bắt đầu của mảng tạm array

    // Gộp 2 mảng tạm thời vào array
    while (i < n1 && j < n2)
    {
        // xét phần tử đầu tiên trong mảng con bên trái nhỏ hơn bằng phần tử đầu tiên trong mảng con bên phải
        if (L[i] <= R[j])
        {
            // gán a[k] tại vị trí 0 bằng phần tử tại vị trí đầu tiên của mảng con left
            a[k] = L[i];
            i++; // tiếp tục tăng giá trị i lên 1 để xét
        }
        // xét trường hợp còn lại phần tử đầu tiên trong mảng con bên trái lớn hơn bằng phần tử đầu tiên trong mảng con bên phải
        else
        {
            a[k] = R[j];
            j++;
        }
        k++; // tăng giá trị k lên 1 để xét tiếp mảng con
    }
    // Trường hợp 2 mảng con chia không đều thì ta có 2 câu lệnh i < n1 và j < n2
    // Copy các phần tử còn lại của mảng Left vào array nếu có
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    // Copy các phần tử còn lại của mảng Right vào array nếu có
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

// l là chỉ số trái và r là chỉ số phải mảng cần được sắp xếp
void mergeSort(int a[], int l, int r)
{
    if (l < r) // l là chỉ số đầu của mảng và r là chỉ số cuối của mảng
    {
        // Tương tự mid = ( left + right ) / 2, nhưng cách này tránh làm tràn số
        // nếu gặp left và right là số lớn
        int m = l + (r - l) / 2;
        // Gọi hàm đệ quy chia đôi từng mảng
        mergeSort(a, l, m);     // chia nửa đầu tiên bắt đầu từ left đến mid ( mảng con trái )(2)
        mergeSort(a, m + 1, r); // chia đôi nửa thứ hai bắt đầu từ mid + 1 đến right ( mảng con phải )(3)
        merge(a, l, m, r);      // gộp 2 mảng đã sắp xếp của (2) và (3)
    }
}

int main()
{
    int a[1000];
    int n;
    NhapMang(a, n);
    mergeSort(a, 0, n - 1);
    cout << "Mang sau khi duoc sap xep : ";
    XuatMang(a, n);
    cout << endl;
    return 0;
}