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

void CountingSort(int a[], int n)
{

    int output[n];
    int max = a[0];
    int min = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
        else if (a[i] < min)
            min = a[i];
    }

    int k = max - min + 1;

    int count_array[k];
    fill_n(count_array, k, 0);

    for (int i = 0; i < n; i++)
        count_array[a[i] - min]++;

    for (int i = 1; i < k; i++)
        count_array[i] += count_array[i - 1];

    for (int i = 0; i < n; i++)
    {
        output[count_array[a[i] - min] - 1] = a[i];
        count_array[a[i] - min]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

int main()
{
    int a[1000];
    int n;
    NhapMang(a, n);
    CountingSort(a, n);
    cout << "Mang sau khi da duoc sap xep la : ";
    XuatMang(a, n);
    cout << endl;
    return 0;
}